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


