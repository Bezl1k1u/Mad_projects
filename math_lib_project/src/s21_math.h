#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>

#define EXC_NAN 0.0 / 0.0
#define EXC_INF 1.0 / 0.0
#define EPS_20 1E-20
#define EPS_18 1E-18
#define EPS_16 1E-16
#define N_PI 3.14159265358979323846264338327950288
#define LN2 0.693147180559945309417232121458176568
#define LN10 2.3025850929940456840179914546844
#define N_E 2.71828182845904523536028747135266250
#define DBL_MAXIMUM 1E20

long double s21_log(double x);
long double s21_sqrt(double x);
long double s21_pow(double base, double exp);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
int s21_abs(int x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fabs(double x);
long double s21_exp(double x);
long double s21_fmod(double x, double y);

#endif  // SRC_S21_MATH_H_
