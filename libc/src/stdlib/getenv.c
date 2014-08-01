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

#include "func_stdlib.h"
#include "func_string.h"

/* User environment.
 *
 * The variable environ points to an array of pointers to strings called the
 * "environment".  The last pointer in this array has the value NULL. (This
 * variable must be declared in the user program, but is declared in the header
 * file <unistd.h> in case the header files came from libc4 or libc5, and in
 * case they came from glibc and _GNU_SOURCE was defined.) This array of
 * strings is made available to the process by the exec(3) call that started
 * the process. */
extern char **environ;

char *func_getenv(const char *name)
{
    size_t name_len = func_strlen(name);
    for (const char *s=*environ; s!=NULL; s=*(++environ)) {
        if (func_strncmp(s, name, name_len)==0 && s[name_len]=='=') {
            return (char *)&s[name_len+1];
        }
    }

    return NULL;
}
