/*------------------------------------------------------------------------------
	* file:amlgraph.h
	* date:10-12-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:邻接多重表实现无向图/网的基本操作
--------------------------------------------------------------------------------*/


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define MAX_VERTEX_NUM 20

//顶点数据类型
typedef int VertexType;

typedef int Status;

typedef enum {unvisited,isvisited}VisitIf;

//图的种类:无向图/网
typedef enum {UDG,UDN}GraphKind;

typedef struct EBox {
	VisitIf mark;	//访问标记
	int ivex;	//边顶点一
	int jvex;	//边顶点二
	struct EBox *ilink;	//指向依附于顶点一的下一条边,类似于起点相同的一条弧
	struct EBox *jlink;	//指向依附于顶点二的下一条边,类似与终点想同的一条弧
	int weight;	//边的权值
}EBox;


typedef struct VexBox {
	VertexType data;
	EBox *firstarc;	//指向第一条依附于该顶点的边
}VexBox;


typedef struct {
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vexnum;	//图的顶点数
	int arcnum;	//图的边数
	GraphKind kind; //图的种类
}AMLGraph;


//访问标志数组
int visited[MAX_VERTEX_NUM];


//创建图
Status CreateGraph(AMLGraph *G);

//定位一个顶点值为图中的位置，否则返回-1
int LocateVex(AMLGraph G,VertexType v);


//返回顶点的值
VertexType GetVex(AMLGraph G,int v);

//返回顶点值为v的下一个邻接顶点的序号，否怎返回-1
int FirstAdjVex(AMLGraph G,VertexType v);

//返回顶点值为v相对于顶点值为w的下一个顶点的序号
int NextAdjVex(AMLGraph G,VertexType v,VertexType w);


//深度优先遍历
Status DFSTraverse(AMLGraph G,Status (*Visit) (VertexType));


//递归实现深度遍历邻接点
void DFS(AMLGraph G,int i,Status (*Visit) (VertexType));


//打印顶点元素
Status PrintElem(AMLGraph G,VertexType elem);

