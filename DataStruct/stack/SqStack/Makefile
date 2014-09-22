# Makefile for test the opertion of stack

OBJS = test.o SqStack.o
CC = gcc
GFLAGS = -Wall -O -g

SqStack:$(OBJS)
	$(CC) $(OBJS) -o SqStack

SqStack.o:SqStack.c sqstack.h
	$(CC) $(GFLAGS) -c SqStack.c -o SqStack.o

test.o:test.c sqstack.h
	$(CC) $(GFLAGS) -c test.c -o test.o


clean:
	rm -rf *o SqStack
