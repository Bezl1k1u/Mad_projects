#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

enum RESULT {
  OK,
  INVALID_MATRIX,
  ERROR_CALC,
};

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// BASIC
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

// COMPARISON
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// ARITHMETIC
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

// ANOTHER FUNCTIONS
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// SUPPORT
enum BOOLEAN { FALSE, TRUE };

int isCorrect(matrix_t *A);
int equalSize(matrix_t *A, matrix_t *B);
void getOffsetMatrix(matrix_t *A, int row, int col, matrix_t *tmp);
