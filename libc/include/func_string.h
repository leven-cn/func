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

#endif /* __FUNC_STRING_H */
