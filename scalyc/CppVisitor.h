#ifndef __scalyc__CppVisitor__
#define __scalyc__CppVisitor__
#include "scalyc.h"
using namespace scaly;
namespace scalyc {

class CppVisitor : public SyntaxVisitor {
public:
    CppError* Execute(Program& program);
private:
    CppError* cppError;
    String* projectFile;
    
public:
    virtual bool OpenProgram(Program& program);
    virtual void CloseProgram(Program& program);
    String* programName;
    String* programDirectory;
    virtual bool OpenCompilationUnit(CompilationUnit& compilationUnit);
    virtual void CloseCompilationUnit(CompilationUnit& compilationUnit);
    virtual bool OpenStatementWithSemicolon(StatementWithSemicolon& statementWithSemicolon);
    virtual void CloseStatementWithSemicolon(StatementWithSemicolon& statementWithSemicolon);
    virtual bool OpenUseDeclaration(UseDeclaration& useDeclaration);
    virtual void CloseUseDeclaration(UseDeclaration& useDeclaration);
    virtual bool OpenPathIdentifier(PathIdentifier& pathIdentifier);
    virtual void ClosePathIdentifier(PathIdentifier& pathIdentifier);
    virtual void VisitPathItem(PathItem& pathItem);
    String* pathItemName;
    virtual bool OpenInitializer(Initializer& initializer);
    virtual void CloseInitializer(Initializer& initializer);
    virtual bool OpenConstantDeclaration(ConstantDeclaration& constantDeclaration);
    virtual void CloseConstantDeclaration(ConstantDeclaration& constantDeclaration);
    virtual bool OpenVariableDeclaration(VariableDeclaration& variableDeclaration);
    virtual void CloseVariableDeclaration(VariableDeclaration& variableDeclaration);
    virtual bool OpenBindingInitializer(BindingInitializer& bindingInitializer);
    virtual void CloseBindingInitializer(BindingInitializer& bindingInitializer);
    virtual bool OpenPatternInitializer(PatternInitializer& patternInitializer);
    virtual void ClosePatternInitializer(PatternInitializer& patternInitializer);
    virtual bool OpenAdditionalInitializer(AdditionalInitializer& additionalInitializer);
    virtual void CloseAdditionalInitializer(AdditionalInitializer& additionalInitializer);
    virtual bool OpenFunctionDeclaration(FunctionDeclaration& functionDeclaration);
    virtual void CloseFunctionDeclaration(FunctionDeclaration& functionDeclaration);
    virtual bool OpenInitializerDeclaration(InitializerDeclaration& initializerDeclaration);
    virtual void CloseInitializerDeclaration(InitializerDeclaration& initializerDeclaration);
    virtual void VisitOverride(Override& override);
    virtual void VisitStaticWord(StaticWord& staticWord);
    virtual void VisitIdentifierFunction(IdentifierFunction& identifierFunction);
    String* identifierFunctionName;
    virtual bool OpenFunctionSignature(FunctionSignature& functionSignature);
    virtual void CloseFunctionSignature(FunctionSignature& functionSignature);
    virtual bool OpenFunctionResult(FunctionResult& functionResult);
    virtual void CloseFunctionResult(FunctionResult& functionResult);
    virtual bool OpenParameterClause(ParameterClause& parameterClause);
    virtual void CloseParameterClause(ParameterClause& parameterClause);
    virtual bool OpenConstParameter(ConstParameter& constParameter);
    virtual void CloseConstParameter(ConstParameter& constParameter);
    String* constParameterName;
    virtual bool OpenVarParameter(VarParameter& varParameter);
    virtual void CloseVarParameter(VarParameter& varParameter);
    String* varParameterName;
    virtual bool OpenThrowsClause(ThrowsClause& throwsClause);
    virtual void CloseThrowsClause(ThrowsClause& throwsClause);
    virtual bool OpenEnumDeclaration(EnumDeclaration& enumDeclaration);
    virtual void CloseEnumDeclaration(EnumDeclaration& enumDeclaration);
    String* enumDeclarationName;
    virtual bool OpenEnumMember(EnumMember& enumMember);
    virtual void CloseEnumMember(EnumMember& enumMember);
    virtual bool OpenTupleType(TupleType& tupleType);
    virtual void CloseTupleType(TupleType& tupleType);
    virtual bool OpenAdditionalType(AdditionalType& additionalType);
    virtual void CloseAdditionalType(AdditionalType& additionalType);
    virtual void VisitEnumCase(EnumCase& enumCase);
    String* enumCaseName;
    virtual bool OpenAdditionalCase(AdditionalCase& additionalCase);
    virtual void CloseAdditionalCase(AdditionalCase& additionalCase);
    virtual bool OpenClassDeclaration(ClassDeclaration& classDeclaration);
    virtual void CloseClassDeclaration(ClassDeclaration& classDeclaration);
    String* classDeclarationName;
    virtual bool OpenGenericArgumentClause(GenericArgumentClause& genericArgumentClause);
    virtual void CloseGenericArgumentClause(GenericArgumentClause& genericArgumentClause);
    virtual void VisitGenericParameter(GenericParameter& genericParameter);
    String* genericParameterTypeName;
    virtual bool OpenClassMember(ClassMember& classMember);
    virtual void CloseClassMember(ClassMember& classMember);
    virtual bool OpenCodeBlock(CodeBlock& codeBlock);
    virtual void CloseCodeBlock(CodeBlock& codeBlock);
    virtual bool OpenSimpleExpression(SimpleExpression& simpleExpression);
    virtual void CloseSimpleExpression(SimpleExpression& simpleExpression);
    virtual bool OpenPrefixExpression(PrefixExpression& prefixExpression);
    virtual void ClosePrefixExpression(PrefixExpression& prefixExpression);
    virtual bool OpenPostfixExpression(PostfixExpression& postfixExpression);
    virtual void ClosePostfixExpression(PostfixExpression& postfixExpression);
    virtual bool OpenBinaryOperation(BinaryOperation& binaryOperation);
    virtual void CloseBinaryOperation(BinaryOperation& binaryOperation);
    virtual bool OpenAssignment(Assignment& assignment);
    virtual void CloseAssignment(Assignment& assignment);
    virtual bool OpenTypeQuery(TypeQuery& typeQuery);
    virtual void CloseTypeQuery(TypeQuery& typeQuery);
    virtual bool OpenTypeCast(TypeCast& typeCast);
    virtual void CloseTypeCast(TypeCast& typeCast);
    virtual bool OpenCatchClause(CatchClause& catchClause);
    virtual void CloseCatchClause(CatchClause& catchClause);
    virtual bool OpenWildCardCatchPattern(WildCardCatchPattern& wildCardCatchPattern);
    virtual void CloseWildCardCatchPattern(WildCardCatchPattern& wildCardCatchPattern);
    virtual bool OpenPathItemCatchPattern(PathItemCatchPattern& pathItemCatchPattern);
    virtual void ClosePathItemCatchPattern(PathItemCatchPattern& pathItemCatchPattern);
    virtual void VisitOperatorPostfix(OperatorPostfix& operatorPostfix);
    virtual bool OpenFunctionCall(FunctionCall& functionCall);
    virtual void CloseFunctionCall(FunctionCall& functionCall);
    virtual bool OpenExplicitMemberExpression(ExplicitMemberExpression& explicitMemberExpression);
    virtual void CloseExplicitMemberExpression(ExplicitMemberExpression& explicitMemberExpression);
    virtual bool OpenSubscript(Subscript& subscript);
    virtual void CloseSubscript(Subscript& subscript);
    virtual bool OpenExpressionElement(ExpressionElement& expressionElement);
    virtual void CloseExpressionElement(ExpressionElement& expressionElement);
    virtual bool OpenNamedMemberPostfix(NamedMemberPostfix& namedMemberPostfix);
    virtual void CloseNamedMemberPostfix(NamedMemberPostfix& namedMemberPostfix);
    virtual bool OpenParenthesizedExpression(ParenthesizedExpression& parenthesizedExpression);
    virtual void CloseParenthesizedExpression(ParenthesizedExpression& parenthesizedExpression);
    virtual void VisitLiteralExpression(LiteralExpression& literalExpression);
    virtual void VisitIdentifierExpression(IdentifierExpression& identifierExpression);
    String* identifierExpressionName;
    virtual bool OpenIfExpression(IfExpression& ifExpression);
    virtual void CloseIfExpression(IfExpression& ifExpression);
    virtual bool OpenElseClause(ElseClause& elseClause);
    virtual void CloseElseClause(ElseClause& elseClause);
    virtual bool OpenSwitchExpression(SwitchExpression& switchExpression);
    virtual void CloseSwitchExpression(SwitchExpression& switchExpression);
    virtual bool OpenCurliedSwitchBody(CurliedSwitchBody& curliedSwitchBody);
    virtual void CloseCurliedSwitchBody(CurliedSwitchBody& curliedSwitchBody);
    virtual bool OpenNakedSwitchBody(NakedSwitchBody& nakedSwitchBody);
    virtual void CloseNakedSwitchBody(NakedSwitchBody& nakedSwitchBody);
    virtual bool OpenSwitchCase(SwitchCase& switchCase);
    virtual void CloseSwitchCase(SwitchCase& switchCase);
    virtual bool OpenItemCaseLabel(ItemCaseLabel& itemCaseLabel);
    virtual void CloseItemCaseLabel(ItemCaseLabel& itemCaseLabel);
    virtual bool OpenCaseItem(CaseItem& caseItem);
    virtual void CloseCaseItem(CaseItem& caseItem);
    virtual bool OpenForExpression(ForExpression& forExpression);
    virtual void CloseForExpression(ForExpression& forExpression);
    virtual bool OpenForEach(ForEach& forEach);
    virtual void CloseForEach(ForEach& forEach);
    virtual bool OpenPlainFor(PlainFor& plainFor);
    virtual void ClosePlainFor(PlainFor& plainFor);
    virtual bool OpenReturnExpression(ReturnExpression& returnExpression);
    virtual void CloseReturnExpression(ReturnExpression& returnExpression);
    virtual bool OpenThrowExpression(ThrowExpression& throwExpression);
    virtual void CloseThrowExpression(ThrowExpression& throwExpression);
    virtual bool OpenBreakExpression(BreakExpression& breakExpression);
    virtual void CloseBreakExpression(BreakExpression& breakExpression);
    virtual void VisitWildcardPattern(WildcardPattern& wildcardPattern);
    virtual bool OpenIdentifierPattern(IdentifierPattern& identifierPattern);
    virtual void CloseIdentifierPattern(IdentifierPattern& identifierPattern);
    String* identifierPatternIdentifier;
    virtual bool OpenTuplePattern(TuplePattern& tuplePattern);
    virtual void CloseTuplePattern(TuplePattern& tuplePattern);
    virtual bool OpenTuplePatternElement(TuplePatternElement& tuplePatternElement);
    virtual void CloseTuplePatternElement(TuplePatternElement& tuplePatternElement);
    virtual bool OpenExpressionPattern(ExpressionPattern& expressionPattern);
    virtual void CloseExpressionPattern(ExpressionPattern& expressionPattern);
    virtual void VisitDefaultCaseLabel(DefaultCaseLabel& defaultCaseLabel);
    virtual bool OpenBlockCaseContent(BlockCaseContent& blockCaseContent);
    virtual void CloseBlockCaseContent(BlockCaseContent& blockCaseContent);
    virtual void VisitEmptyCaseContent(EmptyCaseContent& emptyCaseContent);
    virtual bool OpenInitializerCall(InitializerCall& initializerCall);
    virtual void CloseInitializerCall(InitializerCall& initializerCall);
    virtual bool OpenThisDot(ThisDot& thisDot);
    virtual void CloseThisDot(ThisDot& thisDot);
    virtual bool OpenThisSubscript(ThisSubscript& thisSubscript);
    virtual void CloseThisSubscript(ThisSubscript& thisSubscript);
    virtual void VisitThisWord(ThisWord& thisWord);
    virtual void VisitThisInit(ThisInit& thisInit);
    virtual void VisitThisMember(ThisMember& thisMember);
    String* thisMemberName;
    virtual bool OpenSuperDot(SuperDot& superDot);
    virtual void CloseSuperDot(SuperDot& superDot);
    virtual bool OpenSuperSubscript(SuperSubscript& superSubscript);
    virtual void CloseSuperSubscript(SuperSubscript& superSubscript);
    virtual void VisitSuperInit(SuperInit& superInit);
    virtual void VisitSuperMember(SuperMember& superMember);
    String* superMemberName;
    virtual bool OpenTypeAnnotation(TypeAnnotation& typeAnnotation);
    virtual void CloseTypeAnnotation(TypeAnnotation& typeAnnotation);
    virtual bool OpenTypeIdentifier(TypeIdentifier& typeIdentifier);
    virtual void CloseTypeIdentifier(TypeIdentifier& typeIdentifier);
    String* typeIdentifierName;
    virtual bool OpenSubtypeIdentifier(SubtypeIdentifier& subtypeIdentifier);
    virtual void CloseSubtypeIdentifier(SubtypeIdentifier& subtypeIdentifier);
    virtual bool OpenArrayType(ArrayType& arrayType);
    virtual void CloseArrayType(ArrayType& arrayType);
    virtual void VisitOptionalType(OptionalType& optionalType);
    virtual bool OpenTypeInheritanceClause(TypeInheritanceClause& typeInheritanceClause);
    virtual void CloseTypeInheritanceClause(TypeInheritanceClause& typeInheritanceClause);
    virtual bool OpenInheritance(Inheritance& inheritance);
    virtual void CloseInheritance(Inheritance& inheritance);
};

}
#endif // __scalyc__CppVisitor__
