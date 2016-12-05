#include "scalyc.h"
using namespace scaly;
namespace scalyc {

HeaderVisitor::HeaderVisitor() {
    moduleName = new(_getPage()->allocateExclusivePage()) string();
    headerFile = new(_getPage()->allocateExclusivePage()) VarString();
    mainHeaderFile = new(_getPage()->allocateExclusivePage()) VarString();
    inherits = new(_getPage()->allocateExclusivePage()) _Array<Inherits>();
    classes = new(_getPage()->allocateExclusivePage()) _Array<string>();
}

bool HeaderVisitor::openProgram(Program* program) {
    _Region _region; _Page* _p = _region.get();
    string* programDirectory = new(_p) string(program->directory);
    if (programDirectory == nullptr || programDirectory->equals("")) {
        programDirectory = new(_p) string(".");
    }
    if (!Directory::exists(programDirectory)) {
        auto _Directory_error = Directory::create(_p, programDirectory);
        if (_Directory_error) { switch (_Directory_error->_getErrorCode()) {
            default: {
            return false;
            }
        } }
    }
    {
        _Region _region; _Page* _p = _region.get();
        VarString* outputFilePath = new(_p) VarString(programDirectory);
        outputFilePath->append("/");
        outputFilePath->append(program->name);
        {
            buildMainHeaderFileString(program);
            {
                _Region _region; _Page* _p = _region.get();
                VarString* headerFilePath = new(_p) VarString(outputFilePath);
                headerFilePath->append(".h");
                auto _File_error = File::writeFromString(_p, headerFilePath, mainHeaderFile);
                if (_File_error) { switch (_File_error->_getErrorCode()) {
                    default: {
                    return false;
                    }
                } }
            }
        }
        collectInheritances(program);
    }
    return true;
}

bool HeaderVisitor::openCompilationUnit(CompilationUnit* compilationUnit) {
    moduleName = compilationUnit->fileName;
    if (!(compilationUnit->parent->_isProgram()))
        return false;
    string* programName = ((Program*)(compilationUnit->parent))->name;
    if (!moduleName->equals(programName)) {
        if (headerFile != nullptr)
            headerFile->_getPage()->clear();
        headerFile = new(headerFile->_getPage()) VarString();
        headerFile->append("#ifndef __");
        headerFile->append(programName);
        headerFile->append("__");
        headerFile->append(moduleName);
        headerFile->append("__\n");
        headerFile->append("#define __");
        headerFile->append(programName);
        headerFile->append("__");
        headerFile->append(moduleName);
        headerFile->append("__\n#include \"");
        headerFile->append(programName);
        headerFile->append(".h\"\nusing namespace scaly;\nnamespace ");
        headerFile->append(programName);
        headerFile->append(" {");
    }
    return true;
}

void HeaderVisitor::closeCompilationUnit(CompilationUnit* compilationUnit) {
    _Region _region; _Page* _p = _region.get();
    if (!(compilationUnit->parent)->_isProgram())
        return;
    string* programName = ((Program*)(compilationUnit->parent))->name;
    string* programDirectory = ((Program*)(compilationUnit->parent))->directory;
    VarString* outputFilePath = new(_p) VarString(programDirectory);
    outputFilePath->append('/');
    string* fileNameWithoutExtension = Path::getFileNameWithoutExtension(_p, compilationUnit->fileName);
    outputFilePath->append(fileNameWithoutExtension);
    if (!moduleName->equals(programName)) {
        _Region _region; _Page* _p = _region.get();
        headerFile->append("\n\n}\n#endif // __scalyc__");
        headerFile->append(moduleName);
        headerFile->append("__\n");
        VarString* headerFilePath = new(_p) VarString(outputFilePath);
        headerFilePath->append(".h");
        auto _File_error = File::writeFromString(_p, headerFilePath, headerFile);
        if (_File_error) { switch (_File_error->_getErrorCode()) {
            default: {
            return;
            }
        } }
    }
}

bool HeaderVisitor::openConstantDeclaration(ConstantDeclaration* constantDeclaration) {
    if (constantDeclaration->parent->parent->parent == nullptr)
        return false;
    if (constantDeclaration->parent->parent->parent->_isClassDeclaration())
        return true;
    return false;
}

bool HeaderVisitor::openVariableDeclaration(VariableDeclaration* variableDeclaration) {
    if (variableDeclaration->parent->parent->parent == nullptr)
        return false;
    if (variableDeclaration->parent->parent->parent->_isClassDeclaration())
        return true;
    return false;
}

bool HeaderVisitor::openMutableDeclaration(MutableDeclaration* mutableDeclaration) {
    if (mutableDeclaration->parent->parent->parent == nullptr)
        return false;
    if (mutableDeclaration->parent->parent->parent->_isClassDeclaration())
        return true;
    return false;
}

void HeaderVisitor::closeFunctionDeclaration(FunctionDeclaration* functionDeclaration) {
    if (functionDeclaration->body == nullptr)
        headerFile->append(" = 0");
}

bool HeaderVisitor::openEnumDeclaration(EnumDeclaration* enumDeclaration) {
    string* enumDeclarationName = enumDeclaration->name;
    headerFile->append("\n\nclass ");
    headerFile->append(enumDeclarationName);
    headerFile->append(";\n");
    return true;
}

void HeaderVisitor::closeEnumDeclaration(EnumDeclaration* enumDeclaration) {
    string* enumDeclarationName = enumDeclaration->name;
    _Array<EnumMember>* members = enumDeclaration->members;
    if (members != nullptr) {
        headerFile->append("enum _");
        headerFile->append(enumDeclarationName);
        headerFile->append("Code {\n");
        int i = 0;
        EnumMember* member = nullptr;
        size_t _members_length = members->length();
        for (size_t _i = 0; _i < _members_length; _i++) {
            member = *(*members)[_i];
            {
                headerFile->append("    _");
                headerFile->append(enumDeclarationName);
                headerFile->append("Code_");
                headerFile->append(member->enumCase->name);
                if (i == 0)
                    headerFile->append(" = 1");
                headerFile->append(",\n");
                i++;
            }
        }
        headerFile->append("};\n\n");
    }
    headerFile->append("class ");
    headerFile->append(enumDeclarationName);
    headerFile->append(" : public Object {\npublic:\n    ");
    headerFile->append(enumDeclarationName);
    headerFile->append("(_");
    headerFile->append(enumDeclarationName);
    headerFile->append("Code errorCode)\n    : errorCode(errorCode), errorInfo(0) {}\n\n");
    if (members != nullptr) {
        EnumMember* member = nullptr;
        size_t _members_length = members->length();
        for (size_t _i = 0; _i < _members_length; _i++) {
            member = *(*members)[_i];
            {
                if (member->parameterClause) {
                    headerFile->append("    ");
                    headerFile->append(enumDeclarationName);
                    headerFile->append("(_");
                    headerFile->append(enumDeclarationName);
                    headerFile->append("_");
                    headerFile->append(member->enumCase->name);
                    headerFile->append("* ");
                    headerFile->append(member->enumCase->name);
                    headerFile->append(")\n    : errorCode(_");
                    headerFile->append(enumDeclarationName);
                    headerFile->append("Code_");
                    headerFile->append(member->enumCase->name);
                    headerFile->append("), errorInfo(");
                    headerFile->append(member->enumCase->name);
                    headerFile->append(") {}\n\n");
                }
            }
        }
    }
    headerFile->append("    long _getErrorCode();\n    void* _getErrorInfo();\n\n");
    if (members != nullptr) {
        EnumMember* member = nullptr;
        size_t _members_length = members->length();
        for (size_t _i = 0; _i < _members_length; _i++) {
            member = *(*members)[_i];
            {
                if (member->parameterClause) {
                    headerFile->append("    _");
                    headerFile->append(enumDeclarationName);
                    headerFile->append("_");
                    headerFile->append(member->enumCase->name);
                    headerFile->append("* get_");
                    headerFile->append(member->enumCase->name);
                    headerFile->append("();\n");
                }
            }
        }
    }
    headerFile->append("\nprivate:\n    _");
    headerFile->append(enumDeclarationName);
    headerFile->append("Code errorCode;\n    void* errorInfo;\n};");
}

bool HeaderVisitor::openClassDeclaration(ClassDeclaration* classDeclaration) {
    headerFile->append("\n\nclass ");
    headerFile->append(classDeclaration->name);
    if (classDeclaration->body == nullptr) {
        headerFile->append(";");
        return false;
    }
    headerFile->append(" : public ");
    if (classDeclaration->typeInheritanceClause != nullptr) {
        _Array<Inheritance>* inheritances = classDeclaration->typeInheritanceClause->inheritances;
        int i = 0;
        Inheritance* inheritance = nullptr;
        size_t _inheritances_length = inheritances->length();
        for (size_t _i = 0; _i < _inheritances_length; _i++) {
            inheritance = *(*inheritances)[_i];
            {
                if (i > 0)
                    headerFile->append(", ");
                headerFile->append(inheritance->type->name);
                i++;
            }
        }
    }
    else {
        headerFile->append("Object");
    }
    headerFile->append(" {\n");
    headerFile->append("public:");
    return true;
}

void HeaderVisitor::closeClassDeclaration(ClassDeclaration* classDeclaration) {
    headerFile->append("\n");
    if (classDeclaration->typeInheritanceClause != nullptr) {
        headerFile->append("\n    virtual bool _is");
        headerFile->append(classDeclaration->name);
        headerFile->append("();");
    }
    {
        _Region _region; _Page* _p = _region.get();
        _Array<string>* derivedClasses = new(_p) _Array<string>();
        collectDerivedClasses(derivedClasses, classDeclaration->name);
        string* derivedClass = nullptr;
        size_t _derivedClasses_length = derivedClasses->length();
        for (size_t _i = 0; _i < _derivedClasses_length; _i++) {
            derivedClass = *(*derivedClasses)[_i];
            {
                headerFile->append("\n    virtual bool _is");
                headerFile->append(derivedClass);
                headerFile->append("();");
            }
        }
    }
    headerFile->append("\n};");
}

bool HeaderVisitor::openConstructorDeclaration(ConstructorDeclaration* constructorDeclaration) {
    if (!constructorDeclaration->parent->parent->parent->_isClassDeclaration())
        return false;
    string* classDeclarationName = ((Program*)(constructorDeclaration->parent->parent->parent))->name;
    headerFile->append(classDeclarationName);
    headerFile->append("(");
    return true;
}

bool HeaderVisitor::openCodeBlock(CodeBlock* codeBlock) {
    return false;
}

bool HeaderVisitor::openPatternInitializer(PatternInitializer* patternInitializer) {
    if (patternInitializer->parent->_isAdditionalInitializer())
        headerFile->append(", ");
    return true;
}

bool HeaderVisitor::openFunctionSignature(FunctionSignature* functionSignature) {
    string* functionName = ((FunctionDeclaration*)functionSignature->parent)->name;
    FunctionDeclaration* functionDeclaration = (FunctionDeclaration*)functionSignature->parent;
    if (functionDeclaration->modifiers != nullptr) {
        _Array<Modifier>* modifiers = functionDeclaration->modifiers;
        Modifier* modifier = nullptr;
        size_t _modifiers_length = modifiers->length();
        for (size_t _i = 0; _i < _modifiers_length; _i++) {
            modifier = *(*modifiers)[_i];
            {
                if (modifier->_isStaticWord())
                    headerFile->append("static ");
                else
                    headerFile->append("virtual ");
            }
        }
    }
    else {
        headerFile->append("virtual ");
    }
    if (functionSignature->result == nullptr) {
        if (functionSignature->throwsClause == nullptr) {
            headerFile->append("void");
        }
        else {
            appendCppType(headerFile, functionSignature->throwsClause->throwsType);
        }
    }
    else {
        if (functionSignature->throwsClause != nullptr) {
            headerFile->append("_Result<");
            if (hasArrayPostfix(functionSignature->result->resultType)) {
                headerFile->append("_Array<");
                Type* type = functionSignature->result->resultType;
                appendCppTypeName(headerFile, type);
                headerFile->append(">");
            }
            else {
                Type* type = (Type*)functionSignature->result->resultType;
                appendCppTypeName(headerFile, type);
            }
            headerFile->append(", ");
            appendCppTypeName(headerFile, (Type*)(functionSignature->throwsClause->throwsType));
            headerFile->append(">");
        }
        else {
            if (hasArrayPostfix(functionSignature->result->resultType)) {
                headerFile->append("_Array<");
                Type* type = functionSignature->result->resultType;
                appendCppTypeName(headerFile, type);
                headerFile->append(">");
            }
            else {
                Type* type = (Type*)functionSignature->result->resultType;
                appendCppTypeName(headerFile, type);
                if (isClass(type->name)) {
                    headerFile->append("*");
                }
            }
        }
    }
    headerFile->append(" ");
    headerFile->append(functionName);
    headerFile->append("(");
    if (functionSignature->result != nullptr) {
        Type* type = (Type*)functionSignature->result->resultType;
        if (isClass(type->name)) {
            LifeTime* lifeTime = type->lifeTime;
            if ((lifeTime == nullptr) || !(lifeTime->_isReference())) {
                headerFile->append("_Page* _rp");
                if ((functionSignature->parameterClause->parameters) || (functionSignature->throwsClause)) {
                    headerFile->append(", ");
                }
            }
        }
    }
    if (functionSignature->throwsClause != nullptr) {
        headerFile->append("_Page* _ep");
        if (functionSignature->parameterClause->parameters) {
            headerFile->append(", ");
        }
    }
    return true;
}

void HeaderVisitor::closeParameterClause(ParameterClause* parameterClause) {
    headerFile->append(")");
}

bool HeaderVisitor::openConstParameter(ConstParameter* constParameter) {
    string* constParameterName = constParameter->name;
    writeParameter(constParameterName, constParameter->parameterType);
    return false;
}

void HeaderVisitor::writeParameter(string* name, Type* parameterType) {
    ParameterClause* parameterClause = (ParameterClause*)parameterType->parent->parent;
    _Array<Parameter>* parameters = parameterClause->parameters;
    Parameter* parameter = (Parameter*)parameterType->parent;
    if (parameter != *(*parameters)[0])
        headerFile->append(", ");
    parameterType->accept(this);
    headerFile->append(" ");
    headerFile->append(name);
}

bool HeaderVisitor::isClass(string* name) {
    if ((name->equals("string") || name->equals("VarString") || name->equals("File") || name->equals("Directory") || name->equals("Path") || name->equals("DirectoryError") || name->equals("FileError") || name->equals("ParserError") || name->equals("CppError") || name->equals("CompilerError"))) {
        return true;
    }
    string* className = nullptr;
    size_t _classes_length = classes->length();
    for (size_t _i = 0; _i < _classes_length; _i++) {
        className = *(*classes)[_i];
        {
            if (className->equals(name)) {
                return true;
            }
        }
    }
    return false;
}

void HeaderVisitor::closeConstParameter(ConstParameter* constParameter) {
    headerFile->append(constParameter->name);
}

bool HeaderVisitor::openVarParameter(VarParameter* varParameter) {
    writeParameter(varParameter->name, varParameter->parameterType);
    return false;
}

void HeaderVisitor::closeVarParameter(VarParameter* varParameter) {
    string* varParameterName = varParameter->name;
    headerFile->append(varParameterName);
}

bool HeaderVisitor::openEnumMember(EnumMember* enumMember) {
    if (!enumMember->parent->_isEnumDeclaration())
        return false;
    string* enumDeclarationName = ((EnumDeclaration*)(enumMember->parent))->name;
    if (enumMember->parameterClause) {
        headerFile->append("\nclass _");
        headerFile->append(enumDeclarationName);
        headerFile->append("_");
        headerFile->append(enumMember->enumCase->name);
        headerFile->append(" : public Object {\npublic:\n    _");
        headerFile->append(enumDeclarationName);
        headerFile->append("_");
        headerFile->append(enumMember->enumCase->name);
        headerFile->append("(");
    }
    return true;
}

void HeaderVisitor::closeEnumMember(EnumMember* enumMember) {
    if (enumMember->parameterClause != nullptr) {
        headerFile->append(";\n\n");
        _Array<Parameter>* parameters = enumMember->parameterClause->parameters;
        if (parameters != nullptr) {
            size_t pos = 0;
            Parameter* parameter = nullptr;
            size_t _parameters_length = parameters->length();
            for (size_t _i = 0; _i < _parameters_length; _i++) {
                parameter = *(*parameters)[_i];
                {
                    if (parameter->_isConstParameter()) {
                        ConstParameter* constParameter = (ConstParameter*)parameter;
                        headerFile->append("    ");
                        appendCppType(headerFile, constParameter->parameterType);
                        headerFile->append(" ");
                        headerFile->append(constParameter->name);
                        headerFile->append(";\n");
                    }
                    pos++;
                }
            }
        }
        headerFile->append("};\n");
    }
}

void HeaderVisitor::collectDerivedClasses(_Array<string>* derivedClasses, string* className) {
    Inherits* inherit = nullptr;
    size_t _inherits_length = inherits->length();
    for (size_t _i = 0; _i < _inherits_length; _i++) {
        inherit = *(*inherits)[_i];
        {
            if (inherit->name->equals(className))
                appendDerivedClasses(derivedClasses, inherit->inheritors);
        }
    }
}

void HeaderVisitor::appendDerivedClasses(_Array<string>* derivedClasses, _Array<string>* inheritors) {
    string* inheritor = nullptr;
    size_t _inheritors_length = inheritors->length();
    for (size_t _i = 0; _i < _inheritors_length; _i++) {
        inheritor = *(*inheritors)[_i];
        {
            derivedClasses->push(inheritor);
            collectDerivedClasses(derivedClasses, inheritor);
        }
    }
}

bool HeaderVisitor::openClassMember(ClassMember* classMember) {
    headerFile->append("\n    ");
    return true;
}

void HeaderVisitor::closeClassMember(ClassMember* classMember) {
    headerFile->append(";");
}

bool HeaderVisitor::openIdentifierPattern(IdentifierPattern* identifierPattern) {
    if (identifierPattern->annotationForType != nullptr) {
        identifierPattern->annotationForType->accept(this);
        headerFile->append(" ");
    }
    headerFile->append(identifierPattern->identifier);
    return false;
}

bool HeaderVisitor::openType(Type* type) {
    if ((type->parent->_isFunctionResult()) || (type->parent->_isInheritance()) || (type->parent->_isThrowsClause()))
        return false;
    if (hasArrayPostfix(type)) {
        headerFile->append("_Array<");
    }
    appendCppTypeName(headerFile, type);
    return true;
}

void HeaderVisitor::closeType(Type* type) {
    if (hasArrayPostfix(type))
        headerFile->append(">*");
    if (isClass(type->name) && !hasArrayPostfix(type) && !type->parent->_isConstructorCall()) {
        headerFile->append("*");
    }
}

void HeaderVisitor::buildMainHeaderFileString(Program* program) {
    mainHeaderFile->append("#ifndef __scaly__");
    mainHeaderFile->append(program->name);
    mainHeaderFile->append("__\n#define __scaly__");
    mainHeaderFile->append(program->name);
    mainHeaderFile->append("__\n\n#include \"Scaly.h\"\n");
    _Array<CompilationUnit>* compilationUnits = program->compilationUnits;
    CompilationUnit* compilationUnit = nullptr;
    size_t _compilationUnits_length = compilationUnits->length();
    for (size_t _i = 0; _i < _compilationUnits_length; _i++) {
        compilationUnit = *(*compilationUnits)[_i];
        {
            _Region _region; _Page* _p = _region.get();
            mainHeaderFile->append("#include \"");
            string* fileName = Path::getFileNameWithoutExtension(_p, compilationUnit->fileName);
            mainHeaderFile->append(fileName);
            mainHeaderFile->append(".h\"\n");
        }
    }
    mainHeaderFile->append("\nusing namespace scaly;\nnamespace ");
    mainHeaderFile->append(program->name);
    mainHeaderFile->append(" {\nFileError* _main(_Page* page, _Array<string>* arguments);\n}\n\n#endif // __scaly__");
    mainHeaderFile->append(program->name);
    mainHeaderFile->append("__\n");
}

void HeaderVisitor::collectInheritances(Program* program) {
    _Array<CompilationUnit>* compilationUnits = program->compilationUnits;
    CompilationUnit* compilationUnit = nullptr;
    size_t _compilationUnits_length = compilationUnits->length();
    for (size_t _i = 0; _i < _compilationUnits_length; _i++) {
        compilationUnit = *(*compilationUnits)[_i];
        collectInheritancesInCompilationUnit(compilationUnit);
    }
}

void HeaderVisitor::collectInheritancesInCompilationUnit(CompilationUnit* compilationUnit) {
    if (compilationUnit->statements != nullptr) {
        _Array<Statement>* statements = compilationUnit->statements;
        Statement* statement = nullptr;
        size_t _statements_length = statements->length();
        for (size_t _i = 0; _i < _statements_length; _i++) {
            statement = *(*statements)[_i];
            {
                if (statement->_isClassDeclaration()) {
                    ClassDeclaration* classDeclaration = (ClassDeclaration*)statement;
                    classes->push(classDeclaration->name);
                    if (classDeclaration->typeInheritanceClause != nullptr) {
                        TypeInheritanceClause* inheritanceClause = classDeclaration->typeInheritanceClause;
                        _Array<Inheritance>* inheritances = inheritanceClause->inheritances;
                        Inheritance* inheritance = nullptr;
                        size_t _inheritances_length = inheritances->length();
                        for (size_t _i = 0; _i < _inheritances_length; _i++) {
                            inheritance = *(*inheritances)[_i];
                            {
                                registerInheritance(classDeclaration->name, inheritance->type->name);
                            }
                        }
                    }
                }
            }
        }
    }
}

void HeaderVisitor::registerInheritance(string* className, string* baseName) {
    Inherits* inherit = nullptr;
    Inherits* inh = nullptr;
    size_t _inherits_length = inherits->length();
    for (size_t _i = 0; _i < _inherits_length; _i++) {
        inh = *(*inherits)[_i];
        {
            if (inh->name->equals(baseName))
                inherit = inh;
        }
    }
    if (inherit == nullptr) {
        inherit = new(_getPage()) Inherits(baseName);
        inherits->push(inherit);
    }
    inherit->inheritors->push(className);
}

bool HeaderVisitor::_isHeaderVisitor() { return (true); }


}
