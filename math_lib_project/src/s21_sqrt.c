#include "s21_math.h"

long double s21_sqrt(double x) {
  double res = -1;
  if (x < 0.0 || (!(x >= 0.0) && !(x < 0.0)) || x == EXC_NAN)
    res = EXC_NAN;
  else if (x == EXC_INF || x == -EXC_INF)
    res = EXC_INF;
  else if (x == 0.0)
    res = 0.0;
  else if (x > 0.0) {
    double prev_num = 1.0;
    while (1) {
      double next_num = (prev_num + (x / prev_num)) / 2.0;
      if (s21_fabs(prev_num - next_num) < EPS_16) break;
      prev_num = next_num;
    }
    res = prev_num;
  }
  return res;
}
