/*
	date:9-4-2014
	author:doodlesomething
	version:1.0

	tail -- linux tool

	how:
	1.read lines;
	2.write lines;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAXLINES 1000	//define the maxsize of input lines
#define MAXBUFPSIZE 50000 //define the maxsize of bufp

#define MAXLEN 1000 //the maxsize of evey line

char *lineptr[MAXLINES];  //to store the pointers of lines

int readlines(char *lineptr[],int lim);
void writelines(char *lineptr[],int nlines,int n);



//main function 
int main(int argc,char *argv[]) {
	int nlines;
	int n;
	
	n=3;

	//when the nlines bigger than 1 we sort the lines
	if( (nlines = readlines(lineptr,MAXLINES) ) >0) {
		//没输入参数时
		if(argc==1) 
			writelines(lineptr,nlines,n);
		else {
			if( (*++argv)[0] == '-') {
				n=atoi(++argv[0]);
				writelines(lineptr,nlines,n);
			}
			else {
				printf("Usage:tail -n\n");
			}
		}
	}
	else 
		printf("No input line to tail\n");
	

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



	//write line string
	void writelines(char *lineptr[],int nlines,int n) {
		printf("\n");
		//如果所输入的参数大于总行数时
		if(n>nlines) 
			n=nlines;

		while( (n--) > 0) {
			printf("%s\n",  lineptr[nlines-1-n] );
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

