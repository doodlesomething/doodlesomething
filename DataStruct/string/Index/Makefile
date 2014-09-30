# Makefile to complie the BookIndex

OBJS = test.o BookIndex.o LinkList.o HString.o
CC = gcc
GFLAGS = -Wall -g

BookIndex:$(OBJS)
	$(CC) $(OBJS) -o BookIndex

LinkList.o:LinkList.c linklist.h
	$(CC) $(GFLAGS) -c LinkList.c -o LinkList.o

HString.o:HString.c hstring.h
	$(CC) $(GFLAGS) -c HString.c -o HString.o

BookIndex.o:BookIndex.c linklist.h hstring.h bookindex.h
	$(CC) $(GFLAGS) -c BookIndex.c -o BookIndex.o

test.o:test.c bookindex.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o BookIndex
	
