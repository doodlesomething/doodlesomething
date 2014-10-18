# Makefile for StaticSearch
# author:doodlesomething@163.com
# date:10-18-2014

OBJS = test.o StaticSearch.o
CC = gcc
GFLAGS = -Wall -g

StaticSearch:$(OBJS)
	$(CC) $(OBJS) -o StaticSearch

StaticSearch.o:StaticSearch.c staticsearch.h
	$(CC) $(GFLAGS) -c StaticSearch.c -o StaticSearch.o

test.o:test.c staticsearch.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o StaticSearch
