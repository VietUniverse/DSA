#define MAX 100

struct sinhvien
{
    char maSV[8];
    char hoSV[10];
    char tenLot[10];
    char ten[10];
    char lop[6];
    int namSinh;
    double dtb;
    int tichLuy;
};

// ===== Các hàm chức năng =====

// Đọc file -> Mảng cấu trúc
int TapTin_MangCT(char* filename, sinhvien a[MAX], int& n)
{
    ifstream in(filename);
    if (!in)
        return 0;

    n = 0;
    while (!in.eof())
    {
        in >> a[n].maSV;
        in >> a[n].hoSV;
        in >> a[n].tenLot;
        in >> a[n].ten;
        in >> a[n].lop;
        in >> a[n].namSinh;
        in >> a[n].dtb;
        in >> a[n].tichLuy;
        n++;
    }
    in.close();
    return 1;
}

// Tiêu đề bảng
void TieuDe()
{
    cout << "\n:";
    for (int i = 1; i <= 74; i++) cout << '=';
    cout << ":\n";

    cout << setiosflags(ios::left);
    cout << ':'
        << setw(9) << "Ma SV" << ':'
        << setw(30) << "Ho va Ten sinh vien" << ':'
        << setw(10) << "Lop" << ':'
        << setw(6) << "NS" << ':'
        << setw(6) << "DTB" << ':'
        << setw(8) << "TichLuy" << ':';

    cout << "\n:";
    for (int i = 1; i <= 74; i++) cout << '=';
    cout << ":\n";
}

// Xuất 1 sinh viên
void Xuat_SV(sinhvien p)
{
    cout << ':';
    cout << setiosflags(ios::left)
        << setw(9) << p.maSV << ':'
        << setw(10) << p.hoSV
        << setw(10) << p.tenLot
        << setw(10) << p.ten << ':'
        << setw(10) << p.lop << ':'
        << setw(6) << p.namSinh << ':'
        << setw(6) << setiosflags(ios::fixed) << setprecision(2) << p.dtb << ':'
        << setw(8) << p.tichLuy << ':';
}

// Xuất danh sách
void Xuat_DSSV(sinhvien a[MAX], int n)
{
    TieuDe();
    for (int i = 0; i < n; i++)
    {
        Xuat_SV(a[i]);
        cout << "\n";
    }
    cout << ':';
    for (int i = 1; i <= 74; i++) cout << '=';
    cout << ":\n";
}

// ==== Các hàm tìm kiếm ====

// Tìm theo mã
int Tim_MaSo_DauTien(char maSV[10], sinhvien a[MAX], int n)
{
    int i = 0;
    while ((i < n) && (_stricmp(a[i].maSV, maSV)))
        i++;
    if (i == n)
        return -1;
    return i;
}

// Tìm theo tên
void Tim_TheoTen(char ten[10], sinhvien a[MAX], int n)
{
    int kq = -1;
    for (int i = 0; i < n; i++)
        if (_stricmp(a[i].ten, ten) == 0)
        {
            kq = 1;
            break;
        }
    if (kq == -1)
        cout << "\nKhong co sinh vien ten " << ten;
    else
    {
        cout << "\nCac sinh vien ten " << ten << ":\n";
        TieuDe();
        for (int i = 0; i < n; i++)
            if (_stricmp(a[i].ten, ten) == 0)
            {
                cout << endl;
                Xuat_SV(a[i]);
            }
    }
}

// Tìm theo họ
void Tim_TheoHo(char hoSV[10], sinhvien a[MAX], int n)
{
    int kq = -1;
    for (int i = 0; i < n; i++)
        if (_stricmp(a[i].hoSV, hoSV) == 0)
        {
            kq = 1;
            break;
        }
    if (kq == -1)
        cout << "\nKhong co sinh vien ho " << hoSV;
    else
    {
        cout << "\nCac sinh vien ho " << hoSV << ":\n";
        TieuDe();
        for (int i = 0; i < n; i++)
            if (_stricmp(a[i].hoSV, hoSV) == 0)
            {
                cout << endl;
                Xuat_SV(a[i]);
            }
    }
}

// Tìm theo lớp
void Tim_TheoLop(char lop[6], sinhvien a[MAX], int n)
{
    int kq = -1;
    for (int i = 0; i < n; i++)
        if (_stricmp(a[i].lop, lop) == 0)
        {
            kq = 1;
            break;
        }
    if (kq == -1)
        cout << "\nKhong co lop " << lop;
    else
    {
        cout << "\nCac sinh vien lop " << lop << ":\n";
        TieuDe();
        for (int i = 0; i < n; i++)
            if (_stricmp(a[i].lop, lop) == 0)
            {
                cout << endl;
                Xuat_SV(a[i]);
            }
    }
}

// Tìm theo điểm trung bình >= x
void Tim_TheoDTB(double dtb, sinhvien a[MAX], int n)
{
    int kq = -1;
    for (int i = 0; i < n; i++)
        if (a[i].dtb >= dtb)
        {
            kq = 1;
            break;
        }
    if (kq == -1)
        cout << "\nKhong co sinh vien nao co DTB >= " << dtb;
    else
    {
        cout << "\nCac sinh vien co DTB >= " << dtb << ":\n";
        TieuDe();
        for (int i = 0; i < n; i++)
            if (a[i].dtb >= dtb)
            {
                cout << endl;
                Xuat_SV(a[i]);
            }
    }
}

// ====== Binary Search theo Tích lũy ======
int KiemTraDayTang(int x[MAX], int n)
{
    for (int i = 0; i < n - 1; i++)
        if (x[i] > x[i + 1])
            return 0;
    return 1;
}

int KiemTraDayGiam(int x[MAX], int n)
{
    for (int i = 0; i < n - 1; i++)
        if (x[i] < x[i + 1])
            return 0;
    return 1;
}

int TKNP_Tang(int x[MAX], int n, int tichLuy)
{
    int left = 0, right = n - 1, mid, kq = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (x[mid] == tichLuy) return mid;
        if (tichLuy < x[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return kq;
}

int TKNP_Giam(int x[MAX], int n, int tichLuy)
{
    int left = 0, right = n - 1, mid, kq = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (x[mid] == tichLuy) return mid;
        if (tichLuy < x[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return kq;
}

void Xuat_TKNP_Theo_TichLuy(int tichLuy, sinhvien a[MAX], int n, int kq)
{
    if (kq == -1)
        cout << "\nKhong co sinh vien co tich luy = " << tichLuy;
    else
    {
        cout << "\nSinh vien co tich luy = " << tichLuy << ":\n";
        TieuDe();
        Xuat_SV(a[kq]);
        cout << endl;
    }
}

void TKNP_Theo_TichLuy(sinhvien a[MAX], int n)
{
    int x[MAX];
    for (int i = 0; i < n; i++) x[i] = a[i].tichLuy;

    if (!KiemTraDayTang(x, n) && !KiemTraDayGiam(x, n))
    {
        cout << "\nTruong tich luy khong don dieu => khong the TKNP.";
        return;
    }

    int tichLuy;
    cout << "\nNhap so tich luy can tim: ";
    cin >> tichLuy;

    int kq;
    if (KiemTraDayTang(x, n))
        kq = TKNP_Tang(x, n, tichLuy);
    else
        kq = TKNP_Giam(x, n, tichLuy);

    Xuat_TKNP_Theo_TichLuy(tichLuy, a, n, kq);
}