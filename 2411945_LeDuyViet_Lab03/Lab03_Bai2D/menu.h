void XuatMenu()
{
    cout << "\n================ MENU ================";
    cout << "\n0. Thoat chuong trinh";
    cout << "\n1. Doc du lieu tu tap tin";
    cout << "\n2. Xem danh sach sinh vien";
    cout << "\n3. Sap tang theo DTB - QuickSort";
    cout << "\n4. Sap tang theo DTB - HeapSort";
    cout << "\n5. Sap tang theo DTB - MergeSort";
    cout << "\n=====================================";
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

void XuLyMenu(int menu, sinhvien a[MAX], int& n)
{
    char filename[50];
    sinhvien b[MAX];

    switch (menu)
    {

    case 1:
        cout << "\nNhap ten tap tin (vd: test.txt): ";
        cin >> filename;
        if (File_Array(filename, a, n))
            cout << "\nDoc du lieu thanh cong!\n";
        else
            cout << "\nLoi mo tap tin!\n";
        break;
    case 2:
        cout << "\nDanh sach sinh vien:\n";
        Output_Arr(a, n);
        break;
    case 3:
        Copy(b, a, n);
        QuickSort(b, n);
        cout << "\nDanh sach sau khi sap tang (QuickSort):\n";
        Output_Arr(b, n);
        break;
    case 4:
        Copy(b, a, n);
        HeapSort(b, n);
        cout << "\nDanh sach sau khi sap tang (HeapSort):\n";
        Output_Arr(b, n);
        break;
    case 5:
        Copy(b, a, n);
        MergeSort(b, n);
        cout << "\nDanh sach sau khi sap tang (MergeSort):\n";
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

void ChayChuongTrinh(sinhvien a[], int n)
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
