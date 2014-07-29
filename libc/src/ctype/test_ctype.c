/**
 * Test <ctype.h>
 *
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

#include "func_ctype.h"
#include <limits.h>
#include <ctype.h>
#include <assert.h>


int main()
{
    for (int c=0; c < UCHAR_MAX+1; c++) { // UCHAR+1 to test character not in ASCII character set
        assert(!((func_isalpha(c) && !isalpha(c)) || (!func_isalpha(c) && isalpha(c))));
        assert(!((func_isdigit(c) && !isdigit(c)) || (!func_isdigit(c) && isdigit(c))));
        assert(!((func_isalnum(c) && !isalnum(c)) || (!func_isalnum(c) && isalnum(c))));
        assert(!((func_isxdigit(c) && !isxdigit(c)) || (!func_isxdigit(c) && isxdigit(c))));
        assert(!((func_isspace(c) && !isspace(c)) || (!func_isspace(c) && isspace(c))));
        assert(!((func_islower(c) && !islower(c)) || (!func_islower(c) && islower(c))));
        assert(!((func_isupper(c) && !isupper(c)) || (!func_isupper(c) && isupper(c))));
        assert(!((func_iscntrl(c) && !iscntrl(c)) || (!func_iscntrl(c) && iscntrl(c))));
        
        assert(func_tolower(c) == tolower(c));
        assert(func_toupper(c) == toupper(c));
    }
    
    return 0;
}