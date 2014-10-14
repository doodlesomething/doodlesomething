/*---------------------------------------------------------------------------------
	* file:MGraph.c
	* date:10-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:实现深度优先遍历生成森林
------------------------------------------------------------------------------------*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mgraph.h"



/*
* @description:创建图,包括有向图，无向图，有向网，无向网
*/
Status CreateGraph(MGraph *G) {
	printf("please enter the kind of the graph:");
	scanf("%d",&(*G).kind);

	switch((*G).kind) {
		case UDG:
			return CreateUDG(G);
			break;
		case DG:
			return CreateDG(G);
		case UDN:
			return CreateUDN(G);
			break;
		case DN:
			return CreateDN(G);
			break;
		default:
			return ERROR;
	}
}	



/*
* @description:创建无向图
* @more:分几步来做
	1.确定顶点数/弧数
	2.确定各个顶点的值
	3.初始化邻接矩阵
	4.确定邻接矩阵
*/
Status CreateUDG(MGraph *G) {
	int i,j,k,infoflag,len;
	char c;
	//设置一个暂存区和一个临时指针
	char str[MAX_INFO];
	char *info;

	VertexType v1,v2;

	len = 0;

	//确定顶点数/弧数
	printf("please enter vexnum, arcnum is info(1 or 0):");
	scanf("%d,%d,%d",&(*G).vexnum,&(*G).arcnum,&infoflag);

	//确定各个顶点的值
	printf("the value of each vertex:");
	for(i = 0;i < (*G).vexnum ; i++)
		scanf("%d,",&(*G).vexs[i]);
	
	//初始化邻接矩阵
	for(i = 0; i < (*G).vexnum; i++) 
		for(j = 0;j < (*G).vexnum ; j++) {
			(*G).arcs[i][j].adj = 0;	//无向图
			(*G).arcs[i][j].info = NULL;
		}


	//确定邻接矩阵
	printf("please %d heads and %d tails:\n",(*G).vexnum,(*G).arcnum);
	for(k = 0; k < (*G).arcnum; k++) {
		scanf("%d,%d",&v1,&v2);
		
		i = LocateVex(*G,v1);
		j = LocateVex(*G,v2);

		if(i >= 0 && j >= 0)
			(*G).arcs[i][j].adj = (*G).arcs[j][i].adj = 1;	//无向图,对称矩阵
		//如果顶点有附带信息,则输入并申请空间
		if(infoflag) {
			printf("please enter the info:");
			while( (c = getchar()) != '#')
				str[len++] = c;

			info = (char *) malloc(len * sizeof(char));
			str[len] = '\0';

			strcpy(info,str);

			(*G).arcs[i][j].info = (*G).arcs[i][j].info = info;
		}
	}

	(*G).kind = UDG;

	return OK;
}





/*
* @description:创建有向图
* @more:分几步来做
	1.确定顶点数/弧数
	2.确定各个顶点的值
	3.初始化邻接矩阵
	4.确定邻接矩阵
*/
Status CreateDG(MGraph *G) {
	int i,j,k,len,infoflag;
	VertexType v1,v2;

	char str[MAX_INFO];
	char *info;
	char c;

	//确定顶点数/弧数
	printf("please enter vexnum , arcnum and is info(1 or 0):");
	scanf("%d,%d,%d",&(*G).vexnum,&(*G).arcnum,&infoflag);

	//确定各个顶点的值
	printf("the value of each vertex:");
	for(i = 0;i < (*G).vexnum ; i++)
		scanf("%d,",&(*G).vexs[i]);
	
	//初始化邻接矩阵
	for(i = 0; i < (*G).vexnum; i++) 
		for(j = 0;j < (*G).vexnum ; j++) {
			(*G).arcs[i][j].adj = 0;	//有向图
			(*G).arcs[i][j].info = NULL;
		}


	//确定邻接矩阵
	printf("please %d heads and %d tails:\n",(*G).vexnum,(*G).arcnum);
	for(k = 0; k < (*G).arcnum; k++) {
		scanf("%d,%d",&v1,&v2);
		
		i = LocateVex(*G,v1);
		j = LocateVex(*G,v2);

		if(i >= 0 && j >= 0)
			(*G).arcs[i][j].adj = 1;	//有向图

		//如果顶点有附带信息,则输入并申请空间
		if(infoflag) {
			printf("please enter the info:");
			while( (c = getchar()) != '#')
				str[len++] = c;

			info = (char *) malloc(len * sizeof(char));
			strcpy(info,str);

			(*G).arcs[i][j].info = info;
		}
	}

	(*G).kind = DG;

	return OK;
}




/*
* @description:创建有向网
*/

Status CreateDN(MGraph *G) {
	int i,j,k,len,infoflag,w;
	VertexType v1,v2;

	char str[MAX_INFO];
	char *info;
	char c;

	//确定顶点数/弧数
	printf("please enter vexnum , arcnum and is info(1 or 0):");
	scanf("%d,%d,%d",&(*G).vexnum,&(*G).arcnum,&infoflag);

	//确定各个顶点的值
	printf("the value of each vertex:");
	for(i = 0;i < (*G).vexnum ; i++)
		scanf("%d,",&(*G).vexs[i]);
	
	//初始化邻接矩阵
	for(i = 0; i < (*G).vexnum; i++) 
		for(j = 0;j < (*G).vexnum ; j++) {
			(*G).arcs[i][j].adj = INFINITY;	//有向网
			(*G).arcs[i][j].info = NULL;
		}


	//确定邻接矩阵
	printf("please %d heads and %d tails and weights:\n",(*G).vexnum,(*G).arcnum);
	for(k = 0; k < (*G).arcnum; k++) {
		scanf("%d,%d,%d",&v1,&v2,&w);
		
		i = LocateVex(*G,v1);
		j = LocateVex(*G,v2);

		if(i >= 0 && j >= 0)
			(*G).arcs[i][j].adj = w;	//有向图

		//如果顶点有附带信息,则输入并申请空间
		if(infoflag) {
			printf("please enter the info:");
			while( (c = getchar()) != '#')
				str[len++] = c;

			info = (char *) malloc(len * sizeof(char));
			strcpy(info,str);

			(*G).arcs[i][j].info = info;
		}
	}

	(*G).kind = DN;

	return OK;
}






/*
* @description:创建无向网
*/

Status CreateUDN(MGraph *G) {
	int i,j,k,len,infoflag,w;
	VertexType v1,v2;

	char str[MAX_INFO];
	char *info;
	char c;

	//确定顶点数/弧数
	printf("please enter vexnum , arcnum and is info(1 or 0):");
	scanf("%d,%d,%d",&(*G).vexnum,&(*G).arcnum,&infoflag);

	//确定各个顶点的值
	printf("the value of each vertex:");
	for(i = 0;i < (*G).vexnum ; i++)
		scanf("%d,",&(*G).vexs[i]);
	
	//初始化邻接矩阵
	for(i = 0; i < (*G).vexnum; i++) 
		for(j = 0;j < (*G).vexnum ; j++) {
			(*G).arcs[i][j].adj = INFINITY;	//无向网
			(*G).arcs[i][j].info = NULL;
		}


	//确定邻接矩阵
	printf("please enter heads,tails and weights:\n",(*G).vexnum,(*G).arcnum);
	for(k = 0; k < (*G).arcnum; k++) {
		scanf("%d,%d,%d",&v1,&v2,&w);
		
		i = LocateVex(*G,v1);
		j = LocateVex(*G,v2);

		if(i >= 0 && j >= 0)
			(*G).arcs[i][j].adj = (*G).arcs[j][i] = w;	//无向网

		//如果顶点有附带信息,则输入并申请空间
		if(infoflag) {
			printf("please enter the info:");
			while( (c = getchar()) != '#')
				str[len++] = c;

			info = (char *) malloc(len * sizeof(char));
			strcpy(info,str);

			(*G).arcs[i][j].info = info;
		}
	}

	(*G).kind = UDN;

	return OK;
}







/*
* @description:判断图中是否存在v顶点，存在则返回该顶点在图中的位置，否则返回其他信息
*/
int LocateVex(MGraph G,VertexType v) {
	int i;

	for(i = 0;i < G.vexnum; i++)
		//匹配则返回
		if(G.vexs[i] == v)
			return i;

	return -1;
}


/*
* @description:深度优先遍历图
* @more:分为两步
	1.一定要重新初始化访问记录数组
	2.访问没有访问过的顶点，并更新访问记录数组
* @本函数中的第二个循环主要是为了保证每个顶点都能被访问到
   而DFS中的循环是在寻找当前节点的相邻节点来访问
   关键的关键在于递归的理解-->废话
*/
Status DFSTraverse(MGraph G,Status (*Visit) (VertexType)) {
	int i;
	//初始化访问记录数组
	for(i = 0;i < G.vexnum; i++)
		visited[i] = FALSE;
	
	for(i = 0;i < G.vexnum ; i++) 
		if(!visited[i])
			DFS(G,i,Visit);

	return OK;
}



/*
* @description:深度优先递归遍历
*/
void DFS(MGraph G,int i,Status (*Visit) (VertexType)) {
	int j,w;

	//标记
	visited[i] = TRUE;
	Visit(G.vexs[i]);

	for(w = FirstAdjVex(G,i); w >= 0; w = NextAdjVex(G,i,w))
		if(!visited[w])
			DFS(G,w,Visit);
}



/*
* @description:返回v的值
*/
VertexType GetVex(MGraph G,int v) {
	if(v >= G.vexnum || v < 0)
		exit(ERROR);

	return G.vexs[v];
}



/*
* @description:返回v(序号)的第一个相邻节点（序号）
*/
int FirstAdjVex(MGraph G,int v) {
	if(v > G.vexnum || v < 0)
		return -1;
	
	int i,j;

	j = 0;

	//如果是网
	if(G.kind == DN || G.kind == UDN )
		j = INFINITY;

	for(i = 0;i < G.vexnum; i++) 
		if(G.arcs[v][i].adj != j)
			return  i;

	return -1;
}

/*
* @description:w是v的相邻节点，返回v相对w的下一个节点的序号，否则返回-1
*/
int NextAdjVex(MGraph G,int v,int w) {
	int i,j;
	
	j = 0;
	//如果为网
	if(G.kind == DN || G.kind == UDN)
		j = INFINITY;
	//两顶点不相邻
	if(G.arcs[v][w].adj == j)
		return -1;
	//从w之后的节点开始就可以
	for(i = w + 1; i < G.vexnum; i++) 
		if(G.arcs[v][i].adj != j)
			return i;

	return -1;
}



/*
* @description:打印元素
*/
Status PrintElem(int elem) {
	printf("%d\t",elem);
	return OK;
}




/*
* @description:建立无向图的深度优先生成森林的孩子兄弟链表T
*/
void DFSForest(MGraph G,BiTree *T) {
	int i;
	BiTree p,q;

	
	*T = p = q = NULL;

	for(i = 0; i < G.vexnum; i++) 
		visited[i] = FALSE;
	
	for(i = 0; i < G.vexnum; i++) {
		if(!visited[i]) {
			p = (BiTree) malloc(sizeof(struct BiTNode));
			if(!p)
				exit(OVERFLOW);

			p->data = GetVex(G,i);
			p->rchild = NULL;
			p->lchild = NULL;

			//第一颗生成树的根
			if(!(*T)) 
				*T = p;
			//其他生成树的根，第一颗树的兄弟
			else
				q->rchild = p;
			q = p;	//q指示当前生成树的根

			DFSTree(G,i,&p);
				
		}
	}

}


/*
* @description:从v出发进行深度优先遍历，生成以T为根节点的生成树
*/
void DFSTree(MGraph G,int v,BiTree *T) {
	BiTree p,q;
	int first,w;

	p = q = NULL;
	visited[v] = TRUE;
	first = TRUE;

	for(w = FirstAdjVex(G,GetVex(G,v)); w >= 0 ; w = NextAdjVex(G,GetVex(G,v),GetVex(G,w))) {
		if(!visited[w]) {
			p = (BiTree) malloc(sizeof(struct BiTNode));
			if(!p)
				exit(OVERFLOW);

			p->data = GetVex(G,w);
			p->rchild = NULL;
			p->lchild = NULL;

			if(first) {
				(*T)->lchild = p;
				first = FALSE;
			}
			else
				q->rchild = p;

			q = p;

			DFSTree(G,w,&q);
		}
	}
}



/*
* @description:前序遍历二叉树
*/
Status PreOrderTraverse(BiTree T,Status (*visit) (TElemType elem)) {
	if(T) {
		if(visit(T->data))
			if(PreOrderTraverse(T->lchild,visit))
				if(PreOrderTraverse(T->rchild,visit))
					return OK;
		return ERROR;
	}
	
	return OK;
}



