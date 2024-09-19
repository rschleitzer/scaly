#ifndef __Scaly_Containers__
#define __Scaly_Containers__

typedef __SIZE_TYPE__ size_t;

extern "C" void exit(int);
extern "C" void* memcpy(void *, const void*, size_t);
extern "C" int memcmp(const void*, const void *, size_t);
extern "C" void* memset(void*, int, size_t);
extern "C" size_t strlen(const char *);

#include "../memory/Object.h"
#include "../memory/PageNode.h"
#include "../memory/PageListIterator.h"
#include "../memory/PageList.h"
#include "../memory/Page.h"
#include "../memory/Region.h"

#include "List.h"
#include "Vector.h"
#include "Array.h"
#include "HashSetBuilder.h"
#include "HashSet.h"
#include "HashMapBuilder.h"
#include "HashMap.h"
#include "MultiMapBuilder.h"
#include "MultiMap.h"
#include "Result.cpp"

#include "String.h"
#include "StringBuilder.h"

#endif // __Scaly_Containers__
