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
//Sinh tất cả tập con của tập n phần tử.
void xuat(int a[], int k) {
	for (int i = 1; i <= k; i++)
		cout << a[i] << "  ";
	cout << endl;
}
void chinhHop(int a[], int n, int k) {
	for (int i = 1; i <= n; i++) a[i] = i;

	bool check = true;
	do {
		xuat(a, k);
		int i = k;
		while (i > 0 && a[i] == n + i - k)i--;
		a[i]++;
		if (i > 0) {
			for (int j = i + 1; j <= n; j++)
				a[j] = a[i] + j - i;
		}
		else check = false;
	} while (check);
}
void play(int a[], int n) {
	for (int i = 1; i <= n; i++) {
		chinhHop(a, n, i);
	}
}

//CHƯƠNG TRÌNH CHÍNH
int main()
{
	//Khai báo biến
	int n;
	int a[100];
	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		cin >> n;
		play(a, n);
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		//END
		cout << "Nhap phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}