/*-----------------------------------------------------------------------------
	* file:bst.h
	* date:10-19-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:二叉查找树
	* more:包括初始化/动态删除/插入/查找/遍历
-------------------------------------------------------------------------------*/



#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2


typedef int Status;

typedef int TElemType;

//二叉查找树的节点结构
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}*BiTree;


//初始化
Status InitDSTable(BiTree *T);

//在二叉排序树中插入不存在的元素
Status InsertBST(BiTree *T,TElemType key);

//判读查找是否成功
Status Search_BST(BiTree T,TElemType key,BiTree f,BiTree *p);

//删除二叉排序树中的某个节点
Status DeleBST(BiTree *T,TElemType key);

//具体的节点删除操作
Status Dele(BiTree *p);


//中序遍历
void InOrderTraverse(BiTree T,Status (*Visit) (TElemType));


//查找
BiTree SearchBST(BiTree T,TElemType key);


//打印元素值
Status PrintElem(TElemType elem);

//销毁二叉排序树
void DestoryTree(BiTree *T);

