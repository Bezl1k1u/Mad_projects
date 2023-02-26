#include "s21_string.h"

/* f01 */
void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  void *out = S21_NULL;
  for (s21_size_t i = 0; i < n && ptr; i++) {
    if (*ptr == (unsigned char)c) {
      out = ptr;
      break;
    }
    ptr++;
  }
  return out;
}

/* f02 */
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int f = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (*((char *)str1 + i) != *((char *)str2 + i)) {
      f = (*((char *)str1 + i) - *((char *)str2 + i));
      break;
    }
  }
  return f;
}

/* f03 */
void *s21_memcpy(void *dest, const void *source, s21_size_t n) {
  int j = 0;
  for (s21_size_t i = 0; *((char *)source + i) != '\0' && i < n; i++, j++) {
    *((char *)dest + j) = *((char *)source + i);
  }
  return dest;
}

/* f04 */
void *s21_memmove(void *dest, const void *source, s21_size_t n) {
  int j = 0;
  for (s21_size_t i = 0; *((char *)source + i) != '\0' && i < n; i++, j++) {
    *((char *)dest + j) = *((char *)source + i);
  }
  return dest;
}

/* f05 */
void *s21_memset(void *mstr, int c, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) *((char *)mstr + i) = c;
  return mstr;
}

/* f06 */
char *s21_strcat(char *dest, const char *source) {
  s21_size_t i = s21_strlen(dest);
  for (int j = 0; source[j] != '\0'; i++, j++) dest[i] = source[j];
  dest[i] = '\0';
  return dest;
}

/* f07 */
char *s21_strncat(char *dest, const char *source, s21_size_t n) {
  s21_size_t i = s21_strlen(dest);
  for (s21_size_t j = 0; source[j] != '\0' && j < n; i++, j++)
    dest[i] = source[j];
  dest[i] = '\0';
  return dest;
}

/* f08 */
char *s21_strchr(const char *mstr, int c) {
  char *p = S21_NULL;
  for (int i = 0; mstr[i] != '\0'; i++) {
    if ((int)mstr[i] == c) {
      p = (char *)mstr + i;
      break;
    }
  }
  return p;
}

/* f09 */
int s21_strcmp(const char *str1, const char *str2) {
  int f = 0;
  for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
    if (str1[i] != str2[i]) {
      f = (int)str1[i] - (int)str2[i];
      break;
    }
  }
  return f;
}

/* f10 */
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;

  if (str1 && str2 && n > 0) {
    for (s21_size_t i = 0; i < n; i++) {
      if (str1[i] == '\0' || str1[i] != str2[i]) {
        res = str1[i] - str2[i];
        break;
      }
    }
  }

  return res;
}

// /* f11 */
char *s21_strcpy(char *dest, const char *src) {
  for (int i = 0; src[i]; i++) {
    dest[i] = src[i];
  }

  dest[s21_strlen(src)] = '\0';

  return dest;
}

/* f12 */
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_memset(dest, '\0', n);

  for (s21_size_t i = 0; i < n && src[i]; i++) {
    dest[i] = src[i];
  }

  return dest;
}

/* f13 */
s21_size_t s21_strcspn(const char *mstr, const char *symbols) {
  s21_size_t i = 0;
  for (; mstr[i] != '\0' && s21_strchr(symbols, mstr[i]) == S21_NULL; i++)
    ;
  return i;
}

/* f15 */
s21_size_t s21_strlen(const char *mstr) {
  s21_size_t i = 0;
  if (mstr)
    for (; mstr[i] != '\0'; i++)
      ;
  return i;
}

/* f16 */
char *s21_strpbrk(const char *str1, const char *symbols) {
  int i = 0;
  char *p = S21_NULL;
  for (; str1[i] != '\0' && s21_strchr(symbols, (int)str1[i]) == S21_NULL; i++)
    ;
  if (str1[i] != '\0') p = (char *)str1 + i;
  return p;
}

/* f17 */
char *s21_strrchr(const char *str, int c) {
  char *res = S21_NULL;
  s21_size_t len = s21_strlen(str);

  for (int i = len; i >= 0; i--) {
    if (str[i] == c) {
      res = ((char *)str) + i;
      break;
    }
  }

  return res;
}

/* f18 */
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t counter = 0;

  for (const char *a = str1; *a; a++) {
    unsigned short was = 0;
    for (const char *b = str2; *b; b++) {
      if (*a == *b) {
        counter++;
        was = 1;
        break;
      }
    }
    if (!was) break;
  }
  return counter;
}

/* f19 */
char *s21_strstr(const char *mstr, const char *ss) {
  int f = 0;
  char *p = S21_NULL;
  int mstr_cap = s21_strlen(mstr);
  int ss_cap = s21_strlen(ss);
  if (ss_cap <= mstr_cap) {
    for (int i = 0; i < mstr_cap - ss_cap + 1; i++) {
      for (int j = 0; j < ss_cap; j++) {
        if (ss[j] != mstr[i + j]) {
          f = 0;
          break;
        } else {
          f++;
        }
      }
      if (f == ss_cap) {
        p = (char *)mstr + i;
        break;
      }
    }
  }
  return p;
}

/* f20 */
char *s21_strtok(char *mstr, const char *delim) {
  int i = 0;
  char *p = S21_NULL;
  static char *marker = S21_NULL;
  if (mstr) marker = mstr + s21_strspn(mstr, delim);
  if (marker[i]) {
    while (marker[i] && !s21_strchr(delim, marker[i])) i++;
    if (marker[i]) {
      marker[i] = '\0';
      i++;
      while (marker[i] && s21_strchr(delim, marker[i])) i++;
    }
    p = marker;
    marker += i;
  }
  return p;
}

/* C#_functions */
void *s21_to_lower(const char *mstr) {
  char *p = S21_NULL;
  size_t n = s21_strlen(mstr) + 1;
  char t[n];
  if (s21_strcpy(t, mstr)) {
    p = t;
    for (int i = 0; t[i] != '\0'; i++) {
      if ((64 < t[i]) && (t[i] < 91)) t[i] += 32;
    }
  }
  return p;
}

void *s21_to_upper(const char *mstr) {
  char *p = S21_NULL;
  size_t n = s21_strlen(mstr) + 1;
  char t[n];
  if (s21_strcpy(t, mstr)) {
    p = t;
    for (int i = 0; t[i] != '\0'; i++) {
      if ((96 < t[i]) && (t[i] < 123)) t[i] -= 32;
    }
  }
  return p;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *ch_insert = S21_NULL;

  if (s21_strlen(src) >= start_index && src) {
    ch_insert =
        (char *)calloc((s21_strlen(src) + s21_strlen(str) + 1), sizeof(char));
    if (ch_insert) {
      s21_size_t i = 0;
      s21_size_t j = 0;
      for (; i < start_index; i++) {
        ch_insert[i] = src[i];
      }
      for (; j < s21_strlen(str); j++) {
        ch_insert[i + j] = str[j];
      }
      for (i = start_index; i < s21_strlen(src); i++) {
        ch_insert[i + j] = src[i];
      }
    }
  }
  return ch_insert;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = S21_NULL;

  if (src) {
    if (trim_chars && *trim_chars) {
      s21_size_t len = s21_strlen(src);
      s21_size_t chars_len = s21_strlen(trim_chars);

      s21_trim_left(&src, trim_chars, &len, chars_len);
      if (len) s21_trim_right(&src, trim_chars, &len, chars_len);

      res = (char *)malloc(sizeof(char) * (len + 1));

      if (res) {
        for (s21_size_t i = 0; i < len + 1; i++) {
          if (i < len) {
            res[i] = src[i];
          } else {
            res[i] = '\0';
          }
        }
      }
    } else {
      res = s21_trim(src, " \t\n");
    }
  }

  return res;
}

void s21_trim_left(const char **src, const char *trim_chars,
                   s21_size_t *src_len, const s21_size_t trim_chars_len) {
  s21_size_t m = 0;

  while (src && m != trim_chars_len) {
    if ((**src) == trim_chars[m]) {
      (*src)++;
      (*src_len) -= 1;
      m = 0;
      continue;
    }
    m++;
  }
}

void s21_trim_right(const char **src, const char *trim_chars,
                    s21_size_t *src_len, const s21_size_t trim_chars_len) {
  s21_size_t m = 0;
  s21_size_t i = (*src_len) - 1;

  while (src && m != trim_chars_len) {
    if ((*src)[i] == trim_chars[m]) {
      i--;
      (*src_len)--;
      m = 0;
      continue;
    }

    m++;
  }
}

/* s21_strntollu */
unsigned long long int s21_strntollu(const char *string, char **endptr,
                                     int basis, int n_byte) {
  unsigned long long res = 0;
  short sign = 1;
  if (endptr) *endptr = S21_NULL;
  char dict[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  if (*string == '-') {
    sign = -1;
    string++;
  }
  if (basis == 16 &&
      (!s21_strncmp(string, "0x", 2) || !s21_strncmp(string, "0X", 2)))
    string += 2;
  long long val;
  short exit = 0;
  while (*string && n_byte && !exit) {
    char *tmp2;
    char current_sim =
        (*string >= 'a' && *string <= 'z') ? *string - 'a' + 'A' : *string;
    tmp2 = s21_strchr(dict, (int)current_sim);
    if (!tmp2) {
      exit = 1;
    } else {
      val = (tmp2 - dict) / sizeof(char);

      if (val >= basis) {
        exit = 1;
      } else {
        res = res * basis + val;
        string++;
        n_byte--;
      }
    }
    if (exit) *endptr = (char *)string;
  }
  return res * sign;
}

long int s21_atoi(const char *str) {
  long int res = 0;
  int sign = 1;
  int overflow = 0;

  while (*str == ' ') str++;

  if (*str == '-') {
    str++;
    sign = -1;
  }

  if (*str == '+') {
    str++;
  }

  while (*str >= '0' && *str <= '9') {
    res = res * 10 + (*str - '0');
    if (res < 0) {
      overflow = 1;
      break;
    }
    str++;
  }

  if (overflow != 0)
    res = sign > 0 ? INT32_MAX : INT32_MIN;
  else
    res *= sign;

  return res;
}

long double s21_atof(const char *buffer) {
  long double frac = 0.0;
  char *p = (char *)buffer;
  int minus_flag = (*p == '-');
  if (*p == '-' || *p == '+') p++;

  long double res = s21_atoi(p);

  while (s21_isdigit(*p)) p++;

  if (*p == '.') {
    p++;
    int trailing_zeros = s21_strspn(p, "0");
    frac = s21_atoi(p);
    int tmp = (int)frac;
    while (tmp) {
      frac /= 10.0;
      tmp /= 10;
    }
    while (trailing_zeros) {
      frac /= 10.0;
      trailing_zeros--;
    }
  }

  res += frac;

  return minus_flag ? -res : res;
}

long s21_atohex(const char *str) {
  long hex = 0;
  int degree = 0;
  int sign = 1;
  int short_pow = 0;
  if (*str == '-' && *(str + 1) != '+') {
    sign = -1;
    str++;
  } else if (*str == '+') {
    str++;
  }
  if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X')) {
    str += 2;
  }
  degree = s21_strlen(str) - 1;
  while (*str &&
         ((*str >= '0' && *str <= '9') ||
          ((*str >= 'a' && *str <= 'f') || (*str >= 'A' && *str <= 'F'))) &&
         degree >= 0) {
    short_pow = (int)pow(16, degree);
    if (*str == 'a' || *str == 'A') {
      hex = hex + (10 * short_pow);
    } else if (*str == 'b' || *str == 'B') {
      hex = hex + (11 * short_pow);
    } else if (*str == 'c' || *str == 'C') {
      hex = hex + (12 * short_pow);
    } else if (*str == 'd' || *str == 'D') {
      hex = hex + (13 * short_pow);
    } else if (*str == 'e' || *str == 'E') {
      hex = hex + (14 * short_pow);
    } else if (*str == 'f' || *str == 'F') {
      hex = hex + (15 * short_pow);
    } else {
      hex = hex + ((*str - '0') * short_pow);
    }
    degree--;
    str++;
  }
  if (sign < 0) hex *= sign;
  return hex;
}

long s21_ato8(const char *str) {
  long hex = 0;
  int degree = 0;
  int sign = 1;
  int short_pow = 0;
  if (*str == '-' && *(str + 1) != '+') {
    sign = -1;
    str++;
  } else if (*str == '+') {
    str++;
  }
  degree = s21_strlen(str) - 1;
  while (*str && (*str >= '0' && *str <= '7') && degree >= 0) {
    short_pow = (int)pow(8, degree);
    hex = hex + ((*str - '0') * short_pow);
    degree--;
    str++;
  }
  if (sign < 0) hex *= sign;
  return hex;
}
