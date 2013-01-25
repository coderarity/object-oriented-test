build:
	gcc -g main.c animal.c dog.c -o test

memcheck:
	valgrind --leak-check=full ./test

clean:
	rm test
