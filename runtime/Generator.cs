﻿using LLVMSharp.Interop;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Scaly.Compiler
{
    internal class NameDictionary
    {
        public Dictionary<string, Definition> Definitions = new Dictionary<string, Definition>();
        public Dictionary<string, List<Function>> Functions = new Dictionary<string, List<Function>>();
        public Dictionary<string, Operator> Operators = new Dictionary<string, Operator>();
        public Dictionary<string, Source> Sources = new Dictionary<string, Source>();
    }

    internal class DictionaryContext
    {
        public NameDictionary Dictionary;
        public Source Source;
        public string Path;
        public Definition Definition;
    }

    internal class GlobalContext
    {
        public LLVMModuleRef Module;
        public NameDictionary Dictionary;
        public Dictionary<string, LLVMTypeRef> Types = new Dictionary<string, LLVMTypeRef>();
        public Dictionary<string, KeyValuePair<TypeSpec, LLVMValueRef>> Values = new Dictionary<string, KeyValuePair<TypeSpec, LLVMValueRef>>();
    }

    internal class Context
    {
        public GlobalContext Global;
        public Source Source;
        public string Path = "";
        public Context ParentContext;
        public Dictionary<string, KeyValuePair<TypeSpec, LLVMValueRef>> Values = new Dictionary<string, KeyValuePair<TypeSpec, LLVMValueRef>>();

        public KeyValuePair<TypeSpec, LLVMValueRef> ResolveValue(string name)
        {
            if (Values.ContainsKey(name))
                return Values[name];

            if (ParentContext != null)
            {
                var valueRef = ParentContext.ResolveValue(name);
                if (valueRef.Value != null)
                    return valueRef;
            }

            if (Global.Values.ContainsKey(name))
                return Global.Values[name];

            return new KeyValuePair<TypeSpec, LLVMValueRef>(null, null);
        }

        internal Definition ResolveDefinitionName(string name, Span span)
        {
            if (!Global.Dictionary.Definitions.ContainsKey(name))
                throw new CompilerException($"Tht definition \"{name}\" was not found.", span);

            return Global.Dictionary.Definitions[name];
        }

        internal List<Function> ResolveFunctionName(string name, Span span)
        {
            if (!Global.Dictionary.Functions.ContainsKey(name))
                throw new CompilerException($"Tht function \"{name}\" was not found.", span);

            return Global.Dictionary.Functions[name];
        }

        internal Operator ResolveOperatorName(string name, Span span)
        {
            if (!Global.Dictionary.Operators.ContainsKey(name))
                throw new CompilerException($"Tht function \"{name}\" was not found.", span);

            return Global.Dictionary.Operators[name];
        }

        internal TypeSpec ResolveFunctionTypeSpec(string name)
        {
            return null;
        }
    }


    internal class Generator
    {
        public delegate int Main(int argc, string[] argv);

        internal static Main JitProgram(List<Source> sources)
        {
            LLVMModuleRef module = LLVMModuleRef.CreateWithName("JIT module");
            Generate(module, sources);
            VerifyAndInitialize(module);
            var engine = module.CreateMCJITCompiler();
            var function = module.GetNamedFunction("main");
            var jitMain = engine.GetPointerToGlobal<Main>(function);
            return jitMain;
        }

        internal static void GenerateProgram(List<Source> sources, string outputName)
        {
            LLVMModuleRef module = LLVMModuleRef.CreateWithName(string.Empty);
            Generate(module, sources);

            VerifyAndInitialize(module);
            LLVM.InitializeAllTargetInfos();
            var triple = LLVMTargetRef.DefaultTriple;
            LLVMTargetRef target = LLVMTargetRef.GetTargetFromTriple(triple);
            LLVMTargetMachineRef targetMachine = target.CreateTargetMachine(triple, "", "",
                LLVMCodeGenOptLevel.LLVMCodeGenLevelDefault, LLVMRelocMode.LLVMRelocDefault,
                LLVMCodeModel.LLVMCodeModelDefault);
            var message = "";
            targetMachine.TryEmitToFile(module, $"{outputName}.o", LLVMCodeGenFileType.LLVMObjectFile, out message);
        }

        static void Generate(LLVMModuleRef module, List<Source> sources)
        {
            var dictionary = new NameDictionary();
            {
                var context = new DictionaryContext { Dictionary = dictionary, Path = "" };
                foreach (var source in sources)
                {
                    context.Source = source;
                    BuildSourceDictionary(context);
                }
            }

            {
                var globalContext = new GlobalContext { Module = module, Dictionary = dictionary };
                var context = new Context { Global = globalContext, ParentContext = null };
                foreach (var source in sources)
                {
                    context.Source = source;
                    if (context.Source.Functions != null)
                    {
                        foreach (var function in context.Source.Functions)
                        {
                            BuildFunction(context, function);
                        }
                    }
                }
            }

            //BuildDefinitionTypes(localContext, definition);
            //BuildDefinitionValues(localContext, definition);
            //BuildFunctions(globalContext, null, definition);
        }

        static KeyValuePair<TypeSpec, LLVMValueRef> BuildFunction(Context context, Function function)
        {
            var functionValue = ResolveFunctionValue(context, function);
            var block = functionValue.Value.AppendBasicBlock(string.Empty);
            using (var builder = context.Global.Module.Context.CreateBuilder())
            {
                builder.PositionAtEnd(block);
                uint paramCount = 0;
                foreach (var parameter in function.Routine.Input)
                {
                    context.Values.Add(parameter.Name, new KeyValuePair<TypeSpec, LLVMValueRef>(parameter.TypeSpec, functionValue.Value.GetParam(paramCount)));
                    paramCount++;
                }
                KeyValuePair<TypeSpec, LLVMValueRef> typedValue = new KeyValuePair<TypeSpec, LLVMValueRef>(null, null);
                foreach (var operation in function.Routine.Operations)
                    typedValue = BuildOperands(context, builder, operation.Operands);
                builder.BuildRet(typedValue.Value);
            }
            return functionValue;
        }

        static KeyValuePair<TypeSpec, LLVMValueRef> ResolveFunctionValue(Context context, Function function)
        {
            var functionName = QualifyFunctionName(context, function);
            if (!context.Global.Values.ContainsKey(functionName))
                BuildFunctionValue(context, function);
            var llvmFunction = context.Global.Values[function.Name];
            return llvmFunction;
        }

        static KeyValuePair<TypeSpec, LLVMValueRef> ResolveOperatorValue(Context context, Operator @operator)
        {
            var functionName = QualifyOperatorName(context, @operator);
            if (!context.Global.Values.ContainsKey(functionName))
                BuildOperatorValue(context, @operator);
            var llvmFunction = context.Global.Values[@operator.Name];
            return llvmFunction;
        }

        static void BuildFunctionValue(Context context, Function function)
        {
            var functionType = ResolveFunctionType(context, function);
            var functionName = QualifyFunctionName(context, function);
            context.Global.Values.Add(function.Name, new KeyValuePair<TypeSpec, LLVMValueRef>(null, context.Global.Module.AddFunction(functionName, functionType)));
        }

        static LLVMTypeRef ResolveFunctionType(Context context, Function function)
        {
            var functionName = QualifyFunctionName(context, function);
            if (context.Global.Types.ContainsKey(functionName))
                return context.Global.Types[functionName];
            var functionType = BuildFunctionType(context, function);
            context.Global.Types.Add(functionName, functionType);
            return functionType;
        }

        static string QualifyFunctionName(Context context, Function function)
        {
            if ((function.Routine.Implementation == Implementation.Extern) || (context.Path == "" && function.Name == "main"))
                return function.Name;

            var functionNameBuilder = new StringBuilder();
            if (context.Path != "")
            {
                functionNameBuilder.Append(context.Path);
                functionNameBuilder.Append('.');
            }
            functionNameBuilder.Append(function.Name);
            functionNameBuilder.Append('(');
            var first = true;
            foreach (var parameter in function.Routine.Input)
            {
                if (first)
                    first = false;
                else
                    functionNameBuilder.Append(',');
                functionNameBuilder.Append(parameter.TypeSpec.Name);
            }
            functionNameBuilder.Append(')');
            return functionNameBuilder.ToString();
        }

        static string QualifyOperatorName(Context context, Operator @operator)
        {
            var operatorNameBuilder = new StringBuilder();
            if (context.Path != "")
            {
                operatorNameBuilder.Append(context.Path);
                operatorNameBuilder.Append('.');
            }
            operatorNameBuilder.Append(@operator.Name);
            return operatorNameBuilder.ToString();
        }


        static LLVMTypeRef BuildFunctionType(Context context, Function function)
        {
            var returnType = GetSingleType(context, function.Routine.Result);
            var parameterTypes = GetTypes(context, function.Routine.Input);
            return LLVMTypeRef.CreateFunction(returnType, parameterTypes);
        }

        static LLVMTypeRef GetSingleType(Context context, List<Parameter> result)
        {
            if (result == null)
                return LLVMTypeRef.Void;

            return ResolveType(context, result[0].TypeSpec);
        }

        static LLVMTypeRef[] GetTypes(Context context, List<Parameter> result)
        {
            if (result == null)
                return new LLVMTypeRef[] { };

            return result.ConvertAll(it => ResolveType(context, it.TypeSpec)).ToArray();
        }

        static LLVMTypeRef ResolveType(Context context, TypeSpec typeSpec)
        {
            LLVMTypeRef type;
            var qualifiedName = QualifyName(context, typeSpec.Name);
            var typeName = AddTypeArguments(qualifiedName, typeSpec.Arguments);
            if (context.Global.Types.ContainsKey(typeName))
                return context.Global.Types[typeName];

            if (typeSpec.Name == "Pointer")
            {
                type = GetPointerType(context, typeSpec);
            }
            else
            {
                var newContext = new Context { Global = context.Global, Source = context.Global.Dictionary.Sources[qualifiedName] };
                type = CreateType(newContext, qualifiedName, typeSpec);
            }

            context.Global.Types.Add(typeName, type);
            return type;
        }

        static LLVMTypeRef GetPointerType(Context context, TypeSpec typeSpec)
        {
            if (typeSpec.Arguments == null)
                throw new CompilerException("Pointer is a generic type which expects a type argument.", typeSpec.Span);
            if (typeSpec.Arguments.Count != 1)
                throw new CompilerException($"Pointer expects exactly one type argument, not {typeSpec.Arguments.Count}.", typeSpec.Span);
            var typeArgument = typeSpec.Arguments[0];
            var pointerTarget = (typeArgument.Name == "Pointer") ? GetPointerType(context, typeArgument) : ResolveType(context, typeArgument);
            return LLVMTypeRef.CreatePointer(pointerTarget, 0);
        }

        static KeyValuePair<TypeSpec, LLVMValueRef> BuildOperands(Context context, LLVMBuilderRef builder, List<Operand> operands)
        {
            KeyValuePair<TypeSpec, LLVMValueRef> typedValue = new KeyValuePair<TypeSpec, LLVMValueRef>(null, null);
            var enumerator = operands.GetEnumerator();
            while (enumerator.MoveNext())
            {
                var operand = enumerator.Current;
                typedValue = BuildOperand(context, typedValue, builder, operand, enumerator);
            }
            return typedValue;
        }

        static KeyValuePair<TypeSpec, LLVMValueRef> BuildOperand(Context context, KeyValuePair<TypeSpec, LLVMValueRef> typedValue, LLVMBuilderRef builder, Operand operand, IEnumerator<Operand> operands)
        {
            switch (operand.Expression)
            {
                case IntegerConstant integerConstant:
                    typedValue = new KeyValuePair<TypeSpec, LLVMValueRef>(context.Global.Dictionary.Definitions["Integer"].Type, LLVMValueRef.CreateConstInt(LLVMTypeRef.Int32, (ulong)integerConstant.Value));
                    break;
                case Name name:
                    typedValue = BuildName(context, builder, name, typedValue, operands);
                    break;
                case Scope scope:
                    typedValue = BuildScope(context, builder, scope);
                    break;
                case Object @object:
                    if (typedValue.Value == null)
                        throw new CompilerException("Objects are currently only supported as parameter lists for function calls.", @object.Span);
                    typedValue = BuildFunctionCall(context, typedValue, builder, @object);
                    break;
                default:
                    throw new NotImplementedException($"BuildOperand for expression {operand.Expression.GetType()} not implemented.");
            }
            return typedValue;
        }

        static KeyValuePair<TypeSpec, LLVMValueRef> BuildName(Context context, LLVMBuilderRef builder, Name name, KeyValuePair<TypeSpec, LLVMValueRef> previousValue, IEnumerator<Operand> operands)
        {
            var valueRef = context.ResolveValue(name.Path);
            if (valueRef.Value != null)
                return valueRef;

            var qualifiedName = QualifyName(context, name.Path);
            if (qualifiedName == null)
                throw new CompilerException($"The name '{name.Path}' has not been found.", name.Span);
            if (!context.Global.Dictionary.Sources.ContainsKey(qualifiedName))
                throw new CompilerException($"The name '{name.Path}' was not in the dictionary.", name.Span);

            List<Function> functions = null;
            if (context.Global.Dictionary.Functions.ContainsKey(qualifiedName))
                functions = context.Global.Dictionary.Functions[qualifiedName];

            Operator @operator = null;
            if (context.Global.Dictionary.Operators.ContainsKey(qualifiedName))
                @operator = context.Global.Dictionary.Operators[qualifiedName];

            if (@operator != null)
            {
                if (previousValue.Value == null)
                    throw new CompilerException("An operator cannot act on nothing. It must follow an operand it can act upon.", @operator.Span);
                var operatorValue = ResolveOperatorValue(context, @operator);
                return BuildOperatorCall(context, operatorValue, builder, previousValue);
            }

            if (functions.Count == 0)
                throw new CompilerException($"The name '{name.Path}' has not been found.", name.Span);

            if (!operands.MoveNext())
                throw new CompilerException($"No function arguments for '{name.Path}' were given.", name.Span);

            var operand = operands.Current;
            switch (operand.Expression)
            {
                case Object @object:
                    valueRef = FindMatchingFunction(context, functions, @object);
                    if (valueRef.Value == null)
                        throw new CompilerException("No matching function has been found for the arguments.", @object.Span);
                    return BuildFunctionCall(context, valueRef, builder, @object);
                default:
                    throw new CompilerException($"Only an object can be applied to function '{name.Path}'. Got an {operand.Expression.GetType()}.", @name.Span);
            }
        }

        static KeyValuePair<TypeSpec, LLVMValueRef> FindMatchingFunction(Context context, List<Function> functions, Object @object)
        {
            var functionsWithSameNumberOfArguments = functions.Where(it => it.Routine.Input.Count == @object.Components.Count).ToList();
            if (functionsWithSameNumberOfArguments.Count == 0)
                throw new CompilerException($"No overload of the function takes {@object.Components.Count} arguments.", @object.Span);
            if (functionsWithSameNumberOfArguments.Count > 1)
                throw new CompilerException($"More than one overload of the function takes {@object.Components.Count} arguments.", @object.Span);
            var function = functionsWithSameNumberOfArguments.First();
            var functionValue = ResolveFunctionValue(context, function);
            return functionValue;
        }

        static KeyValuePair<TypeSpec, LLVMValueRef> BuildScope(Context context, LLVMBuilderRef builder, Scope scope)
        {
            KeyValuePair<TypeSpec, LLVMValueRef> typedValue = new KeyValuePair<TypeSpec, LLVMValueRef>(null, null);
            foreach (var operation in scope.Operations)
                typedValue = BuildOperands(context, builder, operation.Operands);

            if (scope.Binding != null)
                typedValue = BuildBinding(context, builder, scope.Binding);

            return typedValue;
        }

        static KeyValuePair<TypeSpec, LLVMValueRef> BuildBinding(Context context, LLVMBuilderRef builder, Binding binding)
        {
            var newContext = new Context { Global = context.Global, Source = context.Source, ParentContext = context };
            newContext.Values.Add(binding.Identifier, BuildOperands(context, builder, binding.Operation.Operands));
            KeyValuePair<TypeSpec, LLVMValueRef> valueRef = new KeyValuePair<TypeSpec, LLVMValueRef>(null, null);
            foreach (var operation in binding.Operations)
                valueRef = BuildOperands(newContext, builder, operation.Operands);

            return valueRef;
        }

        static KeyValuePair<TypeSpec, LLVMValueRef> BuildFunctionCall(Context context, KeyValuePair<TypeSpec, LLVMValueRef> function, LLVMBuilderRef builder, Object @object)
        {
            var arguments = new List<LLVMValueRef>();
            foreach (var component in @object.Components)
            {
                KeyValuePair<TypeSpec, LLVMValueRef> typedValue = BuildOperands(context, builder, component.Value);
                arguments.Add(typedValue.Value);
            }

            return new KeyValuePair<TypeSpec, LLVMValueRef>(null, builder.BuildCall(function.Value, arguments.ToArray()));
        }

        static KeyValuePair<TypeSpec, LLVMValueRef> BuildOperatorCall(Context context, KeyValuePair<TypeSpec, LLVMValueRef> @operator, LLVMBuilderRef builder, KeyValuePair<TypeSpec, LLVMValueRef> operand)
        {
            return new KeyValuePair<TypeSpec, LLVMValueRef>(null, builder.BuildCall(@operator.Value, new LLVMValueRef[] { operand.Value }));
        }

        static void BuildSourceDictionary(DictionaryContext context)
        {
            if (context.Source.Sources != null)
            {
                foreach (var source in context.Source.Sources)
                {
                    var newContext = new DictionaryContext { Dictionary = context.Dictionary, Source = source, Path = context.Path, Definition = context.Definition };
                    BuildSourceDictionary(newContext);
                }
            }

            if (context.Source.Definitions != null)
            {
                foreach (var definition in context.Source.Definitions.Values)
                {
                    var newContext = new DictionaryContext { Dictionary = context.Dictionary, Source = context.Source, Path = context.Path == "" ? definition.Type.Name : context.Path + "." + definition.Type.Name, Definition = definition };
                    BuildDefinitionDictionary(newContext);
                }
            }

            if (context.Source.Functions != null)
                foreach (var function in context.Source.Functions)
                    BuildFunctionDictionary(context, function);
        }

        static void BuildDefinitionDictionary(DictionaryContext context)
        {
            if (context.Dictionary.Definitions.ContainsKey(context.Path))
                throw new CompilerException($"The definition {context.Path} was already defined.", context.Definition.Span);
            context.Dictionary.Definitions.Add(context.Path, context.Definition);
            context.Dictionary.Sources.Add(context.Path, context.Source);

            if (context.Definition.Sources != null)
            {
                foreach (var source in context.Definition.Sources)
                {
                    var newContext = new DictionaryContext { Dictionary = context.Dictionary, Source = source, Path = context.Path, Definition = context.Definition };
                    BuildSourceDictionary(newContext);
                }
            }

            if (context.Definition.Definitions != null)
            {
                foreach (var definition in context.Definition.Definitions.Values)
                {
                    var newContext = new DictionaryContext { Dictionary = context.Dictionary, Source = context.Source, Path = context.Path == "" ? definition.Type.Name : context.Path + "." + definition.Type.Name, Definition = definition };
                    BuildDefinitionDictionary(newContext);
                }
            }

            if (context.Definition.Functions != null)
                foreach (var function in context.Definition.Functions)
                    BuildFunctionDictionary(context, function);

            if (context.Definition.Operators != null)
                foreach (var @operator in context.Definition.Operators.Values)
                    BuildOperatorDictionary(context, @operator);
        }

        static void BuildFunctionDictionary(DictionaryContext context, Function function)
        {
            var path = context.Path == "" ? function.Name : context.Path + "." + function.Name;
            if (!context.Dictionary.Functions.ContainsKey(path))
                context.Dictionary.Functions.Add(path, new List<Function>());

            context.Dictionary.Functions[path].Add(function);
            context.Dictionary.Sources.Add(path, context.Source);
        }

        static void BuildOperatorDictionary(DictionaryContext context, Operator @operator)
        {
            var path = context.Path + "." + @operator.Name;
            if (context.Dictionary.Operators.ContainsKey(path))
                throw new CompilerException($"The operator {path} was already defined.", @operator.Span);
            context.Dictionary.Operators.Add(path, @operator);
            context.Dictionary.Sources.Add(path, context.Source);
        }

        static void BuildDefinitionTypes(Context context, Definition definition)
        {
            if (definition.Sources != null)
            {
                foreach (var source in definition.Sources)
                {
                    var newContext = new Context { Global = context.Global, Source = source };
                    BuildSourceTypes(newContext);
                }
            }

            if (definition.Functions != null)
                foreach (var function in definition.Functions)
                    BuildFunctionType(context, function);

            if (definition.Operators != null)
                foreach (var @operator in definition.Operators.Values)
                    BuildOperatorType(context, @operator);
        }

        static void BuildSourceTypes(Context context)
        {
            if (context.Source.Definitions != null)
            {
                foreach (var definition in context.Source.Definitions.Values)
                {
                    if (definition.Type.Arguments == null)
                        BuildDefinitionTypes(context, definition);
                }
            }

            if (context.Source.Functions != null)
                foreach (var function in context.Source.Functions)
                    BuildFunctionType(context, function);

            if (context.Source.Operators != null)
                foreach (var @operator in context.Source.Operators.Values)
                    BuildOperatorType(context, @operator);

            if (context.Source.Sources != null)
            {
                foreach (var source in context.Source.Sources)
                {
                    var newContext = new Context { Global = context.Global, Source = source };
                    BuildSourceTypes(newContext);
                }
            }
        }

        static LLVMTypeRef BuildOperatorType(Context context, Operator @operator)
        {
            var returnType = GetSingleType(context, @operator.Routine.Result);
            var parameterTypes = new List<LLVMTypeRef>();
            if (@operator.Routine.Input != null)
                parameterTypes.AddRange(GetTypes(context, @operator.Routine.Input));
            var functionType = LLVMTypeRef.CreateFunction(returnType, parameterTypes.ToArray());
            context.Global.Types.Add(@operator.Name, functionType);
            return functionType;
        }

        static void BuildSourceValues(Context context)
        {
            if (context.Source != null)
            {
                if (context.Source.Functions != null)
                    foreach (var function in context.Source.Functions)
                        BuildFunctionValue(context, function);

                if (context.Source.Operators != null)
                    foreach (var @operator in context.Source.Operators.Values)
                        BuildOperatorValue(context, @operator);

                if (context.Source.Sources != null)
                {
                    foreach (var source in context.Source.Sources)
                    {
                        var newContext = new Context { Global = context.Global, Source = source };
                        BuildSourceValues(newContext);
                    }
                }

                if (context.Source.Definitions != null)
                {
                    foreach (var definition in context.Source.Definitions.Values)
                    {
                        if (definition.Type.Arguments == null)
                            BuildDefinitionValues(context, definition);
                    }
                }
            }
        }

        static void BuildDefinitionValues(Context context, Definition definition)
        {
            if (definition.Sources != null)
            {
                foreach (var source in definition.Sources)
                {
                    var newContext = new Context { Global = context.Global, Source = source };
                    BuildSourceValues(newContext);
                }
            }

            if (definition.Functions != null)
                foreach (var function in definition.Functions)
                    BuildFunctionValue(context, function);

            if (definition.Operators != null)
                foreach (var @operator in definition.Operators.Values)
                    BuildOperatorValue(context, @operator);
        }

        static void BuildOperatorValue(Context context, Operator @operator)
        {
            var operatorType = ResolveOperatorType(context, @operator);
            var operatorName = QualifyOperatorName(context, @operator);
            context.Global.Values.Add(@operator.Name, new KeyValuePair<TypeSpec, LLVMValueRef>(null, context.Global.Module.AddFunction(operatorName, operatorType)));
        }

        static LLVMTypeRef ResolveOperatorType(Context context, Operator @operator)
        {
            var functionName = QualifyOperatorName(context, @operator);
            if (context.Global.Types.ContainsKey(functionName))
                return context.Global.Types[functionName];
            var operatorType = BuildOperatorType(context, @operator);
            context.Global.Types.Add(functionName, operatorType);
            return operatorType;
        }

        static TypeSpec GetOperandType(Context context, LLVMBuilderRef builder, TypeSpec previousTypeSpec, Operand operand)
        {
            switch (operand.Expression)
            {
                //case IntegerConstant integerConstant:
                //    valueRef = LLVMValueRef.CreateConstInt(LLVMTypeRef.Int32, (ulong)integerConstant.Value);
                //    break;
                case Name name:
                    return GetNameType(context, previousTypeSpec, name);
                case Scope scope:
                    return GetScopeType(context, builder, previousTypeSpec, scope);
                //case Object @object:
                //    if (valueRef == null)
                //        throw new CompilerException("Objects are currently only supported as parameter lists for function calls.", @object.Span);
                //    valueRef = BuildFunctionCall(context, valueRef, @object);
                //    break;
                default:
                    throw new NotImplementedException($"GetOperandType for expression {operand.Expression.GetType()} not implemented.");
            }
        }

        static TypeSpec GetNameType(Context context, TypeSpec previousTypeSpec, Name name)
        {
            if (QualifyName(context, name.Path) != null)
                throw new NotImplementedException("Object creation not yet supported.");

            throw new NotImplementedException();
        }

        static TypeSpec GetScopeType(Context context, LLVMBuilderRef builder, TypeSpec previousTypeSpec, Scope scope)
        {
            TypeSpec typeSpec = null;
            foreach (var operation in scope.Operations)
                typeSpec = GetOperandsType(context, builder, operation.Operands);

            if (scope.Binding != null)
                typeSpec = GetBindingType(context, builder, scope.Binding);

            return typeSpec;
        }

        static TypeSpec GetBindingType(Context context, LLVMBuilderRef builder, Binding binding)
        {
            var newContext = new Context { Global = context.Global, Source = context.Source, ParentContext = context };
            newContext.Values.Add(binding.Identifier, BuildOperands(context, builder, binding.Operation.Operands));
            TypeSpec typeSpec = null;
            foreach (var operation in binding.Operations)
                typeSpec = GetOperandsType(newContext, builder, operation.Operands);

            return typeSpec;
        }

        static TypeSpec GetOperandsType(Context context, LLVMBuilderRef builder, List<Operand> operands)
        {
            TypeSpec typeSpec = null;
            foreach (var operand in operands)
            {
                typeSpec = GetOperandType(context, builder, typeSpec, operand);
            }
            return typeSpec;
        }

        static string QualifyName(Context context, string name)
        {
            if (context.Global.Types.ContainsKey(name))
                return name;

            if (context.Global.Dictionary.Definitions.ContainsKey(name))
                return name;

            if (context.Global.Dictionary.Functions.ContainsKey(name))
                return name;

            if (context.Global.Dictionary.Operators.ContainsKey(name))
                return name;

            if (context.Source.Uses != null && context.Source.Uses.ContainsKey(name))
                return context.Source.Uses[name].Path;

            if (context.Source.Usings != null)
            {
                foreach (var @using in context.Source.Usings)
                {
                    var usingName = @using.Path;

                    var definition = context.ResolveDefinitionName(usingName, @using.Span);
                    if (definition.Definitions != null && definition.Definitions.ContainsKey(name))
                        return usingName + "." + name;

                    if (definition.Operators != null && definition.Operators.ContainsKey(name))
                        return usingName + "." + name;
                }
            }

            return null;
        }

        static LLVMTypeRef CreateType(Context context, string qualifiedName, TypeSpec typeSpec)
        {
            var definition = context.ResolveDefinitionName(qualifiedName, typeSpec.Span);
 
            if (typeSpec.Arguments != null)
            {
                if (definition.Type.Arguments != null)
                {
                    if (typeSpec.Arguments.Count != definition.Type.Arguments.Count)
                        throw new CompilerException($"The generic type {qualifiedName} needs {definition.Type.Arguments.Count} type arguments, but {typeSpec.Arguments.Count} type arguments were given.", typeSpec.Span);
                }
                else
                {
                    throw new CompilerException($"The type {qualifiedName} is not a generic type.", typeSpec.Span);
                }
            }
            else
            {
                if (definition.Type.Arguments != null)
                {
                    throw new CompilerException($"The type {qualifiedName} is a generic type. Generic arguments are missing.", typeSpec.Span);
                }
            }

            return CreateGenericType(context, typeSpec, definition);
        }

        static LLVMTypeRef CreateGenericType(Context context, TypeSpec typeSpec, Definition definition)
        {
            if (definition.IsIntrinsic)
                return CreateInstrinsicType(definition.Type.Name, typeSpec.Span);

            if (definition.Structure == null)
                throw new CompilerException($"The type \"{definition.Type.Name}\" contains no data and can only be used as a namespace.", typeSpec.Span);

            if (definition.Structure.Members.Count == 1 && definition.Structure.Members[0].Name == null && definition.Structure.Members[0].Type.Arguments == null)
                return ResolveType(context, definition.Structure.Members[0].Type);

            return null;
        }

        static LLVMTypeRef CreateInstrinsicType(string name, Span span)
        {
            switch (name)
            {
                case "i1":
                    return LLVMTypeRef.Int1;
                case "i8":
                    return LLVMTypeRef.Int8;
                case "i32":
                    return LLVMTypeRef.Int32;
                case "i64":
                    return LLVMTypeRef.Int64;
                default:
                    throw new CompilerException($"The intrinsic type \"{name}\" is unknown.", span);
            }
        }

        static string AddTypeArguments(string name, List<TypeSpec> arguments)
        {
            if (arguments == null)
                return name;

            StringBuilder builder = new StringBuilder(name);
            builder.Append('[');
            bool first = true;
            foreach (var argument in arguments)
            {
                if (first)
                    first = false;
                else
                    builder.Append(',');
                builder.Append(AddTypeArguments(argument.Name, argument.Arguments));
            }
            builder.Append(']');

            return builder.ToString();
        }

        static void VerifyAndInitialize(LLVMModuleRef module)
        {
            module.Verify(LLVMVerifierFailureAction.LLVMPrintMessageAction);
            LLVM.InitializeNativeTarget();
            LLVM.InitializeNativeAsmParser();
            LLVM.InitializeNativeAsmPrinter();
        }
    }
}