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
	MGraph G;
	int i,j,k;

	//创建图
	CreateGraph(&G);

	printf("深度优先遍历:");
	//深度优先搜索遍历图
	DFSTraverse(G,PrintElem);
	printf("\n");

	//生成最小路径
	ShortestPath_DIJ(G,0,PathMatrix,D);

	//最短路径数组
	printf("最短路径数组\n");
	for(i = 0; i < G.vexnum ; i++) {
		for(j = 0; j < G.vexnum ; j++) 
			printf("%2d",PathMatrix[i][j]);
		printf("\n");
	}

	printf("\n");
	//输出最短路径
	printf("%d 到各个顶点的最短路径:",G.vexs[0]);
	for(i = 0; i < G.vexnum ; i++) 
		printf("%d --> %d:%d  ",G.vexs[0],G.vexs[i],D[i]);

	printf("\n");

	ShortestPath_FLOYD(G,PathMatrix,DM);
	
	for(i = 0; i < G.vexnum ; i++) {
		//j = i+1是为了避免重复打印
		for(j = i + 1; j < G.vexnum; j++) {
			printf("%d -> %d : %d\t",i,j,DM[i][j]);

			k = PathMatrix[i][j];
			printf("path:%d",i);

			while(k != j) {
				printf(" -> %d",k);
				k = PathMatrix[k][j];
			}

			printf(" -> %d\n",j);
		}

		printf("\n");
	}
	

	
	return 0;



	/*
	测试用例结果：
	please enter the kind of the graph(DG:0,DN:1,UDG:2,UDN:3):1
	please enter vexnum , arcnum and is info(1 or 0):6,8,0
	the value of each vertex:0,1,2,3,4,5
	please 6 heads and 8 tails and weights:
	0,5,100
	0,4,30
	0,2,10
	1,2,5
	2,3,50
	3,5,10
	4,3,20
	4,5,60
	深度优先遍历:023541
	最短路径数组
	 0 0 0 0 0 0
	 0 0 0 0 0 0
	 1 0 1 0 0 0
	 1 0 0 1 1 0
	 1 0 0 0 1 0
	 1 0 0 1 1 1

	0 到各个顶点的最短路径:0 --> 0:0  0 --> 1:65535  0 --> 2:10  0 --> 3:50  0 --> 4:30  0 --> 5:60  

	*/
		

	/*
	弗洛伊德算法测试：
	please enter the kind of the graph(DG:0,DN:1,UDG:2,UDN:3):3
	please enter vexnum , arcnum and is info(1 or 0):3,3,0
	the value of each vertex:0,1,2,
	please heads,tails and weights:
	0,1,2
	0,2,1
	1,2,5
	深度优先遍历:012
	最短路径数组
	 0 0 0
	 1 1 0
	 1 0 1

	0 到各个顶点的最短路径:0 --> 0:0  0 --> 1:2  0 --> 2:1  
	0 -> 1 : 2	path:0 -> 1
	0 -> 2 : 1	path:0 -> 2

	1 -> 2 : 3	path:1 -> 0 -> 2

	*/

}
