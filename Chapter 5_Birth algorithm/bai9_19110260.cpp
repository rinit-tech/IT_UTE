/*
Công dụng:
Tác giả:		Phạm Minh Phát
MSSV:			19110260
Ngày viết:
Ngày cập nhập:
*/
//THƯ VIỆN
#include <iostream>  //cin và cout
#include <time.h>	//Một số thư viện thường dùng
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <iomanip>
using namespace std;
//CHƯƠNG TRÌNH CHÍNH
//KHAI BÁO TOÀN CỤC (GLOBALLY) - SỬ DỤNG CHUNG CHO TOÀN BỘ CHƯƠNG TRÌNH\
//1. KHAI BÁO KIỂU DỮ LIỆU ( NEW )
//2. KHAI BÁO HẰNG ( CONST )
const int MAX = 100;
//3. KHAI BÁO BIẾN

//4. KHAI BÁO HÀM ( FUNCTION DECLARATIONS / PROTOTYPES )
//Viết chương trình nhập vào ma trận A[M][N], hãy xuất ra màn hình các phần tử
//A[i][j] sao cho A[i][j] là phần tử có giá trị lớn nhất dòng i và nhỏ nhất cột j.

//1. Nhập giá trị cho ma trận
void nhapMang(int Mang2C[][MAX], int Dong, int Cot)
{
	for (int i = 0; i < Dong; i++)				//i là chỉ số dòng
		for (int j = 0; j < Cot; j++)			//j là chỉ số cột
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> Mang2C[i][j];
			//a[i][j] = rand() % 99 + 1;
		}
}
//2. In nội dung của ma trận ra màn hình
void xuatMang2C(int Mang2C[][MAX], int Dong, int Cot)
{
	cout << "-> Mang cua ban: " << endl;
	for (int i = 0; i < Dong; i++)
	{
		for (int j = 0; j < Cot; j++)
		{
			cout.width(5);			//quy định độ rộng cho mỗi giá trị in ra
			cout << Mang2C[i][j];
		}
		cout << endl;				//sang dòng mới
	}
}
int Min(int a[][MAX], int dong, int cot, int vtri) {
	int Min = a[0][vtri];
	int vtMin = 0;
	for (int i = 1; i < dong; i++) {
		if (a[i][vtri] < Min) {
			Min = a[i][vtri];
			vtMin = i;
		}
	}
	return vtMin;
}

int Max(int a[][MAX], int dong, int cot, int vtri) {
	int Max = a[vtri][0];
	int vtMax = 0;
	for (int i = 1; i < cot; i++) {
		if (a[vtri][i] > Max) {
			Max = a[vtri][i];
			vtMax = i;
		}
	}
	return vtMax;
}
void chuongTrinh(int a[][MAX], int dong, int cot) {
	for (int i = 0; i < dong; i++) {
		int vtMaxDong = Max(a, dong, cot, i);
		int vtMinCot = Min(a, dong, cot, vtMaxDong);
		if (a[vtMinCot][vtMaxDong] == a[i][vtMaxDong])
			cout << a[i][vtMaxDong] << endl;
	}
}
//CHƯƠNG TRÌNH CHÍNH
int main()
{
	//Khai báo biến
	int a[MAX][MAX];
	int dong, cot;
	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		cin >> dong >> cot;
		nhapMang(a, dong, cot);
		xuatMang2C(a, dong, cot);
		cout << "Cac so thoa man de bai la: " << endl;
		chuongTrinh(a, dong, cot);
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		//END
		cout << "Nhap phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}