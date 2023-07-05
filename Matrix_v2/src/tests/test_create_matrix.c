#include "test_matrix.h"

START_TEST(create_matrix_1) {
  matrix_t matrix = {NULL, 0, 0};
  int rows = 3;
  int columns = 3;
  int result = s21_create_matrix(rows, columns, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(create_matrix_2) {
  matrix_t matrix = {NULL, 0, 0};
  int rows = 1000;
  int columns = 100;
  int result = s21_create_matrix(rows, columns, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(create_matrix_3) {
  matrix_t matrix = {NULL, 0, 0};
  int rows = -1000;
  int columns = 100;
  int result = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(result, INVALID_MATRIX);
  s21_remove_matrix(&matrix);
}
END_TEST

// START_TEST(create_matrix_4) {
//     matrix_t matrix = {NULL, 0, 0};
//     int rows = 1e9;
//     int columns = 1;
//     int result = s21_create_matrix(rows, columns, &matrix);
//     s21_remove_matrix(&matrix);
//     ck_assert_int_eq(result, INVALID_MATRIX);
// }
// END_TEST

Suite *test_create_matrix() {
  Suite *s = suite_create(color_text("S21_CREATE_MATRIX"));
  TCase *tc = tcase_create("create_matrix");

  tcase_add_test(tc, create_matrix_1);
  tcase_add_test(tc, create_matrix_2);
  tcase_add_test(tc, create_matrix_3);
  //   tcase_add_test(tc, create_matrix_4);

  suite_add_tcase(s, tc);
  return s;
}
