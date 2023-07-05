#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int state = OK;
  if (!isCorrect(A) || !isCorrect(B) || !result)
    state = INVALID_MATRIX;
  else if (A->columns != B->rows)
    state = ERROR_CALC;
  else {
    int n = A->rows;
    int m = B->rows;
    int k = B->columns;
    s21_create_matrix(n, k, result);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        for (int k = 0; k < m; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return state;
}
