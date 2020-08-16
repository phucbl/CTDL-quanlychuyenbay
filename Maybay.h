#pragma once 
#include "Help.h"
#include <stdio.h>
#include <conio.h>
struct Maybay {
  char sohieumb[15];
  char loaimb [40];
  int soday;
  int sodong;
  int luotbay;
};
struct listmb {
  int n;
  Maybay *nodes [MAXLIST];
};
int Search(listmb ds, char x[15]) {
	 for (int i =0; i < ds.n ; i++)
     if (strcmp(ds.nodes[i]->sohieumb, x)==0)  { gotoxy(cotNhap,dongNhap+1);
     	printf( "Thong tin:       So hieu MB         Loai MB        So Day   So Dong\n");
     	gotoxy(cotNhap+6,dongNhap+2);
		 printf (" %8s \t\t %-12s \t%-5d\t %-5d\n", ds.nodes[i]->sohieumb, 
     ds.nodes[i]->loaimb, ds.nodes[i]->soday, ds.nodes[i]->sodong);
     	return i;
	 }
  return -1;
}
int Search2(listmb ds, char x[15]) {
	 for (int i =0; i < ds.n ; i++)
     if (strcmp(ds.nodes[i]->sohieumb, x)==0)  
     	return i;
	 
  return -1;
}
int  NhapMB ( listmb &ds, Maybay &mb){
	char sh[40];char d[5]="";
	int i=1;
	while (i==1){
		gotoxy(cotNhap,dongNhap);
	   NhapChuoi (  "Nhap so hieu may bay (=0 la ket thuc) : ", sh,14);
	   if (strcmp(sh,"0")==0) return 0;
	   if (CheckChuoi(sh,1,15)==-1) 
	   {   
	   		BaoLoi ("Dinh dang sai ");
			continue;
	   }
	   if (strlen(sh)<14){
	   	char f[15]=" ";
	   	for (int i=0;i<13-strlen(sh);i++)  strcat(f," ");
		   strcat(f,sh);
		   strcpy(sh,f);
	   }
	   int search=Search2(ds,sh);
	   if (search>=0){
	       BaoLoi ("So hieu bi trung ");
	       gotoxy(cotNhap,dongNhap); cout<<"                                                   ";
	       continue;
	   }
	   	strcpy(mb.sohieumb,sh);strcpy(sh,"");i=0;//cout<<strlen(mb.sohieumb);}
	   	}
	   	i=1;
	while (i==1){
		gotoxy(cotNhap,dongNhap+1);
		 NhapChuoi (  "Nhap loai may bay: ",sh,39);
		if (CheckChuoi(sh,1,50)==-1) {
	       BaoLoi ("Dinh dang sai "); 
	       continue;
	   }
		strcpy(mb.loaimb,sh);strcpy(sh,"");i=0;//cout<<strlen(mb.sohieumb);}
	}
	i=1;
	while (i==1){  
		
		gotoxy(cotNhap,dongNhap+2);
	    NhapChuoi("Nhap so day: ",d,1);
		int b=CheckChuoi(d,2,10);
		if (b==-1)
		{	
			
	   		BaoLoi ("Nhap lai so day (<10)  ");
	   		gotoxy(cotNhap,dongNhap+2); cout<<"                                                   ";
			continue;
	   	}
		mb.soday=b;i=0;}
		i=1;
		
	   	while (i==1){  
		
		gotoxy(cotNhap,dongNhap+3);
	    NhapChuoi ("Nhap so dong: ",d,2);int b=CheckChuoi(d,2,51);
	    if (b==-1)
		{
	   		BaoLoi ("Nhap lai so dong (<=50)  ");
	   		gotoxy(cotNhap,dongNhap+3); cout<<"                                                   ";
			continue;
	   	}
		mb.sodong=b;i=0;}
		mb.luotbay=0;BaoLoi("Them may bay thanh cong.");
	    return 1;	
	}
void LietKe (listmb ds) {
	SetColor(LightCyan);
		gotoxy (50,1);
		printf ("DANH SACH MAY BAY \n");
		gotoxy (1,3);
		printf ("%15s%30s %35s %21s\n","So hieu","Loai may bay","So day","So dong");
		SetColor(Yellow);//ve khung
		gotoxy (0,0); 
		cout << char(201) << setw(110) << setfill(char(205)) << char(205) << char (187);
		
		gotoxy (0,1);cout << char(186);gotoxy (111,1);cout<<char(186);
		
		gotoxy (0,2);
		cout << char(204) << setw(17) << setfill(char(205)) <<char(209)<< setw(51) << setfill(char(205)) <<char(209) 
		<< setw(21) << setfill(char(205)) <<char(209)<< setw(22) << setfill(char(205)) << char (185);
		
		gotoxy (0,3);cout << char(186);gotoxy (111,3);cout<<char(186);
		
		gotoxy(0,4);	
		cout << char(204) << setw(17) << setfill(char(205)) <<char(216)<< setw(51) << setfill(char(205)) <<char(216) 
		<< setw(21) << setfill(char(205)) <<char(216)<< setw(22) << setfill(char(205)) << char (185);
		
		gotoxy (17,3);cout<<char(179); // 3 canh nho o giua
		gotoxy (68,3);cout<<char(179);
		gotoxy (89,3);cout<<char(179);
	
	Normal();	
 for (int i =0 ; i < ds.n ; i++){
 	gotoxy (1,i+5);
 	SetColor(White);printf ("%15s %50s \t%8d %21d", ds.nodes[i]->sohieumb,
    ds.nodes[i]->loaimb, ds.nodes[i]->soday, ds.nodes[i]->sodong);
	SetColor(Yellow);
	gotoxy (0,i+5);cout << char(186); //  canh ngoai cung 2 ben
	gotoxy (17,i+5);cout<<char(179); //3 canh nho o giua
	gotoxy (68,i+5);cout<<char(179);
	gotoxy (89,i+5);cout<<char(179);    
    gotoxy (111,i+5);cout<<char(186)<<"\n";
 }

  cout << char(200) << setw(17) << setfill(char(205)) <<char(207)<< setw(51) << setfill(char(205)) <<char(207) // canh duoi cung
	<< setw(21) << setfill(char(205)) <<char(207) << setw(22) << setfill(char(205)) << char (188);
 getch();
}
void ThongKeLuotBay (listmb ds) {
	SetColor(LightCyan);
 	gotoxy (50,1);
	printf ("THONG KE LUOT BAY");
	gotoxy (1,3);
 	printf ("%15s %30s %45s","So hieu","Loai","Luot Bay");
 	SetColor(Yellow);//ve khung
		gotoxy (0,0); 
		cout << char(201) << setw(110) << setfill(char(205)) << char(205) << char (187);
		
		gotoxy (0,1);cout << char(186);gotoxy (111,1);cout<<char(186);
		
		gotoxy (0,2);
		cout << char(204) << setw(17) << setfill(char(205)) <<char(209)<< setw(51) << setfill(char(205)) <<char(209) 
		<< setw(43) << setfill(char(205)) << char (185);
		
		gotoxy (0,3);cout << char(186);gotoxy (111,3);cout<<char(186);
		
		gotoxy(0,4);	
		cout << char(204) << setw(17) << setfill(char(205)) <<char(216)<< setw(51) << setfill(char(205)) <<char(216) 
		<< setw(43) << setfill(char(205)) << char (185);
		
		gotoxy (17,3);cout<<char(179); // 3 canh nho o giua
		gotoxy (68,3);cout<<char(179);
		Normal();
 	
 for (int i =0 ; i < ds.n ; i++){
 	gotoxy (1,i+5);
 	SetColor(White);
  	printf ("%15s %30s %45d \n", ds.nodes[i]->sohieumb, 
     ds.nodes[i]->loaimb, ds.nodes[i]->luotbay);
 	SetColor(Yellow);
	gotoxy (0,i+5);cout << char(186); //  canh ngoai cung 2 ben
	gotoxy (17,i+5);cout<<char(179); //3 canh nho o giua
	gotoxy (68,i+5);cout<<char(179);
	gotoxy (111,i+5);cout<<char(186)<<"\n";
 }
 	cout << char(200) << setw(17) << setfill(char(205)) <<char(207)<< setw(51) << setfill(char(205)) <<char(207) // canh duoi cung
	<< setw(43) << setfill(char(205)) << char (188);
 getch();
}


void SuaMb( listmb &ds, int i) { 
	 
	 int day,dong;
        char yn[5];   	
		gotoxy(cotMenuSua,dongMenuSua+1);
		printf( "Sua so hieu may bay : %s", ds.nodes[i]->sohieumb);cout<<"\n";
		char text[5];
		char c[50];
		gotoxy(cotMenuSua,dongMenuSua+3);
		cout<<"         ";
		int ooo =1;
		while (ooo==1){
			gotoxy(cotMenuSua,dongMenuSua+2);
			NhapChuoi("Nhap loai may bay: ",c,50);
			if (CheckChuoi(c,1,50)==-1) {
	       		BaoLoi ("Dinh dang sai ");
	       		gotoxy(cotMenuSua,dongMenuSua+2);cout<<"                                                   ";
	       		continue;
	   			}
	   		ooo=0;
		}
		ooo=1;
		
		while (ooo==1){
			gotoxy(cotMenuSua,dongMenuSua+3);
			NhapChuoi (  "Nhap so day: ", text, 2) ;day=CheckChuoi(text,2,10);
			if (day==-1) {
	       		BaoLoi ("So day phai <10");
	       		gotoxy(cotMenuSua,dongMenuSua+3);cout<<"                                                   ";
	       		continue;
	   			}
	   			
	   		ooo=0;
		}
		ooo=1;
		while (ooo==1){
			gotoxy(cotMenuSua,dongMenuSua+4);
			NhapChuoi (  "Nhap so dong: ", text,2) ;dong=CheckChuoi(text,2,50);
			if (dong==-1) {
	       BaoLoi ("So dong phai <50");
	       gotoxy(cotMenuSua,dongMenuSua+4);cout<<"                                                   ";
	       continue;
	   			}
	   		ooo=0;
		}
		
		
		gotoxy(cotMenuSua,dongMenuSua+5);
		NhapChuoi (  "Chac chan sua thong tin may bay nay (nhap Y de dong y): ", yn,1) ;
		if (strcmp(yn,"Y")==0||strcmp(yn,"y")==0){
			strcpy (ds.nodes[i]->loaimb,c);
			ds.nodes[i]->soday=day;
			ds.nodes[i]->sodong=dong;
			BaoLoi("Sua thong tin may bay thanh cong"); 
		   }
	   
		
		}
//}while (a==-1);
void TangLuotBay( listmb ds, int i) { 
	ds.nodes[i]->luotbay++;
}
void GiamLuotBay( listmb ds, int i) { 
	ds.nodes[i]->luotbay--;
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
 //BaoLoi ("Da load xong danh sach may bay vao bo nho");

}
void XoaMb(listmb &ds, int i){
  
   if (ds.nodes[i]->luotbay>0) {
   	cout<<"May bay da co lich bay. Khong the xoa"; getch(); return ;
   }
   char yn[5];	
   		gotoxy(cotMenuSua+7,dongMenuSua+3);
		printf( "so hieu may bay : %s", ds.nodes[i]->sohieumb);cout<<"\n";
		gotoxy (cotMenuSua,dongMenuSua+4);
   NhapChuoi (  "Ban co chac chan xoa so hieu may bay nay (nhap Y de dong y): ", yn,1) ;
   if (strcmp(yn,"Y")==0){
   
   delete  ds.nodes[i];
     for (int j=i+1; j <ds.n; j++)
       ds.nodes[j-1]=ds.nodes[j];
       
     ds.n--;  
     BaoLoi("Xoa thong tin may bay thanh cong");
	}


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
void InsertOrderLuotBay(listmb &ds, Maybay mb){
	int j, k;
	if (ds.n ==MAXLIST ) return ;
	for (j=0; j < ds.n && ds.nodes[j]->luotbay>mb.luotbay; j++ );
	for ( k = ds.n-1; k >=j  ; k--) 
	   ds.nodes[k+1]= ds.nodes[k];
	ds.nodes[j]= new Maybay;
	*ds.nodes[j]=mb; ds.n++;
	return ;
}
