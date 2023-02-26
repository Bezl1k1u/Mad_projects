#include "tests.h"

START_TEST(strcmp_1) {
  char *str_1_1 = "LUGANO!";
  char *str_1_2 = "LUGANO!";
  int s21_c = s21_strcmp(str_1_1, str_1_2);
  int s_c = strcmp(str_1_1, str_1_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strcmp_2) {
  char *str_2_1 = "LUGANO THE BEST!";
  char *str_2_2 = "LUGANO OF THE BEST!";
  int s21_c = s21_strcmp(str_2_1, str_2_2);
  int s_c = strcmp(str_2_1, str_2_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strcmp_3) {
  char *str_3_1 = "LUGANO OF THE BEST!!!!!";
  char *str_3_2 = "LUGANO!";
  int s21_c = s21_strcmp(str_3_1, str_3_2);
  int s_c = strcmp(str_3_1, str_3_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strcmp_Heloboba_Heloboba) {
  char a[] = "Heloboba";
  char b[] = "Heloboba";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_HEloboba_Heloboba) {
  char a[] = "HEloboba";
  char b[] = "Heloboba";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_Hel0boba_Helob0ba) {
  char a[] = "Hel0boba";
  char b[] = "Helob0ba";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_Heloboba_) {
  char a[] = "Heloboba";
  char b[] = "";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_empty_) {
  char a[] = "";
  char b[] = "";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp__Heloboba) {
  char a[] = "";
  char b[] = "Heloboba";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_Heloboba) {
  char a[] = "L(8)L";
  char b[] = "L(8)L";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_empty) {
  char a[] = "";
  char b[] = "";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_only_num) {
  char a[] = "1234567890";
  char b[] = "1234567890";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

Suite *suite_strcmp(void) {
  Suite *s = suite_create("suite_strcmp");
  TCase *tc = tcase_create("strcmp_tc");
  tcase_add_test(tc, strcmp_1);
  tcase_add_test(tc, strcmp_2);
  tcase_add_test(tc, strcmp_3);
  tcase_add_test(tc, strcmp_Heloboba_Heloboba);
  tcase_add_test(tc, strcmp_HEloboba_Heloboba);
  tcase_add_test(tc, strcmp_Hel0boba_Helob0ba);
  tcase_add_test(tc, strcmp_Heloboba_);
  tcase_add_test(tc, strcmp_empty_);
  tcase_add_test(tc, strcmp__Heloboba);
  tcase_add_test(tc, strcmp_Heloboba);
  tcase_add_test(tc, strcmp_empty);
  tcase_add_test(tc, strcmp_only_num);
  suite_add_tcase(s, tc);
  return s;
}
