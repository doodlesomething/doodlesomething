/*
	date:9-2-2014
	author:doodlesomething
	version:1.0

	sort strings as linux tool

	how:
	1.read lines;
	2.sort lines;
	3.write lines;
*/

#include <stdio.h>
#include <string.h>

#define MAXLINES 1000	//define the maxsize of input lines
#define MAXBUFPSIZE 50000 //define the maxsize of bufp

#define MAXLEN 1000 //the maxsize of evey line

char *lineptr[MAXLINES];  //to store the pointers of lines

int readlines(char *lineptr[],int lim);
void writelines(char *lineptr[],int nlines);

void qsort(char *lineptr[],int left,int right);


//main function 
int main() {
	int nlines; 	//the number of all input lines
	//when the nlines bigger than 1 we sort the lines
	if( (nlines = readlines(lineptr,MAXLINES) ) >0) {
		qsort(lineptr,0,nlines-1);
		writelines(lineptr,nlines);
		return 0;
	}
	else {
		printf("the input line is too big!Sorry we can not handle it\n");
		return 1;
	}
	return 0;
}

	//read line string
	int readlines(char *lineptr[],int lim)	{
		int len,inlines;
		char *p;
		char line[MAXLEN];
		int getLine(char *line,int lim);
		char *alloc(int n);
	
		inlines = 0;
		
		while( (len = getLine(line,MAXLEN)) > 0 ) {
			if( inlines > lim ||  ( p = alloc(len) ) == NULL ) 
				return -1;
			else {
				/*
				the end of input line is '\n',and we should store it
				as a string so we can should add a flag '\0' end of a string array
				*/
				line[len-1]='\0';  
				strcpy(p,line);
				lineptr[inlines++]=p;
			}
		}

		return inlines;
	}


	//quick sort the lines -- key code
	void qsort(char *lineptr[],int left,int right) {
		int last,i;
		void swap(char *v[],int i,int j);
		//if the lines fewer than two
		if(left >= right)
			return;
		
		swap(lineptr,left,(left+right)/2);

		last = left;

		for(i=left+1;i <= right;i++) {
			if( strcmp(lineptr[i],lineptr[left]) <0 )
				swap(lineptr,++last,i);
		}
		
		swap(lineptr,left,last);
		qsort(lineptr,left,last-1);
		qsort(lineptr,last+1,right);
	}

	//swap pointer
	void swap(char *v[],int i,int j) {
		char *tmp;
		tmp=v[i];
		v[i]=v[j];
		v[j]=tmp;
	}

	//write line string
	void writelines(char *lineptr[],int nlines) {
		printf("\nThe result is :\n\n");
		while(nlines-- >0) {
			printf("%s\n",*lineptr++ );
		}
	}

	//get the single line
	int getLine(char *line,int lim) {
		int c;
		char *tmp;

		tmp = line;
		
		while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
			*tmp++=c;
		/*
		在开始程序时，我的代码如下：
		if(c == '\n')
			*tmp=c;
		*++tmp='\0';
		这样无论怎样输入回车加上ctrl+d，tmp的值为1 
		函数的最后返回值都大于零，无法结束输入
		*/

		if(c == '\n')
			*tmp++= c;

		*tmp= '\0';



		//return the length of line
		return (int) (tmp-line);
	}
	
	//buf
	static char buf[MAXBUFPSIZE];
	static char *bufp = buf;

	//ask for buf
	char *alloc(int n) {
		if(n > 0 && (buf + MAXBUFPSIZE - bufp) >= n) {
			bufp = bufp + n;
			return (bufp - n);
		}
		else 
			return 0;
	}

	/*
	测试用例：
	bcd
	vad
	abcdgd
	drejoreiwr3
	>>
	abcdgd
	bcd
	drejoreiwr3
	vad
	*/

