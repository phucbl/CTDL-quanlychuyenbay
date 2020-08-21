#pragma once
#include "datetime2.h"
#include "HanhKhach.h"
struct Ve
{
	int trth = 0;
	char cmnd[13];
};
typedef struct Ve VE;

struct ChuyenBay{
  char machbay[15];
  char noiden[30];
  char trangthai[5];
  char sohieumaybay[15];
  VE *dsve;//= new Ve[MAXVE];
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
	NODEPTRCB p;
	p = First;
	while(p != NULL && strcmp(p->cb.machbay,x)!=0){
		p = p->next;
	}
	return(p);
}

int Empty(NODEPTRCB First)
{
   return(First == NULL ? TRUE : FALSE);
}
int NhapCB(nodeCB &ds, ChuyenBay &cb, listmb ds1){
	int i=1;char sh[30];char str[50];int d;DATETIME time;
		while (i==1){
			gotoxy(cotNhap,dongNhap);
		 NhapChuoi (  "Nhap ma chuyen bay (=0 la ket thuc) : ", sh,14);
	   if (strcmp(sh,"0")==0) return 0;
	   if (CheckChuoi(sh,5,14)==-1) 
	   {   
	       BaoLoi ("Dinh dang sai "); 
	       continue;
	   }
		ThemCach(sh);
	   strcpy(cb.machbay,sh);
	   p=search_info(First, sh);if (p==NULL) strcmp(cb.machbay,sh); else {
	   BaoLoi ("Ma chuyen bay bi trung "); 
	       continue;
	   }
	   i=0;	   
	}
	
	i=1;
	while (i==1){
	 	gotoxy(cotNhap,dongNhap+1);
		NhapChuoi (  "Nhap so hieu may bay: ", sh,14);
		if (strcmp(sh,"0")==0) return 0;
		if (CheckChuoi(sh,5,14)==-1) 
		{   
			BaoLoi ("Dinh dang sai "); 
			continue;
		} 
		ThemCach(sh);
		int search=Search(ds1,sh);
		if (search==-1){
	       BaoLoi ("Khong co so hieu may bay nay");
	       continue;
		}
	   	d=search;	   	
	   	strcpy(cb.sohieumaybay,sh);strcpy(sh,"");i=0;
	   	}
	
	i=1;	 
	while (i==1){
		gotoxy(cotNhap,dongNhap+4);
		NhapChuoi (  "Nhap noi den: ", str,29);
		if (strcmp(str,"0")==0) return 0;
		if (CheckChuoi(str,4,29)==-1)
		{   
			BaoLoi ("Dinh dang sai "); 
	       continue;
		}
		CheckChuoi(str,4,29);
		strcpy(cb.noiden,str);strcpy(str,"");i=0;
	}	 
	i=1;
	gotoxy(cotNhap,dongNhap+5);
	if (ValidDateTime(time)==0) return 0;
	TangLuotBay(ds1,d);
	cb.socot=ds1.nodes[d]->soday;cb.sodong=ds1.nodes[d]->sodong;cb.timebay=time;cb.dsve = new Ve[MAXVE];
	if (CompareDateTimeToNow(cb.timebay)==0) strcpy(cb.trangthai,"3"); else strcpy(cb.trangthai,"1");
	BaoLoi ("Da them chuyen bay.");
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
		printf("khong them chuyen bay vao danh sach duoc");
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
   for(p = First; p != NULL && strcmp(p->cb.machbay,x.machbay)>0; p = p->next)
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
      printf("Khong co chuyen bay trong danh sach");
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
      printf("Khong xoa chuyen bay duoc");
   else
   {
      q = p->next;  // q chi nut can xoa
      p->next = q->next;
      free(q);
   }
}

void traverse(NODEPTRCB &First)
{		system ("cls");
		SetColor(LightCyan);
		gotoxy (50,1);
		printf ("DANH SACH CHUYEN BAY ");
		gotoxy (1,3);
		printf( "  Ma chuyen bay                Noi den             so hieu may bay           Time            Trang thai");
		SetColor(Yellow);//ve khung
		gotoxy (0,0); 
		cout << char(201) << setw(110) << setfill(char(205)) << char(205) << char (187);
		
		gotoxy (0,1);cout << char(186);gotoxy (111,1);cout<<char(186);
		
		gotoxy (0,2);
		cout << char(204) << setw(17) << setfill(char(205)) <<char(209)<< setw(31) << setfill(char(205)) <<char(209)<< setw(20) << setfill(char(205)) <<char(209) 
		<< setw(21) << setfill(char(205)) <<char(209)<< setw(22) << setfill(char(205)) << char (185);
		
		gotoxy (0,3);cout << char(186);gotoxy (111,3);cout<<char(186);
		
		gotoxy(0,4);	
		cout << char(204) << setw(17) << setfill(char(205)) <<char(216)<< setw(31) << setfill(char(205)) <<char(216)<< setw(20) << setfill(char(205)) <<char(216) 
		<< setw(21) << setfill(char(205)) <<char(216)<< setw(22) << setfill(char(205)) << char (185);
		
		gotoxy (17,3);cout<<char(179); // 3 canh nho o giua
		gotoxy (48,3);cout<<char(179);
		gotoxy (68,3);cout<<char(179);
		gotoxy (89,3);cout<<char(179);
	
	Normal();
   NODEPTRCB p;
   int stt = 0;
   p = First;
   if(p == NULL)
      printf("\n   (Khong co chuyen bay trong danh sach)");
	
   while(p != NULL)
   {	if (strcmp(p->cb.trangthai,"1")==0||strcmp(p->cb.trangthai,"2")==0)
      if (CompareDateTimeToNow(p->cb.timebay)==0) strcpy(p->cb.trangthai,"3");
	  char tt[15];
					if (strcmp(p->cb.trangthai,"0")==0) strcpy(tt,"Huy chuyen");
					if (strcmp(p->cb.trangthai,"1")==0) strcpy(tt,"Con ve");
					if (strcmp(p->cb.trangthai,"2")==0) strcpy(tt,"Het ve");
					if (strcmp(p->cb.trangthai,"3")==0) strcpy(tt,"Hoan tat");
		gotoxy (1,stt+5);SetColor(White);
				printf(" %15s %30s %15s       ", p->cb.machbay, p->cb.noiden,p->cb.sohieumaybay);OutputDateTime(p->cb.timebay); printf("%20s ",tt);
      p = p->next;
	  
	SetColor(Yellow);
	gotoxy (0,stt+5);cout << char(186); //  canh ngoai cung 2 ben
	gotoxy (17,stt+5);cout<<char(179); //3 canh nho o giua
	gotoxy (48,stt+5);cout<<char(179);
	gotoxy (68,stt+5);cout<<char(179);
	gotoxy (89,stt+5);cout<<char(179);    
    gotoxy (111,stt+5);cout<<char(186)<<"\n";
    stt++;
   }
   cout << char(200) << setw(17) << setfill(char(205)) <<char(207)<< setw(31) << setfill(char(205)) <<char(207)<< setw(20) << setfill(char(205)) <<char(207) // canh duoi cung
	<< setw(21) << setfill(char(205)) <<char(207) << setw(22) << setfill(char(205)) << char (188);
 getch();
}

void SuaCB(nodeCB &ds, ChuyenBay &cb, listmb ds1, NODEPTRCB p){
	strcpy(cb.machbay,p->cb.machbay);
	strcpy(cb.trangthai,p->cb.trangthai);
	strcpy(cb.noiden,p->cb.noiden);
	strcpy(cb.sohieumaybay,p->cb.sohieumaybay);
	DATETIME time;
	/*int i=1;char sh[30];char str[50];
	while (i==1){
		gotoxy(cotMenuSua,dongMenuSua+2);
		NhapChuoi (  "Nhap noi den: ", str,29);
		
		if (CheckChuoi(str,1,30)==-1) 
	   {   
			BaoLoi ("Dinh dang sai "); 
	       continue;
	   }
	   strcpy(cb.noiden,str);strcpy(str,"");i=0;
	 }
	 i=1;
	 while (i==1){
	 	gotoxy(cotMenuSua,dongMenuSua+3);
		NhapChuoi (  "Nhap so hieu may bay: ", sh,14);
		
		if (CheckChuoi(sh,1,15)==-1) 
	   {   
			BaoLoi ("Dinh dang sai "); 
	       continue;
	   }
	   ThemCach(sh);
	   int search=Search(ds1,sh);
	   if (search==-1){
	       BaoLoi ("Khong co so hieu may bay nay");
	       continue;
	   }
	   	
	   	strcpy(cb.sohieumaybay,sh);strcpy(sh,"");i=0;
	   	}
	 i=1;
	 while (i==1){
	 */
	 
	gotoxy(cotMenuSua,dongMenuSua+1);
	cout<<"Sua time khoi hanh. ";
	if (ValidDateTime(time)==0) return;
	gotoxy(cotMenuSua,dongMenuSua+2);
	cout<<"Ban chac chan huy chuyen bay nay?";
	int chonYN = MenuYN(menuYN,30);
	if (chonYN==0)
	cb.timebay=time; else return;
	if (CompareDateTimeToNow(p->cb.timebay)==0) strcpy(p->cb.trangthai,"3");
	p->cb=cb;
}
void XoaCB(nodeCB &dscb,ChuyenBay cb,NODEPTRCB pp){
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
void HuyCB(nodeCB &ds, listmb &dsmb, NODEPTRCB p){
	ChuyenBay cb;
	gotoxy(cotNhap,dongNhap+6);
	cout<<"Ban chac chan huy chuyen bay nay?";
	int chonYN = MenuYN(menuYN,30); //30 la do dai cua chuoi cout tren
	if (chonYN==0){
	strcpy (cb.trangthai,"0");
	strcpy (cb.machbay,p->cb.machbay);
	strcpy (cb.noiden,p->cb.noiden);
	strcpy (cb.sohieumaybay,p->cb.sohieumaybay);
	cb.timebay=p->cb.timebay;	
	p->cb=cb;
	}	
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
	int x = cotVe; int y = dongVe;
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
			x = cotVe;
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
	gotoxy((column + 1) * 5 -1, (row + 1) * 3 );
	cout << setw(3) << setfill('0') << text;
	Normal();strcpy(text,"");
	
	column = (current - 1) % cot;
	row = (current - 1) / cot;
	a=current%cot;if (a==0) a=cot; c=((current-1)/cot)+1;
		strcat(text,mangchucai[a]);strcat(text,mangchuso[c/10]);strcat(text,mangchuso[c%10]);
	SetBGColor(Red);
	gotoxy((column + 1) * 5 -1, (row + 1) * 3 );
	cout << setw(3) << setfill('0') << text;
	
	Normal();
	currposVeT = current;
}

int ChonVe(NODEPTRCB p)
{	system ("cls");
	ChuyenBay cb;
	cb=p->cb;
	/*char* macb2=strrev(cb.machbay);
	int i=0;
	while (macb2[i]!=char(32)) i++;
	while (macb2[i]==char(32)){
		macb2[i]=char(0);
		i++;
	}
	macb2=strrev(macb2);*/
	char* macb2=cb.machbay;
	while (macb2[0]==' ') strcpy(&macb2[0],&macb2[1]);
	
	gotoxy(cb.socot*6, 4); cout << "So do ghe chuyen bay "<<macb2;
	gotoxy(cb.socot*6, 5); cout << "So ve da ban: "<<cb.sovedaban<<"/"<<cb.socot*cb.sodong;
	gotoxy(cb.socot*6, 6); cout << "Noi den: "<<cb.noiden;
	gotoxy(cb.socot*6, 7); cout << "Time: ";OutputDateTime(cb.timebay);
	for (int i=1; i<=cb.sodong*3+dongVe-1;i++){				//canh khung 2 ben
		SetColor(Yellow);
		gotoxy (0,i);cout<<char(186);
		gotoxy (111,i);cout<<char(186);
		
	}
	gotoxy(0,cb.sodong*3+dongVe);cout << char(200) << setw(111) << setfill(char(205))  << char (188);//canh khung duoi cung
	Normal();
	//reset locate
	currposVe = 1;
	currposVeT = 1;
	MenuVe(p->cb);
	
	int keyboard_read = 0;
	int PASS = 1;
	int d=cb.sodong;
	int c=cb.socot;
	int sove=d*c;	
	SetColor(Yellow);
	gotoxy(0,0);cout << char(201) << setw(111) << setfill(char(205))  << char (187); //canh khung tren cung
	SetBGColor(Red);
	gotoxy(cotVe-1, dongVe);
	cout <<"A01"; Normal();
	
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
NODEPTRCB CheckVeChuyenBayKhac( nodeCB dscb, NODEPTRCB p, char cmnd[13]){
	
{	
	DATETIME dt1,dt2; // 'dt1' la thoi gian sau 'timebay' NH tieng, 'dt2' la thoi gian truoc 'timebay' NH tieng
	dt1=p->cb.timebay;dt2=p->cb.timebay; int nh=5;
	if (dt1.h+nh>23)
	{
		if ((dt1.y % 400 == 0) || (dt1.y % 4 == 0 && dt1.y % 100 != 0))	nDayOfMonth[2] = 29;
		if (dt1.m==nDayOfMonth[dt1.m]) 
			{
			if (dt1.m==12) 
			{
				dt1.y++;
				dt1.d=1;
				dt1.m=1;
				dt1.h=dt1.h+nh-24;
			}
			dt1.m++;
			dt1.d=1;
			dt1.h=dt1.h+nh-24;
			}
	dt1.d++;
	dt1.h=dt1.h+nh-24;
	}
	dt1.h=dt1.h+nh;
	if (dt2.h-nh<0)
	{
		
		if (dt2.d==1)
		{
			if(dt2.m==1){
			dt2.y--;
			dt2.m=12;
			dt2.d=31;
			dt2.h=24-dt2.h+nh;
			}
			if ((dt2.y % 400 == 0) || (dt2.y % 4 == 0 && dt2.y % 100 != 0))	nDayOfMonth[2] = 29;
			dt2.m--;
			dt2.d=nDayOfMonth[dt2.m];
			dt2.h=24-dt2.h+nh;
			
		}
		dt2.d--;
		dt2.h=24-dt2.h+nh;
		
	}
	dt2.h=dt2.h-nh;
	
	NODEPTRCB q;
	q=First;
	while (q!=NULL){
		int a=Compare2DateTime(q->cb.timebay,dt2);
		int b=Compare2DateTime(dt1,q->cb.timebay);
		//cout<<q->cb.machbay<<" ";OutputDateTime(dt1);cout<<" ";OutputDateTime(dt2);
		//cout<<q->cb.machbay<<" "<<a;cout<<" "<<b;
		if(Compare2DateTime(q->cb.timebay,dt2)==0 && Compare2DateTime(dt1,q->cb.timebay)==0)
		{
			for (int i=0; i<(q->cb.socot*q->cb.sodong);i++)
				if (strcmp(q->cb.dsve[i].cmnd,cmnd)==0) return q;
		}
		q=q->next;
	}
	return NULL;
}
}
void TimChuyenBayDatePlace( ){
	char noiden[30];DATETIME date;
	gotoxy(cotNhap,dongNhap);
	NhapChuoi("Nhap noi den: ",noiden,29);
	if (strcmp(noiden,"0")==0) return ;
	CheckChuoi(noiden,4,0);
	gotoxy(cotNhap,dongNhap+1);
	if (ValidDate(date)==0) return ;
	NODEPTRCB p; int count=0;
    p = First;
    while (p!=NULL){
    	if (strcmp(p->cb.noiden,noiden)==0 && IsSame2Date(date,p->cb.timebay)==1 &&strcmp(p->cb.trangthai,"1")==0){
    		int sovecon = (p->cb.sodong*p->cb.socot) - p->cb.sovedaban;
    		gotoxy(cotNhap,dongNhap+2);
    		cout<<"Thong tin: Ma CB     So ve con lai          Time";
    		gotoxy(cotNhap,dongNhap+3+count);
    		cout<<"\t"<<p->cb.machbay<<"\t\t"<<sovecon<<"\t\t";OutputDateTime(p->cb.timebay);
    		count++;
    		if (count == 10) {
    			gotoxy(cotNhap+5,dongNhap+3+count);
    			cout<<" Xem them ";
    			getch();
    			break;
			}
		}
		p=p->next;
	}
	if (count==0) {
		gotoxy(cotNhap,dongNhap+2);cout<<"Khong co chuyen bay phu hop!";
	}
	getch();    
}
void InDsHanhKhach(ChuyenBay cb){
	system("cls");
	gotoxy (20,1);
	printf ("DANH SACH HANH KHACH TREN CHUYEN BAY %s",cb.machbay);
	gotoxy (20,2);
	cout<<"Ngay gio khoi hanh: ";OutputDateTime(cb.timebay);cout<<". Noi den: "<<cb.noiden;
	gotoxy (1,4);
 	printf ("%4s %9s %16s %35s %33s","STT","So ghe","CMND","Ho Ten", "Phai");
 	SetColor(Yellow);//ve khung
	gotoxy (0,1);cout << char(186);gotoxy (111,1);cout<<char(186);
	gotoxy (0,2);cout << char(186);gotoxy (111,2);cout<<char(186);
	gotoxy (0,3);
	cout << char(204) << setw(6) << setfill(char(205)) <<char(209)<< setw(11) << setfill(char(205))<<char(209)
		<< setw(25) << setfill(char(205)) <<char(209) << setw(46) << setfill(char(205)) <<char(209)
		<< setw(23) << setfill(char(205)) << char (185);
	gotoxy (0,4);cout << char(186);gotoxy (111,4);cout<<char(186);
	gotoxy (6,4);cout<<char(179);
	gotoxy (17,4);cout<<char(179); // 3 canh nho o giua
	gotoxy (42,4);cout<<char(179);
	gotoxy (88,4);cout<<char(179);
		
	gotoxy(0,5);	
	cout << char(204) << setw(6) << setfill(char(205)) <<char(216)<< setw(11) << setfill(char(205)) <<char(216) 
		<< setw(25) << setfill(char(205)) <<char(216) << setw(46) << setfill(char(205)) <<char(216)
		<< setw(23) << setfill(char(205)) << char (185);
		Normal();
	int count =1;
	for (int i =0 ; i <=cb.socot*cb.sodong ; i++){
		if (cb.dsve[i].trth==1){
			char hoten[50]=""; char soghe[5]="";
			int a=(i+1)%cb.socot;if (a==0) a=cb.socot;int c=((i)/cb.socot)+1;
			strcat(soghe,mangchucai[a]);strcat(soghe,mangchuso[c/10]);strcat(soghe,mangchuso[c%10]);
			NODEPTRHK ptemp=TimVaLayCMND(tree,p->cb.dsve[i].cmnd);
			strcat(hoten,ptemp->ho);strcat(hoten," ");strcat(hoten,ptemp->ten);
			gotoxy (1,count+5);
			SetColor(White);
  			printf ("%4d %8s %20s %40s %-10s %15s", count, 
     		soghe, ptemp->cmnd, ptemp->ho, ptemp->ten, menuPhai[ptemp->phai]);
     		SetColor(Yellow);
			gotoxy (0,count+5);cout << char(186); //  canh ngoai cung 2 ben
			gotoxy (6,count+5);cout<<char(179); //3 canh nho o giua
			gotoxy (17,count+5);cout<<char(179);
			gotoxy (42,count+5);cout<<char(179);
			gotoxy (88,count+5);cout<<char(179);
			gotoxy (111,count+5);cout<<char(186);
			count++;
		} 
 }SetColor(Yellow);
 cout <<"\n" << char(200) << setw(6) << setfill(char(205)) <<char(207)<< setw(11) << setfill(char(205)) <<char(207) 
		<< setw(25) << setfill(char(205)) <<char(207) << setw(46) << setfill(char(205)) <<char(207)
		<< setw(23) << setfill(char(205)) << char (188);
gotoxy (0,0); 
		cout << char(201) << setw(110) << setfill(char(205)) << char(205) << char (187);
		Normal();
		if (count==1) {gotoxy(0,10);SetColor(Green);cout <<"Khong co hanh khach.";
		}
		getch();
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
//   		CheckChuoi(cb.noiden,4,0);
   	  fwrite (&(cb),sizeof(ChuyenBay),1,f);
   	  int soVe = cb.socot*cb.sodong;
			for (int i = 0; i < soVe; i++){
				/*char cmnd[13];strcpy(cmnd,cb.dsve[i].cmnd);
				if (strlen(cmnd)<9){
				char f[9]="0";
				for (int i=0;i<8-strlen(cmnd);i++)  strcat(f,"0");
				strcat(f,cmnd);
				strcpy(cb.dsve[i].cmnd,f);
				}*/
				fwrite(&(cb.dsve[i]),sizeof(Ve),1,f);
			}
				
				
      p = p->next;
   }
   
 fclose(f);
 //BaoLoi ("Da ghi xong danh sach chuyen bay vao file");

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
			 if (CompareDateTimeToNow(cb.timebay)==0) strcpy(cb.trangthai,"3");
			 InsertOrderCB(First,cb);
			
	}
	
	fclose(f);
	//BaoLoi ("Da load xong danh sach chuyen bay vao bo nho");
	
}
