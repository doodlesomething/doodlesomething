# Makefile fot BiTree

OBJS = test.o BiTree.o LinkQueue.o
CC = gcc
GFLAGS = -Wall -g

BiTree:$(OBJS)
	$(CC) $(OBJS) -o BiTree

BiTree.o:BiTree.c bitree.h linkqueue.h
	$(CC) $(GFLAGS) -c BiTree.c -o BiTree.o

LinkQueu.o:LinkQueue.c linkqueue.h
	$(CC) $(GFLAGS) -c LinkQueue.c -o LinkQueue.o

test.o:test.c bitree.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o BiTree
