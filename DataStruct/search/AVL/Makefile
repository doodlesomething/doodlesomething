# Makefile for AVL
# date:10-19-2014
# author:doodlesomething@163.com

OBJS = test.o AVL.o
CC = gcc
GFLAGS = -Wall -g

AVL:$(OBJS)
	$(CC) $(OBJS) -o AVL

AVL.o:AVL.c avl.h
	$(CC) $(GFLAGS) -c AVL.c -o AVL.o

test.o:test.c avl.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o AVL
