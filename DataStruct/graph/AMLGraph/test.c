/*------------------------------------------------------------------------------
	* file:test.c --->test file for AMLGraph
	* date:10-12-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:邻接多重表实现无向图/网的基本操作
	* more:在实现感觉和十字表有相似之处
--------------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include "amlgraph.h"


void main() {
	AMLGraph G;

	CreateGraph(&G);

	DFSTraverse(G);
	printf("\n");

	/*	
	测试用例结果：
	please enter the kind of graph:0
	please enter vexnum and arcnum:8,8
	please enter each value of graph:1,2,3,4,5,6,7,8
	please enter heads and tails:
	1,2
	1,3
	2,4
	2,5
	3,6
	3,7
	4,8
	5,8
	13762584

	*/
}
