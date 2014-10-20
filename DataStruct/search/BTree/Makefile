# description:Makefile for BTree
# author:doodlesomething@163.com
# date:10-20-2014

OBJS = test.o BTree.o
CC = gcc
GFLAGS = -Wall -g

BTree:$(OBJS)
	$(CC) $(OBJS) -o BTree

BTree.o:BTree.c btree.h
	$(CC) $(GFLAGS) -c BTree.c -o BTree.o

test.o:test.c btree.h
	$(CC) $(GFLAGS) -c test.c -o test.o


clean:
	rm -rf *.o BTree
