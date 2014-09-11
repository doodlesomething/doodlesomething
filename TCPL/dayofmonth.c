/*
	date:9-3-2014
	author:doodlesomething
	version:1.0

	功能：使用指针实现dayofyear() 和monthofyear()
	即将一年中的第几天转换为年月日，其中月应包含英文别名

	question:本来是想用指针数组实现存储daytab却一直报错，无法解决。
*/

#include <stdio.h>


int main() {
	int year,month,day,yearday;
	int dayofyear(int year,int month,int day);
	int monthofyear(int year,int total_day,int *month,int *day);
	char *month_name(int n);

	printf("%d\n",dayofyear(2014,9,3));
	monthofyear(2014,247,&month,&day);
	printf("%d(%s),%d\n",month,month_name(month),day);

	return 0;
}
	
	//之所以加上0是因为方便以12为单位计算
	static int daytab[]={
		0,
		31,
		31+28,
		31+28+31,
		31+28+31+30,
		31+28+31+30+31,
		31+28+31+30+31+30,
		31+28+31+30+31+30+31,
		31+28+31+30+31+30+31+31,
		31+28+31+30+31+30+31+31+30,
		31+28+31+30+31+30+31+31+30+31,
		31+28+31+30+31+30+31+31+30+31+30,
		31+28+31+30+31+30+31+31+30+31+30+31,
		0,
		31,
		31+29,
		31+29+31,
		31+29+31+30,
		31+29+31+30+31,
		31+29+31+30+31+30,
		31+29+31+30+31+30+31,
		31+29+31+30+31+30+31+31,
		31+29+31+30+31+30+31+31+30,
		31+29+31+30+31+30+31+31+30+31,
		31+29+31+30+31+30+31+31+30+31+30,
		31+29+31+30+31+30+31+31+30+31+30+31
	};

	//判断是否为闰年  0-不是 1-是
	int leap(int year) {
		return ( ( (year%4 == 0) && year%100 != 0 ) || year % 400 == 0 );
	}

	int dayofyear(int year,int month,int day) {
		int leap(int year);
		//这一行挺有意思
		return *(daytab + month + !leap(year) * 12 ) + day;
	}

	int monthofyear(int year,int yearday,int *month,int *day) {
		int m,ly;

		ly = leap(year);
		//这一行比较有意思，注意ly取反 --简单的错误判断
		if(yearday < 1 || yearday>(355+!ly)) {
			return -1;
		}

		m = ly ? 11 : 23;

		//到达正确的数组位置
		while(yearday < *(daytab + m)) {
			m--;
		}
		//月
		if(month) {
			*month = m % 12 ;
		}
		//天数
		if(day) {
			*day =yearday - (*(daytab + m));
		}

		return 0;
	}
	
	//the function will return the pointer of the month of sting--别名
	char *month_name(int n) {

		static char *name[]={"January","February","March",
		"April","May","June","July","August","September","October","November",
		"December"};

		return name[n-1];
	}
