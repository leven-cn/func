/**
 * @file func_ctype.h
 * @brief Character processing
 *
 * Use the functions declared in <ctype.h> to test or alter characters
 * that you read in with fgetc, getc, getchar, all declared in <stdio.h>.
 * If you store such a value before you test it, declare the data object
 * to have type int. If you store in any character type instead, you lose
 * information. You may mistake an end-of-file indication for a valid
 * character. Or you may convert a valid character code to a negative
 * value, which is unacceptable.
 *
 * @warning If you generate an argument any other way, be careful. The
 * functions work properly only for the value EOF, defined in <stdio .h>,
 * and values that type unsigned char can represent. The characters in the
 * basic C character set have positive values when represented as type
 * char. Others may not.
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

#ifndef __FUNC_CTYPE_H
#define __FUNC_CTYPE_H

/* ctype code bits */
#define _XD 0x01  /* hex-digit: 0-9, A-F, a-f */
#define _UP 0x02  /* upper-letter: A-Z */
#define _SP 0x04  /* space: \t, ' ' */
#define _PU 0x08  /* punctuation */
#define _LO 0x10  /* lower-letter: a-z */
#define _DI 0x20  /* digit: 0-9 */
#define _CN 0x40  /* control: CR, FF, HI, NL, VT */
#define _BB 0x80  /* BEL, BS, etc. */
#define _XS 0x100 /* extra space */
#define _XA 0x200 /* extra letter */

/* ctype conversion table -- ASCII version */
extern const short *_ctype_tbl;

/**
 * @fn int func_isalpha(int c)
 * @brief Check for an alphabetic character
 *
 * @param c character to be checked.
 * @return 1 for alphabetic character, others for otherwise.
 */
int func_isalpha(int c);

/**
 * @fn int func_isdigit(int c)
 * @brief Check for an digit character
 *
 * @param c character to be checked.
 * @return 1 for digit character, others for otherwise.
 */
int func_isdigit(int c);

/**
 * @fn int func_isalnum(int c)
 * @brief Check for an alphanumeric character
 *
 * @param c character to be checked.
 * @return 1 for alphanumeric character, others for otherwise.
 */
int func_isalnum(int c);

/**
 * @fn int func_isxdigit(int c)
 * @brief Check for an hex-digit character
 *
 * @param c character to be checked.
 * @return 1 for hex-digit character, others for otherwise.
 */
int func_isxdigit(int c);

#endif /* __FUNC_CTYPE_H */
