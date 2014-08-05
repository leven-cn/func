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

int func_ungetc(int c, FUNC_FILE *fp)
{
    if (c == EOF || sizeof(fp->_back) <= fp->_nback
        || (fp->_mode & (_FM_OPEN_READ|_FM_WRITE)) != (_FM_OPEN_READ)) {
        return EOF;
    }
    fp->_mode = fp->_mode & (~_FM_EOF | _FM_READ);
    if (fp->_nback == 0) {
        fp->_save = fp->_rend;
        fp->_rend = fp->_buf;
    }
    fp->_back[fp->_nback++] = c;
    return (unsigned char)c;
}
