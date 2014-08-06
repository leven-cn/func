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
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

int func_fsetpos(FUNC_FILE *fp, const fpos_t *pos)
{
    if (fp == NULL) {
        errno = EBADF;
        return -1;
    }

    if (pos == NULL) {
        return 0;
    }

    if (func_fflush(fp) == EOF) {
        return -1;
    }

    off_t offset = lseek(fp->fd, (off_t)(pos->_offset), SEEK_SET);
    if (offset == -1) {
        return -1;
    }

    if (fp->_mode & (_FM_READ|_FM_WRITE)) {
        fp->_next = fp->_buf;
        fp->_rend = fp->_buf;
        fp->_wend = fp->_buf;
        fp->_nback = 0;
    }
    fp->_mode &= (~(_FM_EOF|_FM_READ|_FM_WRITE));
    return 0;
}
