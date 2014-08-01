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

char *func_strstr(const char *str, const char *sub)
{
    if (*sub == '\0') {
        return (char *)str;
    }
    
    /* match rest of prefix */
    for (; (str=func_strchr(str, *sub)) != NULL; str++) {
        const char *sc1, *sc2;
        for (sc1=str, sc2=sub; ;) {
            if (*++sc2 == '\0') {
                return (char *)str;
            } else if ( *++sc1 != *sc2) {
                break;
            }
        }
    }
    
    return NULL; // not found
}
