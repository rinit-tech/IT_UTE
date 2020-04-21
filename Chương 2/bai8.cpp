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
struct VTri {
	int row;
	int col;
};
//2. KHAI BÁO HẰNG ( CONST )
const int MAX = 100;
//3. KHAI BÁO BIẾN
//4. KHAI BÁO HÀM ( FUNCTION DECLARATIONS / PROTOTYPES )
//1. Nhập giá trị cho ma trận
void nhapMang(int Mang2C[][MAX], int row, int col);
//2. In nội dung của ma trận ra màn hình
void xuatMang(int Mang2C[][MAX], int row, int col);

//
void chuyen2Cthanh1C(int Mang2C[][MAX], int Dong, int Cot, int Mang1C[], int& Phtu);
void createSmall(int arr[][MAX], int& row, int& col);
//
void posMin(VTri vtri[], int posElement, int a[][MAX], int row, int col);


//CHƯƠNG TRÌNH CHÍNH
int main()
{
	//Khai báo biến

	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		VTri vtri[MAX];
		int a[MAX][MAX];
		int col;
		int row;
		int stt = 0;
		//Test Arr
		int b[] = { 5,9,5,6,4,3,8,7,2,11,7,10 };
		col = 4; row = 3;

		for (int i = 0; i < row; i++)				//i là chỉ số dòng
			for (int j = 0; j < col; j++)			//j là chỉ số cột
			{
				a[i][j] = b[stt++];
			
			}
		/*cout << "So dong cua ma tran: "; cin >> row;
		cout << "So cot cua ma tran: "; cin >> col;
		nhapMang(a, row, col);*/
		xuatMang(a, row, col);
		createSmall(a, row, col);
		xuatMang(a, row, col);
		int posElement = 0;
		posMin(vtri, posElement, a, row, col);
		createSmall(a, row, col);
		
		


		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		//END
		cout << "Nhap phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}

//1. Nhập giá trị cho ma trận
void nhapMang(int Mang2C[][MAX], int row, int col)
{
	for (int i = 0; i < row; i++)				//i là chỉ số dòng
		for (int j = 0; j < col; j++)			//j là chỉ số cột
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> Mang2C[i][j];
			//a[i][j] = rand() % 99 + 1;
		}
}
//2. In nội dung của ma trận ra màn hình
void xuatMang(int Mang2C[][MAX], int row, int col)
{
	cout << "-> Mang cua ban: " << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout.width(5);			//quy định độ rộng cho mỗi giá trị in ra
			cout << Mang2C[i][j];
		}
		cout << endl;				//sang dòng mới
	}
}
void chuyen2Cthanh1C(int Mang2C[][MAX], int Dong, int Cot, int Mang1C[], int& Phtu)
{
	Phtu = 0;
	for (int i = 0; i < Dong; i++)
		for (int j = 0; j < Cot; j++)
		{
			Mang1C[Phtu] = Mang2C[i][j];
			Phtu++;
		}
}

void createSmall(int arr[][MAX],int& row, int& col)
{
	int a[MAX], n=0;
	chuyen2Cthanh1C(arr, row, col, a, n);
	row+=2;
	col+=2;
	int k = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			if (i == 0 || j == 0 || i == row - 1  || j == col - 1)
				arr[i][j] = 0;
			else
				arr[i][j] = a[k++];
		}
}

void posMin(VTri vtri[], int posElement, int a[][MAX], int row, int col)
{
	posElement = -1;
	for (int i = 0; i < row; i++)				//i là chỉ số dòng
		for (int j = 0; j < col; j++)			//j là chỉ số cột
		{
			//Khai báo giá trị vị trí xung quanh
			int top = a[i - 1][j];
			int bot = a[i + 1][j];
			int right = a[i][j + 1];
			int left = a[i][j - 1];
			int mang[] = { top,bot,right,left };
			//Yêu cầu bài
			if (top < a[i][j] && bot < a[i][j] && right < a[i][j] && left < a[i][j])
			{
				posElement++;
				vtri[posElement].row = i;
				vtri[posElement].col = j;
			}
		}
	posElement++;
	/*for (int i = 0; i < posElement; i++)
		cout << vtri[i].row << "  " << vtri[i].col << "  " << a[vtri[i].row][vtri[i].col]<< endl;*/
	if (posElement == 0) cout << "-1"<<endl;
	else {
		//Tìm giá trị lồi nhỏ
		int Min = a[vtri[0].row][vtri[0].col];
		VTri vtMin;
		vtMin.row = vtri[0].row;
		vtMin.col = vtri[0].col;
		for (int i = 0; i < posElement; i++)
		{
			int row = vtri[i].row;
			int col = vtri[i].col;
			if (Min > a[row][col])
			{
				Min = a[row][col];
				vtMin.row = row;
				vtMin.col = col;
			}
		}
		cout << vtMin.row - 1 << "  " << vtMin.col - 1 << endl;
	}

}
//

