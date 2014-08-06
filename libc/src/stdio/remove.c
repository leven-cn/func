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

#include "_stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int func_remove(const char *path)
{
    struct stat s;
    if (stat(path, &s) == -1) {
        return -1;
    }

    if (S_ISDIR(s.st_mode)) {
        return rmdir(path);
    } else {
        return unlink(path);
    }
}
