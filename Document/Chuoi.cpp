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
//HÀM 1: LẤY CÁC SỐ TRONG CHUỖI
//1.1 Lấy 1 số thập phân trong chuỗi
void chuyenChuoiThanhSo(char str[]);
//2. Chuyển Char Thành INT( chuyển từ dạng chuỗi sang dạng số thực )
float chuyenChrThanhInt(char str[]);
//1.2 Rút gọn chương trình ( xử lí đối với các bài toán xử lí số có trong chuỗi (*))
void rGchuyenChrThanhSo(char strphu[50], char str[50], int &i, int j, int a);
/*-----------------------------------------------------------------------*/
//HÀM 2: LẤY CÁC TỪ RA TỪ CHUỖI
//Kiểu dữ liệu tự định nghĩa
//Chứa từ
struct Word
{
    char Word_S[40];
};

//HÀM XỬ LÍ CÁC TỪ TRONG CHUỖI
//1.Lấy ra từ trong chuỗi
void giveWord(char str[], Word x[], int &stt);
//2. Xử lí các thứ cần xử lí các từ trong chuỗi
void CT(char str[], Word x[], int stt);
//Xử lí một số thứ liên quan đến từ trong chuỗi
// Đếm số lượng ký tự là nguyên âm trong chuỗi (a,e,i,o,u,y,A,E,I,O,U,Y)
int demSoLanNgam(char str[]);
//Xóa
void xoa_S(char str[], int VtriXoa);
//Chuỗi chuẩn
void chuoiChuan(char str[]);
//Tìm chuỗi con trong chuỗi lớn
void demChuoiCon(char str[], char strcon[]);
//Nối chuỗi từ mảng
char *noiChuoi(Word a[], int n);
//Đổi từ trong chuỗi
void doiTuinChuoi(char str[], char tu_S1[], char tu_S2[]);
//CHƯƠNG TRÌNH CHÍNH
int main()
{
    //Khai báo biến
    char str[50];
    char strcon[50];
    char strdoi[50];
    //CHƯƠNG TRÌNH
    do
    {
        //BEGIN
        /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        //Các lệnh của chương trình đặt ở đây
        //1. Nhập chuỗi
        cout << "Nhap mot chuoi bat ki: ";
        cin.getline(str, 50);
        //2. In và xuất chuỗi
        cout << "Chuoi vua nhap      :" << str << endl;
        ////3. Sao chép nội dung chuỗi
        //	strcpy_s(str2, str);		//str2 = str
        //	cout << "Chuoi vua copy     :" << str2 << endl;
        ////4. Nối chuỗi
        //	strcat_s(str2, " xin chao moi nguoi");
        //	cout << "Chuoi vua noi      :" << str2 << endl;
        ////5. Đổi chữ thường thành chữ hoa
        //	_strlwr_s(str2);
        //	cout << "Chuoi chu thuong   :" << str2 << endl;
        //	_strupr_s(str2);
        //	cout << "Chuoi chu hoa    :" << str2 << endl;
        ////6. Tính độ dài chuỗi
        //	int len = strlen(str);
        //	cout << "Chieu dai chuoi da nhap:  " << len << endl;
        ////7. So sánh hai chuỗi
        //	if (strcmp("thanh", "thanh") > 0)cout << "thanh > thang" << endl; //khác 1 kí tự là khác
        //if (_stricmp("An", "An1") == 0)cout << "An = an" << endl;//so sánh hoa thường chấp hết
        ////8. Tìm xem trong chuỗi có chứa kí tự ch nào đó không
        //	if (strchr(str, 'a') == NULL)cout << "Chuoi khong co ki tu a" << endl;
        //	else cout << strchr(str, 'a') << endl;
        ////9. Tìm xem trong chuỗi có một chuỗi còn nào đó hay không
        /*if (strstr(str,"con cho") == NULL)
				cout << "chuoi khong co chu \"con\"" << endl;
			else cout << strstr(str, "con") << endl;*/
        //10. Ngược chuỗi
        //strrev()
        //chuyenChuoiThanhSo(str);
        demChuoiCon(s)
            /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
            //END
            cout
            << "Nhap phim ESC de thoat...\n";
    } while (_getch() != 27);
    return 0;
}

/*-----------------------------------------------------------------------*/
//HÀM 1: LẤY CÁC SỐ TRONG CHUỖI
//1.1 Lấy 1 số thập phân trong chuỗi
void chuyenChuoiThanhSo(char str[])
{
    int len = strlen(str);
    str[len] = 32;
    len++;
    for (int i = 0; i < len - 1; i++)
    {
        char strphu[MAX] = {}; //reset chuỗi
        int a = 0;
        int socham = 0;    //reset socham
        if (str[i] == '-') //Kiểm tra dấu - trước nếu bắt dấu trừ thì sẽ chuyển thành số âm
        {
            for (int j = i; j < len - 1; j++)
            {
                if (str[j + 1] == '-')
                {
                    i = j;
                    break;
                }
                if (str[j] == '.')
                    socham++;
                if (!(str[j + 1] >= 48 && str[j + 1] <= 57) || socham == 2) //Tìm thấy khác số or . thì dừng ( Chưa KT trường hợp có 2 dấu chấm )
                {
                    rGchuyenChrThanhSo(strphu, str, i, j, a);
                    break;
                }
            }
        }
        else if (str[i] == '.')
        {
            for (int j = i; j < len - 1; j++)
                if (!(str[j + 1] >= 48 && str[j + 1] <= 57)) //Tìm thấy khác số thì dừng
                {
                    rGchuyenChrThanhSo(strphu, str, i, j, a);
                    break;
                }
        }
        else if (str[i] >= 48 && str[i] <= 57)
        {
            for (int j = i; j < len - 1; j++)
            {
                if (str[j] == '.')
                    socham++;
                if (!(str[j + 1] >= 48 && str[j + 1] <= 57) || socham == 1) //Tìm thấy khác số or . thì dừng ( Chưa KT trường hợp có 2 dấu chấm )
                {
                    rGchuyenChrThanhSo(strphu, str, i, j, a);
                    break;
                }
            }
        }
    }
}
//2. Chuyển Char Thành INT( chuyển từ dạng chuỗi sang dạng số thực )
float chuyenChrThanhInt(char str[])
{
    int s1 = 0;
    int s2 = 0;
    float s3 = 0;
    int a = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 48 && str[i] <= 57)
            s1 = s1 * 10 + (int(str[i]) - 48);
        else if (str[i] == '.') //Nếu gặp . thì chuyển ra sau chấm (*)
        {
            for (int k = i + 1; k < len; k++)
            {
                s2 = s2 * 10 + (int(str[k]) - 48);
                a++;
            }
            break;
        }
    }
    s3 = float(s1) + float(s2 / pow(10, a)); //(*)(Chia cho 10 mũ a với a là số lượng các số sau chấm)
    if (str[0] == '-')
        return -s3;
    else
        return s3;
    //Có thể dùng thư viện #include <stdlib.h>
}
//1.2 Rút gọn chương trình ( xử lí đối với các bài toán xử lí số có trong chuỗi (*))
void rGchuyenChrThanhSo(char strphu[50], char str[50], int &i, int j, int a)
{
    for (int k = i; k <= j; k++)
    {
        strphu[a] = str[k];
        a++;
    }
    i = j;
    //(*)( Xử lí bài toán )
    float s = chuyenChrThanhInt(strphu);
    if (s == 0)
        ;
    else
        cout << s << " TEST 2.2" << endl;
}
/*-----------------------------------------------------------------------*/
//HÀM 2: LẤY CÁC TỪ RA TỪ CHUỖI
/*//Kiểu dữ liệu tự định nghĩa
//Chứa từ
struct Word
{
	char Word_S[40];
};
Word SOTU[20];*/
//HÀM XỬ LÍ CÁC TỪ TRONG CHUỖI
//1.Lấy ra từ trong chuỗi
void giveWord(char str[], Word x[], int &stt)
{
    stt = 0;
    char *strphu;
    const char *strCHILL = " "; //Cắt tại "space"
    strphu = strtok(str, strCHILL);
    /*
	strphu = strtok(str, " ") cắt chuỗi đầu tiên đến vị trí có dấu cách
	strphu = strtok(NULL, " ") cắt chuỗi ở vị trí tiếp theo tại vị trí mới dừng lại
	*/
    for (strphu; strphu != NULL; strphu = strtok(NULL, strCHILL))
        strcpy(x[stt++].Word_S, strphu); //s++ tăng sau mỗi lần đi qua
}
//2. Xử lí các thứ cần xử lí các từ trong chuỗi
void CT(char str[], Word x[], int stt)
{
    {
        giveWord(str, x, stt);
        for (int i = 0; i < stt; i++)
        {
            cout << "STT[" << i << "]= " << x[i].Word_S << endl;
        }
    }
}
//Xử lí một số thứ liên quan đến từ trong chuỗi
// Đếm số lượng ký tự là nguyên âm trong chuỗi (a,e,i,o,u,y,A,E,I,O,U,Y)
int demSoLanNgam(char str[])
{
    char NguyenAm[] = {"aeiouyAEIOUY"};
    int a = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        for (int j = 0; j < 13; j++)
            if (str[i] == NguyenAm[j])
                a++;
    return a;
}
//Xóa
void xoa_S(char str[], int VtriXoa)
{
    int Phtu = strlen(str);
    for (VtriXoa; VtriXoa < Phtu; VtriXoa++)
        str[VtriXoa] = str[VtriXoa + 1];
    Phtu--;
}
//Chuỗi chuẩn
void chuoiChuan(char str[])
{
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++)
    {
        int cuoi = len - 1;
        if (str[0] == 32)
        {
            xoa_S(str, 0);
            i--;
        }
        else if (str[cuoi] == 32)
        {
            xoa_S(str, cuoi);
            i--;
            cuoi--;
        }
        else if (str[i] == 32 && str[i + 1] == 32)
        {
            xoa_S(str, i + 1);
            i--;
        }
    }
}
//Tìm chuỗi con trong chuỗi lớn
void demChuoiCon(char str[], char strcon[])
{
    int dem = 0;
    Word chuoi[MAX] = {};
    int sttchuoi = 0;
    Word chuoicon[MAX] = {};
    int sttchuoicon = 0;
    giveWord(str, chuoi, sttchuoi);
    giveWord(strcon, chuoicon, sttchuoicon);
    for (int i = 0; i < sttchuoi; i++)
    {
        int check = 0;
        if (_stricmp(chuoicon[0].Word_S, chuoi[i].Word_S) == 0)
            for (int j = 0; j < sttchuoicon; j++)
            {
                if (_stricmp(chuoicon[j].Word_S, chuoi[i].Word_S) != 0)
                {
                    break;
                } //Nếu từ các từ tiếp theo khác với chuỗi con break
                else
                {
                    i++;
                    check++;
                }
            }
        if (check == sttchuoicon)
        {
            dem++; //Nếu số từ trên đúng bằng với chuỗi con thì dem++
            i--;   //sát nhau quay lại (chỉ trường hợp nếu tìm đúng)
        }
    }
    cout << dem << endl;
}
//Nối chuỗi từ mảng(//dùng strcpy để sử dụng)
char *noiChuoi(Word a[], int n)
{
    char mang[MAX];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int len = strlen(a[i].Word_S);
        for (int j = 0; j < len; j++)
            mang[k++] = a[i].Word_S[j];
        mang[k++] = ' ';
    }
    mang[k] = '\0';
    return mang;
}
//Đổi từ trong chuỗi
void doiTuinChuoi(char str[], char tu_S1[], char tu_S2[])
{
    Word chuoi[MAX];
    int phTuChuoiCon = 0;
    giveWord(str, chuoi, phTuChuoiCon);
    for (int i = 0; i < phTuChuoiCon; i++)
    {
        if (_stricmp(tu_S1, chuoi[i].Word_S) == 0)
            strcpy(chuoi[i].Word_S, tu_S2);
    }
    strcpy(str, (noiChuoi(chuoi, phTuChuoiCon)));
}
//Đổi chuỗi con có trong chuỗi
void demChuoiCon(char str[], char strcon[], char strconthaythe[])
{
    int dem = 0;
    Word chuoi[MAX] = {};
    int sttchuoi = 0;
    Word chuoicon[MAX] = {};
    int sttchuoicon = 0;
    Word chuoiconthaythe[MAX] = {};
    int sttchuoiconthaythe = 0;
    giveWord(str, chuoi, sttchuoi);
    giveWord(strcon, chuoicon, sttchuoicon);
    giveWord(strcon, chuoiconthaythe, sttchuoiconthaythe);
    for (int i = 0; i < sttchuoi; i++)
    {
        int check = 0;
        if (_stricmp(chuoicon[0].Word_S, chuoi[i].Word_S) == 0)
            for (int j = 0; j < sttchuoicon; j++)
            {
                if (_stricmp(chuoicon[j].Word_S, chuoi[i].Word_S) != 0)
                {
                    break;
                } //Nếu từ các từ tiếp theo khác với chuỗi con break
                else
                {
                    i++;
                    check++;
                }
            }
        //Check

        //
        if (check == sttchuoicon)
        {
            i -= sttchuoicon;
            for (int j = 0; j < sttchuoicon; j++)
            {
            }
            i--; //sát nhau quay lại (chỉ trường hợp nếu tìm đúng)
        }
    }
    cout << dem << endl;
}
