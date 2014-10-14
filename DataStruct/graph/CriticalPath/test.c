/*---------------------------------------------------------------------------
 * file:test.c
 * date:10-14-2014
 * author:doodlesomething@163.com
 * version:1.1
 * description:邻接表实现图的基本操作并实现图的拓扑排序和关键路径算法
 ----------------------------------------------------------------------------*/


#include <stdio.h>
#include "criticalpath.h"




int main() {
	
	ALGraph G;
	LinkStack T;

	//创建图
	CreateGraph(&G);

	//深度优先遍历
	DFSTraverse(G,PrintElem);
	printf("\n");

	TopoLogicalSort(G,&T);


	return 0;
}
