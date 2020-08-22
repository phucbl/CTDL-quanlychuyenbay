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
const int so_item = 15;
const int so_item2 = 4;
const int dongMenu =1;
const int cotMenu = 2;
const int dongMenuSua = 6;
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
//ten file
char filenameMB[80]="D:\\DSMB.TXT"; 
char filenameCB[80]="D:\\DSCB.TXT"; 
char filenameHK[80]="D:\\DSHK.TXT"; 
// mang
char mangchucai [10][2] = {" ","A","B","C","D","E","F","G","H","I"};
char mangchuso[10][2]= {"0","1","2","3","4","5","6","7","8","9"};
char thucdon [so_item][50] = {	"------------ MAY BAY -----------",
							  	"  Them 1 may bay                ",
			                  	"  Liet ke danh sach may bay     ",
			                  	"  Tim/sua/xoa may bay           ",
			                  	"  Thong ke luot bay             ",
			                  	"---------- CHUYEN BAY ----------",
			                  	"  Them 1 chuyen bay             ",
			                   	"  Liet ke danh sach chuyen bay  ",
			                   	"  Tim/sua/xoa chuyen bay        ",
			                   	"  Huy chuyen bay                ",
			                   	"-------------- VE --------------",
			                  	"  Dat ve                        ",
			                   	"  Huy ve                        ",
			                   	"  Tra chuyen bay theo ngay      ",
			                   	"  In danh sach hanh khach       ",
			                   	
			                };   
char thucdon2 [so_item2][50] = {"",
							  	"1. Tro ve ",
			                  	"2. Sua    ",
			                  	"3. Xoa    ",			                  	
			                };
char menuYN [2][5] = {"Yes","No"};
char menuPhai[2][5] = {"Nam","Nu"};

inline int num(char x){ return x - '0';}
void Normal () {
	SetColor(White);
	SetBGColor(Black);
}
void HighLight () {
	SetColor(White);
	SetBGColor(DarkGray);
}
void ThemCach(char *str){
	int len=strlen(str);
	if (len<14){
		char f[15]=" ";
	for (int i=0;i<13-len;i++)  strcat(f," ");
	strcat(f,str);
	strcpy(str,f);
	}
}
void KhungMenu(){
	SetColor(Yellow);
	gotoxy (0,0);
	cout << char(201) << setw(34) << setfill(char(205)) << char(205) << char(203)<<setw(75) << setfill(char(205)) << char(205)<< char (187);
	for (int i=1;i<16;i++)
		{
			gotoxy (0,i);cout << char(186);
			gotoxy (35,i);cout<<char(186);
			gotoxy (111,i);cout<<char(186);
		}
	gotoxy (0,16);
	cout << char(204) << setw(34) << setfill(char(205)) << char(205) << char(206)<<setw(75) << setfill(char(205)) << char(205)<< char (185);
	gotoxy (0,17);cout << char(186); cout<<"ESC: Luu va thoat";
	gotoxy (35,17);cout<<char(186);
	gotoxy (111,17);cout<<char(186);
	gotoxy (0,18);
	cout << char(200) << setw(34) << setfill(char(205)) << char(205) << char(202)<<setw(75) << setfill(char(205)) << char(205)<< char (188);
		
}
int MenuYN (char td[2][5],int x)
{	int py=wherey();int chon=0;
	int px=wherex()+5-x;
	gotoxy(px+20,py+1);cout<<td[1];
	HighLight();gotoxy(px,py+1);cout<<td[0];
	char kytu;
	do {
  	kytu = getch();
  	if (kytu==0) kytu = getch();
  	switch (kytu) {
			    case Right : if(chon+1 <2)
			  			{
			  		        Normal();
			              	gotoxy(px,py+1);
			              	cout << td[chon];
			              	chon++;
			              	HighLight();
			              	gotoxy(px+20,py+1);
			              	cout << td[chon];  				
			  			  }
			  			  break;
			  	case Left : if(chon-1 >=0)
			  			{
			  		        Normal();
			              	gotoxy(px+20,py+1);
			              	cout << td[chon];
			              	chon--;
			              	HighLight();
			              	gotoxy(px,py+1);
			              	cout << td[chon];  				
			  			  }
			  			  break;
			  	case ENTER : Normal();return chon;  			  
				}
	}while (1);
}
int MenuDong(char td [so_item][50], int &chon){
  Normal();
  system("cls");   
  KhungMenu();
  SetColor(White);
  int i; 
  for ( i=0; i< so_item ; i++)
  { gotoxy(cotMenu, dongMenu +i);
  	if (i%5==0) SetColor(LightBlue);
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
              	chon --;if (chon%5==0) chon--;
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
              	chon ++;if (chon%5==0) chon++;
              	HighLight();
              	gotoxy(cotMenu,dongMenu+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Right : if(chon+5 <so_item)
  			{
  		        Normal();
              	gotoxy(cotMenu,dongMenu+chon);
              	cout << td[chon];
              	chon=chon+5;
              	HighLight();
              	gotoxy(cotMenu,dongMenu+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
	
  	case Left : if(chon-5 >=1)
  			{
  		        Normal();
              	gotoxy(cotMenu,dongMenu+chon);
              	cout << td[chon];
              	chon=chon-5;
              	HighLight();
              	gotoxy(cotMenu,dongMenu+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case ENTER : Normal();return chon; // end switch
  	case ESC : { 
				Normal();return chon=so_item;
		break;
	  }
	  
  } 
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
  HighLight();
  cout << td[chon];
  Normal();
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
              	HighLight();
              	cout << td[chon];
  				Normal();
  			  }
  			  break;
  	case Down :if (chon+1 <so_item2)
  			  {
  		        
              	gotoxy(cotMenuSua,dongMenuSua+chon);
              	cout << td[chon];
              	chon ++;
              	
              	gotoxy(cotMenuSua,dongMenuSua+chon);
              	HighLight();
              	cout << td[chon];
  				Normal();
  			  }
  			  break;
  	case 13 : return chon;// end switch
  }  
  } while (1);
}

void BaoLoi (char *s){
  int x=wherex() , y=wherey();
  gotoxy (37,17);
  SetColor(LightGreen);
  cout <<s;
  Normal();
  Sleep(2000);
  //gotoxy(37,17);
  //cout<<"                                                            ";
  gotoxy(x,y);
}void ThongbaoVe (char *s,int px){
  int x=wherex() , y=wherey();
  gotoxy (px,18);
  cout<<"                                              ";
  gotoxy (px,19);
  cout<<"                                              ";
  gotoxy (px,19);
  SetColor(LightGreen);
  cout <<s;  
  Sleep(2000);  
}

void NhapChuoi (char *tieude, char *S, int max) {
	cout << tieude ;max--;
	int lenght=0;
			while(lenght<=max)
			{	
				int c=getch();
				//if (c==224||c==0||c=='.'||c=='+'||c=='-'||c=='*') {c=getch();continue;}
				if (c==224||c==0) {c=getch();continue;} //cac truong hop F chuc nang, va phim muoi ten
				if (c==ESC) {strcpy(S,"0");break;}
				if ((c>=65&&c<=90)||(c<=122&&c>=97)||c==32||c==47||c==58||c==8||c==13||(c>=48&&c<=57)){
					S[lenght]= char (c);
				}
				else continue;				
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
int CheckChuoi (char *S, int a, int b){   //a la 1 thi check ky tu va b la do dai chuoi
										 //a la 2 thi check so va b la max co the nhap
										//a la 5 thi check so hieu, giong a la 1 nhung khong co dau cach
										//a la 3 thi check cmnd chi co so'
										//a la 4 thi check ten, chuan hoa ten, xoa cach, in hoa. kiem tra do dai
	if (a==1){
		if (strlen(S)>b) return -1;
	int i;int len=strlen(S);
	for(i=0;i<len;i++)
	{	
		int c=S[i];
		if ((c>='A'&&c<='Z')||(c<='z'&&c>='a')||(c>='0'&&c<='9'))
		i=i; else {
			 return -1;
		}
		
	}
	int c=S[0]; if (c==32) 	return -1;
	c=S[len-1];	if (c==32) 	return -1;
	}
	if (a==5){
		if (strlen(S)>b) return -1;
	int i;int len=strlen(S);
	for(i=0;i<len;i++)
	{	
		int c=S[i];
		if ((c>='A'&&c<='Z')||(c<='z'&&c>='a')||(c>='0'&&c<='9'))
		i=i; else {
			 return -1;
		}
		
	}
	
	}
	if (a==2){
		int i;int d=0;
	int len=strlen(S);
	for(i=0;i<len;i++)
	{	
		int c=num(S[i]);
		if (0<=c && c<=9)
		d=d*10+c;
		else return -1;		
	}
		if (b<=d) return -1; else return d;
	}
	if (a==3){
		int i;
		int len=strlen(S);
		for(i=0;i<len;i++) {
			if ('9'<=S[i] || S[i]<='0') return -1;
		}
	}
	if (a==4){
		int i;
		for(i=0;i<strlen(S)-1;i++) {
			if ((S[i]>='A'&&S[i]<='Z')||(S[i]<='z'&&S[i]>='a'||S[i]==' ')) {
				if (S[i]==' ' && S[i+1]==' ')
				{
					strcpy(&S[i],&S[i+1]); i--;
				}
				if (S[i]==' ' && S[i+1]!=' ') S[i+1] -= 32 * (S[i+1] >= 'a' && S[i+1] <= 'z');
				if (S[i]!=' ' && S[i+1]!=' ') S[i+1] += 32 * (S[i+1] >= 'A' && S[i+1] <= 'Z');
			}
			 else {
			 return -1;
			}
			
		}
		if ((S[i]>='A'&&S[i]<='Z')||(S[i]<='z'&&S[i]>='a'||S[i]==' ')) i=i;
		else 
			 return -1;
		do{
			if (S[strlen(S)-1]==' ') S[strlen(S)-1]=char (0);
		} while (S[strlen(S)-1]==' ');
		
		strcpy(S,strrev(S));
		do{
			if (S[strlen(S)-1]==' ') S[strlen(S)-1]=char (0);
		} while (S[strlen(S)-1]==' ');
		strcpy(S,strrev(S));
		S[0] -= 32 * (S[0] >= 'a' && S[0] <= 'z');
	}
	return 1;		
}
