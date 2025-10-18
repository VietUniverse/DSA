#pragma once
#include "ThuVien.h"

void XuatMenu()
{
    cout << "\n================== HE THONG CHUC NANG ==================";
    cout << "\n0. Thoat chuong trinh";
    cout << "\n1. Tao danh sach nhan vien (doc file)";
    cout << "\n2. Xem danh sach nhan vien";
    cout << "\n3. Tim kiem theo ho, ten";
    cout << "\n4. Tim kiem theo nam sinh";
    cout << "\n5. Tim kiem theo ho, ten va nam sinh < x";
    cout << "\n6. Tim kiem theo ten va dia chi";
    cout << "\n7. Tim kiem theo nam sinh va luong";
    cout << "\n8. Tim kiem nhi phan theo ma nhan vien";
    cout << "\n========================================================";
}

int ChonMenu(int soMenu)
{
    int stt;
    do
    {
        system("CLS");
        XuatMenu();
        cout << "\nNhap lua chon (0.." << soMenu << "): ";
        cin >> stt;
    } while (stt < 0 || stt > soMenu);
    return stt;
}

void XuLyMenu(int menu, NhanVien a[MAX], int& n)
{
    char filename[MAX];
    switch (menu)
    {
    case 1:
        cout << "\nNhap ten tap tin: ";
        cin >> filename;
        if (DocFile(filename, a, n))
        {
            cout << "\nDoc thanh cong. Danh sach:\n";
            Xuat_DSNV(a, n);
        }
        break;
    case 2:
        Xuat_DSNV(a, n);
        break;
    case 3: {
        char ho[11], ten[11];
        cout << "\nNhap ho: "; cin >> ho;
        cout << "Nhap ten: "; cin >> ten;
        Tim_Ho_Ten(ho, ten, a, n);
        break;
    }
    case 4: {
        int nam;
        cout << "\nNhap nam sinh: "; cin >> nam;
        Tim_TheoNamSinh(nam, a, n);
        break;
    }
    case 5: {
        char ho[11], ten[11];
        int x;
        cout << "\nNhap ho: "; cin >> ho;
        cout << "Nhap ten: "; cin >> ten;
        cout << "Nhap gioi han nam sinh x: "; cin >> x;
        Tim_Ho_Ten_NamSinh(ho, ten, x, a, n);
        break;
    }
    case 6: {
        char ten[11], diaChi[16];
        cout << "\nNhap ten: "; cin >> ten;
        cout << "Nhap dia chi: "; cin >> diaChi;
        Tim_Ten_DiaChi(ten, diaChi, a, n);
        break;
    }
    case 7: {
        double x; int y;
        cout << "\nNhap luong >= "; cin >> x;
        cout << "Nhap nam sinh <= "; cin >> y;
        Tim_NamSinh_Luong(y, x, a, n);
        break;
    }
    case 8:
        TimKiemNP(a, n);
        break;
    default:
        cout << endl << "Ket thuc chuong trinh";
        break;
    }
    if (menu > 0)
    {
        cout << endl << "Chon phim bat ky de tiep tuc";
        _getch();
    }
}

void ChayChuongTrinh()
{
    NhanVien a[MAX];
    int n = 0, menu, soMenu = 8;
    do
    {
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, a, n);
        system("PAUSE");
    } while (menu != 0);
}
