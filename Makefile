build:
	gcc -g main.c animal.c dog.c -o test

memcheck:
	valgrind ./test

clean:
	rm test
