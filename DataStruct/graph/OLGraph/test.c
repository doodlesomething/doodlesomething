/*----------------------------------------------------------------------------
	* file: test.c --> test file for OLGraph
	* date:10-11-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:十字链表实现图的基本操作
	* more:十字链表仅仅能表述有向图/网,由于没有进行输入检测，在输入前
	应该想好结构,所有程序亲测
-----------------------------------------------------------------------------*/


#include <stdio.h>
#include "olgraph.h"

void main() {
	OLGraph G;
	//创建图
	CreateGraph(&G);
	//广度优先遍历
	BFSTraverse(G,PrintElem);
	printf("\n");
}
