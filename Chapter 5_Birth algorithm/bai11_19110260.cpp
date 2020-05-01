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
//Sinh tất cả hoán vị của tập n phần tử.
int vtriInhoI1(char* a) {
	for (int i = strlen(a) - 2; i >= 0; i--)
		if (int(a[i]) < int(a[i + 1]))
			return i;
	return -1;
}

int vtrik(char* a, int vtriInhoI1) {
	char max = a[vtriInhoI1];
	for (int i = strlen(a) - 1; i > vtriInhoI1; i--)
		if (int(a[i]) > int(max))
			return i;
	return 0;
}

void swap(char*& a, int i, int k) {
	char tg = a[k];
	a[k] = a[i];
	a[i] = tg;
}

void sapXepTang(char*& a, int i) {
	for (; i < strlen(a) - 1; i++)
		for (int j = i + 1; j < strlen(a); j++)
			if (int(a[i]) > int(a[j]))
				swap(a[i], a[j]);
}

void play(int n) {
	char* a = new char[n + 1];

	for (int i = 0; i < n; i++) {
		a[i] = i + 49;
	}
	a[n] = '\0';

	cout << a << endl;

	bool check = false;
	do {
		int i = vtriInhoI1(a);
		if (i == -1)
			check = true;
		else {
			int k = vtrik(a, i);
			swap(a, k, i);
			sapXepTang(a, i + 1);
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