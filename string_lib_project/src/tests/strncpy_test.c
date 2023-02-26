#include "tests.h"

START_TEST(strncpy_1) {
  s21_size_t n1 = 30;
  char b1[1024] = "1111111111";
  char b11[1024] = "1111111111";
  char str_1_2[1024] = "123\0";
  ck_assert_pstr_eq(strncpy(b1, str_1_2, n1), s21_strncpy(b11, str_1_2, n1));
}
END_TEST

START_TEST(strncpy_2) {
  s21_size_t n2 = 5;
  char b2[1024] = "1111111111";
  char b22[1024] = "1111111111";
  char str_2_2[1024] = "12345\0006789";
  ck_assert_pstr_eq(strncpy(b2, str_2_2, n2), s21_strncpy(b22, str_2_2, n2));
}
END_TEST

START_TEST(strncpy_3) {
  s21_size_t n3 = 5;
  char b3[1024] = "11";
  char b33[1024] = "11";
  char str_3_2[1024] = "12345\0006789";
  ck_assert_pstr_eq(strncpy(b3, str_3_2, n3), s21_strncpy(b33, str_3_2, n3));
}
END_TEST

START_TEST(strncpy_empty) {
  char src[] = "";
  char res[] = "";
  char exp[] = "";
  s21_size_t n_byte = 0;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_zero_byte) {
  char src[] = "123";
  char res[] = "123";
  char exp[] = "123";
  s21_size_t n_byte = 0;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_empty_src) {
  char src[] = "";
  char res[] = "123";
  char exp[] = "123";
  s21_size_t n_byte = 0;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_one_byte) {
  char src[] = "123";
  char res[5] = "123";
  char exp[5] = "123";
  s21_size_t n_byte = 1;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_two_byte) {
  char src[] = "123";
  char res[7] = "123";
  char exp[7] = "123";
  s21_size_t n_byte = 2;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_string) {
  char src[] = "Str1ng";
  char res[7 + 7] = "Str1ng";
  char exp[7 + 7] = "Str1ng";
  s21_size_t n_byte = 7;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

Suite *suite_strncpy(void) {
  Suite *s = suite_create("suite_strncpy");
  TCase *tc = tcase_create("strncpy_tc");
  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, strncpy_empty);
  tcase_add_test(tc, strncpy_zero_byte);
  tcase_add_test(tc, strncpy_empty_src);
  tcase_add_test(tc, strncpy_one_byte);
  tcase_add_test(tc, strncpy_two_byte);
  tcase_add_test(tc, strncpy_string);

  suite_add_tcase(s, tc);
  return s;
}
