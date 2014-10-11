/*----------------------------------------------------------------------------
	* file: OLGraph.c
	* date:10-11-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:十字链表实现图的基本操作
	* more:十字链表仅仅能表述有向图/网，
		还有在遍历等操作时，沿着出
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
* @description:销毁图
* @more:遍历或是销毁等等一个思路可以仅仅按照出表来进行
*/
void Destory(OLGraph *G) {
	ArcBox *p,*pre;
	int i;

	for(i = 0;i < (*G).vexnum ; i++) {

		p = (*G).xlist[i].firstout; 	//找到每个顶点向量对应的十字链表

		while(p) {
			pre = p;
			p = p->tlink;
			free(pre);
		}
		
	}
}


/*
* @description:返回顶点v的值
*/
VertexType GetVex(OLGraph G,int v) {

	if(v > G.vexnum || v < 0 ) 
		exit(OVERFLOW);

	return G.xlist[i].data;
}


/*
* @description:对值为v的顶点赋值为value
*/
Status PutVex(OLGraph *G,VertexType v,VertexType value) {
	int i;

	i = LocateVex(*G,v);

	if( i < 0)
		return ERROR;

	(*G).xlist[i].data = value;

	return OK;
}


/*
* @description:返回顶点值为v的下一个邻接顶点的序号
* @more:这里的第一个邻接顶点理解为顶点对应链表中的第一个节点
*/
int FirstAdjVex(OLGraph G,VertexType v) {
	int i;

	i = LocateVex(G,v);

	if( i < 0)
		return -1;

	if(G.xlist[i].firstout)
		return G.xlist[i].firstout->headvex;
}


/*
* @description:返回顶点为v相对顶点值为w的下一个邻接顶点的序号，w为v的一个邻接顶点
*/
int NextAdjVex(OLGraph G,VertexType v) {
	int i,j;
	ArcBox *p;

	i = LocateVext(G,v);
	j = LocateVext(G,w);

	if(i < 0) 
		return -1;

	p = G.xlist[i].firstout;	//顶点v对应的弧链表

	while(p && p->hlink) 
		if(p->headvex == j)
			return p->hlink->headvex;
	
}


/*
* @description:添加一个顶点值为v
* @more:注意这里不处理边
*/
Status InsertVex(OLGraph *G,VertexType v) {
	int i;
	i = (*G).vexnum;

	(*G).xlist[i].data = v;
	(*G).xlist[i].firstin = NULL;
	(*G).xlist[i].firstout = NULL;

	return OK;
}


/*
* @description:删除一个顶点值为v的顶点，并删除相关的弧
* @more:这里的删除在于出表和入表是交叉的同时可能还要更新其他顶点的firstin等指针
* 思路和邻接表中的不同的是这里不能先进行顶点向量的更新，那样无法找到对应的出/入指针
* 顶点向量的更新应该放在最后面
* 关于十字交叉的出入表的处理思路如下：
	1.找到顶点值对应的链表，然后横向遍历出表的同时，查询入表中的tail是否有顶点的firstin指向该
	节点，如果有则更新该firstin即可
	2.关于出表的删除可进行横向遍历即可
	3.更新顶点向量数组
	4.done
*/
Status DeleVex(OLGraph *G,VertexTyep v) {
	int i,j;
	ArcBox *p,*pre;

	i = LocateVex(*G,v);

	
	p = (*G).xlist[i].firstout;

	
	
	//顶点向量数组上移动
	for(j = i + 1;j < (*G).vexnum; j++)
		(*G).xlist[j - 1] = (*G).xlist[j];


	(*G).vexnum--;
}

/*
* @description:在顶点值v和顶点值w间添加一段弧
*/
Status InsertArc(OLGraph *G,VertexType v,VertexType w) {
	int i,j;


}


/*
* @description:删除顶点值w和顶点值v间的一段弧
*/
Status DeleArc(OLGraph *G,VertexType v,VertexType w) {
	int i,j;

	return OK;
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
* @descrption:广度优先遍历图
*/
Status BFSTraverse(OLGraph G,Status (*Visit) (VertexType)) {


	return OK;
}


/*
* @description:打印元素
*/
Status PrintElem(VertexType elem) {
	printf("%d",elem);
	return OK;
}
