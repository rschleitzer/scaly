(define (syntax) ($

"
    public abstract class SyntaxNode
    {
        public Position start;
        public Position end;
        public SyntaxNode parent;

        public abstract void accept(Visitor visitor);
    }
"
    (apply-to-selected-children "syntax" (lambda (syntax-node) ($
"
    public class "(id syntax-node)" : "(if (base syntax-node) (base syntax-node) "SyntaxNode")"
    {"        (apply-to-children-of syntax-node (lambda (content) ($
            (if (property content) ($
"
        public "
                (case (type content)
                    (("syntax") ($ (link content)(if (multiple? content)"[]" "")))
                    (("identifier") "string")
                    (("literal") "Literal")
                    (("keyword" "punctuation") "bool")
                )
                " "(property content)";"
          )"")
        )))
        (if (abstract? syntax-node) "" ($
"
        public "(id syntax-node)"("(if (program? syntax-node) "" ($ "Position start, Position end"(if (node-list-empty? (properties syntax-node)) "" ", ")))
            (apply-to-property-children-of syntax-node (lambda (content) ($
                (case (type content)
                    (("syntax") ($ (link content)(if (multiple? content)"[]" "")" "(property content)))
                    (("identifier") ($ "string "(property content)))
                    (("literal") ($ "Literal "(property content)))
                    (("keyword" "punctuation") ($ "bool "(property content)))
                )
                (if (properties-remaining? content syntax-node) ", " "")
            )))
            ")
        {
"           (if (program? syntax-node)
"            start = new Position(0, 0);
            end = new Position(0, 0);
            this.name = name;
            this.files = files;
            this.parent = null;
"
                ($
"            this.start = start;
            this.end = end;
"                   (apply-to-property-children-of syntax-node (lambda (content) ($
"            this."(property content)" = "(property content)";
"
                    )))
                )
            )
"        }
"       ))
"
        public override void accept(Visitor visitor)
        {
"       (if (abstract? syntax-node) "" ($
            (if (has-syntax-children? syntax-node)
                ($
"            if (!visitor.open"(id syntax-node)"(this))
                return;

"
                    (apply-to-children-of syntax-node (lambda (content)
                        (case (type content)
                            (("syntax") ($
                                (if (abstract? syntax-node) "" ($
                                    (if (and (optional? content) (not (multiple? content))) ($
"        if ("(property content)" != null)
"
                                    )"")
                                    (if (multiple? content)
                                        ($
"            if ("(property content)" != null)
            {
                foreach ("(link content)" node in "(property content)")
                    node.accept(visitor);
            }
"
                                        )
                                        ($
(if (optional? content) "    " "")"        "(property content)".accept(visitor);
"
                                        )
                                    )
                                ))
                            ))
                            (else "")
                        )
                    ))
"            visitor.close"(id syntax-node)"(this);
"
                )
                ($
"            visitor.visit"(id syntax-node)"(this);
"
                )
            )
       ))
"        }
"
"    }
"   )))
"}
"
))

(define (inheritors node)
    (if (abstract? node) (node-list-union
        (children node)
        (apply node-list-union
            (map inheritors
                (node-list->list
                    (node-list-map
                        (lambda (content-node)
                            (element-with-id (link content-node))
                        )
                        (children node)))))
    )(empty-node-list))
)
