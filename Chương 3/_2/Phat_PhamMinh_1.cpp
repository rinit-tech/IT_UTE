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
using namespace std;
//CHƯƠNG TRÌNH CHÍNH
//KHAI BÁO TOÀN CỤC (GLOBALLY) - SỬ DỤNG CHUNG CHO TOÀN BỘ CHƯƠNG TRÌNH\
//1. KHAI BÁO KIỂU DỮ LIỆU ( NEW )
//2. KHAI BÁO HẰNG ( CONST )
const int MAX = 100;
//3. KHAI BÁO BIẾN

//4. KHAI BÁO HÀM ( FUNCTION DECLARATIONS / PROTOTYPES )

unsigned int bai1(int x, int p) {
	int s = 1;
	while (0 < p--) s *= x;
	return s;
}
int bai2(int x) {
	if (x == 1) return 1;
	
	x++;
	int s = 0;
	while (x-- > 0) s += (x * (x + 1)) / 2;
	return s;
}

float bai3(int x) {
	if (x == 1) return 1;

	x++;
	float s = 0;
	while (x-- > 1) s +=(float) 1 / ((x * (x + 1)) / 2);
	return s;
}

int bai4(int n) {
	int s = 0;
	int x = 1;
	for (int i = 1; i <= n; i++) {
		x *= i;
		s += x;
	}
	return s;
}


int giaithua(int n) {
	if (n <= 2)return n;
	n++;
	int s = 1;
	while (n-- > 1) s *= n;
	return s;
}
float bai5(int n) {
	float s = 0;
	for (int i = 1; i <= n; i++)
		s += (float)1 / giaithua(i);
	return s;
}

////CỘNG CHAR
//char* tinhtong(char a[], char b[]);

//CHƯƠNG TRÌNH CHÍNH
int main()
{
	//Khai báo biến

	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		int n, k;
		cout << "Nhap n: ";
		cin >> n;
		cout << "Nhap k: ";
		cin >> k;
		cout << n << " mu " << k << " = " << bai1(n, k) << endl;
		cout << "bai 2 " << bai2(n) << endl;
		cout << "bai 3 " << bai3(n) << endl;
		cout << "bai 4 " << bai4(n) << endl;
		cout << "bai 5 " << bai5(n) << endl;
		
		


		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		//END
		cout << "Nhap phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}

//char* tinhtong(char a[], char b[]) {
//	a = _strrev(a);
//	b = _strrev(b);
//	int a_len = strlen(a);
//	int b_len = strlen(b);
//
//	int len_M = a_len > b_len ? a_len : b_len;
//
//	int i = 0;
//	char* str = new char[100];
//	int k = 0;
//	int du = 0;
//	while (i < len_M) {
//		if (i >= a_len) {
//			str[k++] = char(du) + b[i];
//			du = 0;
//		}
//		else if (i >= b_len) {
//			str[k++] = char(du) + a[i]  ;
//			du = 0;
//		}
//		else {
//			int tong = ((int)a[i] + (int)b[i] - 96) + du;
//			str[k++] = ((char)tong % 10) + 48;
//			du = tong / 10;
//		}
//			i++;
//	}
//	str[k] = '\0';
//	return _strrev(str);
//}