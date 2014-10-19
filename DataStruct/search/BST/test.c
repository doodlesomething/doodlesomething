/*-----------------------------------------------------------------------------
	* file:BST.c
	* date:10-19-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:二叉查找树
	* more:包括初始化/动态删除/插入/查找/遍历
-------------------------------------------------------------------------------*/


#include <stdio.h>
#include "bst.h"


int main() {
	BiTree T,p;
	int i,n;
	int arr[100];
	
	//准备工作
	printf("Enter n:");
	scanf("%d",&n);
	printf("please enter %d number spearte by ,:",n);
	for(i = 0; i < n; i++)
		scanf("%d,",&arr[i]);

	//初始化
	InitDSTable(&T);
	//插入
	for(i = 0; i < n; i++)
		InsertBST(&T,arr[i]);
	
	printf("中序遍历结果:");
	//中序遍历
	InOrderTraverse(T,PrintElem);
	printf("\n");
	
	//查找
	printf("please enter the number you want to look for:");
	scanf("%d",&n);
	p = SearchBST(T,n);
	if(p)
		printf("There is the num::%d\n",n);
	else 
		printf("Nothing There such as %d\n",n);
	
	//Delete
	printf("please enter the number you want to delete:");
	scanf("%d",&n);
	if(p)
		//删除节点
		DeleBST(&T,n);
	else
		printf("Nothing There such as %d\n",n);
	

	//中序遍历
	InOrderTraverse(T,PrintElem);
	printf("\n");

	return 0;

	/*
	测试：
	
	root@test:~/code/DataStruct/search/BST# ./BST 
	Enter n:5
	please enter 5 number spearte by ,:45,24,53,12,90
	中序遍历结果:12	24	45	53	90	
	please enter the number you want to look for:24
	There is the num::24
	please enter the number you want to delete:90
	12	24	45	53	
	root@test:~/code/DataStruct/search/BST# ./BST 
	Enter n:5
	please enter 5 number spearte by ,:45,24,53,12,90
	中序遍历结果:12	24	45	53	90	
	please enter the number you want to look for:1
	Nothing There such as 1
	please enter the number you want to delete:1
	Nothing There such as 1
	12	24	45	53	90	
	*/
}



