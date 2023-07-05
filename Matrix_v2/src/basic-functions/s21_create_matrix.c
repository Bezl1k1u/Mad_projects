#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int state = OK;
  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(rows * sizeof(double *));
    if (!(result->matrix))
      state = INVALID_MATRIX;
    else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)malloc(columns * sizeof(double));
        if (!(result->matrix)) {
          state = INVALID_MATRIX;
          break;
        }
      }
      for (int j = 0; j < rows; j++) {
        for (int k = 0; k < columns; k++) {
          result->matrix[j][k] = 0;
        }
      }
    }
  } else
    state = INVALID_MATRIX;
  return state;
}
