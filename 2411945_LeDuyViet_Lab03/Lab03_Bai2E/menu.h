void XuatMenu()
{
    cout << "\n=========== MENU SAP XEP ===========\n";
    cout << "0. Doc du lieu tu tap tin\n";
    cout << "1. Xem du lieu\n";
    cout << "2. Merge Sort\n";
    cout << "3. Heap Sort\n";
    cout << "4. Radix Sort\n";
    cout << "5. Quick Sort\n";
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

   switch (menu)
   {
        case 0:
            cout << "\nNhap ten tap tin (test1.txt hoac test2.txt): ";
            cin >> filename;
            if (File_Array(filename, a, n))
                cout << "\nDoc du lieu thanh cong (" << n << " phan tu).\n";
            break;

        case 1:
            XemDuLieu(a, n);
            break;

        case 2:
            MergeSort(a, 0, n - 1);
            cout << "\nSau khi sap xep (Merge Sort):\n";
            XemDuLieu(a, n);
            break;

        case 3:
            HeapSort(a, n);
            cout << "\nSau khi sap xep (Heap Sort):\n";
            XemDuLieu(a, n);
            break;

        case 4:
            RadixSort(a, n);
            cout << "\nSau khi sap xep (Radix Sort):\n";
            XemDuLieu(a, n);
            break;

        case 5:
            QuickSort(a, 0, n - 1);
            cout << "\nSau khi sap xep (Quick Sort):\n";
            XemDuLieu(a, n);
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
