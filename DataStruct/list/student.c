/*-------------------------------------------------------------------------
	* file:student.c
	* date:Sep-14-2014
	* author:doodlesomething -->doodlesomething@163.com
	* detail: a student information manger system
	* function :CRUD
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studentlist.h"


int main(int argc,char *argv[]) {

	int b,option;
	char number[5],name[10];
	LinkList *L;

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
				printf("LinkList Create Begin:\n");
				if(CreateList(L))
					printf("LinkList Create Success\n");
				break;
			case 2:
				AddStudent(L);
				break;
			case 3:
				scanf("%s",number);
				DeleteStudent(L,number);
				break;
			case 4:
				scanf("%s",name);
				FindeStudent(L,name);
				break;
			case 5:
				ListLength(L);
				break;
			case 6:
				SortList(L);
				break;
			case 7:
				ShowAll(L);
				break;
			case 8:
				DestoryList(L);
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

/*
* createlist to store student information
* @param LinkList *L
* @return Status
*/
Status CreateList(LinkList *L) {

}


/*
* Handle single student information  -->For CreatList()
* @param void
* @return LinkList *S
*/
LinkList *InputData(void) {
	LinkList *S;
	char number[5];

	S = NULL;
	printf("number:");
	scanf("%s",number);

	if(number[0] == '@') 
		return S;
	
	if(strlen(number) > 5)
		number[4] = '\0';

	S = (LinkList *) malloc(sizeof(struct LNode));

	if(S != NULL) {
		strcpy(S->StudentInfo.number,number);

		printf("\tname:");
		scanf("%s",&S->StudentInfo.name);

		printf("\tscore:");
		scanf("%d",&S->StudentInfo.score);
	}

	return S;
}



