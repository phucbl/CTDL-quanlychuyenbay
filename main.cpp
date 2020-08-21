#pragma once
#include "Maybay.h"
#include "ChuyenbayVe.h"
#include "Hanhkhach.h"

int main (){ 
  //system ("cls");//Normal();
  
  int chon,chon2;  listmb dsmb; dsmb.n=0; char sohieu[16];
  Maybay mb; ChuyenBay cb; nodeCB dscb;int chona=1,chonb=1;
  char tempCMND[13];
  initialize(First);
  InitializeTree(tree);
  OpenFileMB(dsmb,filenameMB);cout<<"1";
  OpenFileCB(First,filenameCB);cout<<"2";
  OpenfileHK(tree);cout<<"3";
  
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
	
    case 6 :	{ if (NhapCB(dscb,cb,dsmb)==1) 	InsertOrderCB (First,cb);
    		break;	
		}
	case 7 : {
		traverse(First);
		break;
	}
	case 8 :{ 
				int c=1;char sh[15];gotoxy(cotNhap,dongNhap);
				NhapChuoi (  "Nhap ma chuyen bay: ",sh,14);
				if (strcmp(sh,"0")==0) break;			
    			ThemCach(sh);
				p = search_info(First,sh);
				
				if (p!=NULL) 
					{
					char tt[15];
					if (strcmp(p->cb.trangthai,"0")==0) strcpy(tt,"Huy chuyen");
					if (strcmp(p->cb.trangthai,"1")==0) strcpy(tt,"Con ve");
					if (strcmp(p->cb.trangthai,"2")==0) strcpy(tt,"Het ve");
					if (strcmp(p->cb.trangthai,"3")==0) strcpy(tt,"Hoan tat");
					gotoxy(cotNhap,dongNhap+1);SetColor(LightBlue);printf("	Ma CB         		 Noi den    		    So hieuu MB" );
					gotoxy(cotNhap,dongNhap+2);SetColor(White);printf("%15s %30s %15s", p->cb.machbay, p->cb.noiden,p->cb.sohieumaybay);
					gotoxy(cotNhap,dongNhap+3);SetColor(LightBlue);printf("    Time                 	        Trang thai");
					gotoxy(cotNhap,dongNhap+4);SetColor(White);OutputDateTime(p->cb.timebay);cout<<"			"<<tt<<"\n";Normal();
					while (c==1){
				      	chon2 = MenuDong2 (thucdon2);
				      	switch (chon2){
				      		case 1: {c=0;
								break;
							  }
				      		case 2: { 	gotoxy(cotMenuSua,dongMenuSua+1);
										cout<<"                                                 ";
										gotoxy(cotMenuSua,dongMenuSua+2);
										cout<<"                                                 ";
										gotoxy(cotMenuSua,dongMenuSua+3);
										cout<<"                                                 ";
										gotoxy(cotMenuSua,dongMenuSua+1);
										printf( "Chinh sua thoi gian : %s", p->cb.machbay);cout<<"\n";
										SuaCB(dscb,cb,dsmb,p);
							  			
				      					
				      				  c=0;
								break;
							  }
				      		case 3: { 	if (p->cb.sovedaban>0) {
				      						cout<<"Da ban ve. Khong the xoa chuyen bay nay!!!"; getch(); c=0; break;
										  }
										
										
										gotoxy(cotMenuSua,dongMenuSua+1);
										cout<<"                                                 ";
										gotoxy(cotMenuSua,dongMenuSua+2);
										cout<<"                                                 ";
										gotoxy(cotMenuSua,dongMenuSua+3);
										cout<<"                                                 ";
										gotoxy(cotMenuSua,dongMenuSua+1);
										cout<<"Ban chac chan xoa chuyen bay nay?";
										int chonYN = MenuYN(menuYN,30); //30 la do dai cua chuoi cout tren
										if (chonYN==0){
											
											int vitri=Search(dsmb,p->cb.sohieumaybay);
											GiamLuotBay(dsmb,vitri);
							  			XoaCB(dscb,cb,p); 
				      					c=0;
										}
										c=0;
								break;
							  }
						  }
					  }
				}
				else BaoLoi("Khong co ma chuyen bay nay");
					  break;
			}
	case 9: {	
				char sh[15];gotoxy(cotNhap,dongNhap);
				NhapChuoi (  "Nhap ma chuyen bay: ",sh,14);
				if (strcmp(sh,"0")==0) break;			
    			ThemCach(sh);
				p = search_info(First,sh);
				
				if (p!=NULL) 
					{
					char tt[15];
					if (strcmp(p->cb.trangthai,"0")==0) strcpy(tt,"Huy chuyen");
					if (strcmp(p->cb.trangthai,"1")==0) strcpy(tt,"Con ve");
					if (strcmp(p->cb.trangthai,"2")==0) strcpy(tt,"Het ve");
					if (strcmp(p->cb.trangthai,"3")==0) strcpy(tt,"Hoan tat");
					gotoxy(cotNhap,dongNhap+1);SetColor(LightBlue);printf("%10s %30s %25s","Ma CB","Noi den","So hieuu MB" );
					gotoxy(cotNhap,dongNhap+2);SetColor(White);printf("%15s %30s %15s", p->cb.machbay, p->cb.noiden,p->cb.sohieumaybay);
					gotoxy(cotNhap,dongNhap+3);SetColor(LightBlue);printf("    Time                 	        Trang thai");
					gotoxy(cotNhap,dongNhap+4);SetColor(White);OutputDateTime(p->cb.timebay);cout<<"			"<<tt<<"\n";Normal();
					if (strcmp(p->cb.trangthai,"3")==0){
						cout<<"Chuyen bay da hoan tat. Khong the huy chuyen bay nay!!!"; getch(); break;
					}
					
				HuyCB(dscb,dsmb,p);
				
					
				}
				else BaoLoi("Khong co ma chuyen bay nay");
				break;	
			}
	case 11: {	char sohieu[15];
				p = First;int check=1;
				while (check==1){					
				gotoxy(cotNhap,dongNhap);
				cout<<"                                             ";
				gotoxy(cotNhap,dongNhap);
				NhapChuoi (  "Nhap so hieu chuyen bay: ", sohieu,14) ;
					if (strcmp(sohieu,"0")==0) break;
				   if (CheckChuoi(sohieu,5,15)==-1) 
				   {   
				   
				       BaoLoi ("Dinh dang sai "); 
				       continue;
				   }
				   check=0;
				}if (strcmp(sohieu,"0")==0) break;
					ThemCach(sohieu);
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
				
				int wcmnd =1;
				while (wcmnd==1) {
					gotoxy(p->cb.socot*6, 11);
					cout<<"                                 ";
					gotoxy(p->cb.socot*6, 11);
					NhapChuoi (  "Nhap cmnd: ", strcmnd,12);
					if (strcmp(strcmnd,"0")==0)  wcmnd==0;
					if (strlen(strcmnd)==9 || strlen(strcmnd)==12) 
					break;
					else{
					gotoxy(p->cb.socot*6, 12);
					cout<<"Nhap sai CMND";
					continue;
					} 
					
				}
				if (wcmnd==0) break; 	
				ptemp=TimVaLayCMND(tree,strcmnd);
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
				strcpy(p->cb.dsve[k - 1].cmnd,strcmnd);
				p->cb.dsve[k - 1].trth = 1;
				p->cb.sovedaban++;
				if (p->cb.socot*p->cb.sodong== p->cb.sovedaban) strcpy(p->cb.trangthai,"2");
				ThongbaoVe("DAT THANH CONG ",p->cb.socot*6);
				p=NULL;
				}
				else {
					BaoLoi("Khong co so hieu chuyen bay nay!!!");
				}
			
		break;
	}
	case 12: { 	
				char sohieu[16];
				p = First;int check=1;
				while (check==1){					
				gotoxy(cotNhap,dongNhap);
				cout<<"                                             ";
				gotoxy(cotNhap,dongNhap);
				NhapChuoi (  "Nhap so hieu chuyen bay: ", sohieu,14) ;
					if (strcmp(sohieu,"0")==0) break;
				   if (CheckChuoi(sohieu,5,15)==-1) 
				   {   
				   
				       BaoLoi ("Dinh dang sai "); 
				       continue;
				   }
				   check=0;
				}if (strcmp(sohieu,"0")==0) break;
					ThemCach(sohieu);
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
				ThongbaoVe("HUY THANH CONG ",p->cb.socot*6);
				p=NULL;
			}
	break;
	}
	
	case 13: { TimChuyenBayDatePlace();
		break;
	}
	case 14:{ char sohieu[15];
				p = First;gotoxy(cotNhap,dongNhap);
				NhapChuoi (  "Nhap so hieu chuyen bay: ", sohieu,14) ;int c=1;
						 if (strcmp(sohieu,"0")==0) break;
				   if (CheckChuoi(sohieu,5,15)==-1) 
				   {   
				   
				       BaoLoi ("Dinh dang sai "); 
				       return NULL;
				   }
					ThemCach(sohieu);
				p = search_info(First,sohieu);
				if (p!=NULL) {
					InDsHanhKhach(p->cb);
				}
		
		break;
	}
	case so_item: SaveFileMB(dsmb,filenameMB);
				SaveFileCB(First,filenameCB);
			SaveHanhKhach(tree);
			BaoLoi("Dang luu va thoat chuong trinh....");
			system("cls");
			return 0;
	}
  } while (1);
  return 0;
  }
