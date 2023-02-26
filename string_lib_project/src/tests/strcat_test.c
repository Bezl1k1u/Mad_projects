#include "tests.h"

START_TEST(strcat_1) {
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(strcat(b1, str_1_2), s21_strcat(b11, str_1_2));
}
END_TEST

START_TEST(strcat_2) {
  char b2[1024] = "THE";
  char b22[1024] = "THE";
  char str_2_2[1024] = " BEST!!";
  ck_assert_pstr_eq(strcat(b2, str_2_2), s21_strcat(b22, str_2_2));
}
END_TEST

START_TEST(strcat_3) {
  char b3[1024] = "777";
  char b33[1024] = "777";
  char str_3_2[1024] = " LUGANO!";
  ck_assert_pstr_eq(strcat(b3, str_3_2), s21_strcat(b33, str_3_2));
}
END_TEST

START_TEST(strcat_Hello_aboba) {
  char src[] = " aboba!!!";
  char res[5 + 10] = "Hello";
  char expected[5 + 10] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_zero_first) {
  char src[] = " aboba!!!";
  char res[0 + 10] = "";
  char expected[0 + 10] = "";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_zero_last) {
  char src[] = "";
  char res[] = "Hello";
  char expected[] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_any_letters_with_register) {
  char src[] = "asdfj  asdf aisdfjaiushdfASD SAD asDSad ASDAsdwqqeAS";
  char res[5 + 53] = "Hello";
  char expected[5 + 53] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_any_letters_with_register_and_num) {
  char src[] = "asd0fj  asd1f aisdfjw6234A1241SD SA5 asDSad 89SDAsdw7qqeAS";
  char res[5 + 59] = "Hello";
  char expected[5 + 59] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_any_letters_with_register_and_num_and_sim) {
  char src[] =
      "asd0fj  asd1f aisdfjw6234A1241SD SA5 asDSad 89SDAsdw7qqeAS)(?!.,";
  char res[5 + 65] = "Hello";
  char expected[5 + 65] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

Suite *suite_strcat(void) {
  Suite *s = suite_create("suite_strcat");
  TCase *tc = tcase_create("strcat_tc");
  tcase_add_test(tc, strcat_1);
  tcase_add_test(tc, strcat_2);
  tcase_add_test(tc, strcat_3);
  tcase_add_test(tc, strcat_Hello_aboba);
  tcase_add_test(tc, strcat_zero_first);
  tcase_add_test(tc, strcat_zero_last);
  tcase_add_test(tc, strcat_any_letters_with_register);
  tcase_add_test(tc, strcat_any_letters_with_register_and_num);
  tcase_add_test(tc, strcat_any_letters_with_register_and_num_and_sim);
  suite_add_tcase(s, tc);
  return s;
}
