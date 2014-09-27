/*---------------------------------------------------------------------------
	* file:SString.c
	* date:28-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:串的基本操作 --->使用定长顺序实现  
	* more:感觉最坑爹的是由于处理截断的问题，让程序变得十分麻烦
------------------------------------------------------------------------------*/


#include "str.h"



/*
* @description:产生一个字符串 注意数组的第一个元素为字符串长度
*/
Status StrAssign(SString *S,char *str) {
	int i;

	for(i = 1; *str != '\0';i++,str++) {
		(*S)[i] = *str;
	}
	(*S)[0] = i;

	return OK;
}

/*
* @description:求串长
*/
int StrLength(SString S) {
	return S[0];
}

/*
* @description:判空
*/
Status StrEmpty(SString S) {
	return S[0] == 0 ;
}


/*
* @description:比较两字符串
*/
Status StrCompare(SString S,SString T) {
	int i,j;
	i = j = 1;

	if(StrEmpty(S) || StrEmpty(T))
		return OVERFLOW;

	while(S[i++] == T[j++] && i <= S[0] && j <= T[0])
		;
	
	if(S[i] == T[j])
		return 0;
	else if(S[i] > T[j])
		return 1;
	else 
		return -1;
}

/*
* @description:由串S复制得串T
*/
Status StrCopy(SString S,SString *T) {
	if(StrEmpty(S))
		return ERROR;

	int i;

	for(i = 1; i <= S[0]; i++)
		(*T)[i] = S[i];

	(*T)[0] = i;

	return OK;
}


/*
* @description:用T返回S1,S2连接的串
*/
Status StrConcat(SString *T,SString S1,SString S2) {
	if(StrEmpty(S1) || StrEmpty(S2))
		return ERROR;

	int i;

	for(i = 1; i <= S1[0]; i++)
		(*T)[i] = S1[i];
	(*T)[0] = i;
	
	for(i = 1;i <= S2[0];i ++) {
		(*T)[0] += i;
		if((*T)[0] == MAXSIZE)
			break;
		(*T)[i] = S2[i];
	}
	

	return OK;
}


/*
* @description:用串Sub返回串S从第pos位置开始的长度为len的字串
*/
Status SubString(SString *Sub,SString S,int pos,int len) {
	int i,j;

	if( pos < 1 || pos + len > S[0] || len < 0)
		return ERROR;

	for(i = pos,j = 1; i <= pos+ len; i++,j++)
		(*Sub)[j] = S[i];

	return OK;
}


/*
* @description:判断在串S在的pos的元素是否存在和串T相同的字符，如果存在则返回他的位置，否则返回0
*/

int StrIndex(SString S,SString T,int pos) {
	int i,n,m;
	SString Sub;

	if(pos > 0) {
		i = pos;
		n = StrLength(S);
		m = StrLength(T);
	}
	//最多需要遍历n-m+1次，有可能不需要这么多次
	while(i < n -m +1) {
		SubString(&Sub,S,i,m);

		if(!StrCompare(T,S)) 
			return i;
		else 
			i++;
	}

	return 0;
}


/*
* @description:在串S的第pos个元素之前,插入串T
*/
Status StrInsert(SString *S,int pos,SString T) {
	int i,n,m,j,k,tmp;

	n = (*S)[0];
	m = T[0];

	if(pos < 1 || pos > (*S)[0])
		return ERROR;

	if(n + m >= MAXSIZE)
		tmp = m + n;
	else
		tmp = MAXSIZE;

	for(i = tmp ; i >= tmp - pos; i--)
		(*S)[i] = (*S)[i - m];
	for(j = pos,k = 1; j <= i && k <= m;j++,k++)
		(*S)[j] = T[k];


	return OK;
}


/*
* @description:删除第pos起长度为len的子串
*/
Status DeleStr(SString *S,int pos,int len) {
	int i;

	if(pos < 1 || pos + len > (*S)[0] || len < 1)
		return ERROR;

	for(i = pos; i < pos + len; i++) 
		(*S)[i] = '\0';
	
	if(pos + len < (*S)[0])
		for(i = pos + len;i <= (*S)[0];i++)
			(*S)[i-len] = (*S)[i];

	(*S)[0] -= len;

	return OK;
}


/*
* @description:替换S中所有与T相等不重叠的子串为V
*/
Status StrReplace(SString *S,SString T,SString V) {
	if(StrEmpty(*S) || StrEmpty(T) || StrEmpty(V))
		return ERROR;
	
	int i,j,n,m,l,pos,tmp,k;

	n =(*S)[0];
	m = T[0];
	l = V[0];
	k = 1;

	while(pos = StrIndex(*S,T,k)) {
		if(m == l) {
			for(i = pos,j = 1;i < pos + l && j < V[0];i++,j++) 
				(*S)[i] = V[j];
		}
		else if(m > l){
			for(i = pos,j = 1;i < pos + l && j < V[0];i++,j++) 
				(*S)[i] = V[j];
			for(i = pos + m; i <= n;i++)
				(*S)[i - (m-l)] = (*S)[i];
		}
		else {
			if(n-m+l <= MAXSIZE)
				tmp = n - m + l;
			else 
				tmp = MAXSIZE;

			for(i = tmp;i >= pos + l;i--)
				(*S)[i] = (*S)[i- m + l ];

			for(i = pos,j = 1; i < pos + l && j < V[0];i++,j++)
				(*S)[i] = V[j];
		}
	}

	(*S)[0] = (*S)[0] - m + l;

	return OK;
}


/*
* @description:清除串S
*/
void ClearStr(SString *S) {
	(*S)[1] = '\0';
	(*S)[0] = 0;
}

/*
* @description:销毁串S
*/
void DestoryStr(SString *S) {
	ClearStr(S);
}


/*
* @description:打印串
*/
void StrPrint(SString S) {
	int i;
	for(i = 1;i <S[0];i++)
		printf("%c",S[i]);
	printf("\n");
}
