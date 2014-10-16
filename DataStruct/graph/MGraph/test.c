/*---------------------------------------------------------------------------------
	* file:MGraph.c
	* date:10-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:图的数组表示及基本操作
------------------------------------------------------------------------------------*/


#include <stdio.h>
#include "mgraph.h"


int main(int argc,char *argv[]) {
	MGraph G;
	//建图
	CreateGraph(&G);

	//深度优先遍历图
	DFSTraverse(G,PrintElem);
	printf("\n");
	BFSTraverse(G,PrintElem);
	printf("\n");


	/*
	测试用例结果：
	please enter the kind of the graph(DG:0,DN:1,UDG:2,UDN:3):2
	please enter vexnum, arcnum is info(1 or 0):8,8,0
	the value of each vertex:1,2,3,4,5,6,7,8
	please 8 heads and 8 tails:
	1,2
	1,3
	2,4
	2,5
	3,6
	3,7
	4,8 
	5,8
	12485367
	12345678

	*/
}
