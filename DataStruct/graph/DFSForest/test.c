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
	BiTree T;
	//建图
	CreateGraph(&G);

	//深度优先遍历图
	DFSTraverse(G,PrintElem);
	printf("\n");
	DFSForest(G,&T);
	PreOrderTraverse(T,PrintElem);
	printf("\n");


	/*
	测试用例：
	please enter the kind of the graph:2
	please enter vexnum, arcnum is info(1 or 0):13,13,0
	the value of each vertex:0,1,2,3,4,5,6,7,8,9,10,11,12
	please 13 heads and 13 tails:
	0,1
	0,2
	0,5
	0,11
	1,12
	3,4
	6,7
	6,8
	6,10
	7,10
	9,11
	9,12
	11,12
	0	1	12	9	11	2	5	3	4	6	7	10	8	
	0	1	12	9	11	2	5	3	4	6	7	10	8	
	*/
}
