/*

date:4-9-2014
author:doodlesomething
version:2


逆波兰计算器 

如 ./expr 1 2 +
输出3

由于*在shell下会被当作当前目录下所有文件，所以用#代替

*/


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 1024


double stack[STACK_SIZE];
//栈顶指针
int stack_height = 0;

//当参数出错时，退出程序
void panic(const char *msg) {
	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}
//进栈
void push(double value) {
	if (stack_height == STACK_SIZE)
		panic("stack is too high!");
	stack[stack_height] = value;
	++stack_height;
}
//出栈
double pop(void) {
	if (stack_height == 0)
		panic("stack is empty!");
	return stack[--stack_height];
}
int main(int argc, char **argv) {
	int i;
	double value;
	for (i = 1; i < argc; ++i) {
		//这里argv相当一个二位数组
		switch (argv[i][0]) {
			case '\0':
				panic("empty command line argument");
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':

				push(atof(argv[i]));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				value = pop();
				push(pop() - value);
				break;
			case '#':
				push(pop() * pop());
				break;
			case '/':
				value = pop();
				push(pop() / value);
				break;
			default:
				panic("unknown operator");
				break;
		}
	}
	printf("%g\n", pop());
	return 0;
}
