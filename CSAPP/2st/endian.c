/*--------------------------------------------------------------------------------
	* FileName:endian.c
	* author:doodlesomething@163.com
	* date:11-5-2014
	* version:1.0
	* description:大端和小端问题
----------------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>


/*
* @description:下面是比较神奇的方式判断
* @more:巧妙的运用了联合的特点,并使用了宏定义
*/
static union {
	char c[4];
	unsigned long l;
}endian_test = {{'l','?','?','b'}};


#define ENDIANS ((char) endian_test.l) 






/*
* @description:下面是使用具体的数据分析的方式判断是存储的大小端方式
*/

typedef unsigned char *byte_pointer;


//print normal
void show_normal(int n) {
	printf(" 0x%x\n",n);
}


//print
void show_bytes(byte_pointer start,int len) {
	int i;
	for(i = 0; i < len ; i++)
		printf(" %.2x",start[i]);
	
	printf("\n");
}

//int 
void show_int(int x) {
	show_bytes((byte_pointer) &x,sizeof(int));
}

//float
void show_float(float x) {
	show_bytes((byte_pointer) &x,sizeof(float));
}

//void *
void show_void(void *x) {
	show_bytes((byte_pointer) &x,sizeof(void *));
}

//test
void test_show(int value) {
	int ivalue = value;
	float fvalue = (float) ivalue;
	int *pvalue = &ivalue;

	show_normal(value);
	show_int(ivalue);
	show_float(fvalue);
	show_void(pvalue);
}



int main(int argc,char **argv) {

	// detail show
	if(argc == 3) {
		if(argv[1][0] == '-') {
			if(argv[1][1] == 'i') 
				test_show(atoi(argv[2]));
			else if(argv[1][1] == 'f') 
				test_show(atof(argv[2]));
			else if(argv[1][1] == 's')
				show_bytes(argv[2],strlen(argv[2]));
			else 
			fprintf(stderr,"Error:./endian number\n");
		}
		else 
			fprintf(stderr,"Error:./endian number\n");
	}
	else {
		fprintf(stderr,"Error:./endian number\n");
	}

	//jude the endian mode
	if(ENDIANS == 'l') {
		printf(" little endian\n");
	}
	else if(ENDIANS == 'b') {
		printf(" big endian\n");
	}
	else {
		fprintf(stderr," erorr\n");
	}


	return 0;
}



/*
test:


Input:
$ ./endian -i 12345


Output:
0x3039
39 30 00 00 
00 e4 40 4a
74 bf ca bf   这是随机的
little endian


可以看出来在linux下是小端的存储模式


*/



