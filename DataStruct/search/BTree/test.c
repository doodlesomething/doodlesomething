/*---------------------------------------------------------------------------------
	* FileName:test.c
	* date:10-20-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:B树插入和查找
------------------------------------------------------------------------------------*/


#include <stdio.h>
#include "btree.h"


int main() {
	
	int arr[100];
	int i,n;
	BTree T;
	Result r;
	
	//确定输入个数
	printf("please the n:");
	scanf("%d",&n);
	
	//确定各个关键词
	printf("please enter %d numbers:",n);
	for(i = 0; i < n ; i++)
		scanf("%d,",&arr[i]);
	
	InitBTree(&T);

	//插入各个关键词
	for(i = 0; i < n; i++)  {
		r = SearchBTree(T,arr[i]);
		printf("%d %d\n ",r.tag,r.i);
		if(!r.tag)
			InsertBTree(&T,arr[i],r.pt,r.i);
	}

	//遍历输出
	TraverseTree(T,PrintElem);
	printf("\n");

	
	//查找
	printf("please enter the number you want to looking for:");
	scanf("%d",&n);
	r = SearchBTree(T,n);
	if(r.tag)
		printf("There is the number\n");
	else
		printf("Nothing was found\n");

	return 0;

}
