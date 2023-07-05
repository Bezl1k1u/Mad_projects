#include "../s21_matrix.h"

void getOffsetMatrix(matrix_t* A, int row, int col, matrix_t* tmp) {
  int rowShift = 0, colShift = 0;
  int size = A->rows;
  s21_create_matrix(size - 1, size - 1, tmp);
  for (int i = 0; i < size - 1; i++) {
    if (i == row) rowShift = 1;
    colShift = 0;
    for (int j = 0; j < size - 1; j++) {
      if (j == col) colShift = 1;
      tmp->matrix[i][j] = A->matrix[i + rowShift][j + colShift];
    }
  }
}
