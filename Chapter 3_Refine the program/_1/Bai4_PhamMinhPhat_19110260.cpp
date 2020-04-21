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


////CỘNG CHAR
float eMuN(int x, int n) {
	if (n == 0) return 1;
	float sum = 1;
	int tu = 1;
	int mau = 1;
	for (int i = 1; i <= n; i++) {
		tu *= x;
		mau *= i;
		sum += (float)tu / mau;
	}
	return sum;
}

//CHƯƠNG TRÌNH CHÍNH
int main()
{
	//Khai báo biến
	int n,x;
	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		cout << "Nhap x: ";
		cin >> x;
		cout << "Nhap n: ";
		cin >> n;
		cout << eMuN(x, n) << endl;



		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		cout << "Nhap phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}



