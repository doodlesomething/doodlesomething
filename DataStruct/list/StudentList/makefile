OBJS = test.o student.o
CC = gcc
CFLAGS = -Wall -O -g

Student:$(OBJS)
	$(CC) $(OBJS) -o StudentList

Student.o:student.c studentlist.h
	$(CC) $(GFLSGS) -c student.c -o student.o

test.o:test.c studentlist.h
	$(CC) $(GFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o StudentList
