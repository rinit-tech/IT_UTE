#define _CRT_SECURE_NO_WARNINGS
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
#include <ctime>
#include <windows.h>
using namespace std;
//CHƯƠNG TRÌNH CHÍNH
//KHAI BÁO TOÀN CỤC (GLOBALLY) - SỬ DỤNG CHUNG CHO TOÀN BỘ CHƯƠNG TRÌNH\
//1. KHAI BÁO KIỂU DỮ LIỆU ( NEW )
//2. KHAI BÁO HẰNG ( CONST )
const int MAX = 100;
//3. KHAI BÁO BIẾN

//4. KHAI BÁO HÀM ( FUNCTION DECLARATIONS / PROTOTYPES )

char* numChange2(int n);
void numChange2s(int n);

//CHƯƠNG TRÌNH CHÍNH
int main()
{
	//Khai báo biến
	int n;
	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		cout << "Nhap n: "; cin >> n;
		numChange2s(n);
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		//END
		cout << "Nhap phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}

char* numChange2(int n) {
	int du;
	char* str = new char[100];
	int k = 0;
	while (n > 0) {
		if (n % 2 == 0)
			str[k++] = '0';
		else
			str[k++] = '1';
		n /= 2;
	}
	str[k] = '\0';
	return _strrev(str);
}

//Nhập vào số nguyên n, xuất ra tất cả các số từ 0 đến n dưới dạng số nhị phân.
void numChange2s(int n) {
	for (int i = 1; i <= n; i++)
		cout << i << " -> " << numChange2(i) << endl;
}