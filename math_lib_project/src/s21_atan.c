
#include "s21_math.h"

long double s21_atan(double x) {
  double rez = 0;
  if (x == EXC_INF) {
    rez = N_PI / 2.0;
  } else if (x == -0.0) {
    rez = -0.0;
  } else if (x == -EXC_INF) {
    rez = -N_PI / 2.0;
  } else {
    rez = s21_asin((x) / (s21_sqrt(1 + x * x)));
  }
  return rez;
}
