/*
	date:9-9-2014
	author:doodlesomething
	version:1.1

	linux tool like cat

*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {
	FILE *fp;
	void filecopy(FILE *,FILE *);
	char *progname;

	progname = argv[0];

	//命令行未传参
	if(argc == 1) {
		filecopy(stdin,stdout);
	}
	else {
		while(--argc > 0) {
			if( (fp=fopen(*++argv,"r")) == NULL) {
				fprintf(stderr,"%s:%s: No such file or directory\n",progname,*argv);
				exit(1);
			}
			else {
				filecopy(fp,stdout);
				fclose(fp);
			}
		}

		if(ferror(stdout) == 0) {
			fprintf(stderr,"%s can't writing\n",progname);
			exit(2);
		}
	}

	exit(0);
}
	//将输入或标准输入流  复制到标准输出流中
	void filecopy(FILE *ifp,FILE *ofp) {
		int c;
		while( (c=getc(ifp)) != EOF) {
			putc(c,ofp);
		}
	}
