#pragma once 
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include "mylib.h"
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
#define Black 		 0
#define Blue  		 1
#define Green		 2
#define Cyan  		 3
#define Red   		 4
#define Magenta 	 5
#define Brown   	 6
#define LightGray    7
#define DarkGray     8
#define LightBlue    9
#define LightGreen   10
#define LightCyan    11
#define LightRed     12
#define LightMagenta 13
#define Yellow       14
#define White        15
//menu
const int so_item = 18;
const int so_item2 = 4;
const int dongMenu =1;
const int cotMenu = 2;
const int dongMenuSua = 4;
const int cotMenuSua = 37;
const int cotNhap = 37;
const int dongNhap = 1;
const int cotVe = 5;
const int dongVe = 3;

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
char thucdon [so_item][50] = {	"------------ MAY BAY -----------",
							  	"  Them 1 may bay                ",
			                  	"  Liet ke danh sach may bay     ",
			                  	"  Tim/sua/xoa may bay           ",
			                  	"  Thong ke luot bay             ",
			                  	"  Save MB                       ",
			                  	"---------- CHUYEN BAY ----------",
			                  	"  Them 1 chuyen bay             ",
			                   	"  Liet ke danh sach chuyen bay  ",
			                   	"  Tim/sua/xoa chuyen bay        ",
			                   	"  Huy chuyen bay                ",
			                   	"  Save CB                       ",
			                   	"-------------- VE --------------",
			                  	"  Dat ve                        ",
			                   	"  Huy ve                        ",
			                   	"  Tra chuyen bay theo ngay      ",
			                   	"                                ",
			                   	"  Save CB                       ",
			                   	
			                };   
char thucdon2 [so_item2][50] = {"",
							  	"1. Tro ve ",
			                  	"2. Sua    ",
			                  	"3. Xoa    ",			                  	
			                };   
inline int num(char x){ return x - '0';}
void Normal () {
	SetColor(White);
	SetBGColor(Black);
}
void HighLight () {
	SetColor(White);
	SetBGColor(DarkGray);
}

void KhungMenu(){
	SetColor(Yellow);
	gotoxy (0,0);
	cout << char(201) << setw(34) << setfill(char(205)) << char(205) << char(203)<<setw(75) << setfill(char(205)) << char(205)<< char (187);
	for (int i=1;i<19;i++)
		{
			gotoxy (0,i);cout << char(186);
			gotoxy (35,i);cout<<char(186);
			gotoxy (111,i);cout<<char(186);
		}
	gotoxy (0,19);
	cout << char(204) << setw(34) << setfill(char(205)) << char(205) << char(206)<<setw(75) << setfill(char(205)) << char(205)<< char (185);
	gotoxy (0,20);cout << char(186); cout<<"ESC: Thoat";
	gotoxy (35,20);cout<<char(186);
	gotoxy (111,20);cout<<char(186);
	gotoxy (0,21);
	cout << char(200) << setw(34) << setfill(char(205)) << char(205) << char(202)<<setw(75) << setfill(char(205)) << char(205)<< char (188);
		
}
int MenuDong(char td [so_item][50], int &chon){
  Normal();
  system("cls");   
  KhungMenu();
  SetColor(White);
  int i; 
  for ( i=0; i< so_item ; i++)
  { gotoxy(cotMenu, dongMenu +i);
  	if (i%6==0) SetColor(Yellow);
    cout << td[i];
	SetColor(White);
  }
  HighLight();
  gotoxy(cotMenu,dongMenu+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon-1 >=1)
  			  {
  		        Normal();
              	gotoxy(cotMenu,dongMenu+chon);
              	cout << td[chon];
              	chon --;if (chon%6==0) chon--;
              	HighLight();
              	gotoxy(cotMenu,dongMenu+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item)
  			  {
  		        Normal();
              	gotoxy(cotMenu,dongMenu+chon);
              	cout << td[chon];
              	chon ++;if (chon%6==0) chon++;
              	HighLight();
              	gotoxy(cotMenu,dongMenu+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Right : if(chon+6 <so_item)
  			{
  		        Normal();
              	gotoxy(cotMenu,dongMenu+chon);
              	cout << td[chon];
              	chon=chon+6;
              	HighLight();
              	gotoxy(cotMenu,dongMenu+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
	
  	case Left : if(chon-6 >=1)
  			{
  		        Normal();
              	gotoxy(cotMenu,dongMenu+chon);
              	cout << td[chon];
              	chon=chon-6;
              	HighLight();
              	gotoxy(cotMenu,dongMenu+chon);
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
  { gotoxy(cotMenuSua, dongMenuSua+i);
    cout << td[i];
  }
  
  gotoxy(cotMenuSua,dongMenuSua+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon-1 >=1)
  			  {
  		        
              	gotoxy(cotMenuSua,dongMenuSua+chon);
              	cout << td[chon];
              	chon --;
              	
              	gotoxy(cotMenuSua,dongMenuSua+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item2)
  			  {
  		        
              	gotoxy(cotMenuSua,dongMenuSua+chon);
              	cout << td[chon];
              	chon ++;
              	
              	gotoxy(cotMenuSua,dongMenuSua+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon;
  }  // end switch
  } while (1);
}

void BaoLoi (char *s){
  int x=wherex() , y=wherey();
  gotoxy (37,20);
  SetColor(LightGreen);
  cout <<s;
  Normal();
  Sleep(2000);
  gotoxy(37,20);
  cout<<"                                                            ";
  gotoxy(x,y);
}
/*void NhapChuoi (char *tieude, char *S) {
	cout << tieude ;  fflush(stdin);
    do
	  gets(S);
    while (strcmp(S,"")==0)  ;	
}*/
		

/*void NhapChuoi (char *tieude, char *S, int max) {
	cout << tieude ;
	int lenght=0;
			while(lenght<max)
			{	
				
				int c=getch();if (c==224||c==42||c==43||c==45) {c=getch();continue;} 
				if ((c>=65&&c<=90)||(c<=122&&c>=97)||c==32||c==47||c==58||c==8||c==13||(c>=48&&c<=57)){
					S[lenght]= char (c);
				}
				S[lenght]=getch();
				if (lenght ==0 && (S[lenght]=='\b' ||S[lenght]=='\r' )) { S[lenght]==char (0);continue;}
				if (lenght >0 && S[lenght]=='\b'){
					S[lenght]=char(0);
					S[lenght-1]=char(0);
					lenght=lenght-2;
					putch(8);
					cout<<" ";
					putch(8);
					}
				else 
					putch(S[lenght]);
					if(S[lenght]=='\r'){
						S[lenght]=char(0);break;
					}
					lenght++;
				while (lenght==max) {
					char wait[2];
					
					wait[0]=getch();
					if (wait[0]=='\b')
					{
						S[lenght-1]=char(0);
						lenght--;
						putch(8);
						cout<<" ";
						putch(8);
					}
					if (wait[0]=='\r') break;
					
					continue;
				}
			}
			
			
}*/
void NhapChuoi (char *tieude, char *S, int max) {
	cout << tieude ;max--;
	int lenght=0;
			while(lenght<=max)
			{	
				
				int c=getch();if (c==224||c==42||c==43||c==45) {c=getch();continue;} 
				if ((c>=65&&c<=90)||(c<=122&&c>=97)||c==32||c==47||c==58||c==8||c==13||(c>=48&&c<=57)){
					S[lenght]= char (c);
				}
				if (lenght ==0 && (S[lenght]=='\b' ||S[lenght]=='\r' )) { S[lenght]==char (0);continue;}
				if (lenght >0 && S[lenght]=='\b'){
					S[lenght]=char(0);
					S[lenght-1]=char(0);
					lenght=lenght-2;
					putch(8);
					cout<<" ";
					putch(8);
					}
				else 
					putch(S[lenght]);
					if(S[lenght]=='\r'){
						S[lenght]=char(0);break;
					}
					lenght++;
				while (lenght>max) {
					char wait[2];
					
					wait[0]=getch();
					if (wait[0]=='\b')
					{
						S[lenght-1]=char(0);
						lenght--;
						putch(8);
						cout<<" ";
						putch(8);
					}
					if (wait[0]=='\r') break;
					
					continue;
				}
			}
			
			
}
int CheckChuoi (char *S, int a, int b){
	
	if (a==1){
		if (strlen(S)>b) return -1;
	int i;int e=strlen(S);
	for(i=0;i<e;i++)
	{	
		int c=S[i];
		if ((c>=65&&c<=90)||(c<=122&&c>=97)||c==32||(c>=48&&c<=57))
		i=i; else {
			cout<<c; return -1;
		}
		
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
		if (0<=c && c<=9)
		d=d*10+c;
		else return -1;		
	}
		if (b<=d) return -1; else return d;
	}
	return 1;		
}

