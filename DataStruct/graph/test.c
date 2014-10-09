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
	CreateUDG(&G);

	//深度优先遍历图
	DFSTraverse(G,PrintElem);
	
	//返回v的值,返回v的第一个邻接顶点。。
	printf("GetVex:%d,FirstAdjVex:%d,NextAdjVex:%d\n",GetVex(G,1),GetVex(G,FirstAdjVex(G,1)),GetVex(G,NextAdjVex(G,1,3)));

	//赋值
	PutVex(&G,1,9);
	DFSTraverse(G,PrintElem);

	printf("\n");
}
