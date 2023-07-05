#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int state = OK;
  if (isCorrect(A) && result) {
    if (A->rows == 1 && A->columns == 1)
      result = A;
    else {
      s21_create_matrix(A->columns, A->rows, result);
      for (int i = 0; i < A->columns; i++) {
        for (int j = 0; j < A->rows; j++) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    }
  } else
    state = INVALID_MATRIX;
  return state;
}
