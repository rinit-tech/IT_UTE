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
#include <time.h>   //Một số thư viện thường dùng
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
const int MAX = 1000000;
//3. KHAI BÁO BIẾN

//4. KHAI BÁO HÀM ( FUNCTION DECLARATIONS / PROTOTYPES )

void nhanVoiMotSo(char *n, char m, char *&result_nhanVoiMotSo);

void hoanDoi(char *a, char *b);

void tinhTong(char *a, char *b, char *&result_tinhTong);

void nhanAll(char *a, char *b, char *&result_nhanAll);

char *themSoKhong(char *&a, int n);

void giaiThuaMax(int n, char *&result_giaiThuaMax);

void INTsangCHAR(int n, char *&result_INTsangCHAR);

//CHƯƠNG TRÌNH CHÍNH
int main()
{
    //Khai báo biến

    //CHƯƠNG TRÌNH
    do
    {
        //BEGIN
        /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        char *result = new char[MAX];
        int n;
        cin >> n;
        giaiThuaMax(n, result);
        cout << n << "! = " << result << endl;
        cout << " So: " << strlen(result) << endl;
        delete[] result;
        /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        //END
        cout << "Nhap phim ESC de thoat...\n";
    } while (_getch() != 27);
    return 0;
}

void nhanVoiMotSo(char *n, char m, char *&result_nhanVoiMotSo)
{
    int lenN = strlen(n);
    int kResult = 0;
    int du = 0, nhan, nguyen, ip;
    for (int i = lenN - 1; i >= 0; i--)
    {
        nhan = int(n[i] - 48) * int(m - 48);
        nguyen = nhan % 10;
        ip = du + nguyen;
        result_nhanVoiMotSo[kResult++] = ip % 10 + 48;
        du = nhan / 10 + ip / 10;
    }
    if (du != 0)
        result_nhanVoiMotSo[kResult++] = du + 48;
    result_nhanVoiMotSo[kResult] = '\0';
    _strrev(result_nhanVoiMotSo);
}

void hoanDoi(char *a, char *b)
{
    char *tg = new char[MAX];
    if (strlen(b) > strlen(a))
    {
        strcpy(tg, a);
        strcpy(a, b);
        strcpy(b, tg);
    }
    delete[] tg;
    return;
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
}

void nhanAll(char *a, char *b, char *&result_nhanAll)
{
    hoanDoi(a, b);
    int minLen = strlen(b);
    result_nhanAll[0] = '0';
    result_nhanAll[1] = '\0';
    char *result_nhanVoiMotSo = new char[MAX];

    int kB = minLen;
    for (int i = 0; i < minLen; i++)
    {
        char soNhan = b[--kB];
        nhanVoiMotSo(a, soNhan, result_nhanVoiMotSo);
        themSoKhong(result_nhanVoiMotSo, i);
        tinhTong(result_nhanAll, result_nhanVoiMotSo, result_nhanAll);
        _strrev(result_nhanAll);
    }

    delete[] result_nhanVoiMotSo;
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

void giaiThuaMax(int n, char *&result_giaiThuaMax)
{

    char *result_INTsangCHAR = new char[10];
    char *result_ABC = new char[MAX];
    result_ABC[0] = '1';
    result_ABC[1] = '\0';

    for (int i = 1; i <= n; i++)
    {
        INTsangCHAR(i, result_INTsangCHAR);
        nhanAll(result_ABC, result_INTsangCHAR, result_giaiThuaMax);
        //cout << i << "! = " << result_giaiThuaMax << endl;
        strcpy(result_ABC, result_giaiThuaMax);
    }
    delete[] result_ABC;
}

void INTsangCHAR(int n, char *&result_INTsangCHAR)
{
    int kNumr = 0;
    while (n > 0)
    {
        int du = n % 10;
        result_INTsangCHAR[kNumr++] = du + 48;
        n /= 10;
    }
    result_INTsangCHAR[kNumr] = '\0';
    _strrev(result_INTsangCHAR);
}
