# Makefile to the EvaluateExpression

OBJS = Expression.o ListStack.o SqStack.o
CC  = gcc
GFLAGS = -Wall -O -g

Expression:$(OBJS)
	$(CC) $(OBJS) -o Expression

Expression.o:Expression.c liststack.h sqstack.h
	$(CC) $(GFLAGS) -c Expression.c -o Expression.o

ListStack.o:ListStack.c liststack.h
	$(CC) $(GFLAGS) -c ListStack.c -o ListStack.o

SqStack.o:SqStack.c sqstack.h
	$(CC) $(GFLAGS) -c SqStack.c -o SqStack.o

clean:
	rm -rf *.o Expression
