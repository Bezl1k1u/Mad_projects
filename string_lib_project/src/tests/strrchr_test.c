#include "tests.h"

START_TEST(strrchr_1) {
  char str[] = "0163456769";
  ck_assert_pstr_eq(strrchr(str, '6'), s21_strrchr(str, '6'));
}
END_TEST

START_TEST(strrchr_2) {
  char str2[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strrchr(str2, 'o'), s21_strrchr(str2, 'o'));
}
END_TEST

START_TEST(strrchr_3) {
  char str3[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strrchr(str3, 'h'), s21_strrchr(str3, 'h'));
}
END_TEST

START_TEST(strrchr_4) {
  char str4[] = "";
  ck_assert_pstr_eq(strrchr(str4, 'd'), s21_strrchr(str4, 'd'));
}
END_TEST

START_TEST(strrchr_5) {
  char str5[] = {""};
  ck_assert_pstr_eq(strrchr(str5, 'z'), s21_strrchr(str5, 'z'));
}
END_TEST

START_TEST(strrchr_empty) {
  char str1[] = "";
  char str2 = '\0';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST  // FAIL

START_TEST(strrchr_floppy_) {
  char str1[] = "floppy";
  char str2 = '\0';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr__floppy) {
  char str1[] = "";
  char str2 = 'f';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_poki_doki_o) {
  char str1[] = "poki doki";
  char str2 = 'o';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_poki_doki_i) {
  char str1[] = "poki doki";
  char str2 = 'i';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_poki_doki_p) {
  char str1[] = "poki p dokip";
  char str2 = 'p';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_find_big_P) {
  char str1[] = "ppPpppppppppP";
  char str2 = 'P';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_find_zero) {
  char str1[] = "123456789";
  char str2 = '0';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

Suite *suite_strrchr(void) {
  Suite *s = suite_create("suite_strrchr");
  TCase *tc = tcase_create("strrchr_tc");
  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_empty);
  tcase_add_test(tc, strrchr_floppy_);
  tcase_add_test(tc, strrchr__floppy);
  tcase_add_test(tc, strrchr_poki_doki_o);
  tcase_add_test(tc, strrchr_poki_doki_i);
  tcase_add_test(tc, strrchr_poki_doki_p);
  tcase_add_test(tc, strrchr_find_big_P);
  tcase_add_test(tc, strrchr_find_zero);

  suite_add_tcase(s, tc);
  return s;
}