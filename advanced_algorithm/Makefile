default: ex7

all: ex1 ex2 ex3 ex5 ex7 ex10


uniform: uniform.c
	gcc -c uniform.c -o uniform.o -Wall
	ar rs libuniform.a uniform.o
%:uniform
%: %.c
	$(CC) -o $@ $^ -L. -luniform -lm -Wall
ex7: ex7_sherwood.cpp uniform
	g++ -g -o $@ ex7_sherwood.cpp -L. -luniform -lm -Wall

ex10: ex10_PrintPrimes.cpp uniform
	g++ -g -o $@ ex10_PrintPrimes.cpp -L. -luniform -lm -Wall

.PHONY:clean
clean:
	rm *.o ex6 ex1 ex2 ex3 ex5
