# Makefile for the test of LinkStack

OBJS = test.o ListStack.o
CC = gcc
GFLAGS = -Wall -O -g

LinkStack:$(OBJS)
	$(CC) $(OBJS) -o LinkStack

ListStack.o:ListStack.c liststack.h
	$(CC) $(GFLAGS) -c ListStack.c -o ListStack.o

test.o:test.c liststack.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o LinkStack
