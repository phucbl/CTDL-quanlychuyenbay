#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <alloc.h>
#include <ctype.h>
#include <mylib.h>
#define TRUE 1
#define FALSE 0
using namespace std;
struct sinhvien
{
   int mssv;
   char ho[30];
   char ten[10];
};
struct node
{
   sinhvien sv;
   struct node *next;
};
typedef node *NODEPTR;
  NODEPTR First;
   sinhvien sv;
   NODEPTR p;
// Phep toan New_node: cap phat mot nut cho danh sach lien ket
NODEPTR New_node(void)
{
   NODEPTR p;
   p = (NODEPTR)malloc(sizeof(struct node));
   return(p);
}
/* Tac vu nodepointer: xac dinh con tro cua nut i trong danh sach lien ket
   (i = 2, ...) */
NODEPTR nodepointer(NODEPTR First, int i)
{
	NODEPTR p;
	int vitri=1;
	p = First;
	while(p != NULL && vitri < i)
	{
		p = p->next;
		vitri++;
	}
	return(p);
}
// Tac vu position: xac dinh vi tri cua nut p trong danh sach lien ket
int position(NODEPTR First, NODEPTR p)
{
	int vitri;
	NODEPTR q;
	q = First;
	vitri = 1;
	while(q != NULL && q != p)
	{
		q = q->next;
		vitri++;
	}
   if(q == NULL)
      return(-1);
   return(vitri);
}
// Phep toan initialize: khoi dong danh sach lien ket
void initialize(NODEPTR &First)
{
   First = NULL;
}
// Tac vu Empty: kiem tra danh sach lien ket co bi rong khong
int Empty(NODEPTR First)
{
   return(First == NULL ? TRUE : FALSE);
}
// Phep toan Insert_first: them nut moi vao dau danh sach lien ket
void Insert_first(NODEPTR &First, sinhvien x)
{
   NODEPTR p;
   p = New_node();
   p->sv = x;
   p->next = First;
   First = p;
}
// Phep toan Insert_after: them nut moi sau nut co dia chi p
void Insert_after(NODEPTR p, sinhvien x)
{
   NODEPTR q;
   if(p == NULL)
		printf("khong them sinh vien vao danh sach duoc");
   else
   {
      q = New_node();
      q->sv = x;
      q->next = p->next;
      p->next = q;
   }
}
// Phep toan Delete_first: xoa nut o dau danh sach lien ket
void Delete_first(NODEPTR &First)
{
   NODEPTR p;
   if(Empty(First))
      printf("Khong co sinh vien trong danh sach");
   else
   {
      p = First;    // nut can xoa la nut dau
      First = p->next;
      free(p);
   }
}
// Tac vu Delete_after: xoa nut sau nut p
void Delete_after(NODEPTR p)
{
   NODEPTR q;
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
/* Phep toan Insert_Order: Phep toan nay chi su dung khi them nut vao danh sach lien ket da co thu tu */
void Insert_Order(NODEPTR &First, sinhvien x)
{
   NODEPTR p, q;  // q la nut truoc, p la nut sau
   q = NULL;
   for(p = First; p != NULL && p->sv.mssv< x.mssv; p = p->next)
      q = p;
   if(q == NULL)  // them nut vao dau danh sach lien ket
      Insert_first(First, x);
   else           // them nut vao sau nut q
      Insert_after(q, x);
}
// Phep toan clearlist: xoa tat ca cac nut trong danh sach lien ket
void clearlist(NODEPTR &First)
{
   NODEPTR p, q;  // q la nut truoc, p la nut sau
   p = First;
   while(First != NULL)
   {
      p = First;
      First = First->next;
      free(p);
   }
}
// Phep toan traverse: duyet danh sach lien ket
void traverse(NODEPTR First)
{
   NODEPTR p;
   int stt = 0;
   p = First;
   if(p == NULL)
      printf("\n   (Khong co sinh vien trong danh sach)");
   while(p != NULL)
   {
      printf("\n %5d %8d %-30s %-10s", ++stt, p->sv.mssv, p->sv.ho,p->sv.ten);
      p = p->next;
   }
}

/* Tac vu search_info: tim kiem theo phuong phap tim kiem tuyen tinh, neu khong tim thay ham nay tra ve NULL, neu tim thay ham nay tra ve con tro chi  nut tim thay */
NODEPTR search_info(NODEPTR First, int x)
{
	NODEPTR p;
	p = First;
	while(p != NULL && p->sv.mssv != x  )
		p = p->next;
	return(p);
}
// Tac vu selectionsort: sap xep danh sach lien ket theo MSSV tang dan
void selectionsort(NODEPTR &First)
{
   NODEPTR p, q, pmin;
	sinhvien min;
	for(p = First; p->next != NULL; p = p->next)
	{
		min = p->sv;
		pmin = p;
		for(q = p->next; q != NULL; q = q->next)
			if(min.mssv > q->sv.mssv)
			{
				min = q->sv;
				pmin = q;
			}
		// hoan doi truong info cua hai nut p va pmin
		pmin->sv  = p->sv;
		p->sv 	  = min;
	}
}
char menu ()
{  char chucnang;
   do
   {  clrscr();
      printf("\n\n\t\tCHUONG TRINH QUAN LY DANH SACH SINH VIEN");
      printf("\n\nCac chuc nang cua chuong trinh:\n");
      printf("   1: Tao danh sach sinh vien\n");
      printf("   2: Them sinh vien vao danh sach\n");
      printf("   3: Xem danh sach sinh vien\n");
      printf("   4: Hieu chinh sinh vien\n");
      printf("   5: Xoa sinh vien trong danh sach\n");
      printf("   6: Tim kiem sinh vien theo MSSV\n");
      printf("   7: Sap xep danh sach theo MSSV\n");
      printf("   8: Them sinh vien vao danh sach da co thu tu\n");
      printf("   9: Xoa toan bo danh sach\n");
      printf("   0: Ket thuc chuong trinh\n");
      printf("Chuc nang ban chon: ");
      chucnang = getche();
      } while(chucnang < '0' || chucnang >'9') ;
      return chucnang;
}
void Create_list(NODEPTR &First)
{ NODEPTR Last,p ;
  sinhvien sv;

  char maso [5],c;
	clearlist(First);
	printf("Ma so sinh vien: ");
	gets(maso);
	sv.mssv = atoi(maso);
  while (sv.mssv !=0)
  {
		printf("Ho sinh vien: ");
		gets(sv.ho);
		printf("Ten sinh vien: ");
		gets(sv.ten);
		p=New_node();
		p->sv=sv;
		if (First==NULL)
		  First=p;
		else
		  Last->next = p;
		Last=p;
		p->next=NULL;
		printf("Ma so sinh vien moi: ");
		gets(maso);
		sv.mssv = atoi(maso);
  }
}
// chuong trinh chinh
int main()
{
   int vitri;
   char chucnang, c, maso [5], c_vitri[5];
   // khoi dong danh sach lien ket
   initialize(First);
   do
   {
      chucnang = menu();
      //flushall();
      switch(chucnang)
      {
	case '1':
	{
Create_list(First);
break;
	}
	case '2':
	{
printf("\nVi tri them (1, 2, ...): ");
gets(c_vitri);
	vitri = atoi(c_vitri);
		p = nodepointer(First, vitri-1);//p chi nut truoc nut can them
	if (vitri <=0 || p==NULL)
		{
			printf("Vi tri khong hop le");
		getche();
		}
	else
		{
	printf("Ma so sinh vien: ");
	gets(maso);
	sv.mssv = atoi(maso);
	printf("Ho sinh vien: ");
	gets(sv.ho);
	printf("Ten sinh vien: ");
	gets(sv.ten);
	if (vitri == 1)
  Insert_first(First, sv);
	else
Insert_after(p, sv);
	}
		break;
	}
	case '3':
	{
		printf("\nDanh sach sinh vien: ");
	printf("\n     STT   MSSV         HO TEN");
	traverse(First);
	getche();
	break;
	}
	case '4':
	{
		printf("\nVi tri hieu chinh (1, 2, ...): ");
	gets(c_vitri);
	vitri = atoi(c_vitri);
	p = nodepointer(First, vitri); // p chi nut can hieu chinh
		if(p == NULL)
		{
	    printf("Vi tri khong phu hop");
	   getche();
	}
		else
		{
	   printf("\nSTT:%d  MSSV:%d  HO:%s            TEN:%s",
			vitri,p->sv.mssv, p->sv.ho, p->sv.ten);
	   printf("\nMa so sv moi: ");
		   gets(maso);
		   sv.mssv = atoi(maso);
		   printf("Ho sv moi: ");
		   gets(sv.ho);
		   printf("Ten sv moi: ");
		   gets(sv.ten);
		   p->sv = sv;
		}
	break;
	}
	case '5':
	{
	printf("\nVi tri xoa ( 1, 2, ...): ");
	gets(c_vitri);
	vitri = atoi(c_vitri);
	p = nodepointer(First, vitri-1);//p chi nut truoc nut can xoa
	if (vitri <=0 || p==NULL)
	{
	printf("Vi tri khong hop le");
	getche();
	}
	else
if(vitri == 1)
Delete_first(First);
else
Delete_after(p);
	break;
	}
	case '6':
	{
printf("\nMa so sinh vien can tim: ");
gets(maso);
sv.mssv = atoi(maso);
p = search_info(First, sv.mssv);
if(p == NULL)
printf("Khong co sinh vien co MSSV %d trong danh sach", 		sv.mssv);
else
printf("Tim thay o vi tri %d trong danh sach", position(First, p));
getche();
break;
	}
	case '7':
	{
printf("\n   Ban co chac khong? (c/k): ");
c = toupper(getche());
if( c == 'C')
	selectionsort(First);
break;
	}
	case '8':
	{
printf("\n   Ban nho sap xep danh sach truoc. Nhan phim bat ky ...");
getche();
printf("\nMa so sinh vien: ");
gets(maso);
sv.mssv = atoi(maso);
printf("Ho sinh vien: ");
gets(sv.ho);
printf("Ten sinh vien: ");
gets(sv.ten);
Insert_Order(First, sv);
break;
	}
	case '9':
	{
printf("\n   Ban co chac khong (c/k): ");
c = getche();
if(c == 'c' || c == 'C')
	clearlist(First);
break;
	}
      }
   } while(chucnang != '0');

   // xoa tat ca cac nut tren danh sach lien ket
	clearlist(First);
	return 0;
}

