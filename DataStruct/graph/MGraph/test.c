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

	//删除顶点和相关的弧
	//DeleVex(&G,1);
	InsertVex(&G,9);
	InsertVex(&G,0);
	InsertArc(&G,9,0);
	InsertArc(&G,6,0);
	//深度优先遍历图
	DFSTraverse(G,PrintElem);

	printf("\n");
}
