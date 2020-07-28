#pragma once
#include "datetime2.h"
struct Ve
{
	int trth = 0;
	char cmnd[13];
};
typedef struct Ve VE;

struct ChuyenBay{
  char machbay[15];
  //char timebay[25];
  char noiden[30];
  char trangthai[5];
  char sohieumaybay[15];
  VE *dsve= new Ve[MAXVE];
  int sovedaban = 0;
  int socot;
  int sodong;
  DATETIME timebay;
  
};

struct nodeCB {
	ChuyenBay cb;		
	struct nodeCB *next;
	
};
typedef nodeCB *NODEPTRCB;
	NODEPTRCB First;
	NODEPTRCB p;
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
	   	for (int i=0;i<13-strlen(sohieu);i++)  strcat(f," ");
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
int NhapCB(nodeCB &ds, ChuyenBay &cb, listmb ds1){
	int i=1;char sh[30];char str[50];int d;DATETIME time;
		
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
	   	for (int i=0;i<13-strlen(sh);i++)  strcat(f," ");
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
	   	for (int i=0;i<13-strlen(sh);i++)  strcat(f," ");
		   strcat(f,sh);
		   strcpy(sh,f);
	   }
	   int search=Search(ds1,sh);
	   if (search==-1){
	       BaoLoi ("Khong co so hieu may bay nay");
	       continue;
	   }
	   	d=search;	   	
	   	strcpy(cb.sohieumaybay,sh);strcpy(sh,"");i=0;
	   	}
	 
	 
	 i=1;
	 //while (i==1){
		//NhapChuoi (  "Nhap time khoi hanh: ", str);
		ValidDateTime(time);OutputDateTime(time);getch();
		//if (strcmp(str,"0")==0) return 0;
		/*if (CheckChuoi(str,1,25)==-1) 
	   {   
			BaoLoi ("Dinh dang sai, nhap lai -HH:MM DD/MM/YYYY-"); 
	       continue;
	   }*/
	   //strcpy(cb.timebay,str);strcpy(str,"");
	  // i=0;
	 //}
	 //TangLuotBay(ds1,d);
	 cb.socot=ds1.nodes[d]->soday;cb.sodong=ds1.nodes[d]->sodong;cb.timebay=time;
	if (CompareDateTimeToNow(cb.timebay)==0) strcpy(cb.trangthai,"3"); else strcpy(cb.trangthai,"1");
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

void Delete_after(NODEPTRCB &p)
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
      if (CompareDateTimeToNow(p->cb.timebay)==0) strcpy(p->cb.trangthai,"3");
	  char tt[15];
					if (strcmp(p->cb.trangthai,"0")==0) strcpy(tt,"Huy chuyen");
					if (strcmp(p->cb.trangthai,"1")==0) strcpy(tt,"Con ve");
					if (strcmp(p->cb.trangthai,"2")==0) strcpy(tt,"Het ve");
					if (strcmp(p->cb.trangthai,"3")==0) strcpy(tt,"Hoan tat");
				
				printf("\n %15s %30s %15s       ", p->cb.machbay, p->cb.noiden,p->cb.sohieumaybay);OutputDateTime(p->cb.timebay); printf("%10s ",tt);
      p = p->next;
   }
}

void SuaCB(nodeCB &ds, ChuyenBay &cb, listmb ds1, NODEPTRCB p){
	strcpy(cb.machbay,p->cb.machbay);
	strcpy(cb.trangthai,p->cb.trangthai);
	DATETIME time;
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
	   	for (int i=0;i<13-strlen(sh);i++)  strcat(f," ");
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
	 //while (i==1){
		//NhapChuoi (  "Nhap time khoi hanh: ", str);
		ValidDateTime(time);OutputDateTime(time);getch();
		/*if (CheckChuoi(str,1,25)==-1) 
	   {   
			BaoLoi ("Dinh dang sai, nhap lai -HH:MM DD/MM/YYYY-"); 
	       continue;
	   }*/
	   //strcpy(cb.timebay,str);strcpy(str,"");i=0;
	   cb.timebay=time;
	   if (CompareDateTimeToNow(p->cb.timebay)==0) strcpy(p->cb.trangthai,"3");
	 //}
	 p->cb=cb;
}
void XoaCB(nodeCB &dscb,ChuyenBay &cb,NODEPTRCB &pp){
	NODEPTRCB p, q;  // q la nut truoc, p la nut sau
   q = NULL;
   for(p = First; p != NULL && p!=pp; p = p->next)
      q = p;
   if(p == First)  
   {
   	Delete_first(First);
   }
      
   else           
      {
      	Delete_after(q);
	  }
	
}
void HuyCB(nodeCB ds, ChuyenBay cb, listmb ds1, NODEPTRCB p){
	char yn[5];
	NhapChuoi (  "\nBan chac chan huy chuyen bay nay? ( nhap Y de dong y)", yn) ;
	if (strcmp(yn,"Y")==0) 
	strcpy (cb.trangthai,"0");
	strcpy (cb.machbay,p->cb.machbay);
	strcpy (cb.noiden,p->cb.noiden);
	strcpy (cb.sohieumaybay,p->cb.sohieumaybay);
	cb.timebay=p->cb.timebay;
	p->cb=cb;
}

void BoxVe(int x, int y, char  text[5], int trth)
{	
	gotoxy(x - 2, y - 1);
	cout << char(201) << setw(3) << setfill(char(205)) << char(205) << char(187);
	cout << endl;
	gotoxy(x - 2, y);
	
	cout << char(186);if (trth == 1) SetBGColor(1); else SetBGColor(0); cout << setw(3) << setfill('0') << text ; Normal(); cout<< char(186);Normal();
	//SetBGColor(Purple);
	gotoxy(x - 2, y + 1);
	cout << char(200) << setw(3) << setfill(char(205)) << char(205) << char(188)<<" ";
	
}
void MenuVe(ChuyenBay cb)
{
	int x = 20; int y = 8;
	int n = cb.socot*cb.sodong;
	for (int i = 1; i <= n; i++)
	{	
		int trth=cb.dsve[i - 1].trth;
		char text[5]="";int a=i%cb.socot;if (a==0) a=cb.socot;int c=((i-1)/cb.socot)+1;
		strcat(text,mangchucai[a]);strcat(text,mangchuso[c/10]);strcat(text,mangchuso[c%10]);
		BoxVe(x, y, text, trth); Normal();
		x += 5;
		if (i % cb.socot == 0)
		{
			y += 3;
			x = 20;
		}

	}
	
}

void   EditMenu(int index, int preColor, int cot, int dong)
{
	int current = index;
	int column = (currposVeT - 1) % cot;
	int row = (currposVeT - 1) / cot;
	char text[5]="";int a=currposVeT%cot;if (a==0) a=cot;int c=((currposVeT-1)/cot)+1;
	strcat(text,mangchucai[a]);strcat(text,mangchuso[c/10]);strcat(text,mangchuso[c%10]);
	SetBGColor(Red);if (preColor == Blue) SetBGColor(Blue);  else SetBGColor(Black);
	gotoxy(13 + (column + 1) * 5 +1, (row + 1) * 3 + 5);
	cout << setw(3) << setfill('0') << text;
	Normal();strcpy(text,"");
	
	column = (current - 1) % cot;
	row = (current - 1) / cot;
	a=current%cot;if (a==0) a=cot; c=((current-1)/cot)+1;
		strcat(text,mangchucai[a]);strcat(text,mangchuso[c/10]);strcat(text,mangchuso[c%10]);
	SetBGColor(Red);
	gotoxy(13 + (column + 1) * 5 +1, (row + 1) * 3 + 5);
	cout << setw(3) << setfill('0') << text;
	
	Normal();
	currposVeT = current;
}


int ChonVe(NODEPTRCB p)
{	ChuyenBay cb;
	cb=p->cb;
	gotoxy(5, 5); cout << " CHON GHE MUON DAT";
	//reset locate
	currposVe = 1;
	currposVeT = 1;
	MenuVe(cb);
	
	int keyboard_read = 0;
	int PASS = 1;
	int d=cb.sodong;
	int c=cb.socot;
	int sove=d*c;	
	SetBGColor(Red);
	gotoxy(13 + (0 + 1) * 6, (0 + 1) * 3 + 5);
	cout << setw(3) << "A01"; Normal();
	
	while (PASS)
	{
		
		keyboard_read = getch();
		if (keyboard_read == 0)
			keyboard_read = getch();
		switch (keyboard_read)
		{
		case Down: //key down
			if (currposVe + c <= sove)
			{
				currposVe = currposVe + c;
				EditMenu(currposVe, cb.dsve[currposVeT - 1].trth,c,d);
			}

			break;

		case Up: //key up
			if (currposVe - c >= 1)
			{
				currposVe = currposVe - c;
				EditMenu(currposVe, cb.dsve[currposVeT - 1].trth,c,d);
			}

			break;
		case Left: //left
			if (currposVe > 1)
			{
				currposVe--;
				EditMenu(currposVe, cb.dsve[currposVeT - 1].trth,c,d);
			}
			break;
		case Right: //right
			
			if (currposVe < sove)
			{
				currposVe++;
				EditMenu(currposVe, cb.dsve[currposVeT - 1].trth,c,d);
			}
			break;
		case ESC: return -1; break;

		case ENTER: //enter
			PASS = 0;
			return currposVe;
			break;
		}//end switch keyboard
	}
	return 0;
}
void SaveFileCB(NODEPTRCB First,char *filename) {
 FILE * f; ChuyenBay cb;
 if ((f=fopen(filename,"w"))==NULL)
 {  BaoLoi ("Loi mo file de ghi"); return ;
 }
 NODEPTRCB p;
 p = First;
 while(p != NULL)
   {	
   		cb=p->cb;
   	  fwrite (&(cb),sizeof(ChuyenBay),1,f);
   	  int soVe = cb.socot*cb.sodong;
			for (int i = 0; i < soVe; i++)
				fwrite(&(cb.dsve[i]),sizeof(Ve),1,f);
      p = p->next;
   }
   
 fclose(f);
 BaoLoi ("Da ghi xong danh sach chuyen bay vao file");

}
void OpenFileCB(NODEPTRCB &First, char *filename) {
	FILE * f; ChuyenBay cb; Ve ve;
	if ((f=fopen(filename,"r"))==NULL)
		{  BaoLoi ("Loi mo file de doc"); return ;
		}
	
		
	while  (fread (&cb,sizeof(ChuyenBay),1,f)!=0){
			
			int n=cb.socot*cb.sodong;
			cb.dsve= new Ve[MAXVE];
			for (int i = 0; i < n; i++){
				
				fread (&(cb.dsve[i]),sizeof(Ve),1,f);
				
			}
			 
			 InsertOrderCB(First,cb);
			
	}
	
	fclose(f);
	//BaoLoi ("Da load xong danh sach chuyen bay vao bo nho");
	
}
