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
}
