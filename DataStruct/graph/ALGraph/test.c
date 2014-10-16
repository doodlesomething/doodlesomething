/*---------------------------------------------------------------------------
	* file:test.c -->test file for ALGraph
	* date:10-10-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:邻接表实现图的基本操作
----------------------------------------------------------------------------*/

#include <stdio.h>
#include "algraph.h"


void main() {
	ALGraph G;

	//创建图
	CreateGraph(&G);

	BFSTraverse(G,PrintElem);
	printf("\n");
	DFSTraverse(G,PrintElem);
	printf("\n");


	/*
	测试用例结果：
	please enter the kind of graph(DG:0,DN:1,UDG:2,UDN:3):2
	please the vexnum and arcnum:8,8
	please enter the value of each vertex:1,2,3,4,5,6,7,8
	please enter the heads and tails:
	1,2
	1,3
	2,4
	2,5
	3,6
	3,7
	4,8
	5,8
	12345678
	12485367

	*/
}
