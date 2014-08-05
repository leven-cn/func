# C

- ANSI C99
- POSIX C

## C99

- \<stddef.h>
- \<locale.h>
- \<ctype.h>
- \<string.h>
- \<stdlib.h>
- \<stdio.h>

### \<stddef.h>

```c
#include <stddef.h>

NULL

size_t
```

### \<locale.h>

```c
#include <locale.h>

/* locale category */
LC_ALL
LC_CTYPE     // <ctype.h>
LC_TIME      // time and date formats
LC_NUMERIC   // number formats
LC_MONETARY  // monetary formats

char *setlocale(int category, const char *locale) // category = "C" or "POSIX"
```

### \<ctype.h>

```c
#include <ctype.h>

int isalpha(int c)
int isdigit(int c)
int isalnum(int c)
int isxdigit(int c)
int isblank(int c) // New in C99
int isspace(int c)
int isupper(int c)
int islower(int c)
int iscntrl(int c)
int isgraph(int c)
int isprint(int c)
int ispunct(int c)

int tolower(int c)
int toupper(int c)
```

### \<string.h>

```c
#include <string.h>

size_t strlen(const char *str)

int strcmp(const char *s1, const char *s2)
int strncmp(const cahr *s1, const char *s2, size_t n)
int memcmp(const void *p1, const void *p2, size_t n)

char *strcat(char *dst, const char *src) // NOT used, use strncat() instead
char *strncat(char *dst, const char *src, size_t n)

char *strcpy(char *dst, const char *src) // NOT used, use strncpy() instead
char *strncpy(char *dst, const char *src, size_t n)
void *memcpy(void *dst, const void *src, size_t n)
void *memmove(void *dst, const void *src, size_t n)

void memset(void *ptr, int val, size_t n)

char *strchr(const char *str, int c)
char *strrchr(const char *str, int c)
void *memchr(const void *ptr, int val, size_t len)

char *strstr(const char *str, const char *sub)

size_t strspn(const char *str, const char *set)
size_t strcspn(const char *str, const char *set)
char *strpbrk(const char *str, const char *set)

char *strtok(char *str, const char *seps)
```

### \<stdlib.h>

```c
#include <stdlib.h>

/* environment */
char *getenv(const char *env_name)

/* dynamic memory (heap) */
void *malloc(size_t size)
void free(void *p)
```

### \<stdio.h>

```c
#include <stdio.h>

stdin
stdout
stderr

int fflush(FILE *fp)

int fclose(FILE *fp)
int fopen(const char *path, const char *mode)
int freopen(const char *path, const char *mode, FILE *fp)

int fputs(const char *s, FILE *fp)
int puts(const char *s)
int fputc(int c, FILE *fp)
int putc(int c, FILE *fp)
int putchar(int c)
char *fgets(char *buf, int size, FILE *fp)
char *gets(char *buf) // NOT used, use fgets() instead
int fgetc(FILE *fp)
int getc(FILE *fp)
int getchar()
```

## POSIX C

- System I/O

### System I/O

```c
/* standard file descriptor */
#include <unistd.h>
STDIN_FILENO
STDOUT_FILENO
STDERR_FILENO

/* Open a file */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int open(const char *path, int flags)
int open(const char *path, int flags, mode_t mode)

/* Open flags */
O_RDONLY
O_WRONLY
O_RDWR
O_APPEND
O_CREAT
O_TRUNC

/* Open mode */
S_IRUSR
S_IWUSR
S_IXUSR
S_IRGRP
S_IWGRP
S_IXGRP
S_IROTH
S_IWOTH
S_IXOTH

/* Close a file */
#include <unistd.h>
int close(int fd)

/* basic Read/Write */
#include <unistd.h>
ssize_t read(int fd, void *buf, size_t size)
ssize_t write(int fd, const void *buf, size_t size)
```
