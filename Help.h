#pragma once 
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <mylib.h>
#include <iomanip>

using namespace std;

//keyboard
const int ENTER = 13;
const int ESC = 27;
const int Up = 72;
const int Left = 75;
const int Right = 77;
const int Down = 80;
//color
const int Black = 0;
const int Blue = 1;
const int Red = 4;
const int Purple = 5;
//menu
const int so_item = 18;
const int so_item2 = 4;
const int dong =2;
const int cot = 2;
int currposVe = 1;
int currposVeT = 1;
//max tt mb-cb
const int MAXLIST =300;
const int MAXVE =500;



char filenameMB[80]="D:\\DSMB.TXT"; 
char filenameCB[80]="D:\\DSCB.TXT"; 
char filenameHK[80]="D:\\DSHK.TXT"; 
char mangchucai [10][2] = {" ","A","B","C","D","E","F","G","H","I"};
char mangchuso[10][2]= {"0","1","2","3","4","5","6","7","8","9"};
char thucdon [so_item][50] = {	"------------MAYBAY--------------",
							  	"1. Them 1 may bay               ",
			                  	"2. Liet ke danh sach may bay    ",
			                  	"3. Tim/sua/xoa may bay          ",
			                  	"4. Thong ke luot bay            ",
			                  	"5. Save MB                      ",
			                  	"------------CHUYENBAY-----------",
			                  	"1. Them 1 chuyen bay            ",
			                   	"2. Liet ke danh sach chuyen bay ",
			                   	"3. Tim/sua/xoa chuyen bay       ",
			                   	"4. Huy chuyen bay               ",
			                   	"5. Save CB                      ",
			                   	"------------VE------------------",
			                  	"1. Dat ve                       ",
			                   	"2. Huy ve                       ",
			                   	"3. -----------------            ",
			                   	"4.                              ",
			                   	"5. Save CB                      ",
			                   	
			                };   
char thucdon2 [so_item2][50] = {"",
							  	"1. Tro ve ",
			                  	"2. Sua    ",
			                  	"3. Xoa    ",			                  	
			                };   
inline int num(char x){ return x - '0';}
void Normal () {
	SetColor(15);
	SetBGColor(0);
}
void HighLight () {
	SetColor(15);
	SetBGColor(1);
}

int MenuDong(char td [so_item][50], int &chon){
  Normal();
  system("cls");   
  int i; 
  for ( i=0; i< so_item ; i++)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot,dong+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon-1 >=1)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon --;if (chon%6==0) chon--;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon ++;if (chon%6==0) chon++;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Right : if(chon+6 <so_item)
  			{
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon=chon+6;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
	
  	case Left : if(chon-6 >=1)
  			{
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon=chon-6;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : Normal();return chon;
  }  // end switch
  } while (1);
}
int MenuDong2(char td [so_item2][50]){
  
  int chon =1;
  int i; 
  for ( i=0; i< so_item2 ; i++)
  { gotoxy(1, dong+i);
    cout << td[i];
  }
  
  gotoxy(1,dong+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon-1 >=1)
  			  {
  		        
              	gotoxy(1,dong+chon);
              	cout << td[chon];
              	chon --;
              	
              	gotoxy(1,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item2)
  			  {
  		        
              	gotoxy(1,dong+chon);
              	cout << td[chon];
              	chon ++;
              	
              	gotoxy(1,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon;
  }  // end switch
  } while (1);
}

void BaoLoi (char *s){
  int x=wherex() , y=wherey();
  gotoxy (5,20);
  cout <<s;
  Sleep(1000);
  gotoxy(5,20);
  clreol();
  gotoxy(x,y);
}
void NhapChuoi (char *tieude, char *S) {
	cout << tieude ;  fflush(stdin);
    do
	  gets(S);
    while (strcmp(S,"")==0)  ;	
}
int CheckChuoi (char *S, int a, int b){
	
	if (a==1){
		if (strlen(S)>b) return -1;
	int i;int e=strlen(S);
	for(i=0;i<e;i++)
	{	
		int c=S[i];
		if ((c>=65&&c<=90)||(c<=122&&c>=97)||c==32||(c>=48&&c<=57))
		i=i; else return -1;
		
	}
	int c=S[0]; if (c==32) 	return -1;
	c=S[e-1];	if (c==32) 	return -1;
	}
	if (a==2){
		int i;int d=0;
	int e=strlen(S);
	for(i=0;i<e;i++)
	{	
		int c=num(S[i]);
		if (0<=c<=9)
		d=d*10+c;
		else return -1;		
	}
		if (b<=d) return -1; else return d;
	}
	return 1;		
}
