# Makefile for ALGraph
# date:10-10-2014
# author:doodlesomething@163.com

OBJS = ALGraph.o LinkQueue.o test.o
CC = gcc
GFLAGS = -g

ALGraph:$(OBJS)
	$(CC) $(OBJS) -o ALGraph

ALGraph.o:ALGraph.c algraph.h
	$(CC) $(GFLAGS) -c ALGraph.c -o ALGraph.o

LinkQueue.o:LinkQueue.c linkqueue.h
	$(CC) $(GFLAGS) -c LinkQueue.c -o LinkQueue.o

test.o:test.c algraph.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o ALGraph
