#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(fabs_tests) {
  ck_assert_int_eq(fabs(-13.21313), s21_fabs(-13.21313));
  ck_assert_int_eq(fabs(13.21313), s21_fabs(13.21313));
  ck_assert_int_eq(fabs(-1000.21313), s21_fabs(-1000.21313));
  ck_assert_int_eq(fabs(32346234.21313), s21_fabs(32346234.21313));
  ck_assert_int_eq(fabs(0.0), s21_fabs(0.0));
  double a = -0.000001;
  ck_assert_double_eq_tol(fabs(a), s21_fabs(a), 1e-09);
  a = -123242424.12414554533;
  ck_assert_double_eq_tol(fabs(a), s21_fabs(a), 1e-09);
  for (double i = -10; i < 10; i += 0.001)
    ck_assert_double_eq_tol(fabs(i), s21_fabs(i), 1e-09);
}
END_TEST

START_TEST(fmod_tests) {
  ck_assert_ldouble_eq(fmod(-13.21313, 2.5), s21_fmod(-13.21313, 2.5));
  ck_assert_ldouble_eq(fmod(13.21313, 2.5), s21_fmod(13.21313, 2.5));
  ck_assert_ldouble_eq(fmod(-1000.21313, 2.5), s21_fmod(-1000.21313, 2.5));
  ck_assert_ldouble_eq(fmod(32346234.21313, 2.5),
                       s21_fmod(32346234.21313, 2.5));
  ck_assert_ldouble_eq(fmod(0, 2.5), s21_fmod(0, 2.5));
  ck_assert_ldouble_eq(fmod(2.5, 2.5), s21_fmod(2.5, 2.5));
  double x = 53456.43523;
  double y = 2345.34535;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-9);
  x = 53456.43523;
  y = -2345.34535;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-9);
  x = -53456.43523;
  y = 2345.34535;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-9);
  x = -10.1;
  y = -3.;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-9);
  x = 53456.43523;
  y = 0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 0;
  y = 35353.4232;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-9);
  x = 0;
  y = -EXC_NAN;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = EXC_NAN;
  y = 245.32525;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 2424.424525;
  y = EXC_NAN;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 246346346.43534;
  y = EXC_INF;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-9);
  x = EXC_INF;
  y = 214124.123;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  ck_assert_ldouble_nan(s21_fmod(214124.123, EXC_NAN));
  ck_assert_ldouble_nan(s21_fmod(EXC_NAN, 214124.123));
}
END_TEST

START_TEST(exp_tests) {
  ck_assert_float_eq(exp(-13.54), s21_exp(-13.54));
  ck_assert_float_eq(exp(13.54), s21_exp(13.54));
  ck_assert_float_eq(exp(-0.54), s21_exp(-0.54));
  ck_assert_float_eq(exp(1000), s21_exp(1000));
  ck_assert_float_eq(exp(1), s21_exp(1));
  ck_assert_float_eq(exp(2), s21_exp(2));
  ck_assert_double_eq(exp(100), s21_exp(100));  // inf?
  ck_assert_float_eq(exp(-1), s21_exp(-1));
  ck_assert_float_eq(exp(0), s21_exp(0));
  ck_assert_int_eq(exp(EXC_NAN), s21_exp(EXC_NAN));  // nan!
  ck_assert_float_eq(exp(710), s21_exp(710));
  ck_assert_float_eq(exp(1.2345), s21_exp(1.2345));
  ck_assert_float_eq(exp(1.23454656768), s21_exp(1.23454656768));
  ck_assert_double_eq(exp(102.0000002), s21_exp(102.0000002));  // inf?
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-6);
  ck_assert_ldouble_infinite(s21_exp(EXC_INF));
  ck_assert_ldouble_nan(s21_exp(EXC_NAN));
  x = 3.5;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-6);
  x = -32.7584;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-6);
}
END_TEST

START_TEST(asin_tests) {
  ck_assert_int_eq(asin(-13.54), s21_asin(-13.54));
  ck_assert_int_eq(asin(13.54), s21_asin(13.54));
  ck_assert_int_eq(asin(6.28), s21_asin(6.28));
  ck_assert_float_eq(asin(EPS_16), s21_asin(EPS_16));
  ck_assert_float_eq(asin(0.1234), s21_asin(0.1234));
  ck_assert_float_eq(asin(0), s21_asin(0));
  ck_assert_float_eq(asin(1), s21_asin(1));
  ck_assert_float_eq(asin(-1), s21_asin(-1));
  ck_assert_float_eq(asin(0.5), s21_asin(0.5));
  ck_assert_float_eq(asin(-0.5), s21_asin(-0.5));
  ck_assert_ldouble_eq_tol(s21_asin(N_PI / 4), asin(N_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(N_PI / 6), asin(N_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-N_PI / 4), asin(-N_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-N_PI / 6), asin(-N_PI / 6), 1e-6);
  ck_assert_ldouble_nan(s21_asin(EXC_INF));
  ck_assert_ldouble_nan(s21_asin(EXC_NAN));
  ck_assert_ldouble_nan(s21_asin(-EXC_INF));
  ck_assert_ldouble_nan(s21_asin(1.0000001));
  ck_assert_ldouble_nan(s21_asin(-1.0000001));
  ck_assert_ldouble_nan(s21_asin(N_PI / 3));
}
END_TEST

START_TEST(acos_tests) {
  ck_assert_int_eq(acos(-13.54), s21_acos(-13.54));
  ck_assert_int_eq(acos(13.54), s21_acos(13.54));
  ck_assert_int_eq(acos(2.2343), s21_acos(2.2343));
  ck_assert_float_eq(acos(0.1234), s21_acos(0.1234));
  ck_assert_float_eq(acos(0), s21_acos(0));
  ck_assert_float_eq(acos(1), s21_acos(1));
  ck_assert_float_eq(acos(-1), s21_acos(-1));
  ck_assert_float_eq(acos(0.5), s21_acos(0.5));
  ck_assert_float_eq(acos(-0.5), s21_acos(-0.5));
  ck_assert_ldouble_eq_tol(s21_acos(N_PI / 4), acos(N_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(N_PI / 6), acos(N_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-N_PI / 4), acos(-N_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-N_PI / 6), acos(-N_PI / 6), 1e-6);
  ck_assert_ldouble_nan(s21_acos(EXC_INF));
  ck_assert_ldouble_nan(s21_acos(EXC_NAN));
  ck_assert_ldouble_nan(s21_acos(-EXC_INF));
  ck_assert_ldouble_nan(s21_acos(1.0000001));
  ck_assert_ldouble_nan(s21_acos(-1.0000001));
  ck_assert_ldouble_nan(s21_acos(N_PI / 3));
}
END_TEST

START_TEST(atan_tests) {
  ck_assert_int_eq(atan(-13.54), s21_atan(-13.54));
  ck_assert_float_eq(atan(13.54), s21_atan(13.54));
  ck_assert_float_eq(atan(3.14), s21_atan(3.14));
  ck_assert_float_eq(atan(6.28), s21_atan(6.28));
  ck_assert_float_eq(atan(2.2343), s21_atan(2.2343));
  ck_assert_float_eq(atan(0.1234), s21_atan(0.1234));
  ck_assert_float_eq(atan(0), s21_atan(0));
  ck_assert_float_eq(atan(1), s21_atan(1));
  ck_assert_float_eq(atan(-1), s21_atan(-1));
  ck_assert_float_eq(atan(3.5), s21_atan(3.5));
  ck_assert_float_eq(atan(-3.5), s21_atan(-3.5));
  ck_assert_ldouble_eq_tol(s21_atan(N_PI / 2), atan(N_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(N_PI / 4), atan(N_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(N_PI / 6), atan(N_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(N_PI / 3), atan(N_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-N_PI / 2), atan(-N_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-N_PI / 4), atan(-N_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-N_PI / 6), atan(-N_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-N_PI / 3), atan(-N_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-N_PI), atan(-N_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(N_PI), atan(N_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(EXC_INF), atan(EXC_INF), 1e-6);
  ck_assert_ldouble_nan(s21_atan(EXC_NAN));
  ck_assert_ldouble_eq_tol(s21_atan(-EXC_INF), atan(-EXC_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(2.352352), atan(2.352352), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-2.352352), atan(-2.352352), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.00032), atan(0.00032), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-0.00032), atan(-0.00032), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(325235), atan(325235), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-325235), atan(-325235), 1e-6);
}
END_TEST

START_TEST(abs_tests) {
  ck_assert_int_eq(abs(-13), s21_abs(-13));
  ck_assert_int_eq(abs(13), s21_abs(13));
  ck_assert_int_eq(abs(-1000), s21_abs(-1000));
  ck_assert_int_eq(abs(32346234), s21_abs(32346234));
  ck_assert_int_eq(abs(0), s21_abs(0));
  int a = -123412451;
  ck_assert_double_eq_tol(abs(a), s21_abs(a), 1e-09);
  a = -123242424.0;
  ck_assert_double_eq_tol(abs(a), s21_abs(a), 1e-09);
  a = 123242424.0;
  ck_assert_double_eq_tol(abs(a), s21_abs(a), 1e-09);
  for (int i = -1000; i < 1000; i += 10)
    ck_assert_double_eq_tol(abs(i), s21_abs(i), 1e-09);
}
END_TEST

START_TEST(ceil_tests) {
  ck_assert_ldouble_eq(ceil(-13.54), s21_ceil(-13.54));
  ck_assert_ldouble_eq(ceil(13.54), s21_ceil(13.54));
  ck_assert_ldouble_eq(ceil(1000), s21_ceil(1000));
  ck_assert_ldouble_eq(ceil(102.0000002), s21_ceil(102.0000002));
  ck_assert_ldouble_infinite(s21_ceil(EXC_INF));
  double x = 8543948.445;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
  ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
  ck_assert_ldouble_eq(s21_ceil(232424), ceil(232424));
  ck_assert_ldouble_nan(s21_ceil(EXC_NAN));
  ck_assert_ldouble_infinite(s21_ceil(-EXC_INF));
}
END_TEST

START_TEST(floor_tests) {
  ck_assert_ldouble_eq(floor(-13.54), s21_floor(-13.54));
  ck_assert_ldouble_eq(floor(13.54), s21_floor(13.54));
  ck_assert_ldouble_eq(floor(-0.54), s21_floor(-0.54));
  ck_assert_ldouble_eq(floor(1000), s21_floor(1000));
  ck_assert_ldouble_eq(floor(102.0000002), s21_floor(102.0000002));
  ck_assert_ldouble_eq(s21_floor(0), floor(0));
  double x = 8543948.445;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  ck_assert_ldouble_infinite(s21_floor(EXC_INF));
  ck_assert_ldouble_infinite(s21_floor(-EXC_INF));
  x = -8543948.445;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  ck_assert_ldouble_nan(s21_floor(EXC_NAN));
}
END_TEST

START_TEST(sin_tests) {
  ck_assert_float_eq(sin(-13.54), s21_sin(-13.54));
  ck_assert_float_eq(sin(13.54), s21_sin(13.54));
  ck_assert_float_eq(sin(0.0), s21_sin(0.0));
  ck_assert_float_eq(sin(1.0), s21_sin(1.0));
  ck_assert_float_eq(sin(3.14), s21_sin(3.14));
  ck_assert_float_eq(sin(6.28), s21_sin(6.28));
  ck_assert_float_eq(sin(2.2343), s21_sin(2.2343));
  ck_assert_float_eq(sin(0.1234), s21_sin(0.1234));
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_sin(0.123456), sin(0.123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_sin(0.999999), sin(0.999999), 1e-7);
  ck_assert_ldouble_eq_tol(s21_sin(123456), sin(123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_sin(-654321), sin(-654321), 1e-7);
  for (double i = -N_PI; i < N_PI; i += 0.001) {
    ck_assert_ldouble_eq_tol(s21_sin(i), sin(i), 1e-7);
  }
  ck_assert_ldouble_eq_tol(s21_sin(N_PI / 2), sin(N_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(N_PI / 4), sin(N_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(N_PI / 6), sin(N_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(N_PI / 3), sin(N_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-N_PI / 2), sin(-N_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-N_PI / 4), sin(-N_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-N_PI / 6), sin(-N_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-N_PI / 3), sin(-N_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-N_PI), sin(-N_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(N_PI), sin(N_PI), 1e-6);
  ck_assert_ldouble_nan(s21_sin(EXC_INF));
  ck_assert_ldouble_nan(s21_sin(EXC_NAN));
  ck_assert_ldouble_nan(s21_sin(-EXC_INF));
  ck_assert_ldouble_eq_tol(s21_sin(2.352352), sin(2.352352), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-2.352352), sin(-2.352352), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.00032), sin(0.00032), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0.00032), sin(-0.00032), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(325235), sin(325235), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-325235), sin(-325235), 1e-6);
}
END_TEST

START_TEST(cos_tests) {
  ck_assert_float_eq(cos(-13.54), s21_cos(-13.54));
  ck_assert_float_eq(cos(13.54), s21_cos(13.54));
  ck_assert_float_eq(cos(0.0), s21_cos(0.0));
  ck_assert_float_eq(cos(1.0), s21_cos(1.0));
  ck_assert_float_eq(cos(3.14), s21_cos(3.14));
  ck_assert_float_eq(cos(6.28), s21_cos(6.28));
  ck_assert_float_eq(cos(2.2343), s21_cos(2.2343));
  ck_assert_float_eq(cos(0.1234), s21_cos(0.1234));
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_cos(0.123456), cos(0.123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_cos(0.999999), cos(0.999999), 1e-7);
  ck_assert_ldouble_eq_tol(s21_cos(123456), cos(123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_cos(-654321), cos(-654321), 1e-7);
  for (double i = -N_PI; i < N_PI; i += 0.001) {
    ck_assert_ldouble_eq_tol(s21_cos(i), cos(i), 1e-7);
  }
  ck_assert_ldouble_eq_tol(s21_cos(N_PI / 2), cos(N_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(N_PI / 4), cos(N_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(N_PI / 6), cos(N_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(N_PI / 3), cos(N_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-N_PI / 2), cos(-N_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-N_PI / 4), cos(-N_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-N_PI / 6), cos(-N_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-N_PI / 3), cos(-N_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-N_PI), cos(-N_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(N_PI), cos(N_PI), 1e-6);
  ck_assert_ldouble_nan(s21_cos(EXC_INF));
  ck_assert_ldouble_nan(s21_cos(EXC_NAN));
  ck_assert_ldouble_nan(s21_cos(-EXC_INF));
  ck_assert_ldouble_eq_tol(s21_cos(2.352352), cos(2.352352), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-2.352352), cos(-2.352352), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0.00032), cos(0.00032), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0.00032), cos(-0.00032), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(32523), cos(32523), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-32523), cos(-32523), 1e-6);
}
END_TEST

START_TEST(tan_tests) {
  ck_assert_float_eq(tan(-13.54), s21_tan(-13.54));
  ck_assert_float_eq(tan(13.54), s21_tan(13.54));
  ck_assert_float_eq(tan(0), s21_tan(0));
  ck_assert_float_eq(tan(1), s21_tan(1));
  ck_assert_float_eq(tan(3.14), s21_tan(3.14));
  ck_assert_float_eq(tan(6.28), s21_tan(6.28));
  ck_assert_float_eq(tan(2.2343), s21_tan(2.2343));
  ck_assert_float_eq(tan(0.1234), s21_tan(0.1234));
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_tan(0.123456), tan(0.123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_tan(0.999999), tan(0.999999), 1e-7);
  ck_assert_ldouble_eq_tol(s21_tan(123456), tan(123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_tan(-654321), tan(-654321), 1e-7);
  for (double i = -N_PI; i < N_PI; i += 0.001) {
    ck_assert_ldouble_eq_tol(s21_tan(i), tan(i), 1e-7);
  }
  double x = N_PI / 2;
  ck_assert_ldouble_nan(s21_tan(x));
  ck_assert_ldouble_nan(s21_tan(EXC_INF));
  ck_assert_ldouble_nan(s21_tan(-EXC_INF));
  ck_assert_ldouble_nan(s21_tan(EXC_NAN));
  x = 0;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 1e-06);
  x = 55.49234825;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 1e-06);
  ck_assert_ldouble_eq_tol(s21_tan(-N_PI / 6), tan(-N_PI / 6), 1e-0);
  ck_assert_ldouble_eq_tol(s21_tan(2 * N_PI), tan(2 * N_PI), 1e-06);
  ck_assert_ldouble_eq_tol(s21_tan(1.00001), tan(1.00001), 1e-06);
  ck_assert_ldouble_eq_tol(s21_tan(-1.00001), tan(-1.00001), 1e-06);
}
END_TEST

START_TEST(pow_tests) {
  ck_assert_int_eq(s21_pow(2.6, 3.45), pow(2.6, 3.45));
  ck_assert_int_eq(s21_pow(3.0, 14.0), pow(3.0, 14.0));
  ck_assert_int_eq(s21_pow(31.456, 4.3), pow(31.456, 4.3));
  ck_assert_int_eq(s21_pow(31.456, 0.3), pow(31.456, 0.3));
  ck_assert_int_eq(s21_pow(4.3, 4.3), pow(4.3, 4.3));
  ck_assert_int_eq(s21_pow(-1234, 4.3), pow(-1234, 4.3));
  ck_assert_int_eq(s21_pow(-1234, -4.3), pow(-1234, -4.3));
  ck_assert_int_eq(s21_pow(1234, -4.3), pow(1234, -4.3));
  ck_assert_int_eq(pow(-13.21313, 2.5), s21_pow(-13.21313, 2.5));
  ck_assert_float_eq(pow(13.21313, 2.5), s21_pow(13.21313, 2.5));
  ck_assert_int_eq(pow(-1000.21313, 2.5), s21_pow(-1000.21313, 2.5));
  ck_assert_float_eq(pow(32346234.21313, 2.5), s21_pow(32346234.21313, 2.5));
  ck_assert_float_eq(pow(0, 2.5), s21_pow(0, 2.5));
  ck_assert_float_eq(pow(123, -2), s21_pow(123, -2));
  ck_assert_ldouble_eq_tol(s21_pow(2.6, 3.45), pow(2.6, 3.45), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.6, -3.45), pow(2.6, -3.45), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(14, 0.45), pow(14, 0.45), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-16, 9), pow(-16, 9), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(16436.543, 0.31), pow(16436.543, 0.31),
                           1e-6);
  ck_assert_int_eq(s21_pow(EXC_INF, 0.45), EXC_INF);
  ck_assert_ldouble_nan(s21_pow(EXC_NAN, 24252353));
  ck_assert_ldouble_nan(s21_pow(N_PI, EXC_NAN));
  ck_assert_ldouble_eq(s21_pow(0.0, 0.0), pow(0.0, 0.0));
  ck_assert_ldouble_infinite(s21_pow(-EXC_INF, 1.0));
  ck_assert_ldouble_nan(s21_pow(EXC_NAN, 1.0));
}
END_TEST

START_TEST(sqrt_tests) {
  ck_assert_float_eq(sqrt(0.0), s21_sqrt(0.0));
  ck_assert_float_eq(sqrt(1.0), s21_sqrt(1.0));
  ck_assert_float_eq(sqrt(3.14), s21_sqrt(3.14));
  ck_assert_float_eq(sqrt(6.28), s21_sqrt(6.28));
  ck_assert_float_eq(sqrt(2.2343), s21_sqrt(2.2343));
  ck_assert_int_eq(sqrt(-123), s21_sqrt(-123));
  ck_assert_float_eq(sqrt(0.9), s21_sqrt(0.9));
  ck_assert_int_eq(s21_sqrt(16.0), sqrt(16.0));
  ck_assert_int_eq(s21_sqrt(45.35), sqrt(45.35));
  ck_assert_int_eq(s21_sqrt(5.0), sqrt(5.0));
  for (double i = -1.; i < 100000; i += 10) {
    ck_assert_int_eq(s21_sqrt(i), sqrt(i));
  }
  for (double i = 0; i < 1; i += 0.001) {
    ck_assert_int_eq(s21_sqrt(i), sqrt(i));
  }
  double x = 10.0;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
  ck_assert_ldouble_infinite(s21_sqrt(EXC_INF));
  ck_assert_ldouble_nan(s21_sqrt(EXC_NAN));
  ck_assert_ldouble_eq_tol(s21_sqrt(1.0), sqrt(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(10e+5), sqrt(10e+5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(2.6), sqrt(2.6), 1e-6);
}

START_TEST(log_tests) {
  ck_assert_int_eq(log(-13.54), s21_log(-13.54));
  ck_assert_float_eq(log(13.54), s21_log(13.54));
  ck_assert_float_eq(log(0.0), s21_log(0.0));
  ck_assert_int_eq(log(1.0), s21_log(1.0));
  ck_assert_float_eq(log(3.14), s21_log(3.14));
  ck_assert_float_eq(log(6.28), s21_log(6.28));
  ck_assert_float_eq(log(2.2343), s21_log(2.2343));
  ck_assert_float_eq(log(0.1234), s21_log(0.1234));
  ck_assert_int_eq(s21_log(12356), log(12356));
  ck_assert_int_eq(s21_log(1.1), log(1.1));
  double x = 0.0;
  ck_assert_ldouble_infinite(s21_log(x));
  for (double i = -1.; i < 10; i += 0.1) {
    ck_assert_int_eq(s21_log(i), log(i));
  }
  for (double i = 0.; i < 2; i += 0.01) {
    ck_assert_int_eq(s21_log(i), log(i));
  }
  x = 10.0;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 1e-6);
  ck_assert_ldouble_infinite(s21_log(EXC_INF));
  ck_assert_ldouble_nan(s21_log(EXC_NAN));
  ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), 1e-6);
  ck_assert_ldouble_nan(s21_log(-5));
  ck_assert_ldouble_eq_tol(s21_log(10e+16), log(10e+16), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(3.5), log(3.5), 1e-6);
}
END_TEST

Suite *s21_math_tests_create() {
  Suite *s21_math = suite_create("s21_math");
  TCase *s21_math_tests = tcase_create("S21_MATH");
  tcase_add_test(s21_math_tests, sin_tests);
  tcase_add_test(s21_math_tests, cos_tests);
  tcase_add_test(s21_math_tests, tan_tests);
  tcase_add_test(s21_math_tests, ceil_tests);
  tcase_add_test(s21_math_tests, floor_tests);
  tcase_add_test(s21_math_tests, abs_tests);
  tcase_add_test(s21_math_tests, asin_tests);
  tcase_add_test(s21_math_tests, acos_tests);
  tcase_add_test(s21_math_tests, atan_tests);
  tcase_add_test(s21_math_tests, exp_tests);
  tcase_add_test(s21_math_tests, fabs_tests);
  tcase_add_test(s21_math_tests, fmod_tests);
  tcase_add_test(s21_math_tests, pow_tests);
  tcase_add_test(s21_math_tests, sqrt_tests);
  tcase_add_test(s21_math_tests, log_tests);
  suite_add_tcase(s21_math, s21_math_tests);
  return s21_math;
}

int main() {
  Suite *s21_math = s21_math_tests_create();
  SRunner *s21_math_runner = srunner_create(s21_math);
  int number_failed;
  srunner_run_all(s21_math_runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(s21_math_runner);
  srunner_free(s21_math_runner);
  return number_failed == 0 ? 0 : 1;
}