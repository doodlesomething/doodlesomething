# description:Makefile for InsertSort
# author:doodlesomething@163.com
# date:10-22-2014

OBJS = test.o InsertSort.o
CC = gcc
GFLAGS = -Wall -g

InsertSort:$(OBJS)
	$(CC) $(OBJS) -o InsertSort

InsertSort.o:InsertSort.c sort.h
	$(CC) $(GFLAGS) -c InsertSort.c -o InsertSort.o

test.o:test.c sort.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o InsertSort
