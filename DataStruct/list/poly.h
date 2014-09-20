/*----------------------------------------------------------------
	* file:poly.h -->the head file for Polynominal.c 
	* date:9-19-2014
	* author: doodlesomething@163.com
	* version:1.0
	* description:线性链表实现一元多项式的相加减乘运算
-----------------------------------------------------------------*/

#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int Status;

typedef struct {
	int coef; //系数
	int expn; //指数
} term,ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}*Link,*Position;

typedef struct {
	Link head;
	Link tail;
	int len;
} LinkList;

typedef  LinkList Poly;


Status InitList(Poly *Po);
Position GetHead(Poly Po);
void SetCurElem(Link h,ElemType e);
void CreatePoly(Poly *Po,int n);
void InsFirst(Poly *Po,Link q,Link s);
Status MakeNode(Link *s,ElemType e);
Status LocateElem(Poly Po,ElemType e,Link *q,Status (*compare) (ElemType,ElemType));
Status compare(ElemType ta,ElemType tb);
void PrintPoly(Poly Po);
void AddPoly(Poly *Pa,Poly *Pb);
