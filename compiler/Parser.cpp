namespace scaly {
namespace compiler {

struct IdentifierLiteral {
    IdentifierLiteral(String name) : name(name) {}
    String name;
};

struct StringLiteral {
    StringLiteral(String value) : value(value) {}
    String value;
};

struct FragmentLiteral {
    FragmentLiteral(String value) : value(value) {}
    String value;
};

struct IntegerLiteral {
    IntegerLiteral(String value) : value(value) {}
    String value;
};

struct BooleanLiteral {
    BooleanLiteral(bool value) : value(value) {}
    bool value;
};

struct FloatingPointLiteral {
    FloatingPointLiteral(String value) : value(value) {}
    String value;
};

struct HexLiteral {
    HexLiteral(String value) : value(value) {}
    String value;
};

struct Literal : Object {
    Literal(StringLiteral string) : _tag(String), _String(string) {}
    Literal(FragmentLiteral fragment) : _tag(Fragment), _Fragment(fragment) {}
    Literal(IntegerLiteral integer) : _tag(Integer), _Integer(integer) {}
    Literal(BooleanLiteral boolean) : _tag(Boolean), _Boolean(boolean) {}
    Literal(FloatingPointLiteral floating_point) : _tag(FloatingPoint), _FloatingPoint(floating_point) {}
    Literal(HexLiteral hex) : _tag(Hex), _Hex(hex) {}
    enum {
        String,
        Fragment,
        Integer,
        Boolean,
        FloatingPoint,
        Hex,
    } _tag;
    union {
        StringLiteral _String;
        FragmentLiteral _Fragment;
        IntegerLiteral _Integer;
        BooleanLiteral _Boolean;
        FloatingPointLiteral _FloatingPoint;
        HexLiteral _Hex;

    };
};

struct FileSyntax; 
struct DeclarationSyntax; 
struct PrivateSyntax; 
struct ExportSyntax; 
struct DefinitionSyntax; 
struct ExtensionSyntax; 
struct AttributeSyntax; 
struct ConceptSyntax; 
struct ClassSyntax; 
struct NamespaceSyntax; 
struct UnionSyntax; 
struct TagSyntax; 
struct ItemSyntax; 
struct VariantSyntax; 
struct EnumSyntax; 
struct ConstantSyntax; 
struct DelegateSyntax; 
struct BodySyntax; 
struct MemberSyntax; 
struct FieldSyntax; 
struct PropertySyntax; 
struct TypeAnnotationSyntax; 
struct GenericArgumentsSyntax; 
struct GenericArgumentSyntax; 
struct OptionalSyntax; 
struct ReturnsSyntax; 
struct ParameterSetSyntax; 
struct ParametersSyntax; 
struct ThrowsSyntax; 
struct UseSyntax; 
struct ImplementSyntax; 
struct TraitSyntax; 
struct MethodSyntax; 
struct FunctionSyntax; 
struct ProcedureSyntax; 
struct OperatorSyntax; 
struct TargetSyntax; 
struct RoutineSyntax; 
struct SymbolSyntax; 
struct ImplementationSyntax; 
struct ExternSyntax; 
struct InstructionSyntax; 
struct IntrinsicSyntax; 
struct ExtendsSyntax; 
struct ExtendSyntax; 
struct MacroSyntax; 
struct ModuleSyntax; 
struct ModelSyntax; 
struct StatementSyntax; 
struct LetSyntax; 
struct VarSyntax; 
struct MutableSyntax; 
struct BindingSyntax; 
struct BindingAnnotationSyntax; 
struct BindingSpecSyntax; 
struct ArraySyntax; 
struct StructureSyntax; 
struct OperandSyntax; 
struct PostfixSyntax; 
struct MemberAccessSyntax; 
struct CatcherSyntax; 
struct CatchSyntax; 
struct DropSyntax; 
struct ExpressionSyntax; 
struct ContinueSyntax; 
struct BreakSyntax; 
struct LoopSyntax; 
struct ReturnSyntax; 
struct ThrowSyntax; 
struct LiteralSyntax; 
struct ObjectSyntax; 
struct ComponentSyntax; 
struct ValueSyntax; 
struct VectorSyntax; 
struct ElementSyntax; 
struct BlockSyntax; 
struct IfSyntax; 
struct IsSyntax; 
struct AsSyntax; 
struct ElseSyntax; 
struct MatchSyntax; 
struct CaseSyntax; 
struct DefaultSyntax; 
struct LambdaSyntax; 
struct ForSyntax; 
struct LabelSyntax; 
struct WhileSyntax; 
struct RepeatSyntax; 
struct ActionSyntax; 
struct SetSyntax; 
struct OperationSyntax; 
struct SizeOfSyntax; 
struct TypeSyntax; 
struct NameSyntax; 

struct NameSyntax : Object {
    NameSyntax(size_t start, size_t end, String name, Vector<ExtensionSyntax>* extensions) : start(start), end(end), name(name), extensions(extensions) {}
    size_t start;
    size_t end;
    String name;
    Vector<ExtensionSyntax>* extensions;
};

struct TypeSyntax : Object {
    TypeSyntax(size_t start, size_t end, NameSyntax name, GenericArgumentsSyntax* generics, OptionalSyntax* optional) : start(start), end(end), name(name), generics(generics), optional(optional) {}
    size_t start;
    size_t end;
    NameSyntax name;
    GenericArgumentsSyntax* generics;
    OptionalSyntax* optional;
};

struct SizeOfSyntax : Object {
    SizeOfSyntax(size_t start, size_t end, TypeSyntax type) : start(start), end(end), type(type) {}
    size_t start;
    size_t end;
    TypeSyntax type;
};

struct OperationSyntax : Object {
    OperationSyntax(size_t start, size_t end, Vector<OperandSyntax>* operands) : start(start), end(end), operands(operands) {}
    size_t start;
    size_t end;
    Vector<OperandSyntax>* operands;
};

struct SetSyntax : Object {
    SetSyntax(size_t start, size_t end, OperationSyntax target, OperationSyntax source) : start(start), end(end), target(target), source(source) {}
    size_t start;
    size_t end;
    OperationSyntax target;
    OperationSyntax source;
};

struct ActionSyntax : Object {
    ActionSyntax(OperationSyntax _OperationSyntax) : _tag(Operation) { _Operation = _OperationSyntax; }
    ActionSyntax(SetSyntax _SetSyntax) : _tag(Set) { _Set = _SetSyntax; }
    enum {
        Operation,
        Set,
    } _tag;
    union {
        OperationSyntax _Operation;
        SetSyntax _Set;
    };
};

struct RepeatSyntax : Object {
    RepeatSyntax(size_t start, size_t end, LabelSyntax* name, ActionSyntax action) : start(start), end(end), name(name), action(action) {}
    size_t start;
    size_t end;
    LabelSyntax* name;
    ActionSyntax action;
};

struct WhileSyntax : Object {
    WhileSyntax(size_t start, size_t end, OperationSyntax condition, LabelSyntax* name, ActionSyntax action) : start(start), end(end), condition(condition), name(name), action(action) {}
    size_t start;
    size_t end;
    OperationSyntax condition;
    LabelSyntax* name;
    ActionSyntax action;
};

struct LabelSyntax : Object {
    LabelSyntax(size_t start, size_t end, String name) : start(start), end(end), name(name) {}
    size_t start;
    size_t end;
    String name;
};

struct ForSyntax : Object {
    ForSyntax(size_t start, size_t end, OperationSyntax condition, OperationSyntax expression, LabelSyntax* name, ActionSyntax action) : start(start), end(end), condition(condition), expression(expression), name(name), action(action) {}
    size_t start;
    size_t end;
    OperationSyntax condition;
    OperationSyntax expression;
    LabelSyntax* name;
    ActionSyntax action;
};

struct LambdaSyntax : Object {
    LambdaSyntax(size_t start, size_t end, OperationSyntax input, ActionSyntax block) : start(start), end(end), input(input), block(block) {}
    size_t start;
    size_t end;
    OperationSyntax input;
    ActionSyntax block;
};

struct DefaultSyntax : Object {
    DefaultSyntax(size_t start, size_t end, ActionSyntax* alternative) : start(start), end(end), alternative(alternative) {}
    size_t start;
    size_t end;
    ActionSyntax* alternative;
};

struct CaseSyntax : Object {
    CaseSyntax(size_t start, size_t end, OperationSyntax condition, ActionSyntax consequent) : start(start), end(end), condition(condition), consequent(consequent) {}
    size_t start;
    size_t end;
    OperationSyntax condition;
    ActionSyntax consequent;
};

struct MatchSyntax : Object {
    MatchSyntax(size_t start, size_t end, OperationSyntax scrutinee, Vector<CaseSyntax>* cases, DefaultSyntax* alternative) : start(start), end(end), scrutinee(scrutinee), cases(cases), alternative(alternative) {}
    size_t start;
    size_t end;
    OperationSyntax scrutinee;
    Vector<CaseSyntax>* cases;
    DefaultSyntax* alternative;
};

struct ElseSyntax : Object {
    ElseSyntax(size_t start, size_t end, ActionSyntax alternative) : start(start), end(end), alternative(alternative) {}
    size_t start;
    size_t end;
    ActionSyntax alternative;
};

struct AsSyntax : Object {
    AsSyntax(size_t start, size_t end, String name) : start(start), end(end), name(name) {}
    size_t start;
    size_t end;
    String name;
};

struct IsSyntax : Object {
    IsSyntax(size_t start, size_t end, TypeSyntax type) : start(start), end(end), type(type) {}
    size_t start;
    size_t end;
    TypeSyntax type;
};

struct IfSyntax : Object {
    IfSyntax(size_t start, size_t end, OperationSyntax condition, IsSyntax* match, AsSyntax* alias, ActionSyntax consequent, ElseSyntax* alternative) : start(start), end(end), condition(condition), match(match), alias(alias), consequent(consequent), alternative(alternative) {}
    size_t start;
    size_t end;
    OperationSyntax condition;
    IsSyntax* match;
    AsSyntax* alias;
    ActionSyntax consequent;
    ElseSyntax* alternative;
};

struct BlockSyntax : Object {
    BlockSyntax(size_t start, size_t end, Vector<UseSyntax>* uses, Vector<StatementSyntax>* statements) : start(start), end(end), uses(uses), statements(statements) {}
    size_t start;
    size_t end;
    Vector<UseSyntax>* uses;
    Vector<StatementSyntax>* statements;
};

struct ElementSyntax : Object {
    ElementSyntax(size_t start, size_t end, OperationSyntax operation, Vector<AttributeSyntax>* attributes) : start(start), end(end), operation(operation), attributes(attributes) {}
    size_t start;
    size_t end;
    OperationSyntax operation;
    Vector<AttributeSyntax>* attributes;
};

struct VectorSyntax : Object {
    VectorSyntax(size_t start, size_t end, Vector<ElementSyntax>* elements) : start(start), end(end), elements(elements) {}
    size_t start;
    size_t end;
    Vector<ElementSyntax>* elements;
};

struct ValueSyntax : Object {
    ValueSyntax(size_t start, size_t end, OperationSyntax value, Vector<AttributeSyntax>* attributes) : start(start), end(end), value(value), attributes(attributes) {}
    size_t start;
    size_t end;
    OperationSyntax value;
    Vector<AttributeSyntax>* attributes;
};

struct ComponentSyntax : Object {
    ComponentSyntax(size_t start, size_t end, Vector<OperandSyntax>* operands, Vector<AttributeSyntax>* attributes, ValueSyntax* value) : start(start), end(end), operands(operands), attributes(attributes), value(value) {}
    size_t start;
    size_t end;
    Vector<OperandSyntax>* operands;
    Vector<AttributeSyntax>* attributes;
    ValueSyntax* value;
};

struct ObjectSyntax : Object {
    ObjectSyntax(size_t start, size_t end, Vector<ComponentSyntax>* components) : start(start), end(end), components(components) {}
    size_t start;
    size_t end;
    Vector<ComponentSyntax>* components;
};

struct LiteralSyntax : Object {
    LiteralSyntax(size_t start, size_t end, Literal literal) : start(start), end(end), literal(literal) {}
    size_t start;
    size_t end;
    Literal literal;
};

struct ThrowSyntax : Object {
    ThrowSyntax(size_t start, size_t end, OperationSyntax* result) : start(start), end(end), result(result) {}
    size_t start;
    size_t end;
    OperationSyntax* result;
};

struct ReturnSyntax : Object {
    ReturnSyntax(size_t start, size_t end, OperationSyntax* result) : start(start), end(end), result(result) {}
    size_t start;
    size_t end;
    OperationSyntax* result;
};

struct LoopSyntax : Object {
    LoopSyntax(size_t start, size_t end, String name) : start(start), end(end), name(name) {}
    size_t start;
    size_t end;
    String name;
};

struct BreakSyntax : Object {
    BreakSyntax(size_t start, size_t end, LoopSyntax* name, OperationSyntax* result) : start(start), end(end), name(name), result(result) {}
    size_t start;
    size_t end;
    LoopSyntax* name;
    OperationSyntax* result;
};

struct ContinueSyntax : Object {
    ContinueSyntax(size_t start, size_t end, LoopSyntax* name) : start(start), end(end), name(name) {}
    size_t start;
    size_t end;
    LoopSyntax* name;
};

struct ExpressionSyntax : Object {
    ExpressionSyntax(LiteralSyntax _LiteralSyntax) : _tag(Literal) { _Literal = _LiteralSyntax; }
    ExpressionSyntax(NameSyntax _NameSyntax) : _tag(Name) { _Name = _NameSyntax; }
    ExpressionSyntax(ObjectSyntax _ObjectSyntax) : _tag(Object) { _Object = _ObjectSyntax; }
    ExpressionSyntax(VectorSyntax _VectorSyntax) : _tag(Vector) { _Vector = _VectorSyntax; }
    ExpressionSyntax(BlockSyntax _BlockSyntax) : _tag(Block) { _Block = _BlockSyntax; }
    ExpressionSyntax(IfSyntax _IfSyntax) : _tag(If) { _If = _IfSyntax; }
    ExpressionSyntax(MatchSyntax _MatchSyntax) : _tag(Match) { _Match = _MatchSyntax; }
    ExpressionSyntax(LambdaSyntax _LambdaSyntax) : _tag(Lambda) { _Lambda = _LambdaSyntax; }
    ExpressionSyntax(ForSyntax _ForSyntax) : _tag(For) { _For = _ForSyntax; }
    ExpressionSyntax(WhileSyntax _WhileSyntax) : _tag(While) { _While = _WhileSyntax; }
    ExpressionSyntax(RepeatSyntax _RepeatSyntax) : _tag(Repeat) { _Repeat = _RepeatSyntax; }
    ExpressionSyntax(SizeOfSyntax _SizeOfSyntax) : _tag(SizeOf) { _SizeOf = _SizeOfSyntax; }
    ExpressionSyntax(ContinueSyntax _ContinueSyntax) : _tag(Continue) { _Continue = _ContinueSyntax; }
    ExpressionSyntax(BreakSyntax _BreakSyntax) : _tag(Break) { _Break = _BreakSyntax; }
    ExpressionSyntax(ReturnSyntax _ReturnSyntax) : _tag(Return) { _Return = _ReturnSyntax; }
    ExpressionSyntax(ThrowSyntax _ThrowSyntax) : _tag(Throw) { _Throw = _ThrowSyntax; }
    enum {
        Literal,
        Name,
        Object,
        Vector,
        Block,
        If,
        Match,
        Lambda,
        For,
        While,
        Repeat,
        SizeOf,
        Continue,
        Break,
        Return,
        Throw,
    } _tag;
    union {
        LiteralSyntax _Literal;
        NameSyntax _Name;
        ObjectSyntax _Object;
        VectorSyntax _Vector;
        BlockSyntax _Block;
        IfSyntax _If;
        MatchSyntax _Match;
        LambdaSyntax _Lambda;
        ForSyntax _For;
        WhileSyntax _While;
        RepeatSyntax _Repeat;
        SizeOfSyntax _SizeOf;
        ContinueSyntax _Continue;
        BreakSyntax _Break;
        ReturnSyntax _Return;
        ThrowSyntax _Throw;
    };
};

struct DropSyntax : Object {
    DropSyntax(size_t start, size_t end, OperationSyntax handler) : start(start), end(end), handler(handler) {}
    size_t start;
    size_t end;
    OperationSyntax handler;
};

struct CatchSyntax : Object {
    CatchSyntax(size_t start, size_t end, OperationSyntax condition, OperationSyntax handler) : start(start), end(end), condition(condition), handler(handler) {}
    size_t start;
    size_t end;
    OperationSyntax condition;
    OperationSyntax handler;
};

struct CatcherSyntax : Object {
    CatcherSyntax(size_t start, size_t end, Vector<CatchSyntax>* catchers, DropSyntax* dropper) : start(start), end(end), catchers(catchers), dropper(dropper) {}
    size_t start;
    size_t end;
    Vector<CatchSyntax>* catchers;
    DropSyntax* dropper;
};

struct MemberAccessSyntax : Object {
    MemberAccessSyntax(size_t start, size_t end, NameSyntax member) : start(start), end(end), member(member) {}
    size_t start;
    size_t end;
    NameSyntax member;
};

struct PostfixSyntax : Object {
    PostfixSyntax(MemberAccessSyntax _MemberAccessSyntax) : _tag(MemberAccess) { _MemberAccess = _MemberAccessSyntax; }
    PostfixSyntax(CatcherSyntax _CatcherSyntax) : _tag(Catcher) { _Catcher = _CatcherSyntax; }
    enum {
        MemberAccess,
        Catcher,
    } _tag;
    union {
        MemberAccessSyntax _MemberAccess;
        CatcherSyntax _Catcher;
    };
};

struct OperandSyntax : Object {
    OperandSyntax(size_t start, size_t end, ExpressionSyntax expression, Vector<PostfixSyntax>* postfixes) : start(start), end(end), expression(expression), postfixes(postfixes) {}
    size_t start;
    size_t end;
    ExpressionSyntax expression;
    Vector<PostfixSyntax>* postfixes;
};

struct StructureSyntax : Object {
    StructureSyntax(size_t start, size_t end, Vector<MemberSyntax>* members) : start(start), end(end), members(members) {}
    size_t start;
    size_t end;
    Vector<MemberSyntax>* members;
};

struct ArraySyntax : Object {
    ArraySyntax(size_t start, size_t end, Vector<TypeSyntax>* members) : start(start), end(end), members(members) {}
    size_t start;
    size_t end;
    Vector<TypeSyntax>* members;
};

struct BindingSpecSyntax : Object {
    BindingSpecSyntax(StructureSyntax _StructureSyntax) : _tag(Structure) { _Structure = _StructureSyntax; }
    BindingSpecSyntax(TypeSyntax _TypeSyntax) : _tag(Type) { _Type = _TypeSyntax; }
    BindingSpecSyntax(ArraySyntax _ArraySyntax) : _tag(Array) { _Array = _ArraySyntax; }
    enum {
        Structure,
        Type,
        Array,
    } _tag;
    union {
        StructureSyntax _Structure;
        TypeSyntax _Type;
        ArraySyntax _Array;
    };
};

struct BindingAnnotationSyntax : Object {
    BindingAnnotationSyntax(size_t start, size_t end, BindingSpecSyntax spec) : start(start), end(end), spec(spec) {}
    size_t start;
    size_t end;
    BindingSpecSyntax spec;
};

struct BindingSyntax : Object {
    BindingSyntax(size_t start, size_t end, String name, BindingAnnotationSyntax* annotation, OperationSyntax operation) : start(start), end(end), name(name), annotation(annotation), operation(operation) {}
    size_t start;
    size_t end;
    String name;
    BindingAnnotationSyntax* annotation;
    OperationSyntax operation;
};

struct MutableSyntax : Object {
    MutableSyntax(size_t start, size_t end, BindingSyntax binding) : start(start), end(end), binding(binding) {}
    size_t start;
    size_t end;
    BindingSyntax binding;
};

struct VarSyntax : Object {
    VarSyntax(size_t start, size_t end, BindingSyntax binding) : start(start), end(end), binding(binding) {}
    size_t start;
    size_t end;
    BindingSyntax binding;
};

struct LetSyntax : Object {
    LetSyntax(size_t start, size_t end, BindingSyntax binding) : start(start), end(end), binding(binding) {}
    size_t start;
    size_t end;
    BindingSyntax binding;
};

struct StatementSyntax : Object {
    StatementSyntax(OperationSyntax _OperationSyntax) : _tag(Operation) { _Operation = _OperationSyntax; }
    StatementSyntax(LetSyntax _LetSyntax) : _tag(Let) { _Let = _LetSyntax; }
    StatementSyntax(VarSyntax _VarSyntax) : _tag(Var) { _Var = _VarSyntax; }
    StatementSyntax(MutableSyntax _MutableSyntax) : _tag(Mutable) { _Mutable = _MutableSyntax; }
    StatementSyntax(SetSyntax _SetSyntax) : _tag(Set) { _Set = _SetSyntax; }
    enum {
        Operation,
        Let,
        Var,
        Mutable,
        Set,
    } _tag;
    union {
        OperationSyntax _Operation;
        LetSyntax _Let;
        VarSyntax _Var;
        MutableSyntax _Mutable;
        SetSyntax _Set;
    };
};

struct ModelSyntax : Object {
    ModelSyntax(LiteralSyntax _LiteralSyntax) : _tag(Literal) { _Literal = _LiteralSyntax; }
    ModelSyntax(NameSyntax _NameSyntax) : _tag(Name) { _Name = _NameSyntax; }
    ModelSyntax(ObjectSyntax _ObjectSyntax) : _tag(Object) { _Object = _ObjectSyntax; }
    ModelSyntax(VectorSyntax _VectorSyntax) : _tag(Vector) { _Vector = _VectorSyntax; }
    enum {
        Literal,
        Name,
        Object,
        Vector,
    } _tag;
    union {
        LiteralSyntax _Literal;
        NameSyntax _Name;
        ObjectSyntax _Object;
        VectorSyntax _Vector;
    };
};

struct ModuleSyntax : Object {
    ModuleSyntax(size_t start, size_t end, NameSyntax name) : start(start), end(end), name(name) {}
    size_t start;
    size_t end;
    NameSyntax name;
};

struct MacroSyntax : Object {
    MacroSyntax(size_t start, size_t end, String name, ModelSyntax model, OperationSyntax rule) : start(start), end(end), name(name), model(model), rule(rule) {}
    size_t start;
    size_t end;
    String name;
    ModelSyntax model;
    OperationSyntax rule;
};

struct ExtendSyntax : Object {
    ExtendSyntax(size_t start, size_t end, TypeSyntax type) : start(start), end(end), type(type) {}
    size_t start;
    size_t end;
    TypeSyntax type;
};

struct ExtendsSyntax : Object {
    ExtendsSyntax(size_t start, size_t end, Vector<ExtendSyntax>* extensions) : start(start), end(end), extensions(extensions) {}
    size_t start;
    size_t end;
    Vector<ExtendSyntax>* extensions;
};

struct IntrinsicSyntax : Object {
    IntrinsicSyntax(size_t start, size_t end) : start(start), end(end) {}
    size_t start;
    size_t end;
};

struct InstructionSyntax : Object {
    InstructionSyntax(size_t start, size_t end) : start(start), end(end) {}
    size_t start;
    size_t end;
};

struct ExternSyntax : Object {
    ExternSyntax(size_t start, size_t end) : start(start), end(end) {}
    size_t start;
    size_t end;
};

struct ImplementationSyntax : Object {
    ImplementationSyntax(ActionSyntax _ActionSyntax) : _tag(Action) { _Action = _ActionSyntax; }
    ImplementationSyntax(ExternSyntax _ExternSyntax) : _tag(Extern) { _Extern = _ExternSyntax; }
    ImplementationSyntax(InstructionSyntax _InstructionSyntax) : _tag(Instruction) { _Instruction = _InstructionSyntax; }
    ImplementationSyntax(IntrinsicSyntax _IntrinsicSyntax) : _tag(Intrinsic) { _Intrinsic = _IntrinsicSyntax; }
    enum {
        Action,
        Extern,
        Instruction,
        Intrinsic,
    } _tag;
    union {
        ActionSyntax _Action;
        ExternSyntax _Extern;
        InstructionSyntax _Instruction;
        IntrinsicSyntax _Intrinsic;
    };
};

struct SymbolSyntax : Object {
    SymbolSyntax(size_t start, size_t end, String name, Vector<AttributeSyntax>* attributes, ReturnsSyntax* returns, ThrowsSyntax* throws, ImplementationSyntax implementation) : start(start), end(end), name(name), attributes(attributes), returns(returns), throws(throws), implementation(implementation) {}
    size_t start;
    size_t end;
    String name;
    Vector<AttributeSyntax>* attributes;
    ReturnsSyntax* returns;
    ThrowsSyntax* throws;
    ImplementationSyntax implementation;
};

struct RoutineSyntax : Object {
    RoutineSyntax(size_t start, size_t end, ParameterSetSyntax* parameters, Vector<AttributeSyntax>* attributes, ReturnsSyntax* returns, ThrowsSyntax* throws, ImplementationSyntax implementation) : start(start), end(end), parameters(parameters), attributes(attributes), returns(returns), throws(throws), implementation(implementation) {}
    size_t start;
    size_t end;
    ParameterSetSyntax* parameters;
    Vector<AttributeSyntax>* attributes;
    ReturnsSyntax* returns;
    ThrowsSyntax* throws;
    ImplementationSyntax implementation;
};

struct TargetSyntax : Object {
    TargetSyntax(SymbolSyntax _SymbolSyntax) : _tag(Symbol) { _Symbol = _SymbolSyntax; }
    TargetSyntax(RoutineSyntax _RoutineSyntax) : _tag(Routine) { _Routine = _RoutineSyntax; }
    enum {
        Symbol,
        Routine,
    } _tag;
    union {
        SymbolSyntax _Symbol;
        RoutineSyntax _Routine;
    };
};

struct OperatorSyntax : Object {
    OperatorSyntax(size_t start, size_t end, TargetSyntax target) : start(start), end(end), target(target) {}
    size_t start;
    size_t end;
    TargetSyntax target;
};

struct ProcedureSyntax : Object {
    ProcedureSyntax(size_t start, size_t end, String name, GenericArgumentsSyntax* generics, RoutineSyntax routine) : start(start), end(end), name(name), generics(generics), routine(routine) {}
    size_t start;
    size_t end;
    String name;
    GenericArgumentsSyntax* generics;
    RoutineSyntax routine;
};

struct FunctionSyntax : Object {
    FunctionSyntax(size_t start, size_t end, String name, GenericArgumentsSyntax* generics, RoutineSyntax routine) : start(start), end(end), name(name), generics(generics), routine(routine) {}
    size_t start;
    size_t end;
    String name;
    GenericArgumentsSyntax* generics;
    RoutineSyntax routine;
};

struct MethodSyntax : Object {
    MethodSyntax(FunctionSyntax _FunctionSyntax) : _tag(Function) { _Function = _FunctionSyntax; }
    MethodSyntax(ProcedureSyntax _ProcedureSyntax) : _tag(Procedure) { _Procedure = _ProcedureSyntax; }
    MethodSyntax(OperatorSyntax _OperatorSyntax) : _tag(Operator) { _Operator = _OperatorSyntax; }
    enum {
        Function,
        Procedure,
        Operator,
    } _tag;
    union {
        FunctionSyntax _Function;
        ProcedureSyntax _Procedure;
        OperatorSyntax _Operator;
    };
};

struct TraitSyntax : Object {
    TraitSyntax(size_t start, size_t end, NameSyntax name, ExtendsSyntax* extension, Vector<AttributeSyntax>* attributes, Vector<UseSyntax>* uses, Vector<MethodSyntax>* functions) : start(start), end(end), name(name), extension(extension), attributes(attributes), uses(uses), functions(functions) {}
    size_t start;
    size_t end;
    NameSyntax name;
    ExtendsSyntax* extension;
    Vector<AttributeSyntax>* attributes;
    Vector<UseSyntax>* uses;
    Vector<MethodSyntax>* functions;
};

struct ImplementSyntax : Object {
    ImplementSyntax(size_t start, size_t end, TypeSyntax type, Vector<AttributeSyntax>* attributes, Vector<UseSyntax>* uses, Vector<MethodSyntax>* methods) : start(start), end(end), type(type), attributes(attributes), uses(uses), methods(methods) {}
    size_t start;
    size_t end;
    TypeSyntax type;
    Vector<AttributeSyntax>* attributes;
    Vector<UseSyntax>* uses;
    Vector<MethodSyntax>* methods;
};

struct UseSyntax : Object {
    UseSyntax(size_t start, size_t end, NameSyntax name) : start(start), end(end), name(name) {}
    size_t start;
    size_t end;
    NameSyntax name;
};

struct ThrowsSyntax : Object {
    ThrowsSyntax(size_t start, size_t end, TypeSyntax type, Vector<AttributeSyntax>* attributes) : start(start), end(end), type(type), attributes(attributes) {}
    size_t start;
    size_t end;
    TypeSyntax type;
    Vector<AttributeSyntax>* attributes;
};

struct ParametersSyntax : Object {
    ParametersSyntax(size_t start, size_t end, Vector<PropertySyntax>* properties) : start(start), end(end), properties(properties) {}
    size_t start;
    size_t end;
    Vector<PropertySyntax>* properties;
};

struct ParameterSetSyntax : Object {
    ParameterSetSyntax(ParametersSyntax _ParametersSyntax) : _tag(Parameters) { _Parameters = _ParametersSyntax; }
    ParameterSetSyntax(TypeSyntax _TypeSyntax) : _tag(Type) { _Type = _TypeSyntax; }
    enum {
        Parameters,
        Type,
    } _tag;
    union {
        ParametersSyntax _Parameters;
        TypeSyntax _Type;
    };
};

struct ReturnsSyntax : Object {
    ReturnsSyntax(size_t start, size_t end, ParameterSetSyntax parameters, Vector<AttributeSyntax>* attributes) : start(start), end(end), parameters(parameters), attributes(attributes) {}
    size_t start;
    size_t end;
    ParameterSetSyntax parameters;
    Vector<AttributeSyntax>* attributes;
};

struct OptionalSyntax : Object {
    OptionalSyntax(size_t start, size_t end) : start(start), end(end) {}
    size_t start;
    size_t end;
};

struct GenericArgumentSyntax : Object {
    GenericArgumentSyntax(size_t start, size_t end, TypeSyntax type) : start(start), end(end), type(type) {}
    size_t start;
    size_t end;
    TypeSyntax type;
};

struct GenericArgumentsSyntax : Object {
    GenericArgumentsSyntax(size_t start, size_t end, Vector<GenericArgumentSyntax>* generics) : start(start), end(end), generics(generics) {}
    size_t start;
    size_t end;
    Vector<GenericArgumentSyntax>* generics;
};

struct TypeAnnotationSyntax : Object {
    TypeAnnotationSyntax(size_t start, size_t end, TypeSyntax type) : start(start), end(end), type(type) {}
    size_t start;
    size_t end;
    TypeSyntax type;
};

struct PropertySyntax : Object {
    PropertySyntax(size_t start, size_t end, String name, TypeAnnotationSyntax* annotation, Vector<AttributeSyntax>* attributes) : start(start), end(end), name(name), annotation(annotation), attributes(attributes) {}
    size_t start;
    size_t end;
    String name;
    TypeAnnotationSyntax* annotation;
    Vector<AttributeSyntax>* attributes;
};

struct FieldSyntax : Object {
    FieldSyntax(size_t start, size_t end, PropertySyntax property) : start(start), end(end), property(property) {}
    size_t start;
    size_t end;
    PropertySyntax property;
};

struct MemberSyntax : Object {
    MemberSyntax(FieldSyntax _FieldSyntax) : _tag(Field) { _Field = _FieldSyntax; }
    MemberSyntax(PropertySyntax _PropertySyntax) : _tag(Property) { _Property = _PropertySyntax; }
    enum {
        Field,
        Property,
    } _tag;
    union {
        FieldSyntax _Field;
        PropertySyntax _Property;
    };
};

struct BodySyntax : Object {
    BodySyntax(size_t start, size_t end, Vector<UseSyntax>* uses, Vector<DeclarationSyntax>* declarations) : start(start), end(end), uses(uses), declarations(declarations) {}
    size_t start;
    size_t end;
    Vector<UseSyntax>* uses;
    Vector<DeclarationSyntax>* declarations;
};

struct DelegateSyntax : Object {
    DelegateSyntax(size_t start, size_t end, ParameterSetSyntax* parameters, Vector<AttributeSyntax>* attributes, ReturnsSyntax* result, ThrowsSyntax* error) : start(start), end(end), parameters(parameters), attributes(attributes), result(result), error(error) {}
    size_t start;
    size_t end;
    ParameterSetSyntax* parameters;
    Vector<AttributeSyntax>* attributes;
    ReturnsSyntax* result;
    ThrowsSyntax* error;
};

struct ConstantSyntax : Object {
    ConstantSyntax(size_t start, size_t end, OperationSyntax operation) : start(start), end(end), operation(operation) {}
    size_t start;
    size_t end;
    OperationSyntax operation;
};

struct EnumSyntax : Object {
    EnumSyntax(size_t start, size_t end, Literal literal) : start(start), end(end), literal(literal) {}
    size_t start;
    size_t end;
    Literal literal;
};

struct VariantSyntax : Object {
    VariantSyntax(size_t start, size_t end, StructureSyntax structure, BodySyntax* body) : start(start), end(end), structure(structure), body(body) {}
    size_t start;
    size_t end;
    StructureSyntax structure;
    BodySyntax* body;
};

struct ItemSyntax : Object {
    ItemSyntax(VariantSyntax _VariantSyntax) : _tag(Variant) { _Variant = _VariantSyntax; }
    ItemSyntax(EnumSyntax _EnumSyntax) : _tag(Enum) { _Enum = _EnumSyntax; }
    enum {
        Variant,
        Enum,
    } _tag;
    union {
        VariantSyntax _Variant;
        EnumSyntax _Enum;
    };
};

struct TagSyntax : Object {
    TagSyntax(size_t start, size_t end, String name, Vector<AttributeSyntax>* attributes, ItemSyntax* item) : start(start), end(end), name(name), attributes(attributes), item(item) {}
    size_t start;
    size_t end;
    String name;
    Vector<AttributeSyntax>* attributes;
    ItemSyntax* item;
};

struct UnionSyntax : Object {
    UnionSyntax(size_t start, size_t end, Vector<TagSyntax>* tags, BodySyntax body) : start(start), end(end), tags(tags), body(body) {}
    size_t start;
    size_t end;
    Vector<TagSyntax>* tags;
    BodySyntax body;
};

struct NamespaceSyntax : Object {
    NamespaceSyntax(size_t start, size_t end, BodySyntax body) : start(start), end(end), body(body) {}
    size_t start;
    size_t end;
    BodySyntax body;
};

struct ClassSyntax : Object {
    ClassSyntax(size_t start, size_t end, StructureSyntax structure, BodySyntax* body) : start(start), end(end), structure(structure), body(body) {}
    size_t start;
    size_t end;
    StructureSyntax structure;
    BodySyntax* body;
};

struct ConceptSyntax : Object {
    ConceptSyntax(ClassSyntax _ClassSyntax) : _tag(Class) { _Class = _ClassSyntax; }
    ConceptSyntax(NamespaceSyntax _NamespaceSyntax) : _tag(Namespace) { _Namespace = _NamespaceSyntax; }
    ConceptSyntax(UnionSyntax _UnionSyntax) : _tag(Union) { _Union = _UnionSyntax; }
    ConceptSyntax(ConstantSyntax _ConstantSyntax) : _tag(Constant) { _Constant = _ConstantSyntax; }
    ConceptSyntax(DelegateSyntax _DelegateSyntax) : _tag(Delegate) { _Delegate = _DelegateSyntax; }
    ConceptSyntax(IntrinsicSyntax _IntrinsicSyntax) : _tag(Intrinsic) { _Intrinsic = _IntrinsicSyntax; }
    enum {
        Class,
        Namespace,
        Union,
        Constant,
        Delegate,
        Intrinsic,
    } _tag;
    union {
        ClassSyntax _Class;
        NamespaceSyntax _Namespace;
        UnionSyntax _Union;
        ConstantSyntax _Constant;
        DelegateSyntax _Delegate;
        IntrinsicSyntax _Intrinsic;
    };
};

struct AttributeSyntax : Object {
    AttributeSyntax(size_t start, size_t end, String attribute, ModelSyntax value) : start(start), end(end), attribute(attribute), value(value) {}
    size_t start;
    size_t end;
    String attribute;
    ModelSyntax value;
};

struct ExtensionSyntax : Object {
    ExtensionSyntax(size_t start, size_t end, String name) : start(start), end(end), name(name) {}
    size_t start;
    size_t end;
    String name;
};

struct DefinitionSyntax : Object {
    DefinitionSyntax(size_t start, size_t end, TypeSyntax type, Vector<AttributeSyntax>* attributes, ConceptSyntax concept_) : start(start), end(end), type(type), attributes(attributes), concept_(concept_) {}
    size_t start;
    size_t end;
    TypeSyntax type;
    Vector<AttributeSyntax>* attributes;
    ConceptSyntax concept_;
};

struct ExportSyntax : Object {
    ExportSyntax(DefinitionSyntax _DefinitionSyntax) : _tag(Definition) { _Definition = _DefinitionSyntax; }
    ExportSyntax(FunctionSyntax _FunctionSyntax) : _tag(Function) { _Function = _FunctionSyntax; }
    ExportSyntax(ProcedureSyntax _ProcedureSyntax) : _tag(Procedure) { _Procedure = _ProcedureSyntax; }
    ExportSyntax(OperatorSyntax _OperatorSyntax) : _tag(Operator) { _Operator = _OperatorSyntax; }
    ExportSyntax(ImplementSyntax _ImplementSyntax) : _tag(Implement) { _Implement = _ImplementSyntax; }
    ExportSyntax(TraitSyntax _TraitSyntax) : _tag(Trait) { _Trait = _TraitSyntax; }
    ExportSyntax(MacroSyntax _MacroSyntax) : _tag(Macro) { _Macro = _MacroSyntax; }
    ExportSyntax(ModuleSyntax _ModuleSyntax) : _tag(Module) { _Module = _ModuleSyntax; }
    enum {
        Definition,
        Function,
        Procedure,
        Operator,
        Implement,
        Trait,
        Macro,
        Module,
    } _tag;
    union {
        DefinitionSyntax _Definition;
        FunctionSyntax _Function;
        ProcedureSyntax _Procedure;
        OperatorSyntax _Operator;
        ImplementSyntax _Implement;
        TraitSyntax _Trait;
        MacroSyntax _Macro;
        ModuleSyntax _Module;
    };
};

struct PrivateSyntax : Object {
    PrivateSyntax(size_t start, size_t end, ExportSyntax export_) : start(start), end(end), export_(export_) {}
    size_t start;
    size_t end;
    ExportSyntax export_;
};

struct DeclarationSyntax : Object {
    DeclarationSyntax(PrivateSyntax _PrivateSyntax) : _tag(Private) { _Private = _PrivateSyntax; }
    DeclarationSyntax(DefinitionSyntax _DefinitionSyntax) : _tag(Definition) { _Definition = _DefinitionSyntax; }
    DeclarationSyntax(FunctionSyntax _FunctionSyntax) : _tag(Function) { _Function = _FunctionSyntax; }
    DeclarationSyntax(ProcedureSyntax _ProcedureSyntax) : _tag(Procedure) { _Procedure = _ProcedureSyntax; }
    DeclarationSyntax(OperatorSyntax _OperatorSyntax) : _tag(Operator) { _Operator = _OperatorSyntax; }
    DeclarationSyntax(ImplementSyntax _ImplementSyntax) : _tag(Implement) { _Implement = _ImplementSyntax; }
    DeclarationSyntax(TraitSyntax _TraitSyntax) : _tag(Trait) { _Trait = _TraitSyntax; }
    DeclarationSyntax(MacroSyntax _MacroSyntax) : _tag(Macro) { _Macro = _MacroSyntax; }
    DeclarationSyntax(ModuleSyntax _ModuleSyntax) : _tag(Module) { _Module = _ModuleSyntax; }
    enum {
        Private,
        Definition,
        Function,
        Procedure,
        Operator,
        Implement,
        Trait,
        Macro,
        Module,
    } _tag;
    union {
        PrivateSyntax _Private;
        DefinitionSyntax _Definition;
        FunctionSyntax _Function;
        ProcedureSyntax _Procedure;
        OperatorSyntax _Operator;
        ImplementSyntax _Implement;
        TraitSyntax _Trait;
        MacroSyntax _Macro;
        ModuleSyntax _Module;
    };
};

struct FileSyntax : Object {
    FileSyntax(size_t start, size_t end, Vector<UseSyntax>* uses, Vector<DeclarationSyntax>* declarations, Vector<StatementSyntax>* statements) : start(start), end(end), uses(uses), declarations(declarations), statements(statements) {}
    size_t start;
    size_t end;
    Vector<UseSyntax>* uses;
    Vector<DeclarationSyntax>* declarations;
    Vector<StatementSyntax>* statements;
};

using namespace scaly::containers;

struct Parser : Object {
    Lexer lexer;
    HashSet<String> keywords;

    Parser(Region& _pr, Page* _rp, String text)
      : lexer(*new(alignof(Lexer), _rp) Lexer(text)),
        keywords(initialize_keywords(_pr, _rp)) {}

    HashSet<String> initialize_keywords(Region& _pr, Page* _rp) {
        Region _r(_pr);
        HashSetBuilder<String>& hash_set_builder = *new(alignof(HashSetBuilder<String>), _r.page) HashSetBuilder<String>();
        hash_set_builder.add(String(Page::get(this), "as"));
        hash_set_builder.add(String(Page::get(this), "break"));
        hash_set_builder.add(String(Page::get(this), "catch"));
        hash_set_builder.add(String(Page::get(this), "case"));
        hash_set_builder.add(String(Page::get(this), "continue"));
        hash_set_builder.add(String(Page::get(this), "define"));
        hash_set_builder.add(String(Page::get(this), "default"));
        hash_set_builder.add(String(Page::get(this), "delegate"));
        hash_set_builder.add(String(Page::get(this), "drop"));
        hash_set_builder.add(String(Page::get(this), "else"));
        hash_set_builder.add(String(Page::get(this), "extends"));
        hash_set_builder.add(String(Page::get(this), "extern"));
        hash_set_builder.add(String(Page::get(this), "for"));
        hash_set_builder.add(String(Page::get(this), "function"));
        hash_set_builder.add(String(Page::get(this), "if"));
        hash_set_builder.add(String(Page::get(this), "is"));
        hash_set_builder.add(String(Page::get(this), "implement"));
        hash_set_builder.add(String(Page::get(this), "in"));
        hash_set_builder.add(String(Page::get(this), "instruction"));
        hash_set_builder.add(String(Page::get(this), "intrinsic"));
        hash_set_builder.add(String(Page::get(this), "label"));
        hash_set_builder.add(String(Page::get(this), "lambda"));
        hash_set_builder.add(String(Page::get(this), "let"));
        hash_set_builder.add(String(Page::get(this), "loop"));
        hash_set_builder.add(String(Page::get(this), "macro"));
        hash_set_builder.add(String(Page::get(this), "match"));
        hash_set_builder.add(String(Page::get(this), "module"));
        hash_set_builder.add(String(Page::get(this), "mutable"));
        hash_set_builder.add(String(Page::get(this), "operator"));
        hash_set_builder.add(String(Page::get(this), "procedure"));
        hash_set_builder.add(String(Page::get(this), "private"));
        hash_set_builder.add(String(Page::get(this), "return"));
        hash_set_builder.add(String(Page::get(this), "returns"));
        hash_set_builder.add(String(Page::get(this), "repeat"));
        hash_set_builder.add(String(Page::get(this), "set"));
        hash_set_builder.add(String(Page::get(this), "sizeof"));
        hash_set_builder.add(String(Page::get(this), "throw"));
        hash_set_builder.add(String(Page::get(this), "throws"));
        hash_set_builder.add(String(Page::get(this), "trait"));
        hash_set_builder.add(String(Page::get(this), "union"));
        hash_set_builder.add(String(Page::get(this), "use"));
        hash_set_builder.add(String(Page::get(this), "var"));
        hash_set_builder.add(String(Page::get(this), "while"));
        keywords = HashSet<String>(_r, _rp, hash_set_builder);
        return keywords;
    }

    Result<Literal, ParserError> parse_literal_token(Region& _pr, Page* _rp) {
        Region _r(_pr);
        if (this->lexer.token._tag == Token::Empty)
            lexer.advance(_r);

        switch (this->lexer.token._tag)
        {
            case Token::Literal:
                switch (this->lexer.token._Literal._tag)
                {
                    case LiteralToken::String:
                    {
                        auto ret = Literal(StringLiteral(String(_rp, this->lexer.token._Literal._String.value)));
                        this->lexer.empty();
                        return Result<Literal, ParserError> { ._tag = Result<Literal, ParserError>::Ok, ._Ok = ret };
                    }

                    case LiteralToken::Integer:
                    {
                        auto ret = Literal(IntegerLiteral(String(_rp, this->lexer.token._Literal._String.value)));
                        this->lexer.empty();
                        return Result<Literal, ParserError> { ._tag = Result<Literal, ParserError>::Ok, ._Ok = ret };
                    }

                    case LiteralToken::FloatingPoint:
                    {
                        auto ret = Literal(FloatingPointLiteral(String(_rp, this->lexer.token._Literal._String.value)));
                        this->lexer.empty();
                        return Result<Literal, ParserError> { ._tag = Result<Literal, ParserError>::Ok, ._Ok = ret };
                    }

                    case LiteralToken::Hex:
                    {
                        auto ret = Literal(HexLiteral(String(_rp, this->lexer.token._Literal._String.value)));
                        this->lexer.empty();
                        return Result<Literal, ParserError> { ._tag = Result<Literal, ParserError>::Ok, ._Ok = ret };
                    }

                    case LiteralToken::Boolean:
                    {
                        auto ret = Literal(BooleanLiteral(this->lexer.token._Literal._Boolean.value));
                        this->lexer.empty();
                        return Result<Literal, ParserError> { ._tag = Result<Literal, ParserError>::Ok, ._Ok = ret };
                    }

                    case LiteralToken::Fragment:
                    {
                        auto ret = Literal(FragmentLiteral(String(_rp, this->lexer.token._Literal._String.value)));
                        this->lexer.empty();
                        return Result<Literal, ParserError> { ._tag = Result<Literal, ParserError>::Ok, ._Ok = ret };
                    }

                    default:
                        return Result<Literal, ParserError> { ._tag = Result<Literal, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(lexer.position, lexer.position)) };
                }
            default:
                return Result<Literal, ParserError> { ._tag = Result<Literal, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }
    }

    Result<FileSyntax, ParserError> parse_file(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto uses_result = this->parse_use_list(_r, _rp, _ep);
        if (uses_result._tag == Result<Vector<UseSyntax>, ParserError>::Error)
        {
        }

        auto uses = uses_result._tag == Result<Vector<UseSyntax>, ParserError>::Error ? nullptr : uses_result._Ok;

        auto declarations_result = this->parse_declaration_list(_r, _rp, _ep);
        if (declarations_result._tag == Result<Vector<DeclarationSyntax>, ParserError>::Error)
        {
        }

        auto declarations = declarations_result._tag == Result<Vector<DeclarationSyntax>, ParserError>::Error ? nullptr : declarations_result._Ok;

        auto statements_result = this->parse_statement_list(_r, _rp, _ep);
        if (statements_result._tag == Result<Vector<StatementSyntax>, ParserError>::Error)
        {
        }

        auto statements = statements_result._tag == Result<Vector<StatementSyntax>, ParserError>::Error ? nullptr : statements_result._Ok;

        auto end = this->lexer.position;

        auto ret = FileSyntax(start, end, uses, declarations, statements);

        return Result<FileSyntax, ParserError> { ._tag = Result<FileSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<DeclarationSyntax>*, ParserError> parse_declaration_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<DeclarationSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_declaration(_r_1, _rp, _ep);
                if ((node_result._tag == Result<DeclarationSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<DeclarationSyntax>*, ParserError> { ._tag = Result<Vector<DeclarationSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<DeclarationSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<DeclarationSyntax>), _r_1.page) Array<DeclarationSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<DeclarationSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<DeclarationSyntax>*, ParserError> { ._tag = Result<Vector<DeclarationSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<DeclarationSyntax>*, ParserError> { ._tag = Result<Vector<DeclarationSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<DeclarationSyntax>*, ParserError> {
                ._tag = Result<Vector<DeclarationSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<DeclarationSyntax>), _rp) Vector<DeclarationSyntax>(_rp, *array) };
        }
    }

    Result<DeclarationSyntax, ParserError> parse_declaration(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            auto node_result = this->parse_private(_r_1, _rp, _ep);
            if (node_result._tag == Result<PrivateSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Ok, ._Ok = 
                    DeclarationSyntax(PrivateSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_definition(_r_1, _rp, _ep);
            if (node_result._tag == Result<DefinitionSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Ok, ._Ok = 
                    DeclarationSyntax(DefinitionSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_function(_r_1, _rp, _ep);
            if (node_result._tag == Result<FunctionSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Ok, ._Ok = 
                    DeclarationSyntax(FunctionSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_procedure(_r_1, _rp, _ep);
            if (node_result._tag == Result<ProcedureSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Ok, ._Ok = 
                    DeclarationSyntax(ProcedureSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_operator(_r_1, _rp, _ep);
            if (node_result._tag == Result<OperatorSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Ok, ._Ok = 
                    DeclarationSyntax(OperatorSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_implement(_r_1, _rp, _ep);
            if (node_result._tag == Result<ImplementSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Ok, ._Ok = 
                    DeclarationSyntax(ImplementSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_trait(_r_1, _rp, _ep);
            if (node_result._tag == Result<TraitSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Ok, ._Ok = 
                    DeclarationSyntax(TraitSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_macro(_r_1, _rp, _ep);
            if (node_result._tag == Result<MacroSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Ok, ._Ok = 
                    DeclarationSyntax(MacroSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_module(_r_1, _rp, _ep);
            if (node_result._tag == Result<ModuleSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Ok, ._Ok = 
                    DeclarationSyntax(ModuleSyntax(node))
                };
            }
        }
        return Result<DeclarationSyntax, ParserError> { ._tag = Result<DeclarationSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
    }

    Result<PrivateSyntax, ParserError> parse_private(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_private_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "private"));
        if (!success_private_1) {
                return Result<PrivateSyntax, ParserError> { ._tag = Result<PrivateSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto export__result = this->parse_export(_r, _rp, _ep);
        if (export__result._tag == Result<ExportSyntax, ParserError>::Error)
        {
            if (export__result._Error._tag == ParserError::OtherSyntax)
               return Result<PrivateSyntax, ParserError> { ._tag = Result<PrivateSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto export_ = export__result._Ok;

        auto end = this->lexer.position;

        auto ret = PrivateSyntax(start, end, export_);

        return Result<PrivateSyntax, ParserError> { ._tag = Result<PrivateSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ExportSyntax, ParserError> parse_export(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            auto node_result = this->parse_definition(_r_1, _rp, _ep);
            if (node_result._tag == Result<DefinitionSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Ok, ._Ok = 
                    ExportSyntax(DefinitionSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_function(_r_1, _rp, _ep);
            if (node_result._tag == Result<FunctionSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Ok, ._Ok = 
                    ExportSyntax(FunctionSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_procedure(_r_1, _rp, _ep);
            if (node_result._tag == Result<ProcedureSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Ok, ._Ok = 
                    ExportSyntax(ProcedureSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_operator(_r_1, _rp, _ep);
            if (node_result._tag == Result<OperatorSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Ok, ._Ok = 
                    ExportSyntax(OperatorSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_implement(_r_1, _rp, _ep);
            if (node_result._tag == Result<ImplementSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Ok, ._Ok = 
                    ExportSyntax(ImplementSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_trait(_r_1, _rp, _ep);
            if (node_result._tag == Result<TraitSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Ok, ._Ok = 
                    ExportSyntax(TraitSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_macro(_r_1, _rp, _ep);
            if (node_result._tag == Result<MacroSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Ok, ._Ok = 
                    ExportSyntax(MacroSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_module(_r_1, _rp, _ep);
            if (node_result._tag == Result<ModuleSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Ok, ._Ok = 
                    ExportSyntax(ModuleSyntax(node))
                };
            }
        }
        return Result<ExportSyntax, ParserError> { ._tag = Result<ExportSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
    }

    Result<DefinitionSyntax, ParserError> parse_definition(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_define_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "define"));
        if (!success_define_1) {
                return Result<DefinitionSyntax, ParserError> { ._tag = Result<DefinitionSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto type_result = this->parse_type(_r, _rp, _ep);
        if (type_result._tag == Result<TypeSyntax, ParserError>::Error)
        {
            if (type_result._Error._tag == ParserError::OtherSyntax)
               return Result<DefinitionSyntax, ParserError> { ._tag = Result<DefinitionSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto type = type_result._Ok;

        auto success_colon_3 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_3) {
        }

        auto attributes_result = this->parse_attribute_list(_r, _rp, _ep);
        if (attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error)
        {
        }

        auto attributes = attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error ? nullptr : attributes_result._Ok;

        auto concept__result = this->parse_concept(_r, _rp, _ep);
        if (concept__result._tag == Result<ConceptSyntax, ParserError>::Error)
        {
            if (concept__result._Error._tag == ParserError::OtherSyntax)
               return Result<DefinitionSyntax, ParserError> { ._tag = Result<DefinitionSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto concept_ = concept__result._Ok;

        auto end = this->lexer.position;

        auto ret = DefinitionSyntax(start, end, type, attributes, concept_);

        return Result<DefinitionSyntax, ParserError> { ._tag = Result<DefinitionSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<ExtensionSyntax>*, ParserError> parse_extension_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<ExtensionSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_extension(_r_1, _rp, _ep);
                if ((node_result._tag == Result<ExtensionSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<ExtensionSyntax>*, ParserError> { ._tag = Result<Vector<ExtensionSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<ExtensionSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<ExtensionSyntax>), _r_1.page) Array<ExtensionSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<ExtensionSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<ExtensionSyntax>*, ParserError> { ._tag = Result<Vector<ExtensionSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<ExtensionSyntax>*, ParserError> { ._tag = Result<Vector<ExtensionSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<ExtensionSyntax>*, ParserError> {
                ._tag = Result<Vector<ExtensionSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<ExtensionSyntax>), _rp) Vector<ExtensionSyntax>(_rp, *array) };
        }
    }

    Result<ExtensionSyntax, ParserError> parse_extension(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_dot_1 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "."));
        if (!success_dot_1) {
                return Result<ExtensionSyntax, ParserError> { ._tag = Result<ExtensionSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto name = this->lexer.parse_identifier(_r, _rp, this->keywords);
        if (name != nullptr) {
            if (!this->is_identifier(*name)) {
            return Result<ExtensionSyntax, ParserError> { ._tag = Result<ExtensionSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
            }
        }
        else {
            return Result<ExtensionSyntax, ParserError> { ._tag = Result<ExtensionSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto end = this->lexer.position;

        auto ret = ExtensionSyntax(start, end, *name);

        return Result<ExtensionSyntax, ParserError> { ._tag = Result<ExtensionSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<AttributeSyntax>*, ParserError> parse_attribute_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<AttributeSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_attribute(_r_1, _rp, _ep);
                if ((node_result._tag == Result<AttributeSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<AttributeSyntax>*, ParserError> { ._tag = Result<Vector<AttributeSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<AttributeSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<AttributeSyntax>), _r_1.page) Array<AttributeSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<AttributeSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<AttributeSyntax>*, ParserError> { ._tag = Result<Vector<AttributeSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<AttributeSyntax>*, ParserError> { ._tag = Result<Vector<AttributeSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<AttributeSyntax>*, ParserError> {
                ._tag = Result<Vector<AttributeSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<AttributeSyntax>), _rp) Vector<AttributeSyntax>(_rp, *array) };
        }
    }

    Result<AttributeSyntax, ParserError> parse_attribute(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto attribute = this->lexer.parse_attribute(_r, _rp);
        if (attribute == nullptr) {

                return Result<AttributeSyntax, ParserError> { ._tag = Result<AttributeSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto value_result = this->parse_model(_r, _rp, _ep);
        if (value_result._tag == Result<ModelSyntax, ParserError>::Error)
        {
            if (value_result._Error._tag == ParserError::OtherSyntax)
               return Result<AttributeSyntax, ParserError> { ._tag = Result<AttributeSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto value = value_result._Ok;

        auto end = this->lexer.position;

        auto ret = AttributeSyntax(start, end, *attribute, value);

        return Result<AttributeSyntax, ParserError> { ._tag = Result<AttributeSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ConceptSyntax, ParserError> parse_concept(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            auto node_result = this->parse_class(_r_1, _rp, _ep);
            if (node_result._tag == Result<ClassSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ConceptSyntax, ParserError> { ._tag = Result<ConceptSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ConceptSyntax, ParserError> { ._tag = Result<ConceptSyntax, ParserError>::Ok, ._Ok = 
                    ConceptSyntax(ClassSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_namespace(_r_1, _rp, _ep);
            if (node_result._tag == Result<NamespaceSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ConceptSyntax, ParserError> { ._tag = Result<ConceptSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ConceptSyntax, ParserError> { ._tag = Result<ConceptSyntax, ParserError>::Ok, ._Ok = 
                    ConceptSyntax(NamespaceSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_union(_r_1, _rp, _ep);
            if (node_result._tag == Result<UnionSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ConceptSyntax, ParserError> { ._tag = Result<ConceptSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ConceptSyntax, ParserError> { ._tag = Result<ConceptSyntax, ParserError>::Ok, ._Ok = 
                    ConceptSyntax(UnionSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_constant(_r_1, _rp, _ep);
            if (node_result._tag == Result<ConstantSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ConceptSyntax, ParserError> { ._tag = Result<ConceptSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ConceptSyntax, ParserError> { ._tag = Result<ConceptSyntax, ParserError>::Ok, ._Ok = 
                    ConceptSyntax(ConstantSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_delegate(_r_1, _rp, _ep);
            if (node_result._tag == Result<DelegateSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ConceptSyntax, ParserError> { ._tag = Result<ConceptSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ConceptSyntax, ParserError> { ._tag = Result<ConceptSyntax, ParserError>::Ok, ._Ok = 
                    ConceptSyntax(DelegateSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_intrinsic(_r_1, _rp, _ep);
            if (node_result._tag == Result<IntrinsicSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ConceptSyntax, ParserError> { ._tag = Result<ConceptSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ConceptSyntax, ParserError> { ._tag = Result<ConceptSyntax, ParserError>::Ok, ._Ok = 
                    ConceptSyntax(IntrinsicSyntax(node))
                };
            }
        }
        return Result<ConceptSyntax, ParserError> { ._tag = Result<ConceptSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
    }

    Result<ClassSyntax, ParserError> parse_class(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto structure_result = this->parse_structure(_r, _rp, _ep);
        if (structure_result._tag == Result<StructureSyntax, ParserError>::Error)
        {
            if (structure_result._Error._tag == ParserError::OtherSyntax)
               return Result<ClassSyntax, ParserError> { ._tag = Result<ClassSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto structure = structure_result._Ok;

        auto success_colon_2 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_2) {
        }

        auto body_result = this->parse_body(_r, _rp, _ep);
        if (body_result._tag == Result<BodySyntax, ParserError>::Error)
        {
        }

        BodySyntax* body = body_result._tag == Result<BodySyntax, ParserError>::Error ? nullptr : new(alignof(BodySyntax), _rp) BodySyntax(body_result._Ok);

        auto end = this->lexer.position;

        auto ret = ClassSyntax(start, end, structure, body);

        return Result<ClassSyntax, ParserError> { ._tag = Result<ClassSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<NamespaceSyntax, ParserError> parse_namespace(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto body_result = this->parse_body(_r, _rp, _ep);
        if (body_result._tag == Result<BodySyntax, ParserError>::Error)
        {
            if (body_result._Error._tag == ParserError::OtherSyntax)
               return Result<NamespaceSyntax, ParserError> { ._tag = Result<NamespaceSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto body = body_result._Ok;

        auto end = this->lexer.position;

        auto ret = NamespaceSyntax(start, end, body);

        return Result<NamespaceSyntax, ParserError> { ._tag = Result<NamespaceSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<UnionSyntax, ParserError> parse_union(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_union_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "union"));
        if (!success_union_1) {
                return Result<UnionSyntax, ParserError> { ._tag = Result<UnionSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto success_colon_2 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_2) {
        }

        auto success_left_paren_3 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "("));
        if (!success_left_paren_3) {
            return Result<UnionSyntax, ParserError> { ._tag = Result<UnionSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };        }

        auto tags_result = this->parse_tag_list(_r, _rp, _ep);
        if (tags_result._tag == Result<Vector<TagSyntax>, ParserError>::Error)
        {
            if (tags_result._Error._tag == ParserError::OtherSyntax)
               return Result<UnionSyntax, ParserError> { ._tag = Result<UnionSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto tags = tags_result._Ok;

        auto success_right_paren_5 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, ")"));
        if (!success_right_paren_5) {
            return Result<UnionSyntax, ParserError> { ._tag = Result<UnionSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };        }

        auto success_colon_6 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_6) {
        }

        auto body_result = this->parse_body(_r, _rp, _ep);
        if (body_result._tag == Result<BodySyntax, ParserError>::Error)
        {
            if (body_result._Error._tag == ParserError::OtherSyntax)
               return Result<UnionSyntax, ParserError> { ._tag = Result<UnionSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto body = body_result._Ok;

        auto end = this->lexer.position;

        auto ret = UnionSyntax(start, end, tags, body);

        return Result<UnionSyntax, ParserError> { ._tag = Result<UnionSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<TagSyntax>*, ParserError> parse_tag_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<TagSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_tag(_r_1, _rp, _ep);
                if ((node_result._tag == Result<TagSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<TagSyntax>*, ParserError> { ._tag = Result<Vector<TagSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<TagSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<TagSyntax>), _r_1.page) Array<TagSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<TagSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<TagSyntax>*, ParserError> { ._tag = Result<Vector<TagSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<TagSyntax>*, ParserError> { ._tag = Result<Vector<TagSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<TagSyntax>*, ParserError> {
                ._tag = Result<Vector<TagSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<TagSyntax>), _rp) Vector<TagSyntax>(_rp, *array) };
        }
    }

    Result<TagSyntax, ParserError> parse_tag(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto name = this->lexer.parse_identifier(_r, _rp, this->keywords);
        if (name != nullptr) {
            if (!this->is_identifier(*name)) {
                return Result<TagSyntax, ParserError> { ._tag = Result<TagSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };

            }
        }
        else {
                return Result<TagSyntax, ParserError> { ._tag = Result<TagSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };

        }

        auto attributes_result = this->parse_attribute_list(_r, _rp, _ep);
        if (attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error)
        {
        }

        auto attributes = attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error ? nullptr : attributes_result._Ok;

        auto item_result = this->parse_item(_r, _rp, _ep);
        if (item_result._tag == Result<ItemSyntax, ParserError>::Error)
        {
        }

        ItemSyntax* item = item_result._tag == Result<ItemSyntax, ParserError>::Error ? nullptr : new(alignof(ItemSyntax), _rp) ItemSyntax(item_result._Ok);

        auto end = this->lexer.position;

        auto ret = TagSyntax(start, end, *name, attributes, item);

        return Result<TagSyntax, ParserError> { ._tag = Result<TagSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ItemSyntax, ParserError> parse_item(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            auto node_result = this->parse_variant(_r_1, _rp, _ep);
            if (node_result._tag == Result<VariantSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ItemSyntax, ParserError> { ._tag = Result<ItemSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ItemSyntax, ParserError> { ._tag = Result<ItemSyntax, ParserError>::Ok, ._Ok = 
                    ItemSyntax(VariantSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_enum(_r_1, _rp, _ep);
            if (node_result._tag == Result<EnumSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ItemSyntax, ParserError> { ._tag = Result<ItemSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ItemSyntax, ParserError> { ._tag = Result<ItemSyntax, ParserError>::Ok, ._Ok = 
                    ItemSyntax(EnumSyntax(node))
                };
            }
        }
        return Result<ItemSyntax, ParserError> { ._tag = Result<ItemSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
    }

    Result<VariantSyntax, ParserError> parse_variant(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_colon_1 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_1) {
        }

        auto structure_result = this->parse_structure(_r, _rp, _ep);
        if (structure_result._tag == Result<StructureSyntax, ParserError>::Error)
        {
            if (structure_result._Error._tag == ParserError::OtherSyntax)
               return Result<VariantSyntax, ParserError> { ._tag = Result<VariantSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto structure = structure_result._Ok;

        auto success_colon_3 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_3) {
        }

        auto body_result = this->parse_body(_r, _rp, _ep);
        if (body_result._tag == Result<BodySyntax, ParserError>::Error)
        {
        }

        BodySyntax* body = body_result._tag == Result<BodySyntax, ParserError>::Error ? nullptr : new(alignof(BodySyntax), _rp) BodySyntax(body_result._Ok);

        auto success_colon_5 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_5) {
        }

        auto end = this->lexer.position;

        auto ret = VariantSyntax(start, end, structure, body);

        return Result<VariantSyntax, ParserError> { ._tag = Result<VariantSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<EnumSyntax, ParserError> parse_enum(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto literal_result = this->parse_literal_token(_r, _rp);
        if (literal_result._tag == Result<Literal, ParserError>::Error)
        {
            if (literal_result._Error._tag == ParserError::OtherSyntax)
               return Result<EnumSyntax, ParserError> { ._tag = Result<EnumSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto literal = literal_result._Ok;

        auto end = this->lexer.position;

        auto ret = EnumSyntax(start, end, literal);

        return Result<EnumSyntax, ParserError> { ._tag = Result<EnumSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ConstantSyntax, ParserError> parse_constant(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto operation_result = this->parse_operation(_r, _rp, _ep);
        if (operation_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (operation_result._Error._tag == ParserError::OtherSyntax)
               return Result<ConstantSyntax, ParserError> { ._tag = Result<ConstantSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto operation = operation_result._Ok;

        auto success_colon_2 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_2) {
        }

        auto end = this->lexer.position;

        auto ret = ConstantSyntax(start, end, operation);

        return Result<ConstantSyntax, ParserError> { ._tag = Result<ConstantSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<DelegateSyntax, ParserError> parse_delegate(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_delegate_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "delegate"));
        if (!success_delegate_1) {
                return Result<DelegateSyntax, ParserError> { ._tag = Result<DelegateSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto parameters_result = this->parse_parameterset(_r, _rp, _ep);
        if (parameters_result._tag == Result<ParameterSetSyntax, ParserError>::Error)
        {
        }

        ParameterSetSyntax* parameters = parameters_result._tag == Result<ParameterSetSyntax, ParserError>::Error ? nullptr : new(alignof(ParameterSetSyntax), _rp) ParameterSetSyntax(parameters_result._Ok);

        auto attributes_result = this->parse_attribute_list(_r, _rp, _ep);
        if (attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error)
        {
        }

        auto attributes = attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error ? nullptr : attributes_result._Ok;

        auto result_result = this->parse_returns(_r, _rp, _ep);
        if (result_result._tag == Result<ReturnsSyntax, ParserError>::Error)
        {
        }

        ReturnsSyntax* result = result_result._tag == Result<ReturnsSyntax, ParserError>::Error ? nullptr : new(alignof(ReturnsSyntax), _rp) ReturnsSyntax(result_result._Ok);

        auto error_result = this->parse_throws(_r, _rp, _ep);
        if (error_result._tag == Result<ThrowsSyntax, ParserError>::Error)
        {
        }

        ThrowsSyntax* error = error_result._tag == Result<ThrowsSyntax, ParserError>::Error ? nullptr : new(alignof(ThrowsSyntax), _rp) ThrowsSyntax(error_result._Ok);

        auto end = this->lexer.position;

        auto ret = DelegateSyntax(start, end, parameters, attributes, result, error);

        return Result<DelegateSyntax, ParserError> { ._tag = Result<DelegateSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<BodySyntax, ParserError> parse_body(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_left_curly_1 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "{"));
        if (!success_left_curly_1) {
                return Result<BodySyntax, ParserError> { ._tag = Result<BodySyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto uses_result = this->parse_use_list(_r, _rp, _ep);
        if (uses_result._tag == Result<Vector<UseSyntax>, ParserError>::Error)
        {
        }

        auto uses = uses_result._tag == Result<Vector<UseSyntax>, ParserError>::Error ? nullptr : uses_result._Ok;

        auto declarations_result = this->parse_declaration_list(_r, _rp, _ep);
        if (declarations_result._tag == Result<Vector<DeclarationSyntax>, ParserError>::Error)
        {
        }

        auto declarations = declarations_result._tag == Result<Vector<DeclarationSyntax>, ParserError>::Error ? nullptr : declarations_result._Ok;

        auto success_right_curly_4 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "}"));
        if (!success_right_curly_4) {
            return Result<BodySyntax, ParserError> { ._tag = Result<BodySyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };        }

        auto success_colon_5 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_5) {
        }

        auto end = this->lexer.position;

        auto ret = BodySyntax(start, end, uses, declarations);

        return Result<BodySyntax, ParserError> { ._tag = Result<BodySyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<MemberSyntax>*, ParserError> parse_member_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<MemberSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_member(_r_1, _rp, _ep);
                if ((node_result._tag == Result<MemberSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<MemberSyntax>*, ParserError> { ._tag = Result<Vector<MemberSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<MemberSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<MemberSyntax>), _r_1.page) Array<MemberSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<MemberSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<MemberSyntax>*, ParserError> { ._tag = Result<Vector<MemberSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<MemberSyntax>*, ParserError> { ._tag = Result<Vector<MemberSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<MemberSyntax>*, ParserError> {
                ._tag = Result<Vector<MemberSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<MemberSyntax>), _rp) Vector<MemberSyntax>(_rp, *array) };
        }
    }

    Result<MemberSyntax, ParserError> parse_member(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            auto node_result = this->parse_field(_r_1, _rp, _ep);
            if (node_result._tag == Result<FieldSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<MemberSyntax, ParserError> { ._tag = Result<MemberSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<MemberSyntax, ParserError> { ._tag = Result<MemberSyntax, ParserError>::Ok, ._Ok = 
                    MemberSyntax(FieldSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_property(_r_1, _rp, _ep);
            if (node_result._tag == Result<PropertySyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<MemberSyntax, ParserError> { ._tag = Result<MemberSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<MemberSyntax, ParserError> { ._tag = Result<MemberSyntax, ParserError>::Ok, ._Ok = 
                    MemberSyntax(PropertySyntax(node))
                };
            }
        }
        return Result<MemberSyntax, ParserError> { ._tag = Result<MemberSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
    }

    Result<FieldSyntax, ParserError> parse_field(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_private_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "private"));
        if (!success_private_1) {
                return Result<FieldSyntax, ParserError> { ._tag = Result<FieldSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto property_result = this->parse_property(_r, _rp, _ep);
        if (property_result._tag == Result<PropertySyntax, ParserError>::Error)
        {
            if (property_result._Error._tag == ParserError::OtherSyntax)
               return Result<FieldSyntax, ParserError> { ._tag = Result<FieldSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto property = property_result._Ok;

        auto end = this->lexer.position;

        auto ret = FieldSyntax(start, end, property);

        return Result<FieldSyntax, ParserError> { ._tag = Result<FieldSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<PropertySyntax>*, ParserError> parse_property_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<PropertySyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_property(_r_1, _rp, _ep);
                if ((node_result._tag == Result<PropertySyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<PropertySyntax>*, ParserError> { ._tag = Result<Vector<PropertySyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<PropertySyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<PropertySyntax>), _r_1.page) Array<PropertySyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<PropertySyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<PropertySyntax>*, ParserError> { ._tag = Result<Vector<PropertySyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<PropertySyntax>*, ParserError> { ._tag = Result<Vector<PropertySyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<PropertySyntax>*, ParserError> {
                ._tag = Result<Vector<PropertySyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<PropertySyntax>), _rp) Vector<PropertySyntax>(_rp, *array) };
        }
    }

    Result<PropertySyntax, ParserError> parse_property(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto name = this->lexer.parse_identifier(_r, _rp, this->keywords);
        if (name != nullptr) {
            if (!this->is_identifier(*name)) {
                return Result<PropertySyntax, ParserError> { ._tag = Result<PropertySyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };

            }
        }
        else {
                return Result<PropertySyntax, ParserError> { ._tag = Result<PropertySyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };

        }

        auto annotation_result = this->parse_typeannotation(_r, _rp, _ep);
        if (annotation_result._tag == Result<TypeAnnotationSyntax, ParserError>::Error)
        {
        }

        TypeAnnotationSyntax* annotation = annotation_result._tag == Result<TypeAnnotationSyntax, ParserError>::Error ? nullptr : new(alignof(TypeAnnotationSyntax), _rp) TypeAnnotationSyntax(annotation_result._Ok);

        auto attributes_result = this->parse_attribute_list(_r, _rp, _ep);
        if (attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error)
        {
        }

        auto attributes = attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error ? nullptr : attributes_result._Ok;

        auto success_comma_4 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, ","));
        if (!success_comma_4) {
        }

        auto success_colon_5 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_5) {
        }

        auto end = this->lexer.position;

        auto ret = PropertySyntax(start, end, *name, annotation, attributes);

        return Result<PropertySyntax, ParserError> { ._tag = Result<PropertySyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<TypeAnnotationSyntax, ParserError> parse_typeannotation(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_colon_1 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_1) {
                return Result<TypeAnnotationSyntax, ParserError> { ._tag = Result<TypeAnnotationSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto type_result = this->parse_type(_r, _rp, _ep);
        if (type_result._tag == Result<TypeSyntax, ParserError>::Error)
        {
            if (type_result._Error._tag == ParserError::OtherSyntax)
               return Result<TypeAnnotationSyntax, ParserError> { ._tag = Result<TypeAnnotationSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto type = type_result._Ok;

        auto end = this->lexer.position;

        auto ret = TypeAnnotationSyntax(start, end, type);

        return Result<TypeAnnotationSyntax, ParserError> { ._tag = Result<TypeAnnotationSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<GenericArgumentsSyntax, ParserError> parse_genericarguments(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_left_bracket_1 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "["));
        if (!success_left_bracket_1) {
                return Result<GenericArgumentsSyntax, ParserError> { ._tag = Result<GenericArgumentsSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto generics_result = this->parse_genericargument_list(_r, _rp, _ep);
        if (generics_result._tag == Result<Vector<GenericArgumentSyntax>, ParserError>::Error)
        {
        }

        auto generics = generics_result._tag == Result<Vector<GenericArgumentSyntax>, ParserError>::Error ? nullptr : generics_result._Ok;

        auto success_right_bracket_3 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "]"));
        if (!success_right_bracket_3) {
            return Result<GenericArgumentsSyntax, ParserError> { ._tag = Result<GenericArgumentsSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };        }

        auto end = this->lexer.position;

        auto ret = GenericArgumentsSyntax(start, end, generics);

        return Result<GenericArgumentsSyntax, ParserError> { ._tag = Result<GenericArgumentsSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<GenericArgumentSyntax>*, ParserError> parse_genericargument_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<GenericArgumentSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_genericargument(_r_1, _rp, _ep);
                if ((node_result._tag == Result<GenericArgumentSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<GenericArgumentSyntax>*, ParserError> { ._tag = Result<Vector<GenericArgumentSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<GenericArgumentSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<GenericArgumentSyntax>), _r_1.page) Array<GenericArgumentSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<GenericArgumentSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<GenericArgumentSyntax>*, ParserError> { ._tag = Result<Vector<GenericArgumentSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<GenericArgumentSyntax>*, ParserError> { ._tag = Result<Vector<GenericArgumentSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<GenericArgumentSyntax>*, ParserError> {
                ._tag = Result<Vector<GenericArgumentSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<GenericArgumentSyntax>), _rp) Vector<GenericArgumentSyntax>(_rp, *array) };
        }
    }

    Result<GenericArgumentSyntax, ParserError> parse_genericargument(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto type_result = this->parse_type(_r, _rp, _ep);
        if (type_result._tag == Result<TypeSyntax, ParserError>::Error)
        {
            if (type_result._Error._tag == ParserError::OtherSyntax)
               return Result<GenericArgumentSyntax, ParserError> { ._tag = Result<GenericArgumentSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto type = type_result._Ok;

        auto success_comma_2 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, ","));
        if (!success_comma_2) {
        }

        auto end = this->lexer.position;

        auto ret = GenericArgumentSyntax(start, end, type);

        return Result<GenericArgumentSyntax, ParserError> { ._tag = Result<GenericArgumentSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<OptionalSyntax, ParserError> parse_optional(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_question_1 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "?"));
        if (!success_question_1) {
                return Result<OptionalSyntax, ParserError> { ._tag = Result<OptionalSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto end = this->lexer.position;

        auto ret = OptionalSyntax(start, end);

        return Result<OptionalSyntax, ParserError> { ._tag = Result<OptionalSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ReturnsSyntax, ParserError> parse_returns(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_returns_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "returns"));
        if (!success_returns_1) {
                return Result<ReturnsSyntax, ParserError> { ._tag = Result<ReturnsSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto parameters_result = this->parse_parameterset(_r, _rp, _ep);
        if (parameters_result._tag == Result<ParameterSetSyntax, ParserError>::Error)
        {
            if (parameters_result._Error._tag == ParserError::OtherSyntax)
               return Result<ReturnsSyntax, ParserError> { ._tag = Result<ReturnsSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto parameters = parameters_result._Ok;

        auto attributes_result = this->parse_attribute_list(_r, _rp, _ep);
        if (attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error)
        {
        }

        auto attributes = attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error ? nullptr : attributes_result._Ok;

        auto end = this->lexer.position;

        auto ret = ReturnsSyntax(start, end, parameters, attributes);

        return Result<ReturnsSyntax, ParserError> { ._tag = Result<ReturnsSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ParameterSetSyntax, ParserError> parse_parameterset(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            auto node_result = this->parse_parameters(_r_1, _rp, _ep);
            if (node_result._tag == Result<ParametersSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ParameterSetSyntax, ParserError> { ._tag = Result<ParameterSetSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ParameterSetSyntax, ParserError> { ._tag = Result<ParameterSetSyntax, ParserError>::Ok, ._Ok = 
                    ParameterSetSyntax(ParametersSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_type(_r_1, _rp, _ep);
            if (node_result._tag == Result<TypeSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ParameterSetSyntax, ParserError> { ._tag = Result<ParameterSetSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ParameterSetSyntax, ParserError> { ._tag = Result<ParameterSetSyntax, ParserError>::Ok, ._Ok = 
                    ParameterSetSyntax(TypeSyntax(node))
                };
            }
        }
        return Result<ParameterSetSyntax, ParserError> { ._tag = Result<ParameterSetSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
    }

    Result<ParametersSyntax, ParserError> parse_parameters(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_left_paren_1 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "("));
        if (!success_left_paren_1) {
                return Result<ParametersSyntax, ParserError> { ._tag = Result<ParametersSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto properties_result = this->parse_property_list(_r, _rp, _ep);
        if (properties_result._tag == Result<Vector<PropertySyntax>, ParserError>::Error)
        {
        }

        auto properties = properties_result._tag == Result<Vector<PropertySyntax>, ParserError>::Error ? nullptr : properties_result._Ok;

        auto success_right_paren_3 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, ")"));
        if (!success_right_paren_3) {
            return Result<ParametersSyntax, ParserError> { ._tag = Result<ParametersSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };        }

        auto end = this->lexer.position;

        auto ret = ParametersSyntax(start, end, properties);

        return Result<ParametersSyntax, ParserError> { ._tag = Result<ParametersSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ThrowsSyntax, ParserError> parse_throws(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_throws_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "throws"));
        if (!success_throws_1) {
                return Result<ThrowsSyntax, ParserError> { ._tag = Result<ThrowsSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto type_result = this->parse_type(_r, _rp, _ep);
        if (type_result._tag == Result<TypeSyntax, ParserError>::Error)
        {
            if (type_result._Error._tag == ParserError::OtherSyntax)
               return Result<ThrowsSyntax, ParserError> { ._tag = Result<ThrowsSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto type = type_result._Ok;

        auto attributes_result = this->parse_attribute_list(_r, _rp, _ep);
        if (attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error)
        {
        }

        auto attributes = attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error ? nullptr : attributes_result._Ok;

        auto end = this->lexer.position;

        auto ret = ThrowsSyntax(start, end, type, attributes);

        return Result<ThrowsSyntax, ParserError> { ._tag = Result<ThrowsSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<UseSyntax>*, ParserError> parse_use_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<UseSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_use(_r_1, _rp, _ep);
                if ((node_result._tag == Result<UseSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<UseSyntax>*, ParserError> { ._tag = Result<Vector<UseSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<UseSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<UseSyntax>), _r_1.page) Array<UseSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<UseSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<UseSyntax>*, ParserError> { ._tag = Result<Vector<UseSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<UseSyntax>*, ParserError> { ._tag = Result<Vector<UseSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<UseSyntax>*, ParserError> {
                ._tag = Result<Vector<UseSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<UseSyntax>), _rp) Vector<UseSyntax>(_rp, *array) };
        }
    }

    Result<UseSyntax, ParserError> parse_use(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_use_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "use"));
        if (!success_use_1) {
                return Result<UseSyntax, ParserError> { ._tag = Result<UseSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto name_result = this->parse_name(_r, _rp, _ep);
        if (name_result._tag == Result<NameSyntax, ParserError>::Error)
        {
            if (name_result._Error._tag == ParserError::OtherSyntax)
               return Result<UseSyntax, ParserError> { ._tag = Result<UseSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto name = name_result._Ok;

        auto success_colon_3 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_3) {
        }

        auto end = this->lexer.position;

        auto ret = UseSyntax(start, end, name);

        return Result<UseSyntax, ParserError> { ._tag = Result<UseSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ImplementSyntax, ParserError> parse_implement(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_implement_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "implement"));
        if (!success_implement_1) {
                return Result<ImplementSyntax, ParserError> { ._tag = Result<ImplementSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto type_result = this->parse_type(_r, _rp, _ep);
        if (type_result._tag == Result<TypeSyntax, ParserError>::Error)
        {
            if (type_result._Error._tag == ParserError::OtherSyntax)
               return Result<ImplementSyntax, ParserError> { ._tag = Result<ImplementSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto type = type_result._Ok;

        auto attributes_result = this->parse_attribute_list(_r, _rp, _ep);
        if (attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error)
        {
        }

        auto attributes = attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error ? nullptr : attributes_result._Ok;

        auto success_colon_4 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_4) {
        }

        auto success_left_curly_5 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "{"));
        if (!success_left_curly_5) {
            return Result<ImplementSyntax, ParserError> { ._tag = Result<ImplementSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };        }

        auto uses_result = this->parse_use_list(_r, _rp, _ep);
        if (uses_result._tag == Result<Vector<UseSyntax>, ParserError>::Error)
        {
        }

        auto uses = uses_result._tag == Result<Vector<UseSyntax>, ParserError>::Error ? nullptr : uses_result._Ok;

        auto methods_result = this->parse_method_list(_r, _rp, _ep);
        if (methods_result._tag == Result<Vector<MethodSyntax>, ParserError>::Error)
        {
        }

        auto methods = methods_result._tag == Result<Vector<MethodSyntax>, ParserError>::Error ? nullptr : methods_result._Ok;

        auto success_right_curly_8 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "}"));
        if (!success_right_curly_8) {
            return Result<ImplementSyntax, ParserError> { ._tag = Result<ImplementSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };        }

        auto success_colon_9 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_9) {
        }

        auto end = this->lexer.position;

        auto ret = ImplementSyntax(start, end, type, attributes, uses, methods);

        return Result<ImplementSyntax, ParserError> { ._tag = Result<ImplementSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<TraitSyntax, ParserError> parse_trait(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_trait_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "trait"));
        if (!success_trait_1) {
                return Result<TraitSyntax, ParserError> { ._tag = Result<TraitSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto name_result = this->parse_name(_r, _rp, _ep);
        if (name_result._tag == Result<NameSyntax, ParserError>::Error)
        {
            if (name_result._Error._tag == ParserError::OtherSyntax)
               return Result<TraitSyntax, ParserError> { ._tag = Result<TraitSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto name = name_result._Ok;

        auto extension_result = this->parse_extends(_r, _rp, _ep);
        if (extension_result._tag == Result<ExtendsSyntax, ParserError>::Error)
        {
        }

        ExtendsSyntax* extension = extension_result._tag == Result<ExtendsSyntax, ParserError>::Error ? nullptr : new(alignof(ExtendsSyntax), _rp) ExtendsSyntax(extension_result._Ok);

        auto attributes_result = this->parse_attribute_list(_r, _rp, _ep);
        if (attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error)
        {
        }

        auto attributes = attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error ? nullptr : attributes_result._Ok;

        auto success_left_curly_5 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "{"));
        if (!success_left_curly_5) {
            return Result<TraitSyntax, ParserError> { ._tag = Result<TraitSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };        }

        auto uses_result = this->parse_use_list(_r, _rp, _ep);
        if (uses_result._tag == Result<Vector<UseSyntax>, ParserError>::Error)
        {
        }

        auto uses = uses_result._tag == Result<Vector<UseSyntax>, ParserError>::Error ? nullptr : uses_result._Ok;

        auto functions_result = this->parse_method_list(_r, _rp, _ep);
        if (functions_result._tag == Result<Vector<MethodSyntax>, ParserError>::Error)
        {
        }

        auto functions = functions_result._tag == Result<Vector<MethodSyntax>, ParserError>::Error ? nullptr : functions_result._Ok;

        auto success_right_curly_8 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "}"));
        if (!success_right_curly_8) {
            return Result<TraitSyntax, ParserError> { ._tag = Result<TraitSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };        }

        auto success_colon_9 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_9) {
        }

        auto end = this->lexer.position;

        auto ret = TraitSyntax(start, end, name, extension, attributes, uses, functions);

        return Result<TraitSyntax, ParserError> { ._tag = Result<TraitSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<MethodSyntax>*, ParserError> parse_method_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<MethodSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_method(_r_1, _rp, _ep);
                if ((node_result._tag == Result<MethodSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<MethodSyntax>*, ParserError> { ._tag = Result<Vector<MethodSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<MethodSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<MethodSyntax>), _r_1.page) Array<MethodSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<MethodSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<MethodSyntax>*, ParserError> { ._tag = Result<Vector<MethodSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<MethodSyntax>*, ParserError> { ._tag = Result<Vector<MethodSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<MethodSyntax>*, ParserError> {
                ._tag = Result<Vector<MethodSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<MethodSyntax>), _rp) Vector<MethodSyntax>(_rp, *array) };
        }
    }

    Result<MethodSyntax, ParserError> parse_method(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            auto node_result = this->parse_function(_r_1, _rp, _ep);
            if (node_result._tag == Result<FunctionSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<MethodSyntax, ParserError> { ._tag = Result<MethodSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<MethodSyntax, ParserError> { ._tag = Result<MethodSyntax, ParserError>::Ok, ._Ok = 
                    MethodSyntax(FunctionSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_procedure(_r_1, _rp, _ep);
            if (node_result._tag == Result<ProcedureSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<MethodSyntax, ParserError> { ._tag = Result<MethodSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<MethodSyntax, ParserError> { ._tag = Result<MethodSyntax, ParserError>::Ok, ._Ok = 
                    MethodSyntax(ProcedureSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_operator(_r_1, _rp, _ep);
            if (node_result._tag == Result<OperatorSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<MethodSyntax, ParserError> { ._tag = Result<MethodSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<MethodSyntax, ParserError> { ._tag = Result<MethodSyntax, ParserError>::Ok, ._Ok = 
                    MethodSyntax(OperatorSyntax(node))
                };
            }
        }
        return Result<MethodSyntax, ParserError> { ._tag = Result<MethodSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
    }

    Result<FunctionSyntax, ParserError> parse_function(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_function_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "function"));
        if (!success_function_1) {
                return Result<FunctionSyntax, ParserError> { ._tag = Result<FunctionSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto name = this->lexer.parse_identifier(_r, _rp, this->keywords);
        if (name != nullptr) {
            if (!this->is_identifier(*name)) {
            return Result<FunctionSyntax, ParserError> { ._tag = Result<FunctionSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
            }
        }
        else {
            return Result<FunctionSyntax, ParserError> { ._tag = Result<FunctionSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto generics_result = this->parse_genericarguments(_r, _rp, _ep);
        if (generics_result._tag == Result<GenericArgumentsSyntax, ParserError>::Error)
        {
        }

        GenericArgumentsSyntax* generics = generics_result._tag == Result<GenericArgumentsSyntax, ParserError>::Error ? nullptr : new(alignof(GenericArgumentsSyntax), _rp) GenericArgumentsSyntax(generics_result._Ok);

        auto routine_result = this->parse_routine(_r, _rp, _ep);
        if (routine_result._tag == Result<RoutineSyntax, ParserError>::Error)
        {
            if (routine_result._Error._tag == ParserError::OtherSyntax)
               return Result<FunctionSyntax, ParserError> { ._tag = Result<FunctionSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto routine = routine_result._Ok;

        auto end = this->lexer.position;

        auto ret = FunctionSyntax(start, end, *name, generics, routine);

        return Result<FunctionSyntax, ParserError> { ._tag = Result<FunctionSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ProcedureSyntax, ParserError> parse_procedure(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_procedure_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "procedure"));
        if (!success_procedure_1) {
                return Result<ProcedureSyntax, ParserError> { ._tag = Result<ProcedureSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto name = this->lexer.parse_identifier(_r, _rp, this->keywords);
        if (name != nullptr) {
            if (!this->is_identifier(*name)) {
            return Result<ProcedureSyntax, ParserError> { ._tag = Result<ProcedureSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
            }
        }
        else {
            return Result<ProcedureSyntax, ParserError> { ._tag = Result<ProcedureSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto generics_result = this->parse_genericarguments(_r, _rp, _ep);
        if (generics_result._tag == Result<GenericArgumentsSyntax, ParserError>::Error)
        {
        }

        GenericArgumentsSyntax* generics = generics_result._tag == Result<GenericArgumentsSyntax, ParserError>::Error ? nullptr : new(alignof(GenericArgumentsSyntax), _rp) GenericArgumentsSyntax(generics_result._Ok);

        auto routine_result = this->parse_routine(_r, _rp, _ep);
        if (routine_result._tag == Result<RoutineSyntax, ParserError>::Error)
        {
            if (routine_result._Error._tag == ParserError::OtherSyntax)
               return Result<ProcedureSyntax, ParserError> { ._tag = Result<ProcedureSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto routine = routine_result._Ok;

        auto end = this->lexer.position;

        auto ret = ProcedureSyntax(start, end, *name, generics, routine);

        return Result<ProcedureSyntax, ParserError> { ._tag = Result<ProcedureSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<OperatorSyntax, ParserError> parse_operator(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_operator_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "operator"));
        if (!success_operator_1) {
                return Result<OperatorSyntax, ParserError> { ._tag = Result<OperatorSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto target_result = this->parse_target(_r, _rp, _ep);
        if (target_result._tag == Result<TargetSyntax, ParserError>::Error)
        {
            if (target_result._Error._tag == ParserError::OtherSyntax)
               return Result<OperatorSyntax, ParserError> { ._tag = Result<OperatorSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto target = target_result._Ok;

        auto end = this->lexer.position;

        auto ret = OperatorSyntax(start, end, target);

        return Result<OperatorSyntax, ParserError> { ._tag = Result<OperatorSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<TargetSyntax, ParserError> parse_target(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            auto node_result = this->parse_symbol(_r_1, _rp, _ep);
            if (node_result._tag == Result<SymbolSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<TargetSyntax, ParserError> { ._tag = Result<TargetSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<TargetSyntax, ParserError> { ._tag = Result<TargetSyntax, ParserError>::Ok, ._Ok = 
                    TargetSyntax(SymbolSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_routine(_r_1, _rp, _ep);
            if (node_result._tag == Result<RoutineSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<TargetSyntax, ParserError> { ._tag = Result<TargetSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<TargetSyntax, ParserError> { ._tag = Result<TargetSyntax, ParserError>::Ok, ._Ok = 
                    TargetSyntax(RoutineSyntax(node))
                };
            }
        }
        return Result<TargetSyntax, ParserError> { ._tag = Result<TargetSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
    }

    Result<RoutineSyntax, ParserError> parse_routine(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto parameters_result = this->parse_parameterset(_r, _rp, _ep);
        if (parameters_result._tag == Result<ParameterSetSyntax, ParserError>::Error)
        {
        }

        ParameterSetSyntax* parameters = parameters_result._tag == Result<ParameterSetSyntax, ParserError>::Error ? nullptr : new(alignof(ParameterSetSyntax), _rp) ParameterSetSyntax(parameters_result._Ok);

        auto attributes_result = this->parse_attribute_list(_r, _rp, _ep);
        if (attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error)
        {
        }

        auto attributes = attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error ? nullptr : attributes_result._Ok;

        auto returns_result = this->parse_returns(_r, _rp, _ep);
        if (returns_result._tag == Result<ReturnsSyntax, ParserError>::Error)
        {
        }

        ReturnsSyntax* returns = returns_result._tag == Result<ReturnsSyntax, ParserError>::Error ? nullptr : new(alignof(ReturnsSyntax), _rp) ReturnsSyntax(returns_result._Ok);

        auto success_colon_4 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_4) {
        }

        auto throws_result = this->parse_throws(_r, _rp, _ep);
        if (throws_result._tag == Result<ThrowsSyntax, ParserError>::Error)
        {
        }

        ThrowsSyntax* throws = throws_result._tag == Result<ThrowsSyntax, ParserError>::Error ? nullptr : new(alignof(ThrowsSyntax), _rp) ThrowsSyntax(throws_result._Ok);

        auto success_colon_6 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_6) {
        }

        auto implementation_result = this->parse_implementation(_r, _rp, _ep);
        if (implementation_result._tag == Result<ImplementationSyntax, ParserError>::Error)
        {
            if (implementation_result._Error._tag == ParserError::OtherSyntax)
               return Result<RoutineSyntax, ParserError> { ._tag = Result<RoutineSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto implementation = implementation_result._Ok;

        auto end = this->lexer.position;

        auto ret = RoutineSyntax(start, end, parameters, attributes, returns, throws, implementation);

        return Result<RoutineSyntax, ParserError> { ._tag = Result<RoutineSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<SymbolSyntax, ParserError> parse_symbol(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto name = this->lexer.parse_identifier(_r, _rp, this->keywords);
        if (name != nullptr) {
            if (!this->is_identifier(*name)) {
                return Result<SymbolSyntax, ParserError> { ._tag = Result<SymbolSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };

            }
        }
        else {
                return Result<SymbolSyntax, ParserError> { ._tag = Result<SymbolSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };

        }

        auto attributes_result = this->parse_attribute_list(_r, _rp, _ep);
        if (attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error)
        {
        }

        auto attributes = attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error ? nullptr : attributes_result._Ok;

        auto returns_result = this->parse_returns(_r, _rp, _ep);
        if (returns_result._tag == Result<ReturnsSyntax, ParserError>::Error)
        {
        }

        ReturnsSyntax* returns = returns_result._tag == Result<ReturnsSyntax, ParserError>::Error ? nullptr : new(alignof(ReturnsSyntax), _rp) ReturnsSyntax(returns_result._Ok);

        auto success_colon_4 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_4) {
        }

        auto throws_result = this->parse_throws(_r, _rp, _ep);
        if (throws_result._tag == Result<ThrowsSyntax, ParserError>::Error)
        {
        }

        ThrowsSyntax* throws = throws_result._tag == Result<ThrowsSyntax, ParserError>::Error ? nullptr : new(alignof(ThrowsSyntax), _rp) ThrowsSyntax(throws_result._Ok);

        auto success_colon_6 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_6) {
        }

        auto implementation_result = this->parse_implementation(_r, _rp, _ep);
        if (implementation_result._tag == Result<ImplementationSyntax, ParserError>::Error)
        {
            if (implementation_result._Error._tag == ParserError::OtherSyntax)
               return Result<SymbolSyntax, ParserError> { ._tag = Result<SymbolSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto implementation = implementation_result._Ok;

        auto end = this->lexer.position;

        auto ret = SymbolSyntax(start, end, *name, attributes, returns, throws, implementation);

        return Result<SymbolSyntax, ParserError> { ._tag = Result<SymbolSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ImplementationSyntax, ParserError> parse_implementation(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            auto node_result = this->parse_action(_r_1, _rp, _ep);
            if (node_result._tag == Result<ActionSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ImplementationSyntax, ParserError> { ._tag = Result<ImplementationSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ImplementationSyntax, ParserError> { ._tag = Result<ImplementationSyntax, ParserError>::Ok, ._Ok = 
                    ImplementationSyntax(ActionSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_extern(_r_1, _rp, _ep);
            if (node_result._tag == Result<ExternSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ImplementationSyntax, ParserError> { ._tag = Result<ImplementationSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ImplementationSyntax, ParserError> { ._tag = Result<ImplementationSyntax, ParserError>::Ok, ._Ok = 
                    ImplementationSyntax(ExternSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_instruction(_r_1, _rp, _ep);
            if (node_result._tag == Result<InstructionSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ImplementationSyntax, ParserError> { ._tag = Result<ImplementationSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ImplementationSyntax, ParserError> { ._tag = Result<ImplementationSyntax, ParserError>::Ok, ._Ok = 
                    ImplementationSyntax(InstructionSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_intrinsic(_r_1, _rp, _ep);
            if (node_result._tag == Result<IntrinsicSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ImplementationSyntax, ParserError> { ._tag = Result<ImplementationSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ImplementationSyntax, ParserError> { ._tag = Result<ImplementationSyntax, ParserError>::Ok, ._Ok = 
                    ImplementationSyntax(IntrinsicSyntax(node))
                };
            }
        }
        return Result<ImplementationSyntax, ParserError> { ._tag = Result<ImplementationSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
    }

    Result<ExternSyntax, ParserError> parse_extern(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_extern_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "extern"));
        if (!success_extern_1) {
                return Result<ExternSyntax, ParserError> { ._tag = Result<ExternSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto end = this->lexer.position;

        auto ret = ExternSyntax(start, end);

        return Result<ExternSyntax, ParserError> { ._tag = Result<ExternSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<InstructionSyntax, ParserError> parse_instruction(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_instruction_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "instruction"));
        if (!success_instruction_1) {
                return Result<InstructionSyntax, ParserError> { ._tag = Result<InstructionSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto success_colon_2 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_2) {
        }

        auto end = this->lexer.position;

        auto ret = InstructionSyntax(start, end);

        return Result<InstructionSyntax, ParserError> { ._tag = Result<InstructionSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<IntrinsicSyntax, ParserError> parse_intrinsic(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_intrinsic_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "intrinsic"));
        if (!success_intrinsic_1) {
                return Result<IntrinsicSyntax, ParserError> { ._tag = Result<IntrinsicSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto success_colon_2 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_2) {
        }

        auto end = this->lexer.position;

        auto ret = IntrinsicSyntax(start, end);

        return Result<IntrinsicSyntax, ParserError> { ._tag = Result<IntrinsicSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ExtendsSyntax, ParserError> parse_extends(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_extends_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "extends"));
        if (!success_extends_1) {
                return Result<ExtendsSyntax, ParserError> { ._tag = Result<ExtendsSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto extensions_result = this->parse_extend_list(_r, _rp, _ep);
        if (extensions_result._tag == Result<Vector<ExtendSyntax>, ParserError>::Error)
        {
        }

        auto extensions = extensions_result._tag == Result<Vector<ExtendSyntax>, ParserError>::Error ? nullptr : extensions_result._Ok;

        auto end = this->lexer.position;

        auto ret = ExtendsSyntax(start, end, extensions);

        return Result<ExtendsSyntax, ParserError> { ._tag = Result<ExtendsSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<ExtendSyntax>*, ParserError> parse_extend_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<ExtendSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_extend(_r_1, _rp, _ep);
                if ((node_result._tag == Result<ExtendSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<ExtendSyntax>*, ParserError> { ._tag = Result<Vector<ExtendSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<ExtendSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<ExtendSyntax>), _r_1.page) Array<ExtendSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<ExtendSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<ExtendSyntax>*, ParserError> { ._tag = Result<Vector<ExtendSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<ExtendSyntax>*, ParserError> { ._tag = Result<Vector<ExtendSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<ExtendSyntax>*, ParserError> {
                ._tag = Result<Vector<ExtendSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<ExtendSyntax>), _rp) Vector<ExtendSyntax>(_rp, *array) };
        }
    }

    Result<ExtendSyntax, ParserError> parse_extend(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto type_result = this->parse_type(_r, _rp, _ep);
        if (type_result._tag == Result<TypeSyntax, ParserError>::Error)
        {
            if (type_result._Error._tag == ParserError::OtherSyntax)
               return Result<ExtendSyntax, ParserError> { ._tag = Result<ExtendSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto type = type_result._Ok;

        auto success_comma_2 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, ","));
        if (!success_comma_2) {
        }

        auto end = this->lexer.position;

        auto ret = ExtendSyntax(start, end, type);

        return Result<ExtendSyntax, ParserError> { ._tag = Result<ExtendSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<MacroSyntax, ParserError> parse_macro(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_macro_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "macro"));
        if (!success_macro_1) {
                return Result<MacroSyntax, ParserError> { ._tag = Result<MacroSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto name = this->lexer.parse_identifier(_r, _rp, this->keywords);
        if (name != nullptr) {
            if (!this->is_identifier(*name)) {
            return Result<MacroSyntax, ParserError> { ._tag = Result<MacroSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
            }
        }
        else {
            return Result<MacroSyntax, ParserError> { ._tag = Result<MacroSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto model_result = this->parse_model(_r, _rp, _ep);
        if (model_result._tag == Result<ModelSyntax, ParserError>::Error)
        {
            if (model_result._Error._tag == ParserError::OtherSyntax)
               return Result<MacroSyntax, ParserError> { ._tag = Result<MacroSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto model = model_result._Ok;

        auto rule_result = this->parse_operation(_r, _rp, _ep);
        if (rule_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (rule_result._Error._tag == ParserError::OtherSyntax)
               return Result<MacroSyntax, ParserError> { ._tag = Result<MacroSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto rule = rule_result._Ok;

        auto end = this->lexer.position;

        auto ret = MacroSyntax(start, end, *name, model, rule);

        return Result<MacroSyntax, ParserError> { ._tag = Result<MacroSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ModuleSyntax, ParserError> parse_module(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_module_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "module"));
        if (!success_module_1) {
                return Result<ModuleSyntax, ParserError> { ._tag = Result<ModuleSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto name_result = this->parse_name(_r, _rp, _ep);
        if (name_result._tag == Result<NameSyntax, ParserError>::Error)
        {
            if (name_result._Error._tag == ParserError::OtherSyntax)
               return Result<ModuleSyntax, ParserError> { ._tag = Result<ModuleSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto name = name_result._Ok;

        auto success_colon_3 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_3) {
        }

        auto end = this->lexer.position;

        auto ret = ModuleSyntax(start, end, name);

        return Result<ModuleSyntax, ParserError> { ._tag = Result<ModuleSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ModelSyntax, ParserError> parse_model(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            auto node_result = this->parse_literal(_r_1, _rp, _ep);
            if (node_result._tag == Result<LiteralSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ModelSyntax, ParserError> { ._tag = Result<ModelSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ModelSyntax, ParserError> { ._tag = Result<ModelSyntax, ParserError>::Ok, ._Ok = 
                    ModelSyntax(LiteralSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_name(_r_1, _rp, _ep);
            if (node_result._tag == Result<NameSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ModelSyntax, ParserError> { ._tag = Result<ModelSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ModelSyntax, ParserError> { ._tag = Result<ModelSyntax, ParserError>::Ok, ._Ok = 
                    ModelSyntax(NameSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_object(_r_1, _rp, _ep);
            if (node_result._tag == Result<ObjectSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ModelSyntax, ParserError> { ._tag = Result<ModelSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ModelSyntax, ParserError> { ._tag = Result<ModelSyntax, ParserError>::Ok, ._Ok = 
                    ModelSyntax(ObjectSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_vector(_r_1, _rp, _ep);
            if (node_result._tag == Result<VectorSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ModelSyntax, ParserError> { ._tag = Result<ModelSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ModelSyntax, ParserError> { ._tag = Result<ModelSyntax, ParserError>::Ok, ._Ok = 
                    ModelSyntax(VectorSyntax(node))
                };
            }
        }
        return Result<ModelSyntax, ParserError> { ._tag = Result<ModelSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
    }

    Result<Vector<StatementSyntax>*, ParserError> parse_statement_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<StatementSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_statement(_r_1, _rp, _ep);
                if ((node_result._tag == Result<StatementSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<StatementSyntax>*, ParserError> { ._tag = Result<Vector<StatementSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<StatementSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<StatementSyntax>), _r_1.page) Array<StatementSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<StatementSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<StatementSyntax>*, ParserError> { ._tag = Result<Vector<StatementSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<StatementSyntax>*, ParserError> { ._tag = Result<Vector<StatementSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<StatementSyntax>*, ParserError> {
                ._tag = Result<Vector<StatementSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<StatementSyntax>), _rp) Vector<StatementSyntax>(_rp, *array) };
        }
    }

    Result<StatementSyntax, ParserError> parse_statement(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            auto node_result = this->parse_operation(_r_1, _rp, _ep);
            if (node_result._tag == Result<OperationSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<StatementSyntax, ParserError> { ._tag = Result<StatementSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<StatementSyntax, ParserError> { ._tag = Result<StatementSyntax, ParserError>::Ok, ._Ok = 
                    StatementSyntax(OperationSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_let(_r_1, _rp, _ep);
            if (node_result._tag == Result<LetSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<StatementSyntax, ParserError> { ._tag = Result<StatementSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<StatementSyntax, ParserError> { ._tag = Result<StatementSyntax, ParserError>::Ok, ._Ok = 
                    StatementSyntax(LetSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_var(_r_1, _rp, _ep);
            if (node_result._tag == Result<VarSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<StatementSyntax, ParserError> { ._tag = Result<StatementSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<StatementSyntax, ParserError> { ._tag = Result<StatementSyntax, ParserError>::Ok, ._Ok = 
                    StatementSyntax(VarSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_mutable(_r_1, _rp, _ep);
            if (node_result._tag == Result<MutableSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<StatementSyntax, ParserError> { ._tag = Result<StatementSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<StatementSyntax, ParserError> { ._tag = Result<StatementSyntax, ParserError>::Ok, ._Ok = 
                    StatementSyntax(MutableSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_set(_r_1, _rp, _ep);
            if (node_result._tag == Result<SetSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<StatementSyntax, ParserError> { ._tag = Result<StatementSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<StatementSyntax, ParserError> { ._tag = Result<StatementSyntax, ParserError>::Ok, ._Ok = 
                    StatementSyntax(SetSyntax(node))
                };
            }
        }
        return Result<StatementSyntax, ParserError> { ._tag = Result<StatementSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
    }

    Result<LetSyntax, ParserError> parse_let(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_let_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "let"));
        if (!success_let_1) {
                return Result<LetSyntax, ParserError> { ._tag = Result<LetSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto binding_result = this->parse_binding(_r, _rp, _ep);
        if (binding_result._tag == Result<BindingSyntax, ParserError>::Error)
        {
            if (binding_result._Error._tag == ParserError::OtherSyntax)
               return Result<LetSyntax, ParserError> { ._tag = Result<LetSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto binding = binding_result._Ok;

        auto end = this->lexer.position;

        auto ret = LetSyntax(start, end, binding);

        return Result<LetSyntax, ParserError> { ._tag = Result<LetSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<VarSyntax, ParserError> parse_var(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_var_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "var"));
        if (!success_var_1) {
                return Result<VarSyntax, ParserError> { ._tag = Result<VarSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto binding_result = this->parse_binding(_r, _rp, _ep);
        if (binding_result._tag == Result<BindingSyntax, ParserError>::Error)
        {
            if (binding_result._Error._tag == ParserError::OtherSyntax)
               return Result<VarSyntax, ParserError> { ._tag = Result<VarSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto binding = binding_result._Ok;

        auto end = this->lexer.position;

        auto ret = VarSyntax(start, end, binding);

        return Result<VarSyntax, ParserError> { ._tag = Result<VarSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<MutableSyntax, ParserError> parse_mutable(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_mutable_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "mutable"));
        if (!success_mutable_1) {
                return Result<MutableSyntax, ParserError> { ._tag = Result<MutableSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto binding_result = this->parse_binding(_r, _rp, _ep);
        if (binding_result._tag == Result<BindingSyntax, ParserError>::Error)
        {
            if (binding_result._Error._tag == ParserError::OtherSyntax)
               return Result<MutableSyntax, ParserError> { ._tag = Result<MutableSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto binding = binding_result._Ok;

        auto end = this->lexer.position;

        auto ret = MutableSyntax(start, end, binding);

        return Result<MutableSyntax, ParserError> { ._tag = Result<MutableSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<BindingSyntax, ParserError> parse_binding(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto name = this->lexer.parse_identifier(_r, _rp, this->keywords);
        if (name != nullptr) {
            if (!this->is_identifier(*name)) {
                return Result<BindingSyntax, ParserError> { ._tag = Result<BindingSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };

            }
        }
        else {
                return Result<BindingSyntax, ParserError> { ._tag = Result<BindingSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };

        }

        auto annotation_result = this->parse_bindingannotation(_r, _rp, _ep);
        if (annotation_result._tag == Result<BindingAnnotationSyntax, ParserError>::Error)
        {
        }

        BindingAnnotationSyntax* annotation = annotation_result._tag == Result<BindingAnnotationSyntax, ParserError>::Error ? nullptr : new(alignof(BindingAnnotationSyntax), _rp) BindingAnnotationSyntax(annotation_result._Ok);

        auto operation_result = this->parse_operation(_r, _rp, _ep);
        if (operation_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (operation_result._Error._tag == ParserError::OtherSyntax)
               return Result<BindingSyntax, ParserError> { ._tag = Result<BindingSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto operation = operation_result._Ok;

        auto end = this->lexer.position;

        auto ret = BindingSyntax(start, end, *name, annotation, operation);

        return Result<BindingSyntax, ParserError> { ._tag = Result<BindingSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<BindingAnnotationSyntax, ParserError> parse_bindingannotation(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_colon_1 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_1) {
                return Result<BindingAnnotationSyntax, ParserError> { ._tag = Result<BindingAnnotationSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto spec_result = this->parse_bindingspec(_r, _rp, _ep);
        if (spec_result._tag == Result<BindingSpecSyntax, ParserError>::Error)
        {
            if (spec_result._Error._tag == ParserError::OtherSyntax)
               return Result<BindingAnnotationSyntax, ParserError> { ._tag = Result<BindingAnnotationSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto spec = spec_result._Ok;

        auto end = this->lexer.position;

        auto ret = BindingAnnotationSyntax(start, end, spec);

        return Result<BindingAnnotationSyntax, ParserError> { ._tag = Result<BindingAnnotationSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<BindingSpecSyntax>*, ParserError> parse_bindingspec_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<BindingSpecSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_bindingspec(_r_1, _rp, _ep);
                if ((node_result._tag == Result<BindingSpecSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<BindingSpecSyntax>*, ParserError> { ._tag = Result<Vector<BindingSpecSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<BindingSpecSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<BindingSpecSyntax>), _r_1.page) Array<BindingSpecSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<BindingSpecSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<BindingSpecSyntax>*, ParserError> { ._tag = Result<Vector<BindingSpecSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<BindingSpecSyntax>*, ParserError> { ._tag = Result<Vector<BindingSpecSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<BindingSpecSyntax>*, ParserError> {
                ._tag = Result<Vector<BindingSpecSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<BindingSpecSyntax>), _rp) Vector<BindingSpecSyntax>(_rp, *array) };
        }
    }

    Result<BindingSpecSyntax, ParserError> parse_bindingspec(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            auto node_result = this->parse_structure(_r_1, _rp, _ep);
            if (node_result._tag == Result<StructureSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<BindingSpecSyntax, ParserError> { ._tag = Result<BindingSpecSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<BindingSpecSyntax, ParserError> { ._tag = Result<BindingSpecSyntax, ParserError>::Ok, ._Ok = 
                    BindingSpecSyntax(StructureSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_type(_r_1, _rp, _ep);
            if (node_result._tag == Result<TypeSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<BindingSpecSyntax, ParserError> { ._tag = Result<BindingSpecSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<BindingSpecSyntax, ParserError> { ._tag = Result<BindingSpecSyntax, ParserError>::Ok, ._Ok = 
                    BindingSpecSyntax(TypeSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_array(_r_1, _rp, _ep);
            if (node_result._tag == Result<ArraySyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<BindingSpecSyntax, ParserError> { ._tag = Result<BindingSpecSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<BindingSpecSyntax, ParserError> { ._tag = Result<BindingSpecSyntax, ParserError>::Ok, ._Ok = 
                    BindingSpecSyntax(ArraySyntax(node))
                };
            }
        }
        return Result<BindingSpecSyntax, ParserError> { ._tag = Result<BindingSpecSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
    }

    Result<ArraySyntax, ParserError> parse_array(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_left_bracket_1 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "["));
        if (!success_left_bracket_1) {
                return Result<ArraySyntax, ParserError> { ._tag = Result<ArraySyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto members_result = this->parse_type_list(_r, _rp, _ep);
        if (members_result._tag == Result<Vector<TypeSyntax>, ParserError>::Error)
        {
        }

        auto members = members_result._tag == Result<Vector<TypeSyntax>, ParserError>::Error ? nullptr : members_result._Ok;

        auto success_right_bracket_3 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "]"));
        if (!success_right_bracket_3) {
            return Result<ArraySyntax, ParserError> { ._tag = Result<ArraySyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };        }

        auto end = this->lexer.position;

        auto ret = ArraySyntax(start, end, members);

        return Result<ArraySyntax, ParserError> { ._tag = Result<ArraySyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<StructureSyntax, ParserError> parse_structure(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_left_paren_1 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "("));
        if (!success_left_paren_1) {
                return Result<StructureSyntax, ParserError> { ._tag = Result<StructureSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto members_result = this->parse_member_list(_r, _rp, _ep);
        if (members_result._tag == Result<Vector<MemberSyntax>, ParserError>::Error)
        {
        }

        auto members = members_result._tag == Result<Vector<MemberSyntax>, ParserError>::Error ? nullptr : members_result._Ok;

        auto success_right_paren_3 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, ")"));
        if (!success_right_paren_3) {
            return Result<StructureSyntax, ParserError> { ._tag = Result<StructureSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };        }

        auto end = this->lexer.position;

        auto ret = StructureSyntax(start, end, members);

        return Result<StructureSyntax, ParserError> { ._tag = Result<StructureSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<OperandSyntax>*, ParserError> parse_operand_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<OperandSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_operand(_r_1, _rp, _ep);
                if ((node_result._tag == Result<OperandSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<OperandSyntax>*, ParserError> { ._tag = Result<Vector<OperandSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<OperandSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<OperandSyntax>), _r_1.page) Array<OperandSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<OperandSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<OperandSyntax>*, ParserError> { ._tag = Result<Vector<OperandSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<OperandSyntax>*, ParserError> { ._tag = Result<Vector<OperandSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<OperandSyntax>*, ParserError> {
                ._tag = Result<Vector<OperandSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<OperandSyntax>), _rp) Vector<OperandSyntax>(_rp, *array) };
        }
    }

    Result<OperandSyntax, ParserError> parse_operand(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto expression_result = this->parse_expression(_r, _rp, _ep);
        if (expression_result._tag == Result<ExpressionSyntax, ParserError>::Error)
        {
            if (expression_result._Error._tag == ParserError::OtherSyntax)
               return Result<OperandSyntax, ParserError> { ._tag = Result<OperandSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto expression = expression_result._Ok;

        auto postfixes_result = this->parse_postfix_list(_r, _rp, _ep);
        if (postfixes_result._tag == Result<Vector<PostfixSyntax>, ParserError>::Error)
        {
        }

        auto postfixes = postfixes_result._tag == Result<Vector<PostfixSyntax>, ParserError>::Error ? nullptr : postfixes_result._Ok;

        auto end = this->lexer.position;

        auto ret = OperandSyntax(start, end, expression, postfixes);

        return Result<OperandSyntax, ParserError> { ._tag = Result<OperandSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<PostfixSyntax>*, ParserError> parse_postfix_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<PostfixSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_postfix(_r_1, _rp, _ep);
                if ((node_result._tag == Result<PostfixSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<PostfixSyntax>*, ParserError> { ._tag = Result<Vector<PostfixSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<PostfixSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<PostfixSyntax>), _r_1.page) Array<PostfixSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<PostfixSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<PostfixSyntax>*, ParserError> { ._tag = Result<Vector<PostfixSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<PostfixSyntax>*, ParserError> { ._tag = Result<Vector<PostfixSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<PostfixSyntax>*, ParserError> {
                ._tag = Result<Vector<PostfixSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<PostfixSyntax>), _rp) Vector<PostfixSyntax>(_rp, *array) };
        }
    }

    Result<PostfixSyntax, ParserError> parse_postfix(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            auto node_result = this->parse_memberaccess(_r_1, _rp, _ep);
            if (node_result._tag == Result<MemberAccessSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<PostfixSyntax, ParserError> { ._tag = Result<PostfixSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<PostfixSyntax, ParserError> { ._tag = Result<PostfixSyntax, ParserError>::Ok, ._Ok = 
                    PostfixSyntax(MemberAccessSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_catcher(_r_1, _rp, _ep);
            if (node_result._tag == Result<CatcherSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<PostfixSyntax, ParserError> { ._tag = Result<PostfixSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<PostfixSyntax, ParserError> { ._tag = Result<PostfixSyntax, ParserError>::Ok, ._Ok = 
                    PostfixSyntax(CatcherSyntax(node))
                };
            }
        }
        return Result<PostfixSyntax, ParserError> { ._tag = Result<PostfixSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
    }

    Result<MemberAccessSyntax, ParserError> parse_memberaccess(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_dot_1 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "."));
        if (!success_dot_1) {
                return Result<MemberAccessSyntax, ParserError> { ._tag = Result<MemberAccessSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto member_result = this->parse_name(_r, _rp, _ep);
        if (member_result._tag == Result<NameSyntax, ParserError>::Error)
        {
            if (member_result._Error._tag == ParserError::OtherSyntax)
               return Result<MemberAccessSyntax, ParserError> { ._tag = Result<MemberAccessSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto member = member_result._Ok;

        auto end = this->lexer.position;

        auto ret = MemberAccessSyntax(start, end, member);

        return Result<MemberAccessSyntax, ParserError> { ._tag = Result<MemberAccessSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<CatcherSyntax, ParserError> parse_catcher(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto catchers_result = this->parse_catch_list(_r, _rp, _ep);
        if (catchers_result._tag == Result<Vector<CatchSyntax>, ParserError>::Error)
        {
            if (catchers_result._Error._tag == ParserError::OtherSyntax)
               return Result<CatcherSyntax, ParserError> { ._tag = Result<CatcherSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto catchers = catchers_result._Ok;

        auto dropper_result = this->parse_drop(_r, _rp, _ep);
        if (dropper_result._tag == Result<DropSyntax, ParserError>::Error)
        {
        }

        DropSyntax* dropper = dropper_result._tag == Result<DropSyntax, ParserError>::Error ? nullptr : new(alignof(DropSyntax), _rp) DropSyntax(dropper_result._Ok);

        auto end = this->lexer.position;

        auto ret = CatcherSyntax(start, end, catchers, dropper);

        return Result<CatcherSyntax, ParserError> { ._tag = Result<CatcherSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<CatchSyntax>*, ParserError> parse_catch_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<CatchSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_catch(_r_1, _rp, _ep);
                if ((node_result._tag == Result<CatchSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<CatchSyntax>*, ParserError> { ._tag = Result<Vector<CatchSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<CatchSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<CatchSyntax>), _r_1.page) Array<CatchSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<CatchSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<CatchSyntax>*, ParserError> { ._tag = Result<Vector<CatchSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<CatchSyntax>*, ParserError> { ._tag = Result<Vector<CatchSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<CatchSyntax>*, ParserError> {
                ._tag = Result<Vector<CatchSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<CatchSyntax>), _rp) Vector<CatchSyntax>(_rp, *array) };
        }
    }

    Result<CatchSyntax, ParserError> parse_catch(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_catch_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "catch"));
        if (!success_catch_1) {
                return Result<CatchSyntax, ParserError> { ._tag = Result<CatchSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto condition_result = this->parse_operation(_r, _rp, _ep);
        if (condition_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (condition_result._Error._tag == ParserError::OtherSyntax)
               return Result<CatchSyntax, ParserError> { ._tag = Result<CatchSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto condition = condition_result._Ok;

        auto handler_result = this->parse_operation(_r, _rp, _ep);
        if (handler_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (handler_result._Error._tag == ParserError::OtherSyntax)
               return Result<CatchSyntax, ParserError> { ._tag = Result<CatchSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto handler = handler_result._Ok;

        auto end = this->lexer.position;

        auto ret = CatchSyntax(start, end, condition, handler);

        return Result<CatchSyntax, ParserError> { ._tag = Result<CatchSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<DropSyntax, ParserError> parse_drop(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_drop_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "drop"));
        if (!success_drop_1) {
                return Result<DropSyntax, ParserError> { ._tag = Result<DropSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto handler_result = this->parse_operation(_r, _rp, _ep);
        if (handler_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (handler_result._Error._tag == ParserError::OtherSyntax)
               return Result<DropSyntax, ParserError> { ._tag = Result<DropSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto handler = handler_result._Ok;

        auto end = this->lexer.position;

        auto ret = DropSyntax(start, end, handler);

        return Result<DropSyntax, ParserError> { ._tag = Result<DropSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ExpressionSyntax, ParserError> parse_expression(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            auto node_result = this->parse_literal(_r_1, _rp, _ep);
            if (node_result._tag == Result<LiteralSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Ok, ._Ok = 
                    ExpressionSyntax(LiteralSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_name(_r_1, _rp, _ep);
            if (node_result._tag == Result<NameSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Ok, ._Ok = 
                    ExpressionSyntax(NameSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_object(_r_1, _rp, _ep);
            if (node_result._tag == Result<ObjectSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Ok, ._Ok = 
                    ExpressionSyntax(ObjectSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_vector(_r_1, _rp, _ep);
            if (node_result._tag == Result<VectorSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Ok, ._Ok = 
                    ExpressionSyntax(VectorSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_block(_r_1, _rp, _ep);
            if (node_result._tag == Result<BlockSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Ok, ._Ok = 
                    ExpressionSyntax(BlockSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_if(_r_1, _rp, _ep);
            if (node_result._tag == Result<IfSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Ok, ._Ok = 
                    ExpressionSyntax(IfSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_match(_r_1, _rp, _ep);
            if (node_result._tag == Result<MatchSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Ok, ._Ok = 
                    ExpressionSyntax(MatchSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_lambda(_r_1, _rp, _ep);
            if (node_result._tag == Result<LambdaSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Ok, ._Ok = 
                    ExpressionSyntax(LambdaSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_for(_r_1, _rp, _ep);
            if (node_result._tag == Result<ForSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Ok, ._Ok = 
                    ExpressionSyntax(ForSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_while(_r_1, _rp, _ep);
            if (node_result._tag == Result<WhileSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Ok, ._Ok = 
                    ExpressionSyntax(WhileSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_repeat(_r_1, _rp, _ep);
            if (node_result._tag == Result<RepeatSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Ok, ._Ok = 
                    ExpressionSyntax(RepeatSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_sizeof(_r_1, _rp, _ep);
            if (node_result._tag == Result<SizeOfSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Ok, ._Ok = 
                    ExpressionSyntax(SizeOfSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_continue(_r_1, _rp, _ep);
            if (node_result._tag == Result<ContinueSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Ok, ._Ok = 
                    ExpressionSyntax(ContinueSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_break(_r_1, _rp, _ep);
            if (node_result._tag == Result<BreakSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Ok, ._Ok = 
                    ExpressionSyntax(BreakSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_return(_r_1, _rp, _ep);
            if (node_result._tag == Result<ReturnSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Ok, ._Ok = 
                    ExpressionSyntax(ReturnSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_throw(_r_1, _rp, _ep);
            if (node_result._tag == Result<ThrowSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Ok, ._Ok = 
                    ExpressionSyntax(ThrowSyntax(node))
                };
            }
        }
        return Result<ExpressionSyntax, ParserError> { ._tag = Result<ExpressionSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
    }

    Result<ContinueSyntax, ParserError> parse_continue(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_continue_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "continue"));
        if (!success_continue_1) {
                return Result<ContinueSyntax, ParserError> { ._tag = Result<ContinueSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto name_result = this->parse_loop(_r, _rp, _ep);
        if (name_result._tag == Result<LoopSyntax, ParserError>::Error)
        {
        }

        LoopSyntax* name = name_result._tag == Result<LoopSyntax, ParserError>::Error ? nullptr : new(alignof(LoopSyntax), _rp) LoopSyntax(name_result._Ok);

        auto success_colon_3 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_3) {
        }

        auto end = this->lexer.position;

        auto ret = ContinueSyntax(start, end, name);

        return Result<ContinueSyntax, ParserError> { ._tag = Result<ContinueSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<BreakSyntax, ParserError> parse_break(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_break_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "break"));
        if (!success_break_1) {
                return Result<BreakSyntax, ParserError> { ._tag = Result<BreakSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto name_result = this->parse_loop(_r, _rp, _ep);
        if (name_result._tag == Result<LoopSyntax, ParserError>::Error)
        {
        }

        LoopSyntax* name = name_result._tag == Result<LoopSyntax, ParserError>::Error ? nullptr : new(alignof(LoopSyntax), _rp) LoopSyntax(name_result._Ok);

        auto result_result = this->parse_operation(_r, _rp, _ep);
        if (result_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
        }

        OperationSyntax* result = result_result._tag == Result<OperationSyntax, ParserError>::Error ? nullptr : new(alignof(OperationSyntax), _rp) OperationSyntax(result_result._Ok);

        auto success_colon_4 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_4) {
        }

        auto end = this->lexer.position;

        auto ret = BreakSyntax(start, end, name, result);

        return Result<BreakSyntax, ParserError> { ._tag = Result<BreakSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<LoopSyntax, ParserError> parse_loop(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_loop_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "loop"));
        if (!success_loop_1) {
                return Result<LoopSyntax, ParserError> { ._tag = Result<LoopSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto name = this->lexer.parse_identifier(_r, _rp, this->keywords);
        if (name != nullptr) {
            if (!this->is_identifier(*name)) {
            return Result<LoopSyntax, ParserError> { ._tag = Result<LoopSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
            }
        }
        else {
            return Result<LoopSyntax, ParserError> { ._tag = Result<LoopSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto end = this->lexer.position;

        auto ret = LoopSyntax(start, end, *name);

        return Result<LoopSyntax, ParserError> { ._tag = Result<LoopSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ReturnSyntax, ParserError> parse_return(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_return_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "return"));
        if (!success_return_1) {
                return Result<ReturnSyntax, ParserError> { ._tag = Result<ReturnSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto result_result = this->parse_operation(_r, _rp, _ep);
        if (result_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
        }

        OperationSyntax* result = result_result._tag == Result<OperationSyntax, ParserError>::Error ? nullptr : new(alignof(OperationSyntax), _rp) OperationSyntax(result_result._Ok);

        auto end = this->lexer.position;

        auto ret = ReturnSyntax(start, end, result);

        return Result<ReturnSyntax, ParserError> { ._tag = Result<ReturnSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ThrowSyntax, ParserError> parse_throw(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_throw_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "throw"));
        if (!success_throw_1) {
                return Result<ThrowSyntax, ParserError> { ._tag = Result<ThrowSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto result_result = this->parse_operation(_r, _rp, _ep);
        if (result_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
        }

        OperationSyntax* result = result_result._tag == Result<OperationSyntax, ParserError>::Error ? nullptr : new(alignof(OperationSyntax), _rp) OperationSyntax(result_result._Ok);

        auto end = this->lexer.position;

        auto ret = ThrowSyntax(start, end, result);

        return Result<ThrowSyntax, ParserError> { ._tag = Result<ThrowSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<LiteralSyntax, ParserError> parse_literal(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto literal_result = this->parse_literal_token(_r, _rp);
        if (literal_result._tag == Result<Literal, ParserError>::Error)
        {
            if (literal_result._Error._tag == ParserError::OtherSyntax)
               return Result<LiteralSyntax, ParserError> { ._tag = Result<LiteralSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto literal = literal_result._Ok;

        auto end = this->lexer.position;

        auto ret = LiteralSyntax(start, end, literal);

        return Result<LiteralSyntax, ParserError> { ._tag = Result<LiteralSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ObjectSyntax, ParserError> parse_object(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_left_paren_1 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "("));
        if (!success_left_paren_1) {
                return Result<ObjectSyntax, ParserError> { ._tag = Result<ObjectSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto components_result = this->parse_component_list(_r, _rp, _ep);
        if (components_result._tag == Result<Vector<ComponentSyntax>, ParserError>::Error)
        {
        }

        auto components = components_result._tag == Result<Vector<ComponentSyntax>, ParserError>::Error ? nullptr : components_result._Ok;

        auto success_right_paren_3 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, ")"));
        if (!success_right_paren_3) {
            return Result<ObjectSyntax, ParserError> { ._tag = Result<ObjectSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };        }

        auto end = this->lexer.position;

        auto ret = ObjectSyntax(start, end, components);

        return Result<ObjectSyntax, ParserError> { ._tag = Result<ObjectSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<ComponentSyntax>*, ParserError> parse_component_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<ComponentSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_component(_r_1, _rp, _ep);
                if ((node_result._tag == Result<ComponentSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<ComponentSyntax>*, ParserError> { ._tag = Result<Vector<ComponentSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<ComponentSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<ComponentSyntax>), _r_1.page) Array<ComponentSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<ComponentSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<ComponentSyntax>*, ParserError> { ._tag = Result<Vector<ComponentSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<ComponentSyntax>*, ParserError> { ._tag = Result<Vector<ComponentSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<ComponentSyntax>*, ParserError> {
                ._tag = Result<Vector<ComponentSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<ComponentSyntax>), _rp) Vector<ComponentSyntax>(_rp, *array) };
        }
    }

    Result<ComponentSyntax, ParserError> parse_component(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto operands_result = this->parse_operand_list(_r, _rp, _ep);
        if (operands_result._tag == Result<Vector<OperandSyntax>, ParserError>::Error)
        {
            if (operands_result._Error._tag == ParserError::OtherSyntax)
               return Result<ComponentSyntax, ParserError> { ._tag = Result<ComponentSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto operands = operands_result._Ok;

        auto attributes_result = this->parse_attribute_list(_r, _rp, _ep);
        if (attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error)
        {
        }

        auto attributes = attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error ? nullptr : attributes_result._Ok;

        auto value_result = this->parse_value(_r, _rp, _ep);
        if (value_result._tag == Result<ValueSyntax, ParserError>::Error)
        {
        }

        ValueSyntax* value = value_result._tag == Result<ValueSyntax, ParserError>::Error ? nullptr : new(alignof(ValueSyntax), _rp) ValueSyntax(value_result._Ok);

        auto success_comma_4 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, ","));
        if (!success_comma_4) {
        }

        auto end = this->lexer.position;

        auto ret = ComponentSyntax(start, end, operands, attributes, value);

        return Result<ComponentSyntax, ParserError> { ._tag = Result<ComponentSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ValueSyntax, ParserError> parse_value(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_colon_1 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_1) {
                return Result<ValueSyntax, ParserError> { ._tag = Result<ValueSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto value_result = this->parse_operation(_r, _rp, _ep);
        if (value_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (value_result._Error._tag == ParserError::OtherSyntax)
               return Result<ValueSyntax, ParserError> { ._tag = Result<ValueSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto value = value_result._Ok;

        auto attributes_result = this->parse_attribute_list(_r, _rp, _ep);
        if (attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error)
        {
        }

        auto attributes = attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error ? nullptr : attributes_result._Ok;

        auto end = this->lexer.position;

        auto ret = ValueSyntax(start, end, value, attributes);

        return Result<ValueSyntax, ParserError> { ._tag = Result<ValueSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<VectorSyntax, ParserError> parse_vector(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_left_bracket_1 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "["));
        if (!success_left_bracket_1) {
                return Result<VectorSyntax, ParserError> { ._tag = Result<VectorSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto elements_result = this->parse_element_list(_r, _rp, _ep);
        if (elements_result._tag == Result<Vector<ElementSyntax>, ParserError>::Error)
        {
            if (elements_result._Error._tag == ParserError::OtherSyntax)
               return Result<VectorSyntax, ParserError> { ._tag = Result<VectorSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto elements = elements_result._Ok;

        auto success_right_bracket_3 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "]"));
        if (!success_right_bracket_3) {
            return Result<VectorSyntax, ParserError> { ._tag = Result<VectorSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };        }

        auto end = this->lexer.position;

        auto ret = VectorSyntax(start, end, elements);

        return Result<VectorSyntax, ParserError> { ._tag = Result<VectorSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<ElementSyntax>*, ParserError> parse_element_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<ElementSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_element(_r_1, _rp, _ep);
                if ((node_result._tag == Result<ElementSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<ElementSyntax>*, ParserError> { ._tag = Result<Vector<ElementSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<ElementSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<ElementSyntax>), _r_1.page) Array<ElementSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<ElementSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<ElementSyntax>*, ParserError> { ._tag = Result<Vector<ElementSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<ElementSyntax>*, ParserError> { ._tag = Result<Vector<ElementSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<ElementSyntax>*, ParserError> {
                ._tag = Result<Vector<ElementSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<ElementSyntax>), _rp) Vector<ElementSyntax>(_rp, *array) };
        }
    }

    Result<ElementSyntax, ParserError> parse_element(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto operation_result = this->parse_operation(_r, _rp, _ep);
        if (operation_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (operation_result._Error._tag == ParserError::OtherSyntax)
               return Result<ElementSyntax, ParserError> { ._tag = Result<ElementSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto operation = operation_result._Ok;

        auto attributes_result = this->parse_attribute_list(_r, _rp, _ep);
        if (attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error)
        {
        }

        auto attributes = attributes_result._tag == Result<Vector<AttributeSyntax>, ParserError>::Error ? nullptr : attributes_result._Ok;

        auto success_comma_3 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, ","));
        if (!success_comma_3) {
        }

        auto end = this->lexer.position;

        auto ret = ElementSyntax(start, end, operation, attributes);

        return Result<ElementSyntax, ParserError> { ._tag = Result<ElementSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<BlockSyntax, ParserError> parse_block(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_left_curly_1 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "{"));
        if (!success_left_curly_1) {
                return Result<BlockSyntax, ParserError> { ._tag = Result<BlockSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto uses_result = this->parse_use_list(_r, _rp, _ep);
        if (uses_result._tag == Result<Vector<UseSyntax>, ParserError>::Error)
        {
        }

        auto uses = uses_result._tag == Result<Vector<UseSyntax>, ParserError>::Error ? nullptr : uses_result._Ok;

        auto statements_result = this->parse_statement_list(_r, _rp, _ep);
        if (statements_result._tag == Result<Vector<StatementSyntax>, ParserError>::Error)
        {
        }

        auto statements = statements_result._tag == Result<Vector<StatementSyntax>, ParserError>::Error ? nullptr : statements_result._Ok;

        auto success_right_curly_4 = this->lexer.parse_punctuation(_r, _rp, String(_r.page, "}"));
        if (!success_right_curly_4) {
            return Result<BlockSyntax, ParserError> { ._tag = Result<BlockSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };        }

        auto end = this->lexer.position;

        auto ret = BlockSyntax(start, end, uses, statements);

        return Result<BlockSyntax, ParserError> { ._tag = Result<BlockSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<IfSyntax, ParserError> parse_if(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_if_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "if"));
        if (!success_if_1) {
                return Result<IfSyntax, ParserError> { ._tag = Result<IfSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto condition_result = this->parse_operation(_r, _rp, _ep);
        if (condition_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (condition_result._Error._tag == ParserError::OtherSyntax)
               return Result<IfSyntax, ParserError> { ._tag = Result<IfSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto condition = condition_result._Ok;

        auto match_result = this->parse_is(_r, _rp, _ep);
        if (match_result._tag == Result<IsSyntax, ParserError>::Error)
        {
        }

        IsSyntax* match = match_result._tag == Result<IsSyntax, ParserError>::Error ? nullptr : new(alignof(IsSyntax), _rp) IsSyntax(match_result._Ok);

        auto alias_result = this->parse_as(_r, _rp, _ep);
        if (alias_result._tag == Result<AsSyntax, ParserError>::Error)
        {
        }

        AsSyntax* alias = alias_result._tag == Result<AsSyntax, ParserError>::Error ? nullptr : new(alignof(AsSyntax), _rp) AsSyntax(alias_result._Ok);

        auto consequent_result = this->parse_action(_r, _rp, _ep);
        if (consequent_result._tag == Result<ActionSyntax, ParserError>::Error)
        {
            if (consequent_result._Error._tag == ParserError::OtherSyntax)
               return Result<IfSyntax, ParserError> { ._tag = Result<IfSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto consequent = consequent_result._Ok;

        auto alternative_result = this->parse_else(_r, _rp, _ep);
        if (alternative_result._tag == Result<ElseSyntax, ParserError>::Error)
        {
        }

        ElseSyntax* alternative = alternative_result._tag == Result<ElseSyntax, ParserError>::Error ? nullptr : new(alignof(ElseSyntax), _rp) ElseSyntax(alternative_result._Ok);

        auto end = this->lexer.position;

        auto ret = IfSyntax(start, end, condition, match, alias, consequent, alternative);

        return Result<IfSyntax, ParserError> { ._tag = Result<IfSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<IsSyntax, ParserError> parse_is(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_is_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "is"));
        if (!success_is_1) {
                return Result<IsSyntax, ParserError> { ._tag = Result<IsSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto type_result = this->parse_type(_r, _rp, _ep);
        if (type_result._tag == Result<TypeSyntax, ParserError>::Error)
        {
            if (type_result._Error._tag == ParserError::OtherSyntax)
               return Result<IsSyntax, ParserError> { ._tag = Result<IsSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto type = type_result._Ok;

        auto end = this->lexer.position;

        auto ret = IsSyntax(start, end, type);

        return Result<IsSyntax, ParserError> { ._tag = Result<IsSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<AsSyntax, ParserError> parse_as(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_as_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "as"));
        if (!success_as_1) {
                return Result<AsSyntax, ParserError> { ._tag = Result<AsSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto name = this->lexer.parse_identifier(_r, _rp, this->keywords);
        if (name != nullptr) {
            if (!this->is_identifier(*name)) {
            return Result<AsSyntax, ParserError> { ._tag = Result<AsSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
            }
        }
        else {
            return Result<AsSyntax, ParserError> { ._tag = Result<AsSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto success_colon_3 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_3) {
        }

        auto end = this->lexer.position;

        auto ret = AsSyntax(start, end, *name);

        return Result<AsSyntax, ParserError> { ._tag = Result<AsSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ElseSyntax, ParserError> parse_else(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_else_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "else"));
        if (!success_else_1) {
                return Result<ElseSyntax, ParserError> { ._tag = Result<ElseSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto success_colon_2 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_2) {
        }

        auto alternative_result = this->parse_action(_r, _rp, _ep);
        if (alternative_result._tag == Result<ActionSyntax, ParserError>::Error)
        {
            if (alternative_result._Error._tag == ParserError::OtherSyntax)
               return Result<ElseSyntax, ParserError> { ._tag = Result<ElseSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto alternative = alternative_result._Ok;

        auto end = this->lexer.position;

        auto ret = ElseSyntax(start, end, alternative);

        return Result<ElseSyntax, ParserError> { ._tag = Result<ElseSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<MatchSyntax, ParserError> parse_match(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_match_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "match"));
        if (!success_match_1) {
                return Result<MatchSyntax, ParserError> { ._tag = Result<MatchSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto scrutinee_result = this->parse_operation(_r, _rp, _ep);
        if (scrutinee_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (scrutinee_result._Error._tag == ParserError::OtherSyntax)
               return Result<MatchSyntax, ParserError> { ._tag = Result<MatchSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto scrutinee = scrutinee_result._Ok;

        auto cases_result = this->parse_case_list(_r, _rp, _ep);
        if (cases_result._tag == Result<Vector<CaseSyntax>, ParserError>::Error)
        {
            if (cases_result._Error._tag == ParserError::OtherSyntax)
               return Result<MatchSyntax, ParserError> { ._tag = Result<MatchSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto cases = cases_result._Ok;

        auto alternative_result = this->parse_default(_r, _rp, _ep);
        if (alternative_result._tag == Result<DefaultSyntax, ParserError>::Error)
        {
        }

        DefaultSyntax* alternative = alternative_result._tag == Result<DefaultSyntax, ParserError>::Error ? nullptr : new(alignof(DefaultSyntax), _rp) DefaultSyntax(alternative_result._Ok);

        auto end = this->lexer.position;

        auto ret = MatchSyntax(start, end, scrutinee, cases, alternative);

        return Result<MatchSyntax, ParserError> { ._tag = Result<MatchSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<CaseSyntax>*, ParserError> parse_case_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<CaseSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_case(_r_1, _rp, _ep);
                if ((node_result._tag == Result<CaseSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<CaseSyntax>*, ParserError> { ._tag = Result<Vector<CaseSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<CaseSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<CaseSyntax>), _r_1.page) Array<CaseSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<CaseSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<CaseSyntax>*, ParserError> { ._tag = Result<Vector<CaseSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<CaseSyntax>*, ParserError> { ._tag = Result<Vector<CaseSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<CaseSyntax>*, ParserError> {
                ._tag = Result<Vector<CaseSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<CaseSyntax>), _rp) Vector<CaseSyntax>(_rp, *array) };
        }
    }

    Result<CaseSyntax, ParserError> parse_case(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_case_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "case"));
        if (!success_case_1) {
                return Result<CaseSyntax, ParserError> { ._tag = Result<CaseSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto condition_result = this->parse_operation(_r, _rp, _ep);
        if (condition_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (condition_result._Error._tag == ParserError::OtherSyntax)
               return Result<CaseSyntax, ParserError> { ._tag = Result<CaseSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto condition = condition_result._Ok;

        auto consequent_result = this->parse_action(_r, _rp, _ep);
        if (consequent_result._tag == Result<ActionSyntax, ParserError>::Error)
        {
            if (consequent_result._Error._tag == ParserError::OtherSyntax)
               return Result<CaseSyntax, ParserError> { ._tag = Result<CaseSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto consequent = consequent_result._Ok;

        auto end = this->lexer.position;

        auto ret = CaseSyntax(start, end, condition, consequent);

        return Result<CaseSyntax, ParserError> { ._tag = Result<CaseSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<DefaultSyntax, ParserError> parse_default(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_default_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "default"));
        if (!success_default_1) {
                return Result<DefaultSyntax, ParserError> { ._tag = Result<DefaultSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto alternative_result = this->parse_action(_r, _rp, _ep);
        if (alternative_result._tag == Result<ActionSyntax, ParserError>::Error)
        {
        }

        ActionSyntax* alternative = alternative_result._tag == Result<ActionSyntax, ParserError>::Error ? nullptr : new(alignof(ActionSyntax), _rp) ActionSyntax(alternative_result._Ok);

        auto end = this->lexer.position;

        auto ret = DefaultSyntax(start, end, alternative);

        return Result<DefaultSyntax, ParserError> { ._tag = Result<DefaultSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<LambdaSyntax, ParserError> parse_lambda(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_lambda_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "lambda"));
        if (!success_lambda_1) {
                return Result<LambdaSyntax, ParserError> { ._tag = Result<LambdaSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto input_result = this->parse_operation(_r, _rp, _ep);
        if (input_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (input_result._Error._tag == ParserError::OtherSyntax)
               return Result<LambdaSyntax, ParserError> { ._tag = Result<LambdaSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto input = input_result._Ok;

        auto success_colon_3 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_3) {
            return Result<LambdaSyntax, ParserError> { ._tag = Result<LambdaSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };        }

        auto block_result = this->parse_action(_r, _rp, _ep);
        if (block_result._tag == Result<ActionSyntax, ParserError>::Error)
        {
            if (block_result._Error._tag == ParserError::OtherSyntax)
               return Result<LambdaSyntax, ParserError> { ._tag = Result<LambdaSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto block = block_result._Ok;

        auto end = this->lexer.position;

        auto ret = LambdaSyntax(start, end, input, block);

        return Result<LambdaSyntax, ParserError> { ._tag = Result<LambdaSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<ForSyntax, ParserError> parse_for(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_for_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "for"));
        if (!success_for_1) {
                return Result<ForSyntax, ParserError> { ._tag = Result<ForSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto condition_result = this->parse_operation(_r, _rp, _ep);
        if (condition_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (condition_result._Error._tag == ParserError::OtherSyntax)
               return Result<ForSyntax, ParserError> { ._tag = Result<ForSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto condition = condition_result._Ok;

        auto success_in_3 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "in"));
        if (!success_in_3) {
            return Result<ForSyntax, ParserError> { ._tag = Result<ForSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };        }

        auto expression_result = this->parse_operation(_r, _rp, _ep);
        if (expression_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (expression_result._Error._tag == ParserError::OtherSyntax)
               return Result<ForSyntax, ParserError> { ._tag = Result<ForSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto expression = expression_result._Ok;

        auto name_result = this->parse_label(_r, _rp, _ep);
        if (name_result._tag == Result<LabelSyntax, ParserError>::Error)
        {
        }

        LabelSyntax* name = name_result._tag == Result<LabelSyntax, ParserError>::Error ? nullptr : new(alignof(LabelSyntax), _rp) LabelSyntax(name_result._Ok);

        auto action_result = this->parse_action(_r, _rp, _ep);
        if (action_result._tag == Result<ActionSyntax, ParserError>::Error)
        {
            if (action_result._Error._tag == ParserError::OtherSyntax)
               return Result<ForSyntax, ParserError> { ._tag = Result<ForSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto action = action_result._Ok;

        auto end = this->lexer.position;

        auto ret = ForSyntax(start, end, condition, expression, name, action);

        return Result<ForSyntax, ParserError> { ._tag = Result<ForSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<LabelSyntax, ParserError> parse_label(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_label_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "label"));
        if (!success_label_1) {
                return Result<LabelSyntax, ParserError> { ._tag = Result<LabelSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto name = this->lexer.parse_identifier(_r, _rp, this->keywords);
        if (name != nullptr) {
            if (!this->is_identifier(*name)) {
            return Result<LabelSyntax, ParserError> { ._tag = Result<LabelSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
            }
        }
        else {
            return Result<LabelSyntax, ParserError> { ._tag = Result<LabelSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto end = this->lexer.position;

        auto ret = LabelSyntax(start, end, *name);

        return Result<LabelSyntax, ParserError> { ._tag = Result<LabelSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<WhileSyntax, ParserError> parse_while(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_while_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "while"));
        if (!success_while_1) {
                return Result<WhileSyntax, ParserError> { ._tag = Result<WhileSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto condition_result = this->parse_operation(_r, _rp, _ep);
        if (condition_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (condition_result._Error._tag == ParserError::OtherSyntax)
               return Result<WhileSyntax, ParserError> { ._tag = Result<WhileSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto condition = condition_result._Ok;

        auto name_result = this->parse_label(_r, _rp, _ep);
        if (name_result._tag == Result<LabelSyntax, ParserError>::Error)
        {
        }

        LabelSyntax* name = name_result._tag == Result<LabelSyntax, ParserError>::Error ? nullptr : new(alignof(LabelSyntax), _rp) LabelSyntax(name_result._Ok);

        auto action_result = this->parse_action(_r, _rp, _ep);
        if (action_result._tag == Result<ActionSyntax, ParserError>::Error)
        {
            if (action_result._Error._tag == ParserError::OtherSyntax)
               return Result<WhileSyntax, ParserError> { ._tag = Result<WhileSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto action = action_result._Ok;

        auto end = this->lexer.position;

        auto ret = WhileSyntax(start, end, condition, name, action);

        return Result<WhileSyntax, ParserError> { ._tag = Result<WhileSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<RepeatSyntax, ParserError> parse_repeat(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_repeat_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "repeat"));
        if (!success_repeat_1) {
                return Result<RepeatSyntax, ParserError> { ._tag = Result<RepeatSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto name_result = this->parse_label(_r, _rp, _ep);
        if (name_result._tag == Result<LabelSyntax, ParserError>::Error)
        {
        }

        LabelSyntax* name = name_result._tag == Result<LabelSyntax, ParserError>::Error ? nullptr : new(alignof(LabelSyntax), _rp) LabelSyntax(name_result._Ok);

        auto action_result = this->parse_action(_r, _rp, _ep);
        if (action_result._tag == Result<ActionSyntax, ParserError>::Error)
        {
            if (action_result._Error._tag == ParserError::OtherSyntax)
               return Result<RepeatSyntax, ParserError> { ._tag = Result<RepeatSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto action = action_result._Ok;

        auto end = this->lexer.position;

        auto ret = RepeatSyntax(start, end, name, action);

        return Result<RepeatSyntax, ParserError> { ._tag = Result<RepeatSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<ActionSyntax>*, ParserError> parse_action_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<ActionSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_action(_r_1, _rp, _ep);
                if ((node_result._tag == Result<ActionSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<ActionSyntax>*, ParserError> { ._tag = Result<Vector<ActionSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<ActionSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<ActionSyntax>), _r_1.page) Array<ActionSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<ActionSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<ActionSyntax>*, ParserError> { ._tag = Result<Vector<ActionSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<ActionSyntax>*, ParserError> { ._tag = Result<Vector<ActionSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<ActionSyntax>*, ParserError> {
                ._tag = Result<Vector<ActionSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<ActionSyntax>), _rp) Vector<ActionSyntax>(_rp, *array) };
        }
    }

    Result<ActionSyntax, ParserError> parse_action(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            auto node_result = this->parse_operation(_r_1, _rp, _ep);
            if (node_result._tag == Result<OperationSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ActionSyntax, ParserError> { ._tag = Result<ActionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ActionSyntax, ParserError> { ._tag = Result<ActionSyntax, ParserError>::Ok, ._Ok = 
                    ActionSyntax(OperationSyntax(node))
                };
            }
        }
        {
            Region _r_1(_r);
            auto node_result = this->parse_set(_r_1, _rp, _ep);
            if (node_result._tag == Result<SetSyntax, ParserError>::Error)
            {
                if (node_result._Error._tag == ParserError::InvalidSyntax)
                    return Result<ActionSyntax, ParserError> { ._tag = Result<ActionSyntax, ParserError>::Error, ._Error = node_result._Error };
            }
            else
            {
                auto node = node_result._Ok;
                return Result<ActionSyntax, ParserError> { ._tag = Result<ActionSyntax, ParserError>::Ok, ._Ok = 
                    ActionSyntax(SetSyntax(node))
                };
            }
        }
        return Result<ActionSyntax, ParserError> { ._tag = Result<ActionSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
    }

    Result<SetSyntax, ParserError> parse_set(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_set_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "set"));
        if (!success_set_1) {
                return Result<SetSyntax, ParserError> { ._tag = Result<SetSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto target_result = this->parse_operation(_r, _rp, _ep);
        if (target_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (target_result._Error._tag == ParserError::OtherSyntax)
               return Result<SetSyntax, ParserError> { ._tag = Result<SetSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto target = target_result._Ok;

        auto source_result = this->parse_operation(_r, _rp, _ep);
        if (source_result._tag == Result<OperationSyntax, ParserError>::Error)
        {
            if (source_result._Error._tag == ParserError::OtherSyntax)
               return Result<SetSyntax, ParserError> { ._tag = Result<SetSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto source = source_result._Ok;

        auto end = this->lexer.position;

        auto ret = SetSyntax(start, end, target, source);

        return Result<SetSyntax, ParserError> { ._tag = Result<SetSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<OperationSyntax, ParserError> parse_operation(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto operands_result = this->parse_operand_list(_r, _rp, _ep);
        if (operands_result._tag == Result<Vector<OperandSyntax>, ParserError>::Error)
        {
            if (operands_result._Error._tag == ParserError::OtherSyntax)
               return Result<OperationSyntax, ParserError> { ._tag = Result<OperationSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto operands = operands_result._Ok;

        auto success_colon_2 = this->lexer.parse_colon(_r, _rp);
        if (!success_colon_2) {
        }

        auto end = this->lexer.position;

        auto ret = OperationSyntax(start, end, operands);

        return Result<OperationSyntax, ParserError> { ._tag = Result<OperationSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<SizeOfSyntax, ParserError> parse_sizeof(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto success_sizeof_1 = this->lexer.parse_keyword(_r, _rp, String(_r.page, "sizeof"));
        if (!success_sizeof_1) {
                return Result<SizeOfSyntax, ParserError> { ._tag = Result<SizeOfSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto type_result = this->parse_type(_r, _rp, _ep);
        if (type_result._tag == Result<TypeSyntax, ParserError>::Error)
        {
            if (type_result._Error._tag == ParserError::OtherSyntax)
               return Result<SizeOfSyntax, ParserError> { ._tag = Result<SizeOfSyntax, ParserError>::Error, ._Error = ParserError(InvalidSyntaxParserError(start, lexer.position)) };
        }

        auto type = type_result._Ok;

        auto end = this->lexer.position;

        auto ret = SizeOfSyntax(start, end, type);

        return Result<SizeOfSyntax, ParserError> { ._tag = Result<SizeOfSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<Vector<TypeSyntax>*, ParserError> parse_type_list(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        {
            Region _r_1(_r);
            Array<TypeSyntax>* array = nullptr;
            while(true) {
                auto node_result = this->parse_type(_r_1, _rp, _ep);
                if ((node_result._tag == Result<TypeSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::InvalidSyntax))
                    return Result<Vector<TypeSyntax>*, ParserError> { ._tag = Result<Vector<TypeSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                if (node_result._tag == Result<TypeSyntax, ParserError>::Ok) {
                    auto node = node_result._Ok;
                    if (array == nullptr)
                        array = new(alignof(Array<TypeSyntax>), _r_1.page) Array<TypeSyntax>();
                    array->add(node);
                } else {
                    if ((array == nullptr) && (node_result._tag == Result<TypeSyntax, ParserError>::Error) && (node_result._Error._tag == ParserError::OtherSyntax))
                        return Result<Vector<TypeSyntax>*, ParserError> { ._tag = Result<Vector<TypeSyntax>*, ParserError>::Error, ._Error = node_result._Error };
                    break;
                }
            }

            if (array == nullptr)
                return Result<Vector<TypeSyntax>*, ParserError> { ._tag = Result<Vector<TypeSyntax>*, ParserError>::Ok, ._Ok = nullptr };
            
            return Result<Vector<TypeSyntax>*, ParserError> {
                ._tag = Result<Vector<TypeSyntax>*, ParserError>::Ok,
                ._Ok = new(alignof(Vector<TypeSyntax>), _rp) Vector<TypeSyntax>(_rp, *array) };
        }
    }

    Result<TypeSyntax, ParserError> parse_type(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto name_result = this->parse_name(_r, _rp, _ep);
        if (name_result._tag == Result<NameSyntax, ParserError>::Error)
        {
            if (name_result._Error._tag == ParserError::OtherSyntax)
               return Result<TypeSyntax, ParserError> { ._tag = Result<TypeSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };
        }

        auto name = name_result._Ok;

        auto generics_result = this->parse_genericarguments(_r, _rp, _ep);
        if (generics_result._tag == Result<GenericArgumentsSyntax, ParserError>::Error)
        {
        }

        GenericArgumentsSyntax* generics = generics_result._tag == Result<GenericArgumentsSyntax, ParserError>::Error ? nullptr : new(alignof(GenericArgumentsSyntax), _rp) GenericArgumentsSyntax(generics_result._Ok);

        auto optional_result = this->parse_optional(_r, _rp, _ep);
        if (optional_result._tag == Result<OptionalSyntax, ParserError>::Error)
        {
        }

        OptionalSyntax* optional = optional_result._tag == Result<OptionalSyntax, ParserError>::Error ? nullptr : new(alignof(OptionalSyntax), _rp) OptionalSyntax(optional_result._Ok);

        auto end = this->lexer.position;

        auto ret = TypeSyntax(start, end, name, generics, optional);

        return Result<TypeSyntax, ParserError> { ._tag = Result<TypeSyntax, ParserError>::Ok, ._Ok = ret };
    }

    Result<NameSyntax, ParserError> parse_name(Region& _pr, Page* _rp, Page* _ep) {
        Region _r(_pr);
        auto start = this->lexer.previous_position;

        auto name = this->lexer.parse_identifier(_r, _rp, this->keywords);
        if (name != nullptr) {
            if (!this->is_identifier(*name)) {
                return Result<NameSyntax, ParserError> { ._tag = Result<NameSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };

            }
        }
        else {
                return Result<NameSyntax, ParserError> { ._tag = Result<NameSyntax, ParserError>::Error, ._Error = ParserError(OtherSyntaxParserError()) };

        }

        auto extensions_result = this->parse_extension_list(_r, _rp, _ep);
        if (extensions_result._tag == Result<Vector<ExtensionSyntax>, ParserError>::Error)
        {
        }

        auto extensions = extensions_result._tag == Result<Vector<ExtensionSyntax>, ParserError>::Error ? nullptr : extensions_result._Ok;

        auto end = this->lexer.position;

        auto ret = NameSyntax(start, end, *name, extensions);

        return Result<NameSyntax, ParserError> { ._tag = Result<NameSyntax, ParserError>::Ok, ._Ok = ret };
    }

    bool is_at_end() {
        return this->lexer.is_at_end();
    }

    bool is_identifier(String& id) {
        if (this->keywords.contains(id))
            return false;
        else
            return true;
    }
};

}
}
