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


//事件最早发生时间ve数组
int ve[MAX_VERTEX_NUM];



typedef int ElemType;

typedef struct {
	ElemType data;
	ElemType *next;
}StackNode,*StackPoint;

typedef struct {
	StackPoint top;	//栈顶元素
	int len;	//栈长
} LinkStack;

//初始化链栈
void InitStack(LinkStack *S);

//进栈
Status Push(LinkStack *S,ElemType elem);

//判空
Status StackEmpty(LinkStack S);

//出栈
Status Pop(LinkStack *S,ElemType *elem);


//遍历链栈所有元素
void StackTraverse(LinkStack S,void (*visit) (ElemType));

//打印栈顶元素
void visit(ElemType elem);





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


//求图的一个拓扑序列
Status TopoLogicalSort(ALGraph G,LinkStack *T);


//求各个图的各个顶点的入度数组
void FindDegree(ALGraph G,int InDegree[]);

//求关键路径
Status CriticalPath(ALGraph G);


