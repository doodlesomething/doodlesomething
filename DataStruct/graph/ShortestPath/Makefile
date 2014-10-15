# file: Makefile for ShortestPath
# date:10-15-2014
# author:doodlesoemthing@163.com


OBJS = test.o ShortestPath.o
CC = gcc
GFLAGS = -Wall -g

ShortestPath:$(OBJS)
	$(CC) $(OBJS) -o ShortestPath

ShortestPath.o:ShortestPath.c	shortestpath.h
	$(CC) $(GFLAGS) -c ShortestPath.c -o ShortestPath.o
	
test.o:test.c shortestpath.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o ShortestPath
