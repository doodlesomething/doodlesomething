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
	LinkList L;

	b = 1;

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
				if(CreateList(&L))
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
	LinkList *S,*q;

	(*L) = (LinkList *) malloc(sizeof(struct LNode));
	q = *L;
	
	while(1) {
		S = InputData();
		if(S == NULL) 
			return ERROR;
		q->next = S;
		q = S;
	}

	q->next = NULL;

	return OK;
}


/*
* Handle single student information  -->For CreatList() and AddStudent()
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


/*
* Add Student Information on the tail
* @param LinkList *L
* @return Status
*/
Status AddStudent(LinkList *L) {
	LinkList *p;
	p = L->next;
	while(p != NULL) 
		p = p->next;

	p = InputData();
	if(p != NULL)
		p->next = NULL;
	else 
		return ERROR;

	return OK;
}


/*
* Delete student information according to the student number
* @parm LinkList *L
* @param char *number
* @return Status
*/
Status DeleteStudent(LinkList *L,char *number) {
	LinkList *p,*q;

	p = L->next;

	while(p->next != NULL) {
		if( (strcmp(p->StudentInfo.number,number)) == 0) {
			p = p ->next;
			return OK;
		}
		p = p->next;
	}

	return ERROR;
}

/*
* find the student information according to the student name
* @param LinkList *L
* @param char *name
* @return Status
*/
Status FindStudent(LinkList *L,char *name) {

}

/*
* show single student information -->for function FindStudent() and ShowAll()
* @param LinkList *p
* @return void
*/
void ShowSingle(LinkList *p) {

	printf("");
}
