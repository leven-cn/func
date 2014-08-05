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

/**
 * @fn int func_fclose(FUNC_FILE *fp)
 * @brief Flushes the stream pointed to by <var>fp</var> (writing any buffered
 * output data using <code>fflush()</code> and closes the underlying file
 * descriptor.
 *
 * @param fp file pointer to be closed.
 * @return 0 for success, <code>EOF</code> for error and <code>errno</code> is
 * set.
 */
extern int func_fclose(FUNC_FILE *fp);

/**
 * @fn FUNC_FILE* fopen(const char *path, const char *mode)
 * @brief Opens the file whose name is the string pointed to by <var>path</var>
 * and associates a stream with it.
 *
 * The argument <var>mode</var> points to a string beginning with one of the
 * following sequences (possibly followed by additional characters, as
 * described below):
 *
 *     r      Open text file for reading. The stream is
 *            positioned at the beginning of the file.
 *
 *     r+     Open for reading and writing.  The  stream  is
 *            positioned at the beginning of the file.
 *
 *     w      Truncate file to zero length or create text
 *            file for writing.  The stream is positioned  at
 *            the beginning of the file.
 *
 *     w+     Open for reading and writing. The file is created
 *            if it does not exist, otherwise it is truncated.
 *            The stream is positioned at the beginning of the file.
 *
 *     a      Open for appending (writing at end of file).
 *            The  file is created if it does not exist. The
 *            stream is positioned at the end of the file.
 *
 *     a+     Open for reading and appending (writing at end
 *            of file).  The file is created if it does not
 *            exist.  The initial file position  for  reading
 *            is at the beginning of the file, but output is
 *            always appended to the end of the file.
 *
 * @param path file path.
 * @param mode file open mode.
 * @return a FILE pointer for success, <code>NULL</code> for error and
 * <code>errno</code> is set.
 */
extern FUNC_FILE* fopen(const char *path, const char *mode);

/**
 * @fn FUNC_FILE* freopen(const char *path, const char *mode, FUNC_FILE *fp)
 * @brief Opens the file whose name is the string pointed to by <var>path</var>
 * and associates the stream pointed to by <var>fp</var> with it. The original
 * stream (if it exists) is closed.  The mode argument is used just as in the
 * <code>fopen()</code> function. The primary use of the <code>freopen()</code>
 * function is to change the file associated with a standard text stream
 * (<code>stderr</code>, <code>stdin</code>, or <code>stdout</code>).
 *
 * The argument <var>mode</var> points to a string beginning with one of the
 * following sequences (possibly followed by additional characters, as
 * described below):
 *
 *     r      Open text file for reading. The stream is
 *            positioned at the beginning of the file.
 *
 *     r+     Open for reading and writing.  The  stream  is
 *            positioned at the beginning of the file.
 *
 *     w      Truncate file to zero length or create text
 *            file for writing.  The stream is positioned  at
 *            the beginning of the file.
 *
 *     w+     Open for reading and writing. The file is created
 *            if it does not exist, otherwise it is truncated.
 *            The stream is positioned at the beginning of the file.
 *
 *     a      Open for appending (writing at end of file).
 *            The  file is created if it does not exist. The
 *            stream is positioned at the end of the file.
 *
 *     a+     Open for reading and appending (writing at end
 *            of file).  The file is created if it does not
 *            exist.  The initial file position  for  reading
 *            is at the beginning of the file, but output is
 *            always appended to the end of the file.
 *
 * @param path file path.
 * @param mode file open mode.
 * @param fp FILE pointer to re-open stream.
 * @return a FILE pointer for success, <code>NULL</code> for error and
 * <code>errno</code> is set.
 */
extern FUNC_FILE *freopen(const char *path, const char *mode, FUNC_FILE *fp);

/**
 * @fn int func_fputs(const char *s, FUNC_FILE *fp)
 * @brief Writes the string <var>s</var> to <var>fp</var>, without its
 * terminating null byte (<code>'\0'</code>).
 *
 * @param s string to be written to file <var>fp</var>.
 * @param fp file pointer to be written.
 * @return number of characters written for success, <code>EOF</code> for error
 * and <code>errno</code> is set.
 */
extern int func_fputs(const char *s, FUNC_FILE *fp);

/**
 * @fn int func_puts(const char *s)
 * @brief Writes the string <var>s</var> to <code>stdout</code>, with
 * terminating null byte (<code>'\0'</code>).
 *
 * @param s string to be written to <code>stdout</code>.
 * @return number of characters written for success, <code>EOF</code> for error
 * and <code>errno</code> is set.
 */
#define func_puts(s) \
		(func_fputs((s),stdout) < 0 || func_fputc('\n', stdout) < 0 ? EOF : 0)

/**
 * @fn int func_fputc(int c, FUNC_FILE *fp)
 * @brief Writes the character <var>c</var>, cast to an
 * <code>unsigned char</code>, to file <var>fp</var>.
 *
 * @param c character to be written to file <var>fp</var>.
 * @param fp file pointer to be written.
 * @return character written cast to an <code>int</code> for success,
 * <code>EOF</code> for error and <code>errno</code> is set.
 */
extern int func_fputc(int c, FUNC_FILE *fp);

/**
 * @fn int func_putc(int c, FUNC_FILE *fp)
 * @brief A macro implementation of <code>fputc()</code>.
 *
 * @param c character to be written to file <var>fp</var>.
 * @param fp file pointer to be written.
 * @return character written cast to an <code>int</code> for success,
 * <code>EOF</code> for error and <code>errno</code> is set.
 */
#define func_putc(c,fp) (func_fputc((c), (fp)))

/**
 * @fn int func_putchar(int c)
 * @brief Equivalent to <code>putc(c, stdout)</code>.
 *
 * @param c character to be written to file <code>stdout</code>.
 * @return character written cast to an <code>int</code> for success,
 * <code>EOF</code> for error and <code>errno</code> is set.
 */
#define func_putchar(c) (func_putc((c), stdout))

/**
 * @fn int func_fgets(char *buf, int size, FUNC_FILE *fp)
 * @brief Reads in at most one less than <var>size</var> characters from file
 * <var>fp</var> and stores them into the buffer pointed to by <var>buf</var>.
 * Reading stops after an <code>EOF</code> or a newline. If a newline is read,
 * it is stored into the buffer. A terminating null byte (<code>'\0'</code>) is
 * stored after the last character in the buffer.
 *
 * @warning Never use <code>gets()</code>
 *
 * @param buf string buffer to get reading characters.
 * @param size number of characters to read from file.
 * @return pointer to <var>buf</var> for success, <code>NULL</code> for error
 * and <code>errno</code> is set.
 */
extern char *func_fgets(char *buf, int size, FUNC_FILE *fp);

/**
 * @fn int func_fgetc(FILE *fp);
 * @brief Reads the next character from file <var>fp</var> and returns it as an
 * <code>unsigned char</code> cast to an <code>int</code>, or <code>EOF</code>
 * on end of file or error.
 *
 * @param fp file pointer to be read from.
 * @return character to read or <code>EOF</code> on end of file or error.
 */
extern int func_fgetc(FUNC_FILE *fp);

/**
 * @fn int func_getc(FILE *fp);
 * @brief A macro implementation of <code>fgetc()</code>.
 *
 * @param fp file pointer to be read from.
 * @return character to read or <code>EOF</code> on end of file or error.
 */
#define func_getc(fp) (func_fgetc((fp)))

/**
 * @fn int func_getchar();
 * @brief Equivalent to <code>getc(stdin)</code>.
 *
 * @return character to read or <code>EOF</code> on end of file or error.
 */
#define func_getchar() (func_getc(stdin))

/**
 * @fn int func_ungetc(int c, FUNC_FILE *fp);
 * @brief Push character <var>c</var> back to file <var>fp</var>, cast to
 * <code>unsigned char</code>, where it is available for subsequent read
 * operations. Pushed-back characters will be returned in reverse order;
 * <strong>only one</strong> pushback is guaranteed.
 *
 * @param fp a file pointer.
 * @return character to push back.
 */
extern int func_ungetc(int c, FUNC_FILE *fp);

/**
 * @fn int func_feof(FUNC_FILE *fp);
 * @brief Test the end-of-file indicator for the file pointed to by
 * <var>fp</var>, returning non-zero if it is set. The end-of-file indicator
 * can be cleared only by the function <code>clearerr()</code>.
 *
 * @param fp a file pointer to be checked.
 * @return non-zero if it is set.
 */
extern int func_feof(FUNC_FILE *fp);

/**
 * @fn int func_ferror(FUNC_FILE *fp);
 * @brief Test the error indicator for the file pointed to by <var>fp</var>,
 * returning non-zero if it is set. The error indicator can be reset only by
 * the <code>clearerr()</code> function.
 *
 * @param fp a file pointer to be checked.
 * @return non-zero if it is set.
 */
extern int func_ferror(FUNC_FILE *fp);

/**
 * @fn void func_clearerr(FUNC_FILE *fp);
 * @brief Clear the end-of-file and error indicators for the file pointed to by
 * <var>fp</var>.
 *
 * @param fp a file pointer to be cleared.
 */
extern void func_clearerr(FUNC_FILE *fp);

#endif /* __FUNC_STDIO_H */
