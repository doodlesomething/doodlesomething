/*--------------------------------------------------------------------------------------
	* FileName:HashTable.c
	* date:10-21-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:哈希表的建立/重建/查找
	* more:冲突处理采用开放地址法:Hi = (H(key) + di) mod m 
----------------------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"



int m = 0;	//哈希表的容量

//哈希表容量递增表，为一个合适的素数序列
int hashsize[] = {19,29,37,41,59,79,107,2333};


/*
* @description:初始化哈希表
*/
Status InitHTable(HashTable *H) {
	int i;
	(*H).count = 0;
	//哈希表容量中第一个作为哈希表的初始容量
	(*H).sizeindex = 0;	//hashsize[sizeindex]为当前哈希表容量
	m = hashsize[0];
	(*H).elem = (ElemType *) malloc( m * sizeof(ElemType));
	if(!(*H).elem)
		exit(OVERFLOW);

	//将哈希表中元素全部初始化为零
	for(i = 0; i < m; i++ )
		(*H).elem[i].key = NULLKEY;
	
	return SUCCESS;
}



/*
* @description:在哈希表中查找，主要配合插入操作
* @more:在开放地址哈希表中查找关键词，若查找成功，
	以p指示待查数据在表中的位置，并且返回查询成功
	若查询失败，则返回应该插入位置
*/
Status SearchHash(HashTable H,KeyType key,int *p, int *c) {
	//求哈希地址
	*p = Hash(key);
	//向插入的位置已经有元素且不等于插入的关键词本身
	while(H.elem[*p].key != NULLKEY && H.elem[*p].key != key) {
		(*c)++;
		if((*c) < m)
			//产生冲突，则探寻下一个可能的位置
			collision(p,*c);
		else
			break;
	}
	
	//查找成功
	if(H.elem[*p].key == key)
		return SUCCESS;
	else
		return UNSUCCESS;
}


/*
* @description:求哈希值
* @more:可根据实际情况来选择更合适的
*/
unsigned Hash(KeyType key) {
	return key % m;
}

/*
* @description:冲突处理函数，这里使用开放地址法
*/
void collision(int *p,int c) {
	*p = (*p + c) % m;
}

/*
* @description:哈希表插入元素
*/
Status InsertHash(HashTable *H,KeyType key) {
	int c,p;
	//用于计数，也用作步长
	c =  0;
	if(SearchHash(*H,key,&p,&c))
		return DUPLICATE;
	/*
	产生冲突但是冲突次数没有达到上限
	这里的上限是可以调整，根据实际情况来设定
	*/
	else if(c < hashsize[(*H).sizeindex] / 2) {
		//插入
		(*H).elem[p].key = key;
		(*H).count++;
		return SUCCESS;
	}
	//冲突次数超过了上限，故需要重建哈希表即进行扩容
	else {
		RecreateHash(H);
		return UNSUCCESS;
	}

}


/*
* @description:重建哈希表，即进行扩容
*/
void RecreateHash(HashTable *H) {
	int i,count;
	ElemType *p,*elem;

	count = (*H).count;
	elem = (ElemType *) malloc (count * sizeof(ElemType));

	if(!elem)
		exit(OVERFLOW);
	
	//将现在哈希表中的元素暂存到elem中
	for(i = 0 ; i < m ; i++) 
		if((*H).elem[i].key != NULLKEY)
			*elem = *((*H).elem + i);

	(*H).count = 0;
	(*H).sizeindex++;
	m = hashsize[(*H).sizeindex];
	p = (ElemType *) realloc ((*H).elem, m * sizeof(ElemType));
	if(!p)
		exit(OVERFLOW);

	(*H).elem = p;
	//初始化新哈希表中元素值
	for(i = 0; i < m ; i++) 
		(*H).elem[i].key = NULLKEY;

	//将元素插入到新的哈希表中
	for(p = elem ; p < elem + count ; p++)
		InsertHash(H,(*p).key);
}



/*
* @description:遍历输出
*/
void TraverseHTable(HashTable H,void (*Visit) (KeyType)) {
	int i;
	for(i = 0; i < m ; i++)
		if(H.elem[i].key != NULLKEY)
			Visit(H.elem[i].key);
}


/*
* @description:打印元素值
*/
void PrintElem(KeyType key) {
	printf("%d\t",key);
}


