/*
Công dụng:		Thư Viện
Tác giả:		Phạm Minh Phát
MSSV:			19110260
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
//4. KHAI BÁO HÀM ( FUNCTION DECLARATIONS / PROTOTYPES )

//Thao tác mảng 1 chiều
void NhapMang(int Mang[], int Phtu);
//Xuất mảng
void XuatMang(int Mang[], int Phtu);
//Tìm Kiếm
bool TimKiem(int x, int y);
//Chú thích :
//- NewMang[] = mảng mới cần tạo để lưu các vị trí
//- m luôn khai báo = 0
//- x là giá trị cần tìm kiếm
void LuuMTimKiem(int Mang[], int Phtu, int MangMoi[], int &PhtuMangMoi, int GtriTimKiem);
//Xóa
//Xóa 1 phần tử bất kì
void Xoa(int Mang[], int &Phtu, int VtriXoa);
//Xóa các phần tử theo vị trí trong mảng
void XoaTheoVtri(int MangCanXoa[], int &PhtuMxoa, int MangVtri[], int PhtuMvtri);
//Lọc mảng ( Loại bỏ các Phtu giống nhau trong mảng )
void CoppyMang(int Mang[], int PhtuMang, int MangSaoChep[], int &PhtuMsaoChep);
void LocMang(int MangLoc[], int &PhtuMloc);
//Sắp xếp
void Swap(int &x, int &y);
void SapXepMang(int Mang[], int Phtu);
//Thêm
void Them(int Mang[], int &Phtu, int VtriThem, int GtriThem);
//Chèn
void Chen(int Mang[], int &Phtu, int VtriChen, int GtriChen);
//Số Chẵn
bool Chan(int x);
//Số Lẻ
bool Le(int x);
//Ước Số
void UocSo(int x, int Mang[], int &Phtu);
//Số Nguyên Tố
bool SoNgto(int x);
//Số Chính Phương
bool ChinhPhuong(int x);
//Số Hoàn Thiện
bool SoHoanThien(int x);
//Ước Chung Lớn Nhất
int UocSoChungLN(int x, int y);
//Bội Chung Nhỏ Nhất
int BoiSoChungNN(int x, int y);
//Kiểm Tra UCLN
int KiemTralonnhat(int x, int y);
//
void LuuMNgtoCungNhau(int Mang[], int Phtu, int MangNgToCungNhau[], int &PhtuMangNgToCungNhau, int GtriTimNgToCungNhau);
//
void ChuongTrinh(int Mang[], int &Phtu, int MangNgToCungNhau[], int &PhtuMangNgToCungNhau, int GtriTimNgToCungNhau);
//Đếm Số lần xuất hiện
void DemSoLanXuatHien(int Mang[], int PhtuMang);
//
void CTdemSoLanXuatHien(int Mang[], int Phtu);
//
//Tìm số lớn nhất và vị trí của nó trong mảng
int TimSoLNvaVtritrongM(int Mang[], int Phtu, int &Max, int &Vtri);
//Tìm số nhỏ nhất và vị trí của nó trong mảng
int TimSoNNvaVtritrongM(int Mang[], int Phtu, int &Min, int &Vtri);

//CHƯƠNG TRÌNH CHÍNH
int main()
{
    //Khai báo biến
    int Mang[MAX], Phtu;
    int MangMoi[MAX], PhtuMangMoi = NULL;
    //CHƯƠNG TRÌNH
    do
    {
        //BEGIN
        /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        //cout << "- So phan tu cua mang: "; cin >> Phtu;
        //NhapMang(Mang, Phtu);
        //XuatMang(Mang, Phtu);
        //int x;
        //cout << "- Gia tri can tim kiem o cac vi tri: "; cin >> x;
        //LuuMTimKiem(Mang, Phtu, MangMoi, PhtuMangMoi, x);
        //XuatMang(MangMoi, PhtuMangMoi);
        //XoaTheoVtri(Mang, Phtu, MangMoi, PhtuMangMoi);
        //XuatMangm(Mang, Phtu);
        /*CoppyMang(Mang, Phtu, MangMoi, PhtuMangMoi);
		XuatMang(MangMoi, PhtuMangMoi);
		LocMang(Mang, Phtu, MangMoi, PhtuMangMoi);
		XuatMang(MangMoi, PhtuMangMoi);
		*/
        /*SapXepMang(Mang, Phtu);
		XuatMang(Mang, Phtu);
		int VtriThem;
		int GtriThem;
		cout << "VtriThem: "; cin >> VtriThem;
		cout << "GtriThem: "; cin >> GtriThem;
		Them(Mang, Phtu, VtriThem, GtriThem);
		XuatMang(Mang, Phtu);*/
        //UocSo(10,MangTamThoi,PhtuMtamThoi);
        //XuatMang(MangTamThoi, PhtuMtamThoi);
        //DemSoLanXuatHien(Mang, Phtu);
        //DemSoLanXuatHien(Mang, Phtu);
        //XuatMang(MangTamThoi1, PhtuMtamThoi1);
        //XuatMang(MangTamThoi2, PhtuMtamThoi2);
        //CTdemSoLanXuatHien(Mang, Phtu);
        //cout << BoiSoChungNN(2, 6) << endl;
        //int Max1, Vtri;
        //TimSoLNvaVtritrongM(Mang, Phtu, Max1,Vtri);
        //cout << "So lon nhat la " << Max1 << " tai vi tri " << Vtri << endl;
        //cout << SoHoanThien(6) << endl;

        /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        //END
        cout << "Nhap phim ESC de thoat...\n";
    } while (_getch() != 27);
    return 0;
}
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
//Bài để phát triển
//Tìm Kiếm
bool TimKiem(int x, int y)
{
    return x == y;
}
//Chú thích :
//- NewMang[] = mảng mới cần tạo để lưu các vị trí
//- m luôn khai báo = 0
//- x là giá trị cần tìm kiếm
void LuuMTimKiem(int Mang[], int Phtu, int MangMoi[], int &PhtuMangMoi, int GtriTimKiem)
{
    PhtuMangMoi = 0;
    for (int i = 0; i < Phtu; i++)
        if (TimKiem(Mang[i], GtriTimKiem) == true)
        {
            MangMoi[PhtuMangMoi] = i;
            PhtuMangMoi++;
        }
}
//Xóa
//Xóa 1 phần tử bất kì
void Xoa(int Mang[], int &Phtu, int VtriXoa)
{
    for (VtriXoa; VtriXoa < Phtu; VtriXoa++)
        Mang[VtriXoa] = Mang[VtriXoa + 1];
    Phtu--;
}
//Xóa các phần tử theo vị trí trong mảng
void XoaTheoVtri(int MangCanXoa[], int &PhtuMxoa, int MangVtri[], int PhtuMvtri)
{
    for (int i = 0; i < PhtuMvtri; i++)
    {
        int k = MangVtri[i];
        for (k; k < PhtuMxoa; k++)
            MangCanXoa[k] = MangCanXoa[k + 1];
        PhtuMxoa--;
        for (int h = i; h < PhtuMvtri; h++)
        {
            MangVtri[h] = MangVtri[h] - 1;
        }
    }
}
//Lọc mảng ( Loại bỏ các Phtu giống nhau trong mảng )
void CoppyMang(int Mang[], int PhtuMang, int MangSaoChep[], int &PhtuMsaoChep)
{
    for (int i = 0; i < PhtuMang; i++)
        MangSaoChep[i] = Mang[i];
    PhtuMsaoChep = PhtuMang;
}
void LocMang(int MangLoc[], int &PhtuMloc)
{
    for (int i = 0; i < PhtuMloc - 1; i++)
        for (int j = i + 1; j < PhtuMloc; j++)
            if (MangLoc[i] == MangLoc[j])
            {
                Xoa(MangLoc, PhtuMloc, j);
                j--; //Quay lại xét
            }
}
//Sắp xếp
void Swap(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}
//Tăng dần
void SapXepMang(int Mang[], int Phtu)
{
    for (int i = 0; i < Phtu - 1; i++)
        for (int j = i; j < Phtu; j++)
            if (Mang[i] > Mang[j]) //Sửa giảm dân ( < )
                Swap(Mang[i], Mang[j]);
}
//Thêm
void Them(int Mang[], int &Phtu, int VtriThem, int GtriThem)
{
    for (int i = Phtu; i >= VtriThem; i--) //#..
        Mang[i] = Mang[i - 1];
    Mang[VtriThem] = GtriThem; //Sửa VtriThem - 1 nếu tính #0 là vị trí thứ nhất
    Phtu++;
}
//Chèn
void Chen(int Mang[], int &Phtu, int VtriChen, int GtriChen)
{
    Mang[VtriChen] = GtriChen;
}
//Số Chẵn
bool Chan(int x)
{
    return x % 2 == 0;
}
//Số Lẻ
bool Le(int x)
{
    return x % 2 != 0;
}
//Ước Số
void UocSo(int x, int Mang[], int &Phtu)
{
    Phtu = 0;
    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0)
        {
            Mang[Phtu] = i;
            Phtu++;
        }
    }
}
//Số Nguyên Tố
bool SoNgto(int x)
{
    if (x < 2)
        return 0;
    double t = sqrt(x);
    for (int i = 2; i <= t; i++)
        if (x % i == 0)
            return 0; //vi phạm
    return 1;         //ko vi phạm
}
//Số Chính Phương
bool ChinhPhuong(int x)
{
    double can = sqrt(x);  //tính căn bậc 2
    int nguyen = (int)can; //tìm phần nguyên
    if (nguyen == can)
        return 1;
    else
        return 0;
}
//Số Hoàn Thiện(số hoàn hảo)
bool SoHoanThien(int x)
{
    int s = 0;
    for (int i = 1; i < x; i++)
    {
        if (x % i == 0)
            s = s + i;
    }
    return s == x;
}
//Ước Số chung lớn nhất
int UocSoChungLN(int x, int y)
{
    for (int i = x - 1; i > 0; i--)
        if (x % i == 0 && y % i == 0)
            return i;
}
//Bội chung nhỏ nhất
int BoiSoChungNN(int x, int y)
{
    return (x * y) / UocSoChungLN(x, y);
}
//
int KiemTralonnhat(int x, int y)
{
    if (UocSoChungLN(x, y) == 1)
        return 1;
    else
        return 0;
}
//
void LuuMNgtoCungNhau(int Mang[], int Phtu, int MangNgToCungNhau[], int &PhtuMangNgToCungNhau, int GtriTimNgToCungNhau)
{
    PhtuMangNgToCungNhau = 0;
    for (int i = 0; i < Phtu; i++)
        if (KiemTralonnhat(GtriTimNgToCungNhau, Mang[i]) == true)
        {
            MangNgToCungNhau[PhtuMangNgToCungNhau] = i;
            PhtuMangNgToCungNhau++;
        }
}
void ChuongTrinh(int Mang[], int &Phtu, int MangNgToCungNhau[], int &PhtuMangNgToCungNhau, int GtriTimNgToCungNhau)
{
    LuuMNgtoCungNhau(Mang, Phtu, MangNgToCungNhau, PhtuMangNgToCungNhau, GtriTimNgToCungNhau);
    XoaTheoVtri(Mang, Phtu, MangTamThoi1, PhtuMtamThoi1);
}
//Đếm số lần xuất hiện
void DemSoLanXuatHien(int Mang[], int PhtuMang)
{
    CoppyMang(Mang, PhtuMang, MangTamThoi1, PhtuMtamThoi1);
    LocMang(MangTamThoi1, PhtuMtamThoi1);
    SapXepMang(MangTamThoi1, PhtuMtamThoi1);
    for (int i = 0; i < PhtuMtamThoi1; i++)
    {
        int dem = 0;
        for (int j = 0; j < PhtuMang; j++)
            if (MangTamThoi1[i] == Mang[j])
                dem++;
        MangTamThoi2[PhtuMtamThoi2] = dem;
        PhtuMtamThoi2++;
    }
}
//Chương trình đếm số lần xuất hiện
void CTdemSoLanXuatHien(int Mang[], int Phtu)
{
    DemSoLanXuatHien(Mang, Phtu);
    for (int i = 0; i < PhtuMtamThoi1; i++)
        cout << "- So lan xuat hien cua so " << MangTamThoi1[i] << " la: " << MangTamThoi2[i] << endl;
}
//Tìm số lớn nhất và vị trí của nó trong mảng
int TimSoLNvaVtritrongM(int Mang[], int Phtu, int &Max, int &Vtri)
{
    Max = Mang[0];
    Vtri = 0;
    for (int i = 1; i < Phtu; i++)
    {
        if (Max < Mang[i])
        {
            Max = Mang[i];
            Vtri = i;
        }
    }
    return Max, Vtri;
}
//Tìm số nhỏ nhất và vị trí của nó trong mảng
int TimSoNNvaVtritrongM(int Mang[], int Phtu, int &Min, int &Vtri)
{
    Min = Mang[0];
    Vtri = 0;
    for (int i = 1; i < Phtu; i++)
    {
        if (Min < Mang[i])
        {
            Min = Mang[i];
            Vtri = i;
        }
    }
    return Min, Vtri;
}
