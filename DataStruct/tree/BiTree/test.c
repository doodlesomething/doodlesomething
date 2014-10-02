/*------------------------------------------------------------------------
	* file:test.c -->test file fot BiTree.c
	* date:1-10-2014
	* author:doodlesomething@63.com
	* version:1.0
	* description:二叉树的基本操作
--------------------------------------------------------------------------*/


#include <stdio.h>
#include "bitree.h"

int main(int argc,char *argv[])  {
	BiTree T;

	CreateBiTree(&T);
	PreOrderTraverse(T,PrintElem);
	printf("\n");
	InOrderTraverse(T,PrintElem);
	printf("\n");
	PostOrderTraverse(T,PrintElem);
	printf("\n");
	PrintAsTree(T,0);
	printf("\n");

	return 0;


	/*
	测试用例结果:
	AB#D##C##
	>>
	ABDC
	BDAC
	DBCA
	*/
}
