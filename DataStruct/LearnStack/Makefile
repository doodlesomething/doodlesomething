# Makefile for the test of LearnStack

OBJS = test.o ListStack.o
CC = gcc
GFLAGS = -Wall -O -g

LearnStack:$(OBJS)
	$(CC) $(OBJS) -o LearnStack

ListStack.o:ListStack.c liststack.h
	$(CC) $(GFLAGS) -c ListStack.c -o ListStack.o

test.o:test.c liststack.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o LearnStack
