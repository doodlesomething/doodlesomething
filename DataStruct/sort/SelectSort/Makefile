# description:Makefile for SelectSort
# date:10-22-2014
# author:doodlesomething@163.com

OBJS = test.o SelectSort.o
CC = gcc
GFLAGS = -Wall -g


SelectSort:$(OBJS)
	$(CC) $(OBJS) -o SelectSort


SelectSort.o:SelectSort.c sort.h
	$(CC) $(GFLAGS) -c SelectSort.c -o SelectSort.o


test.o:test.c sort.h
	$(CC) $(GFLAGS) -c test.c -o test.o


clean:
	rm -rf *.o SelectSort
