OBJS = Polynominal.o test.o
CC = gcc
GFLAGS = -Wall -O -g

Poly:$(OBJS)
	$(CC) $(OBJS) -o  Poly

Polynominal.o:Polynominal.c poly.h
	$(CC) $(GFLAGS) -c Polynominal.c -o Polynominal.o

test.o:test.c poly.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o Poly
