CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
MATH_FLAG = -lm
EXECUTABLE = test
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	GFLAGS = -lcheck_pic -lsubunit $(MATH_FLAG)
endif

ifeq ($(UNAME), Darwin)
	GFLAGS = -lcheck
endif

SRC_SUPPORT = $(wildcard support-functions/*.c)
SRC_BASIC = $(wildcard basic-functions/*.c)
SRC_COMPARISON = $(wildcard comparison-functions/*.c)
SRC_ARITHMETIC = $(wildcard arithmetic-functions/*.c)
SRC_ANOTHER = $(wildcard another-functions/*.c)
SRC_TESTS = $(wildcard tests/*.c)

OBJ_SUPPORT = $(patsubst %.c, %.o, $(SRC_SUPPORT))
OBJ_BASIC = $(patsubst %.c, %.o, $(SRC_BASIC))
OBJ_COMPARISON = $(patsubst %.c, %.o, $(SRC_COMPARISON))
OBJ_ARITHMETIC = $(patsubst %.c, %.o, $(SRC_ARITHMETIC))
OBJ_ANOTHER = $(patsubst %.c, %.o, $(SRC_ANOTHER))
OBJ_TESTS = $(patsubst %.c, %.o, $(SRC_TESTS))

all: clean s21_matrix.a

clean:
	@rm -rf s21_matrix.a
	@rm -rf $(EXECUTABLE)
	@rm -rf ./report
	@rm -rf *.gcno *.gcda *.gcov *.info
	@rm -rf $(OBJ_SUPPORT) $(OBJ_BASIC) $(OBJ_COMPARISON) $(OBJ_ARITHMETIC) $(OBJ_ANOTHER) $(OBJ_TESTS)

test: clean s21_matrix.a $(OBJ_TESTS)
	@$(CC) $(CFLAGS) $(OBJ_TESTS) $(GFLAGS) s21_matrix.a -o $(EXECUTABLE)
	@./$(EXECUTABLE)

s21_matrix.a: clean $(OBJ_SUPPORT) $(OBJ_BASIC) $(OBJ_COMPARISON) $(OBJ_ARITHMETIC) $(OBJ_ANOTHER)
	ar rc s21_matrix.a $(OBJ_SUPPORT) $(OBJ_BASIC) $(OBJ_COMPARISON) $(OBJ_ARITHMETIC) $(OBJ_ANOTHER)
	ranlib s21_matrix.a

gcov_report: clean s21_matrix.a
	@$(CC) $(CFLAGS) $(SRC_SUPPORT) $(SRC_BASIC) $(SRC_COMPARISON) $(SRC_ARITHMETIC) $(SRC_ANOTHER) $(SRC_TESTS) $(GFLAGS) s21_matrix.a -o $(EXECUTABLE) --coverage
	@./$(EXECUTABLE)
	@rm -rf test-test* test-eq* test-is* equal_size* is_* test_*
	@lcov -t "tests" -o tests.info -c -d .
	genhtml -o report tests.info
	open report/index.html

style: clean
	@cp ../materials/linters/.clang-format ./
	clang-format -n ./*/*.c
	clang-format -n *.h ./tests/*.h
	@rm .clang-format

clang-format: clean
	@cp ../materials/linters/.clang-format ./
	clang-format -i ./*/*.c
	clang-format -i *.h ./tests/*.h
	@rm .clang-format

.PHONY: all clean test s21_matrix.a gcov_report style clang-format
