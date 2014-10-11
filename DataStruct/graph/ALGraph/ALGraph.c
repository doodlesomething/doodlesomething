/*---------------------------------------------------------------------------
 * file:ALGraph.c
 * date:10-10-2014
 * author:doodlesomething@163.com
 * version:1.0
 * description:邻接表实现图的基本操作
 ----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "algraph.h"
#include "linkqueue.h"

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

	for(i = 0;i < (*G).vexnum; i++) {
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
 * @description:对顶点v赋值value
 */
Status PutVex(ALGraph *G,int v,VertexType value) {
	if(v > (*G).vexnum || v < 0)
		exit(ERROR);

	(*G).vertices[v].data = value;

	return OK;
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
 * @description:添加顶点值为v(不做边的处理)
 * @more:仅仅添加一个顶点值，而不添加边会导致整个遍历出错，
 	因为这里的遍历是依据边表进行的
 */
Status InsertVex(ALGraph *G,VertexType v) {

	//将顶点值添加到顶点向量数组中
	(*G).vertices[(*G).vexnum].data = v;

	(*G).vertices[(*G).vexnum].firstarc = NULL;

	(*G).vexnum++;

	return OK;
}


/*
 * @description:删除顶点值为v的顶点和相关边
 * @more:注意在v下面的顶点往上移动之后，
 每个边表中顶点adjvex应该左相应的更新
 */
Status DeleVex(ALGraph *G,VertexType v) {
	int i,j;
	ArcNode *p,*pre;

	i = LocateVex(*G,v);

	if(i > (*G).vexnum || i < 0)
		return ERROR;

	p = (*G).vertices[i].firstarc;

	//释放顶点v对应的边表
	while(p) {
		pre = p;
		p = p->nextarc;
		free(pre);
		(*G).arcnum--;
	}

	//顶点数组i后面的顶点上移
	for(j = i + 1; j < (*G).vexnum ; j++)
		(*G).vertices[j - 1].data = (*G).vertices[j].data;

	//更新顶点数
	(*G).vexnum--;

	//更改其他顶点中v顶点信息,对整个顶点数组从上向下遍历修改
	for(j = 0; j < (*G).vexnum ; j++) {
		p = (*G).vertices[j].firstarc;

		while(p) {

			if(p->adjvex == i) {
				//如果要删除的为边表中的第一个节点
				if((*G).vertices[j].firstarc == p) {
					(*G).vertices[j].firstarc = p->nextarc;
					free(p);
					p = (*G).vertices[j].firstarc;
					//有向图或网还需要更新弧数
					if((*G).kind == DN || (*G).kind == DG)
						(*G).arcnum--;
				}
				else {
					pre->nextarc = p->nextarc;
					free(p);
					p = pre->nextarc;

					//有向图或网还需要更新弧数
					if((*G).kind == DN || (*G).kind == DG)
						(*G).arcnum--;

				}
			}
			else {
				//由于顶点数组中的位置已经变了，因此需要更新对应的adjvex
				if(p->adjvex > i)
					p->adjvex--;
				pre = p;
				p = p->nextarc;
			}
		}
	}


	return OK;

}


/*
 * @description:在v,w间插入一段弧或边
 */
Status InsertArc(ALGraph *G,VertexType v,VertexType w) {
	ArcNode *p;
	int v1,w1;

	v1 = LocateVex(*G,v); //弧尾
	w1 = LocateVex(*G,w); //弧头

	if(v1 < 0 || w1 < 0)
		return ERROR;

	p = (ArcNode *) malloc(sizeof(struct ArcNode));
	if(!p)
		exit(OVERFLOW);

	if((*G).kind == DN || (*G).kind == UDN)
		scanf("%d",&p->weight);
	p->adjvex = w1;
	p->nextarc = (*G).vertices[v1].firstarc;
	(*G).vertices[v1].firstarc = p;
	(*G).arcnum++;

	//无向图/网
	if((*G).kind == UDN || (*G).kind == UDG ) {
		p = (ArcNode *) malloc(sizeof(struct ArcNode));
		if(!p)
			exit(OVERFLOW);

		if((*G).kind == UDN)
			scanf("%d",&p->weight);

		p->adjvex = v1;
		p->nextarc = (*G).vertices[w1].firstarc;
		(*G).vertices[w1].firstarc = p;
		(*G).arcnum++;
	}

	return OK;
}


/*
 * @description:删除一段边或弧
 * @more:注意删除一段弧会导致访问出错，因为遍历访问是基于边表来进行了，
 */
Status DeleArc(ALGraph *G,VertexType v,VertexType w) {
	int v1,w1;
	ArcNode *p,*pre;

	v1 = LocateVex(*G,v); //弧尾
	w1 = LocateVex(*G,w); //弧头

	if(v1 < 0 || w1 < 0)
		return ERROR;

	p = (*G).vertices[v1].firstarc;


	while(p) {
		if(p->adjvex == w1) {
			//如果删除的是第一个节点
			if((*G).vertices[v1].firstarc == p) {
				(*G).vertices[v1].firstarc = p->nextarc;
				free(p);
				p = (*G).vertices[v1].firstarc;
			}
			else {
				pre->nextarc = p->nextarc;
				free(p);
				p = pre->nextarc;
			}
			(*G).arcnum--;
		}
		else {
			pre = p;
			p = p->nextarc;
		}
	}
	//如果是无向图/网还存在对称边/弧
	if((*G).kind == UDN || (*G).kind == UDG) {
		p = (*G).vertices[w1].firstarc;
		while(p) {
			if(p->adjvex == v1) {
				//如果删除的是第一个节点
				if((*G).vertices[w1].firstarc == p) {
					(*G).vertices[w1].firstarc = p->nextarc;
					free(p);
					p = (*G).vertices[w1].firstarc;
				}
				else {
					pre->nextarc = p->nextarc;
					free(p);
					p = pre->nextarc;
				}
				(*G).arcnum--;
			}
			else {
				pre = p;
				p = p->nextarc;
			}
		}
	}
	
	return OK;
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
* @description:广度优先遍历图
*/
Status BFSTraverse(ALGraph G,Status (*Visit) (VertexType)) {
	LinkQueue Q;
	int i,v,w;

	InitQueue(&Q);
	//重新初始化访问标记数组
	for(i = 0;i < G.vexnum; i++)
		visited[i] = FALSE;

	//外层循环保证每个节点都能访问到
	for(i = 0;i < G.vexnum ; i++) {
		if(!visited[i]) {
			Visit(G.vertices[i].data);
			visited[i] = TRUE;
			
			EnQueue(&Q,i);

			while(!QueueEmpty(Q)) {
				DeQueue(&Q,&v);

				for(w = FirstAdjVex(G,GetVex(G,v)); w >= 0; w = NextAdjVex(G,GetVex(G,v),GetVex(G,w))  ) {
					if(!visited[w]) {
						Visit(G.vertices[w].data);
						visited[w] = TRUE;
						EnQueue(&Q,w);
					}
				}
			}
		}
	}

	return OK;

}

/*
 * @description:打印顶点值
 */
Status PrintElem(VertexType elem) {
	printf("%d",elem);
	return OK;
}


/*
* @description:销毁图
*/
void DestoryGraph(ALGraph *G) {
	int i;
	ArcNode *p,*pre;

	(*G).arcnum = 0;

	for(i = 0;i < (*G).vexnum; i++) {

		p = (*G).vertices[i].firstarc;

		while(p) {
			pre = p;
			p = p->nextarc;
			free(pre);
		}
	}
	(*G).vexnum = 0;
}



