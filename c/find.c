/*
date:9-3-2014
author:doodlesomething

find -n -x pattern

程序带两个可选参数。其中一个参数表示“打印除匹配模式之外的所有行”
,另一个参数表示“每个打印的文本行前面加上相应的行号”
可选参数应该允许以任意次序出现,同时,程序的其余部分应该与命令行中参数的数目无关


 */

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000


int main(int argc,char *argv[]) {

	char line[MAXLEN];
	int x;	//flag for except or not except; the value of it 1 or 0
	int n;  //flag for show linenum or not
	int linenum;  //the number of lines
	int c;
	int getLine(char *s,int lim);

	x = 0;
	n = 0;
	linenum = 0;
	
	/*
	这里的(*++argv)[0]取到的是每个参数的第一个字符（第一个参数除外）
	(*++argv) 类似取到了一个字符数组
	*/
	while(--argc > 0 && (*++argv)[0] == '-') {
		/*
		*++argv[0]  由于上面的while中argv会自增，这里取到的argv[0]是一个指针
		是一个字符指针，指向对应的字符串，++该指针即遍历该参数（除-外）中的每个字符
		*/
		while(c = *++argv[0]) {
			switch(c) {
				case 'x':
					x=1;
					break;
				case 'n':
					n=1;
					break;
				default:
					printf("Usage:find -n -x pattern \n");
					argc=0;
					break;
			}
		}
	}
	/*
	当输入后面不跟任何参数时，此处argc=0
	在参数不出错的情况下，argc必然为1
	*/
	if( argc != 1) {
		printf("Usage:find -n -x pattern\n");
	}
	else {
		while( getLine(line,MAXLEN) >0 ) {
			linenum++;
			/*
			当带有-x时,如果匹配则条件为 1 !=1,反之不匹配则条件为 0 != 1(满足，则打印不匹配的);
			当不带-x时，如果匹配则条件为 1 != 0 (满足，则打印匹配的)
			*/
			if( (strstr(line,*argv) != NULL) != x) {
				if(n) {
					printf("%d:",linenum);
				}
				printf("%s",line);
			}
		}
	}

	return 0;
}

int getLine(char *s,int lim) {
	char *tmp;
	char c;

	tmp = s;

	while( (c = getchar()) != EOF && c != '\n') {
		*tmp++=c;
	}

	if(c == '\n') {
		*tmp++=c;
	}
	*tmp='\0';

	return (int) (tmp-s);
}
