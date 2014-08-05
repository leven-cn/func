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

int func_fclose(FUNC_FILE *fp)
{
    if (fp == NULL) {
        return 0;
    }

    int stat = func_fflush(fp);
    if (fp->_mode & _FM_ALLOC_BUF) {
        free(fp->_buf);
    }
    fp->_buf = NULL;
    fp->_end = NULL;

    if (fp->fd >= 0 && close(fp->fd) == -1) {
        stat = EOF;
    }

    if (fp->_mode & _FM_ALLOC_FILE) {
        free(fp);
        _files[fp->_index] = NULL;
    }
    fp->_mode = _FM_NOUSE;

    return stat;
}
