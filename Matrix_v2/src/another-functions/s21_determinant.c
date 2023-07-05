#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int state = OK;
  *result = 0;
  if (isCorrect(A) && result) {
    if (A->rows == A->columns) {
      int size = A->rows;
      if (A->rows == 1)
        *result = A->matrix[0][0];
      else if (A->rows == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[0][1] * A->matrix[1][0];
      } else {
        int degree = 1;
        double resultTmp = 0;
        matrix_t tmp = {NULL, 0, 0};
        for (int j = 0; j < size; j++) {
          getOffsetMatrix(A, 0, j, &tmp);
          s21_determinant(&tmp, &resultTmp);
          resultTmp *= degree * A->matrix[0][j];
          degree = -degree;
          *result += resultTmp;
          s21_remove_matrix(&tmp);
        }
      }
    } else
      state = ERROR_CALC;
  } else
    state = INVALID_MATRIX;
  return state;
}
