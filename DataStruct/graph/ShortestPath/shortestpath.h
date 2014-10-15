/*---------------------------------------------------------------------------------
	* file:mgraph.h
	* date:10-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:图的数组表示及基本操作
------------------------------------------------------------------------------------*/


#define TRUE 1
#define ERROR 0
#define OK 1
#define FALSE 0

#define INFINITY 65535 //表示无穷大-->在带权的图中用到，即网
#define MAX_VERTEX_NUM 20 //图的最大定点数

#define MAX_INFO 20  //每条弧附带信息最大长度

typedef int Status;

//顶点关系类型
typedef int VRType;

//附加信息类型
typedef char InfoType;

//顶点数据类型
typedef int VertexType;

//图的种类:分别代表有向图，有向网，无向图，无向网
typedef enum {DG,DN,UDG,UDN} GraphKind;


typedef struct {
	VRType adj; //定点关系类型，对无权图用1或0表示是否相邻；对带权图，则为权值类型
	InfoType *info;	//附加信息指针
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];


typedef struct {
	//顶点向量
	VertexType vexs[MAX_VERTEX_NUM];
	//邻接矩阵
	AdjMatrix arcs;
	//图的当前顶点数
	int vexnum;
	//图的弧数
	int arcnum;
	//图的种类
	GraphKind kind;
}MGraph;


//数组标记某元素是否被访问过
int visited[MAX_VERTEX_NUM];

int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

//最短路径矩阵
int D[MAX_VERTEX_NUM];

int DM[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

//创建图,包括有无向图，有无向网
Status CreateGraph(MGraph *G);

//创建无向图
Status CreateUDG(MGraph *G);

//创建有向图
Status CreateDG(MGraph *G);

//创建无向网
Status CreateUDN(MGraph *G);

//创建有向网
Status CreateDN(MGraph *G);

//返回某顶点在图中的位置
int LocateVex(MGraph G,VertexType v);

//打印元素
Status PrintElem(VertexType elem);

//深度优先遍历图
Status DFSTraverse(MGraph G,Status (*Visit) (VertexType));

//深度优先递归遍历
void DFS(MGraph G,int i,Status (*Visit) (VertexType));

//返回v的值
VertexType GetVex(MGraph G,int v);

//返回v的第一个邻接顶点
int FirstAdjVex(MGraph G,int v);

//w是v的邻接点，返回v相对于w的下一个邻接点
int NextAdjVex(MGraph G,int v,int w);


//迪杰特斯拉算法实现最短路径
void ShortestPath_DIJ(MGraph G,int v,int P[][MAX_VERTEX_NUM],int D[]);


//弗洛伊德算法实现求图的任意两顶点的最短路径
void ShortestPath_FLOYD(MGraph G,int P[][MAX_VERTEX_NUM],int D[][MAX_VERTEX_NUM]);



