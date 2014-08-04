/**
 * Copyright 2014 Li Yun <leven.cn@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "_alloc.h"
#if _XOPEN_SOURCE >= 500 && \
        !(_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600)
#include <unistd.h>
#endif

_cell *_sbrk(size_t size)
{
#if _XOPEN_SOURCE >= 500 && \
        !(_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600)
    void *p = NULL;
    int isize = (int)size;
    
    /* Avoid using `brk()` and `sbrk()`: the malloc() memory allocation package
    is the portable and comfortable way of allocating memory.
    
    NOTE: brk() and sbrk() are removed in POSIX.1-2001. */
    return (isize<=0 || (p=sbrk(isize))==(void *)-1 ? NULL : p);
#else
    size += 0; // ignore GCC unused-parameter warning
    return NULL;
#endif
}
