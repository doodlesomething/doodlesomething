/*----------------------------------------------------------------------------
	* file:test.c --> test file for BiThrTree.c
	* date:4-10-2014
	* author:doodlesomething@163.com
	* version:1.1
	* description:二叉树的线索化和遍历
------------------------------------------------------------------------------*/

#include <stdio.h>
#include "bithrtree.h"


int main(int argc,char *argv[]) {
	BiThrTree T,Thrt;

	if(CreateBiThrTree(&T))
		if(PreOrderThread(&Thrt,T))
			PreOrderTraverse_Thr(Thrt,PrintElem);
	printf("\n");
	
	return 0;

}

/*
	//程序已经亲测，前序/中序/后序的处理上略微不同

	测试用例结果:
	AB#D##C##
	>>
	中序遍历:BDAC

	>>
	前序遍历:ABDC

	>>
	后序遍历
*/
