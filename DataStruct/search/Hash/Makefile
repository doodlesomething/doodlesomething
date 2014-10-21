# Makefile for Hash
# date:10-21-2014
# author:doodlesomething@163.com


OBJS = test.o HashTable.o
CC = gcc
GFLAGS = -Wall -g

HashTable:$(OBJS)
	$(CC) $(OBJS) -o HashTable

HashTable.o:HashTable.o hashtable.h
	$(CC) $(GFLAGS) -c HashTable.c -o HashTable.o

test.o:test.c hashtable.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o HashTable
