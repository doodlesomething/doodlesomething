# Makefile to the SString

OBJS = test.o SString.o
CC = gcc
GFLAGS = -Wall -g

SString:$(OBJS)
	$(CC) $(OBJS) -o SString

SString.o:SString.c str.h
	$(CC) $(GFLAGS) -c SString.c -o SString.o

test.o:test.c str.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm *.o SString
