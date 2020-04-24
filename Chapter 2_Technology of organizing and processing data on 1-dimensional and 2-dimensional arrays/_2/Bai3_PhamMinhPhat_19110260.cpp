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
char* tinhtong(char a[], char b[]);
void hoanDoi(char* a, char* b);

//CHƯƠNG TRÌNH CHÍNH
int main()
{
	//Khai báo biến
	char* a = new char[300];
	char* b = new char[300];

	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		cout << "Nhap mot chuoi so a bat ki: ";
		cin.getline(a, 50);
		cout << "Nhap mot chuoi so b bat ki: ";
		cin.getline(b, 50);
		cout << "a + b = " << tinhtong(a, b) << endl;
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		//END
		cout << "Nhap phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}

void hoanDoi(char* a, char* b) {
	char* tg = new char[300];
	if (strlen(b) > strlen(a)) {
		strcpy(tg, a);
		strcpy(a, b);
		strcpy(b, tg);
	}
	delete tg;
}

char* tinhtong(char* a, char* b) {
	hoanDoi(a, b);

	//Đảo ngược 2 chuỗi
	a = _strrev(a);
	b = _strrev(b);
	int maxLen = strlen(a);

	int i = 0;
	char* str = new char[300];
	int k = 0;
	int du = 0;
	while (i < strlen(a)) {
		if (i >= strlen(b)) {
			str[k++] = char(du) + a[i];
			du = 0;
		}
		else {
			int tong = ((int)a[i] + (int)b[i] - 96) + du;
			str[k++] = ((char)tong % 10) + 48;
			du = tong / 10;
		}
		i++;
	}
	str[k] = '\0';
	return _strrev(str);
}

