/*----------------------------------------------------------------------------------------
	* FileName:POJ1328.c
	* author:doodlesomething@163.com
	* date:10-29-2014
	* version:1.0
	* description:Radar Installation  POJ1328 soloved by Greedy Algorithm
-----------------------------------------------------------------------------------------*/



#include <stdio.h>
#include <math.h>


#define N 10

typedef struct {
	double left; 
	double right;
}Pos;

//这样设置是为了理解上的方便
typedef struct {
	int x;
	int y;
}Posi;



/*
* @description:quick sort by the left asc
*/
void QuickSort(Pos P[],int low,int high) {
	int first,last;
	Pos temp;

	if(low >= high) {
		return;
	}

	first = low;
	last = high;
	temp = P[0];

	while(first < last) {
		while(first < last && temp.left <= P[last].left)
			last--;
		P[first] = P[last];

		while(first < last && temp.left >= P[first].left)
			first++;
		P[last] = P[first];
	}

	P[first] = temp;

	QuickSort(P,low,first - 1);
	QuickSort(P,first + 1,high);

}


int main() {
	
	int n,dis,i,flag,total;
	double CurrentRight;
	Pos P[1000];
	Posi S[1000];

	flag = 1;
	total = 1;

	printf("please enter n and dis:");
	scanf("%d,%d",&n,&dis);
	printf("please enter each value:\n");
	for(i = 0; i < n; i++) {
		scanf("%d%d",&S[i].x,&S[i].y);
		if(S[i].y > dis)
			flag = 0;
	}


	if(!flag) {
		printf("result:-1\n");
	}
	else {
		for(i = 0; i < n ; i++) {
			P[i].left =  S[i].x - sqrt( (double) (dis * dis - S[i].y * S[i].y)); 
			P[i].right = S[i].x + sqrt( (double) (dis * dis - S[i].y * S[i].y));
		}

		//QuickSort
		QuickSort(P,0,n - 1);

		CurrentRight = P[0].right;

		for( i = 1; i < n; i ++) {
			if(P[i].left > CurrentRight) {
				total++;
				CurrentRight = P[i].right;
			}
			else {
				CurrentRight = P[i].right >  CurrentRight ? CurrentRight : P[i].right;
			}
		}
		//output
		printf("%d\n",total);
	}


	return 0;
}


/*
Sample Input

3,2
1 2
-3 1
2 1

Sample Output
total:2



Sample Input
1,2
0 2

Sample Output
total:1

*/
