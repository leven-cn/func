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
#include "func_string.h"
#include <unistd.h>
#include <stdlib.h>

static int _fputs(FUNC_FILE *fp);

int func_fputs(const char *s, FUNC_FILE *fp)
{
    while (*s) {
        if (fp->_next < fp->_wend) {
        } else if (_fputs(fp) < 0) {
            return EOF;
        }

        {
            const char *p = fp->_mode & _FM_LBF ? func_strchr(s, '\n') : NULL;
            size_t m = p ? (size_t)(p - s +1) : func_strlen(s);
            size_t n = fp->_wend - fp->_next;
            if (n < m) {
                p = NULL;
                m = n;
            }
            func_memcpy(fp->_next, s, m);
            s += m;
            fp->_next += m;
            if (p && func_fflush(fp)) {
                fp->_wend = fp->_buf;
                return EOF;
            }
        }
    }

    if (fp->_mode & _FM_NBF) {
        fp->_wend = fp->_buf;
        if (func_fflush(fp)) {
            return EOF;
        }
    }

    return 0;
}

static int _fputs(FUNC_FILE *fp)
{
    if (fp->_next < fp->_wend) {
        return 0;
    } else if (fp->_mode & _FM_WRITE) {
        return func_fflush(fp);
    } else if ((fp->_mode&(_FM_OPEN_WRITE|_FM_WRITE)) != _FM_OPEN_WRITE) {
        fp->_mode |= _FM_ERROR;
        return -1;
    }

    /* allocate buffer memory */
    if (fp->_buf) {
    } else if ((fp->_buf=malloc(BUFSIZ)) == NULL) {
        fp->_buf = &fp->cbuf;
        fp->_end = fp->_buf + 1;
    } else {
        fp->_mode |= _FM_ALLOC_BUF;
        fp->_end = fp->_buf + BUFSIZ;
    }

    fp->_next = fp->_buf;
    fp->_rend = fp->_buf;
    fp->_wend = fp->_end;
    fp->_mode |= _FM_WRITE;
    return 0;
}
