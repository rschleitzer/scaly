using System;
using System.Collections.Generic;
using System.Text;

namespace scalysh
{
    class Parser
    {
        Lexer lexer;
        string fileName;

        readonly string usingKeyword = "using";
        readonly string namespaceKeyword = "namespace";
        readonly string typedefKeyword = "typedef";
        readonly string letKeyword = "let";
        readonly string mutableKeyword = "mutable";
        readonly string threadlocalKeyword = "threadlocal";
        readonly string varKeyword = "var";
        readonly string setKeyword = "set";
        readonly string classKeyword = "class";
        readonly string extendsKeyword = "extends";
        readonly string constructorKeyword = "constructor";
        readonly string methodKeyword = "method";
        readonly string functionKeyword = "function";
        readonly string operatorKeyword = "operator";
        readonly string thisKeyword = "this";
        readonly string newKeyword = "new";
        readonly string sizeofKeyword = "sizeof";
        readonly string catchKeyword = "catch";
        readonly string throwsKeyword = "throws";
        readonly string asKeyword = "as";
        readonly string isKeyword = "is";
        readonly string ifKeyword = "if";
        readonly string elseKeyword = "else";
        readonly string switchKeyword = "switch";
        readonly string caseKeyword = "case";
        readonly string defaultKeyword = "default";
        readonly string forKeyword = "for";
        readonly string inKeyword = "in";
        readonly string whileKeyword = "while";
        readonly string doKeyword = "do";
        readonly string loopKeyword = "loop";
        readonly string breakKeyword = "break";
        readonly string continueKeyword = "continue";
        readonly string returnKeyword = "return";
        readonly string throwKeyword = "throw";

        readonly string semicolon = ";";
        readonly string leftCurly = "{";
        readonly string rightCurly = "}";
        readonly string leftParen = "(";
        readonly string rightParen = ")";
        readonly string leftBracket = "[";
        readonly string rightBracket = "]";
        readonly string dot = ".";
        readonly string comma = ",";
        readonly string colon = ":";
        readonly string question = "?";
        readonly string exclamation = "!";
        readonly string at = "@";
        readonly string hash = "#";
        readonly string dollar = "$";
        readonly string underscore = "_";
        readonly string backtick = "`";

        public Parser(string theFileName, string text)
        {
            lexer = new Lexer(text);
            fileName = theFileName;
        }

        public File parseFile()
        {
            Position start = lexer.getPreviousPosition();

            Statement[] statements = parseStatementList();
            if (statements != null)
            {
                if (!isAtEnd())
                {
                    Position errorPos = lexer.getPreviousPosition();
                    throw new ParserException(fileName, errorPos.line, errorPos.column);
                }
            }

            Position end = lexer.getPosition();

            File ret = new File(start, end, statements);

            if (statements != null)
            {
                foreach (Statement item in statements)
                    item.parent = ret;
            }

            return ret;
        }

        public Statement[] parseStatementList()
        {
            List<Statement> ret = null;
            while (true)
            {
                Statement node = parseStatement();
                if (node == null)
                    break;

                if (ret == null)
                    ret = new List<Statement>();

                ret.Add(node);
            }

            if (ret != null)
                return ret.ToArray();
            else
                return null;
        }

        public Statement parseStatement()
        {
            {
                Using node = parseUsing();
                if (node != null)
                    return node;
            }

            {
                Namespace node = parseNamespace();
                if (node != null)
                    return node;
            }

            {
                TypeDefinition node = parseTypeDefinition();
                if (node != null)
                    return node;
            }

            {
                Let node = parseLet();
                if (node != null)
                    return node;
            }

            {
                Var node = parseVar();
                if (node != null)
                    return node;
            }

            {
                Mutable node = parseMutable();
                if (node != null)
                    return node;
            }

            {
                ThreadLocal node = parseThreadLocal();
                if (node != null)
                    return node;
            }

            {
                Set node = parseSet();
                if (node != null)
                    return node;
            }

            {
                Calculation node = parseCalculation();
                if (node != null)
                    return node;
            }

            {
                Function node = parseFunction();
                if (node != null)
                    return node;
            }

            {
                Class node = parseClass();
                if (node != null)
                    return node;
            }

            {
                Constructor node = parseConstructor();
                if (node != null)
                    return node;
            }

            {
                Method node = parseMethod();
                if (node != null)
                    return node;
            }

            {
                Operator node = parseOperator();
                if (node != null)
                    return node;
            }

            {
                Break node = parseBreak();
                if (node != null)
                    return node;
            }

            {
                Continue node = parseContinue();
                if (node != null)
                    return node;
            }

            {
                Return node = parseReturn();
                if (node != null)
                    return node;
            }

            {
                Throw node = parseThrow();
                if (node != null)
                    return node;
            }

            return null;
        }

        public Using parseUsing()
        {
            Position start = lexer.getPreviousPosition();

            bool successUsing1 = lexer.parseKeyword(usingKeyword);
            if (successUsing1)
                lexer.advance();
            else
                return null;

            Name name = parseName();
            if (name == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Using ret = new Using(start, end, name);

            name.parent = ret;

            return ret;
        }

        public Name parseName()
        {
            Position start = lexer.getPreviousPosition();

            string name = lexer.parseIdentifier();
            if ((name != null) && isIdentifier(name))
                lexer.advance();
            else
                return null;

            Extension[] extensions = parseExtensionList();

            Position end = lexer.getPosition();

            Name ret = new Name(start, end, name, extensions);

            if (extensions != null)
            {
                foreach (Extension item in extensions)
                    item.parent = ret;
            }

            return ret;
        }

        public Extension[] parseExtensionList()
        {
            List<Extension> ret = null;
            while (true)
            {
                Extension node = parseExtension();
                if (node == null)
                    break;

                if (ret == null)
                    ret = new List<Extension>();

                ret.Add(node);
            }

            if (ret != null)
                return ret.ToArray();
            else
                return null;
        }

        public Extension parseExtension()
        {
            Position start = lexer.getPreviousPosition();

            bool successDot1 = lexer.parsePunctuation(dot);
            if (successDot1)
                lexer.advance();
            else
                return null;

            string name = lexer.parseIdentifier();
            if ((name != null) && isIdentifier(name))
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Extension ret = new Extension(start, end, name);


            return ret;
        }

        public Namespace parseNamespace()
        {
            Position start = lexer.getPreviousPosition();

            bool successNamespace1 = lexer.parseKeyword(namespaceKeyword);
            if (successNamespace1)
                lexer.advance();
            else
                return null;

            Name name = parseName();
            if (name == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Block scope = parseBlock();
            if (scope == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Namespace ret = new Namespace(start, end, name, scope);

            name.parent = ret;
            scope.parent = ret;

            return ret;
        }

        public TypeDefinition parseTypeDefinition()
        {
            Position start = lexer.getPreviousPosition();

            bool successTypedef1 = lexer.parseKeyword(typedefKeyword);
            if (successTypedef1)
                lexer.advance();
            else
                return null;

            string typeName = lexer.parseIdentifier();
            if ((typeName != null) && isIdentifier(typeName))
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            TypeSpec typeSpec = parseTypeSpec();
            if (typeSpec == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            TypeDefinition ret = new TypeDefinition(start, end, typeName, typeSpec);

            typeSpec.parent = ret;

            return ret;
        }

        public Let parseLet()
        {
            Position start = lexer.getPreviousPosition();

            bool successLet1 = lexer.parseKeyword(letKeyword);
            if (successLet1)
                lexer.advance();
            else
                return null;

            Binding binding = parseBinding();
            if (binding == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Let ret = new Let(start, end, binding);

            binding.parent = ret;

            return ret;
        }

        public Var parseVar()
        {
            Position start = lexer.getPreviousPosition();

            bool successVar1 = lexer.parseKeyword(varKeyword);
            if (successVar1)
                lexer.advance();
            else
                return null;

            Binding binding = parseBinding();
            if (binding == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Var ret = new Var(start, end, binding);

            binding.parent = ret;

            return ret;
        }

        public Mutable parseMutable()
        {
            Position start = lexer.getPreviousPosition();

            bool successMutable1 = lexer.parseKeyword(mutableKeyword);
            if (successMutable1)
                lexer.advance();
            else
                return null;

            Binding binding = parseBinding();
            if (binding == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Mutable ret = new Mutable(start, end, binding);

            binding.parent = ret;

            return ret;
        }

        public ThreadLocal parseThreadLocal()
        {
            Position start = lexer.getPreviousPosition();

            bool successThreadlocal1 = lexer.parseKeyword(threadlocalKeyword);
            if (successThreadlocal1)
                lexer.advance();
            else
                return null;

            Binding binding = parseBinding();
            if (binding == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            ThreadLocal ret = new ThreadLocal(start, end, binding);

            binding.parent = ret;

            return ret;
        }

        public Binding parseBinding()
        {
            Position start = lexer.getPreviousPosition();

            Name name = parseName();
            if (name == null)
                return null;

            TypeAnnotation typeAnnotation = parseTypeAnnotation();

            Calculation calculation = parseCalculation();
            if (calculation == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Binding ret = new Binding(start, end, name, typeAnnotation, calculation);

            name.parent = ret;
            if (typeAnnotation != null)
                typeAnnotation.parent = ret;
            calculation.parent = ret;

            return ret;
        }

        public Set parseSet()
        {
            Position start = lexer.getPreviousPosition();

            bool successSet1 = lexer.parseKeyword(setKeyword);
            if (successSet1)
                lexer.advance();
            else
                return null;

            Operation lValue = parseOperation();
            if (lValue == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            bool successColon3 = lexer.parsePunctuation(colon);
            if (successColon3)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Calculation rValue = parseCalculation();
            if (rValue == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Set ret = new Set(start, end, lValue, rValue);

            lValue.parent = ret;
            rValue.parent = ret;

            return ret;
        }

        public Calculation parseCalculation()
        {
            Position start = lexer.getPreviousPosition();

            Operation operation = parseOperation();
            if (operation == null)
                return null;

            bool successSemicolon2 = lexer.parsePunctuation(semicolon);
            if (successSemicolon2)
                lexer.advance();

            Position end = lexer.getPosition();

            Calculation ret = new Calculation(start, end, operation);

            operation.parent = ret;

            return ret;
        }

        public Operation parseOperation()
        {
            Position start = lexer.getPreviousPosition();

            Operand[] op = parseOperandList();
            if (op == null)
                return null;

            Position end = lexer.getPosition();

            Operation ret = new Operation(start, end, op);

            if (op != null)
            {
                foreach (Operand item in op)
                    item.parent = ret;
            }

            return ret;
        }

        public Operand[] parseOperandList()
        {
            List<Operand> ret = null;
            while (true)
            {
                Operand node = parseOperand();
                if (node == null)
                    break;

                if (ret == null)
                    ret = new List<Operand>();

                ret.Add(node);
            }

            if (ret != null)
                return ret.ToArray();
            else
                return null;
        }

        public Operand parseOperand()
        {
            Position start = lexer.getPreviousPosition();

            Expression primary = parseExpression();
            if (primary == null)
                return null;

            Postfix[] postfixes = parsePostfixList();

            Position end = lexer.getPosition();

            Operand ret = new Operand(start, end, primary, postfixes);

            primary.parent = ret;
            if (postfixes != null)
            {
                foreach (Postfix item in postfixes)
                    item.parent = ret;
            }

            return ret;
        }

        public Postfix[] parsePostfixList()
        {
            List<Postfix> ret = null;
            while (true)
            {
                Postfix node = parsePostfix();
                if (node == null)
                    break;

                if (ret == null)
                    ret = new List<Postfix>();

                ret.Add(node);
            }

            if (ret != null)
                return ret.ToArray();
            else
                return null;
        }

        public Postfix parsePostfix()
        {
            {
                MemberAccess node = parseMemberAccess();
                if (node != null)
                    return node;
            }

            {
                As node = parseAs();
                if (node != null)
                    return node;
            }

            {
                Is node = parseIs();
                if (node != null)
                    return node;
            }

            {
                Unwrap node = parseUnwrap();
                if (node != null)
                    return node;
            }

            {
                Catch node = parseCatch();
                if (node != null)
                    return node;
            }

            return null;
        }

        public MemberAccess parseMemberAccess()
        {
            Position start = lexer.getPreviousPosition();

            bool successDot1 = lexer.parsePunctuation(dot);
            if (successDot1)
                lexer.advance();
            else
                return null;

            string member = lexer.parseIdentifier();
            if ((member != null) && isIdentifier(member))
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            MemberAccess ret = new MemberAccess(start, end, member);


            return ret;
        }

        public As parseAs()
        {
            Position start = lexer.getPreviousPosition();

            bool successAs1 = lexer.parseKeyword(asKeyword);
            if (successAs1)
                lexer.advance();
            else
                return null;

            TypeSpec typeSpec = parseTypeSpec();
            if (typeSpec == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            As ret = new As(start, end, typeSpec);

            typeSpec.parent = ret;

            return ret;
        }

        public Is parseIs()
        {
            Position start = lexer.getPreviousPosition();

            bool successIs1 = lexer.parseKeyword(isKeyword);
            if (successIs1)
                lexer.advance();
            else
                return null;

            TypeSpec typeSpec = parseTypeSpec();
            if (typeSpec == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Is ret = new Is(start, end, typeSpec);

            typeSpec.parent = ret;

            return ret;
        }

        public Unwrap parseUnwrap()
        {
            Position start = lexer.getPreviousPosition();

            bool successExclamation1 = lexer.parsePunctuation(exclamation);
            if (successExclamation1)
                lexer.advance();
            else
                return null;

            Position end = lexer.getPosition();

            Unwrap ret = new Unwrap(start, end);


            return ret;
        }

        public Catch parseCatch()
        {
            Position start = lexer.getPreviousPosition();

            bool successCatch1 = lexer.parseKeyword(catchKeyword);
            if (successCatch1)
                lexer.advance();
            else
                return null;

            CatchPattern typeSpec = parseCatchPattern();
            if (typeSpec == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Block handler = parseBlock();
            if (handler == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Catch ret = new Catch(start, end, typeSpec, handler);

            typeSpec.parent = ret;
            handler.parent = ret;

            return ret;
        }

        public CatchPattern parseCatchPattern()
        {
            {
                WildCardCatchPattern node = parseWildCardCatchPattern();
                if (node != null)
                    return node;
            }

            {
                NameCatchPattern node = parseNameCatchPattern();
                if (node != null)
                    return node;
            }

            return null;
        }

        public WildCardCatchPattern parseWildCardCatchPattern()
        {
            Position start = lexer.getPreviousPosition();

            WildcardPattern pattern = parseWildcardPattern();
            if (pattern == null)
                return null;

            Position end = lexer.getPosition();

            WildCardCatchPattern ret = new WildCardCatchPattern(start, end, pattern);

            pattern.parent = ret;

            return ret;
        }

        public NameCatchPattern parseNameCatchPattern()
        {
            Position start = lexer.getPreviousPosition();

            Name name = parseName();

            bool successLeftParen2 = lexer.parsePunctuation(leftParen);
            if (successLeftParen2)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            string errorName = lexer.parseIdentifier();
            if ((errorName != null) && isIdentifier(errorName))
                lexer.advance();

            bool successRightParen4 = lexer.parsePunctuation(rightParen);
            if (successRightParen4)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            NameCatchPattern ret = new NameCatchPattern(start, end, name, errorName);

            if (name != null)
                name.parent = ret;

            return ret;
        }

        public Expression[] parseExpressionList()
        {
            List<Expression> ret = null;
            while (true)
            {
                Expression node = parseExpression();
                if (node == null)
                    break;

                if (ret == null)
                    ret = new List<Expression>();

                ret.Add(node);
            }

            if (ret != null)
                return ret.ToArray();
            else
                return null;
        }

        public Expression parseExpression()
        {
            {
                Block node = parseBlock();
                if (node != null)
                    return node;
            }

            {
                Name node = parseName();
                if (node != null)
                    return node;
            }

            {
                Constant node = parseConstant();
                if (node != null)
                    return node;
            }

            {
                If node = parseIf();
                if (node != null)
                    return node;
            }

            {
                Switch node = parseSwitch();
                if (node != null)
                    return node;
            }

            {
                For node = parseFor();
                if (node != null)
                    return node;
            }

            {
                While node = parseWhile();
                if (node != null)
                    return node;
            }

            {
                Do node = parseDo();
                if (node != null)
                    return node;
            }

            {
                This node = parseThis();
                if (node != null)
                    return node;
            }

            {
                New node = parseNew();
                if (node != null)
                    return node;
            }

            {
                Object node = parseObject();
                if (node != null)
                    return node;
            }

            {
                Array node = parseArray();
                if (node != null)
                    return node;
            }

            {
                SizeOf node = parseSizeOf();
                if (node != null)
                    return node;
            }

            return null;
        }

        public Block parseBlock()
        {
            Position start = lexer.getPreviousPosition();

            bool successLeftCurly1 = lexer.parsePunctuation(leftCurly);
            if (successLeftCurly1)
                lexer.advance();
            else
                return null;

            Statement[] statements = parseStatementList();

            bool successRightCurly3 = lexer.parsePunctuation(rightCurly);
            if (successRightCurly3)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Block ret = new Block(start, end, statements);

            if (statements != null)
            {
                foreach (Statement item in statements)
                    item.parent = ret;
            }

            return ret;
        }

        public Constant parseConstant()
        {
            Position start = lexer.getPreviousPosition();

            Literal literal = lexer.parseLiteral();
            if (literal != null)
                lexer.advance();
            else
                return null;

            Position end = lexer.getPosition();

            Constant ret = new Constant(start, end, literal);


            return ret;
        }

        public If parseIf()
        {
            Position start = lexer.getPreviousPosition();

            bool successIf1 = lexer.parseKeyword(ifKeyword);
            if (successIf1)
                lexer.advance();
            else
                return null;

            bool successLeftParen2 = lexer.parsePunctuation(leftParen);
            if (successLeftParen2)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Operation condition = parseOperation();
            if (condition == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            bool successRightParen4 = lexer.parsePunctuation(rightParen);
            if (successRightParen4)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Block consequent = parseBlock();
            if (consequent == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Else elseClause = parseElse();

            Position end = lexer.getPosition();

            If ret = new If(start, end, condition, consequent, elseClause);

            condition.parent = ret;
            consequent.parent = ret;
            if (elseClause != null)
                elseClause.parent = ret;

            return ret;
        }

        public Else parseElse()
        {
            Position start = lexer.getPreviousPosition();

            bool successElse1 = lexer.parseKeyword(elseKeyword);
            if (successElse1)
                lexer.advance();
            else
                return null;

            Block alternative = parseBlock();
            if (alternative == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Else ret = new Else(start, end, alternative);

            alternative.parent = ret;

            return ret;
        }

        public Switch parseSwitch()
        {
            Position start = lexer.getPreviousPosition();

            bool successSwitch1 = lexer.parseKeyword(switchKeyword);
            if (successSwitch1)
                lexer.advance();
            else
                return null;

            bool successLeftParen2 = lexer.parsePunctuation(leftParen);
            if (successLeftParen2)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Operation condition = parseOperation();
            if (condition == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            bool successRightParen4 = lexer.parsePunctuation(rightParen);
            if (successRightParen4)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            bool successLeftCurly5 = lexer.parsePunctuation(leftCurly);
            if (successLeftCurly5)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            SwitchCase[] cases = parseSwitchCaseList();
            if (cases == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            bool successRightCurly7 = lexer.parsePunctuation(rightCurly);
            if (successRightCurly7)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Switch ret = new Switch(start, end, condition, cases);

            condition.parent = ret;
            if (cases != null)
            {
                foreach (SwitchCase item in cases)
                    item.parent = ret;
            }

            return ret;
        }

        public SwitchCase[] parseSwitchCaseList()
        {
            List<SwitchCase> ret = null;
            while (true)
            {
                SwitchCase node = parseSwitchCase();
                if (node == null)
                    break;

                if (ret == null)
                    ret = new List<SwitchCase>();

                ret.Add(node);
            }

            if (ret != null)
                return ret.ToArray();
            else
                return null;
        }

        public SwitchCase parseSwitchCase()
        {
            Position start = lexer.getPreviousPosition();

            CaseLabel label = parseCaseLabel();
            if (label == null)
                return null;

            Block content = parseBlock();
            if (content == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            SwitchCase ret = new SwitchCase(start, end, label, content);

            label.parent = ret;
            content.parent = ret;

            return ret;
        }

        public CaseLabel parseCaseLabel()
        {
            {
                ItemCaseLabel node = parseItemCaseLabel();
                if (node != null)
                    return node;
            }

            {
                DefaultCaseLabel node = parseDefaultCaseLabel();
                if (node != null)
                    return node;
            }

            return null;
        }

        public ItemCaseLabel parseItemCaseLabel()
        {
            Position start = lexer.getPreviousPosition();

            bool successCase1 = lexer.parseKeyword(caseKeyword);
            if (successCase1)
                lexer.advance();
            else
                return null;

            CaseItem[] items = parseCaseItemList();
            if (items == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            ItemCaseLabel ret = new ItemCaseLabel(start, end, items);

            if (items != null)
            {
                foreach (CaseItem item in items)
                    item.parent = ret;
            }

            return ret;
        }

        public CaseItem[] parseCaseItemList()
        {
            List<CaseItem> ret = null;
            while (true)
            {
                CaseItem node = parseCaseItem();
                if (node == null)
                    break;

                if (ret == null)
                    ret = new List<CaseItem>();

                ret.Add(node);
            }

            if (ret != null)
                return ret.ToArray();
            else
                return null;
        }

        public CaseItem parseCaseItem()
        {
            Position start = lexer.getPreviousPosition();

            CasePattern pattern = parseCasePattern();
            if (pattern == null)
                return null;

            bool successComma2 = lexer.parsePunctuation(comma);
            if (successComma2)
                lexer.advance();

            Position end = lexer.getPosition();

            CaseItem ret = new CaseItem(start, end, pattern);

            pattern.parent = ret;

            return ret;
        }

        public CasePattern[] parseCasePatternList()
        {
            List<CasePattern> ret = null;
            while (true)
            {
                CasePattern node = parseCasePattern();
                if (node == null)
                    break;

                if (ret == null)
                    ret = new List<CasePattern>();

                ret.Add(node);
            }

            if (ret != null)
                return ret.ToArray();
            else
                return null;
        }

        public CasePattern parseCasePattern()
        {
            {
                ConstantPattern node = parseConstantPattern();
                if (node != null)
                    return node;
            }

            {
                WildcardPattern node = parseWildcardPattern();
                if (node != null)
                    return node;
            }

            {
                NamePattern node = parseNamePattern();
                if (node != null)
                    return node;
            }

            return null;
        }

        public ConstantPattern parseConstantPattern()
        {
            Position start = lexer.getPreviousPosition();

            Constant constant = parseConstant();
            if (constant == null)
                return null;

            Position end = lexer.getPosition();

            ConstantPattern ret = new ConstantPattern(start, end, constant);

            constant.parent = ret;

            return ret;
        }

        public WildcardPattern parseWildcardPattern()
        {
            Position start = lexer.getPreviousPosition();

            bool successUnderscore1 = lexer.parsePunctuation(underscore);
            if (successUnderscore1)
                lexer.advance();
            else
                return null;

            Position end = lexer.getPosition();

            WildcardPattern ret = new WildcardPattern(start, end);


            return ret;
        }

        public NamePattern parseNamePattern()
        {
            Position start = lexer.getPreviousPosition();

            Name name = parseName();
            if (name == null)
                return null;

            Position end = lexer.getPosition();

            NamePattern ret = new NamePattern(start, end, name);

            name.parent = ret;

            return ret;
        }

        public DefaultCaseLabel parseDefaultCaseLabel()
        {
            Position start = lexer.getPreviousPosition();

            bool successDefault1 = lexer.parseKeyword(defaultKeyword);
            if (successDefault1)
                lexer.advance();
            else
                return null;

            Position end = lexer.getPosition();

            DefaultCaseLabel ret = new DefaultCaseLabel(start, end);


            return ret;
        }

        public For parseFor()
        {
            Position start = lexer.getPreviousPosition();

            bool successFor1 = lexer.parseKeyword(forKeyword);
            if (successFor1)
                lexer.advance();
            else
                return null;

            bool successLeftParen2 = lexer.parsePunctuation(leftParen);
            if (successLeftParen2)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            string index = lexer.parseIdentifier();
            if ((index != null) && isIdentifier(index))
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            TypeAnnotation typeAnnotation = parseTypeAnnotation();

            bool successIn5 = lexer.parseKeyword(inKeyword);
            if (successIn5)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Operation operation = parseOperation();
            if (operation == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            bool successRightParen7 = lexer.parsePunctuation(rightParen);
            if (successRightParen7)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Loop iteration = parseLoop();
            if (iteration == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            For ret = new For(start, end, index, typeAnnotation, operation, iteration);

            if (typeAnnotation != null)
                typeAnnotation.parent = ret;
            operation.parent = ret;
            iteration.parent = ret;

            return ret;
        }

        public While parseWhile()
        {
            Position start = lexer.getPreviousPosition();

            bool successWhile1 = lexer.parseKeyword(whileKeyword);
            if (successWhile1)
                lexer.advance();
            else
                return null;

            bool successLeftParen2 = lexer.parsePunctuation(leftParen);
            if (successLeftParen2)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Operation condition = parseOperation();
            if (condition == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            bool successRightParen4 = lexer.parsePunctuation(rightParen);
            if (successRightParen4)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Loop iteration = parseLoop();
            if (iteration == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            While ret = new While(start, end, condition, iteration);

            condition.parent = ret;
            iteration.parent = ret;

            return ret;
        }

        public Do parseDo()
        {
            Position start = lexer.getPreviousPosition();

            bool successDo1 = lexer.parseKeyword(doKeyword);
            if (successDo1)
                lexer.advance();
            else
                return null;

            Loop iteration = parseLoop();
            if (iteration == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            bool successWhile3 = lexer.parseKeyword(whileKeyword);
            if (successWhile3)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            bool successLeftParen4 = lexer.parsePunctuation(leftParen);
            if (successLeftParen4)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Operation condition = parseOperation();
            if (condition == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            bool successRightParen6 = lexer.parsePunctuation(rightParen);
            if (successRightParen6)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Do ret = new Do(start, end, iteration, condition);

            iteration.parent = ret;
            condition.parent = ret;

            return ret;
        }

        public Loop parseLoop()
        {
            {
                SimpleLoop node = parseSimpleLoop();
                if (node != null)
                    return node;
            }

            {
                NamedLoop node = parseNamedLoop();
                if (node != null)
                    return node;
            }

            return null;
        }

        public SimpleLoop parseSimpleLoop()
        {
            Position start = lexer.getPreviousPosition();

            Block code = parseBlock();
            if (code == null)
                return null;

            Position end = lexer.getPosition();

            SimpleLoop ret = new SimpleLoop(start, end, code);

            code.parent = ret;

            return ret;
        }

        public NamedLoop parseNamedLoop()
        {
            Position start = lexer.getPreviousPosition();

            bool successLoop1 = lexer.parseKeyword(loopKeyword);
            if (successLoop1)
                lexer.advance();
            else
                return null;

            string name = lexer.parseIdentifier();
            if ((name != null) && isIdentifier(name))
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Block code = parseBlock();
            if (code == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            NamedLoop ret = new NamedLoop(start, end, name, code);

            code.parent = ret;

            return ret;
        }

        public This parseThis()
        {
            Position start = lexer.getPreviousPosition();

            bool successThis1 = lexer.parseKeyword(thisKeyword);
            if (successThis1)
                lexer.advance();
            else
                return null;

            Position end = lexer.getPosition();

            This ret = new This(start, end);


            return ret;
        }

        public New parseNew()
        {
            Position start = lexer.getPreviousPosition();

            bool successNew1 = lexer.parseKeyword(newKeyword);
            if (successNew1)
                lexer.advance();
            else
                return null;

            Name name = parseName();
            if (name == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            GenericArguments generics = parseGenericArguments();

            LifeTime lifeTime = parseLifeTime();

            Position end = lexer.getPosition();

            New ret = new New(start, end, name, generics, lifeTime);

            name.parent = ret;
            if (generics != null)
                generics.parent = ret;
            if (lifeTime != null)
                lifeTime.parent = ret;

            return ret;
        }

        public Object parseObject()
        {
            Position start = lexer.getPreviousPosition();

            bool successLeftParen1 = lexer.parsePunctuation(leftParen);
            if (successLeftParen1)
                lexer.advance();
            else
                return null;

            Operation firstOp = parseOperation();

            Item[] additionalOps = parseItemList();

            bool successRightParen4 = lexer.parsePunctuation(rightParen);
            if (successRightParen4)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Object ret = new Object(start, end, firstOp, additionalOps);

            if (firstOp != null)
                firstOp.parent = ret;
            if (additionalOps != null)
            {
                foreach (Item item in additionalOps)
                    item.parent = ret;
            }

            return ret;
        }

        public Array parseArray()
        {
            Position start = lexer.getPreviousPosition();

            bool successLeftBracket1 = lexer.parsePunctuation(leftBracket);
            if (successLeftBracket1)
                lexer.advance();
            else
                return null;

            Operation firstOp = parseOperation();

            Item[] additionalOps = parseItemList();

            bool successRightBracket4 = lexer.parsePunctuation(rightBracket);
            if (successRightBracket4)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Array ret = new Array(start, end, firstOp, additionalOps);

            if (firstOp != null)
                firstOp.parent = ret;
            if (additionalOps != null)
            {
                foreach (Item item in additionalOps)
                    item.parent = ret;
            }

            return ret;
        }

        public Item[] parseItemList()
        {
            List<Item> ret = null;
            while (true)
            {
                Item node = parseItem();
                if (node == null)
                    break;

                if (ret == null)
                    ret = new List<Item>();

                ret.Add(node);
            }

            if (ret != null)
                return ret.ToArray();
            else
                return null;
        }

        public Item parseItem()
        {
            Position start = lexer.getPreviousPosition();

            bool successComma1 = lexer.parsePunctuation(comma);
            if (successComma1)
                lexer.advance();
            else
                return null;

            Operation operation = parseOperation();
            if (operation == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Item ret = new Item(start, end, operation);

            operation.parent = ret;

            return ret;
        }

        public SizeOf parseSizeOf()
        {
            Position start = lexer.getPreviousPosition();

            bool successSizeof1 = lexer.parseKeyword(sizeofKeyword);
            if (successSizeof1)
                lexer.advance();
            else
                return null;

            Type typeSpec = parseType();
            if (typeSpec == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            SizeOf ret = new SizeOf(start, end, typeSpec);

            typeSpec.parent = ret;

            return ret;
        }

        public Break parseBreak()
        {
            Position start = lexer.getPreviousPosition();

            bool successBreak1 = lexer.parseKeyword(breakKeyword);
            if (successBreak1)
                lexer.advance();
            else
                return null;

            string iteration = lexer.parseIdentifier();
            if ((iteration != null) && isIdentifier(iteration))
                lexer.advance();

            bool successSemicolon3 = lexer.parsePunctuation(semicolon);
            if (successSemicolon3)
                lexer.advance();

            Position end = lexer.getPosition();

            Break ret = new Break(start, end, iteration);


            return ret;
        }

        public Continue parseContinue()
        {
            Position start = lexer.getPreviousPosition();

            bool successContinue1 = lexer.parseKeyword(continueKeyword);
            if (successContinue1)
                lexer.advance();
            else
                return null;

            string iteration = lexer.parseIdentifier();
            if ((iteration != null) && isIdentifier(iteration))
                lexer.advance();

            bool successSemicolon3 = lexer.parsePunctuation(semicolon);
            if (successSemicolon3)
                lexer.advance();

            Position end = lexer.getPosition();

            Continue ret = new Continue(start, end, iteration);


            return ret;
        }

        public Return parseReturn()
        {
            Position start = lexer.getPreviousPosition();

            bool successReturn1 = lexer.parseKeyword(returnKeyword);
            if (successReturn1)
                lexer.advance();
            else
                return null;

            Calculation result = parseCalculation();

            Position end = lexer.getPosition();

            Return ret = new Return(start, end, result);

            if (result != null)
                result.parent = ret;

            return ret;
        }

        public Throw parseThrow()
        {
            Position start = lexer.getPreviousPosition();

            bool successThrow1 = lexer.parseKeyword(throwKeyword);
            if (successThrow1)
                lexer.advance();
            else
                return null;

            Calculation exception = parseCalculation();
            if (exception == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Throw ret = new Throw(start, end, exception);

            exception.parent = ret;

            return ret;
        }

        public Class parseClass()
        {
            Position start = lexer.getPreviousPosition();

            bool successClass1 = lexer.parseKeyword(classKeyword);
            if (successClass1)
                lexer.advance();
            else
                return null;

            Name name = parseName();
            if (name == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            GenericParameters generics = parseGenericParameters();

            Structure contents = parseStructure();

            Extends baseClass = parseExtends();

            Block body = parseBlock();

            Position end = lexer.getPosition();

            Class ret = new Class(start, end, name, generics, contents, baseClass, body);

            name.parent = ret;
            if (generics != null)
                generics.parent = ret;
            if (contents != null)
                contents.parent = ret;
            if (baseClass != null)
                baseClass.parent = ret;
            if (body != null)
                body.parent = ret;

            return ret;
        }

        public GenericParameters parseGenericParameters()
        {
            Position start = lexer.getPreviousPosition();

            bool successLeftBracket1 = lexer.parsePunctuation(leftBracket);
            if (successLeftBracket1)
                lexer.advance();
            else
                return null;

            string name = lexer.parseIdentifier();
            if ((name != null) && isIdentifier(name))
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            GenericParameter[] additionalGenerics = parseGenericParameterList();

            bool successRightBracket4 = lexer.parsePunctuation(rightBracket);
            if (successRightBracket4)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            GenericParameters ret = new GenericParameters(start, end, name, additionalGenerics);

            if (additionalGenerics != null)
            {
                foreach (GenericParameter item in additionalGenerics)
                    item.parent = ret;
            }

            return ret;
        }

        public GenericParameter[] parseGenericParameterList()
        {
            List<GenericParameter> ret = null;
            while (true)
            {
                GenericParameter node = parseGenericParameter();
                if (node == null)
                    break;

                if (ret == null)
                    ret = new List<GenericParameter>();

                ret.Add(node);
            }

            if (ret != null)
                return ret.ToArray();
            else
                return null;
        }

        public GenericParameter parseGenericParameter()
        {
            Position start = lexer.getPreviousPosition();

            bool successComma1 = lexer.parsePunctuation(comma);
            if (successComma1)
                lexer.advance();
            else
                return null;

            string name = lexer.parseIdentifier();
            if ((name != null) && isIdentifier(name))
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            GenericParameter ret = new GenericParameter(start, end, name);


            return ret;
        }

        public Extends parseExtends()
        {
            Position start = lexer.getPreviousPosition();

            bool successExtends1 = lexer.parseKeyword(extendsKeyword);
            if (successExtends1)
                lexer.advance();
            else
                return null;

            Name name = parseName();
            if (name == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Extends ret = new Extends(start, end, name);

            name.parent = ret;

            return ret;
        }

        public Structure parseStructure()
        {
            Position start = lexer.getPreviousPosition();

            bool successLeftParen1 = lexer.parsePunctuation(leftParen);
            if (successLeftParen1)
                lexer.advance();
            else
                return null;

            Component[] components = parseComponentList();

            bool successRightParen3 = lexer.parsePunctuation(rightParen);
            if (successRightParen3)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Structure ret = new Structure(start, end, components);

            if (components != null)
            {
                foreach (Component item in components)
                    item.parent = ret;
            }

            return ret;
        }

        public Component[] parseComponentList()
        {
            List<Component> ret = null;
            while (true)
            {
                Component node = parseComponent();
                if (node == null)
                    break;

                if (ret == null)
                    ret = new List<Component>();

                ret.Add(node);
            }

            if (ret != null)
                return ret.ToArray();
            else
                return null;
        }

        public Component parseComponent()
        {
            Position start = lexer.getPreviousPosition();

            string name = lexer.parseIdentifier();
            if ((name != null) && isIdentifier(name))
                lexer.advance();
            else
                return null;

            TypeAnnotation typeAnnotation = parseTypeAnnotation();

            bool successComma3 = lexer.parsePunctuation(comma);
            if (successComma3)
                lexer.advance();

            Position end = lexer.getPosition();

            Component ret = new Component(start, end, name, typeAnnotation);

            if (typeAnnotation != null)
                typeAnnotation.parent = ret;

            return ret;
        }

        public Constructor parseConstructor()
        {
            Position start = lexer.getPreviousPosition();

            bool successConstructor1 = lexer.parseKeyword(constructorKeyword);
            if (successConstructor1)
                lexer.advance();
            else
                return null;

            Structure input = parseStructure();

            Block body = parseBlock();
            if (body == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Constructor ret = new Constructor(start, end, input, body);

            if (input != null)
                input.parent = ret;
            body.parent = ret;

            return ret;
        }

        public Method parseMethod()
        {
            Position start = lexer.getPreviousPosition();

            bool successMethod1 = lexer.parseKeyword(methodKeyword);
            if (successMethod1)
                lexer.advance();
            else
                return null;

            Procedure procedure = parseProcedure();
            if (procedure == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Method ret = new Method(start, end, procedure);

            procedure.parent = ret;

            return ret;
        }

        public Function parseFunction()
        {
            Position start = lexer.getPreviousPosition();

            bool successFunction1 = lexer.parseKeyword(functionKeyword);
            if (successFunction1)
                lexer.advance();
            else
                return null;

            Procedure procedure = parseProcedure();
            if (procedure == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Function ret = new Function(start, end, procedure);

            procedure.parent = ret;

            return ret;
        }

        public Operator parseOperator()
        {
            Position start = lexer.getPreviousPosition();

            bool successOperator1 = lexer.parseKeyword(operatorKeyword);
            if (successOperator1)
                lexer.advance();
            else
                return null;

            Routine routine = parseRoutine();
            if (routine == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Operator ret = new Operator(start, end, routine);

            routine.parent = ret;

            return ret;
        }

        public Procedure parseProcedure()
        {
            Position start = lexer.getPreviousPosition();

            string name = lexer.parseIdentifier();
            if ((name != null) && isIdentifier(name))
                lexer.advance();
            else
                return null;

            Routine routine = parseRoutine();
            if (routine == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Procedure ret = new Procedure(start, end, name, routine);

            routine.parent = ret;

            return ret;
        }

        public Routine parseRoutine()
        {
            Position start = lexer.getPreviousPosition();

            Structure input = parseStructure();

            TypeAnnotation output = parseTypeAnnotation();

            Throws throwsClause = parseThrows();

            Block body = parseBlock();
            if (body == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Routine ret = new Routine(start, end, input, output, throwsClause, body);

            if (input != null)
                input.parent = ret;
            if (output != null)
                output.parent = ret;
            if (throwsClause != null)
                throwsClause.parent = ret;
            body.parent = ret;

            return ret;
        }

        public TypeAnnotation parseTypeAnnotation()
        {
            Position start = lexer.getPreviousPosition();

            bool successColon1 = lexer.parsePunctuation(colon);
            if (successColon1)
                lexer.advance();
            else
                return null;

            TypeSpec typeSpec = parseTypeSpec();
            if (typeSpec == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            TypeAnnotation ret = new TypeAnnotation(start, end, typeSpec);

            typeSpec.parent = ret;

            return ret;
        }

        public TypeSpec[] parseTypeSpecList()
        {
            List<TypeSpec> ret = null;
            while (true)
            {
                TypeSpec node = parseTypeSpec();
                if (node == null)
                    break;

                if (ret == null)
                    ret = new List<TypeSpec>();

                ret.Add(node);
            }

            if (ret != null)
                return ret.ToArray();
            else
                return null;
        }

        public TypeSpec parseTypeSpec()
        {
            {
                Type node = parseType();
                if (node != null)
                    return node;
            }

            {
                Variant node = parseVariant();
                if (node != null)
                    return node;
            }

            return null;
        }

        public Type[] parseTypeList()
        {
            List<Type> ret = null;
            while (true)
            {
                Type node = parseType();
                if (node == null)
                    break;

                if (ret == null)
                    ret = new List<Type>();

                ret.Add(node);
            }

            if (ret != null)
                return ret.ToArray();
            else
                return null;
        }

        public Type parseType()
        {
            Position start = lexer.getPreviousPosition();

            Name name = parseName();
            if (name == null)
                return null;

            GenericArguments generics = parseGenericArguments();

            Optional optional = parseOptional();

            LifeTime lifeTime = parseLifeTime();

            Position end = lexer.getPosition();

            Type ret = new Type(start, end, name, generics, optional, lifeTime);

            name.parent = ret;
            if (generics != null)
                generics.parent = ret;
            if (optional != null)
                optional.parent = ret;
            if (lifeTime != null)
                lifeTime.parent = ret;

            return ret;
        }

        public Variant parseVariant()
        {
            Position start = lexer.getPreviousPosition();

            bool successLeftParen1 = lexer.parsePunctuation(leftParen);
            if (successLeftParen1)
                lexer.advance();
            else
                return null;

            TypeSpec[] types = parseTypeSpecList();

            bool successRightParen3 = lexer.parsePunctuation(rightParen);
            if (successRightParen3)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Variant ret = new Variant(start, end, types);

            if (types != null)
            {
                foreach (TypeSpec item in types)
                    item.parent = ret;
            }

            return ret;
        }

        public Throws parseThrows()
        {
            Position start = lexer.getPreviousPosition();

            bool successThrows1 = lexer.parseKeyword(throwsKeyword);
            if (successThrows1)
                lexer.advance();
            else
                return null;

            TypeSpec throwsType = parseTypeSpec();
            if (throwsType == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Throws ret = new Throws(start, end, throwsType);

            throwsType.parent = ret;

            return ret;
        }

        public GenericArguments parseGenericArguments()
        {
            Position start = lexer.getPreviousPosition();

            bool successLeftBracket1 = lexer.parsePunctuation(leftBracket);
            if (successLeftBracket1)
                lexer.advance();
            else
                return null;

            Type generic = parseType();
            if (generic == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            GenericArgument[] additionalGenerics = parseGenericArgumentList();

            bool successRightBracket4 = lexer.parsePunctuation(rightBracket);
            if (successRightBracket4)
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            GenericArguments ret = new GenericArguments(start, end, generic, additionalGenerics);

            generic.parent = ret;
            if (additionalGenerics != null)
            {
                foreach (GenericArgument item in additionalGenerics)
                    item.parent = ret;
            }

            return ret;
        }

        public GenericArgument[] parseGenericArgumentList()
        {
            List<GenericArgument> ret = null;
            while (true)
            {
                GenericArgument node = parseGenericArgument();
                if (node == null)
                    break;

                if (ret == null)
                    ret = new List<GenericArgument>();

                ret.Add(node);
            }

            if (ret != null)
                return ret.ToArray();
            else
                return null;
        }

        public GenericArgument parseGenericArgument()
        {
            Position start = lexer.getPreviousPosition();

            bool successComma1 = lexer.parsePunctuation(comma);
            if (successComma1)
                lexer.advance();
            else
                return null;

            Type typeSpec = parseType();
            if (typeSpec == null)
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            GenericArgument ret = new GenericArgument(start, end, typeSpec);

            typeSpec.parent = ret;

            return ret;
        }

        public Optional parseOptional()
        {
            Position start = lexer.getPreviousPosition();

            bool successQuestion1 = lexer.parsePunctuation(question);
            if (successQuestion1)
                lexer.advance();
            else
                return null;

            Position end = lexer.getPosition();

            Optional ret = new Optional(start, end);


            return ret;
        }

        public LifeTime parseLifeTime()
        {
            {
                Root node = parseRoot();
                if (node != null)
                    return node;
            }

            {
                Local node = parseLocal();
                if (node != null)
                    return node;
            }

            {
                Reference node = parseReference();
                if (node != null)
                    return node;
            }

            {
                Thrown node = parseThrown();
                if (node != null)
                    return node;
            }

            return null;
        }

        public Root parseRoot()
        {
            Position start = lexer.getPreviousPosition();

            bool successDollar1 = lexer.parsePunctuation(dollar);
            if (successDollar1)
                lexer.advance();
            else
                return null;

            Position end = lexer.getPosition();

            Root ret = new Root(start, end);


            return ret;
        }

        public Local parseLocal()
        {
            Position start = lexer.getPreviousPosition();

            bool successAt1 = lexer.parsePunctuation(at);
            if (successAt1)
                lexer.advance();
            else
                return null;

            string location = lexer.parseIdentifier();
            if ((location != null) && isIdentifier(location))
                lexer.advance();
            else
                throw new ParserException(fileName, lexer.line, lexer.column);

            Position end = lexer.getPosition();

            Local ret = new Local(start, end, location);


            return ret;
        }

        public Reference parseReference()
        {
            Position start = lexer.getPreviousPosition();

            bool successBacktick1 = lexer.parsePunctuation(backtick);
            if (successBacktick1)
                lexer.advance();
            else
                return null;

            Literal age = lexer.parseLiteral();
            if (age != null)
                lexer.advance();

            Position end = lexer.getPosition();

            Reference ret = new Reference(start, end, age);


            return ret;
        }

        public Thrown parseThrown()
        {
            Position start = lexer.getPreviousPosition();

            bool successHash1 = lexer.parsePunctuation(hash);
            if (successHash1)
                lexer.advance();
            else
                return null;

            Position end = lexer.getPosition();

            Thrown ret = new Thrown(start, end);


            return ret;
        }

        bool isAtEnd()
        {
            return lexer.isAtEnd();
        }

        bool isIdentifier(string id)
        {
            if (id == usingKeyword)
                return false;

            if (id == namespaceKeyword)
                return false;

            if (id == typedefKeyword)
                return false;

            if (id == letKeyword)
                return false;

            if (id == mutableKeyword)
                return false;

            if (id == threadlocalKeyword)
                return false;

            if (id == varKeyword)
                return false;

            if (id == setKeyword)
                return false;

            if (id == classKeyword)
                return false;

            if (id == extendsKeyword)
                return false;

            if (id == constructorKeyword)
                return false;

            if (id == methodKeyword)
                return false;

            if (id == functionKeyword)
                return false;

            if (id == operatorKeyword)
                return false;

            if (id == thisKeyword)
                return false;

            if (id == newKeyword)
                return false;

            if (id == sizeofKeyword)
                return false;

            if (id == catchKeyword)
                return false;

            if (id == throwsKeyword)
                return false;

            if (id == asKeyword)
                return false;

            if (id == isKeyword)
                return false;

            if (id == ifKeyword)
                return false;

            if (id == elseKeyword)
                return false;

            if (id == switchKeyword)
                return false;

            if (id == caseKeyword)
                return false;

            if (id == defaultKeyword)
                return false;

            if (id == forKeyword)
                return false;

            if (id == inKeyword)
                return false;

            if (id == whileKeyword)
                return false;

            if (id == doKeyword)
                return false;

            if (id == loopKeyword)
                return false;

            if (id == breakKeyword)
                return false;

            if (id == continueKeyword)
                return false;

            if (id == returnKeyword)
                return false;

            if (id == throwKeyword)
                return false;

            return true;
        }
    }

    public class Visitor
    {
        public virtual bool openProgram(Program theProgram)
        {
            return true;
        }

        public virtual void closeProgram(Program theProgram)
        {
        }

        public virtual bool openFile(File theFile)
        {
            return true;
        }

        public virtual void closeFile(File theFile)
        {
        }

        public virtual bool openUsing(Using theUsing)
        {
            return true;
        }

        public virtual void closeUsing(Using theUsing)
        {
        }

        public virtual bool openName(Name theName)
        {
            return true;
        }

        public virtual void closeName(Name theName)
        {
        }

        public virtual void visitExtension(Extension theExtension)
        {
        }

        public virtual bool openNamespace(Namespace theNamespace)
        {
            return true;
        }

        public virtual void closeNamespace(Namespace theNamespace)
        {
        }

        public virtual bool openTypeDefinition(TypeDefinition theTypeDefinition)
        {
            return true;
        }

        public virtual void closeTypeDefinition(TypeDefinition theTypeDefinition)
        {
        }

        public virtual bool openLet(Let theLet)
        {
            return true;
        }

        public virtual void closeLet(Let theLet)
        {
        }

        public virtual bool openVar(Var theVar)
        {
            return true;
        }

        public virtual void closeVar(Var theVar)
        {
        }

        public virtual bool openMutable(Mutable theMutable)
        {
            return true;
        }

        public virtual void closeMutable(Mutable theMutable)
        {
        }

        public virtual bool openThreadLocal(ThreadLocal theThreadLocal)
        {
            return true;
        }

        public virtual void closeThreadLocal(ThreadLocal theThreadLocal)
        {
        }

        public virtual bool openBinding(Binding theBinding)
        {
            return true;
        }

        public virtual void closeBinding(Binding theBinding)
        {
        }

        public virtual bool openSet(Set theSet)
        {
            return true;
        }

        public virtual void closeSet(Set theSet)
        {
        }

        public virtual bool openCalculation(Calculation theCalculation)
        {
            return true;
        }

        public virtual void closeCalculation(Calculation theCalculation)
        {
        }

        public virtual bool openOperation(Operation theOperation)
        {
            return true;
        }

        public virtual void closeOperation(Operation theOperation)
        {
        }

        public virtual bool openOperand(Operand theOperand)
        {
            return true;
        }

        public virtual void closeOperand(Operand theOperand)
        {
        }

        public virtual void visitMemberAccess(MemberAccess theMemberAccess)
        {
        }

        public virtual bool openAs(As theAs)
        {
            return true;
        }

        public virtual void closeAs(As theAs)
        {
        }

        public virtual bool openIs(Is theIs)
        {
            return true;
        }

        public virtual void closeIs(Is theIs)
        {
        }

        public virtual void visitUnwrap(Unwrap theUnwrap)
        {
        }

        public virtual bool openCatch(Catch theCatch)
        {
            return true;
        }

        public virtual void closeCatch(Catch theCatch)
        {
        }

        public virtual bool openWildCardCatchPattern(WildCardCatchPattern theWildCardCatchPattern)
        {
            return true;
        }

        public virtual void closeWildCardCatchPattern(WildCardCatchPattern theWildCardCatchPattern)
        {
        }

        public virtual bool openNameCatchPattern(NameCatchPattern theNameCatchPattern)
        {
            return true;
        }

        public virtual void closeNameCatchPattern(NameCatchPattern theNameCatchPattern)
        {
        }

        public virtual bool openBlock(Block theBlock)
        {
            return true;
        }

        public virtual void closeBlock(Block theBlock)
        {
        }

        public virtual void visitConstant(Constant theConstant)
        {
        }

        public virtual bool openIf(If theIf)
        {
            return true;
        }

        public virtual void closeIf(If theIf)
        {
        }

        public virtual bool openElse(Else theElse)
        {
            return true;
        }

        public virtual void closeElse(Else theElse)
        {
        }

        public virtual bool openSwitch(Switch theSwitch)
        {
            return true;
        }

        public virtual void closeSwitch(Switch theSwitch)
        {
        }

        public virtual bool openSwitchCase(SwitchCase theSwitchCase)
        {
            return true;
        }

        public virtual void closeSwitchCase(SwitchCase theSwitchCase)
        {
        }

        public virtual bool openItemCaseLabel(ItemCaseLabel theItemCaseLabel)
        {
            return true;
        }

        public virtual void closeItemCaseLabel(ItemCaseLabel theItemCaseLabel)
        {
        }

        public virtual bool openCaseItem(CaseItem theCaseItem)
        {
            return true;
        }

        public virtual void closeCaseItem(CaseItem theCaseItem)
        {
        }

        public virtual bool openConstantPattern(ConstantPattern theConstantPattern)
        {
            return true;
        }

        public virtual void closeConstantPattern(ConstantPattern theConstantPattern)
        {
        }

        public virtual void visitWildcardPattern(WildcardPattern theWildcardPattern)
        {
        }

        public virtual bool openNamePattern(NamePattern theNamePattern)
        {
            return true;
        }

        public virtual void closeNamePattern(NamePattern theNamePattern)
        {
        }

        public virtual void visitDefaultCaseLabel(DefaultCaseLabel theDefaultCaseLabel)
        {
        }

        public virtual bool openFor(For theFor)
        {
            return true;
        }

        public virtual void closeFor(For theFor)
        {
        }

        public virtual bool openWhile(While theWhile)
        {
            return true;
        }

        public virtual void closeWhile(While theWhile)
        {
        }

        public virtual bool openDo(Do theDo)
        {
            return true;
        }

        public virtual void closeDo(Do theDo)
        {
        }

        public virtual bool openSimpleLoop(SimpleLoop theSimpleLoop)
        {
            return true;
        }

        public virtual void closeSimpleLoop(SimpleLoop theSimpleLoop)
        {
        }

        public virtual bool openNamedLoop(NamedLoop theNamedLoop)
        {
            return true;
        }

        public virtual void closeNamedLoop(NamedLoop theNamedLoop)
        {
        }

        public virtual void visitThis(This theThis)
        {
        }

        public virtual bool openNew(New theNew)
        {
            return true;
        }

        public virtual void closeNew(New theNew)
        {
        }

        public virtual bool openObject(Object theObject)
        {
            return true;
        }

        public virtual void closeObject(Object theObject)
        {
        }

        public virtual bool openArray(Array theArray)
        {
            return true;
        }

        public virtual void closeArray(Array theArray)
        {
        }

        public virtual bool openItem(Item theItem)
        {
            return true;
        }

        public virtual void closeItem(Item theItem)
        {
        }

        public virtual bool openSizeOf(SizeOf theSizeOf)
        {
            return true;
        }

        public virtual void closeSizeOf(SizeOf theSizeOf)
        {
        }

        public virtual void visitBreak(Break theBreak)
        {
        }

        public virtual void visitContinue(Continue theContinue)
        {
        }

        public virtual bool openReturn(Return theReturn)
        {
            return true;
        }

        public virtual void closeReturn(Return theReturn)
        {
        }

        public virtual bool openThrow(Throw theThrow)
        {
            return true;
        }

        public virtual void closeThrow(Throw theThrow)
        {
        }

        public virtual bool openClass(Class theClass)
        {
            return true;
        }

        public virtual void closeClass(Class theClass)
        {
        }

        public virtual bool openGenericParameters(GenericParameters theGenericParameters)
        {
            return true;
        }

        public virtual void closeGenericParameters(GenericParameters theGenericParameters)
        {
        }

        public virtual void visitGenericParameter(GenericParameter theGenericParameter)
        {
        }

        public virtual bool openExtends(Extends theExtends)
        {
            return true;
        }

        public virtual void closeExtends(Extends theExtends)
        {
        }

        public virtual bool openStructure(Structure theStructure)
        {
            return true;
        }

        public virtual void closeStructure(Structure theStructure)
        {
        }

        public virtual bool openComponent(Component theComponent)
        {
            return true;
        }

        public virtual void closeComponent(Component theComponent)
        {
        }

        public virtual bool openConstructor(Constructor theConstructor)
        {
            return true;
        }

        public virtual void closeConstructor(Constructor theConstructor)
        {
        }

        public virtual bool openMethod(Method theMethod)
        {
            return true;
        }

        public virtual void closeMethod(Method theMethod)
        {
        }

        public virtual bool openFunction(Function theFunction)
        {
            return true;
        }

        public virtual void closeFunction(Function theFunction)
        {
        }

        public virtual bool openOperator(Operator theOperator)
        {
            return true;
        }

        public virtual void closeOperator(Operator theOperator)
        {
        }

        public virtual bool openProcedure(Procedure theProcedure)
        {
            return true;
        }

        public virtual void closeProcedure(Procedure theProcedure)
        {
        }

        public virtual bool openRoutine(Routine theRoutine)
        {
            return true;
        }

        public virtual void closeRoutine(Routine theRoutine)
        {
        }

        public virtual bool openTypeAnnotation(TypeAnnotation theTypeAnnotation)
        {
            return true;
        }

        public virtual void closeTypeAnnotation(TypeAnnotation theTypeAnnotation)
        {
        }

        public virtual bool openType(Type theType)
        {
            return true;
        }

        public virtual void closeType(Type theType)
        {
        }

        public virtual bool openVariant(Variant theVariant)
        {
            return true;
        }

        public virtual void closeVariant(Variant theVariant)
        {
        }

        public virtual bool openThrows(Throws theThrows)
        {
            return true;
        }

        public virtual void closeThrows(Throws theThrows)
        {
        }

        public virtual bool openGenericArguments(GenericArguments theGenericArguments)
        {
            return true;
        }

        public virtual void closeGenericArguments(GenericArguments theGenericArguments)
        {
        }

        public virtual bool openGenericArgument(GenericArgument theGenericArgument)
        {
            return true;
        }

        public virtual void closeGenericArgument(GenericArgument theGenericArgument)
        {
        }

        public virtual void visitOptional(Optional theOptional)
        {
        }

        public virtual void visitRoot(Root theRoot)
        {
        }

        public virtual void visitLocal(Local theLocal)
        {
        }

        public virtual void visitReference(Reference theReference)
        {
        }

        public virtual void visitThrown(Thrown theThrown)
        {
        }
}

    public abstract class SyntaxNode
    {
        public Position start;
        public Position end;
        public SyntaxNode parent;

        public abstract void accept(Visitor visitor);
    }

    public class Program : SyntaxNode
    {
        public string name;
        public File[] files;
        public Program(string name, File[] files)
        {
            start = new Position(0, 0);
            end = new Position(0, 0);
            this.name = name;
            this.files = files;
            this.parent = null;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openProgram(this))
                return;

            if (files != null)
            {
                foreach (File node in files)
                    node.accept(visitor);
            }
            visitor.closeProgram(this);
        }
    }

    public class File : SyntaxNode
    {
        public Statement[] statements;
        public string fileName;
        public File(Position start, Position end, Statement[] statements)
        {
            this.start = start;
            this.end = end;
            this.statements = statements;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openFile(this))
                return;

            if (statements != null)
            {
                foreach (Statement node in statements)
                    node.accept(visitor);
            }
            visitor.closeFile(this);
        }
    }

    public class Statement : SyntaxNode
    {
        public override void accept(Visitor visitor)
        {
        }
    }

    public class Using : Statement
    {
        public Name name;
        public Using(Position start, Position end, Name name)
        {
            this.start = start;
            this.end = end;
            this.name = name;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openUsing(this))
                return;

        name.accept(visitor);
            visitor.closeUsing(this);
        }
    }

    public class Name : Expression
    {
        public string name;
        public Extension[] extensions;
        public Name(Position start, Position end, string name, Extension[] extensions)
        {
            this.start = start;
            this.end = end;
            this.name = name;
            this.extensions = extensions;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openName(this))
                return;

            if (extensions != null)
            {
                foreach (Extension node in extensions)
                    node.accept(visitor);
            }
            visitor.closeName(this);
        }
    }

    public class Extension : SyntaxNode
    {
        public string name;
        public Extension(Position start, Position end, string name)
        {
            this.start = start;
            this.end = end;
            this.name = name;
        }

        public override void accept(Visitor visitor)
        {
            visitor.visitExtension(this);
        }
    }

    public class Namespace : Statement
    {
        public Name name;
        public Block scope;
        public Namespace(Position start, Position end, Name name, Block scope)
        {
            this.start = start;
            this.end = end;
            this.name = name;
            this.scope = scope;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openNamespace(this))
                return;

        name.accept(visitor);
        scope.accept(visitor);
            visitor.closeNamespace(this);
        }
    }

    public class TypeDefinition : Statement
    {
        public string typeName;
        public TypeSpec typeSpec;
        public TypeDefinition(Position start, Position end, string typeName, TypeSpec typeSpec)
        {
            this.start = start;
            this.end = end;
            this.typeName = typeName;
            this.typeSpec = typeSpec;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openTypeDefinition(this))
                return;

        typeSpec.accept(visitor);
            visitor.closeTypeDefinition(this);
        }
    }

    public class Let : Statement
    {
        public Binding binding;
        public Let(Position start, Position end, Binding binding)
        {
            this.start = start;
            this.end = end;
            this.binding = binding;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openLet(this))
                return;

        binding.accept(visitor);
            visitor.closeLet(this);
        }
    }

    public class Var : Statement
    {
        public Binding binding;
        public Var(Position start, Position end, Binding binding)
        {
            this.start = start;
            this.end = end;
            this.binding = binding;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openVar(this))
                return;

        binding.accept(visitor);
            visitor.closeVar(this);
        }
    }

    public class Mutable : Statement
    {
        public Binding binding;
        public Mutable(Position start, Position end, Binding binding)
        {
            this.start = start;
            this.end = end;
            this.binding = binding;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openMutable(this))
                return;

        binding.accept(visitor);
            visitor.closeMutable(this);
        }
    }

    public class ThreadLocal : Statement
    {
        public Binding binding;
        public ThreadLocal(Position start, Position end, Binding binding)
        {
            this.start = start;
            this.end = end;
            this.binding = binding;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openThreadLocal(this))
                return;

        binding.accept(visitor);
            visitor.closeThreadLocal(this);
        }
    }

    public class Binding : SyntaxNode
    {
        public Name name;
        public TypeAnnotation typeAnnotation;
        public Calculation calculation;
        public Binding(Position start, Position end, Name name, TypeAnnotation typeAnnotation, Calculation calculation)
        {
            this.start = start;
            this.end = end;
            this.name = name;
            this.typeAnnotation = typeAnnotation;
            this.calculation = calculation;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openBinding(this))
                return;

        name.accept(visitor);
        if (typeAnnotation != null)
            typeAnnotation.accept(visitor);
        calculation.accept(visitor);
            visitor.closeBinding(this);
        }
    }

    public class Set : Statement
    {
        public Operation lValue;
        public Calculation rValue;
        public Set(Position start, Position end, Operation lValue, Calculation rValue)
        {
            this.start = start;
            this.end = end;
            this.lValue = lValue;
            this.rValue = rValue;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openSet(this))
                return;

        lValue.accept(visitor);
        rValue.accept(visitor);
            visitor.closeSet(this);
        }
    }

    public class Calculation : Statement
    {
        public Operation operation;
        public Calculation(Position start, Position end, Operation operation)
        {
            this.start = start;
            this.end = end;
            this.operation = operation;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openCalculation(this))
                return;

        operation.accept(visitor);
            visitor.closeCalculation(this);
        }
    }

    public class Operation : SyntaxNode
    {
        public Operand[] op;
        public Operation(Position start, Position end, Operand[] op)
        {
            this.start = start;
            this.end = end;
            this.op = op;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openOperation(this))
                return;

            if (op != null)
            {
                foreach (Operand node in op)
                    node.accept(visitor);
            }
            visitor.closeOperation(this);
        }
    }

    public class Operand : Statement
    {
        public Expression primary;
        public Postfix[] postfixes;
        public Operand(Position start, Position end, Expression primary, Postfix[] postfixes)
        {
            this.start = start;
            this.end = end;
            this.primary = primary;
            this.postfixes = postfixes;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openOperand(this))
                return;

        primary.accept(visitor);
            if (postfixes != null)
            {
                foreach (Postfix node in postfixes)
                    node.accept(visitor);
            }
            visitor.closeOperand(this);
        }
    }

    public class Postfix : SyntaxNode
    {
        public override void accept(Visitor visitor)
        {
        }
    }

    public class MemberAccess : Postfix
    {
        public string member;
        public MemberAccess(Position start, Position end, string member)
        {
            this.start = start;
            this.end = end;
            this.member = member;
        }

        public override void accept(Visitor visitor)
        {
            visitor.visitMemberAccess(this);
        }
    }

    public class As : Postfix
    {
        public TypeSpec typeSpec;
        public As(Position start, Position end, TypeSpec typeSpec)
        {
            this.start = start;
            this.end = end;
            this.typeSpec = typeSpec;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openAs(this))
                return;

        typeSpec.accept(visitor);
            visitor.closeAs(this);
        }
    }

    public class Is : Postfix
    {
        public TypeSpec typeSpec;
        public Is(Position start, Position end, TypeSpec typeSpec)
        {
            this.start = start;
            this.end = end;
            this.typeSpec = typeSpec;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openIs(this))
                return;

        typeSpec.accept(visitor);
            visitor.closeIs(this);
        }
    }

    public class Unwrap : Postfix
    {
        public Unwrap(Position start, Position end)
        {
            this.start = start;
            this.end = end;
        }

        public override void accept(Visitor visitor)
        {
            visitor.visitUnwrap(this);
        }
    }

    public class Catch : Postfix
    {
        public CatchPattern typeSpec;
        public Block handler;
        public Catch(Position start, Position end, CatchPattern typeSpec, Block handler)
        {
            this.start = start;
            this.end = end;
            this.typeSpec = typeSpec;
            this.handler = handler;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openCatch(this))
                return;

        typeSpec.accept(visitor);
        handler.accept(visitor);
            visitor.closeCatch(this);
        }
    }

    public class CatchPattern : SyntaxNode
    {
        public override void accept(Visitor visitor)
        {
        }
    }

    public class WildCardCatchPattern : CatchPattern
    {
        public WildcardPattern pattern;
        public WildCardCatchPattern(Position start, Position end, WildcardPattern pattern)
        {
            this.start = start;
            this.end = end;
            this.pattern = pattern;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openWildCardCatchPattern(this))
                return;

        pattern.accept(visitor);
            visitor.closeWildCardCatchPattern(this);
        }
    }

    public class NameCatchPattern : CatchPattern
    {
        public Name name;
        public string errorName;
        public NameCatchPattern(Position start, Position end, Name name, string errorName)
        {
            this.start = start;
            this.end = end;
            this.name = name;
            this.errorName = errorName;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openNameCatchPattern(this))
                return;

        if (name != null)
            name.accept(visitor);
            visitor.closeNameCatchPattern(this);
        }
    }

    public class Expression : SyntaxNode
    {
        public override void accept(Visitor visitor)
        {
        }
    }

    public class Block : Expression
    {
        public Statement[] statements;
        public Block(Position start, Position end, Statement[] statements)
        {
            this.start = start;
            this.end = end;
            this.statements = statements;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openBlock(this))
                return;

            if (statements != null)
            {
                foreach (Statement node in statements)
                    node.accept(visitor);
            }
            visitor.closeBlock(this);
        }
    }

    public class Constant : Expression
    {
        public Literal literal;
        public Constant(Position start, Position end, Literal literal)
        {
            this.start = start;
            this.end = end;
            this.literal = literal;
        }

        public override void accept(Visitor visitor)
        {
            visitor.visitConstant(this);
        }
    }

    public class If : Expression
    {
        public Operation condition;
        public Block consequent;
        public Else elseClause;
        public If(Position start, Position end, Operation condition, Block consequent, Else elseClause)
        {
            this.start = start;
            this.end = end;
            this.condition = condition;
            this.consequent = consequent;
            this.elseClause = elseClause;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openIf(this))
                return;

        condition.accept(visitor);
        consequent.accept(visitor);
        if (elseClause != null)
            elseClause.accept(visitor);
            visitor.closeIf(this);
        }
    }

    public class Else : SyntaxNode
    {
        public Block alternative;
        public Else(Position start, Position end, Block alternative)
        {
            this.start = start;
            this.end = end;
            this.alternative = alternative;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openElse(this))
                return;

        alternative.accept(visitor);
            visitor.closeElse(this);
        }
    }

    public class Switch : Expression
    {
        public Operation condition;
        public SwitchCase[] cases;
        public Switch(Position start, Position end, Operation condition, SwitchCase[] cases)
        {
            this.start = start;
            this.end = end;
            this.condition = condition;
            this.cases = cases;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openSwitch(this))
                return;

        condition.accept(visitor);
            if (cases != null)
            {
                foreach (SwitchCase node in cases)
                    node.accept(visitor);
            }
            visitor.closeSwitch(this);
        }
    }

    public class SwitchCase : SyntaxNode
    {
        public CaseLabel label;
        public Block content;
        public SwitchCase(Position start, Position end, CaseLabel label, Block content)
        {
            this.start = start;
            this.end = end;
            this.label = label;
            this.content = content;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openSwitchCase(this))
                return;

        label.accept(visitor);
        content.accept(visitor);
            visitor.closeSwitchCase(this);
        }
    }

    public class CaseLabel : SyntaxNode
    {
        public override void accept(Visitor visitor)
        {
        }
    }

    public class ItemCaseLabel : CaseLabel
    {
        public CaseItem[] items;
        public ItemCaseLabel(Position start, Position end, CaseItem[] items)
        {
            this.start = start;
            this.end = end;
            this.items = items;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openItemCaseLabel(this))
                return;

            if (items != null)
            {
                foreach (CaseItem node in items)
                    node.accept(visitor);
            }
            visitor.closeItemCaseLabel(this);
        }
    }

    public class CaseItem : SyntaxNode
    {
        public CasePattern pattern;
        public CaseItem(Position start, Position end, CasePattern pattern)
        {
            this.start = start;
            this.end = end;
            this.pattern = pattern;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openCaseItem(this))
                return;

        pattern.accept(visitor);
            visitor.closeCaseItem(this);
        }
    }

    public class CasePattern : SyntaxNode
    {
        public override void accept(Visitor visitor)
        {
        }
    }

    public class ConstantPattern : CasePattern
    {
        public Constant constant;
        public ConstantPattern(Position start, Position end, Constant constant)
        {
            this.start = start;
            this.end = end;
            this.constant = constant;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openConstantPattern(this))
                return;

        constant.accept(visitor);
            visitor.closeConstantPattern(this);
        }
    }

    public class WildcardPattern : CasePattern
    {
        public WildcardPattern(Position start, Position end)
        {
            this.start = start;
            this.end = end;
        }

        public override void accept(Visitor visitor)
        {
            visitor.visitWildcardPattern(this);
        }
    }

    public class NamePattern : CasePattern
    {
        public Name name;
        public NamePattern(Position start, Position end, Name name)
        {
            this.start = start;
            this.end = end;
            this.name = name;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openNamePattern(this))
                return;

        name.accept(visitor);
            visitor.closeNamePattern(this);
        }
    }

    public class DefaultCaseLabel : CaseLabel
    {
        public DefaultCaseLabel(Position start, Position end)
        {
            this.start = start;
            this.end = end;
        }

        public override void accept(Visitor visitor)
        {
            visitor.visitDefaultCaseLabel(this);
        }
    }

    public class For : Expression
    {
        public string index;
        public TypeAnnotation typeAnnotation;
        public Operation operation;
        public Loop iteration;
        public For(Position start, Position end, string index, TypeAnnotation typeAnnotation, Operation operation, Loop iteration)
        {
            this.start = start;
            this.end = end;
            this.index = index;
            this.typeAnnotation = typeAnnotation;
            this.operation = operation;
            this.iteration = iteration;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openFor(this))
                return;

        if (typeAnnotation != null)
            typeAnnotation.accept(visitor);
        operation.accept(visitor);
        iteration.accept(visitor);
            visitor.closeFor(this);
        }
    }

    public class While : Expression
    {
        public Operation condition;
        public Loop iteration;
        public While(Position start, Position end, Operation condition, Loop iteration)
        {
            this.start = start;
            this.end = end;
            this.condition = condition;
            this.iteration = iteration;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openWhile(this))
                return;

        condition.accept(visitor);
        iteration.accept(visitor);
            visitor.closeWhile(this);
        }
    }

    public class Do : Expression
    {
        public Loop iteration;
        public Operation condition;
        public Do(Position start, Position end, Loop iteration, Operation condition)
        {
            this.start = start;
            this.end = end;
            this.iteration = iteration;
            this.condition = condition;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openDo(this))
                return;

        iteration.accept(visitor);
        condition.accept(visitor);
            visitor.closeDo(this);
        }
    }

    public class Loop : SyntaxNode
    {
        public override void accept(Visitor visitor)
        {
        }
    }

    public class SimpleLoop : Loop
    {
        public Block code;
        public SimpleLoop(Position start, Position end, Block code)
        {
            this.start = start;
            this.end = end;
            this.code = code;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openSimpleLoop(this))
                return;

        code.accept(visitor);
            visitor.closeSimpleLoop(this);
        }
    }

    public class NamedLoop : Loop
    {
        public string name;
        public Block code;
        public NamedLoop(Position start, Position end, string name, Block code)
        {
            this.start = start;
            this.end = end;
            this.name = name;
            this.code = code;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openNamedLoop(this))
                return;

        code.accept(visitor);
            visitor.closeNamedLoop(this);
        }
    }

    public class This : Expression
    {
        public This(Position start, Position end)
        {
            this.start = start;
            this.end = end;
        }

        public override void accept(Visitor visitor)
        {
            visitor.visitThis(this);
        }
    }

    public class New : Expression
    {
        public Name name;
        public GenericArguments generics;
        public LifeTime lifeTime;
        public New(Position start, Position end, Name name, GenericArguments generics, LifeTime lifeTime)
        {
            this.start = start;
            this.end = end;
            this.name = name;
            this.generics = generics;
            this.lifeTime = lifeTime;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openNew(this))
                return;

        name.accept(visitor);
        if (generics != null)
            generics.accept(visitor);
        if (lifeTime != null)
            lifeTime.accept(visitor);
            visitor.closeNew(this);
        }
    }

    public class Object : Expression
    {
        public Operation firstOp;
        public Item[] additionalOps;
        public Object(Position start, Position end, Operation firstOp, Item[] additionalOps)
        {
            this.start = start;
            this.end = end;
            this.firstOp = firstOp;
            this.additionalOps = additionalOps;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openObject(this))
                return;

        if (firstOp != null)
            firstOp.accept(visitor);
            if (additionalOps != null)
            {
                foreach (Item node in additionalOps)
                    node.accept(visitor);
            }
            visitor.closeObject(this);
        }
    }

    public class Array : Expression
    {
        public Operation firstOp;
        public Item[] additionalOps;
        public Array(Position start, Position end, Operation firstOp, Item[] additionalOps)
        {
            this.start = start;
            this.end = end;
            this.firstOp = firstOp;
            this.additionalOps = additionalOps;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openArray(this))
                return;

        if (firstOp != null)
            firstOp.accept(visitor);
            if (additionalOps != null)
            {
                foreach (Item node in additionalOps)
                    node.accept(visitor);
            }
            visitor.closeArray(this);
        }
    }

    public class Item : SyntaxNode
    {
        public Operation operation;
        public Item(Position start, Position end, Operation operation)
        {
            this.start = start;
            this.end = end;
            this.operation = operation;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openItem(this))
                return;

        operation.accept(visitor);
            visitor.closeItem(this);
        }
    }

    public class SizeOf : Expression
    {
        public Type typeSpec;
        public SizeOf(Position start, Position end, Type typeSpec)
        {
            this.start = start;
            this.end = end;
            this.typeSpec = typeSpec;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openSizeOf(this))
                return;

        typeSpec.accept(visitor);
            visitor.closeSizeOf(this);
        }
    }

    public class Break : Statement
    {
        public string iteration;
        public Break(Position start, Position end, string iteration)
        {
            this.start = start;
            this.end = end;
            this.iteration = iteration;
        }

        public override void accept(Visitor visitor)
        {
            visitor.visitBreak(this);
        }
    }

    public class Continue : Statement
    {
        public string iteration;
        public Continue(Position start, Position end, string iteration)
        {
            this.start = start;
            this.end = end;
            this.iteration = iteration;
        }

        public override void accept(Visitor visitor)
        {
            visitor.visitContinue(this);
        }
    }

    public class Return : Statement
    {
        public Calculation result;
        public Return(Position start, Position end, Calculation result)
        {
            this.start = start;
            this.end = end;
            this.result = result;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openReturn(this))
                return;

        if (result != null)
            result.accept(visitor);
            visitor.closeReturn(this);
        }
    }

    public class Throw : Statement
    {
        public Calculation exception;
        public Throw(Position start, Position end, Calculation exception)
        {
            this.start = start;
            this.end = end;
            this.exception = exception;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openThrow(this))
                return;

        exception.accept(visitor);
            visitor.closeThrow(this);
        }
    }

    public class Class : Statement
    {
        public Name name;
        public GenericParameters generics;
        public Structure contents;
        public Extends baseClass;
        public Block body;
        public Class(Position start, Position end, Name name, GenericParameters generics, Structure contents, Extends baseClass, Block body)
        {
            this.start = start;
            this.end = end;
            this.name = name;
            this.generics = generics;
            this.contents = contents;
            this.baseClass = baseClass;
            this.body = body;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openClass(this))
                return;

        name.accept(visitor);
        if (generics != null)
            generics.accept(visitor);
        if (contents != null)
            contents.accept(visitor);
        if (baseClass != null)
            baseClass.accept(visitor);
        if (body != null)
            body.accept(visitor);
            visitor.closeClass(this);
        }
    }

    public class GenericParameters : SyntaxNode
    {
        public string name;
        public GenericParameter[] additionalGenerics;
        public GenericParameters(Position start, Position end, string name, GenericParameter[] additionalGenerics)
        {
            this.start = start;
            this.end = end;
            this.name = name;
            this.additionalGenerics = additionalGenerics;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openGenericParameters(this))
                return;

            if (additionalGenerics != null)
            {
                foreach (GenericParameter node in additionalGenerics)
                    node.accept(visitor);
            }
            visitor.closeGenericParameters(this);
        }
    }

    public class GenericParameter : SyntaxNode
    {
        public string name;
        public GenericParameter(Position start, Position end, string name)
        {
            this.start = start;
            this.end = end;
            this.name = name;
        }

        public override void accept(Visitor visitor)
        {
            visitor.visitGenericParameter(this);
        }
    }

    public class Extends : SyntaxNode
    {
        public Name name;
        public Extends(Position start, Position end, Name name)
        {
            this.start = start;
            this.end = end;
            this.name = name;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openExtends(this))
                return;

        name.accept(visitor);
            visitor.closeExtends(this);
        }
    }

    public class Structure : SyntaxNode
    {
        public Component[] components;
        public Structure(Position start, Position end, Component[] components)
        {
            this.start = start;
            this.end = end;
            this.components = components;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openStructure(this))
                return;

            if (components != null)
            {
                foreach (Component node in components)
                    node.accept(visitor);
            }
            visitor.closeStructure(this);
        }
    }

    public class Component : SyntaxNode
    {
        public string name;
        public TypeAnnotation typeAnnotation;
        public Component(Position start, Position end, string name, TypeAnnotation typeAnnotation)
        {
            this.start = start;
            this.end = end;
            this.name = name;
            this.typeAnnotation = typeAnnotation;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openComponent(this))
                return;

        if (typeAnnotation != null)
            typeAnnotation.accept(visitor);
            visitor.closeComponent(this);
        }
    }

    public class Constructor : Statement
    {
        public Structure input;
        public Block body;
        public Constructor(Position start, Position end, Structure input, Block body)
        {
            this.start = start;
            this.end = end;
            this.input = input;
            this.body = body;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openConstructor(this))
                return;

        if (input != null)
            input.accept(visitor);
        body.accept(visitor);
            visitor.closeConstructor(this);
        }
    }

    public class Method : Statement
    {
        public Procedure procedure;
        public Method(Position start, Position end, Procedure procedure)
        {
            this.start = start;
            this.end = end;
            this.procedure = procedure;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openMethod(this))
                return;

        procedure.accept(visitor);
            visitor.closeMethod(this);
        }
    }

    public class Function : Statement
    {
        public Procedure procedure;
        public Function(Position start, Position end, Procedure procedure)
        {
            this.start = start;
            this.end = end;
            this.procedure = procedure;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openFunction(this))
                return;

        procedure.accept(visitor);
            visitor.closeFunction(this);
        }
    }

    public class Operator : Statement
    {
        public Routine routine;
        public Operator(Position start, Position end, Routine routine)
        {
            this.start = start;
            this.end = end;
            this.routine = routine;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openOperator(this))
                return;

        routine.accept(visitor);
            visitor.closeOperator(this);
        }
    }

    public class Procedure : SyntaxNode
    {
        public string name;
        public Routine routine;
        public Procedure(Position start, Position end, string name, Routine routine)
        {
            this.start = start;
            this.end = end;
            this.name = name;
            this.routine = routine;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openProcedure(this))
                return;

        routine.accept(visitor);
            visitor.closeProcedure(this);
        }
    }

    public class Routine : SyntaxNode
    {
        public Structure input;
        public TypeAnnotation output;
        public Throws throwsClause;
        public Block body;
        public Routine(Position start, Position end, Structure input, TypeAnnotation output, Throws throwsClause, Block body)
        {
            this.start = start;
            this.end = end;
            this.input = input;
            this.output = output;
            this.throwsClause = throwsClause;
            this.body = body;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openRoutine(this))
                return;

        if (input != null)
            input.accept(visitor);
        if (output != null)
            output.accept(visitor);
        if (throwsClause != null)
            throwsClause.accept(visitor);
        body.accept(visitor);
            visitor.closeRoutine(this);
        }
    }

    public class TypeAnnotation : SyntaxNode
    {
        public TypeSpec typeSpec;
        public TypeAnnotation(Position start, Position end, TypeSpec typeSpec)
        {
            this.start = start;
            this.end = end;
            this.typeSpec = typeSpec;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openTypeAnnotation(this))
                return;

        typeSpec.accept(visitor);
            visitor.closeTypeAnnotation(this);
        }
    }

    public class TypeSpec : SyntaxNode
    {
        public override void accept(Visitor visitor)
        {
        }
    }

    public class Type : TypeSpec
    {
        public Name name;
        public GenericArguments generics;
        public Optional optional;
        public LifeTime lifeTime;
        public Type(Position start, Position end, Name name, GenericArguments generics, Optional optional, LifeTime lifeTime)
        {
            this.start = start;
            this.end = end;
            this.name = name;
            this.generics = generics;
            this.optional = optional;
            this.lifeTime = lifeTime;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openType(this))
                return;

        name.accept(visitor);
        if (generics != null)
            generics.accept(visitor);
        if (optional != null)
            optional.accept(visitor);
        if (lifeTime != null)
            lifeTime.accept(visitor);
            visitor.closeType(this);
        }
    }

    public class Variant : TypeSpec
    {
        public TypeSpec[] types;
        public Variant(Position start, Position end, TypeSpec[] types)
        {
            this.start = start;
            this.end = end;
            this.types = types;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openVariant(this))
                return;

            if (types != null)
            {
                foreach (TypeSpec node in types)
                    node.accept(visitor);
            }
            visitor.closeVariant(this);
        }
    }

    public class Throws : SyntaxNode
    {
        public TypeSpec throwsType;
        public Throws(Position start, Position end, TypeSpec throwsType)
        {
            this.start = start;
            this.end = end;
            this.throwsType = throwsType;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openThrows(this))
                return;

        throwsType.accept(visitor);
            visitor.closeThrows(this);
        }
    }

    public class GenericArguments : SyntaxNode
    {
        public Type generic;
        public GenericArgument[] additionalGenerics;
        public GenericArguments(Position start, Position end, Type generic, GenericArgument[] additionalGenerics)
        {
            this.start = start;
            this.end = end;
            this.generic = generic;
            this.additionalGenerics = additionalGenerics;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openGenericArguments(this))
                return;

        generic.accept(visitor);
            if (additionalGenerics != null)
            {
                foreach (GenericArgument node in additionalGenerics)
                    node.accept(visitor);
            }
            visitor.closeGenericArguments(this);
        }
    }

    public class GenericArgument : SyntaxNode
    {
        public Type typeSpec;
        public GenericArgument(Position start, Position end, Type typeSpec)
        {
            this.start = start;
            this.end = end;
            this.typeSpec = typeSpec;
        }

        public override void accept(Visitor visitor)
        {
            if (!visitor.openGenericArgument(this))
                return;

        typeSpec.accept(visitor);
            visitor.closeGenericArgument(this);
        }
    }

    public class Optional : SyntaxNode
    {
        public Optional(Position start, Position end)
        {
            this.start = start;
            this.end = end;
        }

        public override void accept(Visitor visitor)
        {
            visitor.visitOptional(this);
        }
    }

    public class LifeTime : SyntaxNode
    {
        public override void accept(Visitor visitor)
        {
        }
    }

    public class Root : LifeTime
    {
        public Root(Position start, Position end)
        {
            this.start = start;
            this.end = end;
        }

        public override void accept(Visitor visitor)
        {
            visitor.visitRoot(this);
        }
    }

    public class Local : LifeTime
    {
        public string location;
        public Local(Position start, Position end, string location)
        {
            this.start = start;
            this.end = end;
            this.location = location;
        }

        public override void accept(Visitor visitor)
        {
            visitor.visitLocal(this);
        }
    }

    public class Reference : LifeTime
    {
        public Literal age;
        public Reference(Position start, Position end, Literal age)
        {
            this.start = start;
            this.end = end;
            this.age = age;
        }

        public override void accept(Visitor visitor)
        {
            visitor.visitReference(this);
        }
    }

    public class Thrown : LifeTime
    {
        public Thrown(Position start, Position end)
        {
            this.start = start;
            this.end = end;
        }

        public override void accept(Visitor visitor)
        {
            visitor.visitThrown(this);
        }
    }
}
