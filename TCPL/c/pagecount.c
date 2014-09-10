/*
	date:9-10-2014
	author:doodlesomething
	version:1.0

	打印一个文件集合，每个文件都从新的一页开始打印，并且打印每个文件的标题和页数

	从文件中fgets一行 fputs到stdout中去
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100
#define TRUE 1
#define FALSE 0
#define PER_PAGE 10	//

int main(int argc,char *argv[]) {
	void printfile(char *filename);
	int i;

	if(argc == 1) {
		fprintf(stderr,"%s Usage:%s filename1 filename2 ...",argv[0],argv[0]);
		exit(1);
	}
	else  {
		for(i=1;i < argc;i++) {
			printfile(argv[i]);
		}
	}

}

void printfile(char *filename) {
	char line[MAXLEN];
	FILE *fp;
	int pagenum,linecount,isnew;
	
	isnew = TRUE;
	pagenum = 1;

	fp = fopen(filename,"r");

	if( fp == NULL) {
		fprintf(stderr,"Error:can't open file or directory %s\n",filename);
		exit(2);
	}
	else {
		while( fgets(line,MAXLEN,fp) != NULL ) {
			if(isnew) {
				printf("[%s] page:%d start\n",filename,pagenum);
				isnew = FALSE;
				linecount = 1;
			}

			fputs(line,stdout);

			if(++linecount > PER_PAGE) {
				printf("[%s] page:%d end\n\n",filename,pagenum);
				pagenum++;
				isnew = TRUE;
			}

		}
		if(!isnew) {
			printf("[%s] page:%d end\n",filename,pagenum);
		}
	}
}
