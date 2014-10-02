# Makefile fot BiTree

OBJS = test.o BiTree.o
CC = gcc
GFLAGS = -Wall -g

BiTree:$(OBJS)
	$(CC) $(OBJS) -o BiTree

BiTree.o:BiTree.c bitree.h
	$(CC) $(GFLAGS) -c BiTree.c -o BiTree.o

test.o:test.c bitree.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o BiTree
