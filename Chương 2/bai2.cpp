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
//3. KHAI BÁO BIẾN
//4. KHAI BÁO HÀM ( FUNCTION DECLARATIONS / PROTOTYPES )
int searchNhiPhan(int arr[], int h, int l, int value);
//CHƯƠNG TRÌNH CHÍNH
int main()
{
	//Khai báo biến

	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		int arr[100];
		int phTu;
		cout << "So phan tu: "; 
		cin >> phTu;
		for (int i = 0; i < phTu; i++)
		{
			cout << "+ Phan tu so #" << i << " = ";
			cin >> arr[i];
		}
		int value;
		cout << "So can tim kiem: ";
		cin >> value;
		
		int result = searchNhiPhan(arr, 0, phTu - 1, value);
		cout << result << endl;

		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		//END
		cout << "Nhap phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}
int searchNhiPhan(int arr[], int h, int l, int value) {
	if (l >= h) {
		int mid = h + (l - h) / 2; // trách trường hợp tràn số

		if (arr[mid] == value)
			return mid;

		// Nếu arr[mid] > x, tìm kiếm bên trái
		if (arr[mid] > value)
			return searchNhiPhan(arr, h, mid - 1, value);

		// Nếu arr[mid] < x, tìm kiếm bên phải
		return searchNhiPhan(arr, mid + 1, l, value);
	}

	return -1;
}