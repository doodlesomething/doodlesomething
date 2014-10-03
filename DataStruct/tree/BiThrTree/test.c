/*----------------------------------------------------------------------------
	* file:test.c --> test file for BiThrTree.c
	* date:3-10-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:二叉树的线索化和遍历
------------------------------------------------------------------------------*/

#include <stdio.h>
#include "bithrtree.h"


int main(int argc,char *argv[]) {
	BiThrTree T,Thrt;

	if(CreateBiThrTree(&T))
		if(InOrderThread(&Thrt,T))
			InOrderTraverse_Thr(Thrt,PrintElem);
	printf("\n");
	
	return 0;

}

/*
	测试用例结果:
	AB#D##C##
	>>
	BDAC
*/
