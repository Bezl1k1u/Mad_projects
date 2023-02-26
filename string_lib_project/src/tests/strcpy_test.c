#include "tests.h"

START_TEST(strcpy_1) {
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(strcpy(b1, str_1_2), s21_strcpy(b11, str_1_2));
}
END_TEST

START_TEST(strcpy_2) {
  char b2[1024] = "";
  char b22[1024] = "";
  char str_2_2[1024] = "THE OF \0BEST!!";
  ck_assert_pstr_eq(strcpy(b2, str_2_2), s21_strcpy(b22, str_2_2));
}
END_TEST

START_TEST(strcpy_3) {
  char b3[1024] = "777 ";
  char b33[1024] = "777 ";
  char str_3_2[1024] = "LUGANO!";
  ck_assert_pstr_eq(strcpy(b3, str_3_2), s21_strcpy(b33, str_3_2));
}
END_TEST

START_TEST(strcpy_aboba_floppa) {
  char src[] = " floppa!!!";
  char res[5 + 15] = "aboba ";
  char expected[5 + 15] = "aboba ";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy__floppa) {
  char src[] = "Floppa!!!";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_aboba_) {
  char src[] = "";
  char res[5 + 15] = "abobas";
  char expected[5 + 15] = "abobas";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_empty) {
  char src[] = "";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_empty_num) {
  char src[] = "1";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_hello) {
  char src[] = " my dear friend\"";
  char res[5 + 15] = "Hello";
  char expected[5 + 15] = "Hello";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_over_string) {
  char src[] = "ab\0ba";
  char res[10 + 9] = "Gre\0t";
  char expected[10 + 9] = "Gre\0t";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_hard_test) {
  char src[] = "ad[sofijpoiajsdf pj98981h23 p9h floppa!!!";
  char res[49 + 42] = "as[oidjf paijsdf j9oqh2837o4h hUW auhduash W8awd";
  char expected[49 + 42] = "as[oidjf paijsdf j9oqh2837o4h hUW auhduash W8awd";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

Suite *suite_strcpy(void) {
  Suite *s = suite_create("suite_strcpy");
  TCase *tc = tcase_create("strcpy_tc");
  tcase_add_test(tc, strcpy_1);
  tcase_add_test(tc, strcpy_2);
  tcase_add_test(tc, strcpy_3);
  tcase_add_test(tc, strcpy_aboba_floppa);
  tcase_add_test(tc, strcpy__floppa);
  tcase_add_test(tc, strcpy_aboba_);
  tcase_add_test(tc, strcpy_empty);
  tcase_add_test(tc, strcpy_empty_num);
  tcase_add_test(tc, strcpy_hello);
  tcase_add_test(tc, strcpy_over_string);
  tcase_add_test(tc, strcpy_hard_test);

  suite_add_tcase(s, tc);
  return s;
}
