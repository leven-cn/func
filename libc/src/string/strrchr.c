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

#include "func_string.h"

char *func_strrchr(const char *str, int c)
{
    const char ch = (char)c;
    for (const char *sc=NULL; ; str++) {
        /* check another char */
        if (*str == ch) {
            sc = str;
        }
        if (*str == '\0') {
            return (char *)sc;
        }
    }
}
