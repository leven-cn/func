/**
 * @file func_stdlib.h
 * @brief Utilities.
 *
 * The <stdlib.h> includes:
 *
 *     * integer math (as, div, labs, and ldiv) - performing simple integer
 *       arithmetic.
 *
 *     * algorithms (bsearch, qsort, rand, and srand) - capturing operations
 *       complex and widespread enough to warrant packaging as library
 *       functions.
 *
 *     * text conversions (atof, atoi, atol, strtod, strtol, and strtoul) -
 *       determining encoded arithmetic values from text representations.
 *
 *     * multibyte conversions (mblen, mbstowcs, mbtowc, wcstombs, and wctomb)
 *       - mapping between multibyte and wide-character encodings.
 *
 *     * storage allocation (calloc, free, malloc, and realloc) - managing a
 *       heap of data objects.
 *
 *     * environmental interactions (abort, atexit, exit, getenv, and system) -
 *       interfacing between the program and the execution environment.
 *
 * 
 * @warning NOT all functions are included in this header file.
 *
 * @section License
 *
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

#ifndef __FUNC_STDLIB_H
#define __FUNC_STDLIB_H

#include <stddef.h>

/**
 * @fn char *func_getenv(const char *name)
 * @brief Get the environment variable.
 *
 * @param name environment variable name.
 * @return a pointer to the corresponding value string or <code>NULL</code> if
 * no environment variable available.
 */
char *func_getenv(const char *name);

/**
 * @fn void func_free(void *p)
 * @brief Frees the memory space pointed to by <var>p</var>, which must have
 * been returned by a previous call to <code>malloc()</code>,
 * <code>calloc()</code> or <code>realloc()</code>. Otherwise, or if
 * <code>free(p)</code> has already been called before, undefined behavior
 * occurs. If <var>p</var> is <code>NULL</code>, no operation is performed.
 *
 * @param p pointer to memory space to be freed.
 */
void func_free(void *p);

/**
 * @fn void *func_malloc(size_t size)
 * @brief Allocates <var>size</var> bytes and returns a pointer to the
 * allocated memory. The memory is NOT initialized. If size is 0, then
 * <code>malloc()</code> returns either <code>NULL</code>, or a unique pointer
 * value that can later be successfully passed to <code>free()</code>.
 *
 * @param size bytes of memory allocated.
 * @return a pointer to the allocated memory.
 */
void *func_malloc(size_t size);

#endif /* __FUNC_STDLIB_H */
