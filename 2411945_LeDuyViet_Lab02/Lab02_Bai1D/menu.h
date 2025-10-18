#define MAX 100

void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, int a[MAX], int& n);
void ChayChuongTrinh()



void XuatMenu()
{
    cout << "\n================ He thong chuc nang ===============";
    cout << "\n0. Thoat khoi chuong trinh";
    cout << "\n1. Tao du lieu tu tap tin";
    cout << "\n2. Xem du lieu";
    cout << "\n3. Tim kiem tuyen tinh - Chi so dau tien";
    cout << "\n4. Tim kiem tuyen tinh (co linh canh) - Chi so dau tien";
    cout << "\n5. Tim kiem tuyen tinh - Chi so cuoi cung";
    cout << "\n6. Tra ve tat ca chi so neu co";
    cout << "\n===================================================";
}

int ChonMenu(int soMenu)
{
    int stt;
    do
    {
        system("cls");
        XuatMenu();
        cout << "\nNhap 1 so (0 <= so <= " << soMenu << "): ";
        cin >> stt;
    } while (stt < 0 || stt > soMenu);
    return stt;
}

void XuLyMenu(int menu, int a[MAX], int& n)
{
    int kq, x;
    char filename[MAX];

    switch (menu)
    {

    case 1:
        system("cls");
        cout << "\n1. Tao du lieu tu tap tin";
        do
        {
            cout << "\nNhap ten tap tin (vd: test1.txt): ";
            cin >> filename;
            kq = TapTin_mang1c(filename, a, n);
            if (!kq) cout << "\nLoi! Khong mo duoc tap tin. Thu lai.\n";
        } while (!kq);
        cout << "\nMang vua tao:\n";
        Xuat_Mang(a, n);
        break;

    case 2:
        system("cls");
        cout << "\n2. Xem du lieu:\n";
        Xuat_Mang(a, n);
        break;

    case 3:
        system("cls");
        cout << "\n3. Tim kiem tuyen tinh - Tra ve chi so dau tien\n";
        Xuat_Mang(a, n);
        cout << "\nNhap x = ";
        cin >> x;
        kq = TKTT_DauTien(a, n, x);
        if (kq == -1)
            cout << x << " khong co trong mang.";
        else
            cout << x << " xuat hien lan dau tien tai vi tri: " << kq;
        break;

    case 4:
        system("cls");
        cout << "\n4. Tim kiem tuyen tinh (co linh canh) - Chi so dau tien\n";
        Xuat_Mang(a, n);
        cout << "\nNhap x = ";
        cin >> x;
        kq = TKTT_DauTien_LC(a, n, x);
        if (kq == -1)
            cout << x << " khong co trong mang.";
        else
            cout << x << " xuat hien lan dau tien tai vi tri: " << kq;
        break;

    case 5:
        system("cls");
        cout << "\n5. Tim kiem tuyen tinh - Chi so cuoi cung\n";
        Xuat_Mang(a, n);
        cout << "\nNhap x = ";
        cin >> x;
        kq = TKTT_CuoiCung(a, n, x);
        if (kq == -1)
            cout << x << " khong co trong mang.";
        else
            cout << x << " xuat hien lan cuoi tai vi tri: " << kq;
        break;

    case 6:
        system("cls");
        cout << "\n6. Tra ve tat ca chi so neu co\n";
        Xuat_Mang(a, n);
        cout << "\nNhap x = ";
        cin >> x;
        TKTT_CacChiSo(a, n, x);
        break;
    default:
        cout << endl << "Thoat khoi chuong trinh";
        break;
    }
    if (menu > 0)
    {
        cout << endl << "Nhan mot phim bat ky de tiep tuc";
        _getch();
    }

}

void ChayChuongTrinh()
{
    int soMenu = 6, menu;
    int a[MAX], n = 0;
    do
    {
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, a, n);
        if (menu > 0)
        {
            cout << endl << "Nhan phim bat ky de tiep tuc...";
        }
    } while (menu > 0);
}