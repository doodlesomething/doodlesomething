#Makefile for BiThrTree

OBJS = test.o BiThrTree.o
CC = gcc
GFLAGS = -Wall -g

BiThrTree:$(OBJS)
	$(CC) $(OBJS) -o BiThrTree

BiThrTree.o:BiThrTree.c bithrtree.h 
	$(CC) $(GFLAGS) -c BiThrTree.c -o BiThrTree.o

test.o:test.c bithrtree.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o BiThrTree

