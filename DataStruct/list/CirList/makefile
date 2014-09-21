OBJS = CirLinkList.o test.o
CC = gcc
GFLAGS = -Wall -O -g

CirLinkList:$(OBJS)
	$(CC) $(OBJS) -o CirLinkList

CirLinkList.o:CirLinkList.c cirlinklist.h
	$(CC) $(GFLAGS) -c CirLinkList.c -o CirLinkList.o

test.o:test.c cirlinklist.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o CirLinkList
