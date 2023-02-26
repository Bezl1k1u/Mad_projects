#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>

#include "s21_sprintf.h"
#include "s21_sscanf.h"
#include "s21_strerror.h"

#define BUFF_SIZE 512
#define S21_NULL ((void *)0)

int s21_sprintf(char *str, const char *format, ...);
int s21_sscanf(const char *str, const char *fstr, ...);

int s21_isdigit(char c);

typedef long unsigned int s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *source, s21_size_t n);
void *s21_memmove(void *dest, const void *source, s21_size_t n);
void *s21_memset(void *mstr, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *source);
char *s21_strncat(char *dest, const char *source, s21_size_t n);
char *s21_strchr(const char *mstr, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *source, s21_size_t n);
s21_size_t s21_strcspn(const char *mstr, const char *symbols);
s21_size_t s21_strlen(const char *mstr);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *mstr, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *mstr, const char *ss);
char *s21_strtok(char *mstr, const char *delim);
char *s21_strerror(int errnum);
long int s21_atoi(const char *str);
long double s21_atof(const char *buffer);
long s21_ato8(const char *str);
long s21_atohex(const char *str);
unsigned long long int s21_strntollu(const char *string, char **endptr,
                                     int basis, int n_byte);
int s21_is_delim(char ch, const char *delim);
long double s21_strtold(const char *buffer);

/* C#_functions */
void *s21_to_upper(const char *mstr);
void *s21_to_lower(const char *mstr);
void *s21_insert(const char *source, const char *mstr, s21_size_t start_index);
void *s21_trim(const char *source, const char *trim_chars);
void s21_trim_left(const char **src, const char *trim_chars,
                   s21_size_t *src_len, const s21_size_t trim_chars_len);
void s21_trim_right(const char **src, const char *trim_chars,
                    s21_size_t *src_len, const s21_size_t trim_chars_len);

#endif  //  SRC_S21_STRING_H_
