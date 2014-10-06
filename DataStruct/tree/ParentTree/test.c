/*------------------------------------------------------------------------
	*file:test.c -->test file for ParentTree.c
	*date:10-4-2014
	*author:doodlesomething@163.com
	*version:1.0
	*description:双亲表示法建树和操作
-------------------------------------------------------------------------*/

#include <stdio.h>
#include "parenttree.h"

int main(int argc,char *argv[]) {
	PTree T;
	InitTree(&T);
	CreateTree(&T);
	PrintTree(T);
	printf("\n");
	TreeTraverse(T,PrintElem);
	Assign(&T,'5','0');
	printf("\nTreeEmpty:%d,TreeDepth:%d,Root:%c,Value:%c\n",TreeEmpty(T),TreeDepth(T),Root(T),Value(T,1));
	printf("Root:%c, Parent:%c, LeftChild:%c, RightSibling:%c, LeftSibling:%c\n",Root(T),Parent(T,'2'),LeftChild(T,'2'),RightSibling(T,'2'),LeftSibling(T,'3'));
	return 0;
}
