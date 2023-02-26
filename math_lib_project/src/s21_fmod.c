#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0.0;
  if (!(x >= 0) && !(x < 0))
    res = EXC_NAN;
  else if (!(y >= 0) && !(y < 0))
    res = EXC_NAN;
  else if ((x != EXC_NAN && y == 0))
    res = EXC_NAN;
  else if (y == -EXC_INF || y == EXC_INF)
    res = x;
  else if ((x == -EXC_INF || x == EXC_INF) && y != EXC_NAN)
    res = EXC_NAN;
  else if (x == 0.0 && y != 0.0)
    res = 0.0;
  else {
    long long int mod = 0;
    mod = x / y;
    res = (long double)x - mod * (long double)y;
  }
  return res;
}