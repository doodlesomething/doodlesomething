/*---------------------------------------------------------------------------
 * file:ALGraph.c
 * date:10-14-2014
 * author:doodlesomething@163.com
 * version:1.1
 * description:邻接表实现图的基本操作并实现图的拓扑排序和关键路径算法
 ----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "criticalpath.h"





/*
* @description:初始化链栈
*/
void InitStack(LinkStack *S) {
	(*S).top = NULL;
	(*S).len = 0;
}

/*
* @description:进栈
*/
Status Push(LinkStack *S,ElemType elem) {
	StackPoint s = (StackPoint) malloc(sizeof(StackNode));
	if(!s)
		exit(OVERFLOW);
	
	s->data = elem;
	s->next = (*S).top;
	(*S).top = s;
	(*S).len++;

	return OK;
}


/*
* @description:判空
*/
Status StackEmpty(LinkStack S) {
	return S.top == NULL ? TRUE : FALSE;
}

/*
* @description:出栈
*/
Status Pop(LinkStack *S,ElemType *elem) {
	StackPoint p;

	if(StackEmpty(*S))
		return ERROR;

	//保存栈顶，以便删除
	p = (*S).top;
	(*elem) = p->data;
	(*S).top = p->next;
	free(p);
	(*S).len--;

	return OK;
}

/*
* @description:遍历链栈所有元素
*/
void StackTraverse(LinkStack S,void (*visit) (ElemType)) {
	StackPoint p;
	p = S.top;

	while(p) {
		visit(p->data);
		p = p->next;
	}
}

/*
* @description:打印栈元素
*/
void visit(ElemType elem) {
	printf("%d\t",elem);
}





/*
 * @deccription:创建图(有向图/网，无向图/网)
 */
Status CreateGraph(ALGraph *G) {
	int i,w,v1,v2;
	VertexType va,vb;
	ArcNode *p;

	//图的种类
	printf("please enter the kind of graph(DG:0,DN:1,UDG:2,UDN:3):");
	scanf("%d",&(*G).kind);

	//输入顶点数目和边数目
	printf("please the vexnum and arcnum:");
	scanf("%d,%d",&(*G).vexnum,&(*G).arcnum);

	//确定顶点值
	printf("please enter the value of each vertex:");
	for(i = 0;i < (*G).vexnum ; i++) {
		scanf("%d,",&(*G).vertices[i].data);
		(*G).vertices[i].firstarc = NULL;

	}



	//确定边关系，注意邻接链表中只存储边的关系和信息，不存储邻接点的值
	if((*G).kind == DN || (*G).kind == UDN)
		printf("please enter the heads,tails and weights:\n");
	else
		printf("please enter the heads and tails:\n");

	for(i = 0;i < (*G).arcnum; i++) {
		if((*G).kind == DN || (*G).kind == UDN) 
			scanf("%d,%d,%d",&va,&vb,&w);
		else 
			scanf("%d,%d",&va,&vb);

		v1 = LocateVex(*G,va); //弧头
		v2 = LocateVex(*G,vb); //弧尾

		if(v1 < 0 || v2 < 0)
			return ERROR;



		p = (ArcNode *) malloc(sizeof(struct ArcNode));

		if(!p)
			exit(OVERFLOW);
		//注意：在有向图或网中，顶点为弧尾
		p->adjvex = v2;
		p->nextarc = (*G).vertices[v1].firstarc;
		(*G).vertices[v1].firstarc = p;

		//处理权值
		if((*G).kind == DN || (*G).kind == UDN)
			p->weight = w;

		//有向图/网中邻接表值处理出度，而无向图/网中则一次性处理涉及到的两个顶点
		if((*G).kind == UDN || (*G).kind == UDG) {
			p = (ArcNode *) malloc(sizeof(struct ArcNode));

			if(!p)
				exit(OVERFLOW);

			p->adjvex = v1;
			p->nextarc = (*G).vertices[v2].firstarc;
			(*G).vertices[v2].firstarc = p;
			//无向网
			if((*G).kind == UDN)
				p->weight = w;
		}
	}

	return OK;
}


/*
 * @description:返回顶点值在顶点向量数组中位置，无则返回-1
 */
int LocateVex(ALGraph G,VertexType v) {
	int i;

	for(i = 0;i < G.vexnum; i++) 
		if(G.vertices[i].data == v )
			return i;

	return -1;
}

/*
 * @description:返回v的值
 */
VertexType GetVex(ALGraph G,int v) {
	if(v > G.vexnum || v < 0)
		exit(ERROR);

	return G.vertices[v].data;
}


/*
 * @description:返回v的第一个邻接点的序号，否则返回-1
 * @more:为了方便理解同意左边的为第一个，则为边表的最后一个
 */
int FirstAdjVex(ALGraph G,VertexType v) {
	int i;
	ArcNode *p,*pre;

	i = LocateVex(G,v);

	p = G.vertices[i].firstarc;

	while(p) {
		pre = p;
		p = p->nextarc;
	}

	if(pre)
		return pre->adjvex;

	return -1;
}

/*
 * @description:返回v相对w的下一个顶点的序号，w为v的邻接顶点
 */
int NextAdjVex(ALGraph G,VertexType v,VertexType w) {
	int v1,w1;

	ArcNode *p,*pre;

	v1 = LocateVex(G,v);
	w1 = LocateVex(G,w);

	p = G.vertices[v1].firstarc;
	pre = p;
	while(p) {
		if(p->adjvex == w1)
			if(pre->adjvex != w1)
				return pre->adjvex;
			else
				return -1;
		pre = p;
		p = p->nextarc;
	}

	return -1;
}



/*
 * @description:深度优先遍历图
 */
Status DFSTraverse(ALGraph G,Status (*Visit) (VertexType)) {
	int i;

	//每次遍历前都需要进行初始化
	for(i = 0; i < G.vexnum; i++)
		visited[i] = FALSE;

	for(i = 0;i < G.vexnum; i++)
		if(!visited[i])
			DFS(G,i,Visit);

	return OK;
}


/*
 * @description:递归遍历邻接顶点
 */
void DFS(ALGraph G,int i,Status (*Visit) (VertexType)) {
	int w;

	visited[i] = TRUE;
	Visit(G.vertices[i].data);

	for(w = FirstAdjVex(G,GetVex(G,i)); w >= 0; w = NextAdjVex( G,GetVex(G,i),GetVex(G,w) ) ) 
		if(!visited[w])
			DFS(G,w,Visit);


}


/*
 * @description:打印顶点值
 */
Status PrintElem(VertexType elem) {
	printf("%d",elem);
	return OK;
}



/*
* @description:求图的一个拓扑序列
* @more:算法实现思路：
	1.在有向图中选一个没有前驱节点的且输出它
	2.从图中删除该顶点和所有以它为尾的弧
	3.重复上面的步骤，直到所有的顶点都输出
	4.当图中不存在无前驱的顶点时，则说明该图是有环的，无法输出拓扑序列
*/
Status TopoLogicalSort(ALGraph G,LinkStack *T) {
	int InDegree[MAX_VERTEX_NUM];	//各个顶点的入度数组
	LinkStack S;
	int i,count;
	ArcNode *p;

	FindDegree(G,InDegree);
	InitStack(&S);

	//将入度为0的顶点进栈
	for(i = 0 ; i < G.vexnum ; i++)  
		if(!InDegree[i])
			Push(&S,i);

	count = 0; 	//用于输出顶点计数，方便后面判断是否有环

	while(!StackEmpty(S)) {
		Pop(&S,&i);
		//将入度为零的顶点序号进栈是为方便后面使用
		Push(T,i);
		printf("%d",G.vertices[i].data);
		count++;

		//对当前入度为零的邻接顶点减1(因为要"删除"当前节点)
		for(p = G.vertices[i].firstarc ; p ; p = p->nextarc)
			if(!(--InDegree[p->adjvex]))
				Push(&S,p->adjvex);
	}


	if(count < G.vexnum )
		return ERROR;
	else
		return OK;
}



/*
* @description:根据邻接链表求各个顶点的入度(这样不需要在邻接链表中增加in域)
*/
void FindDegree(ALGraph G,int InDegree[]) {
	int i;
	ArcNode *p;

	//顶点的入度全部初始化为0
	for(i = 0; i < G.vexnum ; i++)
		InDegree[i] = 0;
	
	//遍历各个顶点对应的链表
	for(i = 0; i < G.vexnum ; i++) {
		p = G.vertices[0].firstarc;
		//遍历当前顶点的链表
		while(p) {
			InDegree[p->adjvex]++;
			p = p->nextarc;
		}
	}
}



/*
* @description:求关键路径
*/
Status CriticalPath(ALGraph G) {
	return OK;
}





