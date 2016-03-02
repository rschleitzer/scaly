#include "scalyc.h"
using namespace scaly;
namespace scalyc {


bool MyVisitor::openProgram(Program* program) {
    *programName = *program->name;
    *programDirectory = *program->directory;
    return true;
}

void MyVisitor::closeProgram(Program* program) {
    programName = 0;
    programDirectory = 0;
}

bool MyVisitor::openCompilationUnit(CompilationUnit* compilationUnit) {
    return true;
}

void MyVisitor::closeCompilationUnit(CompilationUnit* compilationUnit) {
}

bool MyVisitor::openStatementWithSemicolon(StatementWithSemicolon* statementWithSemicolon) {
    return true;
}

void MyVisitor::closeStatementWithSemicolon(StatementWithSemicolon* statementWithSemicolon) {
}

bool MyVisitor::openUseDeclaration(UseDeclaration* useDeclaration) {
    return true;
}

void MyVisitor::closeUseDeclaration(UseDeclaration* useDeclaration) {
}

bool MyVisitor::openConstantDeclaration(ConstantDeclaration* constantDeclaration) {
    return true;
}

void MyVisitor::closeConstantDeclaration(ConstantDeclaration* constantDeclaration) {
}

bool MyVisitor::openVariableDeclaration(VariableDeclaration* variableDeclaration) {
    return true;
}

void MyVisitor::closeVariableDeclaration(VariableDeclaration* variableDeclaration) {
}

bool MyVisitor::openFunctionDeclaration(FunctionDeclaration* functionDeclaration) {
    return true;
}

void MyVisitor::closeFunctionDeclaration(FunctionDeclaration* functionDeclaration) {
}

bool MyVisitor::openEnumDeclaration(EnumDeclaration* enumDeclaration) {
    *enumDeclarationName = *enumDeclaration->name;
    return true;
}

void MyVisitor::closeEnumDeclaration(EnumDeclaration* enumDeclaration) {
    enumDeclarationName = 0;
}

bool MyVisitor::openClassDeclaration(ClassDeclaration* classDeclaration) {
    *classDeclarationName = *classDeclaration->name;
    return true;
}

void MyVisitor::closeClassDeclaration(ClassDeclaration* classDeclaration) {
    classDeclarationName = 0;
}

bool MyVisitor::openInitializerDeclaration(InitializerDeclaration* initializerDeclaration) {
    return true;
}

void MyVisitor::closeInitializerDeclaration(InitializerDeclaration* initializerDeclaration) {
}

bool MyVisitor::openCodeBlock(CodeBlock* codeBlock) {
    return true;
}

void MyVisitor::closeCodeBlock(CodeBlock* codeBlock) {
}

bool MyVisitor::openSimpleExpression(SimpleExpression* simpleExpression) {
    return true;
}

void MyVisitor::closeSimpleExpression(SimpleExpression* simpleExpression) {
}

bool MyVisitor::openPathIdentifier(PathIdentifier* pathIdentifier) {
    return true;
}

void MyVisitor::closePathIdentifier(PathIdentifier* pathIdentifier) {
}

void MyVisitor::visitPathItem(PathItem* pathItem) {
}

bool MyVisitor::openInitializer(Initializer* initializer) {
    return true;
}

void MyVisitor::closeInitializer(Initializer* initializer) {
}

bool MyVisitor::openBindingInitializer(BindingInitializer* bindingInitializer) {
    return true;
}

void MyVisitor::closeBindingInitializer(BindingInitializer* bindingInitializer) {
}

bool MyVisitor::openPatternInitializer(PatternInitializer* patternInitializer) {
    return true;
}

void MyVisitor::closePatternInitializer(PatternInitializer* patternInitializer) {
}

bool MyVisitor::openAdditionalInitializer(AdditionalInitializer* additionalInitializer) {
    return true;
}

void MyVisitor::closeAdditionalInitializer(AdditionalInitializer* additionalInitializer) {
}

void MyVisitor::visitOverrideWord(OverrideWord* overrideWord) {
}

void MyVisitor::visitStaticWord(StaticWord* staticWord) {
}

void MyVisitor::visitIdentifierFunction(IdentifierFunction* identifierFunction) {
}

bool MyVisitor::openFunctionSignature(FunctionSignature* functionSignature) {
    return true;
}

void MyVisitor::closeFunctionSignature(FunctionSignature* functionSignature) {
}

bool MyVisitor::openFunctionResult(FunctionResult* functionResult) {
    return true;
}

void MyVisitor::closeFunctionResult(FunctionResult* functionResult) {
}

bool MyVisitor::openParameterClause(ParameterClause* parameterClause) {
    return true;
}

void MyVisitor::closeParameterClause(ParameterClause* parameterClause) {
}

bool MyVisitor::openConstParameter(ConstParameter* constParameter) {
    *constParameterName = *constParameter->name;
    return true;
}

void MyVisitor::closeConstParameter(ConstParameter* constParameter) {
    constParameterName = 0;
}

bool MyVisitor::openVarParameter(VarParameter* varParameter) {
    *varParameterName = *varParameter->name;
    return true;
}

void MyVisitor::closeVarParameter(VarParameter* varParameter) {
    varParameterName = 0;
}

bool MyVisitor::openThrowsClause(ThrowsClause* throwsClause) {
    return true;
}

void MyVisitor::closeThrowsClause(ThrowsClause* throwsClause) {
}

bool MyVisitor::openEnumMember(EnumMember* enumMember) {
    return true;
}

void MyVisitor::closeEnumMember(EnumMember* enumMember) {
}

void MyVisitor::visitEnumCase(EnumCase* enumCase) {
}

bool MyVisitor::openAdditionalCase(AdditionalCase* additionalCase) {
    return true;
}

void MyVisitor::closeAdditionalCase(AdditionalCase* additionalCase) {
}

bool MyVisitor::openClassBody(ClassBody* classBody) {
    return true;
}

void MyVisitor::closeClassBody(ClassBody* classBody) {
}

bool MyVisitor::openGenericArgumentClause(GenericArgumentClause* genericArgumentClause) {
    return true;
}

void MyVisitor::closeGenericArgumentClause(GenericArgumentClause* genericArgumentClause) {
}

void MyVisitor::visitGenericParameter(GenericParameter* genericParameter) {
}

bool MyVisitor::openClassMember(ClassMember* classMember) {
    return true;
}

void MyVisitor::closeClassMember(ClassMember* classMember) {
}

bool MyVisitor::openPrefixExpression(PrefixExpression* prefixExpression) {
    return true;
}

void MyVisitor::closePrefixExpression(PrefixExpression* prefixExpression) {
}

bool MyVisitor::openPostfixExpression(PostfixExpression* postfixExpression) {
    return true;
}

void MyVisitor::closePostfixExpression(PostfixExpression* postfixExpression) {
}

bool MyVisitor::openBinaryOperation(BinaryOperation* binaryOperation) {
    return true;
}

void MyVisitor::closeBinaryOperation(BinaryOperation* binaryOperation) {
}

bool MyVisitor::openAssignment(Assignment* assignment) {
    return true;
}

void MyVisitor::closeAssignment(Assignment* assignment) {
}

bool MyVisitor::openTypeQuery(TypeQuery* typeQuery) {
    return true;
}

void MyVisitor::closeTypeQuery(TypeQuery* typeQuery) {
}

bool MyVisitor::openTypeCast(TypeCast* typeCast) {
    return true;
}

void MyVisitor::closeTypeCast(TypeCast* typeCast) {
}

bool MyVisitor::openCatchClause(CatchClause* catchClause) {
    return true;
}

void MyVisitor::closeCatchClause(CatchClause* catchClause) {
}

bool MyVisitor::openWildCardCatchPattern(WildCardCatchPattern* wildCardCatchPattern) {
    return true;
}

void MyVisitor::closeWildCardCatchPattern(WildCardCatchPattern* wildCardCatchPattern) {
}

bool MyVisitor::openPathItemCatchPattern(PathItemCatchPattern* pathItemCatchPattern) {
    return true;
}

void MyVisitor::closePathItemCatchPattern(PathItemCatchPattern* pathItemCatchPattern) {
}

void MyVisitor::visitOperatorPostfix(OperatorPostfix* operatorPostfix) {
}

bool MyVisitor::openFunctionCall(FunctionCall* functionCall) {
    return true;
}

void MyVisitor::closeFunctionCall(FunctionCall* functionCall) {
}

bool MyVisitor::openExplicitMemberExpression(ExplicitMemberExpression* explicitMemberExpression) {
    return true;
}

void MyVisitor::closeExplicitMemberExpression(ExplicitMemberExpression* explicitMemberExpression) {
}

bool MyVisitor::openSubscript(Subscript* subscript) {
    return true;
}

void MyVisitor::closeSubscript(Subscript* subscript) {
}

bool MyVisitor::openExpressionElement(ExpressionElement* expressionElement) {
    return true;
}

void MyVisitor::closeExpressionElement(ExpressionElement* expressionElement) {
}

bool MyVisitor::openNamedMemberPostfix(NamedMemberPostfix* namedMemberPostfix) {
    return true;
}

void MyVisitor::closeNamedMemberPostfix(NamedMemberPostfix* namedMemberPostfix) {
}

void MyVisitor::visitIdentifierExpression(IdentifierExpression* identifierExpression) {
}

void MyVisitor::visitLiteralExpression(LiteralExpression* literalExpression) {
}

bool MyVisitor::openIfExpression(IfExpression* ifExpression) {
    return true;
}

void MyVisitor::closeIfExpression(IfExpression* ifExpression) {
}

bool MyVisitor::openSwitchExpression(SwitchExpression* switchExpression) {
    return true;
}

void MyVisitor::closeSwitchExpression(SwitchExpression* switchExpression) {
}

bool MyVisitor::openForExpression(ForExpression* forExpression) {
    return true;
}

void MyVisitor::closeForExpression(ForExpression* forExpression) {
}

bool MyVisitor::openParenthesizedExpression(ParenthesizedExpression* parenthesizedExpression) {
    return true;
}

void MyVisitor::closeParenthesizedExpression(ParenthesizedExpression* parenthesizedExpression) {
}

bool MyVisitor::openReturnExpression(ReturnExpression* returnExpression) {
    return true;
}

void MyVisitor::closeReturnExpression(ReturnExpression* returnExpression) {
}

bool MyVisitor::openThrowExpression(ThrowExpression* throwExpression) {
    return true;
}

void MyVisitor::closeThrowExpression(ThrowExpression* throwExpression) {
}

bool MyVisitor::openBreakExpression(BreakExpression* breakExpression) {
    return true;
}

void MyVisitor::closeBreakExpression(BreakExpression* breakExpression) {
}

bool MyVisitor::openInitializerCall(InitializerCall* initializerCall) {
    return true;
}

void MyVisitor::closeInitializerCall(InitializerCall* initializerCall) {
}

bool MyVisitor::openThisDot(ThisDot* thisDot) {
    return true;
}

void MyVisitor::closeThisDot(ThisDot* thisDot) {
}

bool MyVisitor::openThisSubscript(ThisSubscript* thisSubscript) {
    return true;
}

void MyVisitor::closeThisSubscript(ThisSubscript* thisSubscript) {
}

void MyVisitor::visitThisWord(ThisWord* thisWord) {
}

bool MyVisitor::openSuperDot(SuperDot* superDot) {
    return true;
}

void MyVisitor::closeSuperDot(SuperDot* superDot) {
}

bool MyVisitor::openSuperSubscript(SuperSubscript* superSubscript) {
    return true;
}

void MyVisitor::closeSuperSubscript(SuperSubscript* superSubscript) {
}

bool MyVisitor::openElseClause(ElseClause* elseClause) {
    return true;
}

void MyVisitor::closeElseClause(ElseClause* elseClause) {
}

bool MyVisitor::openCurliedSwitchBody(CurliedSwitchBody* curliedSwitchBody) {
    return true;
}

void MyVisitor::closeCurliedSwitchBody(CurliedSwitchBody* curliedSwitchBody) {
}

bool MyVisitor::openNakedSwitchBody(NakedSwitchBody* nakedSwitchBody) {
    return true;
}

void MyVisitor::closeNakedSwitchBody(NakedSwitchBody* nakedSwitchBody) {
}

bool MyVisitor::openSwitchCase(SwitchCase* switchCase) {
    return true;
}

void MyVisitor::closeSwitchCase(SwitchCase* switchCase) {
}

bool MyVisitor::openItemCaseLabel(ItemCaseLabel* itemCaseLabel) {
    return true;
}

void MyVisitor::closeItemCaseLabel(ItemCaseLabel* itemCaseLabel) {
}

void MyVisitor::visitDefaultCaseLabel(DefaultCaseLabel* defaultCaseLabel) {
}

bool MyVisitor::openCaseItem(CaseItem* caseItem) {
    return true;
}

void MyVisitor::closeCaseItem(CaseItem* caseItem) {
}

bool MyVisitor::openForEach(ForEach* forEach) {
    return true;
}

void MyVisitor::closeForEach(ForEach* forEach) {
}

bool MyVisitor::openPlainFor(PlainFor* plainFor) {
    return true;
}

void MyVisitor::closePlainFor(PlainFor* plainFor) {
}

void MyVisitor::visitWildcardPattern(WildcardPattern* wildcardPattern) {
}

bool MyVisitor::openIdentifierPattern(IdentifierPattern* identifierPattern) {
    *identifierPatternIdentifier = *identifierPattern->identifier;
    return true;
}

void MyVisitor::closeIdentifierPattern(IdentifierPattern* identifierPattern) {
    identifierPatternIdentifier = 0;
}

bool MyVisitor::openTuplePattern(TuplePattern* tuplePattern) {
    return true;
}

void MyVisitor::closeTuplePattern(TuplePattern* tuplePattern) {
}

bool MyVisitor::openExpressionPattern(ExpressionPattern* expressionPattern) {
    return true;
}

void MyVisitor::closeExpressionPattern(ExpressionPattern* expressionPattern) {
}

bool MyVisitor::openTuplePatternElement(TuplePatternElement* tuplePatternElement) {
    return true;
}

void MyVisitor::closeTuplePatternElement(TuplePatternElement* tuplePatternElement) {
}

bool MyVisitor::openBlockCaseContent(BlockCaseContent* blockCaseContent) {
    return true;
}

void MyVisitor::closeBlockCaseContent(BlockCaseContent* blockCaseContent) {
}

void MyVisitor::visitEmptyCaseContent(EmptyCaseContent* emptyCaseContent) {
}

void MyVisitor::visitThisInit(ThisInit* thisInit) {
}

void MyVisitor::visitThisMember(ThisMember* thisMember) {
}

void MyVisitor::visitSuperInit(SuperInit* superInit) {
}

void MyVisitor::visitSuperMember(SuperMember* superMember) {
}

bool MyVisitor::openTypeIdentifier(TypeIdentifier* typeIdentifier) {
    *typeIdentifierName = *typeIdentifier->name;
    return true;
}

void MyVisitor::closeTypeIdentifier(TypeIdentifier* typeIdentifier) {
    typeIdentifierName = 0;
}

bool MyVisitor::openArrayType(ArrayType* arrayType) {
    return true;
}

void MyVisitor::closeArrayType(ArrayType* arrayType) {
}

bool MyVisitor::openTypeAnnotation(TypeAnnotation* typeAnnotation) {
    return true;
}

void MyVisitor::closeTypeAnnotation(TypeAnnotation* typeAnnotation) {
}

bool MyVisitor::openSubtypeIdentifier(SubtypeIdentifier* subtypeIdentifier) {
    return true;
}

void MyVisitor::closeSubtypeIdentifier(SubtypeIdentifier* subtypeIdentifier) {
}

void MyVisitor::visitOptionalType(OptionalType* optionalType) {
}

bool MyVisitor::openTypeInheritanceClause(TypeInheritanceClause* typeInheritanceClause) {
    return true;
}

void MyVisitor::closeTypeInheritanceClause(TypeInheritanceClause* typeInheritanceClause) {
}

bool MyVisitor::openInheritance(Inheritance* inheritance) {
    return true;
}

void MyVisitor::closeInheritance(Inheritance* inheritance) {
}

bool SyntaxVisitor::_isSyntaxVisitor() { return true; }
bool SyntaxVisitor::_isMyVisitor() { return false; }
bool SyntaxVisitor::_isCppVisitor() { return false; }
bool MyVisitor::_isMyVisitor() { return true; }
}
