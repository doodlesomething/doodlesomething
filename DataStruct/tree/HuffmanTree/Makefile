#Makefile for HuffmanTree 
#date:10-6-2014
#author:doodlesomething@163.com



OBJS = test.o HuffmanTree.o
CC = gcc
GFLAGS = -Wall -g

HuffmanTree:$(OBJS)
	$(CC) $(OBJS) -o HuffmanTree

HuffmanTree.o:HuffmanTree.c huffmantree.h
	$(CC) $(GFLAGS) -c HuffmanTree.c -o HuffmanTree.o

test.o:test.c huffmantree.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o HuffmanTree
