expr: expr.o
	gcc -o expr expr.c -Wall -Werror
	./expr
.PHONY: expr
