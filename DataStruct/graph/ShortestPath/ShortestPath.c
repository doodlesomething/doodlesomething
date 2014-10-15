/*---------------------------------------------------------------------------------
	* file:ShortestPath.c
	* date:10-15-2014
	* author:doodlesomething@163.com
	* version:1.1
	* description:最短路径
------------------------------------------------------------------------------------*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shortestpath.h"



/*
* @description:创建图,包括有向图，无向图，有向网，无向网
*/
Status CreateGraph(MGraph *G) {
	printf("please enter the kind of the graph(DG:0,DN:1,UDG:2,UDN:3):");
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

			(*G).arcs[i][j].info = (*G).arcs[j][i].info = info;
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
	printf("please heads,tails and weights:\n");
	for(k = 0; k < (*G).arcnum; k++) {
		scanf("%d,%d,%d",&v1,&v2,&w);
		
		i = LocateVex(*G,v1);
		j = LocateVex(*G,v2);

		if(i >= 0 && j >= 0)
			(*G).arcs[i][j].adj = (*G).arcs[j][i].adj = w;	//无向网

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
	int w;

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
Status PrintElem(VertexType elem) {
	printf("%d",elem);
	return OK;
}


/*
* @description:迪杰斯特拉算法实现最短路径
* @more:类似贪心算法：即总是选择当前最优的路径，最后得到总体最优
	时间复杂度:O(n的二次方)
*/
void ShortestPath_DIJ(MGraph G,int v0,int P[][MAX_VERTEX_NUM],int D[]) {
	//用于记录该节点和v是否已经有最短路径
	int final[MAX_VERTEX_NUM];
	int i,w,min,v,j;

	for(i = 0; i < G.vexnum ; i++) {
		//将所有顶点都确定为还未求得最短路径
		final[i] = FALSE;
		D[i] = G.arcs[v0][i].adj;
		//设置空路径
		for(w = 0; w < G.vexnum ;w++) 
			P[i][w] = FALSE;
		if(D[i] < INFINITY ) {
			P[i][v0] = TRUE;
			P[i][i] = TRUE;
		}
	}
	
	//v0到v0的距离为0，且其最短路径已经求得
	D[v0] = 0;
	final[v0] = TRUE;

	//上面的初始化全部完成，进入主循环

	
	/*
	* 主要思想：每次求得v0到vi的最短路径，并添加到vi到S集中，
		1.在v0邻接点的路径中选择一条路径最短的，假设这条
		最短路径的头为v1,则在以上面的最短路径的基础上，求
		v1与邻接点中路径中最短的一条，如此循环下去，直至
		所有的顶点与v0的最短路径都找到
	*/
	//外层循环主要用于控制次数
	for(i = 1; i < G.vexnum ; i++) {
		min = INFINITY;

		for(w = 0; w < G.vexnum ; w++) {
			if(!final[w]) 
				if(D[w] < min) {
					//当前顶点与v0顶点更近
					v = w;
					min = D[w];
				}
		}


		//标志已经找到了v0和v的最短路径
		final[v] = TRUE;

		//更新当前最短路径及距离
		for(w = 0; w < G.vexnum ; w++) {
			if(!final[w] && (min + G.arcs[v][w].adj) < D[w]) {
				D[w] = min + G.arcs[v][w].adj;
				for(j = 0; j < G.vexnum; j++)
					P[w][j] = P[v][j];

				P[w][w] = TRUE;
			}
		}


	}
}





/*
* @description:任意两顶点间最短路径,使用弗洛伊德算法实现
* @more:可以使用上面的迪杰斯特拉算法实现，即在外面再加上一层循环，两者时间复杂度同为O(n的三次方)
	主要思想是：为了说明我们假设有三个点v0,v1,v2
	如果从v1 -> v0 ->v2 的路径短于从v1 -> v2的路径，我们将前者作为v1到v2的最短路径，v0则为中转
	节点，以此类推..
*/
void ShortestPath_FLOYD(MGraph G,int P[][MAX_VERTEX_NUM],int D[][MAX_VERTEX_NUM]) {
	int v,w,k;

	//初始化
	for(v = 0; v < G.vexnum ; v++)
		for(w = 0; w < G.vexnum ; w++) {
			//D的初始值即为图的邻接矩阵
			D[v][w] = G.arcs[v][w].adj;
			P[v][w]= w;
		}

	//主循环,k代表用于中转的顶点序号，v代表开始的顶点，w代表结束的顶点
	for( k = 0; k < G.vexnum ; k++) 
		for( v = 0; v < G.vexnum ; v++)
			for(w = 0; w < G.vexnum ; w++) {
				/*
				D[v][w]代表从v->w,D[v][k]代表从v->k,D[k][w]代表从k->w
				D[v][k] + D[k][w] 代表以k顶点作为中转的路径长度
				*/
				if(D[v][w]  > D[v][k] + D[k][w] ) {
					D[v][w] = D[v][k] + D[k][w];
					//同时更新路径矩阵
					P[v][w] = P[v][k];
				}
			}
}


