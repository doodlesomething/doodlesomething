/*----------------------------------------------------------------------------
	* file:dlinklist.h  -->>  the head file for DLinkList.c
	* date:9-18-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:双向链表的实现
------------------------------------------------------------------------------*/

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

struct LNode {
	ElemType data;
	struct LNode *prior;
	struct LNode *next;
};

typedef struct LNode *LinkList;

Status InitLength(LinkList L);
int ListLength(LinkList L);
Status NextElem(LinkList L,ElemType elem,ElemType *next_e);
Status PriorElem(LinkList L,ElemType elem,ElemType *pre_e);
LinkList GetElemP(LinkList L,int i);
Status ListInsert(LinkList L,int i,ElemType elem);
Status ListDelete(LinkList L,int i,ElemType *elem);
void ListTraverse(LinkList L,void (*visit) (ElemType));
void visit(ElemType elem);
