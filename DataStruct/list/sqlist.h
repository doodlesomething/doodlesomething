/*----------------------------------------------------
	* file:Sqlist.h  -->head file for Sqlist.c
	* date:16-9-2014
	* author:doodlesomething -->doodlesomething@163.com
	* version:1.0
	* detail:使用数组实现线性表
-----------------------------------------------------*/

#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define TRUE 1
#define FLASE 0

#define LISTINITSIZE 100
#define SIZEINCREMENT 10

typedef int ElemType;
typedef int Status;

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
} Sqlist;

Status InitList(Sqlist *L);
Status ListInsert(Sqlist *L,int i,int e);
Status ListDelete(Sqlist *L,int i,ElemType *e);
int ListLength(Sqlist *L);
void DestoryList(Sqlist *L);
void ClearList(Sqlist *L);
Status ListEmpty(Sqlist *L);
Status PriorElem(Sqlist *L,ElemType e,ElemType *elem);
Status NextElem(Sqlist *L,ElemType e,ElemType *elem);
int LocateElem(Sqlist *L,ElemType e);
void ListTraverse(Sqlist *L,void (*vist)(ElemType));
void vist(ElemType);
