#include <stdio.h>
#include "slinklist.h"


int main(int argc,char *argv[]) {
	SLinkList L;
	int i,pre_e,next_e,elem;
	InitList(L);

	for(i=1;i < 6;i++)
		ListInsert(L,1,i);

	ListTraverse(L,visit);
	printf("\n");
	GetElem(L,5,&elem);
	printf("Length:%d, GetElem:%d ,LocateElem:%d \n",ListLength(L),elem,LocateElem(L,5));
	PreElem(L,2,&pre_e);
	NextElem(L,2,&next_e);
	printf("PreElem:%d, NextElem:%d ,IsEempty:%d\n",pre_e,next_e,ListEmpty(L));
	ListDelete(L,2);
	printf("Length:%d\n",ListLength(L));
	ListTraverse(L,visit);
	printf("\n");
	
	/*
	上述测试用例结果：

	5	4	3	2	1	
	Length:5, GetElem:1 ,LocateElem:1 
	PreElem:3, NextElem:1 ,IsEempty:0
	Length:4
	5	3	2	1	
	*/
}

