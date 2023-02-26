CC= gcc 
CFLAGS= -Wall -Wextra -Werror -std=c11
PROJECT= *.c
TEST= tests/*.c
TEST_FLAGS = -lcheck

OS := $(shell uname -s)

ifeq ($(OS), Darwin)
    TEST_FLAGS = -lcheck
else
	TEST_FLAGS = -lcheck -lpthread -pthread -lrt -lm -lsubunit
endif

all: gcov_report

s21_math.a:
	$(CC) $(CFLAGS) $(PROJECT) -c 
	ar rcs s21_math.a *.o
	rm -rf *.o

test:
	$(CC) --coverage $(TEST_FLAGS) $(CFLAGS) $(TEST) $(PROJECT) -o test

gcov_report:	s21_math.a	test
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o coverage test.info
	open coverage/index.html
	rm -rf *.gcda *.gcno *.a

clean:
	rm -rf test
	rm -rf *.a *.out *.o coverage *.gc* *.info
	rm -rf *.gcda *.gcno

rebuild:	clean	all

valgrind_test: clean
	cd ../materials/build/Valgrind/ && bash run.sh

leak:
	CK_FORK=no leaks --atExit -- ./test

linter:
	cp ../materials/linters/.clang-format ../src
	clang-format -i *.c *.h tests/*.c 
	clang-format -n *.c *.h tests/*.c
	rm -rf .clang-format
