/**
 * @file func_stdio.h
 * @brief Standard I/O.
 *
 *
 * @section License
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

#ifndef __FUNC_STDIO_H
#define __FUNC_STDIO_H

#include <stddef.h>

#define EOF       (-1)  /* end of file identifier */
#define FOPEN_MAX (8)   /* implementation-defined, at least 8 in C89/C99 */
#define BUFSIZ    (512) /* default buffer size */

/* NULL pointer */
#ifndef NULL
#define NULL ((void *)0)
#endif /* NULL */

/* buffering */
#define _IOFBF  (0)  /* fully buffered */
#define _IOLBF  (1)  /* line buffered */
#define _IONBF  (2)  /* no buffered */

/* file position */
#define SEEK_SET (0)
#define SEEK_CUR (1)
#define SEEK_END (2)

/* file object */
typedef struct _FUNC_FILE {
    unsigned short _mode;    /* file mode bits */
    int fd;                  /* file descriptor */
    unsigned char *_buf;     /* start address of buffer */
    unsigned char *_end;     /* end address of buffer */
    unsigned char *_next;    /* next byte to be read or written */
    unsigned char *_rend;    /* end address of buffer that can be read */
    unsigned char *_wend;    /* end address of buffer that can be written */
	unsigned char *_save;
    unsigned char _back[2];  /* push-back buffer */
    unsigned short _nback;   /* count of characters in push-back buffer */
    unsigned char cbuf;      /* one-character buffer when no buffer available */
    unsigned int _index;     /* index for internal file arrays */
} FUNC_FILE;

/* internal file object table */
extern FUNC_FILE *_files[FOPEN_MAX];

/* standard streams */
#define stdin _files[0]
#define stdout _files[1]
#define stderr _files[2]

/**
 * @fn int func_fflush(FUNC_FILE *fp)
 * @brief For output streams, <code>fflush()</code> forces a write of all
 * user-space buffered data for the given output or update stream via the
 * stream's underlying write function. For input streams, <code>fflush()</code>
 * discards any buffered  data that has been fetched from the underlying file,
 * but has not been consumed by the application. The open status of the stream
 * is unaffected.
 *
 * @param fp file pointer to be flushed. If <code>NULL</code>, it flushes all
 * open output streams.
 * @return 0 for success, <code>EOF</code> for error and <code>errno</code> is
 * set.
 */
extern int func_fflush(FUNC_FILE *fp);

#endif /* __FUNC_STDIO_H */
