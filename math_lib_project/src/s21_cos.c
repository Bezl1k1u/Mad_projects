#include "s21_math.h"

long double s21_cos(double x) {
  long double cosinus;
  cosinus = s21_sin((N_PI / 2) - x);
  return cosinus;
}
