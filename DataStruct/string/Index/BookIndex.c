/*----------------------------------------------------------------------------
	* file:BookIndex.c 
	* date:29-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:建立图书书目索引表
	* more:涉及串/链表操作
-----------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bookindex.h"


/*
* @description:初始化书目索引表
*/
Status InitIdxList(IdxListType *IdxList) {
	InitStr(&(*IdxList).item[0].key);
	InitList(&(*IdxList).item[0].bnolist);
	(*IdxList).len = 0;
}


/*
* @description:将每个书目串读入缓冲区中
*/
Status GetLine(FILE *fp) {
	buf = chars;

	return fgets(buf,MaxLineLen,fp);

}


/*
* @param int *BookNum
* @param void
* @description:书目串提取出书号放在BookNum中返回
		提取出每个单词放在wdlist中
*/
void ExtractKeyWord(int *BookNum) {
	int i,j,k;
	char *c;

	//过滤书号前面的空格
	while(*buf == ' ')
		buf++;
	//提取书号
	for(i = 0; i < DataLen;i++) { 
		BookNum[i] = *buf-'0';
		buf++;
	}


	
	InitWdList(&wdlist);

		//提取单词	
	for(j =0; *buf != '\0'  && j < MaxWordNum; j++) {
	//过滤书号和单词间空格

		while(*buf == ' ')
			buf++;
		for(k =0;*buf != ' ' && k < MaxWordLen; k++)  {
			wdlist.item[j][k] = tolower(*buf);
			buf++;
		}
		if(*buf == '\0')
			break;
		
		wdlist.len++;
	}
}

/*
* @param WordListType *wdlist
* @return void
* @description:初始化词表
*/
void InitWdList(WordListType *wdlist) {
	int i,k;

	for(i =0;i < MaxWordNum;i++) {
		(*wdlist).item[i] = (char *) malloc(MaxWordLen * sizeof(char));
		for(k =0;k < MaxWordLen;k++)
			(*wdlist).item[i][k] = '\0';
	}	

	(*wdlist).len = 0;
}


/*
* @param IdxListType *IdxList
* @param int BookNum
* @return Status
* @description:向索引表中插入元素，如果需要的话 -->注意这里的索引表为有序表
*/
Status InsIdxList(IdxListType *IdxList,int *BookNum) {
	int i,j,flag;
	HString H;

	for(i = 0;i < wdlist.len;i++) {
		//从串词表中获取一个单词
		GetWord(i,&H);
		//判断该词是否在索引表中和位置
		j = Locate(*IdxList,H,&flag);

		//若该词不再索引表中则插入关键词
		if(!flag)
			InsertNewKey(IdxList,j,H);

		//插入书号
		if(!InsertBook(IdxList,j,BookNum))
			exit(OVERFLOW);
	}

	return OK;
}


/*
* @param IdxListType *IdxList
* @param int i;
* @param int BookNum
* @description:在对应关键词中插入书号
*/
Status InsertBook(IdxListType *IdxList,int i,int *BookNum) {
	Link p;

	if(!MakeNode(&p,BookNum))
		return ERROR;

	Append(&(*IdxList).item[i].bnolist,p);

	return OK;
}




/*
* @param HString H
* @param IdxListType *IdxList
* @param int j
* @description:插入关键词 
*/
void InsertNewKey(IdxListType *IdxList,int i,HString H) {
	int j;
	//后移元素
	for(j = (*IdxList).len - 1;j >= i; j--)
		(*IdxList).item[j+1] =(*IdxList).item[j]; 
	//插入元素
	StrCopy(&(*IdxList).item[i].key,H);
	(*IdxList).len++;

	//别忘初始化书号链表
	InitList(&(*IdxList).item[i].bnolist);
}



/*
* @param IdxListType IdxList
* @param HString H
* @param int *flag
* @description:查询在索引表是否存在，如果存在则返回所在位置且将flag置为TRUE
		倘若不存在则返回插入位置，将flag置为FALSE
*/
int Locate(IdxListType IdxList,HString H,int *flag) {
	int m,i;

	for(i = IdxList.len -1; (m = StrCompare(IdxList.item[i].key,H)) > 0; i--)
		;

	//找到匹配项
	if(m == 0) {
		(*flag) = TRUE;
		return i;
	}
	else {
		(*flag) = FALSE;
		return i + 1;
	}
}

/*
* @param int i
* @param HString *H
* @return void
* @description:从串词表中获取一个单词
*/
void GetWord(int i,HString *H) {
	char *p;
	//到对应的单词
	p = *(wdlist.item + i);

	StrAssign(H,p);
}


/*
* @description:将结果写入到文件中
*/
void PutIdxList(IdxListType IdxList,FILE *fp) {
	int i,j;
	Link p;

	for(i = 0; i < IdxList.len; i++) {
		fprintf(fp,"%-20s",IdxList.item[i].key.elem);
		p = IdxList.item[i].bnolist.head->next;

		while(p) {
			for(j =0;j < DataLen;j++)
				fprintf(fp,"%d",p->data[j]);
			if(p->next)
				fprintf(fp,",");

			p = p->next;
		}
		
		fprintf(fp,"\n");
	}
}
