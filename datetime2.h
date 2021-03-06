#pragma once
#include <iostream>
#include <string.h>
#include <ctime>
#include <iomanip>


using namespace std;

char strDateTime[20];
int nDayOfMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

struct DateTime
{
	int y = 0, m = 0, d = 0, h = 0, mi = 0;
};
typedef struct DateTime DATETIME;

int ConvertCharToInt(char* strDateTime, int n) 
{
    int numb = 0; 
    for (int i = 0; i < n; ++i) 
        numb = numb * 10 + strDateTime[i] - '0'; 
    return numb; 
}


//inline int num(char x) {return x - '0';}

bool isRightDateTime(char* strDateTime, int n)
{
	for (int i = 0; i < n; ++i)
		if ((strDateTime[i] - '0') > -1 && (strDateTime[i] - '0') < 10)
			continue;
		else
			return false;
	return true;
}

void OutputDateTime(DATETIME &dt)
{
	cout<< setw(2) << setfill('0') <<dt.h << ":" 
		<< setw(2) << setfill('0') <<dt.mi << " " 
		<< setw(2) << setfill('0') <<dt.d << "/" 
		<< setw(2) << setfill('0') <<dt.m << "/" << dt.y;
}
int CompareDateTimeToNow(DATETIME dt2)
{	
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	DATETIME dtNow;
	dtNow.y = ltm->tm_year+1900;
	dtNow.m = ltm->tm_mon+1;
	dtNow.d = ltm->tm_mday;
	dtNow.h = ltm->tm_hour;
	dtNow.mi = ltm->tm_min;
	if (dt2.y > dtNow.y ) return 1;if (dt2.y < dtNow.y ) return 0;
	if (dt2.m > dtNow.m) return 1;if (dt2.m < dtNow.m) return 0;
	//if ((dt.y % 400 == 0) || (dt.y % 4 == 0 && dt.y % 100 != 0))	nDayOfMonth[2] = 29;
	if (dt2.d > dtNow.d) return 1;if (dt2.d < dtNow.d) return 0;
	if (dt2.h > dtNow.h) return 1;if (dt2.h < dtNow.h) return 0;
	if (dt2.mi > dtNow.mi) return 1;if (dt2.mi <= dtNow.mi) return 0;
	return 0;
	
}
int Compare2DateTime (DATETIME dt1,DATETIME dt2){
	if (dt2.y > dt1.y ) return 1;if (dt2.y < dt1.y ) return 0;
	if (dt2.m > dt1.m) return 1;if (dt2.m < dt1.m) return 0;
	//if ((dt.y % 400 == 0) || (dt.y % 4 == 0 && dt.y % 100 != 0))	nDayOfMonth[2] = 29;
	if (dt2.d > dt1.d) return 1;if (dt2.d < dt1.d) return 0;
	if (dt2.h > dt1.h) return 1;if (dt2.h < dt1.h) return 0;
	if (dt2.mi > dt1.mi) return 1;if (dt2.mi <= dt1.mi) return 0;
	return 0;
}
int IsSame2Date (DATETIME dt1,DATETIME dt2){
	if (dt2.y != dt1.y) return 0;
	if (dt2.m != dt1.m) return 0;
	if (dt2.d != dt1.d) return 0;
	return 1;
}
bool IsRightMonth(DATETIME dt)
{	
	nDayOfMonth[2] = 28;
	if ((dt.y % 400 == 0) || (dt.y % 4 == 0 && dt.y % 100 != 0))
		nDayOfMonth[2] = 29;
	if (dt.d > nDayOfMonth[dt.m]) 
		return false;
	return true;
}
int ValidDateTime(DATETIME &dt)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	DATETIME dtNow, dtFlight;
	
	dtNow.y = 1900 + ltm->tm_year;
	dtNow.m = 1 + ltm->tm_mon;
	dtNow.d = ltm->tm_mday;
	dtNow.h = ltm->tm_hour;
	dtNow.mi = ltm->tm_min;

	bool flagDateTime = true;
	while(flagDateTime)
	{
		//OutputDateTime(dtNow);
		
		bool flagSize = true;
		int xx=wherex();int yy=wherey();
		while(flagSize)
		{
				gotoxy(xx,yy);
				cout<<"                                                 ";
				gotoxy(xx,yy);
				NhapChuoi("Nhap datetime: ",strDateTime,16);
				if (strcmp(strDateTime,"0")==0) return 0 ;
				if (strlen(strDateTime) == 16)
					flagSize = false;
				else{
					gotoxy(xx,yy+1);
					cout << "Nhap thieu hoac du ky tu";
					continue;
				}
		}
		gotoxy(xx,yy+1);
		cout << "                              ";
		char day[] = {strDateTime[0], strDateTime[1]};
		char month[] = {strDateTime[3], strDateTime[4]};
		char year[] = {strDateTime[6], strDateTime[7], strDateTime[8], strDateTime[9]};
		char hour[] = {strDateTime[11], strDateTime[12]};
		char minute[] = {strDateTime[14], strDateTime[15]};
		int y, m, d, h, mi;
		if(isRightDateTime(year, 4))
			y = ConvertCharToInt(year, 4);
		else
		{
			cout << "Nhap nam khong dung" << endl;
			continue;
		}
		if(y < dtNow.y)
		{
			cout << "Nhap nam khong dung" << endl;
			continue;
		}
		if(isRightDateTime(month, 2))
			m = ConvertCharToInt(month, 2);	
		else
		{
			cout << "Nhap thang khong dung" << endl;
			continue;
		}
		if(m > 12 || m < 1)
		{
			cout << "Nhap thang khong dung" << endl;
			continue;
		}
		nDayOfMonth[2] = 28;
		if ((dtFlight.y % 400 == 0) || (dtFlight.y % 4 == 0 && dtFlight.y % 100 != 0))
		nDayOfMonth[2] = 29;
		if(isRightDateTime(day, 2))
			d = ConvertCharToInt(day, 2);	
		else
		{
			cout << "Nhap ngay khong dung" << endl;
			continue;
		}
		if(d > nDayOfMonth[m])
		{
			cout << "Nhap ngay khong dung" << endl;
			continue;
		}
		if(isRightDateTime(hour, 2))
			h = ConvertCharToInt(hour, 2);
		else
		{
			cout << "Nhap gio khong dung" << endl;
			continue;
		}
		if(h > 23 || h < 0)
		{
			cout << "Nhap gio khong dung" << endl;
			continue;
		}
		if(isRightDateTime(minute, 2))
			mi = ConvertCharToInt(minute, 2);			
		else
		{
			cout << "Nhap phut khong dung" << endl;
			continue;
		}
		if(mi > 59 || mi < 0)
		{
			cout << "Nhap phut khong dung" << endl;
			continue;
		}
		dtFlight.y = y;
		dtFlight.m = m;
		dtFlight.d = d;
		dtFlight.h = h;
		dtFlight.mi = mi;
		dt = dtFlight;
		flagDateTime = false;
	}
	return 1;
}
int ValidDate(DATETIME &dt)
{
	DATETIME dtFlight;
	bool flagDateTime = true;
	while(flagDateTime)
	{
		
		bool flagSize = true;
		int xx=wherex();int yy=wherey();
		while(flagSize)
		{		
				gotoxy(xx,yy);
				NhapChuoi("Nhap date: ",strDateTime,10);
				if (strcmp(strDateTime,"0")==0) return 0 ;
				if (strlen(strDateTime) == 10)
					flagSize = false;
				else{
					gotoxy(xx,yy+1);
					cout << "Nhap thieu hoac du ky tu";
					gotoxy(xx,yy);
					cout << "                              ";
					continue;
				}	
		}
		gotoxy(xx,yy+1);
		cout << "                              ";
		char day[] = {strDateTime[0], strDateTime[1]};
		char month[] = {strDateTime[3], strDateTime[4]};
		char year[] = {strDateTime[6], strDateTime[7], strDateTime[8], strDateTime[9]};
		char hour[] = {strDateTime[11], strDateTime[12]};
		char minute[] = {strDateTime[14], strDateTime[15]};
		int y, m, d, h, mi;
		
		if(isRightDateTime(year, 4))
			y = ConvertCharToInt(year, 4);
		else
		{
			cout << "Nhap nam khong dung" << endl;
			continue;
		}
		if(isRightDateTime(month, 2))
			m = ConvertCharToInt(month, 2);	
		else
		{
			cout << "Nhap thang khong dung" << endl;
			continue;
		}
		if(m > 12 || m < 1)
		{
			cout << "Nhap thang khong dung" << endl;
			continue;
		}
		nDayOfMonth[2] = 28;
		if ((dtFlight.y % 400 == 0) || (dtFlight.y % 4 == 0 && dtFlight.y % 100 != 0))
		nDayOfMonth[2] = 29;
		if(isRightDateTime(day, 2))
			d = ConvertCharToInt(day, 2);	
		else
		{
			cout << "Nhap ngay khong dung" << endl;
			continue;
		}
		if(d > nDayOfMonth[m])
		{
			cout << "Nhap ngay khong dung" << endl;
			continue;
		}
		dtFlight.y = y;
		dtFlight.m = m;
		dtFlight.d = d;
		dtFlight.mi= 0;
		dtFlight.h=0;
		dt = dtFlight;
		flagDateTime = false;
	}
	return 1;
}
