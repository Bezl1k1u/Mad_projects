#include "tests.h"

START_TEST(atoii_test_p) {
  char src[] = "12345";
  int test = 12345;
  ck_assert_int_eq(test, s21_atoi(src));
}
END_TEST

START_TEST(atoii_test_n) {
  char src[] = "-12345";
  int test = -12345;
  ck_assert_int_eq(test, s21_atoi(src));
}
END_TEST

START_TEST(atol_test_p) {
  char src[] = "1234567890123";
  long test = 1234567890123;
  ck_assert_int_eq(test, s21_atoi(src));
}
END_TEST

START_TEST(atol_test_n) {
  char src[] = "-123457890123";
  long test = -123457890123;
  ck_assert_int_eq(test, s21_atoi(src));
}
END_TEST

START_TEST(atoll_test_p) {
  char src[] = "12345678901234567";
  long long test = 12345678901234567;
  ck_assert_int_eq(test, s21_atoi(src));
}
END_TEST

START_TEST(atoll_test_n) {
  char src[] = "-12345678901234567";
  long long test = -12345678901234567;
  ck_assert_int_eq(test, s21_atoi(src));
}
END_TEST

START_TEST(atos_test_p) {
  char src[] = "12345";
  short test = 12345;
  ck_assert_int_eq(test, s21_atoi(src));
}
END_TEST

START_TEST(atos_test_n) {
  char src[] = "-12345";
  short test = -12345;
  ck_assert_int_eq(test, s21_atoi(src));
}
END_TEST

START_TEST(atof_test_p) {
  char src[] = "12345.6";
  float test = 12345.6;
  ck_assert_float_eq(test, s21_atof(src));
}
END_TEST

START_TEST(atof_test_n) {
  char src[] = "-12345.6";
  float test = -12345.6;
  ck_assert_float_eq(test, s21_atof(src));
}
END_TEST

START_TEST(atod_test_p) {
  char src[] = "12345.678";
  double test = 12345.678;
  ck_assert_double_eq(test, s21_atof(src));
}
END_TEST

START_TEST(atod_test_n) {
  char src[] = "-12345.67";
  double test = -12345.67;
  ck_assert_double_eq(test, s21_atof(src));
}
END_TEST

START_TEST(atohex_test_p) {
  char src[] = "123Ab";
  int test = 74667;
  ck_assert_int_eq(test, s21_atohex(src));  // s21_atohex
}
END_TEST

START_TEST(atohex_test_n) {
  char src[] = "-1234aB";
  int test = -1193131;
  ck_assert_int_eq(test, s21_atohex(src));  // s21_atohex
}
END_TEST

START_TEST(ato8_test_p) {
  char src[] = "12345";
  int test = 5349;
  ck_assert_int_eq(test, s21_ato8(src));  // s21_ato8
}
END_TEST

START_TEST(ato8_test_n) {
  char src[] = "-1234567";
  int test = -342391;
  ck_assert_int_eq(test, s21_ato8(src));  // s21_ato8
}
END_TEST

START_TEST(atoE_test_p) {
  char src[] = "12345";
  float test = 1.2345e+04;
  ck_assert_double_eq(test, s21_atoi(src));
}
END_TEST

START_TEST(atoE_test_n) {
  char src[] = "-1234567";
  float test = -1.234567e+06;
  ck_assert_double_eq(test, s21_atoi(src));
}
END_TEST

Suite *suite_atoi(void) {
  Suite *s = suite_create("suite_atoi");
  TCase *tc = tcase_create("atoi_tc");

  tcase_add_test(tc, atoii_test_p);
  tcase_add_test(tc, atoii_test_n);
  tcase_add_test(tc, atol_test_p);
  tcase_add_test(tc, atol_test_n);
  tcase_add_test(tc, atoll_test_p);
  tcase_add_test(tc, atoll_test_n);
  tcase_add_test(tc, atos_test_p);
  tcase_add_test(tc, atos_test_n);
  tcase_add_test(tc, atof_test_p);
  tcase_add_test(tc, atof_test_n);
  tcase_add_test(tc, atod_test_p);
  tcase_add_test(tc, atod_test_n);
  tcase_add_test(tc, atohex_test_p);
  tcase_add_test(tc, atohex_test_n);
  tcase_add_test(tc, ato8_test_p);
  tcase_add_test(tc, ato8_test_n);
  tcase_add_test(tc, atoE_test_p);
  tcase_add_test(tc, atoE_test_n);

  suite_add_tcase(s, tc);
  return s;
}
