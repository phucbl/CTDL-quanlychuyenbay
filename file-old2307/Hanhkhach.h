#pragma once

const int Nam = 1;
const int Nu = 0;
int soHanhKhach;

struct Hanhkhach
{
   char cmnd[13];
   char ho[30];
   char ten[10];
   int phai = 0;
   struct Hanhkhach *left;
   struct Hanhkhach *right;
};
typedef struct Hanhkhach *NODEPTRHK;
NODEPTRHK tree=NULL;



void InitializeTree(NODEPTRHK &root)
{
   root = NULL;
}

int Empty(NODEPTRHK root)
{
   return(root == NULL ? TRUE : FALSE);
}

/*int TimCmndTrung(NODEPTRHK t, char x[13])
{	char tempcmnd[13];strcpy(tempcmnd,(t->cmnd));
	
	if (t != NULL)
	{
		if (strcmp(tempcmnd,x)==0)
			return 1;
		if (strcmp(tempcmnd,x)>0)
			TimCmndTrung(t->left, x);
		else
			TimCmndTrung(t->right, x);
	}
	return 0;
}*/
NODEPTRHK SearchHK (NODEPTRHK root, char x[13])
{
   NODEPTRHK p;
   p = root;
   while (p != NULL && strcmp(p->cmnd,x)!=0)
    if(strcmp(p->cmnd,x)>0)
         p = p->left;
      else
         p = p->right;

return(p);
}

void  remove_case_3 ( NODEPTRHK  &r )
{
	NODEPTRHK rp;
  	if (r->left != NULL)
     remove_case_3 (r->left);
   //den day r la nut cuc trai cua cay con ben phai co nut goc la rp}
    else 
	{
   strcpy(rp->cmnd,r->cmnd);   //Chep noi dung cua r sang rp ";
   strcpy(rp->ho,r->ho);
   strcpy(rp->ten,r->ten);  	
   rp->phai =r->phai;	//  de lat nua free(rp)
   rp = r;           	
   r = rp->right;
	  }
  }
void  remove (char x[13] ,  NODEPTRHK &p )
{
	NODEPTRHK rp;
	if (p == NULL)  printf ("Khong tim thay");
	else
	  if (strcmp(x,p->cmnd)<0)   remove (x, p->left);
	  else if (strcmp(x,p->cmnd)>0)
		  remove (x, p->right);
	       else   	// p->key = x
	       {
		 rp = p;
              if (rp->right == NULL)  p = rp->left;   
	// p là nút lá hoac la nut chi co cay con ben trai
		 else 	if (rp->left == NULL)
			   p = rp->right;  // p là nut co cay con ben phai
			else remove_case_3 (rp->right);
		 delete rp;
	       }
}
/*NODEPTRHK SearchHK (NODEPTRHK root, char x[13])
{
   NODEPTRHK p;
   p = root;
   while (p != NULL && strcmp(x,p->cmnd)!=0)
    if(strcmp(x,p->cmnd)<0)
         p = p->left;
      else
         p = p->right;

return(p); 
}*/
void Insert_node(NODEPTRHK &p, char cmnd[13], char ho[30], char ten[10], int phai)
{ 
   if(p == NULL)    // nút p hien tai se là nút lá
   {
     p = new Hanhkhach;
     strcpy(p->cmnd,cmnd);
     strcpy(p->ho,ho);
     strcpy(p->ten,ten);
     p->phai = phai;
     p->left = NULL;     p->right = NULL;  
   }
   else
    if(strcmp(cmnd,p->cmnd)<0)
      Insert_node(p->left, cmnd, ho,ten,phai);
    else if(strcmp(cmnd,p->cmnd)>0)	    Insert_node(p->right, cmnd, ho,ten,phai);
}
int CheckTrungCMND(NODEPTRHK &root,char str[13])
{ 		NODEPTRHK p; 
        p=SearchHK(tree,str);
        if (p!=NULL) {
        	BaoLoi(" Da co du lieu CMND nay. "); return 1;
		}
		else return 0;
        
    /*{
         printf("Nhap ho :");
         cin >> ho;
         printf("Nhap ten :");
         cin >> ten;
         printf("Nhap phai :");
         cin >> phai;
         Insert_node(root,cmnd,ho,ten,phai);soHanhKhach++; 
     }*/
		
//  } while (strcmp(cmnd,"0")!=0); 
}
NODEPTRHK TimVaLayCMND (NODEPTRHK &root, char str[13])
{ 		NODEPTRHK p;
        p=SearchHK(tree,str);
        if (p!=NULL) {
        	return p;
		}
		else return NULL;

}
void NhapHK (NODEPTRHK &root, char str[13]){
	char ho[30];char ten[10];int phai;
		printf("Nhap ho :");
        cin >> ho;
        
        printf("Nhap ten :");
        cin >> ten;
        
        printf("Nhap phai :");
        cin >> phai;
        Insert_node(root,str,ho,ten,phai);soHanhKhach++; 
	
}
void GhiHanhKhachVaoFile(NODEPTRHK p, FILE * &file)
{
	if (p != NULL)
	{
		Hanhkhach hk;
		strcpy(hk.cmnd,p->cmnd);
		strcpy(hk.ho,p->ho);
		strcpy(hk.ten,p->ten);
		hk.phai=p->phai;
		fwrite(&hk.cmnd,sizeof(hk.cmnd),1,file);
		fwrite(&hk.ho,sizeof(hk.ho),1,file);
		fwrite(&hk.ten,sizeof(hk.ten),1,file);
		fwrite(&hk.phai,sizeof(hk.phai),1,file);
		GhiHanhKhachVaoFile(p->left, file);
		GhiHanhKhachVaoFile(p->right, file);
	}
}
void SaveHanhKhach(NODEPTRHK t)
{	FILE * f; 
 	if ((f=fopen(filenameHK,"w"))==NULL)
 	{  BaoLoi ("Loi mo file de ghi"); return ;
 	}
	
	fwrite(&(soHanhKhach),sizeof(soHanhKhach),1,f);
	//int sizeData = ;
	NODEPTRHK p = t;
	GhiHanhKhachVaoFile(p, f);
	fclose(f);
}
void OpenfileHK(NODEPTRHK &t)
{	char cmnd[13];char ho[30];char ten[10];int phai;
	FILE * f; Hanhkhach pa;
	if ((f=fopen(filenameHK,"r"))==NULL)
		{  BaoLoi ("Loi mo file de doc"); return ;
		}
	int soHanhKhach;
	fread(&(soHanhKhach),sizeof(soHanhKhach),1,f);
	//int sizeData = sizeof(Hanhkhach);
	
	for (int i = 0; i < soHanhKhach; i++)
	{
		fread (&pa.cmnd,sizeof(pa.cmnd),1,f);
		fread (&pa.ho,sizeof(pa.ho),1,f);
		fread (&pa.ten,sizeof(pa.ten),1,f);
		fread (&pa.phai,sizeof(pa.phai),1,f);		
		Insert_node(t,pa.cmnd,pa.ho,pa.ten,pa.phai);
	}
}




