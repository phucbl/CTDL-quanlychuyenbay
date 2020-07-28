#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
//#include <windows.h>
#include <mylib.h>
#include <string.h>

using namespace std;

const int MAX = 1000;

const int PgUp = 73;   
const int PgDn = 81;   

 struct NV {
	int ms ; char ho [100]; char ten [10];	
	char mapb [10];
};
 struct List {
	int n;
	NV nv [MAX];
};

int Search( List &ds, int x)
{
	for ( int i =0 ; i <ds.n ; i++)
  		if (ds.nv[i].ms == x) return i;
	 return -1;
}

int NhapNV (List &ds, NV &nv){
	
	
	if (Search (ds,nv.ms)>=0) return 0;
	cout << "Ho     : " ; 
	fflush (stdin) ; gets (nv.ho);
	cout << "Ten    : " ; fflush (stdin) ; gets (nv.ten);
	cout << "Ma PB : " ; fflush (stdin) ;gets (nv.mapb	);
	return 1;
}
char * NhapChuoi (int type) { //type = 0 : "" thi ok 
                              //type =1  : "" thi nhap lai
	char S[100];
	do {	
	  fflush (stdin) ; gets (S);
	  if (type ==0) return S;
    } while (strlen(S)==0);
    return S;
}
void NhapDSNV (List &ds) {
	NV nv; char *S;
	while (ds.n < MAX) {
		nv.ms= ds.n > 0 ? ds.nv[ds.n-1].ms+1 :1;
		cout << "Ho (Ho = "" thi dung : " ; gets(S);
		if (strlen(S)==0) return ;
		strcpy(nv.ho,S);
		cout << "Ten    : " ; gets(S); strcpy(nv.ten, S); 
		cout << "Ma PB : " ; gets(S);  strcpy(nv.mapb, S);
		
	    ds.nv[ds.n++]= nv;
	}
}
// CAU LIET KE
void ShowData (List &ds, int i, int amount) {
	system("cls");
	for (int j =i ; j < ds.n && j <i+amount; j++) {
		gotoxy (10, wherey()); cout << ds.nv[j].ms ;
		gotoxy (15, wherey()); cout << ds.nv[j].ho ;
		gotoxy (35, wherey()); cout << ds.nv[j].ten ;
		gotoxy (50, wherey()); cout << ds.nv[j].mapb << endl;
	}
}
void LietKe (List &ds) {
	const int amount =3;
	int pages = ds.n / amount + (ds.n % amount ==0 ? 0 : 1);
	int page =0, i; int kt;
	ShowData (ds, 0,amount);
	do {
		kt=getch();
		if (kt==224)    kt=getch();
		if (kt== PgDn)
			   if (page < pages-1)  
			       {  page++; i=page*amount;
			          ShowData (ds, i, amount);
			       } 
   
 		if (kt==PgUp)  
		     if (page > 0)  
			       {  page--; i=page*amount;
			          ShowData (ds, i, amount);
			       } 
 	} while (kt !=27);
}

void SapxepPhongMaso(List &ds) {
 int i,j ; NV nv;   char key1 [100], key2[100];
 for(  i=0 ; i < ds.n-1 ; i++)
 {  
    strcpy(key1, ds.nv[i].mapb);
    
   // strcat(key1, ConvertIntToChar(ds.nv[i].ms)); 
    for (j = i+1; j< ds.n ; j++)
    {  strcpy(key2, ds.nv[j].ten);
     //  strcat(key2, ConvertIntToChar(ds.nv[j].ms));

       if (stricmp(key1, key2) > 0)
       {
    	nv=ds.nv[i];
   		ds.nv[i]=ds.nv[j];
   		ds.nv[j]=nv;
   		strcpy(key1, key2);
       }
    }
 }
}
void SapxepTenHo(List &ds) {
 int i,j ; NV nv;   char key1 [100], key2[100];
 for(  i=0 ; i < ds.n-1 ; i++)
 {  
    strcpy(key1, ds.nv[i].ten);
    strcat(key1, ds.nv[i].ho); ;
    for (j = i+1; j< ds.n ; j++)
    {  strcpy(key2, ds.nv[j].ten);
       strcat(key2, ds.nv[j].ho);

       if (stricmp(key1, key2) > 0)
       {
    	nv=ds.nv[i];
   		ds.nv[i]=ds.nv[j];
   		ds.nv[j]=nv;
   		strcpy(key1, key2);
       }
    }
 }
}
 struct item_idx{ // INDEX
 
  char mapb[10]; int chiso ;
};

 struct list_maso {
  int n;
  item_idx *nodes;
};
 void TaoIndex_Maso (List &ds, list_maso &idxms) {


   idxms.n=ds.n; int i;
   idxms.nodes = new item_idx [ds.n];

   for ( i =0 ; i< ds.n ; i++)
   { strcpy (idxms.nodes[i].mapb, ds.nv[i].mapb);
     idxms.nodes[i].chiso = i;	
   }
 // Sap xep mang idxms.nodes theo mapb
 int imin,j ; item_idx item;
 for(  i=0 ; i < ds.n-1 ; i++)
 { imin =i ;
   for (j = i+1; j< ds.n ; j++)
     if (stricmp(idxms.nodes[j].mapb, idxms.nodes[imin].mapb ) <0)
	    imin =j;
   item=idxms.nodes[i];
   idxms.nodes[i]=idxms.nodes[imin];
   idxms.nodes[imin]=item;
 }
}

void  Lietke_idxmaso(List &ds, list_maso &idxms){
int cs;

printf ("\n DANH SACH NHAN VIEN \n");
  char mmapb [10];
  strcpy (mmapb, idxms.nodes[0].mapb);
  int dem=0;
  printf ("MA PHONG BAN : %s\n",mmapb);
  printf ("MANV     HO TEN      \n");
  for (int i=0 ; i < idxms.n ; i++)
  { cs= idxms.nodes[i].chiso;
    if (stricmp(idxms.nodes[i].mapb , mmapb)!= 0  )
    {
     	printf ("\n So nhan vien : %d\n", dem);
    	strcpy (mmapb, idxms.nodes[i].mapb);
        dem=0;
  		printf ("\nMA PB : %s\n", mmapb);
  		printf ("MANV     HO TEN     \n");
  	
    }
     printf("\n%5d %-30s %-10s \n ", ds.nv[cs].ms, 
      ds.nv[cs].ho,	 ds.nv[cs].ten);
      dem++;
  }
  printf ("\n So sinh vien : %d\n", dem);
  getch();

}

int GhiDSNV (List &ds, char *tenfile) {
	FILE *f; char kt;
	f= fopen (tenfile , "wb");
	if (f!=NULL) {
		cout << "File " << tenfile << " da co. Ghi de (Y/N) ?" ;
		kt=toupper(getche());
		if (kt!='Y')  return   0;
   }
	f= fopen (tenfile , "wb");
	for (int i=0 ; i <ds.n ; i++)
	  fwrite (&ds.nv[i], sizeof(NV),1, f);
	fclose (f);
	return 1;
	
	
}
int NapDSNV (List &ds, char *tenfile) {
	FILE *f; char kt;
	f= fopen (tenfile , "rb");
	if (f==NULL) {
	  cout << "File " << tenfile << " khong co. " ;
	  return   0;
   }
   if (ds.n> 0 ) {
   	    cout << "Trong bo nho da co sinh vien. Ghi de (Y/N) ? " ;
   		kt=toupper(getche());
		if (kt!='Y') return 0;
   }
   ds.n=0;
   for ( ; fread (&ds.nv[ds.n], sizeof(NV),1, f) ==1 ; ds.n++) ;
	  
	fclose (f);
	return 1;
	
	
}
int Insert_Order (List &ds) {
	NV nv ;
	if (ds.n ==MAX) return 0;
	int err= NhapNV(ds, nv);
	if (err <=0) return 0;
	int i =0 ;
	for ( ; i <ds.n && ds.nv[i].ms < nv.ms; i++) ;
	for (int j =ds.n-1; j >=i; j--)
	  ds.nv[j+1]= ds.nv[j];
	ds.nv[i]= nv; ds.n++ ;
	return 1;  
}
int main() {
 List ds; ds.n=0;
 //list_maso idxms;
 //NapDSNV (ds, "d:/dsnv.ds");
 //SapxepTenHo(ds);
 NhapDSNV ( ds);
 //TaoIndex_Maso (ds, idxms);
 //Lietke_idxmaso (ds, idxms);
 getch();
  LietKe(ds);
 //cout << "An phim bat ky de ghi ..."; getch();
 //GhiDSNV (ds, "d:/dsnv.ds");
 
 return 0;
}
