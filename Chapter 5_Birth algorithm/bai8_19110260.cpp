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
int MangTamThoi1[MAX], PhtuMtamThoi1 = 0;
int MangTamThoi2[MAX], PhtuMtamThoi2 = 0;
int MangTamThoi3[MAX], PhtuMtamThoi3 = 0;
int MangTamThoi4[MAX], PhtuMtamThoi4 = 0;
//4. KHAI BÁO HÀM ( FUNCTION DECLARATIONS / PROTOTYPES )
//Viết chương trình kiểm tra một chuỗi có đối xứng không ?
void copyStr(char* a, char*& b) {
	for (int i = 0; i < strlen(a); i++) {
		b[i] = a[i];
	}
	b[strlen(a)] = '\0';
	return;
}

bool soSanhChuoiDoiXung(char* a) {
	char* str = new char[MAX];
	copyStr(a, str);
	_strrev(str);
	if (strcmp(str, a) > 0)
		return false;
	return true;
}
//CHƯƠNG TRÌNH CHÍNH
int main()
{
	//Khai báo biến
	char str[MAX];
	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		//1. Nhập chuỗi
		cout << "Nhap mot chuoi bat ki: ";
		cin.getline(str, 50);
		//2. In và xuất chuỗi
		cout << "Chuoi vua nhap:" << str << endl;

		if (soSanhChuoiDoiXung(str))
			cout << "Chuoi " << str << " doi xung !" << endl;
		else
			cout << "Chuoi " << str << " khong doi xung !" << endl;
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		//END
		cout << "Nhap phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}