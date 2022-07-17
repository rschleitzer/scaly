namespace scaly {
namespace compiler {
namespace model {

using namespace scaly::io;

struct Span : Object {
    size_t start;
    size_t end;
    Span(size_t start, size_t end) : start(start), end(end) {}
};

struct Operand;

struct Component : Object {
    Span span;
    String* name;
    Vector<Operand> value;
    Component(Span span, String* name, Vector<Operand> value) : span(span), name(name), value(value) {}
};

struct Name : Object {
    String path;
    Name(String path) : path(path) {}
};


struct Constant {
    enum {
        Boolean,
        Integer,
        Hex,
        FloatingPoint,
        String,
        Fragment,
    } _tag;
    union {
        bool _Boolean;
        size_t _Integer;
        size_t _Hex;
        double _FloatingPoint;
        struct String _String;
        struct String _Fragment;
    };
};

struct Tuple : Object {
    Span span;
    Vector<Component> components;
    Tuple(Span span, Vector<Component> components) : span(span), components(components) {}
};

struct Operation;

struct Matrix : Object {
    Span span;
    Vector<Operation> operations;
    Matrix(Span span, Vector<Operation> operations) : span(span), operations(operations) {}
};

struct Block {

};

struct Type : Object {
    String name;
    Type(String name) : name(name) {}
};

struct Property {
    String* name;
    Type* type;
    Property(String* name, Type* type) : name(name), type(type) {}
};

struct Operation : Object {
    Vector<Operand> operands;
    Operation(Vector<Operand> operands) : operands(operands) {}
};

struct Statement;

struct Binding {
    enum Mutability { Constant, Extendable, Mutable, } binding_type;
    Property property;
    Operation operation;
    Vector<Statement> body;
    Binding(Mutability binding_type, Property property, Operation operation, Vector<Statement> body)
      : binding_type(binding_type), property(property), operation(operation), body(body) {}
};

struct Mutation : Object {
    Operation source;
    Operation target;
    Mutation(Operation source, Operation target) : source(source), target(target) {}
};

struct Action {
    enum {
        Operation,
        Mutation,
    } _tag;
    union {
        struct Operation _Operation;
        struct Mutation _Mutation;
    };

};

struct If : Object {
    Span span;
    Vector<Operand> condition;
    Property* property;
    Action consequent;
    Action alternative;
    If(Span span, Vector<Operand> condition, Property* property, Action consequent, Action alternative) : span(span), condition(condition), property(property), consequent(consequent), alternative(alternative) {}
};

struct For : Object {
    Span span;
    String identifier;
    Vector<Operand> expression;
    Action action;
    For(Span span, String identifier, Vector<Operand> expression, Action action) : span(span), identifier(identifier), expression(expression), action(action) {}
};

struct SizeOf : Object {
    Span span;
    Type type;
    SizeOf(Span span, Type type) : span(span), type(type) {}
};

struct Return : Object {
    Span span;
    Vector<Operand> result;
    Return(Span span, Vector<Operand> result) : span(span), result(result) {}
};

struct Expression {
    enum {
        Constant,
        Variable,
        Tuple,
        Matrix,
        Block,
        If,
        For,
        SizeOf,
        Return,
    } _tag;
    union {
        struct Constant _Constant;
        struct String _Variable;
        struct Tuple _Tuple;
        struct Matrix _Matrix;
        struct Block _Block;
        struct If _If;
        struct For _For;
        struct SizeOf _SizeOf;
        struct Return _Return;
    };

};

struct Postfix {

};

struct Operand : Object {
    Span span;
    Expression expression;
    Vector<Postfix>* postfixes;
    Operand(Span span, Expression expression, Vector<Postfix>* postfixes) : span(span), expression(expression), postfixes(postfixes) {}
};

struct Statement {
    enum {
        Action,
        Binding,
    } _tag;
    union {
        struct Action _Action;
        struct Binding _Binding;
    };
};


struct Extern {};

struct Instruction {};

struct Intrinsic {};

struct Implementation {
    enum {
        Action,
        Extern,
        Instruction,
        Intrinsic,
    } _tag;
    union {
        struct Action _Action;
        struct Extern _Extern;
        struct Instruction _Instruction;
        struct Intrinsic _Intrinsic;
    };
};

struct Function : Object {
    Span span;
    bool private_;
    String name;
    Vector<Property>* input;
    Vector<Property>* output;
    Implementation implementation;
    Function(Span span, bool private_, String name, Vector<Property>* input, Vector<Property>* output, Implementation implementation)
      : span(span),
        private_(private_),
        name(name),
        input(input),
        output(output),
        implementation(implementation) {}
};

struct Initializer : Object {
    Span span;
    bool private_;
    Vector<Property>* input;
    Implementation implementation;
    Initializer(Span span, bool private_, Vector<Property>* input, Implementation implementation)
      : span(span),
        private_(private_),
        input(input),
        implementation(implementation) {}
};

struct DeInitializer : Object {
    Span span;
    Implementation implementation;
    DeInitializer(Span span, Implementation implementation)
      : span(span),
        implementation(implementation) {}
};
struct Operator : Object {
    Span span;
    bool private_;
    String name;
    Vector<Property>* output;
    Operation* operation;
    Operator(Span span, bool private_, String name, Vector<Property>* output, Operation* operation)
      : span(span),
        private_(private_),
        name(name),
        output(output),
        operation(operation) {}
};

struct Module;
struct Concept;
struct Nameable;

struct Code {
    HashMap<String, Nameable> symbols;
    Vector<Initializer>* initializers;
    DeInitializer* deinitializer;
    Code(HashMap<String, Nameable> symbols, Vector<Initializer>* initializers, DeInitializer* deinitializer)
      : symbols(symbols), initializers(initializers), deinitializer(deinitializer) {}
};

struct Structure{
    Span span;
    bool private_;
    HashMap<String, Property> properties;
    Code code;
    Structure(Span span, bool private_, HashMap<String, Property> properties, Code code)
      : span(span),
        private_(private_),
        properties(properties),
        code(code) {}
};

struct Union {

};

struct NameSpace {
    Code code;
    NameSpace(Code code)
      : code(code) {}
};

struct Body {
    enum {
        Intrinsic,
        Constant,
        NameSpace,
        Structure,
        Union,
    } _tag;
    union {
        struct Intrinsic _Intrinsic;
        Operation _Constant;
        struct NameSpace _NameSpace;
        struct Structure _Structure;
        struct Union _Union;
    };
};

struct Concept : Object {
    Span span;
    String name;
    Body body;
    Concept(Span span, String name, Body body)
      : span(span),
        name(name),
        body(body) {}
};

struct Text {
    enum {
        Program,
        File,
    } _tag;
    union {
        String _Program;
        String _File;
    };
};

struct Module : Object {
    bool private_;
    String name;
    Text text;
    Concept concept;
    Module(bool private_, String name, Text text, Concept concept)
      : private_(private_),
        name(name),
        text(text),
        concept(concept) {}
};

struct Nameable {
    enum {
        Module,
        Concept,
        Operator,
        Functions,
    } _tag;
    union {
        struct Module _Module;
        struct Concept _Concept;
        struct Operator _Operator;
        Vector<Function> _Functions;
    };
};

}
}
}