/*----------------------------------------------------------
	* file:Simulation.c
	* date:25-9-2014
	* author:doodlesomething@163.com
	* version:.10
	* description:银行离散事件模拟
-----------------------------------------------------------*/


#include <stdio.h>
#include "simulation.h"


int main(int argc,char *argv[]) {
	Bank_Simulation();

	exit(0);
}

/*
* @description:银行离散事件模拟
*/
void Bank_Simulation() {
	Link p;

	OpenForDay();
	while(!ListEmpty(ev)) {
		DeleFirst(&ev,GetHead(ev),&p);
		en = GetCurElem(p);
		if(en.NType == 0)
			CustomerArrived();
		else 
			CustomerDeparture();
	}

	printf("ave time:%d\n",TotalTime/CustomerNum);
}


/*
* @description:初始化一天的业务
*/
void OpenForDay() {
	int i;

	//初始化事件链表
	InitList(&ev);

	en.NType = 0;
	en.OccurTime = 0;
	OrderInsert(&ev,en,cmp);

	for(i = 1;i < QueueNum; i++)
		InitQueue(&q[i]);
}

/*
* @description:客户到达事件处理
*/
void CustomerArrived()  {
	int duration; //客户业务处理所需时间
	int intertime;	//下一个客户到达时间间隔
	int i;
	Event et;

	QElemType qe;

	CustomerNum++;

	RandTime(&duration,&intertime);

	et.OccurTime = en.OccurTime + intertime;
	et.NType = 0;

	if(et.OccurTime < CloseTime)
		OrderInsert(&ev,et,cmp);
	
	i = MinQueue(q);

	qe.ArrivalTime = en.OccurTime;
	qe.Duration = duration;

	EnQueue(&q[i],qe);
	
	printf("customer arrive:%d 在%d号窗口 当前时间:%d  到达时间:%d 办理时间:%d  事件种类:%d\n",en.OccurTime,i,en.OccurTime,qe.ArrivalTime,qe.Duration,en.NType);

	if(QueueLength(q[i]) == 1) {
		et.OccurTime = en.OccurTime + duration;
		et.NType = i;
		OrderInsert(&ev,et,cmp);
	}
}


/*
* @description:用户离开事件
*/
void CustomerDeparture() {
	int i;
	Event et;

	i = en.NType;

	DeQueue(&q[i],&customer);
	TotalTime += en.OccurTime - customer.ArrivalTime;

	if(!QueueEmpty(q[i])) {
		GetHeadQueue(q[i],&customer);
		et.OccurTime = en.OccurTime+customer.Duration;
		et.NType = i;

		OrderInsert(&ev,et,cmp);
	}

	printf("customer leave:%d 在%d号窗口 当前时间:%d  到达时间:%d 办理时间:%d  事件种类:%d\n",en.OccurTime,i,en.OccurTime,customer.ArrivalTime,customer.Duration,en.NType);
}

/*
* @description:返回4个队列中人数最少的
*/
int MinQueue(LinkQueue q[]) {
	int tmp[5],i,k;
	
	k = 1;

	for(i = 1; i < QueueNum; i++)
		tmp[i] = QueueLength(q[i]);


	for(i = 1; i < QueueNum; i++) {
		if(tmp[1] > tmp[i]) {
			tmp[1] = tmp[i];
			k = i;
		}
	}

	return k;
}

/*
* @description:获取随机时间
*/
void RandTime(int *duration,int *intertime) {
	(*duration) = rand()%30 + 1;
	(*intertime) = rand()%5 + 1;
}



