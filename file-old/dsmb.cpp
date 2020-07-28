#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <mylib.h>
using namespace std;

const int so_item = 12;
const int so_item2 = 4;
const int dong =2;
const int cot = 2;
const int Up = 72;
const int Down = 80;
const int Left = 75;
const int Right = 77;

const int MAXLIST =300;
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
			                   	"4. Huy chuyen bay           ",
			                   	"5. Save CB                      ",
			                   	
			                };   
char thucdon2 [so_item2][50] = {"",
							  	"1. Tro ve ",
			                  	"2. Sua    ",
			                  	"3. Xoa    ",			                  	
			                };   
struct Maybay {
  char sohieumb[16];
  char loaimb [51];
  int soday;
  int sodong;
  int luotbay;
};
struct ChuyenBay{
  char machbay[16];
  char timebay[25];
  char noiden[30];
  char trangthai[5];
  char sohieumaybay[16];	
};
struct vemb{
	int sove;
	char machbay[15];
	char cmnd[12];
	struct vemb *next;
};
struct listVe{
	int n;
	vemb *nodes;
};
struct nodeCB {
	ChuyenBay cb;
	struct vemb *head;
	struct nodeCB *next;
	
};
typedef nodeCB *NODEPTRCB;
	NODEPTRCB First;
	NODEPTRCB p;

struct listmb {
  int n;
  Maybay *nodes [MAXLIST];
};
struct hanhkhach
{
   char cmnd[13];	
   char ho[30];
   char ten[10];
   char phai[5];
   struct hanhkhach *left;
   struct hanhkhach *right;
};
typedef struct hanhkhach *NODEPTRHK;
NODEPTRHK tree=NULL;

void Normal () {
	SetColor(15);
	SetBGColor(0);
}
void HighLight () {
	SetColor(15);
	SetBGColor(1);
}
inline int num(char x){ return x - '0';}
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
  	case 13 : return chon;
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
int Search(listmb &ds, char x[15]) {
  for (int i =0; i < ds.n ; i++)
     if (strcmp(ds.nodes[i]->sohieumb, x)==0)  return i;
  return -1;
}
void BaoLoi (char *s){
  int x=wherex() , y=wherey();
  gotoxy (5,20);
  cout <<s;
  Sleep(1000);
  gotoxy(50,20);
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
int  NhapMB ( listmb &ds, Maybay &mb){
	int i=1;char sh[30];char l[100];
	while (i==1){
		
	   NhapChuoi (  "Nhap so hieu may bay (=0 la ket thuc) : ", sh);
	   if (strcmp(sh,"0")==0) return 0;
	   if (CheckChuoi(sh,1,15)==-1) 
	   {   
	   
	       BaoLoi ("Dinh dang sai "); 
	       continue;
	   }
	   if (strlen(sh)<15){
	   	char f[15]=" ";
	   	for (int i=0;i<14-strlen(sh);i++)  strcat(f," ");
		   strcat(f,sh);
		   strcpy(sh,f);
	   }
	   int search=Search(ds,sh);
	   if (search>=0){
	       BaoLoi ("So hieu bi trung "); 
	       continue;
	   }
	   	
	   	strcpy(mb.sohieumb,sh);strcpy(sh,"");i=0;//cout<<strlen(mb.sohieumb);}
	   	}
	   	i=1;
	while (i==1){
		 NhapChuoi (  "Nhap loai may bay: ",l);
		if (CheckChuoi(l,1,50)==-1) {
	       BaoLoi ("Dinh dang sai "); 
	       continue;
	   }
		strcpy(mb.loaimb,l);strcpy(l,"");i=0;//cout<<strlen(mb.sohieumb);}
	}
	i=1;
	while (i==1){  
		
		
	    NhapChuoi (  "Nhap so day: ",sh);int b=CheckChuoi(sh,2,10);
	    if (b==-1)
		{
	   		BaoLoi ("Nhap lai so day (<10)  "); 
			continue;
	   	}
		mb.soday=b;i=0;}
		i=1;
		
	   	while (i==1){  
		
		
	    NhapChuoi (  "Nhap so dong: ",sh);int b=CheckChuoi(sh,2,100);
	    if (b==-1)
		{
	   		BaoLoi ("Nhap lai so dong (<100)  "); 
			continue;
	   	}
		mb.sodong=b;i=0;}
		mb.luotbay=0;
	    return 1;
	
	}
 
void LietKe (listmb ds) {
 system("cls") ;
 printf ("                     DANH SACH MAY BAY \n");
 printf ("   So hieu              Loai            So day   So Dong     Luot Bay\n");
 for (int i =0 ; i < ds.n ; i++)
  printf ("%15s %15s \t%-5d\t %-5d %5d \n", ds.nodes[i]->sohieumb, 
     ds.nodes[i]->loaimb, ds.nodes[i]->soday, ds.nodes[i]->sodong,ds.nodes[i]->luotbay);
 getch();
}
int TimMb( listmb ds, char sohieu[16] ) {
  //char a;
  
  //do{
  if (strlen(sohieu)<15){
	   	char f[15]=" ";
	   	for (int i=0;i<14-strlen(sohieu);i++)  strcat(f," ");
		   strcat(f,sohieu);
		   strcpy(sohieu,f);
	   }
	   
  int i = Search (ds,sohieu) ; if (i>=0)
  printf( " Thong tin : %8s \t %-5s \t%-5d\t %-5d\n", ds.nodes[i]->sohieumb, 
     ds.nodes[i]->loaimb, ds.nodes[i]->soday, ds.nodes[i]->sodong);
     else return -1;
  return i;
}
void SuaMb( listmb ds, int i) { 
	 //a=i;
        char yn[5];   		
		printf( " So hieu may bay : %s", ds.nodes[i]->sohieumb);cout<<"\n";
		int a,b;
		char c[50];
		NhapChuoi (  "Nhap loai may bay: ", c) ;
		cout<<"Nhap so day: ";cin>>a;
		cout<<"Nhap so dong: ";cin>>b;
		NhapChuoi (  "Chac chan sua thong tin may bay nay (nhap Y de dong y): ", yn) ;
		if (strcmp(yn,"Y")==0){
			strcpy (ds.nodes[i]->loaimb,c);
			ds.nodes[i]->soday=a;
			ds.nodes[i]->sodong=b;
		   }
	   
		BaoLoi("Sua thong tin may bay thanh cong"); 
		}
//}while (a==-1);
void TangLuotBay( listmb ds, int i) { 
	ds.nodes[i]->luotbay++;
}

void SaveFileMB(listmb ds,char *filename) {
 FILE * f;
 if ((f=fopen(filename,"w"))==NULL)
 {  BaoLoi ("Loi mo file de ghi"); return ;
 }
 for (int i=0; i < ds.n; i++)
   fwrite (ds.nodes[i], sizeof (Maybay), 1, f);
 fclose(f);
 BaoLoi ("Da ghi xong danh sach may bay vao file");

}
void OpenFileMB(listmb &ds, char *filename) {
 FILE * f; Maybay mb;
 if ((f=fopen(filename,"r"))==NULL)
 {  BaoLoi ("Loi mo file de doc"); return ;
 }
 ds.n =0;
 while  (fread (&mb, sizeof (Maybay), 1, f)!=0) {
 	ds.nodes[ds.n]=new Maybay;
 	*ds.nodes[ds.n]=mb;
 	ds.n ++;
 }
    
 fclose(f);
 BaoLoi ("Da load xong danh sach may bay vao bo nho");

}
void XoaMb(listmb &ds, int i){
  
   char yn[5];
   NhapChuoi (  "Ban co chac chan xoa so hieu may bay nay (nhap Y de dong y): ", yn) ;
   if (strcmp(yn,"Y")==0){
   
   delete  ds.nodes[i];
     for (int j=i+1; j <ds.n; j++)
       ds.nodes[j-1]=ds.nodes[j];
       
     ds.n--;  
	}

BaoLoi("Xoa thong tin may bay thanh cong");
}
int InsertOrderMB (listmb &ds, Maybay mb){
	int j, k;
	if (ds.n ==MAXLIST ) return 0;
	for (j=0; j < ds.n && strcmp(ds.nodes[j]->sohieumb,mb.sohieumb)<0; j++ );
	for ( k = ds.n-1; k >=j  ; k--) 
	   ds.nodes[k+1]= ds.nodes[k];
	ds.nodes[j]= new Maybay;
	*ds.nodes[j]=mb; ds.n++;
	return 1;
	
}
void initialize(NODEPTRCB &First)
{
   First = NULL;
}
NODEPTRCB New_node(void)
{
   NODEPTRCB p;
   p = (NODEPTRCB)malloc(sizeof(struct nodeCB));
   return(p);
}	


NODEPTRCB search_info(NODEPTRCB First, char x[16])
{
	NODEPTRCB p;int ii=1;
	p = First;
	while(p != NULL && strcmp(p->cb.machbay,x)!=0){
		p = p->next;
	}
		
	return(p);
}
NODEPTRCB search_info2(NODEPTRCB First)
{
	NODEPTRCB p;char sohieu[16];
	p = First;
	NhapChuoi (  "Nhap so hieu chuyen bay: ", sohieu) ;int c=1;
			 if (strcmp(sohieu,"0")==0) return NULL;
	   if (CheckChuoi(sohieu,1,15)==-1) 
	   {   
	   
	       BaoLoi ("Dinh dang sai "); 
	       return NULL;
	   }
		if (strlen(sohieu)<15){
	   	char f[15]=" ";
	   	for (int i=0;i<14-strlen(sohieu);i++)  strcat(f," ");
		   strcat(f,sohieu);
		   strcpy(sohieu,f);
	   }
	while(p != NULL && strcmp(p->cb.machbay,sohieu)!=0){
		p = p->next;
	}
	if (p==NULL) {BaoLoi(" Khong co so hieu chuyen bay nay!!! "); return NULL;
	}
			else {
				char tt[15];
					if (strcmp(p->cb.trangthai,"0")==0) strcpy(tt,"Huy chuyen");
					if (strcmp(p->cb.trangthai,"1")==0) strcpy(tt,"Con ve");
					if (strcmp(p->cb.trangthai,"2")==0) strcpy(tt,"Het ve");
					if (strcmp(p->cb.trangthai,"3")==0) strcpy(tt,"Hoan tat");
				printf("\n %15s %30s %15s %25s %10s \n", p->cb.machbay, p->cb.noiden,p->cb.sohieumaybay, p->cb.timebay, tt);
		
	return(p);
}}
int Empty(NODEPTRCB First)
{
   return(First == NULL ? TRUE : FALSE);
}
int NhapCB(nodeCB &ds, ChuyenBay &cb, listmb &ds1){
	int i=1;char sh[30];char str[50];int d;
	
		while (i==1){
		 NhapChuoi (  "Nhap so hieu chuyen (=0 la ket thuc) : ", sh);
	   if (strcmp(sh,"0")==0) return 0;
	   if (CheckChuoi(sh,1,15)==-1) 
	   {   
	   
	       BaoLoi ("Dinh dang sai "); 
	       continue;
	   }
		if (strlen(sh)<15){
	   	char f[15]=" ";
	   	for (int i=0;i<14-strlen(sh);i++)  strcat(f," ");
		   strcat(f,sh);
		   strcpy(sh,f);
	   }
	   strcpy(cb.machbay,sh);
	   p=search_info(First, sh);if (p==NULL) strcmp(cb.machbay,sh); else {
	   BaoLoi ("So hieu bi trung "); 
	       continue;
	   }
	   i=0;	   
	}
	
	i=1;
	while (i==1){
		NhapChuoi (  "Nhap noi den: ", str);
		if (strcmp(str,"0")==0) return 0;
		if (CheckChuoi(str,1,30)==-1) 
	   {   
			BaoLoi ("Dinh dang sai "); 
	       continue;
	   }
	   strcpy(cb.noiden,str);strcpy(str,"");i=0;
	 }
	 i=1;
	 while (i==1){
		NhapChuoi (  "Nhap so hieu may bay: ", sh);
		if (strcmp(sh,"0")==0) return 0;
		if (CheckChuoi(sh,1,15)==-1) 
	   {   
			BaoLoi ("Dinh dang sai "); 
	       continue;
	   }
	   if (strlen(sh)<15){
	   	char f[15]=" ";
	   	for (int i=0;i<14-strlen(sh);i++)  strcat(f," ");
		   strcat(f,sh);
		   strcpy(sh,f);
	   }
	   int search=Search(ds1,sh);
	   if (search==-1){
	       BaoLoi ("Khong co so hieu may bay nay");
	       continue;
	   }
	   	d=TimMb(ds1,sh);
	   	
	   	strcpy(cb.sohieumaybay,sh);strcpy(sh,"");i=0;
	   	}
	 
	 
	 i=1;
	 while (i==1){
		NhapChuoi (  "Nhap time khoi hanh: ", str);
		if (strcmp(str,"0")==0) return 0;
		/*if (CheckChuoi(str,1,25)==-1) 
	   {   
			BaoLoi ("Dinh dang sai, nhap lai -HH:MM DD/MM/YYYY-"); 
	       continue;
	   }*/
	   strcpy(cb.timebay,str);strcpy(str,"");i=0;
	 }
	 TangLuotBay(ds1,d);
	 strcpy(cb.trangthai,"1");
	 return 1;
	
}
void Insert_first(NODEPTRCB &First, ChuyenBay x)
{
   NODEPTRCB p;
   p = New_node();
   p->cb = x;
   p->next = First;
   First = p;
   
}
void Insert_after(NODEPTRCB p, ChuyenBay x)
{
   NODEPTRCB q;
   if(p == NULL)
		printf("khong them sinh vien vao danh sach duoc");
   else
   {
      q = New_node();
      q->cb = x;
      q->next = p->next;
      p->next = q;
      
   }
}

void InsertOrderCB(NODEPTRCB &First, ChuyenBay x)
{	

	
   NODEPTRCB p, q;  // q la nut truoc, p la nut sau
   q = NULL;
   for(p = First; p != NULL && strcmp(p->cb.machbay,x.machbay)<0; p = p->next)
      q = p;
   if(q == NULL)  // them nut vao dau danh sach lien ket
      Insert_first(First, x);
   else           // them nut vao sau nut q
      Insert_after(q, x);
}


void Delete_first(NODEPTRCB &First)
{
   NODEPTRCB p;
   if(Empty(First))
      printf("Khong co sinh vien trong danh sach");
   else
   {
      p = First;    // nut can xoa la nut dau
      First = p->next;
      free(p);
   }
}

void Delete_after(NODEPTRCB p)
{
   NODEPTRCB q;
   // neu p la NULL hoac p chi nut cuoi
   if((p == NULL) || (p->next == NULL))
      printf("khong xoa sinh vien nay duoc");
   else
   {
      q = p->next;  // q chi nut can xoa
      p->next = q->next;
      free(q);
   }
}

void traverse(NODEPTRCB First)
{
   NODEPTRCB p;
   int stt = 0;
   p = First;
   if(p == NULL)
      printf("\n   (Khong co chuyen bay trong danh sach)");
	printf( "  Ma chuyen bay                       Noi den      so hieu may bay              Time         Trang thai");
   while(p != NULL)
   {
      char tt[15];
					if (strcmp(p->cb.trangthai,"0")==0) strcpy(tt,"Huy chuyen");
					if (strcmp(p->cb.trangthai,"1")==0) strcpy(tt,"Con ve");
					if (strcmp(p->cb.trangthai,"2")==0) strcpy(tt,"Het ve");
					if (strcmp(p->cb.trangthai,"3")==0) strcpy(tt,"Hoan tat");
				
				printf("\n %15s %30s %15s %25s %10s ", p->cb.machbay, p->cb.noiden,p->cb.sohieumaybay, p->cb.timebay, tt);
      p = p->next;
   }
}

void SuaCB(nodeCB &ds, ChuyenBay &cb, listmb ds1, NODEPTRCB p){
	strcpy(cb.machbay,p->cb.machbay);
	strcpy(cb.trangthai,p->cb.trangthai);
	int i=1;char sh[30];char str[50];
	while (i==1){
		NhapChuoi (  "Nhap noi den: ", str);
		
		if (CheckChuoi(str,1,30)==-1) 
	   {   
			BaoLoi ("Dinh dang sai "); 
	       continue;
	   }
	   strcpy(cb.noiden,str);strcpy(str,"");i=0;
	 }
	 i=1;
	 while (i==1){
		NhapChuoi (  "Nhap so hieu may bay: ", sh);
		
		if (CheckChuoi(sh,1,15)==-1) 
	   {   
			BaoLoi ("Dinh dang sai "); 
	       continue;
	   }
	   if (strlen(sh)<15){
	   	char f[15]=" ";
	   	for (int i=0;i<14-strlen(sh);i++)  strcat(f," ");
		   strcat(f,sh);
		   strcpy(sh,f);
	   }
	   int search=Search(ds1,sh);
	   if (search==-1){
	       BaoLoi ("Khong co so hieu may bay nay");
	       continue;
	   }
	   	
	   	strcpy(cb.sohieumaybay,sh);strcpy(sh,"");i=0;
	   	}
	 
	 
	 i=1;
	 while (i==1){
		NhapChuoi (  "Nhap time khoi hanh: ", str);
		
		/*if (CheckChuoi(str,1,25)==-1) 
	   {   
			BaoLoi ("Dinh dang sai, nhap lai -HH:MM DD/MM/YYYY-"); 
	       continue;
	   }*/
	   strcpy(cb.timebay,str);strcpy(str,"");i=0;
	 }
	 p->cb=cb;
}
void XoaCB(NODEPTRCB &First, char x[16] ){
	NODEPTRCB p, q;  // q la nut truoc, p la nut sau
   q = NULL;
   for(p = First; p != NULL && strcmp(p->cb.machbay,x)!=0; p = p->next)
      q = p;
   if(p == First)  // them nut vao dau danh sach lien ket
      Delete_first(First);
   else           // them nut vao sau nut q
      Delete_after(q);	
}
void HuyCB(nodeCB &ds, ChuyenBay &cb, listmb ds1, NODEPTRCB p){
	char yn[5];
	NhapChuoi (  "\nBan chac chan huy chuyen bay nay? ( nhap Y de dong y)", yn) ;
	if (strcmp(yn,"Y")==0) 
	strcpy (cb.trangthai,"0");
	strcpy (cb.machbay,p->cb.machbay);
	strcpy (cb.noiden,p->cb.noiden);
	strcpy (cb.sohieumaybay,p->cb.sohieumaybay);
	strcpy (cb.timebay,p->cb.timebay);
	p->cb=cb;
}
void SaveFileCB(NODEPTRCB First,char *filename) {
 FILE * f; 
 if ((f=fopen(filename,"w"))==NULL)
 {  BaoLoi ("Loi mo file de ghi"); return ;
 }
 NODEPTRCB p;
 p = First;
 while(p != NULL)
   {
   	  fwrite (&(p->cb),sizeof(p->cb),1,f);
      p = p->next;
   }
   
 fclose(f);
 BaoLoi ("Da ghi xong danh sach chuyen bay vao file");

}
void OpenFileCB(NODEPTRCB &First, char *filename) {
	FILE * f; ChuyenBay cb;
	if ((f=fopen(filename,"r"))==NULL)
		{  BaoLoi ("Loi mo file de doc"); return ;
		}
	NODEPTRCB p;
	int co=0;	
	while  (fread (&cb,sizeof(cb),1,f)!=0) {
			InsertOrderCB(First,cb);
	}
	
	fclose(f);
	BaoLoi ("Da load xong danh sach may bay vao bo nho");
	
}

int main (){ 
  system ("cls");
  char filenameMB[80]="D:\\DSMB.TXT"; 
  char filenameCB[80]="D:\\DSCB.TXT"; 
	
  int chon,chon2;  listmb dsmb; dsmb.n=0; char sohieu[16]; Maybay mb; ChuyenBay cb; nodeCB dscb;int chona=1;int chonb=1;
  initialize(First);
  OpenFileMB(dsmb,filenameMB);
  OpenFileCB(First,filenameCB);
  
  do
  {
    chon = MenuDong (thucdon,chona);
    system ("cls");
    switch (chon ){
    case 1: {  	
				if (NhapMB(dsmb, mb)==1) InsertOrderMB (dsmb,mb);
              	break;
            };
    case 2: 	{LietKe(dsmb); 
		break;
	}
    case 3: { 	
				NhapChuoi (  "Nhap so hieu may bay: ", sohieu) ;int c=1;
    			
    			int d=TimMb(dsmb,sohieu);
				if (d>=0){
    				while (c==1){
				      	chon2 = MenuDong2 (thucdon2);
				      	switch (chon2){
				      		case 1: {c=0;
								break;
							  }
				      		case 2: { SuaMb(dsmb,d);
				      					
				      				c=0;
								break;
							  }
				      		case 3: {XoaMb(dsmb,d); 
				      				c=0;
								break;
							  }
						  }
					  } 
				} else BaoLoi(" Khong co so hieu may bay nay!!! ");
	       
		  strcpy(sohieu,"");break;
	    };
	case 4: { 
		  break;
	    };    
	
    case 5 :   {SaveFileMB(dsmb,filenameMB);break;}
    case 7 :	{ if (NhapCB(dscb,cb,dsmb)==1) 	InsertOrderCB (First,cb);
    		break;	
		}
	case 8 : {
		traverse(First);
		getche();
		break;
	}
	case 9 :{ 
				int c=1;
				p = search_info2(First);
				if (p!=NULL) 
				
					while (c==1){
				      	chon2 = MenuDong2 (thucdon2);
				      	switch (chon2){
				      		case 1: {c=0;
								break;
							  }
				      		case 2: { 
										printf( " So hieu chuyen bay : %s", p->cb.machbay);cout<<"\n";
										SuaCB(dscb,cb,dsmb,p);
							  			
				      					
				      				  c=0;
								break;
							  }
				      		case 3: { printf( " So hieu chuyen bay : %s", p->cb.machbay);cout<<"\n";
							  			XoaCB(First,sohieu); 
				      					c=0;
								break;
							  }
						  }
					  }
					  break;
			}
	case 10: {	
				p = search_info2(First);
				if (p!=NULL) HuyCB(dscb,cb,dsmb,p);
				break;
				}

	case 11: {
		SaveFileCB(First,filenameCB);
		break;
	}
	}
  } while (1);
  return 0;
  }
