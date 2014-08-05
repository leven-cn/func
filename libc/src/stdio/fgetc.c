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
#include <unistd.h>
#include <stdlib.h>

int func_fgetc(FUNC_FILE *fp)
{
    if (fp->_nback > 0) {
        if (--fp->_nback == 0) {
            fp->_rend = fp->_save;
        }
        return fp->_back[fp->_nback];
    }

    if (fp->_next < fp->_rend) {
    } else if (_fgets(fp) <= 0) {
        return EOF;
    }

    return *fp->_next++;
}
