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
 * @fn char *func_strncat(char *dst, const char *src, size_t n)
 * @brief Appends the <var>src</var> string to the <var>dst</var> string,
 * overwriting the terminating null byte (<code>'\0'</code>) at the end of
 * <var>dst</var>, and then adds a terminating null byte.
 *
 * @warning The strings may not overlap, and the <var>dst</var> string must
 * have enough space for the result.
 *
 * @warning The <var>strcat</var> may cause memory overflow.
 *
 * @param dst destination string buffer.
 * @param src string to be appended.
 * @param n number of characters to be appended.
 * @return a pointer to the destination string.
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
 * @fn char *func_strncpy(char *dst, const char *src, size_t n)
 * @brief Copy first <var>n</var> characters from string <var>src</var> to
 * string buffer <var>dst</var>.
 *
 * @warning The <var>strcpy()</var> may cause memory overflow.
 *
 * @param dst destination string buffer.
 * @param src source string.
 * @param n number of first characters to be copied.
 * @return a pointer to destination string.
 */
char *func_strncpy(char *dst, const char *src, size_t n);

/**
 * @fn void *func_memcpy(void *dst, const void *src, size_t n)
 * @brief Copy first <var>n</var> bytes from memory area <var>src</var> to
 * memory area <var>dst</var>.
 *
 * @warning The memory areas must NOT overlap.
 *
 * @param dst destination memory area.
 * @param src source memory area.
 * @param n number of first bytes to be copied.
 * @return a pointer to destination memory area.
 */
void *func_memcpy(void *dst, const void *src, size_t n);

/**
 * @fn void *func_memmove(void *dst, const void *src, size_t n)
 * @brief Copy first <var>n</var> bytes from memory area <var>src</var> to
 * memory area <var>dst</var>. The memory areas may overlap: copying takes
 * place as though the bytes in <var>src</var> are first copied into a
 * temporary array that does not overlap <var>src</var> or <var>dst</var>, and
 * the bytes are then copied from the temporary array to <var>dst</var>.
 *
 * @param dst destination memory area.
 * @param src source memory area.
 * @param n number of first bytes to be copied.
 * @return a pointer to destination memory area.
 */
void *func_memmove(void *dst, const void *src, size_t n);

/**
 * @fn void *func_memset(void *p, int c, size_t n)
 * @brief Fills the first <var>n</var> bytes of the memory area pointed to by
 * <var>p</var> with the constant byte <var>c</var>.
 *
 * @param p a pointer to memory area.
 * @param c constant byte filled.
 * @param n number of first bytes to be filled.
 * @return a pointer to memory area.
 */
void *func_memset(void *p, int c, size_t n);

/**
 * @fn char *func_strchr(const char *str, int c)
 * @brief Find first occurrence of <var>c</var> in string <var>str</var>.
 *
 * @param str the string to be scanned.
 * @param c the character to be found.
 * @return a pointer to the first occurrence of the character <var>c</var> in
 * the string <var>str</var> or <code>NULL</code> if the character is not found.
 */
char *func_strchr(const char *str, int c);

/**
 * @fn char *func_strrchr(const char *str, int c)
 * @brief Find last occurrence of <var>c</var> in string <var>str</var>.
 *
 * @param str the string to be scanned.
 * @param c the character to be found.
 * @return a pointer to the last occurrence of the character <var>c</var> in
 * the string <var>str</var> or <code>NULL</code> if the character is not found.
 */
char *func_strrchr(const char *str, int c);

/**
 * @fn void *func_memchr(const void *p, int c, size_t n)
 * @brief Scan the initial <var>n</var> bytes of the memory area pointed to by
 * <var>p</var> for the first instance of <var>c</var>. Both <var>c</var> and
 * the bytes of the memory area pointed to by <var>p</var> are interpreted as
 * <code>unsigned char</code>.
 *
 * @param p the memory area to be scanned.
 * @param c the byte/character to be found.
 * @return a pointer to the first occurrence of the byte/character <var>c</var>
 * in the memory area <var>p</var> or <var>NULL</var> if the byte/character is
 * not found.
 */
void *func_memchr(const void *p, int c, size_t n);

/**
 * @fn char *func_strstr(const char *str, const char *sub)
 * @brief Find the first occurrence of the substring <var>sub</var> in the
 * string <var>str</var>. The terminating null bytes (<code>'\0'</code>) are
 * not compared.
 *
 * @param str the string to be scanned.
 * @param sub the substring to be found.
 * @return a pointer to the first occurrence of the substring <var>sub</var> in
 * the string <var>str</var> or <code>NULL</code> if the substring is not found.
 */
char *func_strstr(const char *str, const char *sub);

#endif /* __FUNC_STRING_H */
