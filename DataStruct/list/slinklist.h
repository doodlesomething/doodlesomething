/*----------------------------------------------------------
	* file:slinklist.h   -->head file for SLinkList.c
	* date:9-17-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:静态链表的实现，静态链表主要用在没有
	指针的高级语言中，使其可以使用链表结构
-----------------------------------------------------------*/

#define OK 1
#define ERROR 0
#define MAXSIZE 1000

typedef int ElemType;
typedef int Status;

typedef struct {
	ElemType data;
	int cur;
}SLinkList[MAXSIZE];

void InitList(SLinkList L);
int Malloc_SL(SLinkList L);
int ListLength(SLinkList L);
Status ListInsert(SLinkList L,int i,int elem);
void Free_SL(SLinkList L,int k);
Status ListDelete(SLinkList L,int i);
void ListTraverse(SLinkList L,void (*visit) (ElemType));
void visit(ElemType elem);
