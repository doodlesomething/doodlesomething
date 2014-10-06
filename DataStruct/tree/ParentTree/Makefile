# Make file for ParentTree

OBJS = test.o LinkQueue.o ParentTree.o
CC = gcc
GFLAGS = -Wall -g

ParentTree:$(OBJS)
	$(CC) $(OBJS) -o ParentTree

LinkQueue.o:LinkQueue.c linkqueue.h
	$(CC) $(GFLAGS) -c LinkQueue.c -o LinkQueue.o

ParentTree.o:ParentTree.c parenttree.h
	$(CC) $(GFLAGS) -c ParentTree.c -o ParentTree.o

test.o:test.c parenttree.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o ParentTree
