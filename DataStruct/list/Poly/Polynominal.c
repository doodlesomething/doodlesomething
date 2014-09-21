/*----------------------------------------------------------------
	* file:Polynominal.c 
	* date:9-19-2014
	* author: doodlesomething@163.com
	* version:1.0
	* description:线性链表实现一元多项式的相加减乘运算
	* attentio :这里没有输入检测
-----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "poly.h"



/*
* @description:初始化空链表
* @param Poly Po
* @return Status
*/
Status InitList(Poly *Po) {

	Link p;
	p = (Link) malloc(sizeof(struct LNode));

	if(p != NULL) {
		p->next = NULL;
		(*Po).head = (*Po).tail = p;
		(*Po).len = 0;
		return OK;
	}
	return ERROR;
}


int ListLength(Poly Po) {
	return Po.len;
}

/*
* @description 返回头结点
* @param Poly Po
* @return Postion head
*/
Position GetHead(Poly Po){
	return Po.head;
}

/*
* @description 设置头结点的值
*/
void SetCurElem(Link h,ElemType e)  {
	h->data = e;
}



/*
* @description 创建多项式链表
* @param Poly Po
* @param int n
* @return void
*/
void CreatePoly(Poly *Po,int n) {
	InitList(Po);

	Position q,s,h;
	int i;

	term e;
	
	h = GetHead(*Po);
	e.coef = 0;
	e.expn = -1;

	SetCurElem(h,e);
	
	printf("Please enter %d coef,expn:\n",n);

	for(i = 0; i < n; i++) {
		scanf("%d,%d;",&e.coef,&e.expn);
		
		if(!LocateElem(*Po,e,&q,compare)) {
			if(MakeNode(&s,e))
				InsFirst(Po,q,s);
		}
	}
}

/*
* @description 将生成的节点插入链表中
*/
void InsFirst(Poly *Po,Link q,Link s) {
	s->next = q->next;
	q->next = s;
	
	(*Po).len++;

	if(q == (*Po).tail)
		(*Po).tail = q->next;
}

/*
* @description 为新加入的元素创建节点
*/
Status MakeNode(Link *s,ElemType e) {
	(*s) = (Link) malloc(sizeof(struct LNode));

	if( (*s) != NULL) {
		(*s)->data = e;
		(*s)->next = NULL;
		return OK;
	}

	return ERROR;
}



/*
* @description 判断该元素在P中是否存在，倘若存在则返回TRUE及该位置，否则返回第一个compare >0的前驱位置
*/
Status LocateElem(Poly Po,ElemType e,Link *q,Status (*compare) (ElemType,ElemType)) {
	Link p,pre;

	p = Po.head;

	do {
		pre = p;
		p = p->next;
	}while(p != NULL && compare(p->data,e) < 0);

	if(p == NULL || compare(p->data,e) > 0) {
		(*q) = pre;
		return FALSE;
	}
	else {
		(*q) = p;
		return TRUE;
	}
}

/*
* @description 比较ta,tb两个元素的大小
*/
Status compare(ElemType ta,ElemType tb) {
	if(ta.expn > tb.expn)
		return 1;
	else if(ta.expn == tb.expn)
		return 0;
	else 
		return -1;
}


/*
* @descrption 打印链表
*/
void PrintPoly(Poly Po) {
	Link p;

	p = Po.head->next;

	printf("\t\t系数    指数:\n");

	while(p != NULL) {
		printf("\t\t %d        %d\n",p->data.coef,p->data.expn);
		p = p->next;
	}

}


/*
* @description 二项式相加
* @param Poly *Pa
* @param Poly *Pb
* @return void
* @detail a,b多项式相加有三种情况：
	1.a的指数小于b的指数，则将a的指针向后移动，
	2.a的指数等于b的指数,则两者的系数相加的sum，
		2.1 sum等于0,则删除a,b两节点，并将两者的指针后移
		2.2 sum不等于0,则将a节点的coef更新，删除b节点，两指针后移
	3.a的指数大于b的指数，将b插入在a之前,删除b节点,指针后移
*/
void AddPoly(Poly *Pa,Poly *Pb) {
	//ha的作用类似与前驱节点，方便删除节点
	Link ha,hb,pa,pb;
	term ta,tb;
	int sum;
	
	ha = GetHead(*Pa);
	hb = GetHead(*Pb);
	
	pa = NextPos(ha);
	pb = NextPos(hb);

	while(pa && pb) {
		ta = GetCurElem(pa);
		tb = GetCurElem(pb);

		switch(compare(ta,tb)) {
			case -1:
				ha = pa;
				pa = NextPos(ha);
				break;
			case 0:
				sum = pa->data.coef + pb->data.coef;
				
				if(sum != 0) {
					pa->data.coef = sum;
					SetCurElem(pa,pa->data);
					ha = pa;
				}
				else {
					DeleFirst(Pa,ha,&pa);
					FreeNode(pa);
				}
				
				DeleFirst(Pb,hb,&pb);
				FreeNode(pb);
				pa = NextPos(ha);
				pb = NextPos(hb);
				break;
			case 1:
				printf("%d\n",DeleFirst(Pb,hb,&pb));
				InsFirst(Pa,ha,pb);
				FreeNode(pb);
				ha = NextPos(ha);
				pb = NextPos(hb);
				break;
		}
	}

	if(!ListEmpty(*Pb))
		Append(Pa,pb);
	//将Pb头结点释放
	FreeNode(hb);
}

//将剩余的链接到Pa中
void Append(Poly *Po,Link pb) {
	int i;

	i = 0;	
	(*Po).tail->next = pb;

	while(pb) {
		pb = pb->next;
		i++;
	}

	(*Po).tail = pb;
	(*Po).len += i;
}


//返回下一个节点的位置
Position NextPos(Link p) {
	return p->next;
}

//删除节点
Status DeleFirst(Poly *Po,Link h,Link *p) {
	(*p) = h->next;
	if(*p) {
		h->next = (*p)->next;
		if(!h->next)
			(*Po).tail = h;

		(*Po).len--;
		return OK;
	}
	else 
		return ERROR;

	
}

//释放节点
void FreeNode(Link p) {
	free(p);
	p = NULL;
}

//获取当前节点的值
ElemType GetCurElem(Link p) {
	return p->data;
}

/*
* @description 判空
*/
Status ListEmpty(Poly Po) {
	return Po.len > 0 ? FALSE : TRUE;
}


