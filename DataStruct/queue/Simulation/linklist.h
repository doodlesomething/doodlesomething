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

typedef int Status;

typedef struct {  
	int     OccurTime;      // 事件发生的时间  
	int     NType;          // 事件类型， Qu表示到达事件，0至Qu-1表示Qu个窗口的离开事件  
}Event, ElemType;           // 事件类型，有序链表LinkList的数据元素类型  

typedef struct LNode  {  
	ElemType    data;  
	struct LNode       *next;  
}LNode, *Link, *Position;;  

typedef struct {  
	Link    head, tail;  
	int     len;  
}LinkList;  


//创建节点
Status MakeNode(Link *s,ElemType e);

//释放节点
void FreeNode(Link *p);


//初始化链表
Status InitList(LinkList *L);

//清空链表
Status ClearList(LinkList *L);

//销毁链表
Status DestoryList(LinkList *L);

//将生成的节点插入链表中
void InsFirst(LinkList *L,Link q,Link s);

//删除节点
Status DeleFirst(LinkList *L,Link h,Link *p);

//判空
Status ListEmpty(LinkList L);


//获取头结点的地址
Position GetHead(LinkList L);

//返回尾节点的地址
Position GetLast(LinkList L);

//获取当前指针的值
ElemType GetCurElem(Link p);

//将节点插入链尾
Status Append(LinkList *L,Link s);

//移除最后一个节点，并透过q返回
Status Remove(LinkList *L,Link *q);


//将s所指节点插入在p所指节点之前
Status InsBefore(LinkList *L,Link s,Link p);


//将s所指节点插入在p所指节点之后
Status InsAfter(LinkList *L,Link s,Link p);


//求链表的长度
int ListLength(LinkList L);


//更新p节点所指的值
Status SetCurElem(Link *p,ElemType elem);


//返回前驱元素的地址
Position PriorElem(LinkList L,ElemType elem,Status (*compare) (ElemType ,ElemType ));



//返回后继元素的地址
//Position NextElem(LinkList L,ElemType elem,Status (*compare) (ElemType ,ElemType ));


//定位元素,返回其地址
Status LocateElem(LinkList L,Link *p,ElemType elem,Status (*compare) (ElemType,ElemType));


//返回第i个元素的指针
Position LocatePos(LinkList L,int i);


//遍历链表
Status ListTraverse(LinkList L,void (*visit) (ElemType));


//打印元素
void print(ElemType elem);


//比较两个的元素的大小
Status compare(ElemType elem,ElemType e);



//将元素插入升序表中依然保持升序
Status OrderInsert(LinkList *L,ElemType elem,Status (*cmp) (ElemType,ElemType));

//比较两元素大小
Status cmp(ElemType elem,ElemType);
