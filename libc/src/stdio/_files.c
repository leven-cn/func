/**
 * Internal file object table.
 *
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

#define STDERR_BUFSIZ 64

static unsigned char ebuf[STDERR_BUFSIZ];

/* standard input stream */
static FUNC_FILE _stdin = {
    (_FM_OPEN_READ), STDIN_FILENO,                 /* _mode, _fd */
    NULL, NULL,                                    /* _buf, _end */
    &(_stdin.cbuf), &(_stdin.cbuf), NULL, NULL,    /* _next, _rend, _wend, _save */
    {'\0','\0'}, 0,                                /* _back, _nback */
    '\0',                                          /* cbuf */
    0                                              /* _index */
};

/* standard output stream */
static FUNC_FILE _stdout = {
    (_FM_OPEN_WRITE), STDOUT_FILENO,                /* _mode, _fd */
    NULL, NULL,                                     /* _buf, _end */
    &(_stdout.cbuf), NULL, &(_stdout.cbuf), NULL,   /* _next, _rend, _wend, _save */
    {'\0','\0'}, 0,                                 /* _back, _nback */
    '\0',                                           /* cbuf */
    1                                               /* _index */
};

/* standard error stream */
static FUNC_FILE _stderr = {
    (_FM_OPEN_WRITE) | (_FM_NBF), STDERR_FILENO,   /* _mode, _fd */
    ebuf, ebuf+sizeof(ebuf),                       /* _buf, _end */
    ebuf, NULL, ebuf+sizeof(ebuf), NULL,           /* _next, _rend, _wend, _save */
    {'\0','\0'}, 0,                                /* _back, _nback */
    '\0',                                          /* cbuf */
    2                                              /* _index */
};

FUNC_FILE *_files[FOPEN_MAX] = {&_stdin, &_stdout, &_stderr};
