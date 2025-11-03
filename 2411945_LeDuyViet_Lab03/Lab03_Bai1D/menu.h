void XuatMenu()
{
    cout << "\n================ MENU ================";
    cout << "\n0. Thoat chuong trinh";
    cout << "\n1. Tao du lieu tu tap tin";
    cout << "\n2. Xem du lieu";
    cout << "\n3. Chon truc tiep (Selection sort)";
    cout << "\n4. Chen truc tiep (Insertion sort)";
    cout << "\n5. Doi cho truc tiep (Interchange sort)";
    cout << "\n6. Noi bot (Bubble sort)";
    cout << "\n7. Chen nhi phan (Binary Insertion sort)";
    cout << "\n8. Radix sort";
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

void XuLyMenu(int menu, int a[MAX], int& n)
{
    char filename[50];
    int b[MAX];

    switch (menu)
    {
    case 1:
        cout << "\nNhap ten tap tin (vd: test1.txt): ";
        cin >> filename;
        if (File_Array(filename, a, n))
            cout << "\nDoc du lieu thanh cong!";
        else
            cout << "\nLoi mo tap tin!";
        break;
    case 2:
        cout << "\nDu lieu hien tai: ";
        Output(a, n);
        break;
    case 3:
        Copy(b, a, n);
        Selection_L(b, n);
        cout << "\nMang sau khi sap tang (Selection sort): ";
        Output(b, n);
        break;
    case 4:
        Copy(b, a, n);
        Insertion_L(b, n);
        cout << "\nMang sau khi sap tang (Insertion sort): ";
        Output(b, n);
        break;
    case 5:
        Copy(b, a, n);
        Interchange_L(b, n);
        cout << "\nMang sau khi sap tang (Interchange sort): ";
        Output(b, n);
        break;
    case 6:
        Copy(b, a, n);
        Buble_L(b, n);
        cout << "\nMang sau khi sap tang (Bubble sort): ";
        Output(b, n);
        break;
    case 7:
        Copy(b, a, n);
        Binary_Insertion(b, n);
        cout << "\nMang sau khi sap tang (Binary Insertion sort): ";
        Output(b, n);
        break;
    case 8:
        Copy(b, a, n);
        Radix(b, n);
        cout << "\nMang sau khi sap tang (Radix sort): ";
        Output(b, n);
        break;
    default:
        cout << "\nThoat chuong trinh.\n";
        break;
    }
    if (menu > 0) {
        cout << endl << "Chon phim bat ky de tiep tuc";
        _getch();
    }
}

void ChayChuongTrinh(int a[], int n)
{
    int menu, soMenu = 8;

    do
    {
        system("cls");
        XuatMenu();
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, a, n);
    } while (menu != 0);
}
