
/*-------------------------------------------------------------------------
	* file:studentlist.h  -->this a file for student.c
	* date:Sep-14-2014
	* author:doodlesomething -->doodlesomething@163.com
	* detail: a student information manger system
	* function :CRUD
--------------------------------------------------------------------------*/

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0


typedef  int ElemType;
typedef  int Status;

typedef struct student  {
	char number[5];
	char name[10];
	ElemType score;
}Student;

typedef struct LNode {
	struct LNode *next;
	Student StudentInfo;
};

typedef struct LNode *LinkList;

Status CreateList(LinkList *L);
LinkList *InputData(void);
Status AddStudent(LinkList *L);
Status DeleteStudent(LinkList *L,char *number);
Status FindStudent(LinkList *L,char *name);
void ShowSingle(LinkList *p);

