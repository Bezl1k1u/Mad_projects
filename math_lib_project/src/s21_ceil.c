#include "s21_math.h"

long double s21_ceil(double x) {
  long double result = (long long int)x;
  if (!(x >= 0) && !(x < 0))
    result = EXC_NAN;
  else if (x == EXC_INF || x == -EXC_INF)
    result = EXC_INF;
  else if (s21_fabs(x) > 0. && x != result)
    if (x > 0.) result += 1;

  return result;
}
