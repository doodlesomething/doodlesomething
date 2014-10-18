/*--------------------------------------------------------------------------------------
	* file:staticsearch.h 
	* date:10-18-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:静态查找表
	* more:包括顺序表的查找/折半查找/静态树表查找
----------------------------------------------------------------------------------------*/

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define STACKOVER -2


#define EQ(a,b) ( (a) == (b) )
#define LT(a,b) ( (a) <  (b) )
#define LQ(a,b) ( (a) <=  (b) )

typedef int Status;

typedef int KeyType;

//顺序表节点结构
typedef struct {
	KeyType key;	//关键词
	int weight;	//权值（主要在静态树表查找中用到）
}ElemType;


typedef struct {
	ElemType *elem;	
	int length;	//顺序表长度
}SSTable;



typedef ElemType TElemType;
//判定树节点结构
typedef struct BiTNode {
	TElemType data;
	int order;	//记录序号
	struct BiTNode *lchild;	//左孩子指针
	struct BiTNode *rchild;	//右孩子指针
}*BiTree;




//创建顺序表
Status Create_Seq(SSTable *S,int n,ElemType *Data);


//顺序查找
int Search_Seq(SSTable S,KeyType key);


//将顺序表按关键词有序化
void Ascend(SSTable *S);


//折半查找
int Search_Bin(SSTable S,KeyType key);


//创建一个长度为n的增序的顺序表
Status Create_Ord(SSTable *S,int n,ElemType *Data);


//销毁顺序表
void Destory(SSTable *S);

//构造次优查找树
void SecondOptimal(BiTree *T,ElemType R[],int sw[],int low,int high);


//创建有序的次优查找树
Status CreateSOSTree(BiTree *T,SSTable S);


//静态树表查找
int Search_SOSTree(BiTree T,KeyType key);

//累计权值
void FindSW(int *sw,SSTable S);

//遍历顺序表
Status Traverse(SSTable S,Status (*Visit) (KeyType));

//打印关键词
Status PrintElem(KeyType key);

//前序遍历树
Status PreOrderTraverse(BiTree T,Status (*Visit) (KeyTYpe));
