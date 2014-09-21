#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"


int main(int argc,char *argv[]) {
	LinkList La,Lb,Lc;
	int i;

	InitList(&La);
	InitList(&Lb);
	InitList(&Lc);

	for(i = 1; i < 7; i++ )
		ListInsert(La,1,i);
	ListTraverse(La,visit);
	printf("\n");
	SplitList(La,Lb,Lc);
	ListTraverse(Lb,visit);
	ListTraverse(Lc,visit);
	printf("%d\n",IsIncreasingList(La));
	ListReverse(La);
	printf("%d\n",IsIncreasingList(La));
	DeleteInRange(La,1,4);
	ListInsert(La,2,4);
	ListInsert(La,4,1);
	ListTraverse(La,visit);
	DistinctList(La);
	DeleteMin(La);
	ListTraverse(La,visit);
	ListReverse1(La);
	ListTraverse(La,visit);
	printf("\n");


	/*
	输出结果：
	6	5	4	3	2	1	

	6	4	2	
	5	3	1	
	0
	1
	1	4	4	1	5	6	
	4	5	6	
	6	5	4	
	*/
}
