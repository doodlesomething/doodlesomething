/*--------------------------------------------------------------------------------
	* file:test.c
	* date:10-29-2014
	* author:doodlesomething@163.com
	* version:1.o
	* description:平衡二叉树的建立查找
	* more:包括建立(插入)/遍历/查找	--->这东西真不是人看的
--------------------------------------------------------------------------------*/


#include <stdio.h>
#include "avl.h"

int main() {
	BiTree T,p;
	int i,n;
	int arr[100];
	Status taller;

	//确定输入个数
	printf("please enter the N:");
	scanf("%d",&n);

	//输入节点元素值
	printf("please enter %d numbers:",n);
	for(i = 0; i < n ; i++)
		scanf("%d,",&arr[i]);

	//初始化和插入
	InitTree(&T);
	for(i = 0; i < n ; i++) 
		InsertAVL(&T,arr[i],&taller);

	//中序遍历
	printf("中序遍历:");
	InOrderTraverse(T,PrintElem);
	printf("\n");

	//查找
	printf("please enter the number you want to looking for:");
	scanf("%d",&n);
	p = SearchTree(T,n);
	if(p)
		printf("There is the number %d\n",n);
	else
		printf("Nothing such as %d\n",n);


	return 0;


	/*
	please enter the N:5
	please enter 5 numbers:13,37,90,53,24
	中序遍历:13	24	37	53	90	
	please enter the number you want to looking for:53
	There is the number 53
	*/
}


