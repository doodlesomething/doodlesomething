/*---------------------------------------------------------------
	*file:ListStack.c
	*date:22-9-2014
	*author:doodlesomething@163.com
	*version:1.0
	*description:链栈的基本操作
----------------------------------------------------------------*/

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

typedef struct {
	ElemType data;
	ElemType *next;
}StackNode,*StackPoint;

typedef struct {
	StackPoint top;	//栈顶元素
	int len;	//栈长
} LinkStack;

//初始化链栈
void InitStack(LinkStack *S);

//进栈
Status Push(LinkStack *S,ElemType elem);

//判空
Status StackEmpty(LinkStack S);

//出栈
Status Pop(LinkStack *S,ElemType *elem);

//获取栈长
int StackLength(LinkStack S);

//遍历链栈所有元素
void StackTraverse(LinkStack S,void (*visit) (ElemType));

//打印栈顶元素
void visit(ElemType elem);

//清空链栈
void ClearStack(LinkStack *S);

//获取栈顶元素
Status GetTop(LinkStack S,ElemType *elem);

//销毁链栈
void DestoryStack(LinkStack *S);

/*
两个栈实现队列的功能
*/
//入队
void InsertQueue(LinkStack *S,ElemType elem);

//出队
ElemType DeleQueue(LinkStack *S1,LinkStack *S2);

//出队
