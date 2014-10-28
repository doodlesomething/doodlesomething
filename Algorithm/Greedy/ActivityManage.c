/*----------------------------------------------------------------------------------
	* FileName:ActivityMange.c
	* author:doodlesomething@163.com
	* date:10-28-2014
	* version:1.o
	* description:ActivityMange-->Greedy Algorithm
-------------------------------------------------------------------------------------*/


#include <stdio.h>



typedef struct {
	int start_time;
	int end_time;
}Act;


/*
* @description:swap a elem
*/
void swap(Act arr[],int i,int j) {
	Act temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


/*
* @description:sort asc according to the activity end_time
*/
void BubbleSort(Act arr[],int n) {
	int i,j,flag;

	flag = 1;

	for(i = 0; i < n && flag; i++ ) {
		flag = 0;
		for(j = n - 1; j >= i; j-- ) {
			if(arr[j].end_time < arr[j - 1].end_time)  {
				swap(arr,j,j - 1);
				flag = 1;
			}
		}
	}

}


/*
* @description:return the total activities can arrange together
* @more:you should mention the question is [a,b) not [a,b]
*/
int ActivityMange(Act Activity[],int n,int flag[]) {
	int count,i,j;

	flag[0] = 1;
	count = 1;
	j = 0;

	for(i = 1; i < n; i++) {
		if(Activity[i].start_time >= Activity[j].end_time) {
			flag[i] = 1;
			count++;
			j = i;
		}
		else {
			flag[i] = 0;
		}
	}
	
	return count;
}


int main() {
	int i,n,result;
	int flag[100];
	Act Activity[100];

	//input
	printf("please enter n:");
	scanf("%d",&n);
	
	printf("please enter the list such as start_time end_time and enter Enter:\n");
	for(i = 0; i < n; i++) {
		scanf("%d%d",&Activity[i].start_time,&Activity[i].end_time);
	}

	//handler
	BubbleSort(Activity,n);

	result = ActivityMange(Activity,n,flag);

	//output
	printf("total activities:%d\n",result);
	printf("the activities are:");
	for(i = 0; i < n; i++) {
		if(flag[i]) 
		printf("%d\t",i);
	}
	printf("\n");

	return 0;
}



