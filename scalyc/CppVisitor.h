#ifndef __scalyc__CppVisitor__
#define __scalyc__CppVisitor__
#include "scalyc.h"
using namespace scaly;
namespace scalyc {

class Inherits : public Object {
public:
    string* name;
    _Array<string>* inheritors;
    Inherits(string* className);

};

class CppVisitor : public Visitor {
public:
    string* moduleName;
    virtual void execute(Program* program);
    virtual bool hasArrayPostfix(Type* type);
    virtual bool isClass(string* name) = 0;
    virtual void appendCppType(VarString* s, Type* type);
    virtual void appendCppTypeName(VarString* s, Type* type);

    virtual bool _isCppVisitor();
    virtual bool _isHeaderVisitor();
    virtual bool _isSourceVisitor();
};

}
#endif // __scalyc__CppVisitor__
