#include "s21_string.h"

/* f14 */
char *s21_strerror(int errnum) {
  char s21_app_errlist[][1024] = ERRORS static char res[128] = {'\0'};
  if (errnum < 0 || errnum >= N) {
    s21_sprintf(res, "Unknown error: %d", errnum);
  } else {
#if defined(__APPLE__)
    s21_strcpy(res, s21_app_errlist[errnum]);
#elif defined(__linux__)
    s21_strcpy(res, s21_app_errlist[errnum]);
#endif
  }
  return res;
}
