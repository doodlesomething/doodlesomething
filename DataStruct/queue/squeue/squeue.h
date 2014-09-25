/*---------------------------------------------------------------------
	* file:squeue.h --> head file for squeue.c
	* date:24-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:数组实现队列的基本操作
-----------------------------------------------------------------------*/



#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define QUEUE_SIZE 3

typedef int Status;
typedef int ElemType;

typedef struct {
	int capacity;
	int font;
	int rear;
	int size;
	ElemType *elem;
}Queue;


//初始化队列
Status InitQueue(Queue *Q);

//判空
Status QueueEmpty(Queue Q);

//队列长度
int QueueLength(Queue Q);

//判满
Status QueueFull(Queue Q);

//实现循环数组
int ReSet(int value,Queue Q);

//从队尾插入元素
Status EnQueue(Queue *Q,ElemType e);

//删除队头元素
Status DeQueue(Queue *Q,ElemType *e);

//遍历队列元素
Status QueueTraverse(Queue Q,void (*visit) (ElemType));

//打印元素
void visit(ElemType elem);
