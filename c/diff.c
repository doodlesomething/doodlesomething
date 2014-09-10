/*
  date:9-10-2014
  author:doodlesomething
  version:1.0

  比较两个文件并打印他们第一个不相同的行
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1000


int main(int argc,char *argv[]) {
	int getLine(char *line,int lim,FILE *fp);
	char line_1[MAXLEN];
	char line_2[MAXLEN];
	FILE *fp1,*fp2;
	char *prog;
	int i;


	prog = argv[0];
	i = 0;

	if(argc != 3) {
		fprintf(stderr,"%s:Usage:./differ filename1 filename2\n",prog);
		exit(1);
	}
	else {
		fp1 = fopen(argv[1],"r");
		if(fp1 == NULL) {
			fprintf(stderr,"Error:%s can't open file or directory %s\n",prog,argv[1]);
			exit(1);
		}

		fp2 = fopen(argv[2],"r");
		if(fp2 == NULL) {
			fprintf(stderr,"Error:%s can't open file or directory %s\n",prog,argv[2]);
			exit(1);
		}

		while( (fgets(line_1,MAXLEN,fp1)) != NULL && (fgets(line_2,MAXLEN,fp2)) != NULL) {
			if( strcmp(line_1,line_2) !=0 ) {
				printf("filename:%s linenum:%d  difference:%s",argv[1],i,line_1);
				printf("filename:%s linenum:%d  difference:%s",argv[2],i,line_2);
				exit(0);
			}

			i++;
		}
	}

	exit(0);
}


