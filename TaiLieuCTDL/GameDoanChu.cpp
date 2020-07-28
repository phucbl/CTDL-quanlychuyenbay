#include <iostream>
#include <ctime>
#include <cstdlib>
#include <mylib.h>
#include <windows.h>

using namespace std;

const int lv1 = 50;
const int lv2 = 80;
const int lv3 = 100;

char map[100][100];
int diemNguoiChoi, diemMay, flag = 0;
int lv = lv3;
	
void VeMap()
{
	for(int i = 0; i < 23; i++)
	{
		map[i][0] = '|';
		map[i][27] = '|';
		for(int j = 1; j < 27; j++)
		{
			map[0][j] = 64 + j;
			map[i][j] = ' ';
			map[22][j] = '_';
		}
	}
}

void InMap()
{
	for(int i = 0; i < 23; i++)
	{
		for(int j = 0; j < 28; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	gotoxy(30, 0);
	cout << "TRO CHOI DOAN CHU";
	gotoxy(30, 2);
	cout << "Diem cua ban: " << diemNguoiChoi;
	gotoxy(30, 3);
	cout << "Diem cua may: " << diemMay;
	gotoxy(30, 13);
	cout << "Level 1: " << lv1;
	gotoxy(30, 14);
	cout << "Level 2: " << lv2;
	gotoxy(30, 15);
	cout << "Level 3: " << lv3;
	gotoxy(30, 19);
	cout << " 1     Level 1";
	gotoxy(30, 20);
	cout << " 2     Level 2";
	gotoxy(30, 21);
	cout << " 3     Level 3";
	gotoxy(30, 22);
	cout << "ESC    Quit";
}

void DiChuyenChu(int x, int y) //x, y la vi tri hien tai
{
	char temp, kiTu;
	while(x < 22)
	{	
		if(kbhit())
		{
			kiTu = getch();
		}
		if(kiTu == map[x][y] + 32) break;
		else if(kiTu == '1')
		{
			lv = lv1;
		}
		else if(kiTu == '2')
		{
			lv = lv2;
		}
		else if(kiTu == '3')
		{
			lv = lv3;
		}
		else if(kiTu == 27)
		{
			flag = 1;
			break;
		}
		temp = map[x][y];
		map[x][y] = ' ';
		gotoxy(y , x);
		cout << map[x][y];
		x++;
		map[x][y] = temp;
		gotoxy(y ,x);
		cout << map[x][y];
		Sleep(lv);
	}
	if(flag == 1) diemNguoiChoi = -1;
	else if(x < 22) diemNguoiChoi++;
	else diemMay++;
}

int main()
{
	char chose;
	srand(time(NULL));
	int x = 0, y;
	while(1)
	{
		y = rand() % 26 + 1;
		VeMap();
		InMap();
		DiChuyenChu(x , y);
		if(diemNguoiChoi == 5) 
		{
			system("cls");
			gotoxy(32, 7);
			cout << "YOU WIN";
			Sleep(1000);
			gotoxy(27, 9);
			cout << "'ENTER' - TIEP TUC";
			gotoxy(22, 10);
			cout << "Nhan phim bat ki de ket thuc ";
			chose = getche();
			if(chose == 13)
			{
				diemNguoiChoi = 0;
				diemMay = 0;
				system("cls");
				continue;
			}
			else break;
		}
		else if(diemMay == 5) 
		{
			system("cls");
			gotoxy(30, 7);
			cout << "COMPUTER WIN";
			Sleep(1000);
			gotoxy(27, 9);
			cout << "'ENTER' - TIEP TUC";
			gotoxy(22, 10);
			cout << "Nhan phim bat ki de ket thuc ";
			chose = getche();
			if(chose == 13)
			{
				diemNguoiChoi = 0;
				diemMay = 0;
				system("cls");
				continue;
			}
			else break;
		}
		else if(diemNguoiChoi == -1) break;
		system("cls");
	}
	system("cls");
	gotoxy(23, 9);
	cout << "TRO CHOI KET THUC" << endl;
	return 0;
}
