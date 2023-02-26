#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double res = 0.0;
  if (base == 0.0 && exp == 0.0)
    res = 1.0;
  else if (exp == 1.0)
    res = base;
  else if (base == -EXC_INF || base == EXC_INF)
    res = EXC_INF;
  else if (!(base >= 0) && !(base < 0))
    res = EXC_NAN;
  else if (base < 0.0 && exp - (long int)exp != 0.0)
    res = EXC_NAN;
  else if (exp == (int)exp && exp > 0) {
    res = 1.0;
    for (int i = 0; i < exp; i++) {
      res *= base;
    }
  } else {
    res = s21_exp(exp * s21_log(s21_fabs(base)));
    if (s21_fmod(exp, 2.0) != 0.0 && base < 0.0) res *= -1.0;
  }
  return res;
}
