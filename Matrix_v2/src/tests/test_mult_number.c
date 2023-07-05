#include "test_matrix.h"

START_TEST(mult_number_1) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  double value_1 = 10;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = value_1;
    }
  }
  matrix_t result = {NULL, 0, 0};
  int state = s21_mult_number(&A, 10, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], 100.0, TEST_EPS);
    }
  }
  ck_assert_int_eq(state, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_2) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 1, &A);
  double value_1 = 1438.993;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
      A.matrix[i][j] = value_1;
    }
  }
  matrix_t result = {NULL, 0, 0};
  int state = s21_mult_number(&A, 4, &result);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], (1438.993 * 4), TEST_EPS);
    }
  }
  ck_assert_int_eq(state, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_3) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(10, 14, &A);
  double value_1 = 0.000001;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 14; j++) {
      A.matrix[i][j] = value_1;
    }
  }
  matrix_t result = {NULL, 0, 0};
  double tmp = 17;
  int state = s21_mult_number(&A, tmp, &result);
  ck_assert_int_eq(state, OK);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], (value_1 * tmp), TEST_EPS);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_4) {
  matrix_t *A = NULL;
  matrix_t result = {NULL, 0, 0};
  int state = s21_mult_number(A, 34.3, &result);
  ck_assert_int_eq(state, INVALID_MATRIX);
}
END_TEST

Suite *test_mult_number() {
  Suite *s = suite_create(color_text("S21_MULT_NUMBER"));
  TCase *tc = tcase_create("mult_number");

  tcase_add_test(tc, mult_number_1);
  tcase_add_test(tc, mult_number_2);
  tcase_add_test(tc, mult_number_3);
  tcase_add_test(tc, mult_number_4);

  suite_add_tcase(s, tc);
  return s;
}
