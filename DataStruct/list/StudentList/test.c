#include <stdio.h>
#include "studentlist.h"


int main(int argc,char *argv[]) {

	int b,option;
	char number[5],name[10];
	LinkList L;

	b = 1;
	L = NULL;

	while(b) {

		printf("------------------Student Information System-------------------------\n");
		printf("	<1>Create		 <2>Add		<3>Delete\n");
		printf("	<4>Find			 <5>Length	<6>Sort\n");
		printf("	<7>Show			 <8>Destory	<9>exit\n");
		printf("Your option:");
		scanf("%d",&option);

		switch(option) {
			case 1:
				if(L == NULL) {
					printf("LinkList Create Begin:\n");
					if(CreateList(&L))
						printf("LinkList Create Success\n");
				}
				else 
					printf("The LinkList is already exists.\n");
				break;
			case 2:
				AddStudent(L);
				break;
			case 3:
				printf("please enter the student number you want to delete:");
				scanf("%s",number);
				DeleteStudent(L,number);
				break;
			case 4:
				printf("Please enter the student name:");
				scanf("%s",name);
				FindStudent(L,name);
				break;
			case 5:
				printf("There are %d students\n\n",ListLength(L));
				break;
			case 6:
				SortList(L);
				break;
			case 7:
				ShowList(L);
				break;
			case 8:
				DestoryList(&L);
				break;
			case 9:
				b=0;
				break;
			default:
				fprintf(stderr,"Unkown Option:%d\n",option);
				break;
		}
	}
}

