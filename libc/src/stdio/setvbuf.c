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
#include <stdlib.h>
#include <limits.h>

int func_setvbuf(FUNC_FILE *fp, char *buf, int mode, size_t size)
{
    if (fp->_mode & (_FM_READ|_FM_WRITE)) {
        return -1;
    }

    int _mode = -1;
    _mode = (mode == _IOFBF) ? 0
        : (_mode == _IOLBF ? _FM_LBF
        : (_mode == _IONBF) ? _FM_NBF : -1);
    if (_mode == -1) {
        return -1;
    }

    /* setup size of buffer */
    if (size == 0) {
        fp->_buf = &(fp->cbuf);
        size = 1;
    } else if (size > INT_MAX) {
        size = INT_MAX;
    }

    /* setup buffer */
    if (buf) {
    } else if ((buf=(char *)malloc(size)) == NULL) {
        return -1;
    } else {
        _mode |= _FM_ALLOC_BUF;
    }

    if (fp->_mode & _FM_ALLOC_BUF) {
        free(fp->_buf);
        fp->_mode &= ~_FM_ALLOC_BUF;
    }

    fp->_mode |= _mode;
    fp->_buf = (unsigned char *)buf;
    fp->_end = (unsigned char *)(buf + size);
    fp->_next = (unsigned char *)buf;
    fp->_rend = (unsigned char *)buf;
    fp->_wend = (unsigned char *)buf;

    return 0;
}
