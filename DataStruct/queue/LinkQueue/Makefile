# Makefile to test the LinkQueue

OBJS = test.o LinkQueue.o
CC = gcc
GFLAGS = -Wall -O -g

LinkQueue:$(OBJS)
	$(CC) $(OBJS) -o LinkQueue

LinkQueue.o:LinkQueue.c linkqueue.h
	$(CC) $(GFLAGS) -c LinkQueue.c -o LinkQueue.o

test.o:test.c linkqueue.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o LinkQueue
