#ifndef _STRINGS_H_
#define _STRINGS_H_

unsigned int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
char *_strchr(const char *s, int c);
int _strncmp(const char *s1, const char *s2, unsigned int k);
char *_strdup(const char *str);
char *_strstr(char *haystack, char *needle);
int _strcasecmp(const char *s1, const char *s2);
char *_strtok(char *str, const char *comp);
char *_strrchr(const char *s, int c);
char *_strcpy(char *dest, const char *src);
char *ltrim(char *src);
#endif
