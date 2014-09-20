/*----------------------------------------------------------------
	* file:Polynominal.c 
	* date:9-19-2014
	* author: doodlesomething@163.com
	* version:1.0
	* description:线性链表实现一元多项式的相加减乘运算
-----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

int main(int argc,char *argv[]) {
	Poly Pa,Pb;
	int b,option,n;

	b = 1;
	
	while(b)  {
		printf("-----------一元多项式的运算------------------------\n");
		printf("      <0>创建A  <1>创建B   <2>相加    <3>相减  \n");
		printf("      <4>相乘   <5>打印A   <6>打印B   <7>退出  \n");
		printf("Please option the menu:");
		scanf("%d",&option);

		switch(option) {
			case 0:
				printf("Please enter the length of the PolyA:");
				scanf("%d",&n);
				CreatePoly(&Pa,n);
				break;
			case 1:
				printf("Please enter the length of the PolyB");
				scanf("%d",&n);
				CreatePoly(&Pb,n);
				break;
			case 2:
				AddPoly(&Pa,&Pb);
				break;
			case 3:
				//SubtractPoly(Pa,Pb);
				break;
			case 4:
				//MultiplyPoly(Pa,Pb);
				break;
			case 5:
				printf("PolyA:");
				PrintPoly(Pa);
				break;
			case 6:
				printf("PolyB");
				PrintPoly(Pb);
				break;
			case 7:
				b = 0;
				printf("Exiting\n");
				break;
			default:
				fprintf(stderr,"Sorry something wrong with your option:%d\n",option);
				break;
		}
	}

	exit(0);
}



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

*/
