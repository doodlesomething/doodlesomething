# Makefile for OLGraph 
# date:10-11-2014
# author:doodlesomething@163.com

OBJS = test.o OLGraph.o
CC = gcc
GFLAGS = -g

OLGraph:$(OBJS)
	$(CC) $(OBJS) -o OLGraph

OLGraph.o:OLGraph.c olgraph.h
	$(CC) $(GFLAGS) -c OLGraph.c -o OLGraph.o

test.o:test.c olgraph.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o OLGraph
