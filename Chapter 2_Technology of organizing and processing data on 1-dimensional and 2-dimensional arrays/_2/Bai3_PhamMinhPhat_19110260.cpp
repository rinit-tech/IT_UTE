#define _CRT_SECURE_NO_WARNINGS
/*
Công dụng:
Tác giả:		Phạm Minh Phát
MSSV:			19110260
Ngày viết:
Ngày cập nhập:
*/
//THƯ VIỆN
#include <iostream> //cin và cout
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
void tinhTong(char *a, char *b, char *&result_tinhTong);

void hoanDoi(char *a, char *b);

char *themSoKhong(char *&a, int n);

//CHƯƠNG TRÌNH CHÍNH
int main()
{
	//Khai báo biến
	char *a = new char[300];
	char *b = new char[300];

	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		cout << "Nhap mot chuoi so a bat ki: ";
		cin.getline(a, 50);
		cout << "Nhap mot chuoi so b bat ki: ";
		cin.getline(b, 50);
		char *result = new char[MAX];
		tinhTong(a, b, result);
		cout << "a + b = " << result << endl;
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		//END
		cout << "Nhap phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}

void hoanDoi(char *a, char *b)
{
	char *tg = new char[300];
	if (strlen(b) > strlen(a))
	{
		strcpy(tg, a);
		strcpy(a, b);
		strcpy(b, tg);
	}
	delete[] tg;
}

void tinhTong(char *a, char *b, char *&result_tinhTong)
{
	hoanDoi(a, b);

	//Đảo ngược 2 chuỗi
	_strrev(a);
	_strrev(b);

	//Cân bằng 2 chuỗi
	int len = strlen(a) - strlen(b);
	themSoKhong(b, len);

	int maxLen = strlen(a);

	int k = 0, du = 0;

	for (int i = 0; i < maxLen; i++)
	{
		int tong = ((int)a[i] + (int)b[i] - 96) + du;
		result_tinhTong[k++] = ((char)tong % 10) + 48;
		du = tong / 10;
		if (i == maxLen - 1 && du > 0)
		{
			result_tinhTong[k++] = du + 48;
		}
	}
	result_tinhTong[k] = '\0';
	_strrev(result_tinhTong);
}

char *themSoKhong(char *&a, int n)
{
	if (n == 0)
		return a;
	int len = strlen(a);
	for (int i = 0; i < n; i++)
	{
		a[len++] = '0';
	}
	a[len] = '\0';
	return a;
}
