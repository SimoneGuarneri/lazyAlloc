#include "lazyAlloc.h"

static int steps = 20;
static int allocatedPointersLength = 0;
static int allocatedPointersMemory = 0;
static void** allocatedPointers;

void* xrealloc(void *p, size_t newSize){

    void* temp = realloc(allocatedPointers, allocatedPointersMemory * sizeof(void*));

    if(!temp){
        fprintf(stderr, "realloc(%lu) failed. Exiting.\n", allocatedPointersMemory);
        abort();
    }

    return p;    
}

void *xmalloc(size_t size){

    void *p = malloc(size);

    if(!p){
        fprintf(stderr, "malloc(%lu) failed. Exiting.\n", size);
        abort();
    }

    return p;
}

static void updatePointers(void *p){

    if(allocatedPointersLength > steps){
        
        allocatedPointersMemory += steps;
        void* temp = xrealloc(allocatedPointers, allocatedPointersMemory * sizeof(void*));
        
        allocatedPointers = temp;
    }

    allocatedPointers[allocatedPointersLength] = p;
    allocatedPointersLength++;
    
}

void setSteps(size_t size){
    steps = size;
}

void* lazyAlloc(size_t size){

    if(!allocatedPointers){

        allocatedPointersMemory += steps;
        allocatedPointers = xmalloc(sizeof(void*)* allocatedPointersMemory);        
    }

    void *p = xmalloc(size);
    updatePointers(p);
    
    return p;
}

void freeAllPointers(){

    int i;
    for(i = 0; i < allocatedPointersLength; i++){
        free(allocatedPointers[i]);
    }

    printf("\nMemory Freed Correctly, %d pointers Freed", i);
}
