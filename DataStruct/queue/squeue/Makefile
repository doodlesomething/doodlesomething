# Makefile to test the squeue

OBJS = test.o squeue.o
CC = gcc
GFLAGS = -Wall -O -g

Squeue:$(OBJS)
	$(CC) $(OBJS) -o Squeue

squeue.o:squeue.c squeue.h
	$(CC) $(GFLAGS) -c squeue.c -o squeue.o

test.o:test.c squeue.h
	$(CC) $(GFLAGS) -c test.c -o test.o


clean:
	rm -rf *.o Squeue
