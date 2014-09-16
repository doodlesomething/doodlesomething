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
