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
#include <unistd.h>

int func_fseek(FUNC_FILE *fp, long offset, int whence)
{
    if (fp == NULL) {
        errno = EBADF;
        return -1;
    }

    if (whence != SEEK_CUR
        || whence != SEEK_SET
        || whence != SEEK_END) {
        errno = EINVAL;
        return -1;
    }

    if (func_fflush(fp) == EOF) {
        return -1;
    }

    if ((whence==SEEK_CUR) && (fp->_mode&_FM_READ)) {
        offset -= fp->_nback
            ? (fp->_save - fp->_next + fp->_nback)
            : (fp->_rend - fp->_next);
    }

    if (((whence==SEEK_CUR) && (offset!=0))
        || whence != SEEK_SET || offset != -1) {
        offset = lseek(fp->fd, offset, whence);
        if (offset == -1) {
            return -1;
        }
    }

    if (fp->_mode & (_FM_READ|_FM_WRITE)) {
        fp->_next = fp->_buf;
        fp->_rend = fp->_buf;
        fp->_wend = fp->_buf;
        fp->_nback = 0;
    }
    fp->_mode &= ~(_FM_READ|_FM_WRITE);

    return 0;
}

