CC=gcc -Wall -Wextra -Werror

all:
	$(MAKE) s21_cat

rebuild:
	$(MAKE) clean
	$(MAKE) all

s21_cat:
	$(CC) s21_cat.c -o s21_cat

test:
	sh test_func_cat.sh
	sh test_leak_cat.sh

clean:
	rm -rf s21_cat

check:
	clang-format -i *.c *.h
