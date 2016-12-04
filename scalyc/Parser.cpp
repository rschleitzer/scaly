#include "scalyc.h"
using namespace scaly;
namespace scalyc {

bool Visitor::openProgram(Program* program) {
    return true;
}

void Visitor::closeProgram(Program* program) {
}

bool Visitor::openCompilationUnit(CompilationUnit* compilationUnit) {
    return true;
}

void Visitor::closeCompilationUnit(CompilationUnit* compilationUnit) {
}

bool Visitor::openConstantDeclaration(ConstantDeclaration* constantDeclaration) {
    return true;
}

void Visitor::closeConstantDeclaration(ConstantDeclaration* constantDeclaration) {
}

bool Visitor::openVariableDeclaration(VariableDeclaration* variableDeclaration) {
    return true;
}

void Visitor::closeVariableDeclaration(VariableDeclaration* variableDeclaration) {
}

bool Visitor::openMutableDeclaration(MutableDeclaration* mutableDeclaration) {
    return true;
}

void Visitor::closeMutableDeclaration(MutableDeclaration* mutableDeclaration) {
}

bool Visitor::openFunctionDeclaration(FunctionDeclaration* functionDeclaration) {
    return true;
}

void Visitor::closeFunctionDeclaration(FunctionDeclaration* functionDeclaration) {
}

bool Visitor::openEnumDeclaration(EnumDeclaration* enumDeclaration) {
    return true;
}

void Visitor::closeEnumDeclaration(EnumDeclaration* enumDeclaration) {
}

bool Visitor::openClassDeclaration(ClassDeclaration* classDeclaration) {
    return true;
}

void Visitor::closeClassDeclaration(ClassDeclaration* classDeclaration) {
}

bool Visitor::openConstructorDeclaration(ConstructorDeclaration* constructorDeclaration) {
    return true;
}

void Visitor::closeConstructorDeclaration(ConstructorDeclaration* constructorDeclaration) {
}

bool Visitor::openCodeBlock(CodeBlock* codeBlock) {
    return true;
}

void Visitor::closeCodeBlock(CodeBlock* codeBlock) {
}

bool Visitor::openSimpleExpression(SimpleExpression* simpleExpression) {
    return true;
}

void Visitor::closeSimpleExpression(SimpleExpression* simpleExpression) {
}

bool Visitor::openInitializer(Initializer* initializer) {
    return true;
}

void Visitor::closeInitializer(Initializer* initializer) {
}

bool Visitor::openBindingInitializer(BindingInitializer* bindingInitializer) {
    return true;
}

void Visitor::closeBindingInitializer(BindingInitializer* bindingInitializer) {
}

bool Visitor::openPatternInitializer(PatternInitializer* patternInitializer) {
    return true;
}

void Visitor::closePatternInitializer(PatternInitializer* patternInitializer) {
}

bool Visitor::openAdditionalInitializer(AdditionalInitializer* additionalInitializer) {
    return true;
}

void Visitor::closeAdditionalInitializer(AdditionalInitializer* additionalInitializer) {
}

void Visitor::visitOverrideWord(OverrideWord* overrideWord) {
}

void Visitor::visitStaticWord(StaticWord* staticWord) {
}

bool Visitor::openFunctionSignature(FunctionSignature* functionSignature) {
    return true;
}

void Visitor::closeFunctionSignature(FunctionSignature* functionSignature) {
}

bool Visitor::openFunctionResult(FunctionResult* functionResult) {
    return true;
}

void Visitor::closeFunctionResult(FunctionResult* functionResult) {
}

bool Visitor::openParameterClause(ParameterClause* parameterClause) {
    return true;
}

void Visitor::closeParameterClause(ParameterClause* parameterClause) {
}

bool Visitor::openConstParameter(ConstParameter* constParameter) {
    return true;
}

void Visitor::closeConstParameter(ConstParameter* constParameter) {
}

bool Visitor::openVarParameter(VarParameter* varParameter) {
    return true;
}

void Visitor::closeVarParameter(VarParameter* varParameter) {
}

bool Visitor::openThrowsClause(ThrowsClause* throwsClause) {
    return true;
}

void Visitor::closeThrowsClause(ThrowsClause* throwsClause) {
}

bool Visitor::openEnumMember(EnumMember* enumMember) {
    return true;
}

void Visitor::closeEnumMember(EnumMember* enumMember) {
}

void Visitor::visitEnumCase(EnumCase* enumCase) {
}

bool Visitor::openAdditionalCase(AdditionalCase* additionalCase) {
    return true;
}

void Visitor::closeAdditionalCase(AdditionalCase* additionalCase) {
}

bool Visitor::openClassBody(ClassBody* classBody) {
    return true;
}

void Visitor::closeClassBody(ClassBody* classBody) {
}

bool Visitor::openClassMember(ClassMember* classMember) {
    return true;
}

void Visitor::closeClassMember(ClassMember* classMember) {
}

bool Visitor::openPrefixExpression(PrefixExpression* prefixExpression) {
    return true;
}

void Visitor::closePrefixExpression(PrefixExpression* prefixExpression) {
}

bool Visitor::openPostfixExpression(PostfixExpression* postfixExpression) {
    return true;
}

void Visitor::closePostfixExpression(PostfixExpression* postfixExpression) {
}

bool Visitor::openBinaryOperation(BinaryOperation* binaryOperation) {
    return true;
}

void Visitor::closeBinaryOperation(BinaryOperation* binaryOperation) {
}

bool Visitor::openAssignment(Assignment* assignment) {
    return true;
}

void Visitor::closeAssignment(Assignment* assignment) {
}

bool Visitor::openTypeQuery(TypeQuery* typeQuery) {
    return true;
}

void Visitor::closeTypeQuery(TypeQuery* typeQuery) {
}

bool Visitor::openTypeCast(TypeCast* typeCast) {
    return true;
}

void Visitor::closeTypeCast(TypeCast* typeCast) {
}

bool Visitor::openCatchClause(CatchClause* catchClause) {
    return true;
}

void Visitor::closeCatchClause(CatchClause* catchClause) {
}

bool Visitor::openWildCardCatchPattern(WildCardCatchPattern* wildCardCatchPattern) {
    return true;
}

void Visitor::closeWildCardCatchPattern(WildCardCatchPattern* wildCardCatchPattern) {
}

bool Visitor::openIdentifierCatchPattern(IdentifierCatchPattern* identifierCatchPattern) {
    return true;
}

void Visitor::closeIdentifierCatchPattern(IdentifierCatchPattern* identifierCatchPattern) {
}

void Visitor::visitOperatorPostfix(OperatorPostfix* operatorPostfix) {
}

bool Visitor::openFunctionCall(FunctionCall* functionCall) {
    return true;
}

void Visitor::closeFunctionCall(FunctionCall* functionCall) {
}

void Visitor::visitMemberExpression(MemberExpression* memberExpression) {
}

bool Visitor::openSubscript(Subscript* subscript) {
    return true;
}

void Visitor::closeSubscript(Subscript* subscript) {
}

bool Visitor::openExpressionElement(ExpressionElement* expressionElement) {
    return true;
}

void Visitor::closeExpressionElement(ExpressionElement* expressionElement) {
}

void Visitor::visitIdentifierExpression(IdentifierExpression* identifierExpression) {
}

void Visitor::visitLiteralExpression(LiteralExpression* literalExpression) {
}

bool Visitor::openIfExpression(IfExpression* ifExpression) {
    return true;
}

void Visitor::closeIfExpression(IfExpression* ifExpression) {
}

bool Visitor::openSwitchExpression(SwitchExpression* switchExpression) {
    return true;
}

void Visitor::closeSwitchExpression(SwitchExpression* switchExpression) {
}

bool Visitor::openForExpression(ForExpression* forExpression) {
    return true;
}

void Visitor::closeForExpression(ForExpression* forExpression) {
}

bool Visitor::openWhileExpression(WhileExpression* whileExpression) {
    return true;
}

void Visitor::closeWhileExpression(WhileExpression* whileExpression) {
}

bool Visitor::openDoExpression(DoExpression* doExpression) {
    return true;
}

void Visitor::closeDoExpression(DoExpression* doExpression) {
}

bool Visitor::openParenthesizedExpression(ParenthesizedExpression* parenthesizedExpression) {
    return true;
}

void Visitor::closeParenthesizedExpression(ParenthesizedExpression* parenthesizedExpression) {
}

bool Visitor::openReturnExpression(ReturnExpression* returnExpression) {
    return true;
}

void Visitor::closeReturnExpression(ReturnExpression* returnExpression) {
}

bool Visitor::openThrowExpression(ThrowExpression* throwExpression) {
    return true;
}

void Visitor::closeThrowExpression(ThrowExpression* throwExpression) {
}

bool Visitor::openBreakExpression(BreakExpression* breakExpression) {
    return true;
}

void Visitor::closeBreakExpression(BreakExpression* breakExpression) {
}

bool Visitor::openConstructorCall(ConstructorCall* constructorCall) {
    return true;
}

void Visitor::closeConstructorCall(ConstructorCall* constructorCall) {
}

void Visitor::visitThisExpression(ThisExpression* thisExpression) {
}

void Visitor::visitNullExpression(NullExpression* nullExpression) {
}

bool Visitor::openElseClause(ElseClause* elseClause) {
    return true;
}

void Visitor::closeElseClause(ElseClause* elseClause) {
}

bool Visitor::openCurliedSwitchBody(CurliedSwitchBody* curliedSwitchBody) {
    return true;
}

void Visitor::closeCurliedSwitchBody(CurliedSwitchBody* curliedSwitchBody) {
}

bool Visitor::openNakedSwitchBody(NakedSwitchBody* nakedSwitchBody) {
    return true;
}

void Visitor::closeNakedSwitchBody(NakedSwitchBody* nakedSwitchBody) {
}

bool Visitor::openSwitchCase(SwitchCase* switchCase) {
    return true;
}

void Visitor::closeSwitchCase(SwitchCase* switchCase) {
}

bool Visitor::openItemCaseLabel(ItemCaseLabel* itemCaseLabel) {
    return true;
}

void Visitor::closeItemCaseLabel(ItemCaseLabel* itemCaseLabel) {
}

void Visitor::visitDefaultCaseLabel(DefaultCaseLabel* defaultCaseLabel) {
}

bool Visitor::openCaseItem(CaseItem* caseItem) {
    return true;
}

void Visitor::closeCaseItem(CaseItem* caseItem) {
}

void Visitor::visitWildcardPattern(WildcardPattern* wildcardPattern) {
}

bool Visitor::openIdentifierPattern(IdentifierPattern* identifierPattern) {
    return true;
}

void Visitor::closeIdentifierPattern(IdentifierPattern* identifierPattern) {
}

bool Visitor::openTuplePattern(TuplePattern* tuplePattern) {
    return true;
}

void Visitor::closeTuplePattern(TuplePattern* tuplePattern) {
}

bool Visitor::openExpressionPattern(ExpressionPattern* expressionPattern) {
    return true;
}

void Visitor::closeExpressionPattern(ExpressionPattern* expressionPattern) {
}

bool Visitor::openTuplePatternElement(TuplePatternElement* tuplePatternElement) {
    return true;
}

void Visitor::closeTuplePatternElement(TuplePatternElement* tuplePatternElement) {
}

bool Visitor::openCaseContent(CaseContent* caseContent) {
    return true;
}

void Visitor::closeCaseContent(CaseContent* caseContent) {
}

bool Visitor::openType(Type* type) {
    return true;
}

void Visitor::closeType(Type* type) {
}

bool Visitor::openTypeAnnotation(TypeAnnotation* typeAnnotation) {
    return true;
}

void Visitor::closeTypeAnnotation(TypeAnnotation* typeAnnotation) {
}

bool Visitor::openSubtype(Subtype* subtype) {
    return true;
}

void Visitor::closeSubtype(Subtype* subtype) {
}

bool Visitor::openIndexedType(IndexedType* indexedType) {
    return true;
}

void Visitor::closeIndexedType(IndexedType* indexedType) {
}

void Visitor::visitPointer(Pointer* pointer) {
}

void Visitor::visitRoot(Root* root) {
}

void Visitor::visitLocal(Local* local) {
}

void Visitor::visitReference(Reference* reference) {
}

void Visitor::visitThrown(Thrown* thrown) {
}

bool Visitor::openTypeInheritanceClause(TypeInheritanceClause* typeInheritanceClause) {
    return true;
}

void Visitor::closeTypeInheritanceClause(TypeInheritanceClause* typeInheritanceClause) {
}

bool Visitor::openInheritance(Inheritance* inheritance) {
    return true;
}

void Visitor::closeInheritance(Inheritance* inheritance) {
}

bool Visitor::_isCppVisitor() { return (false); }
bool Visitor::_isHeaderVisitor() { return (false); }
bool Visitor::_isSourceVisitor() { return (false); }

bool SyntaxNode::_isProgram() { return (false); }
bool SyntaxNode::_isCompilationUnit() { return (false); }
bool SyntaxNode::_isStatement() { return (false); }
bool SyntaxNode::_isDeclaration() { return (false); }
bool SyntaxNode::_isConstantDeclaration() { return (false); }
bool SyntaxNode::_isVariableDeclaration() { return (false); }
bool SyntaxNode::_isMutableDeclaration() { return (false); }
bool SyntaxNode::_isFunctionDeclaration() { return (false); }
bool SyntaxNode::_isEnumDeclaration() { return (false); }
bool SyntaxNode::_isClassDeclaration() { return (false); }
bool SyntaxNode::_isConstructorDeclaration() { return (false); }
bool SyntaxNode::_isExpression() { return (false); }
bool SyntaxNode::_isCodeBlock() { return (false); }
bool SyntaxNode::_isSimpleExpression() { return (false); }
bool SyntaxNode::_isInitializer() { return (false); }
bool SyntaxNode::_isBindingInitializer() { return (false); }
bool SyntaxNode::_isPatternInitializer() { return (false); }
bool SyntaxNode::_isAdditionalInitializer() { return (false); }
bool SyntaxNode::_isModifier() { return (false); }
bool SyntaxNode::_isOverrideWord() { return (false); }
bool SyntaxNode::_isStaticWord() { return (false); }
bool SyntaxNode::_isFunctionSignature() { return (false); }
bool SyntaxNode::_isFunctionResult() { return (false); }
bool SyntaxNode::_isParameterClause() { return (false); }
bool SyntaxNode::_isParameter() { return (false); }
bool SyntaxNode::_isConstParameter() { return (false); }
bool SyntaxNode::_isVarParameter() { return (false); }
bool SyntaxNode::_isThrowsClause() { return (false); }
bool SyntaxNode::_isEnumMember() { return (false); }
bool SyntaxNode::_isEnumCase() { return (false); }
bool SyntaxNode::_isAdditionalCase() { return (false); }
bool SyntaxNode::_isClassBody() { return (false); }
bool SyntaxNode::_isClassMember() { return (false); }
bool SyntaxNode::_isPrefixExpression() { return (false); }
bool SyntaxNode::_isPostfixExpression() { return (false); }
bool SyntaxNode::_isBinaryOp() { return (false); }
bool SyntaxNode::_isBinaryOperation() { return (false); }
bool SyntaxNode::_isAssignment() { return (false); }
bool SyntaxNode::_isTypeQuery() { return (false); }
bool SyntaxNode::_isTypeCast() { return (false); }
bool SyntaxNode::_isCatchClause() { return (false); }
bool SyntaxNode::_isCatchPattern() { return (false); }
bool SyntaxNode::_isWildCardCatchPattern() { return (false); }
bool SyntaxNode::_isIdentifierCatchPattern() { return (false); }
bool SyntaxNode::_isPostfix() { return (false); }
bool SyntaxNode::_isOperatorPostfix() { return (false); }
bool SyntaxNode::_isFunctionCall() { return (false); }
bool SyntaxNode::_isMemberExpression() { return (false); }
bool SyntaxNode::_isSubscript() { return (false); }
bool SyntaxNode::_isExpressionElement() { return (false); }
bool SyntaxNode::_isPrimaryExpression() { return (false); }
bool SyntaxNode::_isIdentifierExpression() { return (false); }
bool SyntaxNode::_isLiteralExpression() { return (false); }
bool SyntaxNode::_isIfExpression() { return (false); }
bool SyntaxNode::_isSwitchExpression() { return (false); }
bool SyntaxNode::_isForExpression() { return (false); }
bool SyntaxNode::_isWhileExpression() { return (false); }
bool SyntaxNode::_isDoExpression() { return (false); }
bool SyntaxNode::_isParenthesizedExpression() { return (false); }
bool SyntaxNode::_isReturnExpression() { return (false); }
bool SyntaxNode::_isThrowExpression() { return (false); }
bool SyntaxNode::_isBreakExpression() { return (false); }
bool SyntaxNode::_isConstructorCall() { return (false); }
bool SyntaxNode::_isThisExpression() { return (false); }
bool SyntaxNode::_isNullExpression() { return (false); }
bool SyntaxNode::_isElseClause() { return (false); }
bool SyntaxNode::_isSwitchBody() { return (false); }
bool SyntaxNode::_isCurliedSwitchBody() { return (false); }
bool SyntaxNode::_isNakedSwitchBody() { return (false); }
bool SyntaxNode::_isSwitchCase() { return (false); }
bool SyntaxNode::_isCaseLabel() { return (false); }
bool SyntaxNode::_isItemCaseLabel() { return (false); }
bool SyntaxNode::_isDefaultCaseLabel() { return (false); }
bool SyntaxNode::_isCaseItem() { return (false); }
bool SyntaxNode::_isPattern() { return (false); }
bool SyntaxNode::_isWildcardPattern() { return (false); }
bool SyntaxNode::_isIdentifierPattern() { return (false); }
bool SyntaxNode::_isTuplePattern() { return (false); }
bool SyntaxNode::_isExpressionPattern() { return (false); }
bool SyntaxNode::_isTuplePatternElement() { return (false); }
bool SyntaxNode::_isCaseContent() { return (false); }
bool SyntaxNode::_isType() { return (false); }
bool SyntaxNode::_isTypeAnnotation() { return (false); }
bool SyntaxNode::_isSubtype() { return (false); }
bool SyntaxNode::_isTypePostfix() { return (false); }
bool SyntaxNode::_isIndexedType() { return (false); }
bool SyntaxNode::_isPointer() { return (false); }
bool SyntaxNode::_isLifeTime() { return (false); }
bool SyntaxNode::_isRoot() { return (false); }
bool SyntaxNode::_isLocal() { return (false); }
bool SyntaxNode::_isReference() { return (false); }
bool SyntaxNode::_isThrown() { return (false); }
bool SyntaxNode::_isTypeInheritanceClause() { return (false); }
bool SyntaxNode::_isInheritance() { return (false); }

Program::Program(string* name, string* directory, _Array<CompilationUnit>* compilationUnits) {
    start = new(_getPage()) Position(0, 0);
    end = new(_getPage()) Position(0, 0);
    this->name = name;
    this->directory = directory;
    this->compilationUnits = compilationUnits;
    this->parent = nullptr;
}

void Program::accept(Visitor* visitor) {
    if (!visitor->openProgram(this))
        return;
    if (compilationUnits != nullptr) {
        CompilationUnit* node = nullptr;
        size_t _compilationUnits_length = compilationUnits->length();
        for (size_t _i = 0; _i < _compilationUnits_length; _i++) {
            node = *(*compilationUnits)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeProgram(this);
}

bool Program::_isProgram() { return (true); }

CompilationUnit::CompilationUnit(_Array<Statement>* statements, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->statements = statements;
}

void CompilationUnit::accept(Visitor* visitor) {
    if (!visitor->openCompilationUnit(this))
        return;
    if (statements != nullptr) {
        Statement* node = nullptr;
        size_t _statements_length = statements->length();
        for (size_t _i = 0; _i < _statements_length; _i++) {
            node = *(*statements)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeCompilationUnit(this);
}

bool CompilationUnit::_isCompilationUnit() { return (true); }

void Statement::accept(Visitor* visitor) {
}

bool Statement::_isStatement() { return (true); }

bool Statement::_isDeclaration() { return (false); }
bool Statement::_isConstantDeclaration() { return (false); }
bool Statement::_isVariableDeclaration() { return (false); }
bool Statement::_isMutableDeclaration() { return (false); }
bool Statement::_isFunctionDeclaration() { return (false); }
bool Statement::_isEnumDeclaration() { return (false); }
bool Statement::_isClassDeclaration() { return (false); }
bool Statement::_isConstructorDeclaration() { return (false); }
bool Statement::_isExpression() { return (false); }
bool Statement::_isCodeBlock() { return (false); }
bool Statement::_isSimpleExpression() { return (false); }

void Declaration::accept(Visitor* visitor) {
}

bool Declaration::_isDeclaration() { return (true); }

bool Declaration::_isConstantDeclaration() { return (false); }
bool Declaration::_isVariableDeclaration() { return (false); }
bool Declaration::_isMutableDeclaration() { return (false); }
bool Declaration::_isFunctionDeclaration() { return (false); }
bool Declaration::_isEnumDeclaration() { return (false); }
bool Declaration::_isClassDeclaration() { return (false); }
bool Declaration::_isConstructorDeclaration() { return (false); }

void Expression::accept(Visitor* visitor) {
}

bool Expression::_isExpression() { return (true); }

bool Expression::_isCodeBlock() { return (false); }
bool Expression::_isSimpleExpression() { return (false); }

ConstantDeclaration::ConstantDeclaration(BindingInitializer* initializer, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->initializer = initializer;
}

void ConstantDeclaration::accept(Visitor* visitor) {
    if (!visitor->openConstantDeclaration(this))
        return;
    initializer->accept(visitor);
    visitor->closeConstantDeclaration(this);
}

bool ConstantDeclaration::_isConstantDeclaration() { return (true); }

VariableDeclaration::VariableDeclaration(BindingInitializer* initializer, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->initializer = initializer;
}

void VariableDeclaration::accept(Visitor* visitor) {
    if (!visitor->openVariableDeclaration(this))
        return;
    initializer->accept(visitor);
    visitor->closeVariableDeclaration(this);
}

bool VariableDeclaration::_isVariableDeclaration() { return (true); }

MutableDeclaration::MutableDeclaration(BindingInitializer* initializer, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->initializer = initializer;
}

void MutableDeclaration::accept(Visitor* visitor) {
    if (!visitor->openMutableDeclaration(this))
        return;
    initializer->accept(visitor);
    visitor->closeMutableDeclaration(this);
}

bool MutableDeclaration::_isMutableDeclaration() { return (true); }

FunctionDeclaration::FunctionDeclaration(_Array<Modifier>* modifiers, string* name, FunctionSignature* signature, Expression* body, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->modifiers = modifiers;
    this->name = name;
    this->signature = signature;
    this->body = body;
}

void FunctionDeclaration::accept(Visitor* visitor) {
    if (!visitor->openFunctionDeclaration(this))
        return;
    if (modifiers != nullptr) {
        Modifier* node = nullptr;
        size_t _modifiers_length = modifiers->length();
        for (size_t _i = 0; _i < _modifiers_length; _i++) {
            node = *(*modifiers)[_i];
            node->accept(visitor);
        }
    }
    signature->accept(visitor);
    if (body != nullptr)
        body->accept(visitor);
    visitor->closeFunctionDeclaration(this);
}

bool FunctionDeclaration::_isFunctionDeclaration() { return (true); }

EnumDeclaration::EnumDeclaration(string* name, _Array<EnumMember>* members, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->name = name;
    this->members = members;
}

void EnumDeclaration::accept(Visitor* visitor) {
    if (!visitor->openEnumDeclaration(this))
        return;
    if (members != nullptr) {
        EnumMember* node = nullptr;
        size_t _members_length = members->length();
        for (size_t _i = 0; _i < _members_length; _i++) {
            node = *(*members)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeEnumDeclaration(this);
}

bool EnumDeclaration::_isEnumDeclaration() { return (true); }

ClassDeclaration::ClassDeclaration(string* name, TypeInheritanceClause* typeInheritanceClause, ClassBody* body, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->name = name;
    this->typeInheritanceClause = typeInheritanceClause;
    this->body = body;
}

void ClassDeclaration::accept(Visitor* visitor) {
    if (!visitor->openClassDeclaration(this))
        return;
    if (typeInheritanceClause != nullptr)
        typeInheritanceClause->accept(visitor);
    if (body != nullptr)
        body->accept(visitor);
    visitor->closeClassDeclaration(this);
}

bool ClassDeclaration::_isClassDeclaration() { return (true); }

ConstructorDeclaration::ConstructorDeclaration(ParameterClause* parameterClause, Expression* body, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->parameterClause = parameterClause;
    this->body = body;
}

void ConstructorDeclaration::accept(Visitor* visitor) {
    if (!visitor->openConstructorDeclaration(this))
        return;
    parameterClause->accept(visitor);
    body->accept(visitor);
    visitor->closeConstructorDeclaration(this);
}

bool ConstructorDeclaration::_isConstructorDeclaration() { return (true); }

CodeBlock::CodeBlock(_Array<Statement>* statements, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->statements = statements;
}

void CodeBlock::accept(Visitor* visitor) {
    if (!visitor->openCodeBlock(this))
        return;
    if (statements != nullptr) {
        Statement* node = nullptr;
        size_t _statements_length = statements->length();
        for (size_t _i = 0; _i < _statements_length; _i++) {
            node = *(*statements)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeCodeBlock(this);
}

bool CodeBlock::_isCodeBlock() { return (true); }

SimpleExpression::SimpleExpression(PrefixExpression* prefixExpression, _Array<BinaryOp>* binaryOps, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->prefixExpression = prefixExpression;
    this->binaryOps = binaryOps;
}

void SimpleExpression::accept(Visitor* visitor) {
    if (!visitor->openSimpleExpression(this))
        return;
    prefixExpression->accept(visitor);
    if (binaryOps != nullptr) {
        BinaryOp* node = nullptr;
        size_t _binaryOps_length = binaryOps->length();
        for (size_t _i = 0; _i < _binaryOps_length; _i++) {
            node = *(*binaryOps)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeSimpleExpression(this);
}

bool SimpleExpression::_isSimpleExpression() { return (true); }

Initializer::Initializer(Expression* expression, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->expression = expression;
}

void Initializer::accept(Visitor* visitor) {
    if (!visitor->openInitializer(this))
        return;
    expression->accept(visitor);
    visitor->closeInitializer(this);
}

bool Initializer::_isInitializer() { return (true); }

BindingInitializer::BindingInitializer(PatternInitializer* initializer, _Array<AdditionalInitializer>* additionalInitializers, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->initializer = initializer;
    this->additionalInitializers = additionalInitializers;
}

void BindingInitializer::accept(Visitor* visitor) {
    if (!visitor->openBindingInitializer(this))
        return;
    initializer->accept(visitor);
    if (additionalInitializers != nullptr) {
        AdditionalInitializer* node = nullptr;
        size_t _additionalInitializers_length = additionalInitializers->length();
        for (size_t _i = 0; _i < _additionalInitializers_length; _i++) {
            node = *(*additionalInitializers)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeBindingInitializer(this);
}

bool BindingInitializer::_isBindingInitializer() { return (true); }

PatternInitializer::PatternInitializer(Pattern* pattern, Initializer* initializer, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->pattern = pattern;
    this->initializer = initializer;
}

void PatternInitializer::accept(Visitor* visitor) {
    if (!visitor->openPatternInitializer(this))
        return;
    pattern->accept(visitor);
    if (initializer != nullptr)
        initializer->accept(visitor);
    visitor->closePatternInitializer(this);
}

bool PatternInitializer::_isPatternInitializer() { return (true); }

AdditionalInitializer::AdditionalInitializer(PatternInitializer* pattern, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->pattern = pattern;
}

void AdditionalInitializer::accept(Visitor* visitor) {
    if (!visitor->openAdditionalInitializer(this))
        return;
    pattern->accept(visitor);
    visitor->closeAdditionalInitializer(this);
}

bool AdditionalInitializer::_isAdditionalInitializer() { return (true); }

void Modifier::accept(Visitor* visitor) {
}

bool Modifier::_isModifier() { return (true); }

bool Modifier::_isOverrideWord() { return (false); }
bool Modifier::_isStaticWord() { return (false); }

OverrideWord::OverrideWord(Position* start, Position* end) {
    this->start = start;
    this->end = end;
}

void OverrideWord::accept(Visitor* visitor) {
    visitor->visitOverrideWord(this);
}

bool OverrideWord::_isOverrideWord() { return (true); }

StaticWord::StaticWord(Position* start, Position* end) {
    this->start = start;
    this->end = end;
}

void StaticWord::accept(Visitor* visitor) {
    visitor->visitStaticWord(this);
}

bool StaticWord::_isStaticWord() { return (true); }

FunctionSignature::FunctionSignature(ParameterClause* parameterClause, FunctionResult* result, ThrowsClause* throwsClause, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->parameterClause = parameterClause;
    this->result = result;
    this->throwsClause = throwsClause;
}

void FunctionSignature::accept(Visitor* visitor) {
    if (!visitor->openFunctionSignature(this))
        return;
    parameterClause->accept(visitor);
    if (result != nullptr)
        result->accept(visitor);
    if (throwsClause != nullptr)
        throwsClause->accept(visitor);
    visitor->closeFunctionSignature(this);
}

bool FunctionSignature::_isFunctionSignature() { return (true); }

FunctionResult::FunctionResult(Type* resultType, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->resultType = resultType;
}

void FunctionResult::accept(Visitor* visitor) {
    if (!visitor->openFunctionResult(this))
        return;
    resultType->accept(visitor);
    visitor->closeFunctionResult(this);
}

bool FunctionResult::_isFunctionResult() { return (true); }

ParameterClause::ParameterClause(_Array<Parameter>* parameters, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->parameters = parameters;
}

void ParameterClause::accept(Visitor* visitor) {
    if (!visitor->openParameterClause(this))
        return;
    if (parameters != nullptr) {
        Parameter* node = nullptr;
        size_t _parameters_length = parameters->length();
        for (size_t _i = 0; _i < _parameters_length; _i++) {
            node = *(*parameters)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeParameterClause(this);
}

bool ParameterClause::_isParameterClause() { return (true); }

void Parameter::accept(Visitor* visitor) {
}

bool Parameter::_isParameter() { return (true); }

bool Parameter::_isConstParameter() { return (false); }
bool Parameter::_isVarParameter() { return (false); }

ConstParameter::ConstParameter(string* name, Type* parameterType, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->name = name;
    this->parameterType = parameterType;
}

void ConstParameter::accept(Visitor* visitor) {
    if (!visitor->openConstParameter(this))
        return;
    parameterType->accept(visitor);
    visitor->closeConstParameter(this);
}

bool ConstParameter::_isConstParameter() { return (true); }

VarParameter::VarParameter(string* name, Type* parameterType, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->name = name;
    this->parameterType = parameterType;
}

void VarParameter::accept(Visitor* visitor) {
    if (!visitor->openVarParameter(this))
        return;
    parameterType->accept(visitor);
    visitor->closeVarParameter(this);
}

bool VarParameter::_isVarParameter() { return (true); }

ThrowsClause::ThrowsClause(Type* throwsType, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->throwsType = throwsType;
}

void ThrowsClause::accept(Visitor* visitor) {
    if (!visitor->openThrowsClause(this))
        return;
    throwsType->accept(visitor);
    visitor->closeThrowsClause(this);
}

bool ThrowsClause::_isThrowsClause() { return (true); }

EnumMember::EnumMember(EnumCase* enumCase, _Array<AdditionalCase>* additionalCases, ParameterClause* parameterClause, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->enumCase = enumCase;
    this->additionalCases = additionalCases;
    this->parameterClause = parameterClause;
}

void EnumMember::accept(Visitor* visitor) {
    if (!visitor->openEnumMember(this))
        return;
    enumCase->accept(visitor);
    if (additionalCases != nullptr) {
        AdditionalCase* node = nullptr;
        size_t _additionalCases_length = additionalCases->length();
        for (size_t _i = 0; _i < _additionalCases_length; _i++) {
            node = *(*additionalCases)[_i];
            node->accept(visitor);
        }
    }
    if (parameterClause != nullptr)
        parameterClause->accept(visitor);
    visitor->closeEnumMember(this);
}

bool EnumMember::_isEnumMember() { return (true); }

EnumCase::EnumCase(string* name, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->name = name;
}

void EnumCase::accept(Visitor* visitor) {
    visitor->visitEnumCase(this);
}

bool EnumCase::_isEnumCase() { return (true); }

AdditionalCase::AdditionalCase(EnumCase* enumCase, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->enumCase = enumCase;
}

void AdditionalCase::accept(Visitor* visitor) {
    if (!visitor->openAdditionalCase(this))
        return;
    enumCase->accept(visitor);
    visitor->closeAdditionalCase(this);
}

bool AdditionalCase::_isAdditionalCase() { return (true); }

ClassBody::ClassBody(_Array<ClassMember>* members, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->members = members;
}

void ClassBody::accept(Visitor* visitor) {
    if (!visitor->openClassBody(this))
        return;
    if (members != nullptr) {
        ClassMember* node = nullptr;
        size_t _members_length = members->length();
        for (size_t _i = 0; _i < _members_length; _i++) {
            node = *(*members)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeClassBody(this);
}

bool ClassBody::_isClassBody() { return (true); }

ClassMember::ClassMember(Declaration* declaration, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->declaration = declaration;
}

void ClassMember::accept(Visitor* visitor) {
    if (!visitor->openClassMember(this))
        return;
    declaration->accept(visitor);
    visitor->closeClassMember(this);
}

bool ClassMember::_isClassMember() { return (true); }

PrefixExpression::PrefixExpression(string* prefixOperator, PostfixExpression* expression, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->prefixOperator = prefixOperator;
    this->expression = expression;
}

void PrefixExpression::accept(Visitor* visitor) {
    if (!visitor->openPrefixExpression(this))
        return;
    expression->accept(visitor);
    visitor->closePrefixExpression(this);
}

bool PrefixExpression::_isPrefixExpression() { return (true); }

PostfixExpression::PostfixExpression(PrimaryExpression* primaryExpression, _Array<Postfix>* postfixes, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->primaryExpression = primaryExpression;
    this->postfixes = postfixes;
}

void PostfixExpression::accept(Visitor* visitor) {
    if (!visitor->openPostfixExpression(this))
        return;
    primaryExpression->accept(visitor);
    if (postfixes != nullptr) {
        Postfix* node = nullptr;
        size_t _postfixes_length = postfixes->length();
        for (size_t _i = 0; _i < _postfixes_length; _i++) {
            node = *(*postfixes)[_i];
            node->accept(visitor);
        }
    }
    visitor->closePostfixExpression(this);
}

bool PostfixExpression::_isPostfixExpression() { return (true); }

void BinaryOp::accept(Visitor* visitor) {
}

bool BinaryOp::_isBinaryOp() { return (true); }

bool BinaryOp::_isBinaryOperation() { return (false); }
bool BinaryOp::_isAssignment() { return (false); }
bool BinaryOp::_isTypeQuery() { return (false); }
bool BinaryOp::_isTypeCast() { return (false); }

BinaryOperation::BinaryOperation(string* binaryOperator, PrefixExpression* expression, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->binaryOperator = binaryOperator;
    this->expression = expression;
}

void BinaryOperation::accept(Visitor* visitor) {
    if (!visitor->openBinaryOperation(this))
        return;
    expression->accept(visitor);
    visitor->closeBinaryOperation(this);
}

bool BinaryOperation::_isBinaryOperation() { return (true); }

Assignment::Assignment(Expression* expression, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->expression = expression;
}

void Assignment::accept(Visitor* visitor) {
    if (!visitor->openAssignment(this))
        return;
    expression->accept(visitor);
    visitor->closeAssignment(this);
}

bool Assignment::_isAssignment() { return (true); }

TypeQuery::TypeQuery(Type* objectType, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->objectType = objectType;
}

void TypeQuery::accept(Visitor* visitor) {
    if (!visitor->openTypeQuery(this))
        return;
    objectType->accept(visitor);
    visitor->closeTypeQuery(this);
}

bool TypeQuery::_isTypeQuery() { return (true); }

TypeCast::TypeCast(Type* objectType, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->objectType = objectType;
}

void TypeCast::accept(Visitor* visitor) {
    if (!visitor->openTypeCast(this))
        return;
    objectType->accept(visitor);
    visitor->closeTypeCast(this);
}

bool TypeCast::_isTypeCast() { return (true); }

CatchClause::CatchClause(CatchPattern* catchPattern, TuplePattern* bindingPattern, Expression* expression, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->catchPattern = catchPattern;
    this->bindingPattern = bindingPattern;
    this->expression = expression;
}

void CatchClause::accept(Visitor* visitor) {
    if (!visitor->openCatchClause(this))
        return;
    catchPattern->accept(visitor);
    if (bindingPattern != nullptr)
        bindingPattern->accept(visitor);
    expression->accept(visitor);
    visitor->closeCatchClause(this);
}

bool CatchClause::_isCatchClause() { return (true); }

void CatchPattern::accept(Visitor* visitor) {
}

bool CatchPattern::_isCatchPattern() { return (true); }

bool CatchPattern::_isWildCardCatchPattern() { return (false); }
bool CatchPattern::_isIdentifierCatchPattern() { return (false); }

WildCardCatchPattern::WildCardCatchPattern(WildcardPattern* pattern, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->pattern = pattern;
}

void WildCardCatchPattern::accept(Visitor* visitor) {
    if (!visitor->openWildCardCatchPattern(this))
        return;
    pattern->accept(visitor);
    visitor->closeWildCardCatchPattern(this);
}

bool WildCardCatchPattern::_isWildCardCatchPattern() { return (true); }

IdentifierCatchPattern::IdentifierCatchPattern(string* name, MemberExpression* member, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->name = name;
    this->member = member;
}

void IdentifierCatchPattern::accept(Visitor* visitor) {
    if (!visitor->openIdentifierCatchPattern(this))
        return;
    if (member != nullptr)
        member->accept(visitor);
    visitor->closeIdentifierCatchPattern(this);
}

bool IdentifierCatchPattern::_isIdentifierCatchPattern() { return (true); }

void Postfix::accept(Visitor* visitor) {
}

bool Postfix::_isPostfix() { return (true); }

bool Postfix::_isOperatorPostfix() { return (false); }
bool Postfix::_isFunctionCall() { return (false); }
bool Postfix::_isMemberExpression() { return (false); }
bool Postfix::_isSubscript() { return (false); }

OperatorPostfix::OperatorPostfix(string* postfixOperator, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->postfixOperator = postfixOperator;
}

void OperatorPostfix::accept(Visitor* visitor) {
    visitor->visitOperatorPostfix(this);
}

bool OperatorPostfix::_isOperatorPostfix() { return (true); }

FunctionCall::FunctionCall(ParenthesizedExpression* arguments, _Array<CatchClause>* catchClauses, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->arguments = arguments;
    this->catchClauses = catchClauses;
}

void FunctionCall::accept(Visitor* visitor) {
    if (!visitor->openFunctionCall(this))
        return;
    arguments->accept(visitor);
    if (catchClauses != nullptr) {
        CatchClause* node = nullptr;
        size_t _catchClauses_length = catchClauses->length();
        for (size_t _i = 0; _i < _catchClauses_length; _i++) {
            node = *(*catchClauses)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeFunctionCall(this);
}

bool FunctionCall::_isFunctionCall() { return (true); }

MemberExpression::MemberExpression(string* member, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->member = member;
}

void MemberExpression::accept(Visitor* visitor) {
    visitor->visitMemberExpression(this);
}

bool MemberExpression::_isMemberExpression() { return (true); }

Subscript::Subscript(_Array<ExpressionElement>* expressions, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->expressions = expressions;
}

void Subscript::accept(Visitor* visitor) {
    if (!visitor->openSubscript(this))
        return;
    if (expressions != nullptr) {
        ExpressionElement* node = nullptr;
        size_t _expressions_length = expressions->length();
        for (size_t _i = 0; _i < _expressions_length; _i++) {
            node = *(*expressions)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeSubscript(this);
}

bool Subscript::_isSubscript() { return (true); }

ExpressionElement::ExpressionElement(Expression* expression, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->expression = expression;
}

void ExpressionElement::accept(Visitor* visitor) {
    if (!visitor->openExpressionElement(this))
        return;
    expression->accept(visitor);
    visitor->closeExpressionElement(this);
}

bool ExpressionElement::_isExpressionElement() { return (true); }

void PrimaryExpression::accept(Visitor* visitor) {
}

bool PrimaryExpression::_isPrimaryExpression() { return (true); }

bool PrimaryExpression::_isIdentifierExpression() { return (false); }
bool PrimaryExpression::_isLiteralExpression() { return (false); }
bool PrimaryExpression::_isIfExpression() { return (false); }
bool PrimaryExpression::_isSwitchExpression() { return (false); }
bool PrimaryExpression::_isForExpression() { return (false); }
bool PrimaryExpression::_isWhileExpression() { return (false); }
bool PrimaryExpression::_isDoExpression() { return (false); }
bool PrimaryExpression::_isParenthesizedExpression() { return (false); }
bool PrimaryExpression::_isReturnExpression() { return (false); }
bool PrimaryExpression::_isThrowExpression() { return (false); }
bool PrimaryExpression::_isBreakExpression() { return (false); }
bool PrimaryExpression::_isConstructorCall() { return (false); }
bool PrimaryExpression::_isThisExpression() { return (false); }
bool PrimaryExpression::_isNullExpression() { return (false); }

IdentifierExpression::IdentifierExpression(string* name, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->name = name;
}

void IdentifierExpression::accept(Visitor* visitor) {
    visitor->visitIdentifierExpression(this);
}

bool IdentifierExpression::_isIdentifierExpression() { return (true); }

LiteralExpression::LiteralExpression(Literal* literal, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->literal = literal;
}

void LiteralExpression::accept(Visitor* visitor) {
    visitor->visitLiteralExpression(this);
}

bool LiteralExpression::_isLiteralExpression() { return (true); }

IfExpression::IfExpression(Expression* condition, Expression* consequent, ElseClause* elseClause, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->condition = condition;
    this->consequent = consequent;
    this->elseClause = elseClause;
}

void IfExpression::accept(Visitor* visitor) {
    if (!visitor->openIfExpression(this))
        return;
    condition->accept(visitor);
    consequent->accept(visitor);
    if (elseClause != nullptr)
        elseClause->accept(visitor);
    visitor->closeIfExpression(this);
}

bool IfExpression::_isIfExpression() { return (true); }

SwitchExpression::SwitchExpression(Expression* expression, SwitchBody* body, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->expression = expression;
    this->body = body;
}

void SwitchExpression::accept(Visitor* visitor) {
    if (!visitor->openSwitchExpression(this))
        return;
    expression->accept(visitor);
    body->accept(visitor);
    visitor->closeSwitchExpression(this);
}

bool SwitchExpression::_isSwitchExpression() { return (true); }

ForExpression::ForExpression(Pattern* pattern, Expression* expression, Expression* code, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->pattern = pattern;
    this->expression = expression;
    this->code = code;
}

void ForExpression::accept(Visitor* visitor) {
    if (!visitor->openForExpression(this))
        return;
    pattern->accept(visitor);
    expression->accept(visitor);
    code->accept(visitor);
    visitor->closeForExpression(this);
}

bool ForExpression::_isForExpression() { return (true); }

WhileExpression::WhileExpression(Expression* condition, Expression* code, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->condition = condition;
    this->code = code;
}

void WhileExpression::accept(Visitor* visitor) {
    if (!visitor->openWhileExpression(this))
        return;
    condition->accept(visitor);
    code->accept(visitor);
    visitor->closeWhileExpression(this);
}

bool WhileExpression::_isWhileExpression() { return (true); }

DoExpression::DoExpression(Expression* code, Expression* condition, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->code = code;
    this->condition = condition;
}

void DoExpression::accept(Visitor* visitor) {
    if (!visitor->openDoExpression(this))
        return;
    code->accept(visitor);
    condition->accept(visitor);
    visitor->closeDoExpression(this);
}

bool DoExpression::_isDoExpression() { return (true); }

ParenthesizedExpression::ParenthesizedExpression(_Array<ExpressionElement>* expressionElements, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->expressionElements = expressionElements;
}

void ParenthesizedExpression::accept(Visitor* visitor) {
    if (!visitor->openParenthesizedExpression(this))
        return;
    if (expressionElements != nullptr) {
        ExpressionElement* node = nullptr;
        size_t _expressionElements_length = expressionElements->length();
        for (size_t _i = 0; _i < _expressionElements_length; _i++) {
            node = *(*expressionElements)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeParenthesizedExpression(this);
}

bool ParenthesizedExpression::_isParenthesizedExpression() { return (true); }

ReturnExpression::ReturnExpression(ParenthesizedExpression* expression, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->expression = expression;
}

void ReturnExpression::accept(Visitor* visitor) {
    if (!visitor->openReturnExpression(this))
        return;
    if (expression != nullptr)
        expression->accept(visitor);
    visitor->closeReturnExpression(this);
}

bool ReturnExpression::_isReturnExpression() { return (true); }

ThrowExpression::ThrowExpression(IdentifierExpression* error, ParenthesizedExpression* arguments, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->error = error;
    this->arguments = arguments;
}

void ThrowExpression::accept(Visitor* visitor) {
    if (!visitor->openThrowExpression(this))
        return;
    error->accept(visitor);
    if (arguments != nullptr)
        arguments->accept(visitor);
    visitor->closeThrowExpression(this);
}

bool ThrowExpression::_isThrowExpression() { return (true); }

BreakExpression::BreakExpression(ParenthesizedExpression* expression, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->expression = expression;
}

void BreakExpression::accept(Visitor* visitor) {
    if (!visitor->openBreakExpression(this))
        return;
    if (expression != nullptr)
        expression->accept(visitor);
    visitor->closeBreakExpression(this);
}

bool BreakExpression::_isBreakExpression() { return (true); }

ConstructorCall::ConstructorCall(Type* typeToConstruct, ParenthesizedExpression* arguments, _Array<CatchClause>* catchClauses, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->typeToConstruct = typeToConstruct;
    this->arguments = arguments;
    this->catchClauses = catchClauses;
}

void ConstructorCall::accept(Visitor* visitor) {
    if (!visitor->openConstructorCall(this))
        return;
    typeToConstruct->accept(visitor);
    arguments->accept(visitor);
    if (catchClauses != nullptr) {
        CatchClause* node = nullptr;
        size_t _catchClauses_length = catchClauses->length();
        for (size_t _i = 0; _i < _catchClauses_length; _i++) {
            node = *(*catchClauses)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeConstructorCall(this);
}

bool ConstructorCall::_isConstructorCall() { return (true); }

ThisExpression::ThisExpression(Position* start, Position* end) {
    this->start = start;
    this->end = end;
}

void ThisExpression::accept(Visitor* visitor) {
    visitor->visitThisExpression(this);
}

bool ThisExpression::_isThisExpression() { return (true); }

NullExpression::NullExpression(Position* start, Position* end) {
    this->start = start;
    this->end = end;
}

void NullExpression::accept(Visitor* visitor) {
    visitor->visitNullExpression(this);
}

bool NullExpression::_isNullExpression() { return (true); }

ElseClause::ElseClause(Expression* alternative, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->alternative = alternative;
}

void ElseClause::accept(Visitor* visitor) {
    if (!visitor->openElseClause(this))
        return;
    alternative->accept(visitor);
    visitor->closeElseClause(this);
}

bool ElseClause::_isElseClause() { return (true); }

void SwitchBody::accept(Visitor* visitor) {
}

bool SwitchBody::_isSwitchBody() { return (true); }

bool SwitchBody::_isCurliedSwitchBody() { return (false); }
bool SwitchBody::_isNakedSwitchBody() { return (false); }

CurliedSwitchBody::CurliedSwitchBody(_Array<SwitchCase>* cases, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->cases = cases;
}

void CurliedSwitchBody::accept(Visitor* visitor) {
    if (!visitor->openCurliedSwitchBody(this))
        return;
    if (cases != nullptr) {
        SwitchCase* node = nullptr;
        size_t _cases_length = cases->length();
        for (size_t _i = 0; _i < _cases_length; _i++) {
            node = *(*cases)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeCurliedSwitchBody(this);
}

bool CurliedSwitchBody::_isCurliedSwitchBody() { return (true); }

NakedSwitchBody::NakedSwitchBody(_Array<SwitchCase>* cases, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->cases = cases;
}

void NakedSwitchBody::accept(Visitor* visitor) {
    if (!visitor->openNakedSwitchBody(this))
        return;
    if (cases != nullptr) {
        SwitchCase* node = nullptr;
        size_t _cases_length = cases->length();
        for (size_t _i = 0; _i < _cases_length; _i++) {
            node = *(*cases)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeNakedSwitchBody(this);
}

bool NakedSwitchBody::_isNakedSwitchBody() { return (true); }

SwitchCase::SwitchCase(CaseLabel* label, CaseContent* content, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->label = label;
    this->content = content;
}

void SwitchCase::accept(Visitor* visitor) {
    if (!visitor->openSwitchCase(this))
        return;
    label->accept(visitor);
    content->accept(visitor);
    visitor->closeSwitchCase(this);
}

bool SwitchCase::_isSwitchCase() { return (true); }

void CaseLabel::accept(Visitor* visitor) {
}

bool CaseLabel::_isCaseLabel() { return (true); }

bool CaseLabel::_isItemCaseLabel() { return (false); }
bool CaseLabel::_isDefaultCaseLabel() { return (false); }

ItemCaseLabel::ItemCaseLabel(Pattern* pattern, _Array<CaseItem>* additionalPatterns, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->pattern = pattern;
    this->additionalPatterns = additionalPatterns;
}

void ItemCaseLabel::accept(Visitor* visitor) {
    if (!visitor->openItemCaseLabel(this))
        return;
    pattern->accept(visitor);
    if (additionalPatterns != nullptr) {
        CaseItem* node = nullptr;
        size_t _additionalPatterns_length = additionalPatterns->length();
        for (size_t _i = 0; _i < _additionalPatterns_length; _i++) {
            node = *(*additionalPatterns)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeItemCaseLabel(this);
}

bool ItemCaseLabel::_isItemCaseLabel() { return (true); }

DefaultCaseLabel::DefaultCaseLabel(Position* start, Position* end) {
    this->start = start;
    this->end = end;
}

void DefaultCaseLabel::accept(Visitor* visitor) {
    visitor->visitDefaultCaseLabel(this);
}

bool DefaultCaseLabel::_isDefaultCaseLabel() { return (true); }

CaseItem::CaseItem(Pattern* pattern, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->pattern = pattern;
}

void CaseItem::accept(Visitor* visitor) {
    if (!visitor->openCaseItem(this))
        return;
    pattern->accept(visitor);
    visitor->closeCaseItem(this);
}

bool CaseItem::_isCaseItem() { return (true); }

void Pattern::accept(Visitor* visitor) {
}

bool Pattern::_isPattern() { return (true); }

bool Pattern::_isWildcardPattern() { return (false); }
bool Pattern::_isIdentifierPattern() { return (false); }
bool Pattern::_isTuplePattern() { return (false); }
bool Pattern::_isExpressionPattern() { return (false); }

WildcardPattern::WildcardPattern(Position* start, Position* end) {
    this->start = start;
    this->end = end;
}

void WildcardPattern::accept(Visitor* visitor) {
    visitor->visitWildcardPattern(this);
}

bool WildcardPattern::_isWildcardPattern() { return (true); }

IdentifierPattern::IdentifierPattern(string* identifier, TypeAnnotation* annotationForType, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->identifier = identifier;
    this->annotationForType = annotationForType;
}

void IdentifierPattern::accept(Visitor* visitor) {
    if (!visitor->openIdentifierPattern(this))
        return;
    if (annotationForType != nullptr)
        annotationForType->accept(visitor);
    visitor->closeIdentifierPattern(this);
}

bool IdentifierPattern::_isIdentifierPattern() { return (true); }

TuplePattern::TuplePattern(_Array<TuplePatternElement>* elements, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->elements = elements;
}

void TuplePattern::accept(Visitor* visitor) {
    if (!visitor->openTuplePattern(this))
        return;
    if (elements != nullptr) {
        TuplePatternElement* node = nullptr;
        size_t _elements_length = elements->length();
        for (size_t _i = 0; _i < _elements_length; _i++) {
            node = *(*elements)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeTuplePattern(this);
}

bool TuplePattern::_isTuplePattern() { return (true); }

ExpressionPattern::ExpressionPattern(Expression* expression, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->expression = expression;
}

void ExpressionPattern::accept(Visitor* visitor) {
    if (!visitor->openExpressionPattern(this))
        return;
    expression->accept(visitor);
    visitor->closeExpressionPattern(this);
}

bool ExpressionPattern::_isExpressionPattern() { return (true); }

TuplePatternElement::TuplePatternElement(Pattern* pattern, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->pattern = pattern;
}

void TuplePatternElement::accept(Visitor* visitor) {
    if (!visitor->openTuplePatternElement(this))
        return;
    pattern->accept(visitor);
    visitor->closeTuplePatternElement(this);
}

bool TuplePatternElement::_isTuplePatternElement() { return (true); }

CaseContent::CaseContent(_Array<Statement>* statements, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->statements = statements;
}

void CaseContent::accept(Visitor* visitor) {
    if (!visitor->openCaseContent(this))
        return;
    if (statements != nullptr) {
        Statement* node = nullptr;
        size_t _statements_length = statements->length();
        for (size_t _i = 0; _i < _statements_length; _i++) {
            node = *(*statements)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeCaseContent(this);
}

bool CaseContent::_isCaseContent() { return (true); }

Type::Type(string* name, Subtype* subType, _Array<TypePostfix>* postfixes, LifeTime* lifeTime, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->name = name;
    this->subType = subType;
    this->postfixes = postfixes;
    this->lifeTime = lifeTime;
}

void Type::accept(Visitor* visitor) {
    if (!visitor->openType(this))
        return;
    if (subType != nullptr)
        subType->accept(visitor);
    if (postfixes != nullptr) {
        TypePostfix* node = nullptr;
        size_t _postfixes_length = postfixes->length();
        for (size_t _i = 0; _i < _postfixes_length; _i++) {
            node = *(*postfixes)[_i];
            node->accept(visitor);
        }
    }
    if (lifeTime != nullptr)
        lifeTime->accept(visitor);
    visitor->closeType(this);
}

bool Type::_isType() { return (true); }

TypeAnnotation::TypeAnnotation(Type* annotationForType, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->annotationForType = annotationForType;
}

void TypeAnnotation::accept(Visitor* visitor) {
    if (!visitor->openTypeAnnotation(this))
        return;
    annotationForType->accept(visitor);
    visitor->closeTypeAnnotation(this);
}

bool TypeAnnotation::_isTypeAnnotation() { return (true); }

Subtype::Subtype(Type* type, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->type = type;
}

void Subtype::accept(Visitor* visitor) {
    if (!visitor->openSubtype(this))
        return;
    type->accept(visitor);
    visitor->closeSubtype(this);
}

bool Subtype::_isSubtype() { return (true); }

void TypePostfix::accept(Visitor* visitor) {
}

bool TypePostfix::_isTypePostfix() { return (true); }

bool TypePostfix::_isIndexedType() { return (false); }
bool TypePostfix::_isPointer() { return (false); }

IndexedType::IndexedType(Type* key, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->key = key;
}

void IndexedType::accept(Visitor* visitor) {
    if (!visitor->openIndexedType(this))
        return;
    if (key != nullptr)
        key->accept(visitor);
    visitor->closeIndexedType(this);
}

bool IndexedType::_isIndexedType() { return (true); }

Pointer::Pointer(Position* start, Position* end) {
    this->start = start;
    this->end = end;
}

void Pointer::accept(Visitor* visitor) {
    visitor->visitPointer(this);
}

bool Pointer::_isPointer() { return (true); }

void LifeTime::accept(Visitor* visitor) {
}

bool LifeTime::_isLifeTime() { return (true); }

bool LifeTime::_isRoot() { return (false); }
bool LifeTime::_isLocal() { return (false); }
bool LifeTime::_isReference() { return (false); }
bool LifeTime::_isThrown() { return (false); }

Root::Root(Position* start, Position* end) {
    this->start = start;
    this->end = end;
}

void Root::accept(Visitor* visitor) {
    visitor->visitRoot(this);
}

bool Root::_isRoot() { return (true); }

Local::Local(string* location, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->location = location;
}

void Local::accept(Visitor* visitor) {
    visitor->visitLocal(this);
}

bool Local::_isLocal() { return (true); }

Reference::Reference(Literal* age, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->age = age;
}

void Reference::accept(Visitor* visitor) {
    visitor->visitReference(this);
}

bool Reference::_isReference() { return (true); }

Thrown::Thrown(Position* start, Position* end) {
    this->start = start;
    this->end = end;
}

void Thrown::accept(Visitor* visitor) {
    visitor->visitThrown(this);
}

bool Thrown::_isThrown() { return (true); }

TypeInheritanceClause::TypeInheritanceClause(_Array<Inheritance>* inheritances, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->inheritances = inheritances;
}

void TypeInheritanceClause::accept(Visitor* visitor) {
    if (!visitor->openTypeInheritanceClause(this))
        return;
    if (inheritances != nullptr) {
        Inheritance* node = nullptr;
        size_t _inheritances_length = inheritances->length();
        for (size_t _i = 0; _i < _inheritances_length; _i++) {
            node = *(*inheritances)[_i];
            node->accept(visitor);
        }
    }
    visitor->closeTypeInheritanceClause(this);
}

bool TypeInheritanceClause::_isTypeInheritanceClause() { return (true); }

Inheritance::Inheritance(Type* type, Position* start, Position* end) {
    this->start = start;
    this->end = end;
    this->type = type;
}

void Inheritance::accept(Visitor* visitor) {
    if (!visitor->openInheritance(this))
        return;
    type->accept(visitor);
    visitor->closeInheritance(this);
}

bool Inheritance::_isInheritance() { return (true); }

Parser::Parser(string* theFileName, string* text) {
    lexer = new(_getPage()->allocateExclusivePage()) Lexer(text);
    fileName = theFileName;
    classKeyword = new(_getPage()) string("class");
    functionKeyword = new(_getPage()) string("function");
    ifKeyword = new(_getPage()) string("if");
    elseKeyword = new(_getPage()) string("else");
    switchKeyword = new(_getPage()) string("switch");
    caseKeyword = new(_getPage()) string("case");
    defaultKeyword = new(_getPage()) string("default");
    catchKeyword = new(_getPage()) string("catch");
    forKeyword = new(_getPage()) string("for");
    inKeyword = new(_getPage()) string("in");
    whileKeyword = new(_getPage()) string("while");
    doKeyword = new(_getPage()) string("do");
    returnKeyword = new(_getPage()) string("return");
    throwKeyword = new(_getPage()) string("throw");
    breakKeyword = new(_getPage()) string("break");
    throwsKeyword = new(_getPage()) string("throws");
    overrideKeyword = new(_getPage()) string("override");
    staticKeyword = new(_getPage()) string("static");
    letKeyword = new(_getPage()) string("let");
    varKeyword = new(_getPage()) string("var");
    mutableKeyword = new(_getPage()) string("mutable");
    isKeyword = new(_getPage()) string("is");
    asKeyword = new(_getPage()) string("as");
    constructorKeyword = new(_getPage()) string("constructor");
    enumKeyword = new(_getPage()) string("enum");
    thisKeyword = new(_getPage()) string("this");
    nullKeyword = new(_getPage()) string("null");
    newKeyword = new(_getPage()) string("new");
    extendsKeyword = new(_getPage()) string("extends");
    equal = new(_getPage()) string("=");
    comma = new(_getPage()) string(",");
    leftParen = new(_getPage()) string("(");
    rightParen = new(_getPage()) string(")");
    leftCurly = new(_getPage()) string("{");
    rightCurly = new(_getPage()) string("}");
    leftBracket = new(_getPage()) string("[");
    rightBracket = new(_getPage()) string("]");
    colon = new(_getPage()) string(":");
    dot = new(_getPage()) string(".");
    underscore = new(_getPage()) string("_");
    circumflex = new(_getPage()) string("^");
    dollar = new(_getPage()) string("$");
    at = new(_getPage()) string("@");
    hash = new(_getPage()) string("#");
    ampersand = new(_getPage()) string("&");
}

_Result<CompilationUnit, ParserError> Parser::parseCompilationUnit(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _statements_result = parseStatementList(_rp, _ep);
    _Array<Statement>* statements = nullptr;
    if (_statements_result.succeeded()) {
        statements = _statements_result.getResult();
    }
    else {
        statements = nullptr;
    }
    if (statements != nullptr) {
        if (!isAtEnd()) {
            _Region _region; _Page* _p = _region.get();
            Position* current = lexer->getPosition(_p);
            return _Result<CompilationUnit, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_notAtEnd(new(_ep) Position(current))));
        }
    }
    Position* end = lexer->getPosition(_p);
    CompilationUnit* ret = new(_rp) CompilationUnit(statements, new(_rp) Position(start), new(_rp) Position(end));
    ret->fileName = fileName;
    if (statements != nullptr) {
        Statement* item = nullptr;
        size_t _statements_length = statements->length();
        for (size_t _i = 0; _i < _statements_length; _i++) {
            item = *(*statements)[_i];
            item->parent = ret;
        }
    }
    return _Result<CompilationUnit, ParserError>(ret);
}

_Result<_Array<Statement>, ParserError> Parser::parseStatementList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<Statement>* ret = nullptr;
    while (true) {
        auto _node_result = parseStatement(_rp, _ep);
        Statement* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<Statement>();
        ret->push(node);
    }
    return _Result<_Array<Statement>, ParserError>(ret ? new(_rp) _Array<Statement>(ret) : nullptr);
}

_Result<Statement, ParserError> Parser::parseStatement(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ParserError>* errors = new(_p) _Array<ParserError>();
    Position* start = lexer->getPreviousPosition(_p);
    {
        auto _node_result = parseDeclaration(_rp, _ep);
        Declaration* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Statement, ParserError>(node);
    }
    {
        auto _node_result = parseExpression(_rp, _ep);
        Expression* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Statement, ParserError>(node);
    }
    return _Result<Statement, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_unableToParse(new(_ep) Position(start), new(_ep) _Array<ParserError>(errors))));
}

_Result<Declaration, ParserError> Parser::parseDeclaration(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ParserError>* errors = new(_p) _Array<ParserError>();
    Position* start = lexer->getPreviousPosition(_p);
    {
        auto _node_result = parseConstantDeclaration(_rp, _ep);
        ConstantDeclaration* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Declaration, ParserError>(node);
    }
    {
        auto _node_result = parseVariableDeclaration(_rp, _ep);
        VariableDeclaration* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Declaration, ParserError>(node);
    }
    {
        auto _node_result = parseMutableDeclaration(_rp, _ep);
        MutableDeclaration* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Declaration, ParserError>(node);
    }
    {
        auto _node_result = parseFunctionDeclaration(_rp, _ep);
        FunctionDeclaration* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Declaration, ParserError>(node);
    }
    {
        auto _node_result = parseEnumDeclaration(_rp, _ep);
        EnumDeclaration* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Declaration, ParserError>(node);
    }
    {
        auto _node_result = parseClassDeclaration(_rp, _ep);
        ClassDeclaration* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Declaration, ParserError>(node);
    }
    {
        auto _node_result = parseConstructorDeclaration(_rp, _ep);
        ConstructorDeclaration* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Declaration, ParserError>(node);
    }
    return _Result<Declaration, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_unableToParse(new(_ep) Position(start), new(_ep) _Array<ParserError>(errors))));
}

_Result<Expression, ParserError> Parser::parseExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ParserError>* errors = new(_p) _Array<ParserError>();
    Position* start = lexer->getPreviousPosition(_p);
    {
        auto _node_result = parseCodeBlock(_rp, _ep);
        CodeBlock* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Expression, ParserError>(node);
    }
    {
        auto _node_result = parseSimpleExpression(_rp, _ep);
        SimpleExpression* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Expression, ParserError>(node);
    }
    return _Result<Expression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_unableToParse(new(_ep) Position(start), new(_ep) _Array<ParserError>(errors))));
}

_Result<ConstantDeclaration, ParserError> Parser::parseConstantDeclaration(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startLet1 = lexer->getPreviousPosition(_p);
    bool successLet1 = lexer->parseKeyword(letKeyword);
    if (successLet1)
        lexer->advance();
    else
        return _Result<ConstantDeclaration, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startLet1), new(_ep) string(letKeyword))));
    auto _initializer_result = parseBindingInitializer(_rp, _ep);
    BindingInitializer* initializer = nullptr;
    if (_initializer_result.succeeded()) {
        initializer = _initializer_result.getResult();
    }
    else {
        auto error = _initializer_result.getError();
        return _Result<ConstantDeclaration, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    ConstantDeclaration* ret = new(_rp) ConstantDeclaration(initializer, new(_rp) Position(start), new(_rp) Position(end));
    initializer->parent = ret;
    return _Result<ConstantDeclaration, ParserError>(ret);
}

_Result<VariableDeclaration, ParserError> Parser::parseVariableDeclaration(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startVar1 = lexer->getPreviousPosition(_p);
    bool successVar1 = lexer->parseKeyword(varKeyword);
    if (successVar1)
        lexer->advance();
    else
        return _Result<VariableDeclaration, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startVar1), new(_ep) string(varKeyword))));
    auto _initializer_result = parseBindingInitializer(_rp, _ep);
    BindingInitializer* initializer = nullptr;
    if (_initializer_result.succeeded()) {
        initializer = _initializer_result.getResult();
    }
    else {
        auto error = _initializer_result.getError();
        return _Result<VariableDeclaration, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    VariableDeclaration* ret = new(_rp) VariableDeclaration(initializer, new(_rp) Position(start), new(_rp) Position(end));
    initializer->parent = ret;
    return _Result<VariableDeclaration, ParserError>(ret);
}

_Result<MutableDeclaration, ParserError> Parser::parseMutableDeclaration(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startMutable1 = lexer->getPreviousPosition(_p);
    bool successMutable1 = lexer->parseKeyword(mutableKeyword);
    if (successMutable1)
        lexer->advance();
    else
        return _Result<MutableDeclaration, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startMutable1), new(_ep) string(mutableKeyword))));
    auto _initializer_result = parseBindingInitializer(_rp, _ep);
    BindingInitializer* initializer = nullptr;
    if (_initializer_result.succeeded()) {
        initializer = _initializer_result.getResult();
    }
    else {
        auto error = _initializer_result.getError();
        return _Result<MutableDeclaration, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    MutableDeclaration* ret = new(_rp) MutableDeclaration(initializer, new(_rp) Position(start), new(_rp) Position(end));
    initializer->parent = ret;
    return _Result<MutableDeclaration, ParserError>(ret);
}

_Result<FunctionDeclaration, ParserError> Parser::parseFunctionDeclaration(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _modifiers_result = parseModifierList(_rp, _ep);
    _Array<Modifier>* modifiers = nullptr;
    if (_modifiers_result.succeeded()) {
        modifiers = _modifiers_result.getResult();
    }
    else {
        modifiers = nullptr;
    }
    Position* startFunction2 = lexer->getPreviousPosition(_p);
    bool successFunction2 = lexer->parseKeyword(functionKeyword);
    if (successFunction2)
        lexer->advance();
    else
        return _Result<FunctionDeclaration, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startFunction2), new(_ep) string(functionKeyword))));
    Position* startName = lexer->getPreviousPosition(_p);
    string* name = lexer->parseIdentifier(_rp);
    if ((name != nullptr) && isIdentifier(name))
        lexer->advance();
    else
        return _Result<FunctionDeclaration, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_identifierExpected(new(_ep) Position(startName))));
    auto _signature_result = parseFunctionSignature(_rp, _ep);
    FunctionSignature* signature = nullptr;
    if (_signature_result.succeeded()) {
        signature = _signature_result.getResult();
    }
    else {
        auto error = _signature_result.getError();
        return _Result<FunctionDeclaration, ParserError>(error);
    }
    auto _body_result = parseExpression(_rp, _ep);
    Expression* body = nullptr;
    if (_body_result.succeeded()) {
        body = _body_result.getResult();
    }
    else {
        body = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    FunctionDeclaration* ret = new(_rp) FunctionDeclaration(modifiers, name, signature, body, new(_rp) Position(start), new(_rp) Position(end));
    if (modifiers != nullptr) {
        Modifier* item = nullptr;
        size_t _modifiers_length = modifiers->length();
        for (size_t _i = 0; _i < _modifiers_length; _i++) {
            item = *(*modifiers)[_i];
            item->parent = ret;
        }
    }
    signature->parent = ret;
    if (body != nullptr)
        body->parent = ret;
    return _Result<FunctionDeclaration, ParserError>(ret);
}

_Result<EnumDeclaration, ParserError> Parser::parseEnumDeclaration(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startEnum1 = lexer->getPreviousPosition(_p);
    bool successEnum1 = lexer->parseKeyword(enumKeyword);
    if (successEnum1)
        lexer->advance();
    else
        return _Result<EnumDeclaration, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startEnum1), new(_ep) string(enumKeyword))));
    Position* startName = lexer->getPreviousPosition(_p);
    string* name = lexer->parseIdentifier(_rp);
    if ((name != nullptr) && isIdentifier(name))
        lexer->advance();
    else
        return _Result<EnumDeclaration, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_identifierExpected(new(_ep) Position(startName))));
    Position* startLeftCurly3 = lexer->getPreviousPosition(_p);
    bool successLeftCurly3 = lexer->parsePunctuation(leftCurly);
    if (successLeftCurly3)
        lexer->advance();
    else
        return _Result<EnumDeclaration, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startLeftCurly3), new(_ep) string(leftCurly))));
    auto _members_result = parseEnumMemberList(_rp, _ep);
    _Array<EnumMember>* members = nullptr;
    if (_members_result.succeeded()) {
        members = _members_result.getResult();
    }
    else {
        auto error = _members_result.getError();
        return _Result<EnumDeclaration, ParserError>(error);
    }
    Position* startRightCurly5 = lexer->getPreviousPosition(_p);
    bool successRightCurly5 = lexer->parsePunctuation(rightCurly);
    if (successRightCurly5)
        lexer->advance();
    else
        return _Result<EnumDeclaration, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startRightCurly5), new(_ep) string(rightCurly))));
    Position* end = lexer->getPosition(_p);
    EnumDeclaration* ret = new(_rp) EnumDeclaration(name, members, new(_rp) Position(start), new(_rp) Position(end));
    if (members != nullptr) {
        EnumMember* item = nullptr;
        size_t _members_length = members->length();
        for (size_t _i = 0; _i < _members_length; _i++) {
            item = *(*members)[_i];
            item->parent = ret;
        }
    }
    return _Result<EnumDeclaration, ParserError>(ret);
}

_Result<ClassDeclaration, ParserError> Parser::parseClassDeclaration(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startClass1 = lexer->getPreviousPosition(_p);
    bool successClass1 = lexer->parseKeyword(classKeyword);
    if (successClass1)
        lexer->advance();
    else
        return _Result<ClassDeclaration, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startClass1), new(_ep) string(classKeyword))));
    Position* startName = lexer->getPreviousPosition(_p);
    string* name = lexer->parseIdentifier(_rp);
    if ((name != nullptr) && isIdentifier(name))
        lexer->advance();
    else
        return _Result<ClassDeclaration, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_identifierExpected(new(_ep) Position(startName))));
    auto _typeInheritanceClause_result = parseTypeInheritanceClause(_rp, _ep);
    TypeInheritanceClause* typeInheritanceClause = nullptr;
    if (_typeInheritanceClause_result.succeeded()) {
        typeInheritanceClause = _typeInheritanceClause_result.getResult();
    }
    else {
        typeInheritanceClause = nullptr;
    }
    auto _body_result = parseClassBody(_rp, _ep);
    ClassBody* body = nullptr;
    if (_body_result.succeeded()) {
        body = _body_result.getResult();
    }
    else {
        body = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    ClassDeclaration* ret = new(_rp) ClassDeclaration(name, typeInheritanceClause, body, new(_rp) Position(start), new(_rp) Position(end));
    if (typeInheritanceClause != nullptr)
        typeInheritanceClause->parent = ret;
    if (body != nullptr)
        body->parent = ret;
    return _Result<ClassDeclaration, ParserError>(ret);
}

_Result<ConstructorDeclaration, ParserError> Parser::parseConstructorDeclaration(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startConstructor1 = lexer->getPreviousPosition(_p);
    bool successConstructor1 = lexer->parseKeyword(constructorKeyword);
    if (successConstructor1)
        lexer->advance();
    else
        return _Result<ConstructorDeclaration, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startConstructor1), new(_ep) string(constructorKeyword))));
    auto _parameterClause_result = parseParameterClause(_rp, _ep);
    ParameterClause* parameterClause = nullptr;
    if (_parameterClause_result.succeeded()) {
        parameterClause = _parameterClause_result.getResult();
    }
    else {
        auto error = _parameterClause_result.getError();
        return _Result<ConstructorDeclaration, ParserError>(error);
    }
    auto _body_result = parseExpression(_rp, _ep);
    Expression* body = nullptr;
    if (_body_result.succeeded()) {
        body = _body_result.getResult();
    }
    else {
        auto error = _body_result.getError();
        return _Result<ConstructorDeclaration, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    ConstructorDeclaration* ret = new(_rp) ConstructorDeclaration(parameterClause, body, new(_rp) Position(start), new(_rp) Position(end));
    parameterClause->parent = ret;
    body->parent = ret;
    return _Result<ConstructorDeclaration, ParserError>(ret);
}

_Result<CodeBlock, ParserError> Parser::parseCodeBlock(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startLeftCurly1 = lexer->getPreviousPosition(_p);
    bool successLeftCurly1 = lexer->parsePunctuation(leftCurly);
    if (successLeftCurly1)
        lexer->advance();
    else
        return _Result<CodeBlock, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startLeftCurly1), new(_ep) string(leftCurly))));
    auto _statements_result = parseStatementList(_rp, _ep);
    _Array<Statement>* statements = nullptr;
    if (_statements_result.succeeded()) {
        statements = _statements_result.getResult();
    }
    else {
        auto error = _statements_result.getError();
        return _Result<CodeBlock, ParserError>(error);
    }
    Position* startRightCurly3 = lexer->getPreviousPosition(_p);
    bool successRightCurly3 = lexer->parsePunctuation(rightCurly);
    if (successRightCurly3)
        lexer->advance();
    else
        return _Result<CodeBlock, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startRightCurly3), new(_ep) string(rightCurly))));
    Position* end = lexer->getPosition(_p);
    CodeBlock* ret = new(_rp) CodeBlock(statements, new(_rp) Position(start), new(_rp) Position(end));
    if (statements != nullptr) {
        Statement* item = nullptr;
        size_t _statements_length = statements->length();
        for (size_t _i = 0; _i < _statements_length; _i++) {
            item = *(*statements)[_i];
            item->parent = ret;
        }
    }
    return _Result<CodeBlock, ParserError>(ret);
}

_Result<SimpleExpression, ParserError> Parser::parseSimpleExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _prefixExpression_result = parsePrefixExpression(_rp, _ep);
    PrefixExpression* prefixExpression = nullptr;
    if (_prefixExpression_result.succeeded()) {
        prefixExpression = _prefixExpression_result.getResult();
    }
    else {
        auto error = _prefixExpression_result.getError();
        return _Result<SimpleExpression, ParserError>(error);
    }
    auto _binaryOps_result = parseBinaryOpList(_rp, _ep);
    _Array<BinaryOp>* binaryOps = nullptr;
    if (_binaryOps_result.succeeded()) {
        binaryOps = _binaryOps_result.getResult();
    }
    else {
        binaryOps = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    SimpleExpression* ret = new(_rp) SimpleExpression(prefixExpression, binaryOps, new(_rp) Position(start), new(_rp) Position(end));
    prefixExpression->parent = ret;
    if (binaryOps != nullptr) {
        BinaryOp* item = nullptr;
        size_t _binaryOps_length = binaryOps->length();
        for (size_t _i = 0; _i < _binaryOps_length; _i++) {
            item = *(*binaryOps)[_i];
            item->parent = ret;
        }
    }
    return _Result<SimpleExpression, ParserError>(ret);
}

_Result<Initializer, ParserError> Parser::parseInitializer(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startEqual1 = lexer->getPreviousPosition(_p);
    bool successEqual1 = lexer->parsePunctuation(equal);
    if (successEqual1)
        lexer->advance();
    else
        return _Result<Initializer, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startEqual1), new(_ep) string(equal))));
    auto _expression_result = parseExpression(_rp, _ep);
    Expression* expression = nullptr;
    if (_expression_result.succeeded()) {
        expression = _expression_result.getResult();
    }
    else {
        auto error = _expression_result.getError();
        return _Result<Initializer, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    Initializer* ret = new(_rp) Initializer(expression, new(_rp) Position(start), new(_rp) Position(end));
    expression->parent = ret;
    return _Result<Initializer, ParserError>(ret);
}

_Result<BindingInitializer, ParserError> Parser::parseBindingInitializer(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _initializer_result = parsePatternInitializer(_rp, _ep);
    PatternInitializer* initializer = nullptr;
    if (_initializer_result.succeeded()) {
        initializer = _initializer_result.getResult();
    }
    else {
        auto error = _initializer_result.getError();
        return _Result<BindingInitializer, ParserError>(error);
    }
    auto _additionalInitializers_result = parseAdditionalInitializerList(_rp, _ep);
    _Array<AdditionalInitializer>* additionalInitializers = nullptr;
    if (_additionalInitializers_result.succeeded()) {
        additionalInitializers = _additionalInitializers_result.getResult();
    }
    else {
        additionalInitializers = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    BindingInitializer* ret = new(_rp) BindingInitializer(initializer, additionalInitializers, new(_rp) Position(start), new(_rp) Position(end));
    initializer->parent = ret;
    if (additionalInitializers != nullptr) {
        AdditionalInitializer* item = nullptr;
        size_t _additionalInitializers_length = additionalInitializers->length();
        for (size_t _i = 0; _i < _additionalInitializers_length; _i++) {
            item = *(*additionalInitializers)[_i];
            item->parent = ret;
        }
    }
    return _Result<BindingInitializer, ParserError>(ret);
}

_Result<_Array<PatternInitializer>, ParserError> Parser::parsePatternInitializerList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<PatternInitializer>* ret = nullptr;
    while (true) {
        auto _node_result = parsePatternInitializer(_rp, _ep);
        PatternInitializer* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<PatternInitializer>();
        ret->push(node);
    }
    return _Result<_Array<PatternInitializer>, ParserError>(ret ? new(_rp) _Array<PatternInitializer>(ret) : nullptr);
}

_Result<PatternInitializer, ParserError> Parser::parsePatternInitializer(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _pattern_result = parsePattern(_rp, _ep);
    Pattern* pattern = nullptr;
    if (_pattern_result.succeeded()) {
        pattern = _pattern_result.getResult();
    }
    else {
        auto error = _pattern_result.getError();
        return _Result<PatternInitializer, ParserError>(error);
    }
    auto _initializer_result = parseInitializer(_rp, _ep);
    Initializer* initializer = nullptr;
    if (_initializer_result.succeeded()) {
        initializer = _initializer_result.getResult();
    }
    else {
        initializer = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    PatternInitializer* ret = new(_rp) PatternInitializer(pattern, initializer, new(_rp) Position(start), new(_rp) Position(end));
    pattern->parent = ret;
    if (initializer != nullptr)
        initializer->parent = ret;
    return _Result<PatternInitializer, ParserError>(ret);
}

_Result<_Array<AdditionalInitializer>, ParserError> Parser::parseAdditionalInitializerList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<AdditionalInitializer>* ret = nullptr;
    while (true) {
        auto _node_result = parseAdditionalInitializer(_rp, _ep);
        AdditionalInitializer* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<AdditionalInitializer>();
        ret->push(node);
    }
    return _Result<_Array<AdditionalInitializer>, ParserError>(ret ? new(_rp) _Array<AdditionalInitializer>(ret) : nullptr);
}

_Result<AdditionalInitializer, ParserError> Parser::parseAdditionalInitializer(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startComma1 = lexer->getPreviousPosition(_p);
    bool successComma1 = lexer->parsePunctuation(comma);
    if (successComma1)
        lexer->advance();
    else
        return _Result<AdditionalInitializer, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startComma1), new(_ep) string(comma))));
    auto _pattern_result = parsePatternInitializer(_rp, _ep);
    PatternInitializer* pattern = nullptr;
    if (_pattern_result.succeeded()) {
        pattern = _pattern_result.getResult();
    }
    else {
        auto error = _pattern_result.getError();
        return _Result<AdditionalInitializer, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    AdditionalInitializer* ret = new(_rp) AdditionalInitializer(pattern, new(_rp) Position(start), new(_rp) Position(end));
    pattern->parent = ret;
    return _Result<AdditionalInitializer, ParserError>(ret);
}

_Result<_Array<Modifier>, ParserError> Parser::parseModifierList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<Modifier>* ret = nullptr;
    while (true) {
        auto _node_result = parseModifier(_rp, _ep);
        Modifier* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<Modifier>();
        ret->push(node);
    }
    return _Result<_Array<Modifier>, ParserError>(ret ? new(_rp) _Array<Modifier>(ret) : nullptr);
}

_Result<Modifier, ParserError> Parser::parseModifier(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ParserError>* errors = new(_p) _Array<ParserError>();
    Position* start = lexer->getPreviousPosition(_p);
    {
        auto _node_result = parseOverrideWord(_rp, _ep);
        OverrideWord* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Modifier, ParserError>(node);
    }
    {
        auto _node_result = parseStaticWord(_rp, _ep);
        StaticWord* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Modifier, ParserError>(node);
    }
    return _Result<Modifier, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_unableToParse(new(_ep) Position(start), new(_ep) _Array<ParserError>(errors))));
}

_Result<OverrideWord, ParserError> Parser::parseOverrideWord(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startOverride1 = lexer->getPreviousPosition(_p);
    bool successOverride1 = lexer->parseKeyword(overrideKeyword);
    if (successOverride1)
        lexer->advance();
    else
        return _Result<OverrideWord, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startOverride1), new(_ep) string(overrideKeyword))));
    Position* end = lexer->getPosition(_p);
    OverrideWord* ret = new(_rp) OverrideWord(new(_rp) Position(start), new(_rp) Position(end));
    return _Result<OverrideWord, ParserError>(ret);
}

_Result<StaticWord, ParserError> Parser::parseStaticWord(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startStatic1 = lexer->getPreviousPosition(_p);
    bool successStatic1 = lexer->parseKeyword(staticKeyword);
    if (successStatic1)
        lexer->advance();
    else
        return _Result<StaticWord, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startStatic1), new(_ep) string(staticKeyword))));
    Position* end = lexer->getPosition(_p);
    StaticWord* ret = new(_rp) StaticWord(new(_rp) Position(start), new(_rp) Position(end));
    return _Result<StaticWord, ParserError>(ret);
}

_Result<FunctionSignature, ParserError> Parser::parseFunctionSignature(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _parameterClause_result = parseParameterClause(_rp, _ep);
    ParameterClause* parameterClause = nullptr;
    if (_parameterClause_result.succeeded()) {
        parameterClause = _parameterClause_result.getResult();
    }
    else {
        auto error = _parameterClause_result.getError();
        return _Result<FunctionSignature, ParserError>(error);
    }
    auto _result_result = parseFunctionResult(_rp, _ep);
    FunctionResult* result = nullptr;
    if (_result_result.succeeded()) {
        result = _result_result.getResult();
    }
    else {
        result = nullptr;
    }
    auto _throwsClause_result = parseThrowsClause(_rp, _ep);
    ThrowsClause* throwsClause = nullptr;
    if (_throwsClause_result.succeeded()) {
        throwsClause = _throwsClause_result.getResult();
    }
    else {
        throwsClause = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    FunctionSignature* ret = new(_rp) FunctionSignature(parameterClause, result, throwsClause, new(_rp) Position(start), new(_rp) Position(end));
    parameterClause->parent = ret;
    if (result != nullptr)
        result->parent = ret;
    if (throwsClause != nullptr)
        throwsClause->parent = ret;
    return _Result<FunctionSignature, ParserError>(ret);
}

_Result<FunctionResult, ParserError> Parser::parseFunctionResult(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startColon1 = lexer->getPreviousPosition(_p);
    bool successColon1 = lexer->parsePunctuation(colon);
    if (successColon1)
        lexer->advance();
    else
        return _Result<FunctionResult, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startColon1), new(_ep) string(colon))));
    auto _resultType_result = parseType(_rp, _ep);
    Type* resultType = nullptr;
    if (_resultType_result.succeeded()) {
        resultType = _resultType_result.getResult();
    }
    else {
        auto error = _resultType_result.getError();
        return _Result<FunctionResult, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    FunctionResult* ret = new(_rp) FunctionResult(resultType, new(_rp) Position(start), new(_rp) Position(end));
    resultType->parent = ret;
    return _Result<FunctionResult, ParserError>(ret);
}

_Result<_Array<ParameterClause>, ParserError> Parser::parseParameterClauseList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ParameterClause>* ret = nullptr;
    while (true) {
        auto _node_result = parseParameterClause(_rp, _ep);
        ParameterClause* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<ParameterClause>();
        ret->push(node);
    }
    return _Result<_Array<ParameterClause>, ParserError>(ret ? new(_rp) _Array<ParameterClause>(ret) : nullptr);
}

_Result<ParameterClause, ParserError> Parser::parseParameterClause(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startLeftParen1 = lexer->getPreviousPosition(_p);
    bool successLeftParen1 = lexer->parsePunctuation(leftParen);
    if (successLeftParen1)
        lexer->advance();
    else
        return _Result<ParameterClause, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startLeftParen1), new(_ep) string(leftParen))));
    auto _parameters_result = parseParameterList(_rp, _ep);
    _Array<Parameter>* parameters = nullptr;
    if (_parameters_result.succeeded()) {
        parameters = _parameters_result.getResult();
    }
    else {
        parameters = nullptr;
    }
    Position* startRightParen3 = lexer->getPreviousPosition(_p);
    bool successRightParen3 = lexer->parsePunctuation(rightParen);
    if (successRightParen3)
        lexer->advance();
    else
        return _Result<ParameterClause, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startRightParen3), new(_ep) string(rightParen))));
    Position* end = lexer->getPosition(_p);
    ParameterClause* ret = new(_rp) ParameterClause(parameters, new(_rp) Position(start), new(_rp) Position(end));
    if (parameters != nullptr) {
        Parameter* item = nullptr;
        size_t _parameters_length = parameters->length();
        for (size_t _i = 0; _i < _parameters_length; _i++) {
            item = *(*parameters)[_i];
            item->parent = ret;
        }
    }
    return _Result<ParameterClause, ParserError>(ret);
}

_Result<_Array<Parameter>, ParserError> Parser::parseParameterList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<Parameter>* ret = nullptr;
    while (true) {
        auto _node_result = parseParameter(_rp, _ep);
        Parameter* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<Parameter>();
        ret->push(node);
    }
    return _Result<_Array<Parameter>, ParserError>(ret ? new(_rp) _Array<Parameter>(ret) : nullptr);
}

_Result<Parameter, ParserError> Parser::parseParameter(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ParserError>* errors = new(_p) _Array<ParserError>();
    Position* start = lexer->getPreviousPosition(_p);
    {
        auto _node_result = parseConstParameter(_rp, _ep);
        ConstParameter* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Parameter, ParserError>(node);
    }
    {
        auto _node_result = parseVarParameter(_rp, _ep);
        VarParameter* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Parameter, ParserError>(node);
    }
    return _Result<Parameter, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_unableToParse(new(_ep) Position(start), new(_ep) _Array<ParserError>(errors))));
}

_Result<ConstParameter, ParserError> Parser::parseConstParameter(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    bool successLet1 = lexer->parseKeyword(letKeyword);
    if (successLet1)
        lexer->advance();
    Position* startName = lexer->getPreviousPosition(_p);
    string* name = lexer->parseIdentifier(_rp);
    if ((name != nullptr) && isIdentifier(name))
        lexer->advance();
    else
        return _Result<ConstParameter, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_identifierExpected(new(_ep) Position(startName))));
    Position* startColon3 = lexer->getPreviousPosition(_p);
    bool successColon3 = lexer->parsePunctuation(colon);
    if (successColon3)
        lexer->advance();
    else
        return _Result<ConstParameter, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startColon3), new(_ep) string(colon))));
    auto _parameterType_result = parseType(_rp, _ep);
    Type* parameterType = nullptr;
    if (_parameterType_result.succeeded()) {
        parameterType = _parameterType_result.getResult();
    }
    else {
        auto error = _parameterType_result.getError();
        return _Result<ConstParameter, ParserError>(error);
    }
    bool successComma5 = lexer->parsePunctuation(comma);
    if (successComma5)
        lexer->advance();
    Position* end = lexer->getPosition(_p);
    ConstParameter* ret = new(_rp) ConstParameter(name, parameterType, new(_rp) Position(start), new(_rp) Position(end));
    parameterType->parent = ret;
    return _Result<ConstParameter, ParserError>(ret);
}

_Result<VarParameter, ParserError> Parser::parseVarParameter(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startMutable1 = lexer->getPreviousPosition(_p);
    bool successMutable1 = lexer->parseKeyword(mutableKeyword);
    if (successMutable1)
        lexer->advance();
    else
        return _Result<VarParameter, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startMutable1), new(_ep) string(mutableKeyword))));
    Position* startName = lexer->getPreviousPosition(_p);
    string* name = lexer->parseIdentifier(_rp);
    if ((name != nullptr) && isIdentifier(name))
        lexer->advance();
    else
        return _Result<VarParameter, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_identifierExpected(new(_ep) Position(startName))));
    Position* startColon3 = lexer->getPreviousPosition(_p);
    bool successColon3 = lexer->parsePunctuation(colon);
    if (successColon3)
        lexer->advance();
    else
        return _Result<VarParameter, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startColon3), new(_ep) string(colon))));
    auto _parameterType_result = parseType(_rp, _ep);
    Type* parameterType = nullptr;
    if (_parameterType_result.succeeded()) {
        parameterType = _parameterType_result.getResult();
    }
    else {
        auto error = _parameterType_result.getError();
        return _Result<VarParameter, ParserError>(error);
    }
    bool successComma5 = lexer->parsePunctuation(comma);
    if (successComma5)
        lexer->advance();
    Position* end = lexer->getPosition(_p);
    VarParameter* ret = new(_rp) VarParameter(name, parameterType, new(_rp) Position(start), new(_rp) Position(end));
    parameterType->parent = ret;
    return _Result<VarParameter, ParserError>(ret);
}

_Result<ThrowsClause, ParserError> Parser::parseThrowsClause(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startThrows1 = lexer->getPreviousPosition(_p);
    bool successThrows1 = lexer->parseKeyword(throwsKeyword);
    if (successThrows1)
        lexer->advance();
    else
        return _Result<ThrowsClause, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startThrows1), new(_ep) string(throwsKeyword))));
    auto _throwsType_result = parseType(_rp, _ep);
    Type* throwsType = nullptr;
    if (_throwsType_result.succeeded()) {
        throwsType = _throwsType_result.getResult();
    }
    else {
        auto error = _throwsType_result.getError();
        return _Result<ThrowsClause, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    ThrowsClause* ret = new(_rp) ThrowsClause(throwsType, new(_rp) Position(start), new(_rp) Position(end));
    throwsType->parent = ret;
    return _Result<ThrowsClause, ParserError>(ret);
}

_Result<_Array<EnumMember>, ParserError> Parser::parseEnumMemberList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<EnumMember>* ret = nullptr;
    while (true) {
        auto _node_result = parseEnumMember(_rp, _ep);
        EnumMember* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<EnumMember>();
        ret->push(node);
    }
    return _Result<_Array<EnumMember>, ParserError>(ret ? new(_rp) _Array<EnumMember>(ret) : nullptr);
}

_Result<EnumMember, ParserError> Parser::parseEnumMember(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startCase1 = lexer->getPreviousPosition(_p);
    bool successCase1 = lexer->parseKeyword(caseKeyword);
    if (successCase1)
        lexer->advance();
    else
        return _Result<EnumMember, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startCase1), new(_ep) string(caseKeyword))));
    auto _enumCase_result = parseEnumCase(_rp, _ep);
    EnumCase* enumCase = nullptr;
    if (_enumCase_result.succeeded()) {
        enumCase = _enumCase_result.getResult();
    }
    else {
        auto error = _enumCase_result.getError();
        return _Result<EnumMember, ParserError>(error);
    }
    auto _additionalCases_result = parseAdditionalCaseList(_rp, _ep);
    _Array<AdditionalCase>* additionalCases = nullptr;
    if (_additionalCases_result.succeeded()) {
        additionalCases = _additionalCases_result.getResult();
    }
    else {
        additionalCases = nullptr;
    }
    auto _parameterClause_result = parseParameterClause(_rp, _ep);
    ParameterClause* parameterClause = nullptr;
    if (_parameterClause_result.succeeded()) {
        parameterClause = _parameterClause_result.getResult();
    }
    else {
        parameterClause = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    EnumMember* ret = new(_rp) EnumMember(enumCase, additionalCases, parameterClause, new(_rp) Position(start), new(_rp) Position(end));
    enumCase->parent = ret;
    if (additionalCases != nullptr) {
        AdditionalCase* item = nullptr;
        size_t _additionalCases_length = additionalCases->length();
        for (size_t _i = 0; _i < _additionalCases_length; _i++) {
            item = *(*additionalCases)[_i];
            item->parent = ret;
        }
    }
    if (parameterClause != nullptr)
        parameterClause->parent = ret;
    return _Result<EnumMember, ParserError>(ret);
}

_Result<EnumCase, ParserError> Parser::parseEnumCase(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startName = lexer->getPreviousPosition(_p);
    string* name = lexer->parseIdentifier(_rp);
    if ((name != nullptr) && isIdentifier(name))
        lexer->advance();
    else
        return _Result<EnumCase, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_identifierExpected(new(_ep) Position(startName))));
    Position* end = lexer->getPosition(_p);
    EnumCase* ret = new(_rp) EnumCase(name, new(_rp) Position(start), new(_rp) Position(end));
    return _Result<EnumCase, ParserError>(ret);
}

_Result<_Array<AdditionalCase>, ParserError> Parser::parseAdditionalCaseList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<AdditionalCase>* ret = nullptr;
    while (true) {
        auto _node_result = parseAdditionalCase(_rp, _ep);
        AdditionalCase* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<AdditionalCase>();
        ret->push(node);
    }
    return _Result<_Array<AdditionalCase>, ParserError>(ret ? new(_rp) _Array<AdditionalCase>(ret) : nullptr);
}

_Result<AdditionalCase, ParserError> Parser::parseAdditionalCase(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startComma1 = lexer->getPreviousPosition(_p);
    bool successComma1 = lexer->parsePunctuation(comma);
    if (successComma1)
        lexer->advance();
    else
        return _Result<AdditionalCase, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startComma1), new(_ep) string(comma))));
    auto _enumCase_result = parseEnumCase(_rp, _ep);
    EnumCase* enumCase = nullptr;
    if (_enumCase_result.succeeded()) {
        enumCase = _enumCase_result.getResult();
    }
    else {
        auto error = _enumCase_result.getError();
        return _Result<AdditionalCase, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    AdditionalCase* ret = new(_rp) AdditionalCase(enumCase, new(_rp) Position(start), new(_rp) Position(end));
    enumCase->parent = ret;
    return _Result<AdditionalCase, ParserError>(ret);
}

_Result<ClassBody, ParserError> Parser::parseClassBody(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startLeftCurly1 = lexer->getPreviousPosition(_p);
    bool successLeftCurly1 = lexer->parsePunctuation(leftCurly);
    if (successLeftCurly1)
        lexer->advance();
    else
        return _Result<ClassBody, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startLeftCurly1), new(_ep) string(leftCurly))));
    auto _members_result = parseClassMemberList(_rp, _ep);
    _Array<ClassMember>* members = nullptr;
    if (_members_result.succeeded()) {
        members = _members_result.getResult();
    }
    else {
        members = nullptr;
    }
    Position* startRightCurly3 = lexer->getPreviousPosition(_p);
    bool successRightCurly3 = lexer->parsePunctuation(rightCurly);
    if (successRightCurly3)
        lexer->advance();
    else
        return _Result<ClassBody, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startRightCurly3), new(_ep) string(rightCurly))));
    Position* end = lexer->getPosition(_p);
    ClassBody* ret = new(_rp) ClassBody(members, new(_rp) Position(start), new(_rp) Position(end));
    if (members != nullptr) {
        ClassMember* item = nullptr;
        size_t _members_length = members->length();
        for (size_t _i = 0; _i < _members_length; _i++) {
            item = *(*members)[_i];
            item->parent = ret;
        }
    }
    return _Result<ClassBody, ParserError>(ret);
}

_Result<_Array<ClassMember>, ParserError> Parser::parseClassMemberList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ClassMember>* ret = nullptr;
    while (true) {
        auto _node_result = parseClassMember(_rp, _ep);
        ClassMember* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<ClassMember>();
        ret->push(node);
    }
    return _Result<_Array<ClassMember>, ParserError>(ret ? new(_rp) _Array<ClassMember>(ret) : nullptr);
}

_Result<ClassMember, ParserError> Parser::parseClassMember(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _declaration_result = parseDeclaration(_rp, _ep);
    Declaration* declaration = nullptr;
    if (_declaration_result.succeeded()) {
        declaration = _declaration_result.getResult();
    }
    else {
        auto error = _declaration_result.getError();
        return _Result<ClassMember, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    ClassMember* ret = new(_rp) ClassMember(declaration, new(_rp) Position(start), new(_rp) Position(end));
    declaration->parent = ret;
    return _Result<ClassMember, ParserError>(ret);
}

_Result<PrefixExpression, ParserError> Parser::parsePrefixExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    string* prefixOperator = lexer->parsePrefixOperator(_rp);
    if (prefixOperator != nullptr)
        lexer->advance();
    auto _expression_result = parsePostfixExpression(_rp, _ep);
    PostfixExpression* expression = nullptr;
    if (_expression_result.succeeded()) {
        expression = _expression_result.getResult();
    }
    else {
        auto error = _expression_result.getError();
        return _Result<PrefixExpression, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    PrefixExpression* ret = new(_rp) PrefixExpression(prefixOperator, expression, new(_rp) Position(start), new(_rp) Position(end));
    expression->parent = ret;
    return _Result<PrefixExpression, ParserError>(ret);
}

_Result<PostfixExpression, ParserError> Parser::parsePostfixExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _primaryExpression_result = parsePrimaryExpression(_rp, _ep);
    PrimaryExpression* primaryExpression = nullptr;
    if (_primaryExpression_result.succeeded()) {
        primaryExpression = _primaryExpression_result.getResult();
    }
    else {
        auto error = _primaryExpression_result.getError();
        return _Result<PostfixExpression, ParserError>(error);
    }
    auto _postfixes_result = parsePostfixList(_rp, _ep);
    _Array<Postfix>* postfixes = nullptr;
    if (_postfixes_result.succeeded()) {
        postfixes = _postfixes_result.getResult();
    }
    else {
        postfixes = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    PostfixExpression* ret = new(_rp) PostfixExpression(primaryExpression, postfixes, new(_rp) Position(start), new(_rp) Position(end));
    primaryExpression->parent = ret;
    if (postfixes != nullptr) {
        Postfix* item = nullptr;
        size_t _postfixes_length = postfixes->length();
        for (size_t _i = 0; _i < _postfixes_length; _i++) {
            item = *(*postfixes)[_i];
            item->parent = ret;
        }
    }
    return _Result<PostfixExpression, ParserError>(ret);
}

_Result<_Array<BinaryOp>, ParserError> Parser::parseBinaryOpList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<BinaryOp>* ret = nullptr;
    while (true) {
        auto _node_result = parseBinaryOp(_rp, _ep);
        BinaryOp* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<BinaryOp>();
        ret->push(node);
    }
    return _Result<_Array<BinaryOp>, ParserError>(ret ? new(_rp) _Array<BinaryOp>(ret) : nullptr);
}

_Result<BinaryOp, ParserError> Parser::parseBinaryOp(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ParserError>* errors = new(_p) _Array<ParserError>();
    Position* start = lexer->getPreviousPosition(_p);
    {
        auto _node_result = parseBinaryOperation(_rp, _ep);
        BinaryOperation* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<BinaryOp, ParserError>(node);
    }
    {
        auto _node_result = parseAssignment(_rp, _ep);
        Assignment* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<BinaryOp, ParserError>(node);
    }
    {
        auto _node_result = parseTypeQuery(_rp, _ep);
        TypeQuery* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<BinaryOp, ParserError>(node);
    }
    {
        auto _node_result = parseTypeCast(_rp, _ep);
        TypeCast* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<BinaryOp, ParserError>(node);
    }
    return _Result<BinaryOp, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_unableToParse(new(_ep) Position(start), new(_ep) _Array<ParserError>(errors))));
}

_Result<BinaryOperation, ParserError> Parser::parseBinaryOperation(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startBinaryOperator = lexer->getPreviousPosition(_p);
    string* binaryOperator = lexer->parseBinaryOperator(_rp);
    if (binaryOperator != nullptr)
        lexer->advance();
    else
        return _Result<BinaryOperation, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_operatorExpected(new(_ep) Position(startBinaryOperator))));
    auto _expression_result = parsePrefixExpression(_rp, _ep);
    PrefixExpression* expression = nullptr;
    if (_expression_result.succeeded()) {
        expression = _expression_result.getResult();
    }
    else {
        auto error = _expression_result.getError();
        return _Result<BinaryOperation, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    BinaryOperation* ret = new(_rp) BinaryOperation(binaryOperator, expression, new(_rp) Position(start), new(_rp) Position(end));
    expression->parent = ret;
    return _Result<BinaryOperation, ParserError>(ret);
}

_Result<Assignment, ParserError> Parser::parseAssignment(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startEqual1 = lexer->getPreviousPosition(_p);
    bool successEqual1 = lexer->parsePunctuation(equal);
    if (successEqual1)
        lexer->advance();
    else
        return _Result<Assignment, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startEqual1), new(_ep) string(equal))));
    auto _expression_result = parseExpression(_rp, _ep);
    Expression* expression = nullptr;
    if (_expression_result.succeeded()) {
        expression = _expression_result.getResult();
    }
    else {
        auto error = _expression_result.getError();
        return _Result<Assignment, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    Assignment* ret = new(_rp) Assignment(expression, new(_rp) Position(start), new(_rp) Position(end));
    expression->parent = ret;
    return _Result<Assignment, ParserError>(ret);
}

_Result<TypeQuery, ParserError> Parser::parseTypeQuery(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startIs1 = lexer->getPreviousPosition(_p);
    bool successIs1 = lexer->parseKeyword(isKeyword);
    if (successIs1)
        lexer->advance();
    else
        return _Result<TypeQuery, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startIs1), new(_ep) string(isKeyword))));
    auto _objectType_result = parseType(_rp, _ep);
    Type* objectType = nullptr;
    if (_objectType_result.succeeded()) {
        objectType = _objectType_result.getResult();
    }
    else {
        auto error = _objectType_result.getError();
        return _Result<TypeQuery, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    TypeQuery* ret = new(_rp) TypeQuery(objectType, new(_rp) Position(start), new(_rp) Position(end));
    objectType->parent = ret;
    return _Result<TypeQuery, ParserError>(ret);
}

_Result<TypeCast, ParserError> Parser::parseTypeCast(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startAs1 = lexer->getPreviousPosition(_p);
    bool successAs1 = lexer->parseKeyword(asKeyword);
    if (successAs1)
        lexer->advance();
    else
        return _Result<TypeCast, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startAs1), new(_ep) string(asKeyword))));
    auto _objectType_result = parseType(_rp, _ep);
    Type* objectType = nullptr;
    if (_objectType_result.succeeded()) {
        objectType = _objectType_result.getResult();
    }
    else {
        auto error = _objectType_result.getError();
        return _Result<TypeCast, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    TypeCast* ret = new(_rp) TypeCast(objectType, new(_rp) Position(start), new(_rp) Position(end));
    objectType->parent = ret;
    return _Result<TypeCast, ParserError>(ret);
}

_Result<_Array<CatchClause>, ParserError> Parser::parseCatchClauseList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<CatchClause>* ret = nullptr;
    while (true) {
        auto _node_result = parseCatchClause(_rp, _ep);
        CatchClause* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<CatchClause>();
        ret->push(node);
    }
    return _Result<_Array<CatchClause>, ParserError>(ret ? new(_rp) _Array<CatchClause>(ret) : nullptr);
}

_Result<CatchClause, ParserError> Parser::parseCatchClause(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startCatch1 = lexer->getPreviousPosition(_p);
    bool successCatch1 = lexer->parseKeyword(catchKeyword);
    if (successCatch1)
        lexer->advance();
    else
        return _Result<CatchClause, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startCatch1), new(_ep) string(catchKeyword))));
    auto _catchPattern_result = parseCatchPattern(_rp, _ep);
    CatchPattern* catchPattern = nullptr;
    if (_catchPattern_result.succeeded()) {
        catchPattern = _catchPattern_result.getResult();
    }
    else {
        auto error = _catchPattern_result.getError();
        return _Result<CatchClause, ParserError>(error);
    }
    auto _bindingPattern_result = parseTuplePattern(_rp, _ep);
    TuplePattern* bindingPattern = nullptr;
    if (_bindingPattern_result.succeeded()) {
        bindingPattern = _bindingPattern_result.getResult();
    }
    else {
        bindingPattern = nullptr;
    }
    auto _expression_result = parseExpression(_rp, _ep);
    Expression* expression = nullptr;
    if (_expression_result.succeeded()) {
        expression = _expression_result.getResult();
    }
    else {
        auto error = _expression_result.getError();
        return _Result<CatchClause, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    CatchClause* ret = new(_rp) CatchClause(catchPattern, bindingPattern, expression, new(_rp) Position(start), new(_rp) Position(end));
    catchPattern->parent = ret;
    if (bindingPattern != nullptr)
        bindingPattern->parent = ret;
    expression->parent = ret;
    return _Result<CatchClause, ParserError>(ret);
}

_Result<CatchPattern, ParserError> Parser::parseCatchPattern(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ParserError>* errors = new(_p) _Array<ParserError>();
    Position* start = lexer->getPreviousPosition(_p);
    {
        auto _node_result = parseWildCardCatchPattern(_rp, _ep);
        WildCardCatchPattern* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<CatchPattern, ParserError>(node);
    }
    {
        auto _node_result = parseIdentifierCatchPattern(_rp, _ep);
        IdentifierCatchPattern* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<CatchPattern, ParserError>(node);
    }
    return _Result<CatchPattern, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_unableToParse(new(_ep) Position(start), new(_ep) _Array<ParserError>(errors))));
}

_Result<WildCardCatchPattern, ParserError> Parser::parseWildCardCatchPattern(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _pattern_result = parseWildcardPattern(_rp, _ep);
    WildcardPattern* pattern = nullptr;
    if (_pattern_result.succeeded()) {
        pattern = _pattern_result.getResult();
    }
    else {
        auto error = _pattern_result.getError();
        return _Result<WildCardCatchPattern, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    WildCardCatchPattern* ret = new(_rp) WildCardCatchPattern(pattern, new(_rp) Position(start), new(_rp) Position(end));
    pattern->parent = ret;
    return _Result<WildCardCatchPattern, ParserError>(ret);
}

_Result<IdentifierCatchPattern, ParserError> Parser::parseIdentifierCatchPattern(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startName = lexer->getPreviousPosition(_p);
    string* name = lexer->parseIdentifier(_rp);
    if ((name != nullptr) && isIdentifier(name))
        lexer->advance();
    else
        return _Result<IdentifierCatchPattern, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_identifierExpected(new(_ep) Position(startName))));
    auto _member_result = parseMemberExpression(_rp, _ep);
    MemberExpression* member = nullptr;
    if (_member_result.succeeded()) {
        member = _member_result.getResult();
    }
    else {
        member = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    IdentifierCatchPattern* ret = new(_rp) IdentifierCatchPattern(name, member, new(_rp) Position(start), new(_rp) Position(end));
    if (member != nullptr)
        member->parent = ret;
    return _Result<IdentifierCatchPattern, ParserError>(ret);
}

_Result<_Array<Postfix>, ParserError> Parser::parsePostfixList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<Postfix>* ret = nullptr;
    while (true) {
        auto _node_result = parsePostfix(_rp, _ep);
        Postfix* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<Postfix>();
        ret->push(node);
    }
    return _Result<_Array<Postfix>, ParserError>(ret ? new(_rp) _Array<Postfix>(ret) : nullptr);
}

_Result<Postfix, ParserError> Parser::parsePostfix(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ParserError>* errors = new(_p) _Array<ParserError>();
    Position* start = lexer->getPreviousPosition(_p);
    {
        auto _node_result = parseOperatorPostfix(_rp, _ep);
        OperatorPostfix* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Postfix, ParserError>(node);
    }
    {
        auto _node_result = parseFunctionCall(_rp, _ep);
        FunctionCall* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Postfix, ParserError>(node);
    }
    {
        auto _node_result = parseMemberExpression(_rp, _ep);
        MemberExpression* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Postfix, ParserError>(node);
    }
    {
        auto _node_result = parseSubscript(_rp, _ep);
        Subscript* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Postfix, ParserError>(node);
    }
    return _Result<Postfix, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_unableToParse(new(_ep) Position(start), new(_ep) _Array<ParserError>(errors))));
}

_Result<OperatorPostfix, ParserError> Parser::parseOperatorPostfix(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startPostfixOperator = lexer->getPreviousPosition(_p);
    string* postfixOperator = lexer->parsePostfixOperator(_rp);
    if (postfixOperator != nullptr)
        lexer->advance();
    else
        return _Result<OperatorPostfix, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_operatorExpected(new(_ep) Position(startPostfixOperator))));
    Position* end = lexer->getPosition(_p);
    OperatorPostfix* ret = new(_rp) OperatorPostfix(postfixOperator, new(_rp) Position(start), new(_rp) Position(end));
    return _Result<OperatorPostfix, ParserError>(ret);
}

_Result<FunctionCall, ParserError> Parser::parseFunctionCall(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _arguments_result = parseParenthesizedExpression(_rp, _ep);
    ParenthesizedExpression* arguments = nullptr;
    if (_arguments_result.succeeded()) {
        arguments = _arguments_result.getResult();
    }
    else {
        auto error = _arguments_result.getError();
        return _Result<FunctionCall, ParserError>(error);
    }
    auto _catchClauses_result = parseCatchClauseList(_rp, _ep);
    _Array<CatchClause>* catchClauses = nullptr;
    if (_catchClauses_result.succeeded()) {
        catchClauses = _catchClauses_result.getResult();
    }
    else {
        catchClauses = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    FunctionCall* ret = new(_rp) FunctionCall(arguments, catchClauses, new(_rp) Position(start), new(_rp) Position(end));
    arguments->parent = ret;
    if (catchClauses != nullptr) {
        CatchClause* item = nullptr;
        size_t _catchClauses_length = catchClauses->length();
        for (size_t _i = 0; _i < _catchClauses_length; _i++) {
            item = *(*catchClauses)[_i];
            item->parent = ret;
        }
    }
    return _Result<FunctionCall, ParserError>(ret);
}

_Result<MemberExpression, ParserError> Parser::parseMemberExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startDot1 = lexer->getPreviousPosition(_p);
    bool successDot1 = lexer->parsePunctuation(dot);
    if (successDot1)
        lexer->advance();
    else
        return _Result<MemberExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startDot1), new(_ep) string(dot))));
    Position* startMember = lexer->getPreviousPosition(_p);
    string* member = lexer->parseIdentifier(_rp);
    if ((member != nullptr) && isIdentifier(member))
        lexer->advance();
    else
        return _Result<MemberExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_identifierExpected(new(_ep) Position(startMember))));
    Position* end = lexer->getPosition(_p);
    MemberExpression* ret = new(_rp) MemberExpression(member, new(_rp) Position(start), new(_rp) Position(end));
    return _Result<MemberExpression, ParserError>(ret);
}

_Result<Subscript, ParserError> Parser::parseSubscript(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startLeftBracket1 = lexer->getPreviousPosition(_p);
    bool successLeftBracket1 = lexer->parsePunctuation(leftBracket);
    if (successLeftBracket1)
        lexer->advance();
    else
        return _Result<Subscript, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startLeftBracket1), new(_ep) string(leftBracket))));
    auto _expressions_result = parseExpressionElementList(_rp, _ep);
    _Array<ExpressionElement>* expressions = nullptr;
    if (_expressions_result.succeeded()) {
        expressions = _expressions_result.getResult();
    }
    else {
        auto error = _expressions_result.getError();
        return _Result<Subscript, ParserError>(error);
    }
    Position* startRightBracket3 = lexer->getPreviousPosition(_p);
    bool successRightBracket3 = lexer->parsePunctuation(rightBracket);
    if (successRightBracket3)
        lexer->advance();
    else
        return _Result<Subscript, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startRightBracket3), new(_ep) string(rightBracket))));
    Position* end = lexer->getPosition(_p);
    Subscript* ret = new(_rp) Subscript(expressions, new(_rp) Position(start), new(_rp) Position(end));
    if (expressions != nullptr) {
        ExpressionElement* item = nullptr;
        size_t _expressions_length = expressions->length();
        for (size_t _i = 0; _i < _expressions_length; _i++) {
            item = *(*expressions)[_i];
            item->parent = ret;
        }
    }
    return _Result<Subscript, ParserError>(ret);
}

_Result<_Array<ExpressionElement>, ParserError> Parser::parseExpressionElementList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ExpressionElement>* ret = nullptr;
    while (true) {
        auto _node_result = parseExpressionElement(_rp, _ep);
        ExpressionElement* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<ExpressionElement>();
        ret->push(node);
    }
    return _Result<_Array<ExpressionElement>, ParserError>(ret ? new(_rp) _Array<ExpressionElement>(ret) : nullptr);
}

_Result<ExpressionElement, ParserError> Parser::parseExpressionElement(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _expression_result = parseExpression(_rp, _ep);
    Expression* expression = nullptr;
    if (_expression_result.succeeded()) {
        expression = _expression_result.getResult();
    }
    else {
        auto error = _expression_result.getError();
        return _Result<ExpressionElement, ParserError>(error);
    }
    bool successComma2 = lexer->parsePunctuation(comma);
    if (successComma2)
        lexer->advance();
    Position* end = lexer->getPosition(_p);
    ExpressionElement* ret = new(_rp) ExpressionElement(expression, new(_rp) Position(start), new(_rp) Position(end));
    expression->parent = ret;
    return _Result<ExpressionElement, ParserError>(ret);
}

_Result<PrimaryExpression, ParserError> Parser::parsePrimaryExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ParserError>* errors = new(_p) _Array<ParserError>();
    Position* start = lexer->getPreviousPosition(_p);
    {
        auto _node_result = parseIdentifierExpression(_rp, _ep);
        IdentifierExpression* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<PrimaryExpression, ParserError>(node);
    }
    {
        auto _node_result = parseLiteralExpression(_rp, _ep);
        LiteralExpression* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<PrimaryExpression, ParserError>(node);
    }
    {
        auto _node_result = parseIfExpression(_rp, _ep);
        IfExpression* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<PrimaryExpression, ParserError>(node);
    }
    {
        auto _node_result = parseSwitchExpression(_rp, _ep);
        SwitchExpression* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<PrimaryExpression, ParserError>(node);
    }
    {
        auto _node_result = parseForExpression(_rp, _ep);
        ForExpression* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<PrimaryExpression, ParserError>(node);
    }
    {
        auto _node_result = parseWhileExpression(_rp, _ep);
        WhileExpression* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<PrimaryExpression, ParserError>(node);
    }
    {
        auto _node_result = parseDoExpression(_rp, _ep);
        DoExpression* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<PrimaryExpression, ParserError>(node);
    }
    {
        auto _node_result = parseParenthesizedExpression(_rp, _ep);
        ParenthesizedExpression* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<PrimaryExpression, ParserError>(node);
    }
    {
        auto _node_result = parseReturnExpression(_rp, _ep);
        ReturnExpression* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<PrimaryExpression, ParserError>(node);
    }
    {
        auto _node_result = parseThrowExpression(_rp, _ep);
        ThrowExpression* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<PrimaryExpression, ParserError>(node);
    }
    {
        auto _node_result = parseBreakExpression(_rp, _ep);
        BreakExpression* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<PrimaryExpression, ParserError>(node);
    }
    {
        auto _node_result = parseConstructorCall(_rp, _ep);
        ConstructorCall* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<PrimaryExpression, ParserError>(node);
    }
    {
        auto _node_result = parseThisExpression(_rp, _ep);
        ThisExpression* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<PrimaryExpression, ParserError>(node);
    }
    {
        auto _node_result = parseNullExpression(_rp, _ep);
        NullExpression* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<PrimaryExpression, ParserError>(node);
    }
    return _Result<PrimaryExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_unableToParse(new(_ep) Position(start), new(_ep) _Array<ParserError>(errors))));
}

_Result<IdentifierExpression, ParserError> Parser::parseIdentifierExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startName = lexer->getPreviousPosition(_p);
    string* name = lexer->parseIdentifier(_rp);
    if ((name != nullptr) && isIdentifier(name))
        lexer->advance();
    else
        return _Result<IdentifierExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_identifierExpected(new(_ep) Position(startName))));
    Position* end = lexer->getPosition(_p);
    IdentifierExpression* ret = new(_rp) IdentifierExpression(name, new(_rp) Position(start), new(_rp) Position(end));
    return _Result<IdentifierExpression, ParserError>(ret);
}

_Result<LiteralExpression, ParserError> Parser::parseLiteralExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startLiteral = lexer->getPreviousPosition(_p);
    Literal* literal = lexer->parseLiteral(_rp);
    if (literal != nullptr)
        lexer->advance();
    else
        return _Result<LiteralExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_literalExpected(new(_ep) Position(startLiteral))));
    Position* end = lexer->getPosition(_p);
    LiteralExpression* ret = new(_rp) LiteralExpression(literal, new(_rp) Position(start), new(_rp) Position(end));
    return _Result<LiteralExpression, ParserError>(ret);
}

_Result<IfExpression, ParserError> Parser::parseIfExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startIf1 = lexer->getPreviousPosition(_p);
    bool successIf1 = lexer->parseKeyword(ifKeyword);
    if (successIf1)
        lexer->advance();
    else
        return _Result<IfExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startIf1), new(_ep) string(ifKeyword))));
    auto _condition_result = parseExpression(_rp, _ep);
    Expression* condition = nullptr;
    if (_condition_result.succeeded()) {
        condition = _condition_result.getResult();
    }
    else {
        auto error = _condition_result.getError();
        return _Result<IfExpression, ParserError>(error);
    }
    auto _consequent_result = parseExpression(_rp, _ep);
    Expression* consequent = nullptr;
    if (_consequent_result.succeeded()) {
        consequent = _consequent_result.getResult();
    }
    else {
        auto error = _consequent_result.getError();
        return _Result<IfExpression, ParserError>(error);
    }
    auto _elseClause_result = parseElseClause(_rp, _ep);
    ElseClause* elseClause = nullptr;
    if (_elseClause_result.succeeded()) {
        elseClause = _elseClause_result.getResult();
    }
    else {
        elseClause = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    IfExpression* ret = new(_rp) IfExpression(condition, consequent, elseClause, new(_rp) Position(start), new(_rp) Position(end));
    condition->parent = ret;
    consequent->parent = ret;
    if (elseClause != nullptr)
        elseClause->parent = ret;
    return _Result<IfExpression, ParserError>(ret);
}

_Result<SwitchExpression, ParserError> Parser::parseSwitchExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startSwitch1 = lexer->getPreviousPosition(_p);
    bool successSwitch1 = lexer->parseKeyword(switchKeyword);
    if (successSwitch1)
        lexer->advance();
    else
        return _Result<SwitchExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startSwitch1), new(_ep) string(switchKeyword))));
    auto _expression_result = parseExpression(_rp, _ep);
    Expression* expression = nullptr;
    if (_expression_result.succeeded()) {
        expression = _expression_result.getResult();
    }
    else {
        auto error = _expression_result.getError();
        return _Result<SwitchExpression, ParserError>(error);
    }
    auto _body_result = parseSwitchBody(_rp, _ep);
    SwitchBody* body = nullptr;
    if (_body_result.succeeded()) {
        body = _body_result.getResult();
    }
    else {
        auto error = _body_result.getError();
        return _Result<SwitchExpression, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    SwitchExpression* ret = new(_rp) SwitchExpression(expression, body, new(_rp) Position(start), new(_rp) Position(end));
    expression->parent = ret;
    body->parent = ret;
    return _Result<SwitchExpression, ParserError>(ret);
}

_Result<ForExpression, ParserError> Parser::parseForExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startFor1 = lexer->getPreviousPosition(_p);
    bool successFor1 = lexer->parseKeyword(forKeyword);
    if (successFor1)
        lexer->advance();
    else
        return _Result<ForExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startFor1), new(_ep) string(forKeyword))));
    auto _pattern_result = parsePattern(_rp, _ep);
    Pattern* pattern = nullptr;
    if (_pattern_result.succeeded()) {
        pattern = _pattern_result.getResult();
    }
    else {
        auto error = _pattern_result.getError();
        return _Result<ForExpression, ParserError>(error);
    }
    Position* startIn3 = lexer->getPreviousPosition(_p);
    bool successIn3 = lexer->parseKeyword(inKeyword);
    if (successIn3)
        lexer->advance();
    else
        return _Result<ForExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startIn3), new(_ep) string(inKeyword))));
    auto _expression_result = parseExpression(_rp, _ep);
    Expression* expression = nullptr;
    if (_expression_result.succeeded()) {
        expression = _expression_result.getResult();
    }
    else {
        auto error = _expression_result.getError();
        return _Result<ForExpression, ParserError>(error);
    }
    auto _code_result = parseExpression(_rp, _ep);
    Expression* code = nullptr;
    if (_code_result.succeeded()) {
        code = _code_result.getResult();
    }
    else {
        auto error = _code_result.getError();
        return _Result<ForExpression, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    ForExpression* ret = new(_rp) ForExpression(pattern, expression, code, new(_rp) Position(start), new(_rp) Position(end));
    pattern->parent = ret;
    expression->parent = ret;
    code->parent = ret;
    return _Result<ForExpression, ParserError>(ret);
}

_Result<WhileExpression, ParserError> Parser::parseWhileExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startWhile1 = lexer->getPreviousPosition(_p);
    bool successWhile1 = lexer->parseKeyword(whileKeyword);
    if (successWhile1)
        lexer->advance();
    else
        return _Result<WhileExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startWhile1), new(_ep) string(whileKeyword))));
    auto _condition_result = parseExpression(_rp, _ep);
    Expression* condition = nullptr;
    if (_condition_result.succeeded()) {
        condition = _condition_result.getResult();
    }
    else {
        auto error = _condition_result.getError();
        return _Result<WhileExpression, ParserError>(error);
    }
    auto _code_result = parseExpression(_rp, _ep);
    Expression* code = nullptr;
    if (_code_result.succeeded()) {
        code = _code_result.getResult();
    }
    else {
        auto error = _code_result.getError();
        return _Result<WhileExpression, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    WhileExpression* ret = new(_rp) WhileExpression(condition, code, new(_rp) Position(start), new(_rp) Position(end));
    condition->parent = ret;
    code->parent = ret;
    return _Result<WhileExpression, ParserError>(ret);
}

_Result<DoExpression, ParserError> Parser::parseDoExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startDo1 = lexer->getPreviousPosition(_p);
    bool successDo1 = lexer->parseKeyword(doKeyword);
    if (successDo1)
        lexer->advance();
    else
        return _Result<DoExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startDo1), new(_ep) string(doKeyword))));
    auto _code_result = parseExpression(_rp, _ep);
    Expression* code = nullptr;
    if (_code_result.succeeded()) {
        code = _code_result.getResult();
    }
    else {
        auto error = _code_result.getError();
        return _Result<DoExpression, ParserError>(error);
    }
    Position* startWhile3 = lexer->getPreviousPosition(_p);
    bool successWhile3 = lexer->parseKeyword(whileKeyword);
    if (successWhile3)
        lexer->advance();
    else
        return _Result<DoExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startWhile3), new(_ep) string(whileKeyword))));
    auto _condition_result = parseExpression(_rp, _ep);
    Expression* condition = nullptr;
    if (_condition_result.succeeded()) {
        condition = _condition_result.getResult();
    }
    else {
        auto error = _condition_result.getError();
        return _Result<DoExpression, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    DoExpression* ret = new(_rp) DoExpression(code, condition, new(_rp) Position(start), new(_rp) Position(end));
    code->parent = ret;
    condition->parent = ret;
    return _Result<DoExpression, ParserError>(ret);
}

_Result<ParenthesizedExpression, ParserError> Parser::parseParenthesizedExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startLeftParen1 = lexer->getPreviousPosition(_p);
    bool successLeftParen1 = lexer->parsePunctuation(leftParen);
    if (successLeftParen1)
        lexer->advance();
    else
        return _Result<ParenthesizedExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startLeftParen1), new(_ep) string(leftParen))));
    auto _expressionElements_result = parseExpressionElementList(_rp, _ep);
    _Array<ExpressionElement>* expressionElements = nullptr;
    if (_expressionElements_result.succeeded()) {
        expressionElements = _expressionElements_result.getResult();
    }
    else {
        expressionElements = nullptr;
    }
    Position* startRightParen3 = lexer->getPreviousPosition(_p);
    bool successRightParen3 = lexer->parsePunctuation(rightParen);
    if (successRightParen3)
        lexer->advance();
    else
        return _Result<ParenthesizedExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startRightParen3), new(_ep) string(rightParen))));
    Position* end = lexer->getPosition(_p);
    ParenthesizedExpression* ret = new(_rp) ParenthesizedExpression(expressionElements, new(_rp) Position(start), new(_rp) Position(end));
    if (expressionElements != nullptr) {
        ExpressionElement* item = nullptr;
        size_t _expressionElements_length = expressionElements->length();
        for (size_t _i = 0; _i < _expressionElements_length; _i++) {
            item = *(*expressionElements)[_i];
            item->parent = ret;
        }
    }
    return _Result<ParenthesizedExpression, ParserError>(ret);
}

_Result<ReturnExpression, ParserError> Parser::parseReturnExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startReturn1 = lexer->getPreviousPosition(_p);
    bool successReturn1 = lexer->parseKeyword(returnKeyword);
    if (successReturn1)
        lexer->advance();
    else
        return _Result<ReturnExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startReturn1), new(_ep) string(returnKeyword))));
    auto _expression_result = parseParenthesizedExpression(_rp, _ep);
    ParenthesizedExpression* expression = nullptr;
    if (_expression_result.succeeded()) {
        expression = _expression_result.getResult();
    }
    else {
        expression = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    ReturnExpression* ret = new(_rp) ReturnExpression(expression, new(_rp) Position(start), new(_rp) Position(end));
    if (expression != nullptr)
        expression->parent = ret;
    return _Result<ReturnExpression, ParserError>(ret);
}

_Result<ThrowExpression, ParserError> Parser::parseThrowExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startThrow1 = lexer->getPreviousPosition(_p);
    bool successThrow1 = lexer->parseKeyword(throwKeyword);
    if (successThrow1)
        lexer->advance();
    else
        return _Result<ThrowExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startThrow1), new(_ep) string(throwKeyword))));
    auto _error_result = parseIdentifierExpression(_rp, _ep);
    IdentifierExpression* error = nullptr;
    if (_error_result.succeeded()) {
        error = _error_result.getResult();
    }
    else {
        auto error = _error_result.getError();
        return _Result<ThrowExpression, ParserError>(error);
    }
    auto _arguments_result = parseParenthesizedExpression(_rp, _ep);
    ParenthesizedExpression* arguments = nullptr;
    if (_arguments_result.succeeded()) {
        arguments = _arguments_result.getResult();
    }
    else {
        arguments = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    ThrowExpression* ret = new(_rp) ThrowExpression(error, arguments, new(_rp) Position(start), new(_rp) Position(end));
    error->parent = ret;
    if (arguments != nullptr)
        arguments->parent = ret;
    return _Result<ThrowExpression, ParserError>(ret);
}

_Result<BreakExpression, ParserError> Parser::parseBreakExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startBreak1 = lexer->getPreviousPosition(_p);
    bool successBreak1 = lexer->parseKeyword(breakKeyword);
    if (successBreak1)
        lexer->advance();
    else
        return _Result<BreakExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startBreak1), new(_ep) string(breakKeyword))));
    auto _expression_result = parseParenthesizedExpression(_rp, _ep);
    ParenthesizedExpression* expression = nullptr;
    if (_expression_result.succeeded()) {
        expression = _expression_result.getResult();
    }
    else {
        expression = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    BreakExpression* ret = new(_rp) BreakExpression(expression, new(_rp) Position(start), new(_rp) Position(end));
    if (expression != nullptr)
        expression->parent = ret;
    return _Result<BreakExpression, ParserError>(ret);
}

_Result<ConstructorCall, ParserError> Parser::parseConstructorCall(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startNew1 = lexer->getPreviousPosition(_p);
    bool successNew1 = lexer->parseKeyword(newKeyword);
    if (successNew1)
        lexer->advance();
    else
        return _Result<ConstructorCall, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startNew1), new(_ep) string(newKeyword))));
    auto _typeToConstruct_result = parseType(_rp, _ep);
    Type* typeToConstruct = nullptr;
    if (_typeToConstruct_result.succeeded()) {
        typeToConstruct = _typeToConstruct_result.getResult();
    }
    else {
        auto error = _typeToConstruct_result.getError();
        return _Result<ConstructorCall, ParserError>(error);
    }
    auto _arguments_result = parseParenthesizedExpression(_rp, _ep);
    ParenthesizedExpression* arguments = nullptr;
    if (_arguments_result.succeeded()) {
        arguments = _arguments_result.getResult();
    }
    else {
        auto error = _arguments_result.getError();
        return _Result<ConstructorCall, ParserError>(error);
    }
    auto _catchClauses_result = parseCatchClauseList(_rp, _ep);
    _Array<CatchClause>* catchClauses = nullptr;
    if (_catchClauses_result.succeeded()) {
        catchClauses = _catchClauses_result.getResult();
    }
    else {
        catchClauses = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    ConstructorCall* ret = new(_rp) ConstructorCall(typeToConstruct, arguments, catchClauses, new(_rp) Position(start), new(_rp) Position(end));
    typeToConstruct->parent = ret;
    arguments->parent = ret;
    if (catchClauses != nullptr) {
        CatchClause* item = nullptr;
        size_t _catchClauses_length = catchClauses->length();
        for (size_t _i = 0; _i < _catchClauses_length; _i++) {
            item = *(*catchClauses)[_i];
            item->parent = ret;
        }
    }
    return _Result<ConstructorCall, ParserError>(ret);
}

_Result<ThisExpression, ParserError> Parser::parseThisExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startThis1 = lexer->getPreviousPosition(_p);
    bool successThis1 = lexer->parseKeyword(thisKeyword);
    if (successThis1)
        lexer->advance();
    else
        return _Result<ThisExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startThis1), new(_ep) string(thisKeyword))));
    Position* end = lexer->getPosition(_p);
    ThisExpression* ret = new(_rp) ThisExpression(new(_rp) Position(start), new(_rp) Position(end));
    return _Result<ThisExpression, ParserError>(ret);
}

_Result<NullExpression, ParserError> Parser::parseNullExpression(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startNull1 = lexer->getPreviousPosition(_p);
    bool successNull1 = lexer->parseKeyword(nullKeyword);
    if (successNull1)
        lexer->advance();
    else
        return _Result<NullExpression, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startNull1), new(_ep) string(nullKeyword))));
    Position* end = lexer->getPosition(_p);
    NullExpression* ret = new(_rp) NullExpression(new(_rp) Position(start), new(_rp) Position(end));
    return _Result<NullExpression, ParserError>(ret);
}

_Result<ElseClause, ParserError> Parser::parseElseClause(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startElse1 = lexer->getPreviousPosition(_p);
    bool successElse1 = lexer->parseKeyword(elseKeyword);
    if (successElse1)
        lexer->advance();
    else
        return _Result<ElseClause, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startElse1), new(_ep) string(elseKeyword))));
    auto _alternative_result = parseExpression(_rp, _ep);
    Expression* alternative = nullptr;
    if (_alternative_result.succeeded()) {
        alternative = _alternative_result.getResult();
    }
    else {
        auto error = _alternative_result.getError();
        return _Result<ElseClause, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    ElseClause* ret = new(_rp) ElseClause(alternative, new(_rp) Position(start), new(_rp) Position(end));
    alternative->parent = ret;
    return _Result<ElseClause, ParserError>(ret);
}

_Result<SwitchBody, ParserError> Parser::parseSwitchBody(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ParserError>* errors = new(_p) _Array<ParserError>();
    Position* start = lexer->getPreviousPosition(_p);
    {
        auto _node_result = parseCurliedSwitchBody(_rp, _ep);
        CurliedSwitchBody* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<SwitchBody, ParserError>(node);
    }
    {
        auto _node_result = parseNakedSwitchBody(_rp, _ep);
        NakedSwitchBody* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<SwitchBody, ParserError>(node);
    }
    return _Result<SwitchBody, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_unableToParse(new(_ep) Position(start), new(_ep) _Array<ParserError>(errors))));
}

_Result<CurliedSwitchBody, ParserError> Parser::parseCurliedSwitchBody(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startLeftCurly1 = lexer->getPreviousPosition(_p);
    bool successLeftCurly1 = lexer->parsePunctuation(leftCurly);
    if (successLeftCurly1)
        lexer->advance();
    else
        return _Result<CurliedSwitchBody, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startLeftCurly1), new(_ep) string(leftCurly))));
    auto _cases_result = parseSwitchCaseList(_rp, _ep);
    _Array<SwitchCase>* cases = nullptr;
    if (_cases_result.succeeded()) {
        cases = _cases_result.getResult();
    }
    else {
        auto error = _cases_result.getError();
        return _Result<CurliedSwitchBody, ParserError>(error);
    }
    Position* startRightCurly3 = lexer->getPreviousPosition(_p);
    bool successRightCurly3 = lexer->parsePunctuation(rightCurly);
    if (successRightCurly3)
        lexer->advance();
    else
        return _Result<CurliedSwitchBody, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startRightCurly3), new(_ep) string(rightCurly))));
    Position* end = lexer->getPosition(_p);
    CurliedSwitchBody* ret = new(_rp) CurliedSwitchBody(cases, new(_rp) Position(start), new(_rp) Position(end));
    if (cases != nullptr) {
        SwitchCase* item = nullptr;
        size_t _cases_length = cases->length();
        for (size_t _i = 0; _i < _cases_length; _i++) {
            item = *(*cases)[_i];
            item->parent = ret;
        }
    }
    return _Result<CurliedSwitchBody, ParserError>(ret);
}

_Result<NakedSwitchBody, ParserError> Parser::parseNakedSwitchBody(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _cases_result = parseSwitchCaseList(_rp, _ep);
    _Array<SwitchCase>* cases = nullptr;
    if (_cases_result.succeeded()) {
        cases = _cases_result.getResult();
    }
    else {
        auto error = _cases_result.getError();
        return _Result<NakedSwitchBody, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    NakedSwitchBody* ret = new(_rp) NakedSwitchBody(cases, new(_rp) Position(start), new(_rp) Position(end));
    if (cases != nullptr) {
        SwitchCase* item = nullptr;
        size_t _cases_length = cases->length();
        for (size_t _i = 0; _i < _cases_length; _i++) {
            item = *(*cases)[_i];
            item->parent = ret;
        }
    }
    return _Result<NakedSwitchBody, ParserError>(ret);
}

_Result<_Array<SwitchCase>, ParserError> Parser::parseSwitchCaseList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<SwitchCase>* ret = nullptr;
    while (true) {
        auto _node_result = parseSwitchCase(_rp, _ep);
        SwitchCase* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<SwitchCase>();
        ret->push(node);
    }
    return _Result<_Array<SwitchCase>, ParserError>(ret ? new(_rp) _Array<SwitchCase>(ret) : nullptr);
}

_Result<SwitchCase, ParserError> Parser::parseSwitchCase(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _label_result = parseCaseLabel(_rp, _ep);
    CaseLabel* label = nullptr;
    if (_label_result.succeeded()) {
        label = _label_result.getResult();
    }
    else {
        auto error = _label_result.getError();
        return _Result<SwitchCase, ParserError>(error);
    }
    auto _content_result = parseCaseContent(_rp, _ep);
    CaseContent* content = nullptr;
    if (_content_result.succeeded()) {
        content = _content_result.getResult();
    }
    else {
        auto error = _content_result.getError();
        return _Result<SwitchCase, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    SwitchCase* ret = new(_rp) SwitchCase(label, content, new(_rp) Position(start), new(_rp) Position(end));
    label->parent = ret;
    content->parent = ret;
    return _Result<SwitchCase, ParserError>(ret);
}

_Result<CaseLabel, ParserError> Parser::parseCaseLabel(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ParserError>* errors = new(_p) _Array<ParserError>();
    Position* start = lexer->getPreviousPosition(_p);
    {
        auto _node_result = parseItemCaseLabel(_rp, _ep);
        ItemCaseLabel* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<CaseLabel, ParserError>(node);
    }
    {
        auto _node_result = parseDefaultCaseLabel(_rp, _ep);
        DefaultCaseLabel* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<CaseLabel, ParserError>(node);
    }
    return _Result<CaseLabel, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_unableToParse(new(_ep) Position(start), new(_ep) _Array<ParserError>(errors))));
}

_Result<ItemCaseLabel, ParserError> Parser::parseItemCaseLabel(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startCase1 = lexer->getPreviousPosition(_p);
    bool successCase1 = lexer->parseKeyword(caseKeyword);
    if (successCase1)
        lexer->advance();
    else
        return _Result<ItemCaseLabel, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startCase1), new(_ep) string(caseKeyword))));
    auto _pattern_result = parsePattern(_rp, _ep);
    Pattern* pattern = nullptr;
    if (_pattern_result.succeeded()) {
        pattern = _pattern_result.getResult();
    }
    else {
        auto error = _pattern_result.getError();
        return _Result<ItemCaseLabel, ParserError>(error);
    }
    auto _additionalPatterns_result = parseCaseItemList(_rp, _ep);
    _Array<CaseItem>* additionalPatterns = nullptr;
    if (_additionalPatterns_result.succeeded()) {
        additionalPatterns = _additionalPatterns_result.getResult();
    }
    else {
        additionalPatterns = nullptr;
    }
    Position* startColon4 = lexer->getPreviousPosition(_p);
    bool successColon4 = lexer->parsePunctuation(colon);
    if (successColon4)
        lexer->advance();
    else
        return _Result<ItemCaseLabel, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startColon4), new(_ep) string(colon))));
    Position* end = lexer->getPosition(_p);
    ItemCaseLabel* ret = new(_rp) ItemCaseLabel(pattern, additionalPatterns, new(_rp) Position(start), new(_rp) Position(end));
    pattern->parent = ret;
    if (additionalPatterns != nullptr) {
        CaseItem* item = nullptr;
        size_t _additionalPatterns_length = additionalPatterns->length();
        for (size_t _i = 0; _i < _additionalPatterns_length; _i++) {
            item = *(*additionalPatterns)[_i];
            item->parent = ret;
        }
    }
    return _Result<ItemCaseLabel, ParserError>(ret);
}

_Result<DefaultCaseLabel, ParserError> Parser::parseDefaultCaseLabel(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startDefault1 = lexer->getPreviousPosition(_p);
    bool successDefault1 = lexer->parseKeyword(defaultKeyword);
    if (successDefault1)
        lexer->advance();
    else
        return _Result<DefaultCaseLabel, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startDefault1), new(_ep) string(defaultKeyword))));
    Position* startColon2 = lexer->getPreviousPosition(_p);
    bool successColon2 = lexer->parsePunctuation(colon);
    if (successColon2)
        lexer->advance();
    else
        return _Result<DefaultCaseLabel, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startColon2), new(_ep) string(colon))));
    Position* end = lexer->getPosition(_p);
    DefaultCaseLabel* ret = new(_rp) DefaultCaseLabel(new(_rp) Position(start), new(_rp) Position(end));
    return _Result<DefaultCaseLabel, ParserError>(ret);
}

_Result<_Array<CaseItem>, ParserError> Parser::parseCaseItemList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<CaseItem>* ret = nullptr;
    while (true) {
        auto _node_result = parseCaseItem(_rp, _ep);
        CaseItem* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<CaseItem>();
        ret->push(node);
    }
    return _Result<_Array<CaseItem>, ParserError>(ret ? new(_rp) _Array<CaseItem>(ret) : nullptr);
}

_Result<CaseItem, ParserError> Parser::parseCaseItem(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startComma1 = lexer->getPreviousPosition(_p);
    bool successComma1 = lexer->parsePunctuation(comma);
    if (successComma1)
        lexer->advance();
    else
        return _Result<CaseItem, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startComma1), new(_ep) string(comma))));
    auto _pattern_result = parsePattern(_rp, _ep);
    Pattern* pattern = nullptr;
    if (_pattern_result.succeeded()) {
        pattern = _pattern_result.getResult();
    }
    else {
        auto error = _pattern_result.getError();
        return _Result<CaseItem, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    CaseItem* ret = new(_rp) CaseItem(pattern, new(_rp) Position(start), new(_rp) Position(end));
    pattern->parent = ret;
    return _Result<CaseItem, ParserError>(ret);
}

_Result<Pattern, ParserError> Parser::parsePattern(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ParserError>* errors = new(_p) _Array<ParserError>();
    Position* start = lexer->getPreviousPosition(_p);
    {
        auto _node_result = parseWildcardPattern(_rp, _ep);
        WildcardPattern* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Pattern, ParserError>(node);
    }
    {
        auto _node_result = parseIdentifierPattern(_rp, _ep);
        IdentifierPattern* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Pattern, ParserError>(node);
    }
    {
        auto _node_result = parseTuplePattern(_rp, _ep);
        TuplePattern* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Pattern, ParserError>(node);
    }
    {
        auto _node_result = parseExpressionPattern(_rp, _ep);
        ExpressionPattern* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<Pattern, ParserError>(node);
    }
    return _Result<Pattern, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_unableToParse(new(_ep) Position(start), new(_ep) _Array<ParserError>(errors))));
}

_Result<WildcardPattern, ParserError> Parser::parseWildcardPattern(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startUnderscore1 = lexer->getPreviousPosition(_p);
    bool successUnderscore1 = lexer->parsePunctuation(underscore);
    if (successUnderscore1)
        lexer->advance();
    else
        return _Result<WildcardPattern, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startUnderscore1), new(_ep) string(underscore))));
    Position* end = lexer->getPosition(_p);
    WildcardPattern* ret = new(_rp) WildcardPattern(new(_rp) Position(start), new(_rp) Position(end));
    return _Result<WildcardPattern, ParserError>(ret);
}

_Result<IdentifierPattern, ParserError> Parser::parseIdentifierPattern(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startIdentifier = lexer->getPreviousPosition(_p);
    string* identifier = lexer->parseIdentifier(_rp);
    if ((identifier != nullptr) && isIdentifier(identifier))
        lexer->advance();
    else
        return _Result<IdentifierPattern, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_identifierExpected(new(_ep) Position(startIdentifier))));
    auto _annotationForType_result = parseTypeAnnotation(_rp, _ep);
    TypeAnnotation* annotationForType = nullptr;
    if (_annotationForType_result.succeeded()) {
        annotationForType = _annotationForType_result.getResult();
    }
    else {
        annotationForType = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    IdentifierPattern* ret = new(_rp) IdentifierPattern(identifier, annotationForType, new(_rp) Position(start), new(_rp) Position(end));
    if (annotationForType != nullptr)
        annotationForType->parent = ret;
    return _Result<IdentifierPattern, ParserError>(ret);
}

_Result<TuplePattern, ParserError> Parser::parseTuplePattern(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startLeftParen1 = lexer->getPreviousPosition(_p);
    bool successLeftParen1 = lexer->parsePunctuation(leftParen);
    if (successLeftParen1)
        lexer->advance();
    else
        return _Result<TuplePattern, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startLeftParen1), new(_ep) string(leftParen))));
    auto _elements_result = parseTuplePatternElementList(_rp, _ep);
    _Array<TuplePatternElement>* elements = nullptr;
    if (_elements_result.succeeded()) {
        elements = _elements_result.getResult();
    }
    else {
        auto error = _elements_result.getError();
        return _Result<TuplePattern, ParserError>(error);
    }
    Position* startRightParen3 = lexer->getPreviousPosition(_p);
    bool successRightParen3 = lexer->parsePunctuation(rightParen);
    if (successRightParen3)
        lexer->advance();
    else
        return _Result<TuplePattern, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startRightParen3), new(_ep) string(rightParen))));
    Position* end = lexer->getPosition(_p);
    TuplePattern* ret = new(_rp) TuplePattern(elements, new(_rp) Position(start), new(_rp) Position(end));
    if (elements != nullptr) {
        TuplePatternElement* item = nullptr;
        size_t _elements_length = elements->length();
        for (size_t _i = 0; _i < _elements_length; _i++) {
            item = *(*elements)[_i];
            item->parent = ret;
        }
    }
    return _Result<TuplePattern, ParserError>(ret);
}

_Result<ExpressionPattern, ParserError> Parser::parseExpressionPattern(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _expression_result = parseExpression(_rp, _ep);
    Expression* expression = nullptr;
    if (_expression_result.succeeded()) {
        expression = _expression_result.getResult();
    }
    else {
        auto error = _expression_result.getError();
        return _Result<ExpressionPattern, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    ExpressionPattern* ret = new(_rp) ExpressionPattern(expression, new(_rp) Position(start), new(_rp) Position(end));
    expression->parent = ret;
    return _Result<ExpressionPattern, ParserError>(ret);
}

_Result<_Array<TuplePatternElement>, ParserError> Parser::parseTuplePatternElementList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<TuplePatternElement>* ret = nullptr;
    while (true) {
        auto _node_result = parseTuplePatternElement(_rp, _ep);
        TuplePatternElement* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<TuplePatternElement>();
        ret->push(node);
    }
    return _Result<_Array<TuplePatternElement>, ParserError>(ret ? new(_rp) _Array<TuplePatternElement>(ret) : nullptr);
}

_Result<TuplePatternElement, ParserError> Parser::parseTuplePatternElement(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _pattern_result = parsePattern(_rp, _ep);
    Pattern* pattern = nullptr;
    if (_pattern_result.succeeded()) {
        pattern = _pattern_result.getResult();
    }
    else {
        auto error = _pattern_result.getError();
        return _Result<TuplePatternElement, ParserError>(error);
    }
    bool successComma2 = lexer->parsePunctuation(comma);
    if (successComma2)
        lexer->advance();
    Position* end = lexer->getPosition(_p);
    TuplePatternElement* ret = new(_rp) TuplePatternElement(pattern, new(_rp) Position(start), new(_rp) Position(end));
    pattern->parent = ret;
    return _Result<TuplePatternElement, ParserError>(ret);
}

_Result<CaseContent, ParserError> Parser::parseCaseContent(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _statements_result = parseStatementList(_rp, _ep);
    _Array<Statement>* statements = nullptr;
    if (_statements_result.succeeded()) {
        statements = _statements_result.getResult();
    }
    else {
        auto error = _statements_result.getError();
        return _Result<CaseContent, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    CaseContent* ret = new(_rp) CaseContent(statements, new(_rp) Position(start), new(_rp) Position(end));
    if (statements != nullptr) {
        Statement* item = nullptr;
        size_t _statements_length = statements->length();
        for (size_t _i = 0; _i < _statements_length; _i++) {
            item = *(*statements)[_i];
            item->parent = ret;
        }
    }
    return _Result<CaseContent, ParserError>(ret);
}

_Result<Type, ParserError> Parser::parseType(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startName = lexer->getPreviousPosition(_p);
    string* name = lexer->parseIdentifier(_rp);
    if ((name != nullptr) && isIdentifier(name))
        lexer->advance();
    else
        return _Result<Type, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_identifierExpected(new(_ep) Position(startName))));
    auto _subType_result = parseSubtype(_rp, _ep);
    Subtype* subType = nullptr;
    if (_subType_result.succeeded()) {
        subType = _subType_result.getResult();
    }
    else {
        subType = nullptr;
    }
    auto _postfixes_result = parseTypePostfixList(_rp, _ep);
    _Array<TypePostfix>* postfixes = nullptr;
    if (_postfixes_result.succeeded()) {
        postfixes = _postfixes_result.getResult();
    }
    else {
        postfixes = nullptr;
    }
    auto _lifeTime_result = parseLifeTime(_rp, _ep);
    LifeTime* lifeTime = nullptr;
    if (_lifeTime_result.succeeded()) {
        lifeTime = _lifeTime_result.getResult();
    }
    else {
        lifeTime = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    Type* ret = new(_rp) Type(name, subType, postfixes, lifeTime, new(_rp) Position(start), new(_rp) Position(end));
    if (subType != nullptr)
        subType->parent = ret;
    if (postfixes != nullptr) {
        TypePostfix* item = nullptr;
        size_t _postfixes_length = postfixes->length();
        for (size_t _i = 0; _i < _postfixes_length; _i++) {
            item = *(*postfixes)[_i];
            item->parent = ret;
        }
    }
    if (lifeTime != nullptr)
        lifeTime->parent = ret;
    return _Result<Type, ParserError>(ret);
}

_Result<TypeAnnotation, ParserError> Parser::parseTypeAnnotation(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startColon1 = lexer->getPreviousPosition(_p);
    bool successColon1 = lexer->parsePunctuation(colon);
    if (successColon1)
        lexer->advance();
    else
        return _Result<TypeAnnotation, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startColon1), new(_ep) string(colon))));
    auto _annotationForType_result = parseType(_rp, _ep);
    Type* annotationForType = nullptr;
    if (_annotationForType_result.succeeded()) {
        annotationForType = _annotationForType_result.getResult();
    }
    else {
        auto error = _annotationForType_result.getError();
        return _Result<TypeAnnotation, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    TypeAnnotation* ret = new(_rp) TypeAnnotation(annotationForType, new(_rp) Position(start), new(_rp) Position(end));
    annotationForType->parent = ret;
    return _Result<TypeAnnotation, ParserError>(ret);
}

_Result<Subtype, ParserError> Parser::parseSubtype(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startDot1 = lexer->getPreviousPosition(_p);
    bool successDot1 = lexer->parsePunctuation(dot);
    if (successDot1)
        lexer->advance();
    else
        return _Result<Subtype, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startDot1), new(_ep) string(dot))));
    auto _type_result = parseType(_rp, _ep);
    Type* type = nullptr;
    if (_type_result.succeeded()) {
        type = _type_result.getResult();
    }
    else {
        auto error = _type_result.getError();
        return _Result<Subtype, ParserError>(error);
    }
    Position* end = lexer->getPosition(_p);
    Subtype* ret = new(_rp) Subtype(type, new(_rp) Position(start), new(_rp) Position(end));
    type->parent = ret;
    return _Result<Subtype, ParserError>(ret);
}

_Result<_Array<TypePostfix>, ParserError> Parser::parseTypePostfixList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<TypePostfix>* ret = nullptr;
    while (true) {
        auto _node_result = parseTypePostfix(_rp, _ep);
        TypePostfix* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<TypePostfix>();
        ret->push(node);
    }
    return _Result<_Array<TypePostfix>, ParserError>(ret ? new(_rp) _Array<TypePostfix>(ret) : nullptr);
}

_Result<TypePostfix, ParserError> Parser::parseTypePostfix(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ParserError>* errors = new(_p) _Array<ParserError>();
    Position* start = lexer->getPreviousPosition(_p);
    {
        auto _node_result = parseIndexedType(_rp, _ep);
        IndexedType* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<TypePostfix, ParserError>(node);
    }
    {
        auto _node_result = parsePointer(_rp, _ep);
        Pointer* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<TypePostfix, ParserError>(node);
    }
    return _Result<TypePostfix, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_unableToParse(new(_ep) Position(start), new(_ep) _Array<ParserError>(errors))));
}

_Result<IndexedType, ParserError> Parser::parseIndexedType(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startLeftBracket1 = lexer->getPreviousPosition(_p);
    bool successLeftBracket1 = lexer->parsePunctuation(leftBracket);
    if (successLeftBracket1)
        lexer->advance();
    else
        return _Result<IndexedType, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startLeftBracket1), new(_ep) string(leftBracket))));
    auto _key_result = parseType(_rp, _ep);
    Type* key = nullptr;
    if (_key_result.succeeded()) {
        key = _key_result.getResult();
    }
    else {
        key = nullptr;
    }
    Position* startRightBracket3 = lexer->getPreviousPosition(_p);
    bool successRightBracket3 = lexer->parsePunctuation(rightBracket);
    if (successRightBracket3)
        lexer->advance();
    else
        return _Result<IndexedType, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startRightBracket3), new(_ep) string(rightBracket))));
    Position* end = lexer->getPosition(_p);
    IndexedType* ret = new(_rp) IndexedType(key, new(_rp) Position(start), new(_rp) Position(end));
    if (key != nullptr)
        key->parent = ret;
    return _Result<IndexedType, ParserError>(ret);
}

_Result<Pointer, ParserError> Parser::parsePointer(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startCircumflex1 = lexer->getPreviousPosition(_p);
    bool successCircumflex1 = lexer->parsePunctuation(circumflex);
    if (successCircumflex1)
        lexer->advance();
    else
        return _Result<Pointer, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startCircumflex1), new(_ep) string(circumflex))));
    Position* end = lexer->getPosition(_p);
    Pointer* ret = new(_rp) Pointer(new(_rp) Position(start), new(_rp) Position(end));
    return _Result<Pointer, ParserError>(ret);
}

_Result<LifeTime, ParserError> Parser::parseLifeTime(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<ParserError>* errors = new(_p) _Array<ParserError>();
    Position* start = lexer->getPreviousPosition(_p);
    {
        auto _node_result = parseRoot(_rp, _ep);
        Root* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<LifeTime, ParserError>(node);
    }
    {
        auto _node_result = parseLocal(_rp, _ep);
        Local* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<LifeTime, ParserError>(node);
    }
    {
        auto _node_result = parseReference(_rp, _ep);
        Reference* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<LifeTime, ParserError>(node);
    }
    {
        auto _node_result = parseThrown(_rp, _ep);
        Thrown* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            auto error = _node_result.getError();
            {
                errors->push(error);
            }
        }
        if (node != nullptr)
            return _Result<LifeTime, ParserError>(node);
    }
    return _Result<LifeTime, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_unableToParse(new(_ep) Position(start), new(_ep) _Array<ParserError>(errors))));
}

_Result<Root, ParserError> Parser::parseRoot(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startDollar1 = lexer->getPreviousPosition(_p);
    bool successDollar1 = lexer->parsePunctuation(dollar);
    if (successDollar1)
        lexer->advance();
    else
        return _Result<Root, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startDollar1), new(_ep) string(dollar))));
    Position* end = lexer->getPosition(_p);
    Root* ret = new(_rp) Root(new(_rp) Position(start), new(_rp) Position(end));
    return _Result<Root, ParserError>(ret);
}

_Result<Local, ParserError> Parser::parseLocal(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startAt1 = lexer->getPreviousPosition(_p);
    bool successAt1 = lexer->parsePunctuation(at);
    if (successAt1)
        lexer->advance();
    else
        return _Result<Local, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startAt1), new(_ep) string(at))));
    Position* startLocation = lexer->getPreviousPosition(_p);
    string* location = lexer->parseIdentifier(_rp);
    if ((location != nullptr) && isIdentifier(location))
        lexer->advance();
    else
        return _Result<Local, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_identifierExpected(new(_ep) Position(startLocation))));
    Position* end = lexer->getPosition(_p);
    Local* ret = new(_rp) Local(location, new(_rp) Position(start), new(_rp) Position(end));
    return _Result<Local, ParserError>(ret);
}

_Result<Reference, ParserError> Parser::parseReference(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startAmpersand1 = lexer->getPreviousPosition(_p);
    bool successAmpersand1 = lexer->parsePunctuation(ampersand);
    if (successAmpersand1)
        lexer->advance();
    else
        return _Result<Reference, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startAmpersand1), new(_ep) string(ampersand))));
    Literal* age = lexer->parseLiteral(_rp);
    if (age != nullptr)
        lexer->advance();
    Position* end = lexer->getPosition(_p);
    Reference* ret = new(_rp) Reference(age, new(_rp) Position(start), new(_rp) Position(end));
    return _Result<Reference, ParserError>(ret);
}

_Result<Thrown, ParserError> Parser::parseThrown(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startHash1 = lexer->getPreviousPosition(_p);
    bool successHash1 = lexer->parsePunctuation(hash);
    if (successHash1)
        lexer->advance();
    else
        return _Result<Thrown, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_punctuationExpected(new(_ep) Position(startHash1), new(_ep) string(hash))));
    Position* end = lexer->getPosition(_p);
    Thrown* ret = new(_rp) Thrown(new(_rp) Position(start), new(_rp) Position(end));
    return _Result<Thrown, ParserError>(ret);
}

_Result<TypeInheritanceClause, ParserError> Parser::parseTypeInheritanceClause(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    Position* startExtends1 = lexer->getPreviousPosition(_p);
    bool successExtends1 = lexer->parseKeyword(extendsKeyword);
    if (successExtends1)
        lexer->advance();
    else
        return _Result<TypeInheritanceClause, ParserError>(new(_ep) ParserError(new(_ep) _ParserError_keywordExpected(new(_ep) Position(startExtends1), new(_ep) string(extendsKeyword))));
    auto _inheritances_result = parseInheritanceList(_rp, _ep);
    _Array<Inheritance>* inheritances = nullptr;
    if (_inheritances_result.succeeded()) {
        inheritances = _inheritances_result.getResult();
    }
    else {
        inheritances = nullptr;
    }
    Position* end = lexer->getPosition(_p);
    TypeInheritanceClause* ret = new(_rp) TypeInheritanceClause(inheritances, new(_rp) Position(start), new(_rp) Position(end));
    if (inheritances != nullptr) {
        Inheritance* item = nullptr;
        size_t _inheritances_length = inheritances->length();
        for (size_t _i = 0; _i < _inheritances_length; _i++) {
            item = *(*inheritances)[_i];
            item->parent = ret;
        }
    }
    return _Result<TypeInheritanceClause, ParserError>(ret);
}

_Result<_Array<Inheritance>, ParserError> Parser::parseInheritanceList(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    _Array<Inheritance>* ret = nullptr;
    while (true) {
        auto _node_result = parseInheritance(_rp, _ep);
        Inheritance* node = nullptr;
        if (_node_result.succeeded()) {
            node = _node_result.getResult();
        }
        else {
            break;
        }
        if (ret == nullptr)
            ret = new(_p) _Array<Inheritance>();
        ret->push(node);
    }
    return _Result<_Array<Inheritance>, ParserError>(ret ? new(_rp) _Array<Inheritance>(ret) : nullptr);
}

_Result<Inheritance, ParserError> Parser::parseInheritance(_Page* _rp, _Page* _ep) {
    _Region _region; _Page* _p = _region.get();
    Position* start = lexer->getPreviousPosition(_p);
    auto _type_result = parseType(_rp, _ep);
    Type* type = nullptr;
    if (_type_result.succeeded()) {
        type = _type_result.getResult();
    }
    else {
        auto error = _type_result.getError();
        return _Result<Inheritance, ParserError>(error);
    }
    bool successComma2 = lexer->parsePunctuation(comma);
    if (successComma2)
        lexer->advance();
    Position* end = lexer->getPosition(_p);
    Inheritance* ret = new(_rp) Inheritance(type, new(_rp) Position(start), new(_rp) Position(end));
    type->parent = ret;
    return _Result<Inheritance, ParserError>(ret);
}

bool Parser::isAtEnd() {
    return lexer->isAtEnd();
}

bool Parser::isIdentifier(string* id) {
    if (id->equals(classKeyword))
        return false;
    if (id->equals(functionKeyword))
        return false;
    if (id->equals(ifKeyword))
        return false;
    if (id->equals(elseKeyword))
        return false;
    if (id->equals(switchKeyword))
        return false;
    if (id->equals(caseKeyword))
        return false;
    if (id->equals(defaultKeyword))
        return false;
    if (id->equals(catchKeyword))
        return false;
    if (id->equals(forKeyword))
        return false;
    if (id->equals(inKeyword))
        return false;
    if (id->equals(whileKeyword))
        return false;
    if (id->equals(doKeyword))
        return false;
    if (id->equals(returnKeyword))
        return false;
    if (id->equals(throwKeyword))
        return false;
    if (id->equals(breakKeyword))
        return false;
    if (id->equals(throwsKeyword))
        return false;
    if (id->equals(overrideKeyword))
        return false;
    if (id->equals(staticKeyword))
        return false;
    if (id->equals(letKeyword))
        return false;
    if (id->equals(varKeyword))
        return false;
    if (id->equals(mutableKeyword))
        return false;
    if (id->equals(isKeyword))
        return false;
    if (id->equals(asKeyword))
        return false;
    if (id->equals(constructorKeyword))
        return false;
    if (id->equals(enumKeyword))
        return false;
    if (id->equals(thisKeyword))
        return false;
    if (id->equals(nullKeyword))
        return false;
    if (id->equals(newKeyword))
        return false;
    if (id->equals(extendsKeyword))
        return false;
    return true;
}


}
