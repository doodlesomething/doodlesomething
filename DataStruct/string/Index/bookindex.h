/*----------------------------------------------------------------------------
	* file:bookindex.h -->head file for BookInex.c 
	* date:29-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:建立图书书目索引表
	* more:涉及串/链表操作
-----------------------------------------------------------------------------*/


#include "comman.h"



/*
* @description:定义常量
*/
char *buf;	//书目串缓冲区
char chars[MaxLineLen];

WordListType wdlist;
IdxListType IdxList;
int BookNum[DataLen];	//用于存放书号



//初始化索引表
Status InitIdxList(IdxListType *IdxList);

//将每个书目串读入缓冲区
Status GetLine(FILE *fp);

//提取书号和单词提取出来
void ExtractKeyWord(int *BookNum);

//初始化词表
void InitWdList(WordListType *wdlist);

//向索引表中插入元素
Status InsIdxList(IdxListType *IdxList,int *BookNum);

//将书号插入
Status InsertBook(IdxListType *IdxList,int i,int *BookNum);

//将关键词插入
void InsertNewKey(IdxListType *IdxList,int i,HString H);

//定位关键词
int Locate(IdxListType IdxList,HString H,int *flag);

//获取单词
void GetWord(int i,HString *H);


//将结果写入文件
void PutIdxList(IdxListType IdxList,FILE *fp);


