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
struct NGAY {
	int d;
	int m;
	int y;
};
//2. KHAI BÁO HẰNG ( CONST )
const int MAX = 100;
//3. KHAI BÁO BIẾN
//4. KHAI BÁO HÀM ( FUNCTION DECLARATIONS / PROTOTYPES )
//CHƯƠNG TRÌNH CHÍNH

//NHẬP NGÀY
NGAY nhapNgay(NGAY& X);

//CHECK NGÀY
bool checkDay(NGAY X);

//XUẤT NGÀY 
void xuatNgay(NGAY X);
void xuatNgay_O(NGAY X);

//Kiểm tra năm nhuận
bool checkLeapYear(int Y);

//TÍNH SỐ THỨ TỰ
//
int dayOfMonth(int M, int Y);
//TÍNH SỐ NGÀY TRONG NĂM
int dayInYear(NGAY X);
//ĐẾM
int startDay(NGAY X);
NGAY reverse_StartDay(int x);

//TÌM NGÀY TRƯỚC ĐÓ VÀ SAU ĐÓ k NGÀY
//TRƯỚC ĐÓ
NGAY dayBf(NGAY X, int day);
//SAU ĐÓ
NGAY dayAf(NGAY X, int day);

//Khoảng cách giữa 2 ngày
int kc_2ngay(NGAY A, NGAY B);

//So sánh 2 ngày
void soSanh(NGAY A, NGAY B);

int main()
{
	//Khai báo biến
	NGAY ngay;
	NGAY ngay_1;
	NGAY ngay_2;
	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		cout << "1. Kiem tra nam nhuan\n";
		cout << "2. Tinh so thu tu ngay trong nam\n";
		cout << "3. Tinh so thu tu ke tu ngay 1/1/1\n";
		cout << "4. Tim ngay truoc do, sau do k ngay\n";
		cout << "5. Tinh khoang cach giua hai ngay\n";
		cout << "6. So sanh 2 ngay\n";
		cout << "Nhap phim bat ki de thoat !!!\n";
		bool Check = true;
		while (Check) {
			int value;
			cout << ">> ";
			cin >> value;
			switch (value) {
			case 1: {
				nhapNgay(ngay);
				xuatNgay(ngay);
				if (checkLeapYear(ngay.y))
					cout << "--> Day la nam nhuan\n";
				else
					cout << "--> Day khong phai nam nhuan\n";
;				break;
			}
			case 2: {
				nhapNgay(ngay);
				xuatNgay(ngay);
				cout << dayInYear(ngay) << endl;
				break;
			}
			case 3: {
				nhapNgay(ngay);
				xuatNgay(ngay);
				cout << startDay(ngay) << endl;
				break;
			}
			case 4: {
				nhapNgay(ngay);
				xuatNgay(ngay);
				int k;
				cout << "Nhap k >> ";
				cin >> k;
				cout << "Ngay truoc do " << k << " ngay la:";
				xuatNgay(dayBf(ngay, k));
				cout << "Ngay sau do " << k << " ngay la:";
				xuatNgay(dayAf(ngay,k));
				break;
			}
			case 5: {
				nhapNgay(ngay_1);
				xuatNgay(ngay_1);
				nhapNgay(ngay_2);
				xuatNgay(ngay_2);
				cout << kc_2ngay(ngay_1, ngay_2) << endl;
				break;
			}
			case 6: {
				nhapNgay(ngay_1);
				xuatNgay(ngay_1);
				nhapNgay(ngay_2);
				xuatNgay(ngay_2);
				soSanh(ngay_1, ngay_2);
				break;
			}
			default: Check = false;
			}

		}
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		//END
		cout << "Nhap phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}

//NHẬP NGÀY
NGAY nhapNgay(NGAY& X) {
	while (true) {
		//CHECK NGÀY
		cout << "Nhap ngay: ";
		cin >> X.d >> X.m >> X.y;
		if (checkDay(X)) return X;
	}
}

//CHECK NGÀY
bool checkDay(NGAY X) {
	if (X.m > 12) return false;
	if (X.d > dayOfMonth(X.m, X.y)) return false;
	return true;
}


//XUẤT NGÀY 
void xuatNgay(NGAY X) {
	cout << X.d << "/" << X.m << "/" << X.y << endl;
}
void xuatNgay_O(NGAY X) {
	cout << X.d << "/" << X.m << "/" << X.y;
}

//Kiểm tra năm nhuận
bool checkLeapYear(int Y) {
	if (Y % 400 == 0 || (Y % 4 == 0 && Y % 100 != 0))
		return true;
	return false;
}

//TÍNH SỐ THỨ TỰ
//
int dayOfMonth(int M, int Y) {
	switch (M) {
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
		if (checkLeapYear(Y) == true) return 29;
		else return 28;
	}
}
//TÍNH SỐ NGÀY TRONG NĂM
int dayInYear(NGAY X) {
	int sumDay = 0;
	for (int i = 1; i < X.m; i++) {
		sumDay += dayOfMonth(i, X.y);
	}
	return sumDay + X.d;
}
//ĐẾM
int startDay(NGAY X) {
	int y = X.y - 1; // lấy trước 1 năm so với năm đang tính
	int leapYear = y / 4;
	int duLeapYear = y / 100;
	int du_LeapYear = y / 400;
	int ngayOfLeap = leapYear - duLeapYear + du_LeapYear;
	int ngayOfNow = dayInYear(X);
	return y * 365 + ngayOfLeap + ngayOfNow - 1;
}
//Chuyển từ StartDay sang day ( vấn chưa tìm ra lỗi )
NGAY reverse_StartDay(int x) {
	int y = (x / 365.24) + 1;
	int y_O = y - 1; // lấy trước 1 năm so với năm đang tính
	int leapYear = y_O / 4;
	int duLeapYear = y_O / 100;
	int du_LeapYear = y_O / 400;
	int ngayOfLeap = leapYear - duLeapYear + du_LeapYear;
	//Tính từ ngày dư ra ngày và tháng
	int sumDay = x - (y_O * 365 + ngayOfLeap);
	int i = 1;
	int month = 1;
	while (true) {
		int dayOfM = dayOfMonth(i++, y);
		if (sumDay < dayOfM) break;
		else {
			sumDay -= dayOfM;
			month++;
		}
	}
	return { sumDay + 1, month, y };
}

//TÌM NGÀY TRƯỚC ĐÓ VÀ SAU ĐÓ k NGÀY
//TRƯỚC ĐÓ
NGAY dayBf(NGAY X, int day) {
	return reverse_StartDay(startDay(X) - day);
}
//SAU ĐÓ
NGAY dayAf(NGAY X, int day) {
	return reverse_StartDay(startDay(X) + day);
}

//Khoảng cách giữa 2 ngày
int kc_2ngay(NGAY A, NGAY B) {
	return abs(startDay(A) - startDay(B));
}

//So sánh 2 ngày
void soSanh(NGAY A, NGAY B) {
	int a = startDay(A);
	int b = startDay(B);
	if (a > b) {
		xuatNgay_O(B);
		cout << " som hon ";
		xuatNgay_O(A);
		cout << endl;
	}
	else if (a < b) {
		xuatNgay_O(A);
		cout << " som hon ";
		xuatNgay_O(B);
		cout << endl;
	}
}