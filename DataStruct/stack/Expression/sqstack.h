/*-------------------------------------------------------------------
	* file:sqstack.h -->the head file for SqStack.c
	* date:22-9-2014
	* author:doodlesomething@163.com
	* version:.1.0
	* description:实现顺序栈的基本操作
--------------------------------------------------------------------*/

#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1
#define OVERFLOW -2

#define INTSIZE 100  //栈的初始化空间
#define INCREMENT_SIZE 10  //每次分配内存空间的增长量

typedef int SElemType;
typedef int Status;

typedef struct {
	SElemType *top;  //栈顶指针	
	SElemType *base;  //栈底指针
	int stacksize;   //栈的大小
}SqStack;


//初始化栈
Status InitStack1(SqStack *S);


//进栈
Status Push1(SqStack *S,SElemType elem);

//出栈
Status Pop1(SqStack *S,SElemType *elem);

//获取栈顶元素(不弹出)
Status GetTop1(SqStack S,SElemType *elem);

