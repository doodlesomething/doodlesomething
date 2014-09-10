/*
	date:9-2-2014
	author:doodlesomethig
	fuction:
	change day to month
	change month to day
	this is the pointer version
*/



#include <stdio.h>


int main() {
	int year,month,day,yearday;
	int dayofyear(int year,int month,int day);
	int monthofyear(int year,int total_day,int *month,int *day);
	char *month_name(int n);
	printf("%d\n",dayofyear(2014,9,2));
	monthofyear(2014,246,&month,&day);
	printf("%d(%s),%d\n",month,month_name(month),day);
	return 0;
}
	static int daytabs[2][13] = {
			{0,31,29,31,30,31,30,31,31,30,31,30,31}, //leap year
			{0,31,28,31,30,31,30,31,31,30,31,30,31} //it's not a leap year
			};

	int dayofyear(int year,int month,int day) {

		int leap;
		int days;
		int *p;
		int *tmp;

		days=0;

		//the value of leap is 1(true) or 0(false)
		leap =  year%4 == 0 && year%100 != 0 || year%400 == 0;

		if(year < 1949 || month > 12 || month < 1 || day < 1)
			return -1;

		p = &daytabs[leap][0];
		tmp=p;

		if(day > *(tmp + month))
			return -1;

		for(;tmp< (p + month);tmp++)
			days += *tmp;
	
		days += day;

		return days;

	}

	int monthofyear(int year,int total_day,int *month,int *day) {

		int leap;
		int *p;
		int i;
		
		i=1;
		leap =  year%4 == 0 && year%100 != 0 || year%400 == 0;
		
		if(year < 1949 || total_day<1)
			return -1;
		
		if( (leap && total_day>365) || (!leap && total_day>366) )
			return -1;

		p = &daytabs[leap][1];

		for(;*p < total_day;p++) {
			total_day -= *p;
			i++;
		}

		*month=i;
		*day = total_day;

		return 0;
	}
	//the function will return the pointer of the month of sting
	char *month_name(int n) {
		static char *name[]={"January","February","March",
		"April","May","June","July","August","September","October","November",
		"December"};
		return name[n-1];
	}
