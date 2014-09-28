# Makefile for the KMP

OBJS = kmp.o
CC = gcc
GFLAGS = -Wall -g

kmp:$(OBJS)
	$(CC) $(OBJS) -o kmp

kmp.o:kmp.c hstring.h
	$(CC) $(GFLAGS) -c kmp.c -o kmp.o

clean:
	rm -rf *.o kmp
