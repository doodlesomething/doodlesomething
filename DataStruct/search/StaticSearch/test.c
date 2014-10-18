/*--------------------------------------------------------------------------------------
	* file:test.c
	* date:10-18-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:静态查找表
	* more:包括顺序表的查找/折半查找/静态树表查找
----------------------------------------------------------------------------------------*/


#include <stdio.h>
#include "staticsearch.h"

int main() {
	BiTree T;
	SSTable S;

	ElemType Data[] = { {4,5}, {1,1}, {2,1}, {3,2},  {5,3}, {8,3}, {6,4}, {7,4} , {9,5}};

	//创建顺序表
	Create_Seq(&S,9,Data);
	//遍历输出
	Traverse(S,PrintElem);
	printf("\n");
	
	//查找
	printf("顺序查找:%d\n",Search_Seq(S,7));
	Ascend(&S);
	Traverse(S,PrintElem);
	printf("\n");
	printf("折半查找:%d\n",Search_Bin(S,4));

	//建立判定树
	CreateSOSTree(&T,S);
	//前序遍历
	PreOrderTraverse(T,PrintElem);
	printf("\n");

	//查找
	if(Search_SOSTree(&T,3))
		printf("静态树表查找:%d\n",T->data.weight);
	//前序遍历
	PreOrderTraverse(T,PrintElem);
	printf("\n");
	

	return 0;]

	/*
	4	1	2	3	5	8	6	7	9	
	顺序查找:8
	1	2	3	4	5	6	7	8	9	
	折半查找:4
	6	4	2	1	3	5	7	8	9	
	静态树表查找:2
	3	
	*/
}
