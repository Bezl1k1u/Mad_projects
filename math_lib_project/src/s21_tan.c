#include "s21_math.h"

long double s21_tan(double x) {
  long double tangens = s21_cos(x);
  tangens = (tangens != 0.0) ? (s21_sin(x) / tangens) : EXC_NAN;
  return tangens;
}
