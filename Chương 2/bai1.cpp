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
bool search(int arr[], int n, int value);
//CHƯƠNG TRÌNH CHÍNH
int main()
{
	//Khai báo biến

	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

		int arr[] = { 1,2,3,4,5,6,7,9,10,11,12,13 };
		int result;
		result = search(arr, sizeof(arr) / 4, 8);
		result == 1 ? cout << "true\n" : cout << "false\n";
		result = search(arr, sizeof(arr) / 4, 12);
		result == 1 ? cout << "true\n" : cout << "false\n";

		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		//END
		cout << "Nhap phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}
bool search(int arr[], int n, int value) {
	arr[n] = value;
	int i = 0;
	while (arr[i] != value) i++;
	return i >= n ? false : true;
}