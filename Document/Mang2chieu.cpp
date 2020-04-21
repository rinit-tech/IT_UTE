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
float Mang2CtamThoi1[MAX][MAX];
int PhtuCotMtamThoi1 = 0, PhtuDongMtamThoi1 = 0;
float Mang2CtamThoi2[MAX][MAX];
int PhtuCotMtamThoi2 = 0, PhtuDongMtamThoi2 = 0;
float Mang2CtamThoi3[MAX][MAX];
int PhtuCotMtamThoi3 = 0, PhtuDongMtamThoi3 = 0;
//4. KHAI BÁO HÀM ( FUNCTION DECLARATIONS / PROTOTYPES )
//1. Nhập giá trị cho ma trận
void NhapMang(float Mang2C[][MAX], int Dong, int Cot);
//2. In nội dung của ma trận ra màn hình
void XuatMang2C(float Mang2C[][MAX], int Dong, int Cot);
//3. Chuyển ma trận 2 thành 1
void Chuyen2Cthanh1C(float Mang2C[][MAX], int Dong, int Cot, int Mang1C[], int &Phtu);
//Xuất mảng
void XuatMang(int Mang[], int Phtu);
//Truy xuất vào Dòng
void TruyXuatDong(float Mang2C[][MAX], int Dong, int Cot, int MangTamThoi1[], int &Phtu, int TruyXuatDong);
//Truy xuất vào Cột
void TruyXuatCot(float Mang2C[][MAX], int Dong, int Cot, int MangTamThoi1[], int &Phtu, int TruyXuatCot);
void TimKiemM2C(float Mang2C[][MAX], int Dong, int Cot, int GtriTimKiem);
void Nhan2MaTran(float Mang2C1[][MAX], int Dong1, int Cot1, float Mang2C2[][MAX], int Dong2, int Cot2);
void ChuyenVi(float Mang2C[][MAX], int Dong, int Cot);
void GiaiMaTran(float Mang2C[][MAX], int Dong, int Cot);
void Swap(float &x, float &y);
void SapXepabc(float Mang2C[][MAX], int Dong, int Cot, int C);
//CHƯƠNG TRÌNH CHÍNH
int main()
{
    //Khai báo biến
    float Mang2C1[MAX][MAX]; //ma trận
    int Dong1, Cot1;         //cấp của ma trận
    float Mang2C2[MAX][MAX]; //ma trận
    int Dong2, Cot2;         //cấp của ma trận
    int i, j, k;             //biến chạy

    //CHƯƠNG TRÌNH
    do
    {
        //BEGIN
        /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        cout << "So dong cua ma tran 1: ";
        cin >> Dong1;
        cout << "So cot cua ma tran 1: ";
        cin >> Cot1;
        NhapMang(Mang2C1, Dong1, Cot1);
        XuatMang2C(Mang2C1, Dong1, Cot1);
        /*cout << "So dong cua ma tran 2: "; cin >> Dong2;
		cout << "So cot cua ma tran 2: "; cin >> Cot2;
		NhapMang(Mang2C2, Dong2, Cot2);
		XuatMang2C(Mang2C2, Dong2, Cot2);*/
        //Chuyen2Cthanh1C(Mang2C, Dong, Cot, MangTamThoi1, PhtuMtamThoi1);
        //XuatMang(MangTamThoi1, PhtuMtamThoi1);
        int TruyXuatCotin;
        cout << "Cot can truy xuat vao: ";
        cin >> TruyXuatCotin;
        TruyXuatCot(Mang2C1, Dong1, Cot1, MangTamThoi1, PhtuMtamThoi1, TruyXuatCotin);
        XuatMang(MangTamThoi1, PhtuMtamThoi1);
        //int x;
        //cout << "Gtri Tim kiem: "; cin >> x;
        //TimKiemM2C(Mang2C, Dong, Cot, x);
        //Nhan2MaTran(Mang2C1, Dong1, Cot1, Mang2C2, Dong2, Cot2);
        //ChuyenVi(Mang2C1, Dong1, Cot1);
        //	GiaiMaTran(Mang2C1, Dong1, Cot1);
        //SapXepabc(Mang2C1, Dong1, Cot1);

        /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        //END
        cout << "Nhap phim ESC de thoat...\n";
    } while (_getch() != 27);
    return 0;
}

//1. Nhập giá trị cho ma trận
void NhapMang(float Mang2C[][MAX], int Dong, int Cot)
{
    for (int i = 0; i < Dong; i++)    //i là chỉ số dòng
        for (int j = 0; j < Cot; j++) //j là chỉ số cột
        {
            cout << "a[" << i << "][" << j << "]=";
            cin >> Mang2C[i][j];
            //a[i][j] = rand() % 99 + 1;
        }
}
//2. In nội dung của ma trận ra màn hình
void XuatMang2C(float Mang2C[][MAX], int Dong, int Cot)
{
    cout << "-> Mang cua ban: " << endl;
    for (int i = 0; i < Dong; i++)
    {
        for (int j = 0; j < Cot; j++)
        {
            cout.width(5); //quy định độ rộng cho mỗi giá trị in ra
            cout << Mang2C[i][j];
        }
        cout << endl; //sang dòng mới
    }
}
//3. Chuyển ma trận 2 thành 1
void Chuyen2Cthanh1C(float Mang2C[][MAX], int Dong, int Cot, int Mang1C[], int &Phtu)
{
    Phtu = 0;
    for (int i = 0; i < Dong; i++)
        for (int j = 0; j < Cot; j++)
        {
            Mang1C[Phtu] = Mang2C[i][j];
            Phtu++;
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
//Truy xuất vào Dòng
void TruyXuatDong(float Mang2C[][MAX], int Dong, int Cot, int MangTamThoi[], int &Phtu, int TruyXuatDong)
{
    Phtu = 0;
    for (int j = 0; j < Cot; j++)
    {
        MangTamThoi[Phtu] = Mang2C[TruyXuatDong][j];
        Phtu++;
    }
}
//Truy xuất vào Cột
void TruyXuatCot(float Mang2C[][MAX], int Dong, int Cot, int MangTamThoi[], int &Phtu, int TruyXuatCot)
{
    Phtu = 0;
    for (int i = 0; i < Dong; i++)
    {
        MangTamThoi[Phtu] = Mang2C[i][TruyXuatCot];
        Phtu++;
    }
} //Chéo chính

void TimKiemM2C(float Mang2C[][MAX], int Dong, int Cot, int GtriTimKiem)
{
    cout << "- Cac gia tri tim kiem: " << endl;
    for (int i = 0; i < Dong; i++)
        for (int j = 0; j < Cot; j++)
            if (Mang2C[i][j] == GtriTimKiem)
                cout << "Vi tri o (dong,cot) = ( " << i << " , " << j << " )" << endl;
}
void Nhan2MaTran(float Mang2C1[][MAX], int Dong1, int Cot1, float Mang2C2[][MAX], int Dong2, int Cot2)
{
    if (Cot1 != Dong2)
        cout << "Khong the nhan 2 ma tran !" << endl;
    else
    {
        for (int i = 0; i < Cot1; i++)
        {

            TruyXuatDong(Mang2C1, Dong1, Cot1, MangTamThoi1, PhtuMtamThoi1, i);
            for (int j = 0; j < Dong2; j++)
            {
                TruyXuatCot(Mang2C2, Dong2, Cot2, MangTamThoi2, PhtuMtamThoi2, j);
                int S = 0;
                for (int k = 0; k < Cot1; k++)
                    S = S + MangTamThoi1[k] * MangTamThoi2[k];
                Mang2CtamThoi1[i][j] = S;
            }
        }
        PhtuDongMtamThoi1 = Dong1;
        PhtuCotMtamThoi1 = Cot2;
        XuatMang2C(Mang2CtamThoi1, PhtuDongMtamThoi1, PhtuCotMtamThoi1);
    }
}
void ChuyenVi(float Mang2C[][MAX], int Dong, int Cot)
{
    int k = 0;
    for (int i = 0; i < Cot; i++)
    {
        TruyXuatDong(Mang2C, Dong, Cot, MangTamThoi1, PhtuMtamThoi1, i);
        for (int j = 0; j < PhtuMtamThoi1; j++)
        {
            Mang2CtamThoi1[j][k] = MangTamThoi1[j];
        }
        k++;
    }
    PhtuDongMtamThoi1 = Cot;
    PhtuCotMtamThoi1 = Dong;
    XuatMang2C(Mang2CtamThoi1, PhtuDongMtamThoi1, PhtuCotMtamThoi1);
}
void GiaiMaTran(float Mang2C[][MAX], int Dong, int Cot)
{
    for (int i = 0; i < Dong - 1; i++)
    {
        SapXepabc(Mang2C, Dong, Cot, i);
        for (int k = i + 1; k < Dong; k++)
        {
            TruyXuatDong(Mang2C, Dong, Cot, MangTamThoi1, PhtuMtamThoi1, i);
            TruyXuatDong(Mang2C, Dong, Cot, MangTamThoi2, PhtuMtamThoi2, k);
            for (int p = i; p < Cot; p++)
            {
                float X = ((float(MangTamThoi1[i]) / (MangTamThoi2[i])) * MangTamThoi2[p]) - MangTamThoi1[p];
                Mang2C[k][p] = X; //roundf(X * 100) / 100;
            }
            XuatMang2C(Mang2C, Dong, Cot);
        }
    }
}
void SapXepabc(float Mang2C[][MAX], int Dong, int Cot, int C)
{
    TruyXuatCot(Mang2C, Dong, Cot, MangTamThoi1, PhtuMtamThoi1, C);
    for (int i = C; i < PhtuMtamThoi1 - 1; i++)
        for (int j = C + 1; j < PhtuMtamThoi1; j++)
            if (MangTamThoi1[i] > MangTamThoi1[j]) //Sửa giảm dân ( < )
                for (int k = 0; k < Dong; k++)
                    Swap(Mang2C[i][k], Mang2C[j][k]);
    //XuatMang2C(Mang2C, Dong, Cot);
}
void Swap(float &x, float &y)
{
    int t = x;
    x = y;
    y = t;
}
