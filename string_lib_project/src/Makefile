CC= gcc -std=c11
CFLAGS= -Wall -Wextra -Werror -fsanitize=leak -g
PROJECT= *.c
TEST= tests/*.c
TEST_FLAGS = -lcheck

OS := $(shell uname -s)

ifeq ($(OS), Darwin)
    TEST_FLAGS = -lcheck
else
	TEST_FLAGS = -lcheck -lpthread -pthread -lrt -lm -lsubunit
endif

all: clean	gcov_report

s21_string.a:
	$(CC) $(CFLAGS) $(PROJECT) -c 
	ar rcs s21_string.a *.o

test:
	$(CC) --coverage $(TEST_FLAGS) $(CFLAGS) $(TEST) $(PROJECT) -o test

gcov_report:	s21_string.a	test
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o coverage test.info
	open coverage/index.html

clean:
	rm -rf test
	rm -rf *.a *.out *.o coverage *.gc* s21_string.a *.info
	rm -rf *.gcda *.gcno

rebuild:	clean	all

leak:
	CK_FORK=no leaks --atExit -- ./test

linter:
	cp ../materials/linters/.clang-format ..
	clang-format -i *.c *.h tests/*.c tests/*.h
	clang-format -n *.c *.h tests/*.c tests/*.h
	rm -rf ../.clang-format
