(define (visitor-h concrete) ($
"#ifndef __scalyc__"(if concrete "My" "")"Visitor__
#define __scalyc__"(if concrete "My" "")"Visitor__
#include \"scalyc.h\"
using namespace scaly;
namespace scalyc {
"
    (if concrete "" ($
        (apply-to-selected-children "syntax" (lambda (syntax-node) ($
"
class "(id syntax-node)";"
        )))
"
"   ))
"
class "(if concrete "MyVisitor : public " "")"SyntaxVisitor {
public:"
    (apply-to-selected-children "syntax" (lambda (syntax) ($ "
    virtual void Open"(id syntax)"("(id syntax)"& "(string-firstchar-downcase (id syntax))")"(if concrete "" "= 0")";
    virtual void Close"(id syntax)"("(id syntax)"& "(string-firstchar-downcase (id syntax))")"(if concrete "" "= 0")";"
    )))
"
};

}
#endif // __scalyc__"(if concrete "My" "")"Visitor__
"
))

(define (visitor-cpp) ($
"#include \"scalyc.h\"
using namespace scaly;
namespace scalyc {

"
    (apply-to-selected-children "syntax" (lambda (syntax) ($
"
void MyVisitor::Open"(id syntax)"("(id syntax)"& "(string-firstchar-downcase (id syntax))") {
}

void MyVisitor::Close"(id syntax)"("(id syntax)"& "(string-firstchar-downcase (id syntax))") {
}
"    )))
"
}
"
))
