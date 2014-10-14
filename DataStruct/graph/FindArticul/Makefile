# description:Makefile for FindArticul
# date:10-14-2014
# author:doodlesomething@163.com


OBJS = test.o FindArticul.o
CC = gcc
GFLAGS = -Wall -g


FindArticul:$(OBJS)
	$(CC) $(OBJS) -o FindArticul

FindArticul.o:FindArticul.c	findarticul.h
	$(CC) $(GFLAGS) -c FindArticul.c -o FindArticul.o

test.o:test.c findarticul.h
	$(CC) $(GFLAGS) -c test.c -o test.o


clean:	
	rm -rf *.o FindArticul
