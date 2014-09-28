# Makefile for HString complier

OBJS = test.o HString.o
CC = gcc
GFLAGS = -Wall -g

HString:$(OBJS)
	$(CC) $(OBJS) -o HString

HString.o:HString.c hstring.h
	$(CC) $(GFLAGS) -c HString.c -o HString.o

test.o:test.c hstring.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o HString
