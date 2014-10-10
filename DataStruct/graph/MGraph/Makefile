# Makefile for MGraph 
# author:doodlesomething@163.com
# date:10-9-2014

OBJS = test.o MGraph.o
CC = gcc
GFLAGS = -g

MGraph:$(OBJS)
	$(CC) $(OBJS) -o MGraph

MGraph.o:MGraph.c mgraph.h
	$(CC) $(GFLAGS) -c MGraph.c -o MGraph.o

test.o:test.c mgraph.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o MGraph
