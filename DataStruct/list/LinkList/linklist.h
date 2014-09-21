/*--------------------------------------------------------------------------
	* date:9-16-2014
	* author:doodlesomething  --> doodlesomething@163.com
	* version:1.3
	* description:实现带头结点单链表的初始化/判空/插入/删除/销毁/查找
	  前驱节点和后继节点元素/元素定位/
--------------------------------------------------------------------------*/

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define FALSE 0
#define TRUE 1

typedef int ElemType;
typedef int Status;

struct LNode {
	ElemType data;
	struct LNode *next;
};
typedef struct LNode *LinkList;


Status InitList(LinkList *L);
Status DestoryList(LinkList *L);
Status ClearList(LinkList L);
Status ListEmpty(LinkList L);
int ListLength(LinkList L);
Status GetElem(LinkList L,int i,ElemType *e);
int LocateElem(LinkList L,int e);
Status PreElem(LinkList L,ElemType cur_e,ElemType *pre_e);
Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e);
Status ListInsert(LinkList L,int i,ElemType e);
Status ListDelete(LinkList L,int i,ElemType *e);
Status ListTraverse(LinkList L,void (*vist)(ElemType));
void CreateList(LinkList *L,int n);
void CreateListReverse(LinkList *L,int n);
void UnionList(LinkList La,LinkList Lb);
void MergeList(LinkList *La,LinkList *Lb,LinkList *Lc);
void DistinctSort(LinkList L);
void ListReverse(LinkList L);
void ListReverse1(LinkList L);
void visit(ElemType elem);
void SplitList(LinkList La,LinkList Lb,LinkList Lc);
void DeleteInRange(LinkList L,ElemType min,ElemType max);
Status IsIncreasingList(LinkList L);
void DistinctList(LinkList L);
void DeleteMin(LinkList L);
