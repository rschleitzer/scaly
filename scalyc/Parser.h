#ifndef __scalyc__Parser__
#define __scalyc__Parser__
#include "scalyc.h"
using namespace scaly;
namespace scalyc {

class Parser : public Object {
public:
    Parser(string* theFileName, string* text);
    virtual _Result<CompilationUnit, ParserError> parseCompilationUnit(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<TerminatedStatement>, ParserError> parseTerminatedStatementList(_Page* _rp, _Page* _ep);
    virtual _Result<TerminatedStatement, ParserError> parseTerminatedStatement(_Page* _rp, _Page* _ep);
    virtual _Result<Statement, ParserError> parseStatement(_Page* _rp, _Page* _ep);
    virtual _Result<Declaration, ParserError> parseDeclaration(_Page* _rp, _Page* _ep);
    virtual _Result<Expression, ParserError> parseExpression(_Page* _rp, _Page* _ep);
    virtual _Result<UseDeclaration, ParserError> parseUseDeclaration(_Page* _rp, _Page* _ep);
    virtual _Result<ConstantDeclaration, ParserError> parseConstantDeclaration(_Page* _rp, _Page* _ep);
    virtual _Result<VariableDeclaration, ParserError> parseVariableDeclaration(_Page* _rp, _Page* _ep);
    virtual _Result<MutableDeclaration, ParserError> parseMutableDeclaration(_Page* _rp, _Page* _ep);
    virtual _Result<FunctionDeclaration, ParserError> parseFunctionDeclaration(_Page* _rp, _Page* _ep);
    virtual _Result<EnumDeclaration, ParserError> parseEnumDeclaration(_Page* _rp, _Page* _ep);
    virtual _Result<ClassDeclaration, ParserError> parseClassDeclaration(_Page* _rp, _Page* _ep);
    virtual _Result<ConstructorDeclaration, ParserError> parseConstructorDeclaration(_Page* _rp, _Page* _ep);
    virtual _Result<CodeBlock, ParserError> parseCodeBlock(_Page* _rp, _Page* _ep);
    virtual _Result<SimpleExpression, ParserError> parseSimpleExpression(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<PathIdentifier>, ParserError> parsePathIdentifierList(_Page* _rp, _Page* _ep);
    virtual _Result<PathIdentifier, ParserError> parsePathIdentifier(_Page* _rp, _Page* _ep);
    virtual _Result<PathItem, ParserError> parsePathItem(_Page* _rp, _Page* _ep);
    virtual _Result<Initializer, ParserError> parseInitializer(_Page* _rp, _Page* _ep);
    virtual _Result<BindingInitializer, ParserError> parseBindingInitializer(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<PatternInitializer>, ParserError> parsePatternInitializerList(_Page* _rp, _Page* _ep);
    virtual _Result<PatternInitializer, ParserError> parsePatternInitializer(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<AdditionalInitializer>, ParserError> parseAdditionalInitializerList(_Page* _rp, _Page* _ep);
    virtual _Result<AdditionalInitializer, ParserError> parseAdditionalInitializer(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<Modifier>, ParserError> parseModifierList(_Page* _rp, _Page* _ep);
    virtual _Result<Modifier, ParserError> parseModifier(_Page* _rp, _Page* _ep);
    virtual _Result<OverrideWord, ParserError> parseOverrideWord(_Page* _rp, _Page* _ep);
    virtual _Result<StaticWord, ParserError> parseStaticWord(_Page* _rp, _Page* _ep);
    virtual _Result<FunctionName, ParserError> parseFunctionName(_Page* _rp, _Page* _ep);
    virtual _Result<IdentifierFunction, ParserError> parseIdentifierFunction(_Page* _rp, _Page* _ep);
    virtual _Result<FunctionSignature, ParserError> parseFunctionSignature(_Page* _rp, _Page* _ep);
    virtual _Result<FunctionResult, ParserError> parseFunctionResult(_Page* _rp, _Page* _ep);
    virtual _Result<ExistingClause, ParserError> parseExistingClause(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<ParameterClause>, ParserError> parseParameterClauseList(_Page* _rp, _Page* _ep);
    virtual _Result<ParameterClause, ParserError> parseParameterClause(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<Parameter>, ParserError> parseParameterList(_Page* _rp, _Page* _ep);
    virtual _Result<Parameter, ParserError> parseParameter(_Page* _rp, _Page* _ep);
    virtual _Result<ConstParameter, ParserError> parseConstParameter(_Page* _rp, _Page* _ep);
    virtual _Result<VarParameter, ParserError> parseVarParameter(_Page* _rp, _Page* _ep);
    virtual _Result<ThrowsClause, ParserError> parseThrowsClause(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<EnumMember>, ParserError> parseEnumMemberList(_Page* _rp, _Page* _ep);
    virtual _Result<EnumMember, ParserError> parseEnumMember(_Page* _rp, _Page* _ep);
    virtual _Result<EnumCase, ParserError> parseEnumCase(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<AdditionalCase>, ParserError> parseAdditionalCaseList(_Page* _rp, _Page* _ep);
    virtual _Result<AdditionalCase, ParserError> parseAdditionalCase(_Page* _rp, _Page* _ep);
    virtual _Result<ClassBody, ParserError> parseClassBody(_Page* _rp, _Page* _ep);
    virtual _Result<GenericArgumentClause, ParserError> parseGenericArgumentClause(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<GenericParameter>, ParserError> parseGenericParameterList(_Page* _rp, _Page* _ep);
    virtual _Result<GenericParameter, ParserError> parseGenericParameter(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<ClassMember>, ParserError> parseClassMemberList(_Page* _rp, _Page* _ep);
    virtual _Result<ClassMember, ParserError> parseClassMember(_Page* _rp, _Page* _ep);
    virtual _Result<PrefixExpression, ParserError> parsePrefixExpression(_Page* _rp, _Page* _ep);
    virtual _Result<PostfixExpression, ParserError> parsePostfixExpression(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<BinaryOp>, ParserError> parseBinaryOpList(_Page* _rp, _Page* _ep);
    virtual _Result<BinaryOp, ParserError> parseBinaryOp(_Page* _rp, _Page* _ep);
    virtual _Result<BinaryOperation, ParserError> parseBinaryOperation(_Page* _rp, _Page* _ep);
    virtual _Result<Assignment, ParserError> parseAssignment(_Page* _rp, _Page* _ep);
    virtual _Result<TypeQuery, ParserError> parseTypeQuery(_Page* _rp, _Page* _ep);
    virtual _Result<TypeCast, ParserError> parseTypeCast(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<CatchClause>, ParserError> parseCatchClauseList(_Page* _rp, _Page* _ep);
    virtual _Result<CatchClause, ParserError> parseCatchClause(_Page* _rp, _Page* _ep);
    virtual _Result<CatchPattern, ParserError> parseCatchPattern(_Page* _rp, _Page* _ep);
    virtual _Result<WildCardCatchPattern, ParserError> parseWildCardCatchPattern(_Page* _rp, _Page* _ep);
    virtual _Result<IdentifierCatchPattern, ParserError> parseIdentifierCatchPattern(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<Postfix>, ParserError> parsePostfixList(_Page* _rp, _Page* _ep);
    virtual _Result<Postfix, ParserError> parsePostfix(_Page* _rp, _Page* _ep);
    virtual _Result<OperatorPostfix, ParserError> parseOperatorPostfix(_Page* _rp, _Page* _ep);
    virtual _Result<FunctionCall, ParserError> parseFunctionCall(_Page* _rp, _Page* _ep);
    virtual _Result<ExplicitMemberExpression, ParserError> parseExplicitMemberExpression(_Page* _rp, _Page* _ep);
    virtual _Result<Subscript, ParserError> parseSubscript(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<ExpressionElement>, ParserError> parseExpressionElementList(_Page* _rp, _Page* _ep);
    virtual _Result<ExpressionElement, ParserError> parseExpressionElement(_Page* _rp, _Page* _ep);
    virtual _Result<MemberPostfix, ParserError> parseMemberPostfix(_Page* _rp, _Page* _ep);
    virtual _Result<NamedMemberPostfix, ParserError> parseNamedMemberPostfix(_Page* _rp, _Page* _ep);
    virtual _Result<PrimaryExpression, ParserError> parsePrimaryExpression(_Page* _rp, _Page* _ep);
    virtual _Result<IdentifierExpression, ParserError> parseIdentifierExpression(_Page* _rp, _Page* _ep);
    virtual _Result<LiteralExpression, ParserError> parseLiteralExpression(_Page* _rp, _Page* _ep);
    virtual _Result<IfExpression, ParserError> parseIfExpression(_Page* _rp, _Page* _ep);
    virtual _Result<SwitchExpression, ParserError> parseSwitchExpression(_Page* _rp, _Page* _ep);
    virtual _Result<ForExpression, ParserError> parseForExpression(_Page* _rp, _Page* _ep);
    virtual _Result<WhileExpression, ParserError> parseWhileExpression(_Page* _rp, _Page* _ep);
    virtual _Result<RepeatExpression, ParserError> parseRepeatExpression(_Page* _rp, _Page* _ep);
    virtual _Result<ParenthesizedExpression, ParserError> parseParenthesizedExpression(_Page* _rp, _Page* _ep);
    virtual _Result<ReturnExpression, ParserError> parseReturnExpression(_Page* _rp, _Page* _ep);
    virtual _Result<ThrowExpression, ParserError> parseThrowExpression(_Page* _rp, _Page* _ep);
    virtual _Result<BreakExpression, ParserError> parseBreakExpression(_Page* _rp, _Page* _ep);
    virtual _Result<ConstructorCall, ParserError> parseConstructorCall(_Page* _rp, _Page* _ep);
    virtual _Result<ThisExpression, ParserError> parseThisExpression(_Page* _rp, _Page* _ep);
    virtual _Result<SuperExpression, ParserError> parseSuperExpression(_Page* _rp, _Page* _ep);
    virtual _Result<SuperDot, ParserError> parseSuperDot(_Page* _rp, _Page* _ep);
    virtual _Result<SuperSubscript, ParserError> parseSuperSubscript(_Page* _rp, _Page* _ep);
    virtual _Result<NullExpression, ParserError> parseNullExpression(_Page* _rp, _Page* _ep);
    virtual _Result<ElseClause, ParserError> parseElseClause(_Page* _rp, _Page* _ep);
    virtual _Result<SwitchBody, ParserError> parseSwitchBody(_Page* _rp, _Page* _ep);
    virtual _Result<CurliedSwitchBody, ParserError> parseCurliedSwitchBody(_Page* _rp, _Page* _ep);
    virtual _Result<NakedSwitchBody, ParserError> parseNakedSwitchBody(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<SwitchCase>, ParserError> parseSwitchCaseList(_Page* _rp, _Page* _ep);
    virtual _Result<SwitchCase, ParserError> parseSwitchCase(_Page* _rp, _Page* _ep);
    virtual _Result<CaseLabel, ParserError> parseCaseLabel(_Page* _rp, _Page* _ep);
    virtual _Result<ItemCaseLabel, ParserError> parseItemCaseLabel(_Page* _rp, _Page* _ep);
    virtual _Result<DefaultCaseLabel, ParserError> parseDefaultCaseLabel(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<CaseItem>, ParserError> parseCaseItemList(_Page* _rp, _Page* _ep);
    virtual _Result<CaseItem, ParserError> parseCaseItem(_Page* _rp, _Page* _ep);
    virtual _Result<Pattern, ParserError> parsePattern(_Page* _rp, _Page* _ep);
    virtual _Result<WildcardPattern, ParserError> parseWildcardPattern(_Page* _rp, _Page* _ep);
    virtual _Result<IdentifierPattern, ParserError> parseIdentifierPattern(_Page* _rp, _Page* _ep);
    virtual _Result<TuplePattern, ParserError> parseTuplePattern(_Page* _rp, _Page* _ep);
    virtual _Result<ExpressionPattern, ParserError> parseExpressionPattern(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<TuplePatternElement>, ParserError> parseTuplePatternElementList(_Page* _rp, _Page* _ep);
    virtual _Result<TuplePatternElement, ParserError> parseTuplePatternElement(_Page* _rp, _Page* _ep);
    virtual _Result<CaseContent, ParserError> parseCaseContent(_Page* _rp, _Page* _ep);
    virtual _Result<CommonSuperMember, ParserError> parseCommonSuperMember(_Page* _rp, _Page* _ep);
    virtual _Result<SuperConstructor, ParserError> parseSuperConstructor(_Page* _rp, _Page* _ep);
    virtual _Result<SuperMember, ParserError> parseSuperMember(_Page* _rp, _Page* _ep);
    virtual _Result<Type, ParserError> parseType(_Page* _rp, _Page* _ep);
    virtual _Result<TypeAnnotation, ParserError> parseTypeAnnotation(_Page* _rp, _Page* _ep);
    virtual _Result<Subtype, ParserError> parseSubtype(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<TypePostfix>, ParserError> parseTypePostfixList(_Page* _rp, _Page* _ep);
    virtual _Result<TypePostfix, ParserError> parseTypePostfix(_Page* _rp, _Page* _ep);
    virtual _Result<OptionalType, ParserError> parseOptionalType(_Page* _rp, _Page* _ep);
    virtual _Result<IndexedType, ParserError> parseIndexedType(_Page* _rp, _Page* _ep);
    virtual _Result<TypeInheritanceClause, ParserError> parseTypeInheritanceClause(_Page* _rp, _Page* _ep);
    virtual _Result<_Vector<Inheritance>, ParserError> parseInheritanceList(_Page* _rp, _Page* _ep);
    virtual _Result<Inheritance, ParserError> parseInheritance(_Page* _rp, _Page* _ep);
    virtual bool isAtEnd();
    virtual bool isIdentifier(string* id);
    Lexer* lexer;
    string* fileName;
    string* useKeyword;
    string* classKeyword;
    string* functionKeyword;
    string* ifKeyword;
    string* elseKeyword;
    string* switchKeyword;
    string* caseKeyword;
    string* defaultKeyword;
    string* catchKeyword;
    string* forKeyword;
    string* inKeyword;
    string* whileKeyword;
    string* repeatKeyword;
    string* returnKeyword;
    string* throwKeyword;
    string* breakKeyword;
    string* throwsKeyword;
    string* existingKeyword;
    string* overrideKeyword;
    string* staticKeyword;
    string* letKeyword;
    string* varKeyword;
    string* mutableKeyword;
    string* isKeyword;
    string* asKeyword;
    string* constructorKeyword;
    string* enumKeyword;
    string* superKeyword;
    string* thisKeyword;
    string* nullKeyword;
    string* newKeyword;
    string* extendsKeyword;
    string* equal;
    string* leftAngular;
    string* rightAngular;
    string* comma;
    string* leftParen;
    string* rightParen;
    string* leftCurly;
    string* rightCurly;
    string* leftBracket;
    string* rightBracket;
    string* colon;
    string* dot;
    string* questionMark;
    string* underscore;

};

}
#endif // __scalyc__Parser__
