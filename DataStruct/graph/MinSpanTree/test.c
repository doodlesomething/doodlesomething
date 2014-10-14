/*---------------------------------------------------------------------------------------------
                * file:MinSpanTree.c
		* date:10-13-2014
		* author:doodlesomething@163.com
		* version:1.0
		* description:最小生成树的Prim算法和Kruskal算法
----------------------------------------------------------------------------------------------*/


#include <stdio.h>
#include "mgraph.h"

void main() {
	MGraph G;
	
	//创建图
	CreateGraph(&G);
	//深度优先遍历
	DFSTraverse(G,PrintElem);
	printf("\n");

	//构造最小生成树
	MinSpanTree_Prim(G);
	


	/*
	测试用例：
	please enter the kind of the graph:3
	please enter vexnum , arcnum and is info(1 or 0):6,10,0
	the value of each vertex:1,2,3,4,5,6 
	please heads,tails and weights:
	1,2,6
	1,3,1
	1,4,5
	2,3,5
	2,5,3
	3,4,5
	3,5,6
	3,6,4
	4,6,2
	5,6,6
	
	深度优先遍历:
	1	2	3	4	6	5
	最小生成树输出:
	0,2
	2,5
	5,3
	2,1
	1,4

	*/

}
