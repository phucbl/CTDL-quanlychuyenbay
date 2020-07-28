#pragma once
#include "Maybay.h"
#include "ChuyenbayVe.h"
#include "Hanhkhach.h"





int main (){ 
  system ("cls"); Normal();
  
	
  int chon,chon2;  listmb dsmb; dsmb.n=0; char sohieu[16]; Maybay mb; ChuyenBay cb; nodeCB dscb;int chona=1;int chonb=1;
  char tempCMND[13];
  initialize(First);
  InitializeTree(tree);
  OpenFileMB(dsmb,filenameMB);
  OpenFileCB(First,filenameCB);
  OpenfileHK(tree);
  
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
    			
    			int d=Search(dsmb,sohieu);
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
	case 4: { cout<<dsmb.n;Sleep(500);
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
				      		case 3: { 	printf( " So hieu chuyen bay : %s", p->cb.machbay);cout<<"\n";
							  			XoaCB(dscb,cb,p); 
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
	case 13: {	ChuyenBay cb2;
				p = search_info2(First);
				if (p!=NULL) 
				{
					cb2=p->cb;
				int k;
				do
				{
					k = ChonVe(cb2);
					if (cb2.dsve[k - 1].trth == 1 && k != -1)
					{
						BaoLoi(" VE DA CO NGUOI DAT ");
						
					}
					
				} while (cb2.dsve[k - 1].trth == 1 && k != -1);
				
				if (k == -1)
				{
					system("cls");
					break;
				}
				system("cls");cout<<"DAT VE CHUYEN BAY "<<cb2.machbay<<"\n";
				char strcmnd[13];NODEPTRHK ptemp;
				NhapChuoi (  "Nhap cmnd: ", strcmnd); ptemp=TimVaLayCMND(tree,strcmnd);
				if (ptemp==NULL) {
					NhapHK(tree,strcmnd); strcpy(cb2.dsve[k - 1].cmnd,strcmnd); 
				} else
				{	
				cout<<"Da co thong tin  \nCMND: "<<ptemp->cmnd;
				cout<<"\nHo :"<<ptemp->ho<<"\nTen: "<<ptemp->ten<<"\nPhai: "<<ptemp->phai<<"\n";
				strcpy(cb2.dsve[k - 1].cmnd,ptemp->cmnd);}
				bool yn;
				cout<<"Xac nhan thong tin va dat ve (Y de dong y)";cin>>yn;if (yn!=1) break; 
				cb2.dsve[k - 1].trth = 1;
				cb2.sovedaban++;
				if (cb2.socot*cb2.sodong== cb2.sovedaban) strcpy(cb2.trangthai,"2");
				BaoLoi(" DAT THANH CONG ");
				p->cb=cb2;
				}
			
		break;
	}
	case 14: { 
				ChuyenBay cb2;
				p = search_info2(First);
				if (p!=NULL) 
				{
					cb2=p->cb;
				int k;
				do
				{
					k = ChonVe(cb2);
					if (cb2.dsve[k - 1].trth == 0 && k != -1)
					{
						BaoLoi(" VE CHUA CO NGUOI DAT ");
						
					}
					
				} while (cb2.dsve[k - 1].trth == 0 && k != -1);
				
				if (k == -1)
				{
					system("cls");
					break;
				}
				
				NODEPTRHK ptemp;
				ptemp=TimVaLayCMND(tree,cb2.dsve[k - 1].cmnd);
				cout<<"Thong tin  \nCMND: "<<ptemp->cmnd;
				cout<<"\nHo :"<<ptemp->ho<<"\nTen: "<<ptemp->ten<<"\nPhai: "<<ptemp->phai<<"\n";
				strcpy(cb2.dsve[k - 1].cmnd,ptemp->cmnd);
				bool yn;
				cout<<"Xac nhan thong tin va huy ve ( nhap 1 de dong y)";cin>>yn;if (yn!=1) break;
				strcpy(cb2.dsve[k - 1].cmnd,"");
				cb2.dsve[k - 1].trth = 0;
				cb2.sovedaban--;
				if (cb2.socot*cb2.sodong< cb2.sovedaban) strcpy(cb2.trangthai,"1");
				BaoLoi(" HUY VE THANH CONG ");
				p->cb=cb2;
			}
	break;
	}
	
	case 15: { 
		break;
	}
	}
  } while (1);
  return 0;
  }
