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
using namespace std;
//CHƯƠNG TRÌNH CHÍNH
//KHAI BÁO TOÀN CỤC (GLOBALLY) - SỬ DỤNG CHUNG CHO TOÀN BỘ CHƯƠNG TRÌNH\
//1. KHAI BÁO KIỂU DỮ LIỆU ( NEW )
//2. KHAI BÁO HẰNG ( CONST )
const int MAX = 100;
//3. KHAI BÁO BIẾN

//4. KHAI BÁO HÀM ( FUNCTION DECLARATIONS / PROTOTYPES )

//Nhập mảng
void NhapMang(int Mang[], int Phtu)
{
	for (int i = 0; i < Phtu; i++)
	{
		cout << "+ Phan tu so #" << i << " = ";
		cin >> Mang[i];
	}
}
//Xuất mảng
void XuatMang(int Mang[], int Phtu)
{
	cout << "-> Mang cua ban: " << endl;
	for (int i = 0; i < Phtu; i++)
	{
		cout << Mang[i] << "  ";
	}
	cout << endl;
}

// GÍA TRỊ THỨ N CỦA DÃY FIBONACCI
int resultNFib(int n);

// TÍNH TỔNG GIÁ TRỊ CÁC SỐ NGUYÊN CÓ TRONG MỘT CHUỖI KÍ TỰ
int sumChar(char X[]);

//TÌM SỐ NGUYÊN TỐ NHỎ NHẤT TRONG MẢNG
bool SNT(int n);
//
int SNTmin(int a[], int n);

//TÌM UCLN CỦA TẤT CẢ CÁC PHẦN TỬ TRONG MẢNG
int UCLN(int a[], int n);

//TÌM PHẦN TỬ CÓ TẦN SỐ XUẤT HIỆN NHIỀU NHẤT TRONG MẢNG
struct f
{
	int key;
	int value;
};
//CHECK TỒN TẠI
int search(f fm[], int k, int key);

// XUẤT ARR FM MAX
void tanSO_MAX(int a[], int n);

//CHƯƠNG TRÌNH CHÍNH
int main()
{
	//Khai báo biến
	int n;
	int a[MAX];
	char str[MAX];
	//CHƯƠNG TRÌNH
	do
	{
		//BEGIN
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		bool check = true;
		while (check)
		{
			cout << endl;
			cout << "1. Gia tri phan tu thu n cua day Fibonacci\n";
			cout << "2. Tinh tong gia tri cua so nguyen co trong mot chuoi ky tu\n";
			cout << "3. Tim so nguyen to nho nhat trong mang\n";
			cout << "4. Tim UCLN cua tat ca cac phan tu trong mang\n";
			cout << "5. Tim phan tu co tan so xuat hien nhieu nhat trong mot mang\n";
			cout << "Nhan phim bat ki de thoat !!!\n";
			int value;
			cout << ">> ";
			cin >> value;
			switch (value)
			{
			case 1:
				cout << "Nhap n: ";
				cin >> n;
				cout << resultNFib(n) << endl;
				break;
			case 2:
				cout << "Nhap mot chuoi bat ki: ";
				cin.ignore();
				cin.getline(str, 50);
				cout << sumChar(str) << endl;
				break;
			case 3:
				cout << "Nhap n: ";
				cin >> n;
				NhapMang(a, n);
				XuatMang(a, n);
				cout << SNTmin(a, n) << endl;
				break;
			case 4:
				cout << "Nhap n: ";
				cin >> n;
				NhapMang(a, n);
				XuatMang(a, n);
				cout << UCLN(a, n) << endl;
				break;
			case 5:
				cout << "Nhap n: ";
				cin >> n;
				NhapMang(a, n);
				XuatMang(a, n);
				tanSO_MAX(a, n);
				break;
			default:
				check = false;
				break;
			}
		}

		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		//END
		cout << "Nhap phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}

// GÍA TRỊ THỨ N CỦA DÃY FIBONACCI
int resultNFib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return resultNFib(n - 1) + resultNFib(n - 2);
}
//1 1 2 3 5

// TÍNH TỔNG GIÁ TRỊ CÁC SỐ NGUYÊN CÓ TRONG MỘT CHUỖI KÍ TỰ
int sumChar(char X[])
{
	int len = strlen(X);
	int sum = 0;
	int i = 0, k;
	while (i < len)
	{
		if (X[i] >= 48 && X[i] <= 57)
		{
			char value[10] = {};
			k = 0;
			for (; i < len; i++)
			{
				value[k++] = X[i];
				if (X[i + 1] >= 65 && X[i + 1] <= 122)
					break;
			}
			sum += atoi(value);
		}
		i++;
	}
	return sum;
}

//TÌM SỐ NGUYÊN TỐ NHỎ NHẤT TRONG MẢNG
bool SNT(int n)
{
	if (n <= 0)
		return false;
	if (n <= 3)
		return true;
	int i = 2;
	while (i < n && n % i != 0)
		i++;
	if (i <= n - 1)
		return false;
	return true;
}
//
int SNTmin(int a[], int n)
{
	int arrSNT[20];
	int k = 0;
	for (int i = 0; i < n; i++)
		if (SNT(a[i]))
			arrSNT[k++] = a[i];
	int min = arrSNT[0];
	for (int i = 0; i < k; i++)
		if (min > arrSNT[i])
			min = arrSNT[i];
	return min;
}

//TÌM UCLN
int UCLN(int a[], int n)
{
	int min = a[0];
	for (int i = 1; i < n; i++)
	{
		min = min > a[i] ? a[i] : min;
	}
	int k = min;
	int k_arr = 0;
	int arr[50];
	while (k >= 1)
	{
		if (min % k == 0)
			arr[k_arr++] = k;
		k--;
	}
	for (int i = 0; i < k_arr; i++)
	{
		a[n] = arr[i] - 1;
		int j = 0;
		if (arr[i] == 1)
			return 1;
		while (a[j] % arr[i] == 0)
			j++;
		if (j >= n)
			return arr[i];
	}
}

//CHECK TỒN TẠI
int search(f fm[], int k, int key)
{
	int i = 0;
	while (i < k && fm[i].key != key)
		i++;
	if (i < k)
		return i;
	return -1;
}
// XUẤT ARR FM MAX
void tanSO_MAX(int a[], int n)
{
	f fm[50];
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		int result = search(fm, k, a[i]);
		if (result == -1)
		{
			fm[k++].key = a[i];
			fm[--k].value = 1;
			k++;
		}
		else
		{
			fm[result].value++;
		}
	}
	//MAX tần số
	int max = fm[0].value;
	for (int i = 0; i < k; i++)
	{
		max = max < fm[i].value ? fm[i].value : max;
	}
	for (int i = 0; i < k; i++)
		if (fm[i].value == max)
			cout << fm[i].key << " ";
	cout << endl;
}