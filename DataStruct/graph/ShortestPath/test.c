/*---------------------------------------------------------------------------------
	* file:test.c
	* date:10-15-2014
	* author:doodlesomething@163.com
	* version:1.1
	* description:最短路径
------------------------------------------------------------------------------------*/


#include <stdio.h>
#include "shortestpath.h"


int main() {
	MGaph G;

	//创建图
	CreateGraph(&G);

	//深度优先搜索遍历图
	DFSTraverse(G,PrintElem);


	//生成最小路径
	ShortestPath(G,0,PathMatrix,D);

	//输出最短路径
	


	return 0;
}
