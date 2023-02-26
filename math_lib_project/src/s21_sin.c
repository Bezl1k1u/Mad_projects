#include "s21_math.h"

long double s21_sin(double x) {
  long double unsinus;
  int sign = 1;
  if (x != EXC_INF && x != -EXC_INF) {
    int n = 1;
    if (s21_fabs(x) >= 2 * N_PI) x = (double)s21_fmod(x, (2 * N_PI));
    if (x >= N_PI) {
      x -= N_PI;
      sign = -1;
    }
    long double schetchik = x;
    unsinus = x;
    while (s21_fabs((double)schetchik) > EPS_20) {
      schetchik *= -1.0 * x * x / ((2 * n) * (2 * n + 1));
      unsinus += schetchik;
      n++;
    }
  }
  if (x == EXC_INF || x == -EXC_INF) unsinus = EXC_NAN;
  return sign * unsinus;
}
