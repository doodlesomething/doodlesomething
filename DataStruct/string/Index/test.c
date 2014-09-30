/*----------------------------------------------------------------------------
	* file:test.c -->test file for BookIndex 
	* date:29-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:建立图书书目索引表
	* more:涉及串/链表操作
-----------------------------------------------------------------------------*/


#include <stdio.h>
#include "bookindex.h"


int main(int argc,char *argv[]) {
	FILE *f,*fp;

	if(! (f = fopen("booklist","r")) ) 
		printf("ERROR:can't open the file to read\n");



	InitIdxList(&IdxList);

	while(GetLine(f)) {
		/*
		书目串提取出书号放在BookNum中放回
		提取出每个单词放在wdlist中
		*/
		ExtractKeyWord(&BookNum);
		//执行插入（如果有必要插入的话）
		InsIdxList(&IdxList,&BookNum);
	}

	if( !(fp = fopen("bookindexlist","w")) ) 
		fprintf(stderr,"Can't not open the file to write\n");

	//将结果写入文件中
	PutIdxList(IdxList,fp);

	return 0;
}


