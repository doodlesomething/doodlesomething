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
	for(i = 0; i <5; i++)
		EnQueue(&Q,i);
	
	QueueTraverse(Q,visit);
	printf("\n");

	printf("Length:%d,IsFull:%d \n",QueueLength(Q),QueueFull(Q));
	
	/*测试用例结果：
	0 1 2 3 4 5
	Length:5 ,IsFull:0
	*/

}
