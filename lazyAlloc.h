#ifndef _LAZYALLOC_H
#define _LAZYALLOC_H

#include <stdio.h>
#include <stdlib.h>

extern void* xrealloc(void *p, size_t newSize);
extern void* xmalloc(size_t size);
extern void* lazyAlloc(size_t size);
static void updatePointers(void *p);
extern void setSteps();
extern void freeAllPointers();

#endif