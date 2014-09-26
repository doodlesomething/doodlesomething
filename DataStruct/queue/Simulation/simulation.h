/*----------------------------------------------------------
	* file:simulation.h -->head file for Simulation.c
	* date:25-9-2014
	* author:doodlesomething@163.com
	* version:.10
	* description:银行离散事件模拟
-----------------------------------------------------------*/

#include <stdlib.h>
#include "linklist.h"
#include "linkqueue.h"


typedef LinkList EventList;

#define SPTIME 5  //最大相隔时间
#define BSTIME 30 //最大业务时间
#define CloseTime 10 //银行关门时间
#define QueueNum 5 //"队列书目"


/*
全局变量
*/

EventList ev;	//用于存储用户事件的链表
Event en; 	//当前发生的事件类型,et为临时存储变量
LinkQueue q[QueueNum];	 //为了区分第0个事件，队列数组从1开始
QElemType customer;
int TotalTime,CustomerNum;

//银行离散事件模拟
void Bank_Simulation();

//初始化一天的业务
void OpenForDay();

//客户到达
void CustomerArrived();

//客户离开
void CustomerDeparture();

//获取最小队列
int MinQueue(LinkQueue q[]);

//随机时间
void RandTime(int *duration,int *intertime);

