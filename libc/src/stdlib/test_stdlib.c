/**
 * Test <stdlib.h>
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

#include "func_stdlib.h"
#include "func_string.h"
#include <stdlib.h>
#include <assert.h>


int main()
{
    const char *env_var[] = {"PWD", "SHELL", "USER", "HOME", "LANG"};
    for (size_t i=0; i<sizeof(env_var)/sizeof(env_var[0]); i++) {
        const char *env_func = func_getenv(env_var[i]);
        const char *env_stdc = getenv(env_var[i]);
        
        if (env_func!=NULL && env_stdc!=NULL) {
            assert(func_strcmp(env_func, env_stdc) == 0);
        } else {
            assert(env_func == env_stdc);
        }
    }
    
    return 0;
}