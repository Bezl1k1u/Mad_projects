#include "tests.h"

START_TEST(trim_1) {
  char src1[] = "     &#@\n\n\t Hello, World! *&#@ \n\t   ";
  char trim_chars[] = " &#@\n\t";
  char *psrc = s21_trim(src1, trim_chars);
  ck_assert_pstr_eq(psrc, "Hello, World! *");
}
END_TEST

START_TEST(trim_2) {
  char src1[] = "    \n\tHello, World! *&#@ \n\t   ";
  char trim_chars[] = "";
  char *psrc = s21_trim(src1, trim_chars);
  ck_assert_pstr_eq(psrc, "Hello, World! *&#@");
}
END_TEST

START_TEST(trim_all_empty) {
  char str[] = "";
  char trim_ch[] = "";
  char *expected = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_pstr_eq(got, expected);
}
END_TEST

START_TEST(trim_str_empty) {
  char str[] = "";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(trim_empty) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "";
  char *expected = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(trim_and_str_eq) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(trim_test1) {
  char str[] = "+!!++Abo+ba++00";
  char trim_ch[] = "+!0-";
  char expected[] = "Abo+ba";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(trim_test2) {
  char str[] = "Ab000cd0";
  char trim_ch[] = "003";
  char expected[] = "Ab000cd";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(trim_test3) {
  char str[] = "DoNotTouch";
  char trim_ch[] = "Not";
  char expected[] = "DoNotTouch";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(trim_test4) {
  char str[] = "&* !!sc21 * **";
  char trim_ch[] = "&!* ";
  char expected[] = "sc21";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(trim_test5) {
  char str[] = " Good morning!    ";
  char trim_ch[] = " ";
  char expected[] = "Good morning!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(trim_empty_spaces) {
  char str[] = "        abc         ";
  char trim_ch[] = "";
  char *expected = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_pstr_eq(got, expected);
}
END_TEST

START_TEST(trim_null_ptr_trim_chars) {
  char str[] = "        abc         ";
  char *trim_ch = S21_NULL;
  char expected[] = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
}
END_TEST

Suite *suite_trim(void) {
  Suite *s = suite_create("suite_trim");
  TCase *tc = tcase_create("trim_tc");
  tcase_add_test(tc, trim_1);
  tcase_add_test(tc, trim_2);
  tcase_add_test(tc, trim_all_empty);
  tcase_add_test(tc, trim_str_empty);
  tcase_add_test(tc, trim_empty);
  tcase_add_test(tc, trim_and_str_eq);
  tcase_add_test(tc, trim_test1);
  tcase_add_test(tc, trim_test2);
  tcase_add_test(tc, trim_test3);
  tcase_add_test(tc, trim_test4);
  tcase_add_test(tc, trim_test5);
  tcase_add_test(tc, trim_empty_spaces);
  tcase_add_test(tc, trim_null_ptr_trim_chars);

  suite_add_tcase(s, tc);
  return s;
}
