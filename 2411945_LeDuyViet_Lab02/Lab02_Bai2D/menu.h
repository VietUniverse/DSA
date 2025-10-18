
void XuatMenu()
{
    cout << "\n================ He thong chuc nang ===============";
    cout << "\n0. Thoat khoi chuong trinh";
    cout << "\n1. Tao danh sach sinh vien";
    cout << "\n2. Xem danh sach sinh vien";
    cout << "\n3. Tim kiem theo ma sinh vien";
    cout << "\n4. Tim kiem theo ten";
    cout << "\n5. Tim kiem theo ho";
    cout << "\n6. Tim kiem theo DTB >= x";
    cout << "\n7. Tim kiem theo lop";
    cout << "\n8. Tim kiem nhi phan theo tich luy";
}

int ChonMenu(int soMenu)
{
    int stt;
    do
    {
        system("CLS");
        XuatMenu();
        cout << "\nNhap so (0 <= so <= " << soMenu << "): ";
        cin >> stt;
    } while (stt < 0 || stt > soMenu);
    return stt;
}

void XuLyMenu(int menu, sinhvien a[MAX], int& n)
{
    int kq; char filename[MAX];
    switch (menu)
    {

        case 1:
            cout << "\n1. Tao danh sach sinh vien\n";
            do {
                cout << "Nhap ten tap tin: ";
                cin >> filename;
                kq = TapTin_MangCT(filename, a, n);
            } while (!kq);
            cout << "\nDanh sach sinh vien vua nhap:\n";
            Xuat_DSSV(a, n);
            break;
        case 2:
            cout << "\n2. Danh sach hien hanh:\n";
            Xuat_DSSV(a, n);
            break;
        case 3: {
            char ma[10];
            cout << "\nNhap ma sinh vien: "; cin >> ma;
            int pos = Tim_MaSo_DauTien(ma, a, n);
            if (pos == -1) cout << "\nKhong tim thay!";
            else { TieuDe(); Xuat_SV(a[pos]); }
            break;
        }
        case 4: {
            char ten[10];
            cout << "\nNhap ten: "; cin >> ten;
            Tim_TheoTen(ten, a, n);
            break;
        }
        case 5: {
            char ho[10];
            cout << "\nNhap ho: "; cin >> ho;
            Tim_TheoHo(ho, a, n);
            break;
        }
        case 6: {
            double x; cout << "\nNhap DTB >= "; cin >> x;
            Tim_TheoDTB(x, a, n);
            break;
        }
        case 7: {
            char lop[6]; cout << "\nNhap lop: "; cin >> lop;
            Tim_TheoLop(lop, a, n);
            break;
        }
        case 8:
            TKNP_Theo_TichLuy(a, n);
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
    sinhvien a[MAX];
    int n = 0, soMenu = 8, menu;

    do {
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, a, n);
        system("PAUSE");
    } while (menu > 0);
}