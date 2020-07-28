#pragma once 
#include "Help.h"
struct Maybay {
  char sohieumb[15];
  char loaimb [50];
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
     if (strcmp(ds.nodes[i]->sohieumb, x)==0)  {
     	printf( " Thong tin : %8s \t %-5s \t%-5d\t %-5d\n", ds.nodes[i]->sohieumb, 
     ds.nodes[i]->loaimb, ds.nodes[i]->soday, ds.nodes[i]->sodong);
     	return i;
	 }
  return -1;
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
	   	for (int i=0;i<13-strlen(sh);i++)  strcat(f," ");
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
 printf ("                     DANH SACH MAY BAY \n");
 printf ("   So hieu              Loai            So day   So Dong     Luot Bay\n");
 for (int i =0 ; i < ds.n ; i++)
  printf ("%15s %15s \t%-5d\t %-5d %5d \n", ds.nodes[i]->sohieumb, 
     ds.nodes[i]->loaimb, ds.nodes[i]->soday, ds.nodes[i]->sodong,ds.nodes[i]->luotbay);
 getch();
}


void SuaMb( listmb &ds, int i) { 
	 //a=i;
        char yn[5];   		
		printf( " So hieu may bay : %s", ds.nodes[i]->sohieumb);cout<<"\n";
		int a,b;
		char c[50];
		NhapChuoi (  "Nhap loai may bay: ", c) ;
		cout<<"Nhap so day: ";cin>>a;
		cout<<"Nhap so dong: ";cin>>b;
		NhapChuoi (  "Chac chan sua thong tin may bay nay (nhap Y de dong y): ", yn) ;
		if (strcmp(yn,"Y")==0||strcmp(yn,"y")==0){
			strcpy (ds.nodes[i]->loaimb,c);
			ds.nodes[i]->soday=a;
			ds.nodes[i]->sodong=b;
			BaoLoi("Sua thong tin may bay thanh cong"); 
		   }
	   
		
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
 //BaoLoi ("Da load xong danh sach may bay vao bo nho");

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
