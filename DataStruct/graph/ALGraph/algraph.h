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

//对顶点v赋值为value
Status PutVex(ALGraph *G,int v,VertexType value);

//返回v的第一个邻接点的序号
int FirstAdjVex(ALGraph G,VertexType v);

//返回v相对w的下一个顶点的序号，w为v的邻接点
int NextAdjVex(ALGraph G,VertexType v,VertexType w);

//插入一个顶点
Status InsertVex(ALGraph *G,VertexType v);

//删除一个顶点和相应的边
Status DeleVex(ALGraph *G,VertexType v);

//插入一段弧或边
Status InsertArc(ALGraph *G,VertexType v,VertexType w);

//删除一段边或弧
Status DeleArc(ALGraph *G,VertexType v,VertexType w);

//深度优先遍历
Status DFSTraverse(ALGraph G,Status (*Visit) (VertexType));

//递归遍历邻接点
void DFS(ALGraph G,int i,Status (*Visit) (VertexType));


//广度优先遍历图
Status BFSTraverse(ALGraph G,Status (*Visit) (VertexType));

//销毁图
void DestoryGraph(ALGraph *G);


