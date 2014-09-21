#include <stdio.h>
#include "cirlinklist.h"

int main(int argc,char *argv[]) {
	LinkList La,Lb,ra,rb;
	char head_e,last_e,del_e;
	char c='b';
	int len;

	ra = CreateList(&La);
	rb = CreateList(&Lb);
	ListTraverse(La,visit);
	printf("\n");
	ListTraverse(Lb,visit);
	GetHead(ra,&head_e);
	GetLast(ra,&last_e);
	printf("\n head_e:%c, last_e:%c\n",head_e,last_e);
	rb = MergeList(ra,rb);
	ListTraverse(La,visit);
	printf("\n length:%d\n",ListLength(La));
	ListInsert(La,2,c);
	ListTraverse(La,visit);
	printf("\n");
	ListDelete(La,ListLength(La),&del_e);
	ListTraverse(La,visit);
	printf("%c\n",del_e);
}
