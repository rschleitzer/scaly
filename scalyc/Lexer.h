#ifndef __scalyc__Lexer__
#define __scalyc__Lexer__
#include "scalyc.h"
using namespace scaly;
namespace scalyc {
 
class Position : public Object {
public:
    Position(size_t line, size_t column);
    size_t line;
    size_t column;
};

class Token  : public Object {
public:
    virtual bool _isPunctuation() = 0;
    virtual bool _isIdentifier() = 0;
    virtual bool _isOperator() = 0;
    virtual bool _isPrefixOperator() = 0;
    virtual bool _isBinaryOperator() = 0;
    virtual bool _isPostfixOperator() = 0;
    virtual bool _isLiteral() = 0;
};

class EofToken : public Token {
public:
    virtual bool _isPunctuation();
    virtual bool _isIdentifier();
    virtual bool _isOperator();
    virtual bool _isPrefixOperator();
    virtual bool _isBinaryOperator();
    virtual bool _isPostfixOperator();
    virtual bool _isLiteral();
};

class InvalidToken : public Token {
public:
    virtual bool _isPunctuation();
    virtual bool _isIdentifier();
    virtual bool _isOperator();
    virtual bool _isPrefixOperator();
    virtual bool _isBinaryOperator();
    virtual bool _isPostfixOperator();
    virtual bool _isLiteral();
};

class Identifier : public Token {
public:
    Identifier(String& name);
    String& name;

    virtual bool _isPunctuation();
    virtual bool _isIdentifier();
    virtual bool _isOperator();
    virtual bool _isPrefixOperator();
    virtual bool _isBinaryOperator();
    virtual bool _isPostfixOperator();
    virtual bool _isLiteral();
};

class Literal : public Token {
public:
    virtual bool _isPunctuation();
    virtual bool _isIdentifier();
    virtual bool _isOperator();
    virtual bool _isPrefixOperator();
    virtual bool _isBinaryOperator();
    virtual bool _isPostfixOperator();
    virtual bool _isLiteral();
};

class StringLiteral : public Literal {
public:
    StringLiteral(String& theString);
    String& string;
};

class NumericLiteral : public Literal {
public:
    NumericLiteral(String& theValue);
    String& value;
};

class Punctuation : public Token {
public:
    Punctuation(String& theSign);
    String& sign;
    
    virtual bool _isPunctuation();
    virtual bool _isIdentifier();
    virtual bool _isOperator();
    virtual bool _isPrefixOperator();
    virtual bool _isBinaryOperator();
    virtual bool _isPostfixOperator();
    virtual bool _isLiteral();
};

class Operator : public Token {
public:
    Operator(String& theOperation);
    String& operation;

    virtual bool _isPunctuation();
    virtual bool _isIdentifier();
    virtual bool _isOperator();
    virtual bool _isLiteral();
};

class PrefixOperator : public Operator {
public:
    PrefixOperator(String& theOperation);

    virtual bool _isPrefixOperator();
    virtual bool _isBinaryOperator();
    virtual bool _isPostfixOperator();
};

class BinaryOperator : public Operator {
public:
    BinaryOperator(String& theOperation);

    virtual bool _isPrefixOperator();
    virtual bool _isBinaryOperator();
    virtual bool _isPostfixOperator();
};

class PostfixOperator : public Operator {
public:
    PostfixOperator(String& theOperation);

    virtual bool _isPrefixOperator();
    virtual bool _isBinaryOperator();
    virtual bool _isPostfixOperator();
};

class Lexer : public Object {
public:
    Token* token;
    bool whitespaceSkipped;
    String& text;
    size_t length;
    size_t position;
    size_t end;
    size_t previousLine;
    size_t previousColumn;
    size_t line;
    size_t column;

    Lexer(String& text);
    void advance();
    Identifier& scanIdentifier(_Page* _rp);
    Operator& scanOperator(_Page* _rp, bool includeDots);
    NumericLiteral* scanNumericLiteral(_Page* _rp);
    Token* scanStringLiteral(_Page* _rp);
    bool parseKeyword(const char* fixedString);
    String* parseIdentifier(_Page* _rp);
    Literal* parseLiteral(_Page* _rp);
    String* parseOperator(_Page* _rp);
    String* parsePrefixOperator(_Page* _rp);
    String* parseBinaryOperator(_Page* _rp);
    String* parsePostfixOperator(_Page* _rp);
    bool skipWhitespace();
    bool parsePunctuation(const char* fixedString);
    bool isAtEnd();
    Position getPosition();
    Position getPreviousPosition();

    void handleSingleLineComment();
    void handleMultiLineComment();
};

}

#endif /* defined(__scalyc__Lexer__) */