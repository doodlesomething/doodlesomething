# Makefile for MinSpanTree
# author:doodlesomething@163.com
# date:10-14-2014


OBJS = test.o MGraph.o
CC = gcc
GFLAGS = -g

MinSpanTree:$(OBJS)
	$(CC) $(OBJS) -o MinSpanTree

MGraph.o:MGraph.c mgraph.h
	$(CC) $(GFLAGS) -c MGraph.c -o MGraph.o

test.o:test.c mgraph.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o MinSpanTree
