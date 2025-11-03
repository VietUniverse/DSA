void XuatMenu()
{
    cout << "\n=========== MENU SAP XEP ===========\n";
    cout << "1. Doc du lieu tu tap tin\n";
    cout << "2. Xem du lieu\n";
    cout << "3. Sap xep chon truc tiep\n";
    cout << "4. Sap xep chen truc tiep\n";
    cout << "5. Sap xep doi cho truc tiep\n";
    cout << "6. Bubble sort\n";
    cout << "===================================\n";
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


void XuLyMenu(int menu, int a[MAX], int& n)
{
    char filename[50];
    long soSanh, hoanVi;

    switch (menu)
    {
    case 1:
        cout << "\nNhap ten tap tin (vd: test1.txt): ";
        cin >> filename;
        if (File_Array(filename, a, n))
            cout << "\nDoc du lieu thanh cong (" << n << " phan tu).\n";
        else
            cout << "\nKhong mo duoc file!\n";
        break;

    case 2:
        if (n == 0) {
            cout << "\nChua co du lieu. Hay chon muc 0 truoc.\n";
            break;
        }
        cout << "\n=== Du lieu hien co ===\n";
        XuatMang(a, n);
        break;

    case 3:
        if (n == 0) { cout << "\nChua co du lieu.\n"; break; }
        SelectionSort(a, n, soSanh, hoanVi);
        cout << "\nSau khi sap xep (Selection Sort):\n";
        XuatMang(a, n);
        cout << "So phep so sanh: " << soSanh
            << " | So phep hoan vi: " << hoanVi << endl;
        break;

    case 4:
        if (n == 0) { cout << "\nChua co du lieu.\n"; break; }
        InsertionSort(a, n, soSanh, hoanVi);
        cout << "\nSau khi sap xep (Insertion Sort):\n";
        XuatMang(a, n);
        cout << "So phep so sanh: " << soSanh
            << " | So phep hoan vi: " << hoanVi << endl;
        break;

    case 5:
        if (n == 0) { cout << "\nChua co du lieu.\n"; break; }
        InterchangeSort(a, n, soSanh, hoanVi);
        cout << "\nSau khi sap xep (Interchange Sort):\n";
        XuatMang(a, n);
        cout << "So phep so sanh: " << soSanh
            << " | So phep hoan vi: " << hoanVi << endl;
        break;

    case 6:
        if (n == 0) { cout << "\nChua co du lieu.\n"; break; }
        BubbleSort(a, n, soSanh, hoanVi);
        cout << "\nSau khi sap xep (Bubble Sort):\n";
        XuatMang(a, n);
        cout << "So phep so sanh: " << soSanh
            << " | So phep hoan vi: " << hoanVi << endl;
        break;

    default:
        cout << "\nThoat chuong trinh.\n";
        break;
    }

    if (menu > 0 && menu < 6)
    {
        cout << "\nNhan mot phim bat ky de tiep tuc...";
        _getch();
    }
}


void ChayChuongTrinh(int a[], int n)
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
