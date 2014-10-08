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


typedef char TElemType;


typedef struct Node {
	TElemType data;
	struct Node *lchild;
	struct Node *rchild;
}*SElemType;


typedef struct {
	SElemType data;
	SElemType *next;
}StackNode,*StackPoint;

typedef struct {
	StackPoint top;	//栈顶元素
	int len;	//栈长
} LinkStack;

//初始化链栈
void InitStack(LinkStack *S);

//进栈
Status Push(LinkStack *S,SElemType elem);

//判空
Status StackEmpty(LinkStack S);

//出栈
Status Pop(LinkStack *S,SElemType *elem);


//清空链栈
void ClearStack(LinkStack *S);

//获取栈顶元素
Status GetTop(LinkStack S,SElemType *elem);
