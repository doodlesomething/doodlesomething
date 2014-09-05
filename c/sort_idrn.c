/*
	date:9-5-2014
	author:doodlesomething
	version:1.4

	sort -n 为进行数字转换后排序

	sort 添加 -r 参数 使用户可以选择降序排列
	sort 添加 -i 参数 用户可以选择忽略大写进行比较排序
	sort 添加 -d 参数 用户可以忽略特殊字符进行排序

	-r -i -d 可以组合使用
	-n 仅仅可以和-r组合使用
	-n 与 -i -d 组合使用的不懂，有懂的麻烦指教 doodlesomething@163.com
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLEN 1000
#define MAXLINES 1000
#define MAXBUFPSIZE 10000
#define TRUE 1
#define FALSE 0

char *lineptr[MAXLINES];

int reverse = FALSE;
int ignoreCase = FALSE;
int isPunct = FALSE;

char *lowerString(char *s);


int main(int argc,char *argv[]) {
	int readlines(char *lineptr[],int lim);
	void quicksort( void *lineptr[],int left,int right,int (*comp)(void *,void *) );
	void writelines(char *lineptr[],int nlines);
	int numcmp(const char *s1,const char *s2);
	int other_strcmp(const char *s1,const char *s2);
	int nlines;
	int isnum; //flag
	int c;

	isnum = FALSE;
	/*
	判断所带参数
	(*++argv)[0] 取得是每个参数的第一个字符(第一个参数除外)
	*++argv[0] 表示 ++ argv[0]这个指针 然后*解析取值
	*/
	while(--argc > 0 && (*++argv)[0] == '-') {
		while( c = *++argv[0] ) {
			switch(c) {
				case 'n':
					isnum = TRUE;
					break;
				case 'r':
					reverse = TRUE;
					break;
				case 'i':
					ignoreCase = TRUE;
					break;
				case 'd':
					isPunct = TRUE;
					break;
				default:
					fprintf(stderr,"invalid parmeter %s\n",*argv);
					return EXIT_FAILURE;
					break;
			}
		}
	}

	if( (nlines = readlines(lineptr,MAXLINES) ) > 1) {
		/*
		(int (*) (void *,void *))  (isnum?numcmp:strcmp )  表示将 numcmp或是strcmp
		强制类型转换为 指针类型 ，该指针指向一个带有两个void型的指针，且该函数返回int的数值
		即最后其是一个指针
		(void**) lineptr 不明白 ---》望指点
		*/
		quicksort( (void**) lineptr,0,nlines-1, (int (*)(void *,void *) ) (isnum ? numcmp:other_strcmp ) );
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

	//逆序比较的strcmp函数
	int other_strcmp(const char *s1,const char *s2) {
		int strpunctcmp(const char *str1,const char *str2);

		const char *p1 = reverse ? s2 : s1;
		const char *p2 = reverse ? s1 : s2;

		return isPunct ? strpunctcmp(p1,p2) :  ( ignoreCase ? strcasecmp(p1,p2):strcmp(p1,p2));

	}

	


	
	//忽略特殊字符的字符串比较
	int strpunctcmp(const char *str1,const char *str2) {

		int c1,c2;
		
		while( (c1 = ignoreCase ? tolower(*str1++) : *str1++) && ( c2 = ignoreCase? tolower(*str2++):*str2++) ) {
			if( ispunct(c1) )
				str1++;
			if( ispunct(c2) )
				str2++;

			if( c1 == c2 ){
				str1++;
				str2++;
			}
			else 
				break;
		}

		c1 = ignoreCase ? tolower(*str1) : *str1;
		c2 = ignoreCase ? tolower(*str2) : *str2;

		if( c1 == c2)
			return 0;
		else if( c1 > c2) 
			return 1;
		else if( c1 < c2)
			return -1;
	}

	
	/*
	这里之所以将函数参数声明为const主要是因为 三目运算符要求参数类型一致，
	strcmp原型为 int strcmp(const char *s1,const char *s2) 当然也可增加安全性
	*/
	int numcmp(const char *s1,const char *s2) {

		const char *p1 = reverse ? s2 : s1;
		const char *p2 = reverse ? s1 : s2;

		double v1,v2;

		v1 = atof(p1);
		v2 = atof(p2);

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


	/*
	测试用例(默认为降序)：
	./sort -i
	abcd
	ABcd
	>>
	abcd
	ABcd

	./sort -d
	abcd#g
	abcdg
	>>
	abcd#g
	abcdg

	./sort -id
	abcd#g
	Abcdg
	>>
	abcd#g
	Abcdg

	./sort
	abcd
	Abcd
	>>
	Abcd
	abcd

	./sort 
	abcd#g
	abcdg
	>>
	abcdg
	abcd#g

	./sort -r
	abcd
	Abcd
	>>
	abcd
	Abcd


	*/
