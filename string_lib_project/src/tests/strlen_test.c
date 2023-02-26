#include "tests.h"

START_TEST(strlen_1) {
  char *str_1 = "KTO\0";
  ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
}
END_TEST

START_TEST(strlen_2) {
  char *str_2 = "KTO\0ZDES??";
  ck_assert_int_eq(strlen(str_2), s21_strlen(str_2));
}
END_TEST

START_TEST(strlen_3) {
  char *str_3 = "\0";
  ck_assert_int_eq(strlen(str_3), s21_strlen(str_3));
}
END_TEST

START_TEST(strlen_empty) {
  char src[] = "";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_abosal) {
  char src[] = "abosal";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_num) {
  char src[] = "987623456124678";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_string) {
  char src[] =
      "987623456124678qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_abosal_no_dal) {
  char src[] = "abosal\0no_dal";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_dai_mne_pen) {
  char src[] = "dai_mne_pen(321321)...123...123";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_Floppy_disk) {
  char src[] = "Floppy_disk";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_Russky_kot_Shlepa) {
  char src[] = "Russky_kot_Shlepa";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_kot_Vasily) {
  char src[] = "kot Vasily";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_floppa) {
  char src[] = "floppa";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *s = suite_create("suite_strlen");
  TCase *tc = tcase_create("strlen_tc");
  tcase_add_test(tc, strlen_1);
  tcase_add_test(tc, strlen_2);
  tcase_add_test(tc, strlen_3);
  tcase_add_test(tc, strlen_empty);
  tcase_add_test(tc, strlen_abosal);
  tcase_add_test(tc, strlen_num);
  tcase_add_test(tc, strlen_string);
  tcase_add_test(tc, strlen_abosal_no_dal);
  tcase_add_test(tc, strlen_dai_mne_pen);
  tcase_add_test(tc, strlen_Floppy_disk);
  tcase_add_test(tc, strlen_floppa);
  tcase_add_test(tc, strlen_kot_Vasily);
  tcase_add_test(tc, strlen_Russky_kot_Shlepa);
  suite_add_tcase(s, tc);
  return s;
}
