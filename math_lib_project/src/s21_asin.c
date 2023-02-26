#include "s21_math.h"

long double s21_fact(int n);

long double s21_asin(double x) {
  long double rez = 0;

  if (x == 0.0) {
    rez = 0.0;
  } else {
    if (s21_fabs(x) <= 1.0) {
      if (s21_fabs(x) <= 0.5) {
        for (int i = 0; i < 45; i++) {
          rez += (s21_fact(2 * i) /
                  ((s21_pow(2, 2 * i) * s21_pow(s21_fact(i), 2)))) *
                 s21_pow(x, 2 * i + 1) / (2 * i + 1);
        }
      } else {
        rez = N_PI / 2 - 2 * s21_asin(s21_sqrt((1 - x) / 2));
      }
    } else {
      rez = EXC_NAN;
    }
  }
  return rez;
}

long double s21_fact(int n) { return (n < 2) ? 1 : n * s21_fact(n - 1); }
