/*---------------------------------------------------------------
	* file:linkqueue.h -->head file for LinkQueue.c and test.c 
	* date:25-9-2014
	* author:doodlesomething@163.com
	* version:.1.0
	* description:链队的基本操作
----------------------------------------------------------------*/


#define  TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;


typedef	struct  {  
    int ArrivalTime;        // 到达时间  
    int Duration;           // 办理事件  
}QElemType;                     // 定义队列的数据元素类型  
  
// 单链队列－－队列的链式存储结构  
typedef struct QNode  {  
    QElemType     data;  
    struct QNode  *next;  
}*QueuePtr;  
  
typedef struct  
{  
    QueuePtr    font, rear;    // 队头、队尾指针  
}LinkQueue;  
  

//初始化队列
Status InitQueue(LinkQueue *Q);

//判空
Status QueueEmpty(LinkQueue Q);

//返回长度
int QueueLength(LinkQueue Q);

//返回队头元素
Status GetHeadQueue(LinkQueue Q,QElemType *elem);

//入队
Status EnQueue(LinkQueue *Q,QElemType elem);

//出队
Status DeQueue(LinkQueue *Q,QElemType *elem);

//销毁队列
void DestoryQueue(LinkQueue *Q);

//清空队列
void ClearQueue(LinkQueue Q);

//遍历数组 
Status QueueTraverse(LinkQueue Q,void (*visit) (QElemType));

//打印元素
void visitQueue(QElemType elem);
