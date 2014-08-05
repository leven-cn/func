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
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

char *func_fgets(char *buf, int size, FUNC_FILE *fp)
{
    if (size <= 1) { /* at least one for storing '\0' */
        errno = EINVAL;
        return NULL;
    }

    if (fp == NULL) {
        errno = EBADF;
        return NULL;
    }

    unsigned char *p = (unsigned char *)buf;

    /* get from push-back buffer */
    while (--size>0 && fp->_nback!=0) {
        *p = fp->_back[--fp->_nback];
        if (*p++ == '\n') {
            /* terminate a line */
            *p = '\0';
            return buf;
        }
    }

    /* get from buffer */
    while (size > 0) {
        if (fp->_next < fp->_rend) {
        } else if (_fgets(fp) < 0) {
            return NULL;
        } else if (fp->_mode & _FM_EOF) {
            break;
        }

        /* copy as many as possible */
        {
            unsigned char *p2 = func_memchr(fp->_next, '\n', fp->_rend-fp->_next);
            size_t n = ((p2) ? (p+1) : (fp->_end)) - fp->_next;
            if (n > (size_t)size) {
                p2 = NULL;
                n = size;
            }
            func_memcpy(p, fp->_buf, n);
            p += n;
            size -= n;
            fp->_next += n;
            if (p2) {
                /* terminate full line */
                *p = '\0';
                return buf;
            }
        }
    }

    if (p == (unsigned char *)buf) {
        return NULL;
    } else {
        /* terminate partial line */
        *p = '\0';
        return buf;
    }
}

int _fgets(FUNC_FILE *fp) {
    if (fp->_next < fp->_rend) {
        return 1;
    } else if (fp->_mode & _FM_EOF) {
        return 0;
    } else if ((fp->_mode & (_FM_OPEN_READ | _FM_WRITE)) != _FM_OPEN_READ) {
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
    fp->_wend = fp->_buf;

    /* try to read into buffer */
    {
        ssize_t n = read(fp->fd, fp->_buf, BUFSIZ-1);
        if (n == -1) {
            fp->_mode |= _FM_ERROR;
            return -1;
        } else if (n == 0) {
            fp->_mode = (fp->_mode & ~_FM_READ) | _FM_EOF;
            return 0;
        } else {
            fp->_mode |= _FM_READ;
            fp->_end += n;
            return 1;
        }
    }

    return 0;
}
