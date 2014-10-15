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

	//创建图
	CreateGraph(&G);

	//深度优先遍历
	printf("深度优先遍历:");
	DFSTraverse(G,PrintElem);
	printf("\n");

	CriticalPath(G);
	printf("\n");
	


	return 0;


	/*
	please enter the kind of graph(DG:0,DN:1,UDG:2,UDN:3):1
	please the vexnum and arcnum:6,8
	please enter the value of each vertex:1,2,3,4,5,6
	please enter the heads,tails and weights:
	1,2,3
	1,3,2
	2,4,2
	2,5,3
	3,4,4
	3,6,2
	4,6,2
	5,6,1
	深度优先遍历:124653
	125346
	j	k	dut	ee	el	tag:
	0	2	2	0	0	*:
	0	1	3	0	1	 :
	1	4	3	3	4	 :
	1	3	2	3	4	 :
	2	5	2	2	6	 :
	2	3	4	2	2	*:
	3	5	2	6	6	*:
	4	5	1	6	7	 :
	输出关键路径:
	1 --> 3,3 --> 4,4 --> 6,

	*/
}
