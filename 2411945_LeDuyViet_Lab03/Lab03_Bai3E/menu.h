void XuatMenu()
{
    cout << "\n============= MENU SAP XEP NHAN VIEN =============\n";
    cout << "0. Doc du lieu tu tap tin\n";
    cout << "1. Xem danh sach nhan vien\n";
    cout << "2. Selection Sort - Tang dan theo MaNV\n";
    cout << "3. Insertion Sort - Tang dan theo DiaChi\n";
    cout << "4. Radix Sort - Tang dan theo NamSinh\n";
    cout << "==================================================\n";
}



int ChonMenu(int soMenu)
{
    int chon;
    do
    {
        cout << "\nNhap tuy chon [0.." << soMenu << "]: ";
        cin >> chon;
    } while (chon < 0 || chon > soMenu);
    return chon;
}

void XuLyMenu(int menu, NhanVien a[MAX], NhanVien b[MAX], int& n)
{
    char filename[50];

    switch (menu) {
    case 0:
        cout << "\nNhap ten tap tin (vi du: test.txt): ";
        cin >> filename;
        if (File_Array(filename, a, n))
            cout << "\nDoc du lieu thanh cong (" << n << " nhan vien)\n";
        break;

    case 1:
        Output_Arr(a, n);
        break;

    case 2:
        Copy(b, a, n);
        Selection_MaNV(b, n);
        cout << "\nDanh sach sap tang theo MaNV:\n";
        Output_Arr(b, n);
        break;

    case 3:
        Copy(b, a, n);
        Insertion_DiaChi(b, n);
        cout << "\nDanh sach sap tang theo DiaChi:\n";
        Output_Arr(b, n);
        break;

    case 4:
        Copy(b, a, n);
        Radix_NamSinh(b, n);
        cout << "\nDanh sach sap tang theo NamSinh:\n";
        Output_Arr(b, n);
        break;
    default:
        cout << "\nThoat chuong trinh.\n";
        break;
    }

    if (menu > 0)
    {
        cout << "Chon mot phim bat ky de tiep tuc";
        _getch();
    }
}

void ChayChuongTrinh(NhanVien a[], NhanVien b[], int n)
{
    int menu, soMenu = 5;

    do
    {
        system("cls");
        XuatMenu();
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, a, b, n);
    } while (menu != 0);
}
