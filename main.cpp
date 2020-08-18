#pragma once
#include "Maybay.h"
#include "ChuyenbayVe.h"
#include "Hanhkhach.h"

int main (){ 
  system ("cls"); Normal();
  
	
  int chon,chon2;  listmb dsmb; dsmb.n=0; char sohieu[16];
  Maybay mb; ChuyenBay cb; nodeCB dscb;int chona=1,chonb=1;
  char tempCMND[13];
  initialize(First);
  InitializeTree(tree);
  OpenFileMB(dsmb,filenameMB);
  OpenFileCB(First,filenameCB);
  OpenfileHK(tree);
  
  do
  {
    chon = MenuDong (thucdon,chona);
    switch (chon ){
    case 1: {  	
				if (NhapMB(dsmb, mb)==1) InsertOrderMB (dsmb,mb);
			   	break;
            };
    case 2: 	{	system ("cls");
					LietKe(dsmb); 
		break;
	}
    case 3: { 	gotoxy(cotNhap,dongNhap);
				NhapChuoi (  "Nhap so hieu may bay: ", sohieu,14) ;				
    			ThemCach(sohieu);
    			int d=Search(dsmb,sohieu);    			
				if (d>=0){
					int c=1;
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
				      		case 3: {
							  		XoaMb(dsmb,d);
				      				c=0;
								break;
							  }
						  }
					  } 
				} else BaoLoi("Khong co so hieu may bay nay!!! ");
	       
		  strcpy(sohieu,"");break;
	    };
	case 4: { 	
				ThongKeLuotBay(dsmb);
		  break;
	    };    
	
    case 5 :   {SaveFileMB(dsmb,filenameMB);break;}
    case 7 :	{ if (NhapCB(dscb,cb,dsmb)==1) 	InsertOrderCB (First,cb);
    		break;	
		}
	case 8 : {
		traverse(First);
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
				      		case 3: { 	if (p->cb.sovedaban>0) {
				      						cout<<"Da ban ve. Khong the xoa chuyen bay nay!!!"; getch(); c=0; break;
										  }
										gotoxy(cotNhap,dongNhap+6);
										cout<<"Ban chac chan xoa chuyen bay nay?";
										int chonYN = MenuYN(menuYN,30); //30 la do dai cua chuoi cout tren
										if (chonYN==0){
							  			XoaCB(dscb,cb,p); 
				      					c=0;
										}
										c=0;
								break;
							  }
						  }
					  }
					  break;
			}
	case 10: {	
				p = search_info2(First);
				if (p!=NULL) {
				if (strcmp(p->cb.trangthai,"3")==0){
						cout<<"Chuyen bay da hoan tat. Khong the huy chuyen bay nay!!!"; getch(); break;
					}
				HuyCB(dscb,cb,dsmb,p);
				
					
				}
				break;	
			}

	case 11: { 
		SaveFileCB(First,filenameCB);
		SaveHanhKhach(tree);
		break;
	}
	case 13: {	char sohieu[16];
				p = First;gotoxy(cotNhap,dongNhap);
				NhapChuoi (  "Nhap so hieu chuyen bay: ", sohieu,14) ;int c=1;
						 if (strcmp(sohieu,"0")==0) break;
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
				p = search_info(First,sohieu);
				if (p!=NULL) 
				{
					
				if (strcmp(p->cb.trangthai,"1")==0||strcmp(p->cb.trangthai,"2")==0){
					if (CompareDateTimeToNow(p->cb.timebay)==0) strcpy(p->cb.trangthai,"3");
				
				}
				if (strcmp(p->cb.trangthai,"3")==0){
					cout<<"Chuyen bay da hoan tat. "; getch(); break;
				}
				if (strcmp(p->cb.trangthai,"0")==0){
					cout<<"Chuyen bay da Huy. "; getch(); break;
				}
				int k;
				do
				{
					k = ChonVe(p);
					if (p->cb.dsve[k - 1].trth == 1 && k != -1)
					{
						BaoLoi(" VE DA CO NGUOI DAT ");	
					}
					
				} while (p->cb.dsve[k - 1].trth == 1 && k != -1);
				
				if (k == -1)
				{
					system("cls");
					break;
				}
				//system("cls");
				gotoxy(p->cb.socot*6, 10); cout<<"NHAP THONG TIN DAT VE";
				char strcmnd[13];NODEPTRHK ptemp;
				gotoxy(p->cb.socot*6, 11);
				NhapChuoi (  "Nhap cmnd: ", strcmnd,12); ptemp=TimVaLayCMND(tree,strcmnd);
				if (ptemp==NULL) {
					NhapHK(tree,strcmnd,p->cb.socot); strcpy(p->cb.dsve[k - 1].cmnd,strcmnd); 
				} else
				{	
				gotoxy(p->cb.socot*6, 12);
				cout<<"Da co thong tin";
				gotoxy(p->cb.socot*6, 13);
				cout<<"CMND: "<<ptemp->cmnd;
				gotoxy(p->cb.socot*6, 14);
				cout<<"Ho :"<<ptemp->ho;
				gotoxy(p->cb.socot*6, 15);
				cout<<"Ten: "<<ptemp->ten;
				gotoxy(p->cb.socot*6, 16);
				cout<<"Phai: "<<menuPhai[ptemp->phai];
				NODEPTRCB q;
				q=CheckVeChuyenBayKhac(dscb,p,strcmnd);
				if (q!=NULL) {
					
					gotoxy(p->cb.socot*6, 18);
					cout<<"CMND nay da dat ve tren chuyen bay "<<q->cb.machbay<<" vao luc ";
					OutputDateTime(q->cb.timebay);cout<< ".Khong the dat ve nay!!!";getch();break;
				} 
				}
				
				gotoxy(p->cb.socot*6, 18);
				cout<<"Xac nhan thong tin va dat ve";
				int chonYN = MenuYN(menuYN,28); //28 la do dai cua chuoi cout "Xac nhan thong tin va dat ve"
				if (chonYN!=0) break;
				strcpy(p->cb.dsve[k - 1].cmnd,ptemp->cmnd);
				p->cb.dsve[k - 1].trth = 1;
				p->cb.sovedaban++;
				if (p->cb.socot*p->cb.sodong== p->cb.sovedaban) strcpy(p->cb.trangthai,"2");
				BaoLoi(" DAT THANH CONG ");
				p=NULL;
				}
				else {
					BaoLoi("Khong co so hieu chuyen bay nay!!!");
				}
			
		break;
	}
	case 14: { 	
				char sohieu[16];
				p = First;gotoxy(cotNhap,dongNhap);
				NhapChuoi (  "Nhap so hieu chuyen bay: ", sohieu,14) ;int c=1;
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
				p = search_info(First,sohieu);
				if (p!=NULL) 
				{
				
				if (strcmp(p->cb.trangthai,"1")==0||strcmp(p->cb.trangthai,"2")==0){
					if (CompareDateTimeToNow(p->cb.timebay)==0) strcpy(p->cb.trangthai,"3");
				
				}
				if (strcmp(p->cb.trangthai,"3")==0){
					cout<<"Chuyen bay da hoan tat. "; getch(); break;
				}
				if (strcmp(p->cb.trangthai,"0")==0){
					cout<<"Chuyen bay da Huy. "; getch(); break;
				}
				
				int k;
				do
				{
					k = ChonVe(p);
					if (p->cb.dsve[k - 1].trth == 0 && k != -1)
					{
						BaoLoi(" VE CHUA CO NGUOI DAT ");
						
					}
					
				} while (p->cb.dsve[k - 1].trth == 0 && k != -1);
				
				if (k == -1)
				{
					system("cls");
					break;
				}
				//system("cls");
				/*if (strcmp(p->cb.dsve[k - 1].cmnd,"")==0) {bool yn;
				cout<<"Xac nhan thong tin va huy ve ( nhap 1 de dong y)";cin>>yn;if (yn!=1) break;
				p->cb.dsve[k - 1].trth = 0;
				p->cb.sovedaban--;
				if (p->cb.socot*p->cb.sodong< p->cb.sovedaban) strcpy(p->cb.trangthai,"1");
				BaoLoi(" HUY VE THANH CONG ");	break;
				}*/
				NODEPTRHK ptemp;
				ptemp=TimVaLayCMND(tree,p->cb.dsve[k - 1].cmnd);
				gotoxy(p->cb.socot*6, 10);
				cout<<"Huy ve tren chuyen bay "<<p->cb.machbay;
				gotoxy(p->cb.socot*6, 11);
				cout<<"Thong tin";
				gotoxy(p->cb.socot*6, 12);
				cout<<"CMND: "<<ptemp->cmnd;
				gotoxy(p->cb.socot*6, 13);
				cout<<"Ho :"<<ptemp->ho;
				gotoxy(p->cb.socot*6, 14);
				cout<<"Ten: "<<ptemp->ten;
				gotoxy(p->cb.socot*6, 15);
				cout<<"Phai: "<<menuPhai[ptemp->phai];
				gotoxy(p->cb.socot*6, 16);
				cout<<"Ban chac chan huy ve?";
				int chonYN = MenuYN(menuYN,21);
				if (chonYN!=0) break;
				strcpy(p->cb.dsve[k - 1].cmnd,"");
				p->cb.dsve[k - 1].trth = 0;
				p->cb.sovedaban--;
				
				if (p->cb.socot*p->cb.sodong< p->cb.sovedaban) strcpy(p->cb.trangthai,"1");
				BaoLoi(" HUY VE THANH CONG ");
				p=NULL;
			}
	break;
	}
	
	case 15: { TimChuyenBayDatePlace();
		break;
	}
	case so_item: SaveFileMB(dsmb,filenameMB);
				SaveFileCB(First,filenameCB);
			SaveHanhKhach(tree);
			BaoLoi("Dang thoat chuong trinh....");
			system("cls");
			return 0;
	}
  } while (1);
  return 0;
  }
