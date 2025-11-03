void XuatMenu()
{
    cout << "\n============= MENU SAP XEP NHAN VIEN =============\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "1. Nhap danh sach tu file\n";
    cout << "2. Nhap danh sach thu cong\n";
    cout << "3. Xem danh sach nhan vien\n";
    cout << "4. Quick Sort - Tang dan theo Luong, Ten, Ho, NamSinh\n";
    cout << "5. Heap Sort  - Tang dan theo Luong, Ten, Ho, NamSinh\n";
    cout << "6. Merge Sort - Tang dan theo Luong, Ten, Ho, NamSinh\n";
    cout << "7. Shaker Sort- Tang dan theo Luong, Ten, Ho, NamSinh\n";
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

void XuLyMenu(int menu, NhanVien a[MAX], int& n)
{
    switch (menu)
    {
    case 0:
        cout << "\nThoat chuong trinh.\n";
        break;

    case 1:
        File_Array("test.txt", a, n);
        break;
    case 2:
        NhapDanhSach(a, n);
    

    case 3:
        XuatDanhSach(a, n);
        break;

    case 4:
        QuickSort(a, 0, n - 1);
        cout << "\nDanh sach sau khi sap xep (Quick Sort):\n";
        XuatDanhSach(a, n);
        break;

    case 5:
        HeapSort(a, n);
        cout << "\nDanh sach sau khi sap xep (Heap Sort):\n";
        XuatDanhSach(a, n);
        break;

    case 6:
        MergeSort(a, 0, n - 1);
        cout << "\nDanh sach sau khi sap xep (Merge Sort):\n";
        XuatDanhSach(a, n);
        break;

    case 7:
        ShakerSort(a, n);
        cout << "\nDanh sach sau khi sap xep (Shaker Sort):\n";
        XuatDanhSach(a, n);
        break;

    default:
        cout << "\nKhong co tuy chon nay!\n";
        break;
    }

    if (menu != 0)
    {
        cout << "\nNhan phim bat ky de tiep tuc...";
        _getch();
    }
}

void ChayChuongTrinh(NhanVien a[], int& n)
{
    int menu, soMenu = 5;

    do
    {
        system("cls");
        XuatMenu();
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, a, n);
    } while (menu != 0);
}
