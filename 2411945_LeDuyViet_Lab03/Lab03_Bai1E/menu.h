void XuatMenu()
{
    cout << "\n================== MENU ==================\n";
    cout << "0. Tao du lieu ngau nhien\n";
    cout << "1. Xem du lieu\n";
    cout << "2. Chon truc tiep (dua GTNN ve dau)\n";
    cout << "3. Chon truc tiep (dua GTLN ve cuoi)\n";
    cout << "4. Chon hai dau (dua GTNN & GTLN)\n";
    cout << "5. Chen truc tiep (vao day con tang ben trai)\n";
    cout << "6. Chen truc tiep (vao day con tang ben phai)\n";
    cout << "7. Chen nhi phan\n";
    cout << "8. Doi cho truc tiep (dua GTNN ve dau)\n";
    cout << "9. Doi cho truc tiep (dua GTLN ve cuoi)\n";
    cout << "10. Noi bot (dua GTNN ve dau)\n";
    cout << "11. Noi bot (dua GTLN ve cuoi)\n";
    cout << "==========================================\n";
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
        TaoDuLieu(a, n);
        break;
    case 1:
        XemDuLieu(a, n);
        break;
    case 2:
        Selection_Min(a, n);
        cout << "\nSau khi sap xep (Chon truc tiep GTNN):\n";
        XemDuLieu(a, n);
        break;
    case 3:
        Selection_Max(a, n);
        cout << "\nSau khi sap xep (Chon truc tiep GTLN):\n";
        XemDuLieu(a, n);
        break;
    case 4:
        Selection_RL(a, n);
        cout << "\nSau khi sap xep (Chon hai dau):\n";
        XemDuLieu(a, n);
        break;
    case 5:
        Insertion_Left(a, n);
        cout << "\nSau khi sap xep (Chen ben trai):\n";
        XemDuLieu(a, n);
        break;
    case 6:
        Insertion_Right(a, n);
        cout << "\nSau khi sap xep (Chen ben phai):\n";
        XemDuLieu(a, n);
        break;
    case 7:
        Binary_Insertion(a, n);
        cout << "\nSau khi sap xep (Chen nhi phan):\n";
        XemDuLieu(a, n);
        break;
    case 8:
        Interchange_Min(a, n);
        cout << "\nSau khi sap xep (Doi cho GTNN):\n";
        XemDuLieu(a, n);
        break;
    case 9:
        Interchange_Max(a, n);
        cout << "\nSau khi sap xep (Doi cho GTLN):\n";
        XemDuLieu(a, n);
        break;
    case 10:
        Bubble_Min(a, n);
        cout << "\nSau khi sap xep (Noi bot GTNN):\n";
        XemDuLieu(a, n);
        break;
    case 11:
        Bubble_Max(a, n);
        cout << "\nSau khi sap xep (Noi bot GTLN):\n";
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
