#include "tests.h"

START_TEST(strcspn_1) {
  char str1[] = "this is a test";
  ck_assert_int_eq(strcspn(str1, "ab"), s21_strcspn(str1, "ab"));
}
END_TEST

START_TEST(strcspn_2) {
  char str2[] = "LOST: 4-8-15-16-23-42";
  ck_assert_int_eq(strcspn(str2, "1234567890"),
                   s21_strcspn(str2, "1234567890"));
}
END_TEST

START_TEST(strcspn_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_int_eq(strcspn(str3, "zx"), s21_strcspn(str3, "zx"));
}
END_TEST

START_TEST(strcspn_empty) {
  char src[] = "";
  char res[] = "";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_gora_) {
  char src[] = "gora";
  char res[] = "";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn__gora) {
  char src[] = "";
  char res[] = "gora";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_any_register) {
  char src[] = "gora";
  char res[] = "gOra";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_num) {
  char src[] = "123";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_long_num_num) {
  char src[] = "12345";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_long_num) {
  char src[] = "123";
  char res[] = "12345";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_any_num) {
  char src[] = "1234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_with_letter) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_with_letter2) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_basic_test) {
  char src[] = "absD";
  char res[] = "aD";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_any_sim) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_upper_letter) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_lower_letter) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_not_uniq_sim) {
  char src[] =
      "333333333333333333333333333333333333333333333333333333333333333333333333"
      "33333333333333";
  char res[] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111111113";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

Suite *suite_strcspn(void) {
  Suite *s = suite_create("suite_strcspn");
  TCase *tc = tcase_create("strcspn_tc");
  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_empty);
  tcase_add_test(tc, strcspn_gora_);
  tcase_add_test(tc, strcspn__gora);
  tcase_add_test(tc, strcspn_any_register);
  tcase_add_test(tc, strcspn_num_num);
  tcase_add_test(tc, strcspn_long_num_num);
  tcase_add_test(tc, strcspn_num_long_num);
  tcase_add_test(tc, strcspn_any_num);
  tcase_add_test(tc, strcspn_num_with_letter);
  tcase_add_test(tc, strcspn_num_with_letter2);
  tcase_add_test(tc, strcspn_basic_test);
  tcase_add_test(tc, strcspn_any_sim);
  tcase_add_test(tc, strcspn_upper_letter);
  tcase_add_test(tc, strcspn_lower_letter);
  tcase_add_test(tc, strcspn_not_uniq_sim);
  suite_add_tcase(s, tc);
  return s;
}
