OBJS = LinkList.o test.o
CC = gcc
GFLAGS = -Wall -O -g

LinkList:$(OBJS)
	$(CC) $(OBJS) -o LinkList

LinkList.o:LinkList.c linklist.h
	$(CC) $(GFLAGS) -c LinkList.c -o LinkList.o

test.o:test.c linklist.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o LinkList
