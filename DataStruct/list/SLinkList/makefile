OBJS = SLinkList.o test.o
CC = gcc
GFLAGS = -Wall -O -g

SLinkList:$(OBJS)
	$(CC) $(OBJS) -o SLinkList

SLinkList.o:SLinkList.c slinklist.h
	$(CC) $(GFLAGS) -c SLinkList.c -o SLinkList.o

test.o:test.c slinklist.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o SLinkList
