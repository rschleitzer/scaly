(element language
    (make sequence

        (create-file ($ "Syntax.h" generated-extension)
            (output (syntax-h)))

        (create-file ($ "Syntax.cpp" generated-extension)
            (output (syntax-cpp)))

        (create-file ($ "Visitor.h" generated-extension)
            (output (visitor-h #f)))

        (create-file ($ "MyVisitor.h" generated-extension)
            (output (visitor-h #t)))

        (create-file ($ "MyVisitor.cpp" generated-extension)
            (output (visitor-cpp)))

        (create-file ($ "Parser.h" generated-extension)
            (output (parser-h)))

        (create-file ($ "Parser.cpp" generated-extension)
            (output (parser-cpp)))
))
