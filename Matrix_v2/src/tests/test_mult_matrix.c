#include "test_matrix.h"

START_TEST(mult_matrix_1) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  double value_1 = 10;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = value_1;
    }
  }
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &B);
  double value_2 = 10;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      B.matrix[i][j] = value_2;
    }
  }
  matrix_t result = {NULL, 0, 0};
  int state = s21_mult_matrix(&A, &B, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], 300.0, TEST_EPS);
    }
  }
  ck_assert_int_eq(state, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 1, &A);
  double value_1 = 10;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
      A.matrix[i][j] = value_1;
    }
  }
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 2, &B);
  double value_2 = 10;
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 2; j++) {
      B.matrix[i][j] = value_2;
    }
  }
  matrix_t result = {NULL, 0, 0};
  int state = s21_mult_matrix(&A, &B, &result);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], 100.0, TEST_EPS);
    }
  }
  ck_assert_int_eq(state, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 1, &A);
  double value_1 = 10;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
      A.matrix[i][j] = value_1;
    }
  }
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 2, &B);
  double value_2 = 10;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      B.matrix[i][j] = value_2;
    }
  }
  matrix_t result = {NULL, 0, 0};
  int state = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(state, ERROR_CALC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_4) {
  matrix_t *A = NULL;
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  int state = s21_mult_matrix(A, &B, &result);
  ck_assert_int_eq(state, INVALID_MATRIX);
}
END_TEST

Suite *test_mult_matrix() {
  Suite *s = suite_create(color_text("S21_MULT_MATRIX"));
  TCase *tc = tcase_create("mult_matrix");

  tcase_add_test(tc, mult_matrix_1);
  tcase_add_test(tc, mult_matrix_2);
  tcase_add_test(tc, mult_matrix_3);
  tcase_add_test(tc, mult_matrix_4);

  suite_add_tcase(s, tc);
  return s;
}
