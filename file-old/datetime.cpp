#pragma once 
#include <iostream>
#include <conio.h>
#include <ctime>
#include <iomanip>
using namespace std;
int nDayOfMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

struct DateTime
{
	int y = 0, m = 0, d = 0, h = 0, mi = 0;
};
typedef struct DateTime DATETIME;

int DateTimeIsRightFormat(int hour, int minut, int day, int month, int year)
{
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	DATETIME dtNow;
	dtNow.y = ltm->tm_year+1900;
	if ((hour<0)||hour>23) return 11;
	if ((minut<0)||minut>59) return 22;
	if ((month<1)||month>12) return 44;
	if ((year<dtNow.y)||(year>(dtNow.y+2))) {
		cout<<year<<" - "<<dtNow.y;
		return 55;
	}
	nDayOfMonth[2] = 28;
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		nDayOfMonth[2] = 29;
	if (day > nDayOfMonth[month]) return 33;
	
	return 0;
}
inline int num(char x){ return x - '0';}
int DateTimeIsValid(DATETIME dt)
{
	nDayOfMonth[2] = 28;
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	DATETIME dtNow;
	dtNow.y = ltm->tm_year+1900;
	dtNow.m = ltm->tm_mon+1;
	dtNow.d = ltm->tm_mday;
	dtNow.h = ltm->tm_hour;
	dtNow.mi = ltm->tm_min;

	if (dt.y > dtNow.y) return 5;
	if (dt.m > dtNow.m) return 4;
	//if ((dt.y % 400 == 0) || (dt.y % 4 == 0 && dt.y % 100 != 0))	nDayOfMonth[2] = 29;
	if (dt.d > dtNow.d)	return 3;
	if (dt.h > dtNow.h)	return 2;
	if (dt.mi > dtNow.mi) return 1;
	return 0;
}
void OutputDateTime(DATETIME &dt)
{
	cout << setw(2) << setfill('0') <<dt.h << ":" << setw(2) << setfill('0') <<dt.mi << " " << setw(2) << setfill('0') <<dt.d << "/" << setw(2) << setfill('0') <<dt.m << "/" << dt.y;
	
}
DATETIME NhapDateTime(){
	char str[20];DateTime dati;int y = 0, m = 0, d = 0, h = 0, i = 0;
	gets(str);cout<<"\n";
	
	h=num(str[0])*10+num(str[1]); 
	i=num(str[3])*10+num(str[4]);
	d=num(str[6])*10+num(str[7]); 
	m=num(str[9])*10+num(str[10]);
	y=num(str[12])*1000+num(str[13])*100+num(str[14])*10+num(str[15]);
	int iii=DateTimeIsRightFormat(h,i,d,m,y);
	if(iii!=0) cout<<iii;  else {
		dati.d=d;
		dati.h=h;
		dati.m=m;
		dati.mi=i;
		dati.y=y;
		OutputDateTime(dati);cout<<"\n"<<DateTimeIsValid(dati);
	} 
	getch();
	return dati;
}


/*bool CompareDate(DATETIME dt1, DATETIME dt2)
{
	return dt1.d == dt2.d && dt2.m == dt1.m && dt1.y == dt2.y;

}*/
int main ()

{	
	 DateTime dt;dt =NhapDateTime();
	return 0;
}
