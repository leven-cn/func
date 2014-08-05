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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

FUNC_FILE* _fopen(const char *path, const char *mode, FUNC_FILE *fp);

/* Wrapper for POSIX API open() */
static int _open(const char *path, FUNC_FILE *fp);

FUNC_FILE* fopen(const char *path, const char *mode)
{
    FUNC_FILE *fp = NULL;
    size_t i;

    for (i=0; i<FOPEN_MAX; i++) {
        if (_files[i] == NULL) {
            /* setup empty file object */
            fp = (FUNC_FILE *)malloc(sizeof(FUNC_FILE));
            if (fp == NULL) {
                return NULL;
            }
            _files[i] = fp;
            fp->_mode = _FM_ALLOC_FILE;
            break;
        } else if (_files[i]->_mode == 0) {
            /* setup pre-allocated file object */
            fp = _files[i];
            break;
        }
    }

    if (i >= FOPEN_MAX) {
        return NULL;
    }

    return _fopen(path, mode, fp);
}

FUNC_FILE* _fopen(const char *path, const char *mode, FUNC_FILE *fp)
{
    fp->fd = -1;
    fp->_buf = NULL;
    fp->_end = NULL;
    fp->cbuf = '\0';
    fp->_next = &fp->cbuf;
    fp->_rend = &fp->cbuf;
    fp->_wend = &fp->cbuf;
    fp->_nback = 0;

    fp->_mode = (fp->_mode & _FM_ALLOC_FILE)
        | ((*mode == 'r') ? _FM_OPEN_READ
        : (*mode == 'w') ? (_FM_CREAT | _FM_OPEN_WRITE | _FM_TRUNC)
        : (*mode == 'a') ? (_FM_CREAT | _FM_OPEN_WRITE | _FM_OPEN_APPEND)
        : _FM_NOUSE );
    if (!(fp->_mode & (_FM_OPEN_READ | _FM_OPEN_WRITE))) {
        errno = EINVAL;
        func_fclose(fp);
        return NULL;
    }

    /* ignore 'b' and '+' mode */

    int fd = _open(path, fp);
    if (fd == -1) {
        func_fclose(fp);
        return NULL;
    }

    fp->fd = fd;
    return fp;
}

static int _open(const char *path, FUNC_FILE *fp)
{
    int flags;
    mode_t fmode;
    if (fp->_mode & _FM_OPEN_READ) {
        flags = O_RDONLY;
        return open(path, flags);
    } else if (fp->_mode & _FM_OPEN_WRITE) {
        flags = O_CREAT | O_WRONLY | O_TRUNC;
        fmode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP; /* rw-rw---- */
        return open(path, flags, fmode);
    } else if (fp->_mode & _FM_OPEN_APPEND) {
        flags = O_CREAT | O_WRONLY | O_APPEND;
        fmode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP; /* rw-rw---- */
        return open(path, flags, fmode);
    }

    /* ignore 'b' and '+' */

    return -1;
}
