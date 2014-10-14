/*---------------------------------------------------------------------------
	* file:algraph.h
	* date:10-10-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:邻接表实现图的基本操作
----------------------------------------------------------------------------*/


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

//顶点数组最大容量
#define MAX_VERTEX_NUM 20

typedef int Status;

//顶点类型
typedef int VertexType;

//图的种类，分别代表有向图/有向网/无向图/无向网
typedef enum{DG,DN,UDG,UDN} GraphKind;


typedef struct ArcNode{
	int adjvex;	//该弧或边所指向的顶点的位置
	struct ArcNode *nextarc;	//指向下一条弧的指针
	int weight;	//弧或是边的权值
}ArcNode;


typedef struct VNode {
	VertexType data;	//顶点值
	ArcNode *firstarc;	//指向第一条依附于该顶点的边的指针
}VNode,AdjList[MAX_VERTEX_NUM];


typedef struct {
	AdjList vertices;
	int vexnum;	//图的顶点数
	int arcnum;	//图的边数
	GraphKind kind;
}ALGraph;


//访问记录数组
int visited[MAX_VERTEX_NUM];

int count;
int low[MAX_VERTEX_NUM];	//

int Order_Low[MAX_VERTEX_NUM];	//记录每个节点在low的访问次序，方便理解


//创建图
Status CreateGraph(ALGraph *G);

//定位顶点值
int LocateVex(ALGraph G,VertexType v);

//深度优先遍历图
Status DFSTraverse(ALGraph G,Status (*Visit) (VertexType));

//深度优先遍历邻接顶点 
void DFS(ALGraph G,int i,Status (*Visit) (VertexType));

//打印顶点值
Status PrintElem(VertexType elem);


//返回v的值
VertexType GetVex(ALGraph G,int v);


//返回v的第一个邻接点的序号
int FirstAdjVex(ALGraph G,VertexType v);

//返回v相对w的下一个顶点的序号，w为v的邻接点
int NextAdjVex(ALGraph G,VertexType v,VertexType w);


//深度优先遍历
Status DFSTraverse(ALGraph G,Status (*Visit) (VertexType));

//递归遍历邻接点
void DFS(ALGraph G,int i,Status (*Visit) (VertexType));


//求图的关节点
void FindArticul(ALGraph G);


//从第v个节点出发深度优先遍历图查找图的关节点
void DFSArticul(ALGraph G,int v);


