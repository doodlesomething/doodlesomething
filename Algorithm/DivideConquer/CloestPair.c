/*-----------------------------------------------------------------------------------------
	* FileName:CloestPair.c
	* author:doodlesomething@163.com
	* version:1.0
	* date:10-31-2014
	* description:最近点对问题--->出自<<数据结构与算法分析>>分治算法
-------------------------------------------------------------------------------------------*/


#include <stdio.h>
#include <math.h>

#define N 100
#define MAX 10000.0

//坐标点结gg构
typedef struct {
	double x;
	double y;
}Pos;


Pos Point[N];
int temp[N];



//快排-->x轴非降序
void QuickSort(int low,int high,int (*cmp) (int i,int j)) {
	int first,last,pivot;
	Pos tmp;

	if(low >= high) {
		return ;
	}

	pivot = first = low;
	last = high;
	tmp = Point[first];

	while(first < last) {
		//从后往前找
		while(first < last && cmp(last,pivot) )
			last--;
		Point[first] = Point[last];
		//从前往后找
		while(first < last && cmp(pivot,first) )
			first++;
		Point[last] = Point[first];
	}

	Point[first] = tmp;

	QuickSort(low,first - 1,cmp);
	QuickSort(first + 1,high,cmp);

}


/*
* @description:用于x轴排序
*/
int cmpx(int i,int j) {
	return Point[i].x >= Point[j].x;
}

/*
* @description:用于y轴排序
*/
int cmpy(int i,int j) {
	return Point[i].y >= Point[j].y;
}

/*
* @description:求两点间距离
*/
double dis(int i,int j) {
	double dx,dy;

	dx = Point[i].x - Point[j].x;
	dy = Point[i].y - Point[j].y;

	return sqrt( dx * dx + dy * dy);
}

/*
* @description:取最小值
*/
double min(double x,double y) {
	return x > y ? y : x;
}

/*
* @description:求最近点对
*/
double ClosetPair(int low,int high) {
	int mid,i,j,k;
	double dl,dr,distance,d;
	
	//处理只有一点或两点的情况
	if(low == high)
		return MAX;
	if(high - low == 1)
		return dis(low,high);
	
	//分治处理
	mid = (low + high) / 2;
	dl = ClosetPair(low,mid);
	dr = ClosetPair(mid + 1,high);
	distance = min(dl,dr);

	k = 0;
	//求得2d范围内的点
	for(i = low; i <= high; i++ ) {
		if(fabs(Point[i].x - Point[i + 1].x) < distance)
			temp[k++] = i;
	}

	//对2d范围内点进行y坐标非将序排序
	QuickSort(0,k,cmpy);
	
	//从下自上进行扫描
	for(i = 0; i < k; i++) {
		for(j = i + 1; j < k && Point[temp[j]].y - Point[temp[i]].y < distance; j++) {
			//更新距离
			d = dis(temp[j],temp[i]);
			distance = min(d,distance);
		}
	}

	return distance;
}


int main(void) {
	int i,n;
	double distance;
	
	//input
	printf("please enter n:");
	scanf("%d",&n);
	printf("please enter x,y:\n");
	for(i = 0; i < n; i++) {
		scanf("%lf,%lf",&Point[i].x,&Point[i].y);
	}

	//Get closet distance
	QuickSort(0,n - 1,cmpx);
	distance = ClosetPair(0,n - 1);

	//output
	printf("%lf\n",distance);

	return 0;
}




/*
Sample Input:
1
1,0

Sample Output:
10000.000000


Sample Input:
2
1,0
0,0

Sample Output:
1,000000

Sample Input:
1,2
2,1
4,1

Sample Output:
1,414214

*/
