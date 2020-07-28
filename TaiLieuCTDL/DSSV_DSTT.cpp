#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
//#include <windows.h>
#include <mylib.h>

using namespace std;
const int MAX = 100;
const int PgUp = 73;  //73
const int PgDn = 81;  //81

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
	cout << "Ma so NV : " ; cin >> nv.ms;
	if (nv.ms <=0) return -1;
	if (Search (ds,nv.ms)>=0) return 0;
	cout << "Ho     : " ; 
	fflush (stdin) ; gets (nv.ho);
	cout << "Ten    : " ; fflush (stdin) ; gets (nv.ten);
	cout << "Ma phong ban : " ; fflush (stdin) ;gets (nv.mapb);
	return 1;
}
void NhapDSNV (List &ds) {
	NV nv;int err;
	while (ds.n < MAX) {
		err= NhapNV (ds,nv);
		if (err==-1) return ;
		if (err==0) 
		{
		  cout << "Ma so NV bi trung. Hay nhap lai " << endl;
		  continue;
	    }
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
	const int amount =10;
	int pages = ds.n / amount +1;
	int page =0, i; int kt;
	ShowData (ds, 0,amount);
	do {
		kt=getch();
		if (kt==224) 
		    kt=getch();
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
  		printf ("\nMA PHONG BAN : %s\n", mmapb);
  		printf ("MANV     HO TEN     \n");
  	
    }
     printf("\n%5d %-30s %-10s \n ", ds.nv[cs].ms, 
      ds.nv[cs].ho,	 ds.nv[cs].ten);
      dem++;
  }
  printf ("\n So nhan vien : %d\n", dem);
  getch();

}

int GhiDSNV (List &ds, char *tenfile) {
	FILE *f; char kt;
	f= fopen (tenfile , "rb");
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
   	    cout << "Trong bo nho da co nhan vien. Ghi de (Y/N) ? " ;
   		kt=toupper(getche());
		if (kt!='Y') return 0;
   }
   ds.n=0;
   for ( ; fread (&ds.nv[ds.n], sizeof(NV),1, f) ==1 ; ds.n++) ;
	  
	fclose (f);
	return 1;
	
	
}

int main() {
 List ds; ds.n=0;
 list_maso idxms;
 NapDSNV (ds, "d:/dsnv.ds");
 //NhapDSNV ( ds);
 TaoIndex_Maso (ds, idxms);
 Lietke_idxmaso (ds, idxms);
 //LietKe(ds);
 //cout << "An phim bat ky de ghi ..."; getch();
 //GhiDSNV (ds, "d:/dsnv.ds");
 
 return 0;
}
