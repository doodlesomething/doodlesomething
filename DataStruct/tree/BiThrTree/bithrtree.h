/*----------------------------------------------------------------------------
	* file:bithrtree.h
	* date:3-10-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:二叉树的线索化和遍历
------------------------------------------------------------------------------*/


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2


//Link ==0 代表孩子指针  Thread == 1 代表线索
typedef enum {Link,Thread}PointerTag;

typedef int Status;

typedef char TElemType;

typedef struct BiThrNode {
	TElemType data;
	struct BiThrNode *lchild;
	struct BiThrNode *rchild;
	PointerTag LTag;
	PointerTag RTag;
}*BiThrTree;


//该指针用于指向刚刚访问过的节点
BiThrTree pre;



//前序建立二叉树
Status CreateBiThrTree(BiThrTree *T);

//为二叉树增加头结点并线索化
Status InOrderThread(BiThrTree *Thrt,BiThrTree T);

//中序遍历二叉树线索化
void InThreading(BiThrTree p);

//中序遍历二叉树
Status InOrderTraverse_Thr(BiThrTree T,Status (*Visit)(TElemType elem));

//打印节点元素
Status PrintElem(TElemType elem);

