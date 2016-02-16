#ifndef __Scaly_Page__
#define __Scaly_Page__
namespace scaly {

class _Page {
public:
    _Page(size_t size);
    _Page* previous();
    void reset();
    void clear();
    void* operator new(size_t size, void* location);
    void* allocateObject(size_t size);
    static _Page* allocateNextPage(_Page* previousPage);
    _Page* allocateExtensionPage(size_t size);
    _Page* allocateExclusivePage();
    static void forget(_Page* page);
    void deallocatePageExtensions();
    static void reclaimArray(void* address);
    static _Page* getPage(void* address);
    bool extend(void* address, size_t size);
    size_t getSize();
    static void initStatistics();

    static const size_t pageSize = 0x1000;

private:
    _Page** getLastExtensionPageLocation();
    static void deallocateExtensionsOfPage(_Page* page);
    _Page* findExtensionChainEnd();
    void freeExtensionPage(_Page* page);
    static _Page* allocate(size_t size);

    _Page* currentPage;
    _Page* previousPage;
    size_t size;
    _Page* extendingPage;
    _Page** nextExtensionPageLocation;

    void* nextObject;
};

}

#endif // __Scaly_Page__

