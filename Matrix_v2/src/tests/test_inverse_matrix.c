#include "test_matrix.h"

START_TEST(inverse_matrix_1) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  matrix_t result = {NULL, 0, 0};
  int state = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(state, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 1, 1e-06);
  ck_assert_double_eq_tol(result.matrix[0][1], -1, 1e-06);
  ck_assert_double_eq_tol(result.matrix[0][2], 1, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][0], -38, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][1], 41, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][2], -34, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][0], 27, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][1], -29, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][2], 24, 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t *A = NULL;
  matrix_t result = {NULL, 0, 0};
  int state = s21_inverse_matrix(A, &result);
  ck_assert_int_eq(state, INVALID_MATRIX);
  s21_remove_matrix(A);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 1, &A);
  matrix_t result = {NULL, 0, 0};
  int state = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(state, ERROR_CALC);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 4;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 1;
  matrix_t result = {NULL, 0, 0};
  int state = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(state, ERROR_CALC);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_inverse_matrix() {
  Suite *s = suite_create(color_text("S21_INVERSE_MATRIX"));
  TCase *tc = tcase_create("inverse_matrix");

  tcase_add_test(tc, inverse_matrix_1);
  tcase_add_test(tc, inverse_matrix_2);
  tcase_add_test(tc, inverse_matrix_3);
  tcase_add_test(tc, inverse_matrix_4);

  suite_add_tcase(s, tc);
  return s;
}
