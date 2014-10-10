/*---------------------------------------------------------------------------------
	* file:MGraph.c
	* date:10-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:图的数组表示及基本操作
------------------------------------------------------------------------------------*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mgraph.h"
#include "linkqueue.h"



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
			return CreateDG(G);
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
	for(k = 0; k < (*G).vexnum; k++) {
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
	for(k = 0; k < (*G).vexnum; k++) {
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
	for(k = 0; k < (*G).vexnum; k++) {
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
	printf("please %d heads and %d tails:\n",(*G).vexnum,(*G).arcnum);
	for(k = 0; k < (*G).vexnum; k++) {
		scanf("%d,%d",&v1,&v2);
		
		i = LocateVex(*G,v1);
		j = LocateVex(*G,v2);

		if(i >= 0 && j >= 0)
			(*G).arcs[i][j].adj = w;	//无向网

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
* @description:图的广度优先遍历
* @more:值得注意的是广度遍历和树中的层序遍历采用的是同样的思路-->采用队列辅助
*/
Status BFSTraverse(MGraph G,Status (*Visit)(VertexType)) {
	LinkQueue Q;
	int i,w,u;
	
	//必须重新初始化访问标记数组
	for(i = 0;i < G.vexnum; i++) 
		visited[i] = FALSE;

	InitQueue(&Q);

	//用于确保每个顶点都会被访问到
	for(i = 0;i < G.vexnum; i++) {
		if(!visited[i]) {
			Visit(G.vexs[i]);
			visited[i] = TRUE;

			//进队
			EnQueue(&Q,i);

			while(!QueueEmpty(Q)) {
				//出队一个元素
				DeQueue(&Q,&u);
				for(w = FirstAdjVex(G,u); w >= 0; w = NextAdjVex(G,u,w)) {
					if(!visited[w]) {
						visited[w] = TRUE;
						Visit(G.vexs[w]);
						EnQueue(&Q,w);
					}
				}
			}
		}
	}

	return OK;
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
* @description:对v进行赋值
*/
Status PutVex(MGraph *G,int v,VertexType value) {
	if(v >= (*G).vexnum || v < 0)
		exit(ERROR);

	(*G).vexs[v] = value;

	return OK;
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
* description:插入一个顶点，但是进行弧的插入，交给后面的插入弧操作进行
* @more:注意需要同时对邻接矩阵行和列的跟新信息,还有这里的插入是直接在
	的位置进行插入，不指定位置
*/
Status InsertVex(MGraph *G,VertexType v) {
	int i;

	//进行赋值
	(*G).vexs[(*G).vexnum] = v;

	if((*G).kind == DN || (*G).kind == UDN)
		for(i = 0; i <= (*G).vexnum; i++) {
			//对行的邻接关系进行初始化
			(*G).arcs[(*G).vexnum][i].adj = INFINITY;
			//对列的邻接关系进行初始化
			(*G).arcs[i][(*G).vexnum].adj = INFINITY;

		}

	else 
		for(i = 0; i <= (*G).vexnum; i++) {
			//对行的邻接关系进行初始化
			(*G).arcs[(*G).vexnum][i].adj = 0;
			//对列的邻接关系进行初始化
			(*G).arcs[i][(*G).vexnum].adj = 0;

		}
	
	//对行进行初始化
	(*G).arcs[(*G).vexnum][i].info = NULL;
	//对列进行初始化
	(*G).arcs[i][(*G).vexnum].info = NULL;

	//图的顶点数目加一
	(*G).vexnum++;

	return OK;
}




/*
* @description:删除G中的顶点v其相关的弧(难点在于弧的删除)
*/
Status DeleVex(MGraph *G,VertexType v) {
	int k,i,j;
	VRType m;

	m = 0;
	k = LocateVex(*G,v);

	if(k >= (*G).vexnum || k < 0)
		return ERROR;

	//图的类型为网
	if((*G).kind == DN || (*G).kind == UDN)
		m = INFINITY;
	/*
	这里主要是释放弧的附带信息，如果是有向图则为释放入弧，
	如果是无向图，由于其是对称矩阵，释放列或行就可
	*/
	for(i =0;i < (*G).vexnum; i++)
		if((*G).arcs[i][k].adj != m) {
			if((*G).arcs[i][k].info)
				free((*G).arcs[i][k].info);
			(*G).arcnum--;
		}

	//有向图存在出弧
	if((*G).kind == DG || (*G).kind == DN) 
		for(i = 0;i < (*G).vexnum; i++)
			if((*G).arcs[k][i].adj != m) {
				if((*G).arcs[k][i].info)
					free((*G).arcs[k][i].info);

				(*G).arcnum--;
			}
	
	//将顶点数组中的v之后的元素前移
	for(i = k + 1; i < (*G).vexnum; i++) 
		(*G).vexs[i-1] = (*G).vexs[i];
	
	//邻接矩阵v之后的前移动
	for(i = 0;i < (*G).vexnum; i++)
		for(j = k + 1; j < (*G).vexnum ; j++)
			(*G).arcs[i][j-1] = (*G).arcs[i][j];

	//邻接矩阵v之下的上移
	for(i = 0;i < (*G).vexnum; i++) 
		for(j = k +1; j < (*G).vexnum ; j++)
			(*G).arcs[j-1][i] = (*G).arcs[j][i];

	(*G).vexnum--;


	return OK;
}


/*
* @description:增添弧<v,w>，若是无向的，则还增添对称弧<w,v>
		注意v,w已经存在图中
*/
Status InsertArc(MGraph *G,VertexType v,VertexType w) {
	int v1,w1,infoflag,len;
	char str[MAX_INFO],c,*info;

	//获取顶点对应位置
	v1 = LocateVex(*G,v);
	w1 = LocateVex(*G,w);
	len = 0;
	
	if(v1 < 0 || w1 < 0)
		return ERROR;
	
	
	if((*G).kind == DN || (*G).kind == UDN) {
		printf("please enter the weight:");
		scanf("%d",&(*G).arcs[v1][w1].adj);
	}
	else 
		(*G).arcs[v1][w1].adj = 1;

	printf("please make sure is info(1 or 0):");
	scanf("%d",&infoflag);

	//边或弧有附带信息
	if(infoflag) {
		while( (c = getchar()) != '#') 
			str[len++] = c;

		info = (char *) malloc(len * sizeof(char));
		strcpy(info,str);
		(*G).arcs[v1][w1].info = info;
	}
	
	//注意如果是无向的，应该添加对称边<w,v)
	if((*G).kind == UDG || (*G).kind == UDN) {
		(*G).arcs[w1][v1].adj = (*G).arcs[v1][w1].adj;
		(*G).arcs[w1][v1].info = (*G).arcs[v1][w1].info;
	}

	(*G).arcnum++;

	return OK;
}


/*
* @description:删除弧或边<v,w>,如果图为无向，则同时删除其对称弧或边
*/
Status DeleArc(MGraph *G,VertexType v,VertexType w) {
	int v1,w1,m;

	v1 = LocateVex(*G,v);
	w1 = LocateVex(*G,w);
	m = 0;
	
	if(v1 < 0 || w1 <0)
		return ERROR;
	
	if((*G).kind == DN || (*G).kind == UDN)
		m = INFINITY;


	(*G).arcs[v1][w1].adj = m;

	if((*G).kind == UDN || (*G).kind == UDG)
		(*G).arcs[w1][v1].adj = (*G).arcs[v1][w1].adj;

	if((*G).arcs[v1][w1].info) {
		free((*G).arcs[v1][w1].info);

		if((*G).kind == UDN || (*G).kind == UDG)
			free((*G).arcs[w1][v1].info);
	}
	(*G).arcnum--;

	return OK;
}


/*
* @description:打印元素
*/
Status PrintElem(VertexType elem) {
	printf("%d",elem);
	return OK;
}


