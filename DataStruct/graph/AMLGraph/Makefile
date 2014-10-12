# Makefile for AMLGraph
# date:10-12-2014
# author:doodlesomething@163.com

OBJS = test.o AMLGraph.o
CC = gcc
GFLAGS = -g

AMLGraph:$(OBJS)
	$(CC) $(OBJS) -o AMLGraph

AMLGraph.o:AMLGraph.c amlgraph.h
	$(CC) $(GFLAGS) -c AMLGraph.c -o AMLGraph.o

test.o:test.c amlgraph.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o AMLGraph
