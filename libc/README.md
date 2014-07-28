# C99

- \<string.h>

## \<string.h>

```c
size_t strlen(const char *str)

char *strcat(char *dst, const char *src) /* NOT used, use strncat() instead */
char *strncat(char *dst, const char *src, size_t n)

int strcmp(const char *s1, const char *s2)
int strncmp(const cahr *s1, const char *s2, size_t n)
int memcmp(const void *p1, const void *p2, size_t n)

char *strcpy(char *dst, const char *src) /* NOT used, use strncpy() instead */
char *strncpy(char *dst, const char *src, size_t n)
void *memcpy(void *dst, const void *src, size_t n)
void *memmove(void *dst, const void *src, size_t n)

void memset(void *ptr, int val, size_t n)

char *strchr(const char *str, int c)
char *strrchr(const char *str, int c)
void *memchr(const void *ptr, int val, size_t len)

size_t strspn(const char *str, const char *set)
size_t strcspn(const char *str, const char *set)
char *strpbrk(const char *str, const char *set)

char *strstr(const char *str, const char *sub)
char *strtok(char *str, const char *seps)
```
