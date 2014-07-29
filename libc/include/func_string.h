/**
 * @file func_string.h
 * @brief String processing
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

#ifndef __FUNC_STRING_H
#define __FUNC_STRING_H

#include <stddef.h>

/**
 * @fn size_t func_strlen(const char *str)
 * @brief Return the length of a string, excluding the terminating NUL byte.
 *
 * @warning glibc cannot handle NULL, may cause segmentation fault.
 *
 * @param str string to be calculated.
 * @return the length of the string.
 */
size_t func_strlen(const char *str);

/**
 * @fn size_t func_strncat(char *dst, const char *src, size_t n)
 * @brief Appends the <var>src</var> string to the <var>dst</var> string,
 *        overwriting the terminating null byte ('\0') at the end of
 *        <var>dst</var>, and then adds a terminating null byte.
 *
 * @warning The strings may not overlap, and the <var>dst</var> string must
 * have enough space for the result.
 *
 * @warning The <var>strcat</var> may cause memory overflow.
 *
 * @param dst destination string buffer.
 * @param src string to be appended.
 * @param n number of characters to be appended.
 * @return the destination string.
 */
char *func_strncat(char *dst, const char *src, size_t n);

/**
 * @fn int func_strcmp(const char *s1, const char *s2)
 * @brief Compare two strings.
 *
 * @param s1 one string.
 * @param s2 another string.
 * @return >0 if s1 > s2, <0 if s1 < s2, and ==0 if s1==s2.
 */
int func_strcmp(const char *s1, const char *s2);

/**
 * @fn int func_strncmp(const char *s1, const char *s2, size_t n)
 * @brief Compare first <var>n</var> characters of two strings.
 *
 * @param s1 one string.
 * @param s2 another string.
 * @param n number of first characters to be compared.
 * @return >0 if >, <0 if <, and ==0 if ==.
 */
int func_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @fn int func_memcmp(const void *p1, const void *p2, size_t n)
 * @brief Compare first <var>n</var> bytes of two memory areas.
 *
 * @param p1 one memory area.
 * @param p2 another memory area.
 * @param n number of first bytes to be compared.
 * @return >0 if >, <0 if <, and ==0 if ==.
 */
int func_memcmp(const void *p1, const void *p2, size_t n);

/**
 * @fn int func_strncpy(char *dst, const char *src, size_t n)
 * @brief Copy first <var>n</var> characters from string <var>src</var> to
 * string buffer <var>dst</var>.
 *
 * @warning The <var>strcpy()</var> may cause memory overflow.
 *
 * @param dst destination string buffer.
 * @param src source string.
 * @param n number of first characters to be copied.
 * @return pointer to destination string.
 */
char *func_strncpy(char *dst, const char *src, size_t n);

#endif /* __FUNC_STRING_H */
