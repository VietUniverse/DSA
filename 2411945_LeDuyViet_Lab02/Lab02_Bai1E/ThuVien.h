#define MAX 100

struct NhanVien
{
    char maNV[8];
    char ho[11];
    char tenLot[11];
    char ten[11];
    char ngaySinh[11];
    char diaChi[16];
    double luong;
};


int DocFile(char* filename, NhanVien a[MAX], int& n)
{
    ifstream in(filename);
    if (!in)
    {
        cout << "\nKhong mo duoc file " << filename;
        return 0;
    }

    n = 0;
    while (!in.eof())
    {
        in >> a[n].maNV;
        in >> a[n].ho;
        in >> a[n].tenLot;
        in >> a[n].ten;
        in >> a[n].ngaySinh;
        in >> a[n].diaChi;
        in >> a[n].luong;
        n++;
    }
    in.close();
    return 1;
}

void XuatTieuDe()
{
    cout << "\n:";
    for (int i = 1; i <= 85; i++) cout << '=';
    cout << ":\n";

    cout << setiosflags(ios::left)
        << ':'
        << setw(9) << "Ma NV" << ':'
        << setw(10) << "Ho"
        << setw(10) << "TenLot"
        << setw(10) << "Ten"
        << setw(12) << "NgaySinh"
        << setw(15) << "DiaChi"
        << setw(10) << "Luong"
        << ":\n";

    cout << ":";
    for (int i = 1; i <= 85; i++) cout << '=';
    cout << ":\n";
}


void Xuat_1NV(NhanVien p)
{
    cout << setiosflags(ios::left)
        << ':'
        << setw(9) << p.maNV << ':'
        << setw(10) << p.ho
        << setw(10) << p.tenLot
        << setw(10) << p.ten
        << setw(12) << p.ngaySinh
        << setw(15) << p.diaChi
        << setw(10) << setprecision(0) << fixed << p.luong
        << ":\n";
}

void Xuat_DSNV(NhanVien a[MAX], int n)
{
    XuatTieuDe();
    for (int i = 0; i < n; i++)
        Xuat_1NV(a[i]);
    cout << ":";
    for (int i = 1; i <= 85; i++) cout << '=';
    cout << ":\n";
}


int LayNam(char ngaySinh[11])
{
    char* p = strrchr(ngaySinh, '/');
    if (p == NULL) return 0;
    return atoi(p + 1);
}


void Tim_Ho_Ten(char ho[11], char ten[11], NhanVien a[MAX], int n)
{
    int kq = 0;
    XuatTieuDe();
    for (int i = 0; i < n; i++)
        if (_stricmp(a[i].ho, ho) == 0 && _stricmp(a[i].ten, ten) == 0)
        {
            Xuat_1NV(a[i]);
            kq = 1;
        }
    if (!kq)
        cout << "\nKhong co nhan vien nao co ho " << ho << " va ten " << ten;
}


void Tim_TheoNamSinh(int nam, NhanVien a[MAX], int n)
{
    int kq = 0;
    XuatTieuDe();
    for (int i = 0; i < n; i++)
        if (LayNam(a[i].ngaySinh) == nam)
        {
            Xuat_1NV(a[i]);
            kq = 1;
        }
    if (!kq)
        cout << "\nKhong co nhan vien nao sinh nam " << nam;
}


void Tim_Ho_Ten_NamSinh(char ho[11], char ten[11], int x, NhanVien a[MAX], int n)
{
    int kq = 0;
    XuatTieuDe();
    for (int i = 0; i < n; i++)
    {
        int nam = LayNam(a[i].ngaySinh);
        if (_stricmp(a[i].ho, ho) == 0 && _stricmp(a[i].ten, ten) == 0 && nam < x)
        {
            Xuat_1NV(a[i]);
            kq = 1;
        }
    }
    if (!kq)
        cout << "\nKhong co nhan vien nao co ho " << ho << ", ten " << ten << " va nam sinh < " << x;
}


void Tim_Ten_DiaChi(char ten[11], char diaChi[16], NhanVien a[MAX], int n)
{
    int kq = 0;
    XuatTieuDe();
    for (int i = 0; i < n; i++)
        if (_stricmp(a[i].ten, ten) == 0 && _stricmp(a[i].diaChi, diaChi) == 0)
        {
            Xuat_1NV(a[i]);
            kq = 1;
        }
    if (!kq)
        cout << "\nKhong co nhan vien nao co ten " << ten << " va dia chi " << diaChi;
}


void Tim_NamSinh_Luong(int y, double x, NhanVien a[MAX], int n)
{
    int kq = 0;
    XuatTieuDe();
    for (int i = 0; i < n; i++)
    {
        int nam = LayNam(a[i].ngaySinh);
        if (a[i].luong >= x && nam <= y)
        {
            Xuat_1NV(a[i]);
            kq = 1;
        }
    }
    if (!kq)
        cout << "\nKhong co nhan vien nao co luong >= " << x << " va nam sinh <= " << y;
}


int KiemTraTang(NhanVien a[MAX], int n)
{
    for (int i = 0; i < n - 1; i++)
        if (strcmp(a[i].maNV, a[i + 1].maNV) > 0)
            return 0;
    return 1;
}

int TKNP_Tang(NhanVien a[MAX], int n, char maNV[8])
{
    int l = 0, r = n - 1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        int ss = strcmp(a[mid].maNV, maNV);
        if (ss == 0) return mid;
        if (ss > 0) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

void TimKiemNP(NhanVien a[MAX], int n)
{
    if (!KiemTraTang(a, n))
    {
        cout << "\nDanh sach khong tang theo ma NV, khong the TKNP!";
        return;
    }
    char ma[8];
    cout << "\nNhap ma nhan vien can tim: ";
    cin >> ma;
    int kq = TKNP_Tang(a, n, ma);
    if (kq == -1)
        cout << "\nKhong co nhan vien ma " << ma;
    else
    {
        cout << "\nNhan vien co ma " << ma << " la:\n";
        XuatTieuDe();
        Xuat_1NV(a[kq]);
    }
}