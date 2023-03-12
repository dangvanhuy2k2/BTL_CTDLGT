#include <iostream>
#include <string>
#include <math.h>
#include <iomanip> // de su dung ham setw
#include <conio.h>
#include <Windows.h>
using namespace std;
void veMenu(int slow);
bool isdidc7 = false;
struct PhanXuong
{
    string maPhanXuong, tenPhanXuong, truongPhanXuong;
    int soNhanVien;
};
typedef struct PhanXuong PhanXuong;

struct Node
{
    // data
    PhanXuong PX;
    // pointer
    Node *pNext;
};
typedef struct Node NODE;
// kiem tra ma phanxuong trung
Node *pRev;
NODE *KtraMaPhanXuong(NODE *pHead, string ma)
{
    NODE *duyet = pHead;
    while (duyet != nullptr)
    {
        if (duyet->PX.maPhanXuong == ma)
        {
            return duyet;
        }
        pRev = duyet;
        duyet = duyet->pNext;
    }
    return nullptr;
}
// ham nhap thong tin 1 phan xuong
void nhapThongTinPhanXuong(NODE *pHead, PhanXuong &a)
{
    Node *check;
    do
    {
        cout << "Nhap ma phan xuong: ";
        getline(cin, a.maPhanXuong);
        check = KtraMaPhanXuong(pHead, a.maPhanXuong);
        if (check != false)
        {
            cout << "Ma bi trung nhap lai\n";
        }
        else if (a.maPhanXuong == "")
            cout << "Khong duoc bo trong!\n";
    } while (check != false || a.maPhanXuong == "");

    do
    {
        cout << "Nhap ten phan xuong: ";
        getline(cin, a.tenPhanXuong);
        if (a.tenPhanXuong == "")
            cout << "Ko dc nhap ten rong!\n";
    } while (a.tenPhanXuong == "");

    do
    {
        cout << "Nhap truong phan xuong: ";
        getline(cin, a.truongPhanXuong);
        if (a.truongPhanXuong == "")
            cout << "Ko dc nhap ten rong!\n";
    } while (a.truongPhanXuong == "");

    do
    {
        cout << "Nhap so nhan vien: ";
        cin >> a.soNhanVien;
        if (a.soNhanVien < 0)
            cout << "Nhap so luong nhan vien sai!";
    } while (a.soNhanVien < 0);
}
// khung xuat
void khung()
{
    cout << '\n';
    cout << "\t" << left << setw(5) << "STT";
    cout << "|\t" << left << setw(20) << "Ma phan xuong";
    cout << "|\t" << left << setw(20) << "Ten phan xuong";
    cout << "|\t" << left << setw(30) << "Ten truong phan xuong";
    cout << "|\t" << left << setw(10) << "So nhan vien";
    cout << '\n';
}

// xuat thong tin phan xuong
void xuatThongtin1PhanXuong(PhanXuong a, int stt)
{
    cout << "\t" << left << setw(5) << stt;
    cout << "|\t" << left << setw(20) << a.maPhanXuong;
    cout << "|\t" << left << setw(20) << a.tenPhanXuong;
    cout << "|\t" << left << setw(30) << a.truongPhanXuong;
    cout << "|\t" << left << setw(10) << a.soNhanVien;
    cout << '\n';
}
// khoi tao node
NODE *KhoiTaoNode(PhanXuong a)
{
    NODE *p = new NODE;
    p->pNext = nullptr;
    if (p == nullptr)
    {
        cout << "Bo may may tinh day!";
        return nullptr;
    }
    p->PX = a;
    return p;
}
// câu 1: Hien thi toan bo danh sách
void xuatDanhSach(Node *pHead)
{
    int stt = 1;
    NODE *duyet = pHead;
    khung();
    while (duyet != nullptr)
    {
        xuatThongtin1PhanXuong(duyet->PX, stt);
        duyet = duyet->pNext;
        ++stt;
    }
}
// câu 2 tim kiem 1 phan xuong tu ma nhap vao tu ban phim
void timKiemPhanXuongTheoMa(Node *pHead)
{
    string ma;
    cout << "Nhap ma phan xuong muon tim kiem: ";
    getline(cin, ma);
    NODE *res = KtraMaPhanXuong(pHead, ma);
    if (res == nullptr)
        cout << "Ma phan xuong ko co trong danh sach.";
    else
    {
        cout << "\n\n\t\t\t\t\tThong tin phan xuong can tim.\n\n\n";
        khung();
        xuatThongtin1PhanXuong(res->PX, 1);
    }
}
// câu 3: them 1 phan xuong vao danh sach ma ko duoc trung
void ThemVaoCuoiDanhSach(Node *&pHead, NODE *p)
{
    if (pHead == nullptr)
    {
        pHead = p;
    }
    else
    {
        NODE *duyet = pHead;
        if (isdidc7 == true)
        {
            while (duyet != nullptr && (duyet->PX.soNhanVien < p->PX.soNhanVien))
            {
                pRev = duyet;
                duyet = duyet->pNext;
            }
            if (duyet == pHead)
            {
                p->pNext = pHead;
                pHead = p;
                return;
            }
            pRev->pNext = p;
            p->pNext = duyet;
        }
        else
        {
            while (duyet->pNext != nullptr)
            {
                duyet = duyet->pNext;
            }
            duyet->pNext = p;
        }
    }
}
void cau3(Node *&pHead)
{
    PhanXuong a;
    nhapThongTinPhanXuong(pHead, a);
    NODE *p = KhoiTaoNode(a);
    ThemVaoCuoiDanhSach(pHead, p);
    cout << "Them vao danh sach thanh cong!";
}

// câu 4: xoa 1 phan xuong voi ma nhap vao tu ban phim
void Xoa1PhanXuong(Node *&pHead, NODE *current)
{
    NODE *themang = current;
    if (pHead == current)
    {
        pHead = pHead->pNext;
    }
    else
    {
        pRev->pNext = current->pNext;
    }
    delete themang;
}
void cau4(Node *&pHead)
{
    string ma;
    cout << "Nhap ma phan xuong muon xoa: ";
    getline(cin, ma);
    NODE *res = KtraMaPhanXuong(pHead, ma);
    if (res == nullptr)
        cout << "Ma phan xuong ko co trong danh sach.";
    else
    {
        Xoa1PhanXuong(pHead, res);
        cout << "Xoa thanh cong!\n";
    }
}
// câu 5: Hien thi toan bo phan xuong co so nhan vien < (so nhan vien nhap tu ban phim)
void HienThiPhanXuongDuaVaoSoNhanVien(NODE *pHead, int soNhanVien, bool &check)
{
    cout << "\n\n\t\t\t\tThong tin cac phan xuong co so nhan vien > " << soNhanVien << "\n\n\n";
    int stt = 1;
    khung();
    NODE *duyet = pHead;
    while (duyet != nullptr)
    {
        if (duyet->PX.soNhanVien > soNhanVien)
        {
            xuatThongtin1PhanXuong(duyet->PX, stt);
            check = true;
            ++stt;
        }
        duyet = duyet->pNext;
    }
}
void cau5(Node *pHead)
{
    int soNhanVien;
    do
    {
        cout << "Nhap so nhan vien: ";
        cin >> soNhanVien;
        if (soNhanVien < 0)
            cout << "Nhap so nhan vien >= 0!\nNhap lai!\n";
    } while (soNhanVien < 0);
    bool check = false;
    HienThiPhanXuongDuaVaoSoNhanVien(pHead, soNhanVien, check);
    if (check == false)
    {
        veMenu(0);
        cout << "\n\nTrong danh sach ko co phan xuong nao co so nhan vien > " << soNhanVien << ".\n";
    }
}
// cau 6: dem so phan xuong co so nhan vien < 10
int soLuongc6 = 10;
int Count(NODE *pHead)
{
    int cnt = 0;
    NODE *duyet = pHead;
    while (duyet != nullptr)
    {
        if (duyet->PX.soNhanVien < soLuongc6)
            ++cnt;
        duyet = duyet->pNext;
    }
    return cnt;
}
// cau 7: sap xep danh sach tang dan theo so nhan vien
void HoanDoi2PhanXuong(PhanXuong &a, PhanXuong &b)
{
    PhanXuong temp = a;
    a = b;
    b = temp;
}
void SapXepDanhSach(Node *&pHead)
{
    for (NODE *k = pHead; k->pNext != nullptr; k = k->pNext)
    {
        for (NODE *h = k->pNext; h != nullptr; h = h->pNext)
        {
            if (k->PX.soNhanVien > h->PX.soNhanVien)
            {
                swap(k->PX, h->PX);
            }
        }
    }
}
void cau7(Node *&pHead)
{
    cout << "Danh sach da duoc sap xep tang danh theo so nhan vien bam 1 de xem danh sach.\n";
    if (isdidc7 == false)
    {
        SapXepDanhSach(pHead);
        isdidc7 = true;
    }
}
// cau 9: tim danh sach phan xuong co so nhan vien <= 15
int soLuongc9 = 15;
void HienThiDanhSachPhanXuongC9(Node *pHead, bool &check)
{
    cout << "\n\n\t\t\t\tDanh sach phan xuong co so nhan vien >= " << soLuongc9 << ".\n\n\n";
    khung();
    int stt = 1;
    for (NODE *duyet = pHead; duyet != nullptr; duyet = duyet->pNext)
    {
        if (duyet->PX.soNhanVien >= soLuongc9)
        {
            xuatThongtin1PhanXuong(duyet->PX, stt);
            ++stt;
            check = true;
        }
    }
}
void cau9(Node *&pHead)
{
    bool check = false;
    HienThiDanhSachPhanXuongC9(pHead, check);
    if (check == false)
    {
        veMenu(0);
        cout << "\n\nTrong danh sach ko co phan xuong nao co so nhan vien > " << soLuongc9 << '\n';
    }
}
// câu 10 huy toan bo danh sach
void HuyDanhSach(Node *&pHead)
{
    NODE *themang;
    while (pHead != nullptr)
    {
        themang = pHead;
        pHead = pHead->pNext;
        delete themang;
    }
}
// ham ve Menu
void veMenu(int slow)
{
    system("cls");
    Sleep(slow);
    cout << "\n\n\n\n\t\t\t|-------------------------------Menu-------------------------------|\n";
    Sleep(slow);
    cout << "\t\t\t|   [+]1.Hien thi danh sach.                                       |\n";
    Sleep(slow);
    cout << "\t\t\t|   [+]2.Tim phan xuong theo ma.                                   |\n";
    Sleep(slow);
    cout << "\t\t\t|   [+]3.Them phan xuong vao cuoi danh sach.                       |\n";
    Sleep(slow);
    cout << "\t\t\t|   [+]4.Xoa phan xuong.                                           |\n";
    Sleep(slow);
    cout << "\t\t\t|   [+]5.Xem thong tin phan xuong dua vao so nhan vien.            |\n";
    Sleep(slow);
    cout << "\t\t\t|   [+]6.Dem so luong phan xuong co so nhan vien < " << soLuongc6 << ".             |\n";
    Sleep(slow);
    cout << "\t\t\t|   [+]7.Sap xep danh sach nhan vien tang dan theo so nhan vien.   |\n";
    Sleep(slow);
    cout << "\t\t\t|   [+]8.Hien thi danh sach cac phan xuong co so nhan vien >= " << soLuongc9 << ".  |\n";
    Sleep(slow);
    cout << "\t\t\t|   [+]9.Huy toan bo danh sach.                                    |\n";
    Sleep(slow);
    cout << "\t\t\t|   [+]10.Thoat MENU.                                              |\n";
    Sleep(slow);
    cout << "\t\t\t|-------------------------------End--------------------------------|\n";
    Sleep(slow);
}
// Menu chay chuong trinh
void Menu(Node *&pHead)
{
    int luachon;
    while (1)
    {
        veMenu(20);
        Sleep(20);
        cout << "\n\nNhap lua chon: ";
        cin >> luachon;
        cin.ignore();
        if (luachon < 1 || luachon > 10)
        {
            cout << "Nhap sai lua chon!\nNhap lai!\n";
            system("pause");
        }
        else if (luachon == 10)
        {
            cout << "Tam biet!.";
            break;
        }
        else if (luachon == 3)
        {
            cau3(pHead);
        }
        else
        {
            if (pHead == nullptr)
                cout << "Danh sach dang rong them thong tin de su dung chuc nang nay!\n";
            else
            {
                if (luachon == 1)
                {
                    cout << "\n\n\t\t\t\t\tThong tin danh sach phan xuong\n\n\n";
                    xuatDanhSach(pHead);
                }
                else if (luachon == 2)
                {
                    timKiemPhanXuongTheoMa(pHead);
                }
                else if (luachon == 4)
                {
                    cau4(pHead);
                }
                else if (luachon == 5)
                {
                    cau5(pHead);
                }
                else if (luachon == 6)
                {
                    cout << "So phan xuong co so nhan vien < 10 la: " << Count(pHead) << '\n';
                }
                else if (luachon == 7)
                {
                    cau7(pHead);
                }
                else if (luachon == 8)
                {
                    cau9(pHead);
                }
                else if (luachon == 9)
                {
                    HuyDanhSach(pHead);
                    cout << "Huy toan bo danh sach thanh cong!";
                }
            }
            system("pause");
        }
    }
}
int main()
{
    NODE *pHead = nullptr;
    Menu(pHead);
    HuyDanhSach(pHead);
    getch();
    return 0;
}