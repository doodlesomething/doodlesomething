/*----------------------------------------------------------------------------
	* file: algraph.h
	* date:10-11-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:十字链表实现图的基本操作
	* more:十字链表仅仅能表述有向图/网
-----------------------------------------------------------------------------*/


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define MAX_VERTEX_NUM 20

typedef int Status;

typedef int VertexType;


//图的种类包括有向图/有向网
typedef enum {DG,DN} GraphKind;

typedef struct ArcBox {
	int tailvex;	//该弧的尾顶点的位置
	int headvex;	//该弧的头顶点的位置
	struct ArcBox *hlink;  //指向下一个起点相同的弧
	struct ArcBox *tlink;	//指向一个终点相同的弧
	int weight;	//弧的权值
}ArcBox;


typedef struct VexNode{
	VertexType data;
	ArcBox *firstin;	//指向该顶点的第一条入弧
	ArcBox *firstout;	//指向该顶点的第一条出弧
}VexNode;


typedef struct {
	VexNode xlist[MAX_VERTEX_NUM];
	int vexnum;	//顶点数
	int arcnum;	//弧数
	GraphKind kind;	//图的种类(有向图/有向网)
}OLGraph;


//访问标记数组
int visited[MAX_VERTEX_NUM];


//创建图(有向图/有向网)
Status CreateGraph(OLGraph *G);

//定位顶点值v的位置，无则返回-1
int LocateVex(OLGraph G,VertexType v);

//销毁图
void DestoryGraph(OLGraph *G);

//返回顶点v的值
VertexType GetVex(OLGraph G,int v);

//对值为v的顶点赋值为value
Status PutVex(OLGraph *G,VertexType v,VertexType value);

//获取v的下一个邻接点的序号
int FirstAdjVex(OLGraph G,VertexType v);

//返回顶点v相对于w的下一个邻接点的序号
int NextAdjVex(OLGraph G,VertexType v,VertexType w);

//添加一个值为v的顶点
Status InsertVex(OLGraph *G,VertexType v);

//

//深度优先遍历
Status DFSTraverse(OLGraph G,Status (*Visit) (VertexType));

//深度优先递归遍历
void DFS(OLGraph G,int i,Status (*Visit) (VertexType));

//打印元素
Status PrintElem(VertexType elem);


