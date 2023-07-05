#include "test_matrix.h"

START_TEST(calc_complements_1) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  matrix_t result = {NULL, 0, 0};
  int state = s21_calc_complements(&A, &result);
  ck_assert_int_eq(state, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 0, 1e-06);
  ck_assert_double_eq_tol(result.matrix[0][1], 10, 1e-06);
  ck_assert_double_eq_tol(result.matrix[0][2], -20, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][0], 4, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][1], -14, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][2], 8, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][0], -8, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][1], -2, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][2], 4, 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_2) {
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
  int state = s21_calc_complements(&A, &result);
  ck_assert_int_eq(state, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -1, 1e-06);
  ck_assert_double_eq_tol(result.matrix[0][1], 38, 1e-06);
  ck_assert_double_eq_tol(result.matrix[0][2], -27, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][0], 1, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][1], -41, 1e-06);
  ck_assert_double_eq_tol(result.matrix[1][2], 29, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][0], -1, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][1], 34, 1e-06);
  ck_assert_double_eq_tol(result.matrix[2][2], -24, 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t *A = NULL;
  matrix_t result = {NULL, 0, 0};
  int state = s21_calc_complements(A, &result);
  ck_assert_int_eq(state, INVALID_MATRIX);
  s21_remove_matrix(A);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 1, &A);
  matrix_t result = {NULL, 0, 0};
  int state = s21_calc_complements(&A, &result);
  ck_assert_int_eq(state, ERROR_CALC);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_calc_complements() {
  Suite *s = suite_create(color_text("S21_CALC_COMPLEMENTS"));
  TCase *tc = tcase_create("calc_complements");

  tcase_add_test(tc, calc_complements_1);
  tcase_add_test(tc, calc_complements_2);
  tcase_add_test(tc, calc_complements_3);
  tcase_add_test(tc, calc_complements_4);

  suite_add_tcase(s, tc);
  return s;
}
