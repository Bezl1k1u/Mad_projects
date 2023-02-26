CC=gcc -Wall -Wextra -Werror

all:
	$(MAKE) s21_grep

rebuild:
	$(MAKE) clean
	$(MAKE) all

s21_grep:
	$(CC) s21_grep.c -o s21_grep

test:
	sh testGrep.sh

clean:
	rm -rf s21_grep

check:
	clang-format -i *.c *.h