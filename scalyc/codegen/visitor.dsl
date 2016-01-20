(define (visitor-h concrete) ($
"#ifndef __scalyc__"(if concrete "My" "")"Visitor__
#define __scalyc__"(if concrete "My" "")"Visitor__
#include \"scalyc.h\"
using namespace scaly;
namespace scalyc {

class "(if concrete "MyVisitor : public " "")"SyntaxVisitor {"
    (apply-to-selected-children "syntax" (lambda (syntax) ($ "
    virtual void Visit"(id syntax)"("(id syntax)")"(if concrete "" "= 0")";"
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
void MyVisitor::Visit"(id syntax)"("(id syntax)") {
}
"    )))
"
}
"
))
