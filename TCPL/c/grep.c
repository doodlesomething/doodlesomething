
/*
	date:9-3-2014
	author:doodlesomething
	version:1.0

	function: It's a simple programming like grep

	strstr()---> <string.h>
	extern char *strstr(const char *str1,const char *str2);
*/

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000 //max length of every line

	int main(int argc,char *argv[]) {
		char lines[MAXLEN];
		int *getLine(char *s,int lim);
		int found;
		//counter
		found = 0;

		if(argc != 2) {
			printf("sorry!No pattern found\n");
		}
		else {
			while( strstr(getLine(lines,MAXLEN),argv[1]) != NULL ) {
				printf("%s",lines);
				found++;
			}
			printf("We have found %d match\n",found);
		}

		return 0;
	}

	int *getLine(char *s,int lim) {
		char c;
		char *tmp;
		
		tmp = s;
		while( (c = getchar()) != EOF && c != '\n' ) {
			*tmp++ = c;
		}

		if(c=='\n') {
			*tmp++ = c;
		}

		*tmp='\0';
		return (int) s;
	}
