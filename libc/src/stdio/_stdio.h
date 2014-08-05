/**
 * Internal header for standard I/O
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

#ifndef ___STDIO_H
#define ___STDIO_H

#include "func_stdio.h"

/* file mode bits */
#define _FM_NOUSE       (0x0)    /* not used */
#define _FM_ERROR       (0x1)    /* stream error */
#define _FM_ALLOC_FILE  (0x2)    /* stream object must be freed on close */
#define _FM_ALLOC_BUF   (0x4)    /* stream buffer must be freed on close */
#define _FM_OPEN_READ   (0x8)    /* stream is open for reading */
#define _FM_OPEN_WRITE  (0xF)    /* stream is open for writing */
#define _FM_OPEN_APPEND (0x10)   /* stream is open for appending */
#define _FM_NBF         (0x20)   /* stream without buffering */
#define _FM_LBF         (0x40)   /* stream with line buffering */
#define _FM_FBF         (0x80)   /* stream with fully buffering */
#define _FM_EOF         (0xF0)   /* end of stream */
#define _FM_READ        (0x100)  /* stream is read */
#define _FM_WRITE       (0x200)  /* stream is written */
#define _FM_TRUNC       (0x400)  /* stream is trunct */
#define _FM_CREAT       (0x800)  /* stream is created */

/* internal implementation for fopen() & freopen() */
extern FUNC_FILE* _fopen(const char *path, const char *mode, FUNC_FILE *fp);

/* internal implementation for fputs() & fputc() */
extern int _fputs(FUNC_FILE *fp);

#endif /* ___STDIO_H */
