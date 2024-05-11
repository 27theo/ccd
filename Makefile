# Basic makefile

all:
	@clang -Wall ccd.c -o ccd

gcc:
	@gcc -Wall ccd.c -o ccd

clean:
	@rm ccd
