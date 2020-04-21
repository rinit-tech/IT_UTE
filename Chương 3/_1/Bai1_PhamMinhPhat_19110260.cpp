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
struct PHANSO {
	int tu;
	int mau;
};

//2. KHAI BÁO HẰNG ( CONST )
const int MAX = 100;
//3. KHAI BÁO BIẾN

//4. KHAI BÁO HÀM ( FUNCTION DECLARATIONS / PROTOTYPES )
//NHẬP PHÂN SỐ
PHANSO nhapPhanSo(PHANSO& A);

//XUẤT PHÂN SỐ
void xuatPhanSo(PHANSO A);

void xuatPhanSo_O(PHANSO A);

//NHẬP MẢNG PHÂN SỐ
void nhapMangPhSo(PHANSO A[], int& n);

//XUẤT MẢNG PHÂN SỐ
void xuatMangPhSo(PHANSO A[], int n);

int gcd(int a, int b);

int BCNN(int a, int b);

PHANSO rutGon(PHANSO A);

void rutGonMang(PHANSO A[], int n);

//TÍNH TỔNG CÁC PHÂN SỐ
int mauChung(PHANSO A[], int n);

PHANSO tongPhanSo(PHANSO A[], int n);
//KẾT THÚC

void quyDong(PHANSO& A, PHANSO& B);

int soSanh(PHANSO A, PHANSO B);


void hoanDoi(PHANSO& A, PHANSO& B);

//SẮP XẾP MẢNG TĂNG DẦN
void sortPhSo_Tang(PHANSO A[], int n);

//TÌM PHÂN SỐ MIN - MAX
void search_Min_Max(PHANSO A[], int n);


//CHƯƠNG TRÌNH CHÍNH
int main()
{
	//Khai báo biến
	PHANSO A[MAX];
	int n;
	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		nhapMangPhSo(A, n);
		xuatMangPhSo(A, n);
		cout << "Tong cac phan so trong mang: ";
		xuatPhanSo_O(tongPhanSo(A, n));
		search_Min_Max(A, n);
		cout << "Sap xep tang dan: ";
		sortPhSo_Tang(A, n);
		xuatMangPhSo(A, n);
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		//END
		cout << "Nhap phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}



//NHẬP PHÂN SỐ
PHANSO nhapPhanSo(PHANSO& A) {
	cin >> A.tu >> A.mau;
	if (A.mau == 0) {
		PHANSO s = { 0,0 };
		A = s;
	}
	if (A.mau < 0)
	{
		A.tu = -A.tu;
		A.mau = -A.mau;
	}
	return A;
}

//XUẤT PHÂN SỐ
void xuatPhanSo(PHANSO A) {
	if (A.tu % A.mau == 0)
		cout << A.tu / A.mau << " ";
	else
		cout << A.tu << "/" << A.mau << " ";
}

void xuatPhanSo_O(PHANSO A) {
	if (A.tu % A.mau == 0)
		cout << A.tu / A.mau << endl;
	else
		cout << A.tu << "/" << A.mau << endl;
}

//NHẬP MẢNG PHÂN SỐ
void nhapMangPhSo(PHANSO A[], int& n) {
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Phan so thu #" << i << endl;
		nhapPhanSo(A[i]);
	}
}

//XUẤT MẢNG PHÂN SỐ
void xuatMangPhSo(PHANSO A[], int n) {
	for (int i = 0; i < n; i++) {
		xuatPhanSo(A[i]);
	}
	cout << endl;
}

int gcd(int a, int b) {
	a = a < 0 ? -a : a;
	if (a == 0 || b == 0) {
		return a + b;
	}
	while (a != b) {
		if (a > b) {
			a -= b; // a = a - b
		}
		else {
			b -= a;
		}
	}
	return a; // return a or b, bởi vì lúc này a và b bằng nhau
}

int BCNN(int a, int b) {
	return (a * b / gcd(a, b));
}

PHANSO rutGon(PHANSO A) {
	int GCD = gcd(A.tu, A.mau);
	if (GCD == 1)
		return A;
	A.tu /= GCD;
	A.mau /= GCD;
	return A;
}

void rutGonMang(PHANSO A[], int n) {
	for (int i = 0; i < n; i++)
		A[i] = rutGon(A[i]);
}

//TÍNH TỔNG CÁC PHÂN SỐ
int mauChung(PHANSO A[], int n) {
	int mauChung = BCNN(A[0].mau, A[1].mau);
	for (int i = 2; i < n; i++) {
		mauChung = BCNN(mauChung, A[i].mau);
	}
	return mauChung;
}

PHANSO tongPhanSo(PHANSO A[], int n) {
	rutGonMang(A, n);
	int mau = mauChung(A, n);
	int tu = 0;
	for (int i = 0; i < n; i++) 
		tu += A[i].tu * (mau / A[i].mau);
	PHANSO result;
	result.tu = tu;
	result.mau = mau;
	return rutGon(result);
}
//KẾT THÚC

void quyDong(PHANSO& A, PHANSO& B) {
	int a = A.mau;
	int b = B.mau;
	A.tu *= b;
	A.mau *= b;
	B.tu *= a;
	B.mau *= a;
}

int soSanh(PHANSO A, PHANSO B) {
	PHANSO a, b;
	a = rutGon(A);
	b = rutGon(B);
	quyDong(a, b);
	if (a.tu == b.tu) {
		return 0;
	}
	else if (a.tu > b.tu) {
		return 1;
	}
	else {
		return -1;
	}
}


void hoanDoi(PHANSO& A, PHANSO& B) {
	PHANSO	tg = A;
	A = B;
	B = tg;
}

//SẮP XẾP MẢNG TĂNG DẦN
void sortPhSo_Tang(PHANSO A[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)
			if (soSanh(A[i], A[j]) == 1)
				hoanDoi(A[i], A[j]);
	}
}

//TÌM PHÂN SỐ MIN - MAX
void search_Min_Max(PHANSO A[], int n) {
	sortPhSo_Tang(A, n);
	cout << "Min: "; xuatPhanSo_O(A[0]);
	cout << "Max: "; xuatPhanSo_O(A[n - 1]);
}


