#include <check.h>

#include "../s21_matrix.h"

#define color_start(start_end) "\033[0;41m" #start_end "\033[0m"
#define color_text(test_name) "\033[0;44m" #test_name "\033[0m"

#define TEST_EPS (1e-07)

// BASIC
Suite *test_create_matrix();

// COMPARISON
Suite *test_eq_matrix();

// ARITHMETIC
Suite *test_sum_matrix();
Suite *test_sub_matrix();
Suite *test_mult_matrix();
Suite *test_mult_number();

// ANOTHER
Suite *test_transpose_matrix();
Suite *test_determinant();
Suite *test_calc_complements();
Suite *test_inverse_matrix();
