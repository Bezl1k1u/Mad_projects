#include "s21_math.h"

long double s21_log(double x) {
  long double res = 0;
  int pow_of_E = 0;
  if (x < 0.0 || (!(x >= 0.0) && !(x < 0.0)) || x == EXC_NAN)
    res = EXC_NAN;
  else if (x == EXC_INF || x == -EXC_INF)
    res = EXC_INF;
  else if (x == 0.0)
    res = -EXC_INF;
  else if (x == 1.0)
    res = 0;
  else if (x > 0.0) {
    long double calc_value = res;
    for (; x >= N_E; x /= N_E, pow_of_E++) continue;
    for (int i = 0; i < 100; i++) {
      calc_value = res;
      res = calc_value +
            2 * (x - s21_exp(calc_value)) / (x + s21_exp(calc_value));
    }
  }
  return (long double)res + pow_of_E;
}