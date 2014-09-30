/*--------------------------------------------------------------------------
 * date:9-16-2014
 * author:doodlesomething  --> doodlesomething@163.com
 * version:1.3
 * description:实现带头结点单链表的初始化/判空/插入/删除/销毁/查找
 前驱节点和后继节点元素/元素定位/
 --------------------------------------------------------------------------*/


#include "comman.h"


//创建节点
Status MakeNode(Link *s,ElemType *e);


//初始化链表
Status InitList(LinkList *L);


//将节点插入链尾
Status Append(LinkList *L,Link s);

