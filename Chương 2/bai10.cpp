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
//CHƯƠNG TRÌNH CHÍNH
//Kiểm tra năm nhuận
bool checkLeapYear(int YYYY);
//Ngày tiếp theo
void theNextDay(int DD, int MM, int YYYY);
//Tháng có bao nhiêu ngày
int dayOfMonth(int MM, int YYYY);
int main()
{
	//Khai báo biến

	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		int DD, MM, YYYY;
		cout << "Day: "; cin >> DD;
		cout << "Month: "; cin >> MM;
		cout << "Year: "; cin >> YYYY;

		cout << "Ngay " << DD << " Thang " << MM << " Nam " << YYYY << endl;
		theNextDay(DD, MM, YYYY);

		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		//END
		cout << "Nhap phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}
//Kiểm tra năm nhuận
bool checkLeapYear(int YYYY) {
	if (YYYY % 400 == 0 || (YYYY % 4 == 0 && YYYY % 100 != 0))
		return true;
	return false;
}
void theNextDay(int DD, int MM, int YYYY) {
	int numOfDay = dayOfMonth(MM, YYYY);
	if (DD > numOfDay) cout << "-1";
	if (DD == numOfDay && MM == 12)
	{
		YYYY++;
		cout << "Ngay "<< 1 << " Thang " << MM << " Nam " << YYYY << endl;
	}
	else if (DD == numOfDay) {
		MM++;
		cout << "Ngay " << 1 << " Thang " << MM << " Nam " << YYYY << endl;
	}else{
		DD++;
		cout << "Ngay " << DD << " Thang " << MM << " Nam " << YYYY << endl;
	}
}
int dayOfMonth(int MM, int YYYY) {
	switch (MM) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: return 31;
	case 4:
	case 6:
	case 9:
	case 11: return 30;
	case 2:
		if (checkLeapYear(YYYY) == true) return 29;
		else return 28;
	}
}

