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

int func_fgetpos(FUNC_FILE *fp, fpos_t *pos)
{
    if (fp == NULL) {
        errno = EBADF;
        return -1;
    }

    if (pos == NULL) {
        /* ignore */
        return 0;
    }

    off_t offset = lseek(fp->fd, 0, SEEK_CUR);
    if (offset == -1) {
        return -1;
    }

    if (fp->_mode & _FM_WRITE) {
        offset += fp->_next - fp->_buf;
    } else if (fp->_mode & _FM_READ) {
        offset -= fp->_nback ? (fp->_save - fp->_next + fp->_nback)
            : (fp->_rend - fp->_next);
    }

    pos->_offset = (unsigned long)offset;
    return 0;
}
