#include "test_matrix.h"

START_TEST(sum_matrix_1) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &B);
  matrix_t result = {NULL, 0, 0};
  int state = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(state, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_2) {
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
  int state = s21_sum_matrix(&A, &B, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], (value_1 + value_2),
                              TEST_EPS);
    }
  }
  ck_assert_int_eq(state, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_3) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  double value_1 = -1e30;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = value_1;
    }
  }
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &B);
  double value_2 = -1e7;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      B.matrix[i][j] = value_2;
    }
  }
  matrix_t result = {NULL, 0, 0};
  int state = s21_sum_matrix(&A, &B, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], (value_1 + value_2),
                              TEST_EPS);
    }
  }
  ck_assert_int_eq(state, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_4) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(17, 9, &A);
  double value_1 = 0.000001;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = value_1;
    }
  }
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(17, 9, &B);
  double value_2 = 0.000001;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      B.matrix[i][j] = value_2;
    }
  }
  matrix_t result = {NULL, 0, 0};
  int state = s21_sum_matrix(&A, &B, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], (value_1 + value_2),
                              TEST_EPS);
    }
  }
  ck_assert_int_eq(state, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_5) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(17, 91, &A);
  double value_1 = 0.000001;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = value_1;
    }
  }
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(17, 9, &B);
  double value_2 = 0.000001;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      B.matrix[i][j] = value_2;
    }
  }
  matrix_t result = {NULL, 0, 0};
  int state = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(state, ERROR_CALC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_6) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(17, 91, &A);
  double value_1 = 0.000001;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = value_1;
    }
  }
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  int state = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(state, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_sum_matrix() {
  Suite *s = suite_create(color_text("S21_SUM_MATRIX"));
  TCase *tc = tcase_create("sum_matrix");

  tcase_add_test(tc, sum_matrix_1);
  tcase_add_test(tc, sum_matrix_2);
  tcase_add_test(tc, sum_matrix_3);
  tcase_add_test(tc, sum_matrix_4);
  tcase_add_test(tc, sum_matrix_5);
  tcase_add_test(tc, sum_matrix_6);

  suite_add_tcase(s, tc);
  return s;
}
