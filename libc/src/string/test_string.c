/**
 * Test <string.h>
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

#include "func_string.h"
#include <limits.h>
#include <string.h>
#include <assert.h>


static char *src = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

int main()
{
    /* Test strlen() */
    assert(func_strlen("") == strlen(""));
    assert(func_strlen("string") == strlen("string"));
    
    /* Test strcmp() */
    assert(func_strcmp("abc", "bbc") < 0);
    assert(func_strcmp("bbc", "abc") > 0);
    assert(func_strcmp("abc", "abc") == 0);
    assert(func_strcmp("abc", "aac") > 0);
    assert(func_strcmp("aac", "abc") < 0);
    assert(func_strcmp("abcde", "abc") > 0);
    assert(func_strcmp("aacde", "abc") < 0);
    
    /* Test strncmp() */
    assert(func_strncmp("abc","bbc", 3) < 0);
    assert(func_strncmp("bbc", "abc", 3) > 0);
    assert(func_strncmp("abc", "abc", 3) == 0);
    assert(func_strncmp("abc", "aac", 3) > 0);
    assert(func_strncmp("aac", "abc", 3) < 0);
    assert(func_strncmp("abcde", "abc", 5) > 0);
    assert(func_strncmp("aacde", "abc", 5) < 0);
    assert(func_strncmp("abcde", "abc", 3) == 0);
    
    /* Test memcmp() */
    assert(func_memcmp("abc","bbc", 3) < 0);
    assert(func_memcmp("bbc", "abc", 3) > 0);
    assert(func_memcmp("abc", "abc", 3) == 0);
    assert(func_memcmp("abc", "aac", 3) > 0);
    assert(func_memcmp("aac", "abc", 3) < 0);
    assert(func_memcmp("abcde", "abc", 5) > 0);
    assert(func_memcmp("aacde", "abc", 5) < 0);
    assert(func_memcmp("abcde", "abc", 3) == 0);
    
    /* Test strncat() */
    char dst_stdc[8] = "a";
    char dst_func[8] = "a";
    size_t n = 8 - strlen(dst_stdc) - 1;
    assert(strcmp(strncat(dst_stdc,src,n), func_strncat(dst_func,src,n)) == 0);
    
    /* Test strncpy() */
    char dst_strncpy_stdc[8];
    char dst_strncpy_func[8];
    strncpy(dst_strncpy_stdc, src, 7);
    func_strncpy(dst_strncpy_func, src, 7);
    assert(strcmp(dst_strncpy_stdc, dst_strncpy_stdc)==0 \
            && strlen(dst_strncpy_stdc)==strlen(dst_strncpy_func));
            
    /* Test memcpy() */
    char dst_memcpy_stdc[8];
    char dst_memcpy_func[8];
    memcpy(dst_memcpy_stdc, src, 7);
    func_memcpy(dst_memcpy_func, src, 7);
    assert(memcmp(dst_memcpy_stdc, dst_memcpy_func, 7) == 0);
            
    /* Test memmove() */
    char dst_memmove_stdc[8];
    char dst_memmove_func[8];
    memmove(dst_memmove_stdc, src, 7);
    func_memmove(dst_memmove_func, src, 7);
    assert(memcmp(dst_memmove_stdc, dst_memmove_func, 7) == 0);
            
    /* Test memset() */
    char memset_buf[6] = "123456";
    assert(memcmp(memset(memset_buf, 0, 6), "\0\0\0\0\0\0", 6) == 0);
    assert(func_memcmp(memset(memset_buf, 0, 6), "\0\0\0\0\0\0", 6) == 0);
    
    /* Test strchr() and strrchr() */
    char *s_strchr = "123456";
    for (char *s=s_strchr; *s!='\0'; s++) {
        assert(strchr(s_strchr, (int)(*s)) \
                == func_strchr(s_strchr, (int)(*s)));
        assert(strrchr(s_strchr, (int)(*s)) \
                == func_strrchr(s_strchr, (int)(*s)));
        assert(memchr(s_strchr, (int)(*s), strlen(s_strchr)) \
                == func_memchr(s_strchr, (int)(*s), strlen(s_strchr)));
    }
    
    return 0;
}
