/*---------------------------------------------------------------------------
 * file:ALGraph.c
 * date:10-14-2014
 * author:doodlesomething@163.com
 * version:1.0
 * description:邻接表实现图的基本操作及求图的关节点
 ----------------------------------------------------------------------------*/


#include <stdio.h>
#include "findarticul.h"

int main() {
	int i;
	ALGraph G;
	
	//创建图
	CreateGraph(&G);

	//深度优先遍历图
	DFSTraverse(G,PrintElem);
	
	printf("\n");

	//求关节点
	FindArticul(G);

	printf("i	G.vertices[i].data	visited[i]	low[i]	Order_Low\n");
	for(i = 0; i < G.vexnum ; i++) 
		printf("%d	%d	%d	%d	%d\n",i,G.vertices[i].data,visited[i],low[i],Order_Low[i]);

	return 0;


	/*
	please enter the kind of graph(DG:0,DN:1,UDG:2,UDN:3):2
	please the vexnum and arcnum:13,17
	please enter the value of each vertex:1,2,3,4,5,6,7,8,9,10,11,12,13
	please enter the heads and tails:
	1,2
	1,3
	1,6
	1,12
	2,3
	2,4
	2,7
	2,8
	2,13
	4,5
	7,8
	7,9
	7,11
	8,11
	10,12
	10,13
	12,13

	>>（可以看到2输出了两次，这是因为删除2会将图分割成三颗树）
	1	2	3	4	5	7	8	11	9	13	10	12	6	
	6,7
	1,2
	3,4
	1,2
	0,1
	i	G.vertices[i].data	visited[i]	low[i]	Order_Low
	0	1	1	1	0
	1	2	5	1	9
	2	3	12	1	8
	3	4	10	5	7
	4	5	11	10	6
	5	6	13	1	12
	6	7	8	5	3
	7	8	6	5	5
	8	9	9	8	2
	9	10	4	2	1
	10	11	7	5	4
	11	12	2	1	11
	12	13	3	1	10

	*/
}
