OBJS = DLinkList.o test.o
CC = gcc
GFLAGS = -Wall -O -g

DLinkList:$(OBJS)
	$(CC) $(OBJS) -o DLinkList

DLinkList.o:DLinkList.c dlinklist.h
	$(CC) $(GFLAGS) -c DLinkList.c -o DLinkList.o

test.o:test.c dlinklist.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o DLinkList
