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

//RÚT GỌN
//1. UCLN
int gcd(int a, int b);
//2. Rút gon
PHANSO rutGon(PHANSO A);

//CỘNG - TRỪ - NHÂN - CHIA
//1. CỘNG
PHANSO congPhSo(PHANSO A, PHANSO B);
//2. TRỪ
PHANSO truPhSo(PHANSO A, PHANSO B);
//3. NHÂN 
PHANSO nhanPhSo(PHANSO A, PHANSO B);
//4. CHIA
PHANSO chiaPhSo(PHANSO A, PHANSO B);

//CHECK TỐI GIẢN
bool checkToiGian(PHANSO A);

//QUY ĐÔNG 2 PHÂN SỐ
void quyDong(PHANSO& A, PHANSO& B);

//CHECK ÂM DƯƠNG 
int checkAmDuong(PHANSO A);

//SO SÁNH
void soSanh(PHANSO A, PHANSO B);

//CHƯƠNG TRÌNH CHÍNH
int main()
{
	//Khai báo biến
	PHANSO phSo;
	PHANSO phSo_1;
	PHANSO phSo_2;
	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		cout << "1. Rut gon phan so\n";
		cout << "2. Tinh tong, hieu, tich thuong hai phan so\n";
		cout << "3. Kiem tra phan so toi gian\n";
		cout << "4. Quy dong 2 phan so\n";
		cout << "5. Kiem tra phan so am hay duong\n";
		cout << "6. So sanh 2 phan sp\n";
		cout << "Nhap phim bat ki de thoat !!!\n";
		bool Check = true;
		while (Check) {
			int value;
			cout << ">> ";
			cin >> value;
			switch (value) {
			case 1: {
				nhapPhanSo(phSo);
				xuatPhanSo(phSo);
				xuatPhanSo(rutGon(phSo));
				break;
			}
			case 2: {
				nhapPhanSo(phSo_1);
				xuatPhanSo(phSo_1);
				nhapPhanSo(phSo_2);
				xuatPhanSo(phSo_2);
				xuatPhanSo(congPhSo(phSo_1, phSo_2));
				xuatPhanSo(truPhSo(phSo_1, phSo_2));
				xuatPhanSo(nhanPhSo(phSo_1, phSo_2));
				xuatPhanSo(chiaPhSo(phSo_1, phSo_2));
				break;
			}
			case 3: {
				nhapPhanSo(phSo);
				xuatPhanSo(phSo);
				if (checkToiGian(phSo) == 1) {
					cout << "--> Da toi gian\n";
				}
				else {
					cout << "--> Chua toi gian\n";
				}
				break;
			}
			case 4: {
				nhapPhanSo(phSo_1);
				xuatPhanSo(phSo_1);
				nhapPhanSo(phSo_2);
				xuatPhanSo(phSo_2);
				quyDong(phSo_1, phSo_2);
				cout << "--> Phan so da quy dong: \n";
				xuatPhanSo(phSo_1);
				xuatPhanSo(phSo_2);
				break;
			}
			case 5: {
				nhapPhanSo(phSo);
				xuatPhanSo(phSo);
				if (checkAmDuong(phSo) == 1)
					cout << "--> Phan so duong\n";
				else
					cout << "--> Phan so am\n";
				break;
			}
			case 6: {
				nhapPhanSo(phSo_1);
				xuatPhanSo(phSo_1);
				nhapPhanSo(phSo_2);
				xuatPhanSo(phSo_2);
				soSanh(phSo_1, phSo_2);
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
	cout << "Tu = ";
	cin >> A.tu;
	while (true) {
		cout << "Mau = ";
		cin >> A.mau;
		if (A.mau != 0) break;
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
	cout << A.tu << "/" << A.mau << endl;
}
void xuatPhanSo_O(PHANSO A) {
	cout << A.tu << "/" << A.mau;
}

//RÚT GỌN
//1. UCLN
int gcd(int a, int b) {
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
//2. Rút gọn
PHANSO rutGon(PHANSO A) {
	int GCD = gcd(A.tu, A.mau);
	if (GCD == 1)
		return A;
	A.tu /= GCD;
	A.mau /= GCD;
	return A;
}

//CỘNG - TRỪ - NHÂN - CHIA
//1. CỘNG
PHANSO congPhSo(PHANSO A, PHANSO B) {
	PHANSO AB;
	if (A.mau == B.mau) {
		AB.tu = A.tu + B.tu;
		AB.mau = A.mau;
	}
	else {
		AB.tu = A.tu * B.mau + B.tu * A.mau;
		AB.mau = A.mau * B.mau;
	}
	return rutGon(AB);
}
//2. TRỪ
PHANSO truPhSo(PHANSO A, PHANSO B) {
	PHANSO AB;
	if (A.mau == B.mau) {
		AB.tu = A.tu - B.tu;
		AB.mau = A.mau;
	}
	else {
		AB.tu = A.tu * B.mau - B.tu * A.mau;
		AB.mau = A.mau * B.mau;
	}
	return rutGon(AB);
}
//3. NHÂN 
PHANSO nhanPhSo(PHANSO A, PHANSO B) {
	PHANSO AB;
	AB.tu = A.tu * B.tu;
	AB.mau = A.mau * B.mau;
	return rutGon(AB);
}
//4. CHIA
PHANSO chiaPhSo(PHANSO A, PHANSO B) {
	PHANSO AB;
	AB.tu = A.tu * B.mau;
	AB.mau = A.mau * B.tu;
	return rutGon(AB);
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

//SO SÁNH
void soSanh(PHANSO A, PHANSO B) {
	PHANSO a, b;
	a = rutGon(A);
	b = rutGon(B);
	quyDong(a, b);
	if (a.tu == b.tu) {
		xuatPhanSo_O(A);
		cout << " = ";
		xuatPhanSo_O(B);
		cout << endl;
	}
	else if (a.tu > b.tu) {
		xuatPhanSo_O(A);
		cout << " > ";
		xuatPhanSo_O(B);
		cout << endl;
	}
	else {
		xuatPhanSo_O(A);
		cout << " < ";
		xuatPhanSo_O(B);
		cout << endl;
	}
}