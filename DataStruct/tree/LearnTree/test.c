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
	BiTree T,T1;

	//创建二叉树
	CreateBiTree(&T);

	//前序遍历二叉树
	PreOrderTraverse(T,PrintElem);
	printf("\n");
	printf("%d\n",NodeNumKth(T,1));

	//PreTraverse(T,PrintElem);
	//printf("\n");
	//InTraverse(T,PrintElem);
	//printf("\n");
	//PostTraverse(T,PrintElem);
	//Exchange(T);

	//前序遍历二叉树
	//PreOrderTraverse(T,PrintElem);
	printf("\n");

	//测试叶子节点数目等函数
	//printf("LevesNum:%d,NodeNum:%d,Locate:%d\n",LevesNum(T),NodeNum(T),Locate(T,'A'));

	//CreateBiTree(&T1);
	//PreOrderTraverse(T1,PrintElem);
	//printf("\n");

	//比较两颗树是否相等
	//printf("Equal:%d\n",EqualBiTree(T,T1));

	return 0;


	/*
	测试用例结果:
	AB#C##D##
	>>
	ABCD
	ADBC
	LevesNum:2,NodeNum:4,Locate:1
	>>
	AB#C##D##
	ABCD
	Equal:0

	*/
}
