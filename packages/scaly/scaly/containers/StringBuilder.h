#ifndef _StringBuilder_h
#define _StringBuilder_h
#include "../../scaly.h"
using namespace scaly;
using namespace scaly::memory;

struct StringBuilder : Object {
    Array<char> buffer;

    StringBuilder(Array<char> buffer);
    StringBuilder();
    StringBuilder(size_t size);
    StringBuilder(char character);
    StringBuilder(String string);
    StringBuilder(const_char* c_string);
    void append(char character);
    void append(String string);
    void append(const_char* c_string);
    void append(char* start, size_t length);
    size_t get_length();
    String to_string(Page* rp);
};

#endif