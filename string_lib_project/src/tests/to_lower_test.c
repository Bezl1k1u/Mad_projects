#include "tests.h"

START_TEST(to_lower_1) {
  char str1[] = "hEllO, WoRLD!";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_pstr_eq(str2, "hello, world!");
}
END_TEST

START_TEST(to_lower_2) {
  char str1[] = "hEllO, WoRLD! 1177";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_pstr_eq(str2, "hello, world! 1177");
}
END_TEST

START_TEST(to_lower_test1) {
  char str[] = "ShLePa V TaZ1Ke?";
  char expected[] = "shlepa v taz1ke?";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(to_lower_test2) {
  char str[] = "123456789Q";
  char expected[] = "123456789q";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(to_lower_test3) {
  char str[] = "Space created";
  char expected[] = "space created";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(to_lower_test4) {
  char str[] = "";
  char expected[] = "";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(to_lower_test5) {
  char str[] = "";
  char expected[] = "";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
}
END_TEST

Suite *suite_to_lower(void) {
  Suite *s = suite_create("suite_to_lower");
  TCase *tc = tcase_create("to_lower_tc");
  tcase_add_test(tc, to_lower_1);
  tcase_add_test(tc, to_lower_2);
  tcase_add_test(tc, to_lower_test1);
  tcase_add_test(tc, to_lower_test2);
  tcase_add_test(tc, to_lower_test3);
  tcase_add_test(tc, to_lower_test4);
  tcase_add_test(tc, to_lower_test5);

  suite_add_tcase(s, tc);
  return s;
}
