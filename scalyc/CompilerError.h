#ifndef __scalyc__CompilerError__
#define __scalyc__CompilerError__
#include "scalyc.h"
using namespace scaly;
namespace scalyc {

class CompilerError;

class _CompilerError_fileNotFound : public Object {
public:
    _CompilerError_fileNotFound(string* file);

    string* file;
};

class _CompilerError_unableToReadFile : public Object {
public:
    _CompilerError_unableToReadFile(string* file, FileError* error);

    string* file;
    FileError* error;
};

class _CompilerError_syntaxError : public Object {
public:
    _CompilerError_syntaxError(ParserError* error);

    ParserError* error;
};

class _CompilerError_unableToCreateOutputDirectory : public Object {
public:
    _CompilerError_unableToCreateOutputDirectory(string* directory, DirectoryError* error);

    string* directory;
    DirectoryError* error;
};
enum _CompilerErrorCode {
    _CompilerErrorCode_fileNotFound = 1,
    _CompilerErrorCode_unableToReadFile,
    _CompilerErrorCode_syntaxError,
    _CompilerErrorCode_unableToCreateOutputDirectory,
};

class CompilerError : public Object {
public:
    CompilerError(_CompilerErrorCode errorCode)
    : errorCode(errorCode), errorInfo(0) {}

    CompilerError(_CompilerError_fileNotFound* fileNotFound)
    : errorCode(_CompilerErrorCode_fileNotFound), errorInfo(fileNotFound) {}

    CompilerError(_CompilerError_unableToReadFile* unableToReadFile)
    : errorCode(_CompilerErrorCode_unableToReadFile), errorInfo(unableToReadFile) {}

    CompilerError(_CompilerError_syntaxError* syntaxError)
    : errorCode(_CompilerErrorCode_syntaxError), errorInfo(syntaxError) {}

    CompilerError(_CompilerError_unableToCreateOutputDirectory* unableToCreateOutputDirectory)
    : errorCode(_CompilerErrorCode_unableToCreateOutputDirectory), errorInfo(unableToCreateOutputDirectory) {}

    long _getErrorCode();
    void* _getErrorInfo();

    _CompilerError_fileNotFound* get_fileNotFound();
    _CompilerError_unableToReadFile* get_unableToReadFile();
    _CompilerError_syntaxError* get_syntaxError();
    _CompilerError_unableToCreateOutputDirectory* get_unableToCreateOutputDirectory();

private:
    _CompilerErrorCode errorCode;
    void* errorInfo;
};

class CppError;

class _CppError_unableToCreateOutputDirectory : public Object {
public:
    _CppError_unableToCreateOutputDirectory(string* directory, DirectoryError* error);

    string* directory;
    DirectoryError* error;
};
enum _CppErrorCode {
    _CppErrorCode_unableToCreateOutputDirectory = 1,
};

class CppError : public Object {
public:
    CppError(_CppErrorCode errorCode)
    : errorCode(errorCode), errorInfo(0) {}

    CppError(_CppError_unableToCreateOutputDirectory* unableToCreateOutputDirectory)
    : errorCode(_CppErrorCode_unableToCreateOutputDirectory), errorInfo(unableToCreateOutputDirectory) {}

    long _getErrorCode();
    void* _getErrorInfo();

    _CppError_unableToCreateOutputDirectory* get_unableToCreateOutputDirectory();

private:
    _CppErrorCode errorCode;
    void* errorInfo;
};

}
#endif // __scalyc__CompilerError__
