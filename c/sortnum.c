/*
	date:9-5-2014
	author:doodlesomething
	version:1.1

	sort -n

排序函数(排序字符串),在给定可选参数-n 的情况下,该函数将按数值大小而非字典顺序对输入行进行排序
排序程序通常包括 3 部分:判断任何两个对象之间次序的比较操作、颠倒对象次序的交
换操作、一个用于比较和交换对象直到所有对象都按正确次序排列的排序算法。由于排序算
法与比较、交换操作无关,因此,通过在排序算法中调用不同的比较和交换函数,便可以实
现按照不同的标准排序
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1000
#define MAXLINES 1000
#define MAXBUFPSIZE 10000

char *lineptr[MAXLINES];


int main(int argc,char *argv[]) {
	int readlines(char *lineptr[],int lim);
	void quicksort( void *lineptr[],int left,int right,int (*comp)(void *,void *) );
	void writelines(char *lineptr[],int nlines);
	int numcmp(const char *s1,const char *s2);
	int nlines;
	int isnum; //flag

	isnum = 0;
	//带有-n参数
	if(argc > 1 && strcmp(argv[1],"-n") == 0 ) {
		isnum=1;
	}
	

	if( (nlines = readlines(lineptr,MAXLINES) ) > 1) {
		/*
		(int (*) (void *,void *))  (isnum?numcmp:strcmp )  表示将 numcmp或是strcmp
		强制类型转换为 指针类型 ，该指针指向一个带有两个void型的指针，且该函数返回int的数值
		即最后其是一个指针
		(void**) lineptr 不明白 ---》望指点
		*/
		quicksort( (void**) lineptr,0,nlines-1, (int (*)(void *,void *) ) (isnum ? numcmp:strcmp ) );
		writelines(lineptr,nlines);
	}
	else {
		printf("Something wrong");
	}

	return 0;
}
	/*
	将单行收集，并用指针数组的方式存储
	*/
	int readlines(char *lineptr[],int lim) {
		int len;
		char line[MAXLEN];
		char *p;
		int nlines;
		int getLine(char *s,int lim);
		char *alloc(int n);

		nlines=0;

		while( (len = getLine(line,MAXLEN) ) >0 ) {
			if( nlines>lim || (p=alloc(len)) == NULL ) {
				return -1;
			}
			else  {
				line[len-1]='\0';
				strcpy(p,line);
				lineptr[nlines++]=p;
			}
		}

		return nlines;
	}

	/*
	排序：快速排序法
	*/
	void quicksort(void *lineptr[],int left,int right, int (*comp) (void *,void *) ) {

		int i,last;

		void swap(void *v[],int i,int j);

		if(left >= right) 
			return;
		swap(lineptr,left,(left+right)/2 );
		
		last = left;
		//找到last的位置
		for(i = left+1;i <= right;i++ ) {
			if( (*comp)(lineptr[i],lineptr[left]) < 0 ) {
				swap(lineptr,++last,i);
			}
		}

		swap(lineptr,left,last);
		quicksort(lineptr,left,last-1,comp);
		quicksort(lineptr,last+1,right,comp);
	}
	
	/*
	这里之所以将函数参数声明为const主要是因为 三目运算符要求参数类型一致，
	strcmp原型为 int strcmp(const char *s1,const char *s2) 当然也可增加安全性
	*/
	int numcmp(const char *s1,const char *s2) {
		double v1,v2;

		v1=atof(s1);
		v2=atof(s2);

		if(v1<v2)
			return -1;
		else if(v1>v2)
			return 1;
		else 
			return 0;
	}
	//交换两元素指针，以减少内存开销和元素的移动
	void swap(void *v[],int i,int j) {
		void *tmp;
		tmp=v[i];
		v[i]=v[j];
		v[j]=tmp;
	}

	//获取单行
	int getLine(char *s,int lim) {
		char *tmp;
		int c;

		tmp=s;

		while(--lim > 0 && (c=getchar()) !=EOF && c != '\n') 
			*tmp++ = c;
		if(c == '\n')
			*tmp++ = c;
		*tmp = '\0';

		return (int) (tmp-s);
	}

	void writelines(char *lineptr[],int nlines) {
		printf("\n");

		while( (nlines--) > 0) {
			printf("%s\n",*lineptr++);
		}
	}


	//缓冲区
	static char buf[MAXBUFPSIZE];
	//栈顶指针
	static char *bufp=buf;

	//ask for stack
	char *alloc(int n) {
		if(n > 0 && (buf+MAXBUFPSIZE-bufp) > n ) {
			bufp=bufp+n;
			return bufp-n;
		}
		else {
			return -1;
		}
	}
