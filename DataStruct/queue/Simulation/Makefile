#  Makefile for Simulation

OBJS = Simulation.o LinkList.o LinkQueue.o
CC = gcc
GFLAGS = -Wall -O -g

Simulation:$(OBJS)
	$(CC) $(OBJS) -o Simulation

Simulation.o:Simulation.c simulation.h linklist.h linkqueue.h
	$(CC) $(GFLAGS) -c Simulation.c -o Simulation.o

LinkList.o:LinkList.c linklist.h
	$(CC) $(GFLAGS) -c LinkList.c -o LinkList.o

LinkQueue.o:LinkQueue.c linkqueue.h
	$(CC) $(GFLAGS) -c LinkQueue.c -o LinkQueu.o

clean:
	rm -rf *.o Simulation
