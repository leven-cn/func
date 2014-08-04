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

int func_fflush(FUNC_FILE *fp) {
    if (fp == NULL) {
        /* flush all output streams */
        int status = 0;
        for (int i=0; i<FOPEN_MAX; i++) {
            if (_files[i] && func_fflush(_files[i]) < 0) {
                status = EOF;
            }
        }
        return status;
    }

    if (!(fp->_mode & _FM_OPEN_WRITE)) {
        /* The standards do not specify the behavior for input stream */
        return 0;
    }

    ssize_t n = write(fp->fd, fp->_buf, (size_t)(fp->_end-fp->_buf));
    if (n < 0) {
        fp->_end = fp->_buf;
        fp->_mode = _FM_ERROR;
        return EOF;
    }

    return 0;
}
