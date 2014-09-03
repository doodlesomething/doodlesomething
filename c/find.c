/*
date:9-3-2014
author:doodlesomething

find -n -x pattern
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

	while(--argc > 0 && (*++argv)[0] == '-') {
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

	if( argc != 1) {
		printf("Usage:find -n -x pattern\n");
	}
	else {
		while( getLine(line,MAXLEN) >0 ) {
			linenum++;
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
