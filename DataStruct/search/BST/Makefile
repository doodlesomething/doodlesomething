# Makefile for BST
# date:10-19-2014
# author:doodlesomething@163.com

OBJS = test.o BST.o
CC = gcc
GFLAGS = -Wall -g

BST:$(OBJS)
	$(CC) $(OBJS) -o BST

BST.o:BST.c bst.h
	$(CC) $(GFLAGS) -c BST.c -o BST.o

test.o:test.c bst.h
	$(CC) $(GFLAGS) -c test.c -o test.o


clean:
	rm -rf *.o BST
