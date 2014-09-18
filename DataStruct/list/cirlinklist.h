
/*--------------------------------------------------------------------
	* file:circulalist.h -->head file for CirLinkList.c 
	* date: 9-18-2014
	* author: doodlesomething@163.com
	* version:1.0
	* description:循环单链表的实现
---------------------------------------------------------------------*/

#define FLASE 0
#define TRUE 1
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef char ElemType;
typedef int Status;

struct LNode {
	ElemType data;
	struct LNode *next;
};

typedef struct LNode *LinkList;

LinkList CreateList(LinkList *L);
void ListTraverse(LinkList L,void (*visit) (ElemType));
void visit(ElemType elem);
Status GetHead(LinkList rear,ElemType *elem);
Status GetLast(LinkList rear,ElemType *elem);
LinkList MergeList(LinkList rearA,LinkList rearB);
