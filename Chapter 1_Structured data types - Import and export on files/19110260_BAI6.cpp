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
struct DIEM {
	int x;
	int y;
};
//2. KHAI BÁO HẰNG ( CONST )
const int MAX = 100;
//3. KHAI BÁO BIẾN

//4. KHAI BÁO HÀM ( FUNCTION DECLARATIONS / PROTOTYPES )

//NHẬP ĐIỂM
//NHẬP 1 ĐIỂM 
DIEM nhapDiem(DIEM& A);
//NHẬP MẢNG ĐIỂM
void nhapMangDiem(DIEM A[], int& n);

//XUẤT ĐIỂM
//XUẤT 1 ĐIỂM
void xuatDiem(DIEM A);
//XUẤT MẢNG ĐIỂM
void xuatMangDiem(DIEM A[], int n);

//ĐẾM SỐ ĐIỂM CÓ HOÀNH ĐỘ DƯƠNG
int sumX_Plus(DIEM A[], int n);

//ĐẾM SỐ LƯƠNG ĐIỂM KHÔNG TRÙNG NHAU 
int pointNotLike(DIEM A[], int n);

//TÌM ĐIỂM CÓ HOÀNG ĐỘ LỚN, NHỎ NHẤT
//HOÀNH ĐỘ LỚN 
DIEM pointX_Max(DIEM A[], int n);
//HOÀNH ĐỘ NHỎ
DIEM pointX_Min(DIEM A[], int n);

//TÌM ĐIỂM GẦN GỐC TỌA ĐỘ NHẤT
//KHOẢNG CÁCH
float kC(DIEM A);
//ĐIỂM GẦN GỐC TỌA ĐỘ
DIEM min_0_0(DIEM A[], int n);

//CHƯƠNG TRÌNH CHÍNH
int main()
{
	//Khai báo biến
	DIEM diem[MAX];
	int n;
	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		cout << "1. Dem so luong diem co hoanh do duong\n";
		cout << "2. Dem so luong diem khong trung\n";
		cout << "3. Tim diem cho hoanh do lon nhat, nho nhat\n";
		cout << "4. Tim diem gan goc toa do\n";
		cout << "Nhap phim bat ki de thoat !!!\n";
		bool Check = true;
		while (Check) {
			int value;
			cout << ">> ";
			cin >> value;
			switch (value) {
			case 1: {
				nhapMangDiem(diem, n);
				xuatMangDiem(diem, n);
				cout << sumX_Plus(diem, n) << endl;
				break;
			}
			case 2: {
				nhapMangDiem(diem, n);
				xuatMangDiem(diem, n);
				cout << pointNotLike(diem, n) << endl;
				break;
			}
			case 3: {
				nhapMangDiem(diem, n);
				xuatMangDiem(diem, n);
				xuatDiem(pointX_Max(diem, n));
				xuatDiem(pointX_Min(diem, n));
				cout << endl;
				break;
			}
			case 4: {
				nhapMangDiem(diem, n);
				xuatMangDiem(diem, n);
				xuatDiem(min_0_0(diem, n));
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

//NHẬP ĐIỂM
//NHẬP 1 ĐIỂM 
DIEM nhapDiem(DIEM& A) {
	cin >> A.x >> A.y;
	return A;
}
//NHẬP MẢNG ĐIỂM
void nhapMangDiem(DIEM A[], int& n) {
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		nhapDiem(A[i]);
}

//XUẤT ĐIỂM
//XUẤT 1 ĐIỂM
void xuatDiem(DIEM A) {
	cout << "{" << A.x << "," << A.y << "}  ";
}
//XUẤT MẢNG ĐIỂM
void xuatMangDiem(DIEM A[], int n) {
	for (int i = 0; i < n; i++) {
		xuatDiem(A[i]);
	}
	cout << endl;
}

//ĐẾM SỐ ĐIỂM CÓ HOÀNH ĐỘ DƯƠNG
int sumX_Plus(DIEM A[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (A[i].x > 0) sum++;
	}
	return sum;
}

//ĐẾM SỐ LƯƠNG ĐIỂM KHÔNG TRÙNG NHAU 
int pointNotLike(DIEM A[], int n) {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		int j = i + 1;
		A[n].x = A[i].x;
		while (A[i].x != A[j].x && A[i].y != A[j].y) j++;
		if (j >= n) sum++;
	}
	return sum;
}

//TÌM ĐIỂM CÓ HOÀNG ĐỘ LỚN, NHỎ NHẤT
//HOÀNH ĐỘ LỚN 
DIEM pointX_Max(DIEM A[], int n) {
	DIEM Max = A[0];
	for (int i = 1; i < n; i++) {
		if (A[i].x > Max.x)
			Max = A[i];
	}
	return Max;
}
//HOÀNH ĐỘ NHỎ
DIEM pointX_Min(DIEM A[], int n) {
	DIEM Min = A[0];
	for (int i = 1; i < n; i++) {
		if (A[i].x < Min.x)
			Min = A[i];
	}
	return Min;
}

//TÌM ĐIỂM GẦN GỐC TỌA ĐỘ NHẤT
//KHOẢNG CÁCH
float kC(DIEM A) {
	return (float)sqrt(A.x * A.x + A.y * A.y);
}
//ĐIỂM GẦN GỐC TỌA ĐỘ
DIEM min_0_0(DIEM A[], int n) {
	DIEM min_Key = A[0];
	float min_Value = kC(A[0]);
	for (int i = 1; i < n; i++) {
		if (kC(A[i]) < min_Value)
		{
			min_Key = A[i];
			min_Value = kC(A[i]);
		}
	}
	return min_Key;
}