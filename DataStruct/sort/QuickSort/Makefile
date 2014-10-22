# description:Makefile for QuickSort
# date:10-22-2014
# author:doodlesomething@163.com

OBJS = test.o QuickSort.o
CC = gcc
GFLAGS = -Wall -g

QuickSort:$(OBJS)
	$(CC) $(OBJS) -o QuickSort

QuickSort.o:QuickSort.c sort.h
	$(CC) $(GFLAGS) -c QuickSort.c -o QuickSort.o

test.o:test.c sort.h
	$(CC) $(GFLAGS) -c test.c -o test.o


clean:
	rm -rf *.o QuickSort
