#include "s21_math.h"

long double s21_acos(double x) {
  double rez = 0;
  rez = (N_PI / 2) - s21_asin(x);
  return rez;
}
