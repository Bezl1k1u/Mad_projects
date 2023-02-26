#include "s21_math.h"

long double s21_floor(double x) {
  long double result = (long long int)x;
  if (!(x >= 0) && !(x < 0))
    result = EXC_NAN;
  else if (x == 1.0 / 0.0 || x == -1.0 / 0.0)
    result = EXC_INF;
  else if (s21_fabs(x - result) > 0. && s21_fabs(x) > 0)
    if (x < 0.) result -= 1;
  return result;
}
