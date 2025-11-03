void XuatMenu()
{
    cout << "\n================ MENU ================\n";
    cout << "1. Xuat mang\n";
    cout << "2. Selection Sort (dua GTLN ve cuoi)\n";
    cout << "3. Selection 2 dau (dua GTNN & GTLN)\n";
    cout << "4. Insertion Sort (chen truc tiep)\n";
    cout << "5. Interchange Sort (doi cho truc tiep)\n";
    cout << "6. Bubble Sort (noi bot)\n";
    cout << "7. Shaker Sort (noi bot 2 chieu)\n";
    cout << "0. Thoat\n";
    cout << "=====================================\n";
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
        case 1:
            cout << "\nMang hien hanh:\n";
            Output(a, n);
            break;
        case 2:
            Selection_R(a, n);
            cout << "\nSau khi Selection Sort:\n";
            Output(a, n);
            break;
        case 3:
            Selection_R_L(a, n);
            cout << "\nSau khi Selection 2 dau:\n";
            Output(a, n);
            break;
        case 4:
            Insertion_R(a, n);
            cout << "\nSau khi Insertion Sort:\n";
            Output(a, n);
            break;
        case 5:
            Interchange_R(a, n);
            cout << "\nSau khi Interchange Sort:\n";
            Output(a, n);
            break;
        case 6:
            Buble_R(a, n);
            cout << "\nSau khi Bubble Sort:\n";
            Output(a, n);
            break;
        case 7:
            Shaker(a, n);
            cout << "\nSau khi Shaker Sort:\n";
            Output(a, n);
            break;
        default:
            cout << endl << "Thoat chuong trinh";
            break;
    }
    if (menu > 0)
    {
        cout << endl << "Chon phim bat ky de tiep tuc";
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
