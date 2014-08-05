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

int func_fputc(int c, FUNC_FILE *fp)
{
    unsigned char cc = (unsigned char)c;

    if (fp->_next < fp->_wend) {
    } else if (_fputs(fp) < 0) {
        return EOF;
    }

    *(fp->_next)++ = cc;
    if (fp->_mode & (_FM_LBF|_FM_NBF)) {
        fp->_wend = fp->_buf;
        if ((fp->_mode & _FM_NBF || cc == '\n') && func_fflush(fp)) {
            return EOF;
        }
    }
    return cc;
}
