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

NULL  ((void *)0)

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

char *setlocale(int category, const char *locale); // category = "C" or "POSIX"
```

### \<ctype.h>

```c
#include <ctype.h>

int isalpha(int c);
int isdigit(int c);
int isalnum(int c);
int isxdigit(int c);
int isblank(int c); // New in C99
int isspace(int c);
int isupper(int c);
int islower(int c);
int iscntrl(int c);
int isgraph(int c);
int isprint(int c);
int ispunct(int c);

int tolower(int c);
int toupper(int c);
```

### \<string.h>

```c
#include <string.h>

size_t strlen(const char *str);

int strcmp(const char *s1, const char *s2);
int strncmp(const cahr *s1, const char *s2, size_t n);
int memcmp(const void *p1, const void *p2, size_t n);

char *strcat(char *dst, const char *src); // NOT used, use strncat() instead
char *strncat(char *dst, const char *src, size_t n);

char *strcpy(char *dst, const char *src); // NOT used, use strncpy() instead
char *strncpy(char *dst, const char *src, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
void *memmove(void *dst, const void *src, size_t n);

void memset(void *ptr, int val, size_t n);

char *strchr(const char *str, int c);
char *strrchr(const char *str, int c);
void *memchr(const void *ptr, int val, size_t len);

char *strstr(const char *str, const char *sub);

size_t strspn(const char *str, const char *set);
size_t strcspn(const char *str, const char *set);
char *strpbrk(const char *str, const char *set);

char *strtok(char *str, const char *seps);
```

### \<stdlib.h>

```c
#include <stdlib.h>

/* environment */
char *getenv(const char *env_name);

/* dynamic memory (heap) */
void *malloc(size_t size);
void free(void *p);
```

### \<stdio.h>

```c
#include <stdio.h>

stdin
stdout
stderr

int fflush(FILE *fp);

int fclose(FILE *fp);
int fopen(const char *path, const char *mode);
int freopen(const char *path, const char *mode, FILE *fp);

int fputs(const char *s, FILE *fp);
int puts(const char *s);
int fputc(int c, FILE *fp);
int putc(int c, FILE *fp);
int putchar(int c);
char *fgets(char *buf, int size, FILE *fp);
char *gets(char *buf); // NOT used, use fgets() instead
int fgetc(FILE *fp);
int getc(FILE *fp);
int getchar();
int ungetc(int c, FILE *fp);

int feof(FILE *fp);
int ferror(FILE *fp);
void clearerr(FILE *fp);

int setvbuf(FILE *fp, char *buf, int mode, size_t size);
int setbuf(FILE *fp, char *buf);

/* setvbuf()/setbuf() mode */
_IONBF
_IOLBF
_IOFBF

long ftell(FILE *fp);
int fseek(FILE *fp, long offset, int whence);

/* fseek() whence */
SEEK_SET  (0)
SEEK_CUR  (1)
SEEK_END  (2)

int remove(const char *path);
int rename(const char *src, const char *dst);
```

## POSIX C

- System I/O

### System I/O

```c
/* standard file descriptor */
#include <unistd.h>
STDIN_FILENO    (0)
STDOUT_FILENO   (0)
STDERR_FILENO   (0)

/* Open a file */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int open(const char *path, int flags);
int open(const char *path, int flags, mode_t mode);

/* open() flags */
O_RDONLY
O_WRONLY
O_RDWR
O_APPEND
O_CREAT
O_TRUNC

/* open() mode */
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
int close(int fd);

/* Basic Read/Write */
#include <unistd.h>
ssize_t read(int fd, void *buf, size_t size);
ssize_t write(int fd, const void *buf, size_t size);

/* File Offset */
#include <sys/types.h>
#include <unistd.h>
off_t lseek(int fd, off_t offset, int whence);

/* lseek() whence */
SEEK_SET  (0)
SEEK_CUR  (1)
SEEK_END  (2)

/* File Status */
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int stat(const char *path, struct stat *st_buf);
int fstat(int fd, struct stat *st_buf);

/* File stat struct */
struct stat {
	dev_t     st_dev;     /* ID of device containing file */
	ino_t     st_ino;     /* inode number */
	mode_t    st_mode;    /* protection */
	nlink_t   st_nlink;   /* number of hard links */
	uid_t     st_uid;     /* user ID of owner */
	gid_t     st_gid;     /* group ID of owner */
	dev_t     st_rdev;    /* device ID (if special file) */
	off_t     st_size;    /* total size, in bytes */
	blksize_t st_blksize; /* blocksize for filesystem I/O */
	blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
	time_t    st_atime;   /* time of last access */
	time_t    st_mtime;   /* time of last modification */
	time_t    st_ctime;   /* time of last status change */
};

/* POSIX macros to check `st_mode` field in `stat` struct */
S_ISREG(m)  // is it a regular file?
S_ISDIR(m)  // directory?
S_ISCHR(m)  // character device?
S_ISBLK(m)  // block device?
S_ISFIFO(m) // FIFO (named pipe)?
S_ISLNK(m)  // symbolic link?  (Not in POSIX.1-1996.)
S_ISSOCK(m) // socket?  (Not in POSIX.1-1996.)

/* `st_mode` field in `stat` struct */
S_IFMT     0170000   // bit mask for the file type bit fields
S_IFSOCK   0140000   // socket
S_IFLNK    0120000   // symbolic link
S_IFREG    0100000   // regular file
S_IFBLK    0060000   // block device
S_IFDIR    0040000   // directory
S_IFCHR    0020000   // character device
S_IFIFO    0010000   // FIFO
S_ISUID    0004000   // set-user-ID bit
S_ISGID    0002000   // set-group-ID bit (see below)
S_ISVTX    0001000   // sticky bit (see below)
S_IRWXU    00700     // mask for file owner permissions
S_IRUSR    00400     // owner has read permission
S_IWUSR    00200     // owner has write permission
S_IXUSR    00100     // owner has execute permission
S_IRWXG    00070     // mask for group permissions
S_IRGRP    00040     // group has read permission
S_IWGRP    00020     // group has write permission
S_IXGRP    00010     // group has execute permission
S_IRWXO    00007     // mask for permissions for others (not in group)
S_IROTH    00004     // others have read permission
S_IWOTH    00002     // others have write permission
S_IXOTH    00001     // others have execute permission

/* File system */
#include <unistd.h>
int link(const char *src, const char *dst);
int unlink(const char *path);
int rmdir(const char *path);
```
