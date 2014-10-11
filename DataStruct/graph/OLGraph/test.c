/*----------------------------------------------------------------------------
	* file: test.c --> test file for OLGraph
	* date:10-11-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:十字链表实现图的基本操作
	* more:十字链表仅仅能表述有向图/网
-----------------------------------------------------------------------------*/


#include <stdio.h>
#include "olgraph.h"

void main() {
	OLGraph G;
	//创建图
	CreateGraph(&G);

	//深度优先遍历
	DFSTraverse(G,PrintElem);
	printf("\n");
}
