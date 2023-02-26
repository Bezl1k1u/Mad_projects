#include "tests.h"

START_TEST(strspn_1) {
  char str[] = "12-years";
  ck_assert_int_eq(strspn(str, "1234567890"), s21_strspn(str, "1234567890"));
}
END_TEST

START_TEST(strspn_2) {
  char str2[] = "this is a test";
  ck_assert_int_eq(strspn(str2, "shit "), s21_strspn(str2, "shit "));
}
END_TEST

START_TEST(strspn_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's'};
  ck_assert_int_eq(strspn(str3, "01234"), s21_strspn(str3, "01234"));
}
END_TEST

START_TEST(strspn_empty) {
  char src[] = "";
  char res[] = "";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_gora_) {
  char src[] = "gora";
  char res[] = "";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn__gora) {
  char src[] = "";
  char res[] = "gora";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_any_register) {
  char src[] = "gora";
  char res[] = "gOra";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_num_num) {
  char src[] = "123";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_long_num_num) {
  char src[] = "12345";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_num_long_num) {
  char src[] = "123";
  char res[] = "12345";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_any_num) {
  char src[] = "1234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_num_with_letter) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_num_with_letter2) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_basic_test) {
  char src[] = "absD";
  char res[] = "aD";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_any_sim) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_upper_letter) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_lower_letter) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_not_uniq_sim) {
  char src[] =
      "333333333333333333333333333333333333333333333333333333333333333333333333"
      "33333333333333";
  char res[] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111111113";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

Suite *suite_strspn(void) {
  Suite *s = suite_create("suite_strspn");
  TCase *tc = tcase_create("strspn_tc");
  tcase_add_test(tc, strspn_1);
  tcase_add_test(tc, strspn_2);
  tcase_add_test(tc, strspn_3);
  tcase_add_test(tc, strspn_empty);
  tcase_add_test(tc, strspn_gora_);
  tcase_add_test(tc, strspn__gora);
  tcase_add_test(tc, strspn_any_register);
  tcase_add_test(tc, strspn_num_num);
  tcase_add_test(tc, strspn_long_num_num);
  tcase_add_test(tc, strspn_num_long_num);
  tcase_add_test(tc, strspn_any_num);
  tcase_add_test(tc, strspn_num_with_letter);
  tcase_add_test(tc, strspn_num_with_letter2);
  tcase_add_test(tc, strspn_basic_test);
  tcase_add_test(tc, strspn_any_sim);
  tcase_add_test(tc, strspn_upper_letter);
  tcase_add_test(tc, strspn_lower_letter);
  tcase_add_test(tc, strspn_not_uniq_sim);

  suite_add_tcase(s, tc);
  return s;
}
