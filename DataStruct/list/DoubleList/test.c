#include <stdio.h>
#include "dlinklist.h"

int main(int argc,char *argv[]) {
	LinkList La;
	int del_e,i,pre_e,next_e;
	InitList(&La);
	for(i = 1;i < 6;i++)
		ListInsert(La,1,i);
	ListTraverse(La,visit);
	printf("\n");
	PriorElem(La,3,&pre_e);
	NextElem(La,3,&next_e);
	printf("pre_e:%d, next_e:%d\n",pre_e,next_e);
	printf("ListLength:%d\n",ListLength(La));
	ListDelete(La,5,&del_e);
	ListTraverse(La,visit);
	printf("\n");
	printf("%d\n",del_e);
	return 0;
	
	/*
	测试用例结果:	
	5	4	3	2	1	
	pre_e:4, next_e:2
	ListLength:5
	5	4	3	2	
	1
	*/
}

