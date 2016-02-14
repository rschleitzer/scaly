#ifndef __scalyc__Compiler__
#define __scalyc__Compiler__
#include "scalyc.h"
using namespace scaly;
namespace scalyc {

class Compiler {
public:
    static CompilerError* compileFiles(_Page* _ep, Options& options);
    static _Result<CompilationUnit, ParserError> compileUnit(_Page* _rp, _Page* _ep, _VarString* fileName, _VarString& text);
};

}

#endif /* defined(__scalyc__Compiler__) */