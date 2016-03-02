#ifndef __scaly__scalyc__
#define __scaly__scalyc__

#include "Scaly.h"
#include "Lexer.h"
#include "Visitor.h"
#include "Syntax.h"
#include "MyVisitor.h"
#include "CppError.h"
#include "CppVisitor.h"
#include "ParserError.h"
#include "Parser.h"
#include "OptionsError.h"
#include "Options.h"
#include "CompilerError.h"
#include "Compiler.h"
#include "scalyc.h"

using namespace scaly;
namespace scalyc {
int _main(_Vector<_LetString>* arguments);
}

#endif // __scaly__scalyc__
