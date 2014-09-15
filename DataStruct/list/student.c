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


/*
* createlist to store student information
* @param LinkList *L
* @return Status
*/
Status CreateList(LinkList *L) {
	LinkList S,q;

	(*L) = (LinkList) malloc(sizeof(struct LNode));
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
LinkList InputData(void) {
	LinkList S;
	char number[5];

	S = NULL;
	printf("number:");
	scanf("%s",number);

	if(number[0] == '@') 
		return S;
	
	if(strlen(number) > 5)
		number[4] = '\0';

	S = (LinkList) malloc(sizeof(struct LNode));

	if(S != NULL) {
		strcpy(S->StudentInfo.number,number);

		printf("\tname:");
		scanf("%s",S->StudentInfo.name);

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
Status AddStudent(LinkList L) {
	LinkList p;
	p = L;
	while(p->next != NULL) 
		p = p->next;

	p->next = InputData();
	p->next->next = NULL;
	return OK;
}


/*
* Delete student information according to the student number
* @parm LinkList *L
* @param char *number
* @return Status
*/
Status DeleteStudent(LinkList L,char *number) {
	LinkList p,q;

	p = L;

	while(p != NULL) {
		if( (strcmp(p->next->StudentInfo.number,number)) == 0) {
			q = p ->next;
			p->next = q->next;
			free(q);
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
Status FindStudent(LinkList L,char *name) {
	LinkList p;
	p = L->next;

	while(p != NULL) {
		if(strcmp(p->StudentInfo.name,name) == 0) {
			printf("\tnumber \t\t name \t\t score\n");
			ShowSingle(p);
			printf("\n");
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}

/*
* show single student information -->for function FindStudent() and ShowAll()
* @param LinkList *p
* @return void
*/
void ShowSingle(LinkList p) {
	printf("\t%s \t\t %s \t\t %d\n",p->StudentInfo.number,p->StudentInfo.name,p->StudentInfo.score);
}


/*
* get the length of the linklist
* @param LinkList *L
* @return int len
*/
int ListLength(LinkList L) {
	int i;
	LinkList p;

	p = L;
	i = 0;

	if(p == NULL)
		return 0;
	else {
		while(p->next != NULL) {
			i++;
			p = p->next;
		}
		return i;
	}
}


/*
* Sort the linklist accroding to the student score -->Bubble Sort
* @param LinkList *L
* @return void
*/
void SortList(LinkList L) {
	LinkList  p,q,tmp,temp;
	p = L->next;
	//外层循环只是起到了计数的作用
	while(p != NULL) {
		q = L;
		while(q->next->next != NULL) {

			if( (q->next->StudentInfo.score > q->next->next->StudentInfo.score) ) {
				tmp = q->next;
				q->next = tmp->next;
				temp = tmp->next->next;
				tmp->next->next = tmp;
				tmp->next = temp;
			}

			q = q->next;
		}

		p = p->next;
	}
}

/*
* show all the student information
* @param LinkList *L
* @return void
*/
void ShowList(LinkList L) {
	LinkList p;
	
	p = L->next;
	printf("\tnumber \t\t name \t\t score\n");

	while(p != NULL) {
		ShowSingle(p);
		p = p->next;
	}
	printf("\n");
}

/*
* destory the linklist
* @param LinkList *L
* @return Status
*/
Status DestoryList(LinkList *L) {
	LinkList tmp;
	
	while(*L != NULL) {
		tmp = (*L)->next;
		free(*L);
		*L = tmp;
	}
	return OK;
}
