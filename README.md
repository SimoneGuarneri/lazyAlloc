# Lazy Alloc

Lazy Alloc is a minimalist library for C dynamic memory allocation

![lazyMalloc](https://i.imgur.com/E5sVfBu.png)

## Installation

You can easily add it including the .c and .h files in your path and compiling with
```bash
gcc main.c lazyAlloc.c
```
Or

- MinGW (currently searching a way to add to path)
- [GNU/Linux or MacOS](https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html).

## Usage

```c
#include "lazyAlloc.h"
or
#include <lazyAlloc.h>
```

## Functions

### Main

- **lazyAlloc(size_t size)**: allocate size bytes and return a **void*** (with automatic check)

- **freeAllPointers()**: frees all pointers allocated by **lazyAlloc()** 
regardless of where they were allocated

- **setSteps()**: sets the number of steps. Step is the number of pointer you can allocate before array where the pointers are saved must be reallocated. _(higher is more speed efficent and safer, lower is more memory efficent and less safe)_



### Others 
- **xmalloc(size_t size):** same as _malloc_ but with automatic check

- **xrealloc(size_t size):** same as _malloc_ but with automatic check
