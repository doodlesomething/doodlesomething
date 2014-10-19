/*--------------------------------------------------------------------------------
	* file:avl.h
	* date:10-29-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:平衡二叉树的建立查找
	* more:包括建立(插入)/遍历/查找	--->这东西真不是人看的
--------------------------------------------------------------------------------*/


#define TRUE 1
#define FALSE 0
#define OVERFLOW -2


#define LH 1 //代表左边高于右边
#define EH 0 //代表左右两边相等
#define RH -1 //代表右边高于左边


typedef int Status;


//树节点的值的数据类型
typedef int TElemType;


//树节点的数据结构
typedef struct BiTNode {
	TElemType data;
	int bf;		//用于记录不平衡因子
	struct BiTNode *lchild;		
	struct BiTNode *rchild;
}*BiTree;



//初始化树
Status InitTree(BiTree *T);


//往二叉平衡树中插入不存在的节点值
Status InsertAVL(BiTree *T,TElemType key,Status *taller);



//左平衡
Status LeftBalance(BiTree *T);


//右平衡
Status RightBalance(BiTree *T);


//左旋转
void L_Rotate(BiTree *p);


//右旋转
void R_Rotate(BiTree *p);

//平衡二叉树查找
BiTree SearchTree(BiTree T,TElemType key);


//中序遍历
void InOrderTraverse(BiTree T,Status (*Visit) (TElemType));



//打印元素
Status PrintElem(TElemType elem);


