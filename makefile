all: sieve.o driver.o
		gcc sieve.o driver.o -lm

sieve.o: sieve.c sieve.h
		gcc -c sieve.c

driver.o: driver.c sieve.h
		gcc -c driver.c

run:
		./a.out $(args)
