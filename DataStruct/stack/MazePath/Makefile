# Makefile for test the MazePath

OBJS = test.o MazePath.o
CC = gcc
GFLAGS =-g

MazePath:$(OBJS)
	$(CC) $(OBJS) -o MazePath

MazePath.o:MazePath.c mazepath.h
	$(CC) $(GFLAGS) -c MazePath.c -o MazePath.o

test.o:test.c mazepath.h
	$(CC) $(GFLAGS) -c test.c -o test.o


clean:
	rm -rf *o MazePath
