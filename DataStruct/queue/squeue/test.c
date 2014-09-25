/*---------------------------------------------------------------------
	* file:test.c  --> test file to test the queue.c
	* date:24-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:数组实现队列的基本操作
-----------------------------------------------------------------------*/


#include <stdio.h>
#include "squeue.h"

int main(int argc,char *argv[]) {
	Queue Q;
	int i;

	InitQueue(&Q);
	for(i = 0; i <10; i++)
		//这里是为了检测循环数组是否起作用，这里的QUEUE_SIZE为3
		if(!EnQueue(&Q,i))
			printf("test\n");

	printf("%d\n",Q.rear);
	
	QueueTraverse(Q,visit);
	printf("\n");

	printf("Length:%d,IsFull:%d \n",QueueLength(Q),QueueFull(Q));
	

}
