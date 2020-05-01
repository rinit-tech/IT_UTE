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
//Sinh tất cả các dãy nhị phân có độ dài n.
int tim_0(char* a) {
	for (int i = strlen(a) - 1; i >= 0; i--) {
		if (a[i] == '0')
			return i;
	}
	return -1;
}
void play(int n) {
	char* a = new char[n + 1];

	char* Int = new char[3];
	for (int i = 0; i < n; i++)
		a[i] = '0';
	a[n] = '\0';

	bool check = false;
	do {
		int k = tim_0(a);
		if (k == -1)
			check = true;
		else {
			a[k] = '1';
			for (int i = k + 1; i < strlen(a); i++)
				a[i] = '0';
			cout << a << endl;
		}
	} while (check == false);
}
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
		cin >> n;
		play(n);
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		//END
		cout << "Nhap phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}