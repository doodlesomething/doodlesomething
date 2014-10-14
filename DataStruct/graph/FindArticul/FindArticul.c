/*---------------------------------------------------------------------------
 * file:ALGraph.c
 * date:10-14-2014
 * author:doodlesomething@163.com
 * version:1.0
 * description:邻接表实现图的基本操作及求图的关节点
 ----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "findarticul.h"



int lowcount = 1;

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
		if(p->adjvex == w1) {
 			if(pre->adjvex != w1)
				return pre->adjvex;
			else
				return -1;
		}
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
	printf("%d\t",elem);
	return OK;
}



/*
* @description:求关节点,关节点的定义；假如删除顶点v及相关各边后，将图的一个
	联通分量分割成两个或是两个以上的联通分量，则顶点v为图的关节点
* @more:注意根节点的情况是需要单独处理的，其关节点成立的条件是：
	生成树的根有两棵或两颗以上的子树
	因为图中不存在连接不同子树的根节点的边，这样在遍历子树的过程，
	会存在有节点子树是无法遍历到的，这样把根节点删除后，就会把图分成
	森林
*/
void FindArticul(ALGraph G) {
	int i,v;
	ArcNode *p;
	

	count = 1;
	low[0] = visited[0] = 1;	//表示邻接表上0号顶点为生成树的根

	//标志其他的节点都没有访问
	for(i = 1; i < G.vexnum ; i++) 
		visited[i] = FALSE;

	p = G.vertices[0].firstarc;
	v = p->adjvex;

	DFSArticul(G,v);	//从第一个邻接点开始进行查找

	if(count < G.vexnum ) {
		//根节点为关节点，输出
		printf("%d,%d\n",0,G.vertices[0].data);
		//继续往下找
		while(p->nextarc) {
			p = p->nextarc;
			v = p->adjvex;
			if(visited[v] == 0) 
				DFSArticul(G,v);
		}
	}

	
}


/*
* @descirption:从第v的节点出发深度优先遍历图查找图的关节点
* @more:注意visited[]现在不再是单纯的访问标志(0/1)而是1/vexnum-1,
	是通过深度优先搜索遍历得到的，且在遍历的过程的中生成树中
	父亲节点的总是并孩子节点先遍历到
	而low[]是类似后序遍历得到的，也就是说孩子节点是先于父亲节点
	遍历到的
*/
void DFSArticul(ALGraph G,int v) {
	int min,w;
	ArcNode *p;


	//v是第count访问的节点
	visited[v] = min = ++count;
	//对v的每个邻接点进行遍历
	for(p = G.vertices[v].firstarc ; p ; p = p->nextarc ) {
		//w是v的邻接点
		w = p->adjvex;

		//w未曾访问，是v的孩子
		if(visited[w] == 0) {
			//返回前求得low[w]
			DFSArticul(G,w);
			/*如果v的孩子节点的low小，说明其还有祖先节点和孩子节点相连,
			这也是为什么上面要先返回low[w]的原因
			*/
			if(low[w] < min)
				min = low[w];

			if(low[w] >= visited[v])
				printf("%d,%d\n",v,G.vertices[v].data);
		}
		//w已经访问过，w是v0在生成树上的祖先
		else if(visited[w] < min)
			min = visited[w];
	}

	/*
	v的节点的low为visited[v]/low[w]/visited[k]中最小的
	w是顶点v的在深度优先生成树上的孩子节点
	k是顶点v在深度优先生成树有回边连接的祖先节点
	*/
	low[v] = min; 

	Order_Low[v] = lowcount++;	//用于理解
}



