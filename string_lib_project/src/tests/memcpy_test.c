#include "tests.h"

START_TEST(memcpy_1) {
  s21_size_t n1 = 3;
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(memcpy(b1, str_1_2, n1), s21_memcpy(b11, str_1_2, n1));
}
END_TEST

START_TEST(memcpy_2) {
  s21_size_t n2 = 5;
  char b2[1024] = "";
  char b22[1024] = "";
  char str_2_2[1024] = "THE OF \0BEST!!";
  ck_assert_pstr_eq(memcpy(b2, str_2_2, n2), s21_memcpy(b22, str_2_2, n2));
}
END_TEST

START_TEST(memcpy_3) {
  s21_size_t n3 = 4;
  char b3[1024] = "777 ";
  char b33[1024] = "777 ";
  char str_3_2[1024] = "LUGANO!";
  ck_assert_pstr_eq(memcpy(b3, str_3_2, n3), s21_memcpy(b33, str_3_2, n3));
}
END_TEST

START_TEST(memcpy_4) {
  s21_size_t n4 = 4;
  char b4[1024] = "LUGANO! 777 ";
  char b44[1024] = "LUGANO! 777 ";
  ck_assert_pstr_eq(memcpy(b4, b4 + 7, n4), s21_memcpy(b44, b44 + 7, n4));
}
END_TEST

START_TEST(memcpy_hate_test) {
  char src[] = "i hate memcmp";
  s21_size_t kByte = 12;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_zero_test_string) {
  char src[] = "aboba";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_any_empty) {
  char src[] = "";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_zero_test_string_with_register) {
  char src[] = "I hate memcmp";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_zero_test_num) {
  char src[] = "123";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_one_byte_string) {
  char src[] = "aboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_one_byte_string_with_register) {
  char src[] = "Zboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_one_byte_num) {
  char src[] = "09";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_basic_long_string) {
  char src[] = "abobasdafoijasdofjas asdopij";
  s21_size_t kByte = 28;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_long_string_with_register) {
  char src[] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
  s21_size_t kByte = 36;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_long_string_with_register_and_num) {
  char src[] = "aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 53;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_long_string_with_register_and_num_and_simbol) {
  char src[] =
      "()()(((())):!,....aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 71;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

Suite *suite_memcpy(void) {
  Suite *s = suite_create("suite_memcpy");
  TCase *tc = tcase_create("memcpy_tc");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memcpy_hate_test);
  tcase_add_test(tc, memcpy_zero_test_string);
  tcase_add_test(tc, memcpy_any_empty);
  tcase_add_test(tc, memcpy_zero_test_string_with_register);
  tcase_add_test(tc, memcpy_zero_test_num);
  tcase_add_test(tc, memcpy_one_byte_string);
  tcase_add_test(tc, memcpy_one_byte_string_with_register);
  tcase_add_test(tc, memcpy_one_byte_num);
  tcase_add_test(tc, memcpy_basic_long_string);
  tcase_add_test(tc, memcpy_long_string_with_register);
  tcase_add_test(tc, memcpy_long_string_with_register_and_num);
  tcase_add_test(tc, memcpy_long_string_with_register_and_num_and_simbol);

  suite_add_tcase(s, tc);

  return s;
}