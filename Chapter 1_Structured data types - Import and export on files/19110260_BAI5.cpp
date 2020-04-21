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

//RÚT GỌN
//1. UCLN
int gcd(int a, int b);
//2. RÚT GỌN
PHANSO rutGon(PHANSO A);
//3. RÚT GỌN MẢNG PHÂN SỐ
void rutGonMang(PHANSO A[], int n);

//CHECK TỐI GIẢN
bool checkToiGian(PHANSO A);

//QUY ĐÔNG 2 PHÂN SỐ
void quyDong(PHANSO& A, PHANSO& B);

//CHECK ÂM DƯƠNG 
int checkAmDuong(PHANSO A);

//ĐẾM SỐ LƯỢNG ÂM DƯƠNG
void amDuong(PHANSO A[], int n);

//TÌM PHÂN SỐ DƯƠNG ĐẦU TIỀN TRONG MẢNG
PHANSO firstPlus(PHANSO A[], int n);

//SO SÁNH
int soSanh(PHANSO A, PHANSO B);

//HOÁN ĐỔI
void hoanDoi(PHANSO& A, PHANSO& B);
//SẮP XẾP TĂNG GIẢM
void sortPhSo_Tang(PHANSO A[], int n);
void sortPhSo_Giam(PHANSO A[], int n);

//Search Min - Max
void search_Min_Max(PHANSO A[], int n);

//CHƯƠNG TRÌNH CHÍNH
int main()
{
	//Khai báo biến
	PHANSO phanSo[MAX];
	int n;
	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		cout << "1. Rut gon moi phan so\n";
		cout << "2. Dem so luong phan so am, duong trong mang\n";
		cout << "3. Tim phan so duong dau tien trong mang\n";
		cout << "4. Tim phan so nho nhat, lon nhat trong mang\n";
		cout << "5. Sap xep mang theo chieu tang dan, giam dan\n";
		cout << "Nhap phim bat ki de thoat !!!\n";
		bool Check = true;
		while (Check) {
			int value;
			cout << ">> ";
			cin >> value;
			switch (value) {
			case 1: {
				nhapMangPhSo(phanSo, n);
				xuatMangPhSo(phanSo, n);
				rutGonMang(phanSo, n);
				xuatMangPhSo(phanSo, n);
				break;
			}
			case 2: {
				nhapMangPhSo(phanSo, n);
				xuatMangPhSo(phanSo, n);
				amDuong(phanSo, n);
				break;
			}
			case 3: {
				nhapMangPhSo(phanSo, n);
				xuatMangPhSo(phanSo, n);
				xuatPhanSo(firstPlus(phanSo, n));
				cout << endl;
				break;
			}
			case 4: {
				nhapMangPhSo(phanSo, n);
				xuatMangPhSo(phanSo, n);
				search_Min_Max(phanSo, n);
				break;
			}
			case 5: {
				nhapMangPhSo(phanSo, n);
				xuatMangPhSo(phanSo, n);
				sortPhSo_Tang(phanSo, n);
				xuatMangPhSo(phanSo, n);
				sortPhSo_Giam(phanSo, n);
				xuatMangPhSo(phanSo, n);
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


//RÚT GỌN
//1. UCLN
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
//2. RÚT GỌN
PHANSO rutGon(PHANSO A) {
	int GCD = gcd(A.tu, A.mau);
	if (GCD == 1)
		return A;
	A.tu /= GCD;
	A.mau /= GCD;
	return A;
}
//3. RÚT GỌN MẢNG PHÂN SỐ
void rutGonMang(PHANSO A[], int n) {
	for (int i = 0; i < n; i++)
		A[i] = rutGon(A[i]);
}

//CHECK TỐI GIẢN
bool checkToiGian(PHANSO A) {
	return gcd(A.tu, A.mau) == 1 ? true : false;
}

//QUY ĐÔNG 2 PHÂN SỐ
void quyDong(PHANSO& A, PHANSO& B) {
	int a = A.mau;
	int b = B.mau;
	A.tu *= b;
	A.mau *= b;
	B.tu *= a;
	B.mau *= a;
}

//CHECK ÂM DƯƠNG 
int checkAmDuong(PHANSO A) {
	return A.tu < 0 ? -1 : 1;
}

//ĐẾM SỐ LƯỢNG ÂM DƯƠNG
void amDuong(PHANSO A[], int n) {
	int am = 0;
	int duong = 0;
	for (int i = 0; i < n; i++) {
		if (checkAmDuong(A[i]) == -1) am++;
		else duong++;
	}
	cout << "Am: " << am << "\n" << "Duong: " << duong << endl;
}

//TÌM PHÂN SỐ DƯƠNG ĐẦU TIỀN TRONG MẢNG
PHANSO firstPlus(PHANSO A[], int n) {
	int i = 0;
	A[n] = { 1,1 };
	while (checkAmDuong(A[i]) == -1) i++;
	if (i >= n) return { 1,0 };
	else return A[i];
}

//SO SÁNH
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

//HOÁN ĐỔI
void hoanDoi(PHANSO& A, PHANSO& B) {
	PHANSO	tg = A;
	A = B;
	B = tg;
}
//SẮP XẾP TĂNG GIẢM
void sortPhSo_Tang(PHANSO A[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)
			if (soSanh(A[i], A[j]) == 1)
				hoanDoi(A[i], A[j]);
	}
}
void sortPhSo_Giam(PHANSO A[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)
			if (soSanh(A[i], A[j]) == -1)
				hoanDoi(A[i], A[j]);
	}
}

//Search Min - Max
void search_Min_Max(PHANSO A[], int n) {
	sortPhSo_Tang(A, n);
	cout << "Min: "; xuatPhanSo_O(A[0]);
	cout << "Max: "; xuatPhanSo_O(A[n - 1]);
}