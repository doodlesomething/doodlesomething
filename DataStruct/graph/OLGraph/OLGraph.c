/*----------------------------------------------------------------------------
	* file: OLGraph.c
	* date:10-11-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:十字链表实现图的基本操作
	* more:十字链表仅仅能表述有向图/网
-----------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include "olgraph.h"

/*
* @description:创建图
*/
Status CreateGraph(OLGraph *G) {
	int i,j,w,k;
	VertexType tv,hv;
	ArcBox *p;

	//确定图的种类
	printf("please enter the kind of graph(DG:0,DN:1):");
	scanf("%d",&(*G).kind);

	//确定顶点数和弧数
	printf("please enter the vexnum and arcnum:");
	scanf("%d,%d",&(*G).vexnum,&(*G).arcnum);
	
	//确定各个顶点
	printf("please enter each value of graph:");
	for(i = 0; i < (*G).vexnum ; i++) { 
		scanf("%d,",&(*G).xlist[i].data);
		(*G).xlist[i].firstin = NULL;
		(*G).xlist[i].firstout = NULL;
	}

	//建立各个顶点间关系，即建立入/出表
	if((*G).kind == DN)
		printf("please enter the heads,tails and weights:\n");
	else 
		printf("please enter the heads and tails:\n");

	for(k = 0;k < (*G).arcnum ; k++) {
		if((*G).kind == DN)	
			scanf("%d,%d,%d",&tv,&hv,&w);
		else
			scanf("%d,%d",&tv,&hv);
		
		i = LocateVex(*G,tv);	//弧尾
		j = LocateVex(*G,hv);	//弧头
	
		p = (ArcBox *) malloc(sizeof(struct ArcBox));

		if(!p)
			exit(OVERFLOW);
		
		p->tailvex = i;	//弧的起点 -->入表
		p->headvex = j;	//弧的终点 -->出表
		p->tlink = (*G).xlist[j].firstin;	//指向下一个起点相同的弧节点
		p->hlink = (*G).xlist[i].firstout;	//指向下一个终点相同的弧节点

		//注意不管是出还是入表都是在表头插入的,<v1,v2>中表示v1有出,v2有入
		(*G).xlist[i].firstout = (*G).xlist[j].firstin = p;

		if((*G).kind == DN)
			p->weight = w;
	}
	

	return OK;
}


/*
* @description:定位顶点值v的位置，无则返回-1
*/
int LocateVex(OLGraph G,VertexType v) {
	int i;
	
	for(i = 0; i < G.vexnum ; i++)
		if( G.xlist[i].data == v)
			return i;
	
	return -1;
}


/*
* @description:深度优先遍历图
*/
Status DFSTraverse(OLGraph G,Status (*Visit) (VertexType)) {
	int i;
	
	//重新初始化访问标记数组
	for(i = 0; i < G.vexnum; i++)
		visited[i] = FALSE;

	//保证每个顶点都能被访问到
	for(i = 0; i < G.vexnum ; i++) 
		if(!visited[i])
			DFS(G,i,Visit);

	return OK;
}


/*
* @description:深度优先递归遍历邻接点
*/
void DFS(OLGraph G,int i,Status (*Visit) (VertexType)) {
	ArcBox *p;

	Visit(G.xlist[i].data);
	visited[i] = TRUE;

	p = G.xlist[i].firstout;	//出表第一个节点指针

	while(p && visited[p->headvex])	//如果出表中当前节点已经被访问则往下找终点相同的点
		p = p->tlink;

	if(p && !visited[p->headvex])
		DFS(G,p->headvex,Visit);

}


/*
* @description:打印元素
*/
Status PrintElem(VertexType elem) {
	printf("%d",elem);
	return OK;
}
