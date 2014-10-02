/*------------------------------------------------------------------------
	* file:BiTree.c -->head file fot BiTree.c
	* date:1-10-2014
	* author:doodlesomething@63.com
	* version:1.0
	* description:二叉树的基本操作
--------------------------------------------------------------------------*/



#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef char TElemType;

typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}*BiTree,*Position;



//前序创建二叉树，#表示一个表示空节点
Status CreateBiTree(BiTree *T);

//前序遍历二叉树
Status PreOrderTraverse(BiTree T,Status (*visit) (TElemType));

//中序遍历二叉树
Status InOrderTraverse(BiTree T,Status (*visit) (TElemType));


//后序遍历二叉树
Status PostOrderTraverse(BiTree T,Status (*visit) (TElemType));

//打印元素
Status PrintElem(TElemType elem);


//树状打印二叉树
void PrintAsTree(BiTree T,int nLayer);
