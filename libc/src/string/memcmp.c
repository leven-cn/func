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

int func_memcmp(const void *p1, const void *p2, size_t n)
{
    const unsigned char *up1 = (unsigned char *)p1;
    const unsigned char *up2 = (unsigned char *)p2;
    
    while (n > 0) {
        if (*up1 != *up2) {
            return (*up1<*up2) ? -1 : +1;
        }
        up1++;
        up2++;
        n--;
    }
    return 0;
}
