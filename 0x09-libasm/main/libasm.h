#ifndef __LIBASM_H__
#define __LIBASM_H__

size_t asm_strlen(const char *str);
int asm_strcmp(const char *s1, const char *s2);
int asm_strncmp(const char *s1, const char *s2, size_t n);
char *asm_strchr(const char *s, int c);
char *asm_strstr(const char *s1, const char *s2);
void *asm_memcpy(void *dest, const void *src, size_t n);
size_t asm_putc(int c);
size_t asm_puts(const char *str);
int asm_strcasecmp(const char *s1, const char *s2);
int asm_strncasecmp(const char *s1, const char *s2, size_t n);
size_t asm_strspn(const char *s, const char *accept);
size_t asm_strcspn(const char *s, const char *reject);
char *asm_strpbrk(const char *s, const char *accept);
size_t asm_puti(int n);
size_t asm_puti_base(int n, const char *base);
#endif
