# description:	Makefile for CriticalPath
# author:	doodlesomething@163.com
# date:10-14-2014


OBJS = CriticalPath.o test.o
CC = gcc
GFLAGS = -Wall -g


CriticalPath:$(OBJS)
	$(CC) $(OBJS) -o CriticalPath

CriticalPath.o:CriticalPath.c criticalpath.h
	$(CC) $(GFLAGS) -c CriticalPath.c -o CriticalPath.o

test.o:test.c criticalpath.h
	$(CC) $(GFLAGS) -c test.c -o test.o


clean:
	rm -rf *.o CriticalPath
