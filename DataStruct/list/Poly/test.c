#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

int main(int argc,char *argv[]) {
	Poly Pa,Pb;
	int b,option,n;

	b = 1;
	
	while(b)  {
		printf("-----------一元多项式的运算------------------------\n");
		printf("      <0>创建A  <1>创建B   <2>相加     \n");
		printf("        <5>打印A   <6>打印B   <7>退出  \n");
		printf("Please option the menu:");
		scanf("%d",&option);

		switch(option) {
			case 0:
				printf("Please enter the length of the PolyA:");
				scanf("%d",&n);
				CreatePoly(&Pa,n);
				break;
			case 1:
				printf("Please enter the length of the PolyB");
				scanf("%d",&n);
				CreatePoly(&Pb,n);
				break;
			case 2:
				AddPoly(&Pa,&Pb);
				break;
			case 3:
				//SubtractPoly(Pa,Pb);
				break;
			case 4:
				//MultiplyPoly(Pa,Pb);
				break;
			case 5:
				printf("PolyA:");
				PrintPoly(Pa);
				break;
			case 6:
				printf("PolyB");
				PrintPoly(Pb);
				break;
			case 7:
				b = 0;
				printf("Exiting\n");
				break;
			default:
				fprintf(stderr,"Sorry something wrong with your option:%d\n",option);
				break;
		}
	}

	exit(0);
}

