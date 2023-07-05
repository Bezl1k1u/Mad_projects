#include "test_matrix.h"

START_TEST(determinant_1) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 7;
  A.matrix[1][2] = 8;
  A.matrix[2][0] = 6;
  A.matrix[2][1] = 9;
  A.matrix[2][2] = 1;
  double result = 0;
  int state = s21_determinant(&A, &result);
  ck_assert_int_eq(state, OK);
  ck_assert_double_eq_tol(result, 51.0, 1e-06);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t *A = NULL;
  double result = 0;
  int state = s21_determinant(A, &result);
  ck_assert_int_eq(state, INVALID_MATRIX);
  s21_remove_matrix(A);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 1, &A);
  double result = 0;
  int state = s21_determinant(&A, &result);
  ck_assert_int_eq(state, ERROR_CALC);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_4) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 3;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  double result = 0;
  int state = s21_determinant(&A, &result);
  ck_assert_int_eq(state, OK);
  ck_assert_double_eq_tol(result, -1.0, 1e-06);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_5) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = -1438.4378;
  double result = 0;
  int state = s21_determinant(&A, &result);
  ck_assert_int_eq(state, OK);
  ck_assert_double_eq_tol(result, -1438.4378, 1e-06);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_determinant() {
  Suite *s = suite_create(color_text("S21_DETERMINANT"));
  TCase *tc = tcase_create("determinant");

  tcase_add_test(tc, determinant_1);
  tcase_add_test(tc, determinant_2);
  tcase_add_test(tc, determinant_3);
  tcase_add_test(tc, determinant_4);
  tcase_add_test(tc, determinant_5);

  suite_add_tcase(s, tc);
  return s;
}
