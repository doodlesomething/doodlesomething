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



//初始化二叉树
Status InitBiTree(BiTree *T);


//判空
Status BiTreeEmpty(BiTree T);


//二叉树的深度
int BiTreeDepth(BiTree T);


//返回根节点的值
TElemType Root(BiTree T);


//将某节点的值赋值为value
TElemType Value(Position node);


//返回某个值在树中的节点的指针
Position NodePoint(BiTree T,TElemType elem);


//返回元素elem的左孩子的值
TElemType LightChild(BiTree T,TElemType elem);


//返回元素elem的右孩子的值
TElemType RightChild(BiTree T,TElemType elem);


//返回父亲节点的值
TElemType Parent(BiTree T,TElemType elem);


//返回节点值为elem的左兄弟
TElemType LeftSibling(BiTree T,TElemType elem);


//返回节点值为elem的右兄弟
TElemType RightSibling(BiTree T,TElemType elem);



//description:将节点node的值赋值为value
Status Assign(Position *node,TElemType value);


//前序创建二叉树，#表示一个表示空节点
Status CreateBiTree(BiTree *T);


//前序遍历二叉树
Status PreOrderTraverse(BiTree T,Status (*visit) (TElemType));


//中序遍历二叉树
Status InOrderTraverse(BiTree T,Status (*visit) (TElemType));


//后序遍历二叉树
Status PostOrderTraverse(BiTree T,Status (*visit) (TElemType));


//层序遍历
Status LevelOrderTraverse(BiTree T,Status (*visit) (TElemType elem));


//打印元素
Status PrintElem(TElemType elem);


//树状打印二叉树
void PrintAsTree(BiTree T,int nLayer);



//销毁二叉树
void DestoryBiTree(BiTree *T);



/*
* @description:删除子树
		LR 等于0代表删除左子树
		LR == 1代表删除右子树
*/
Status DeleteChild(Position p,int LR);




/*
* @description:插入子树
		p指向T中某个节点,非空二叉树c和T不相交且右子树为空
		根据LR的值，插入c为T的p节点的左右子树，p节点的左或右子树成为c的右子树
*/
Status InsertChild(Position p,int LR,BiTree c);
