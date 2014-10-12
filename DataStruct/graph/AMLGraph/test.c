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

	DFSTraverse(G,PrintElem);
	printf("\n");
}
