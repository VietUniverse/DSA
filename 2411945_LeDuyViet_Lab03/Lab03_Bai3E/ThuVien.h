#define MAX 100

struct NhanVien {
    char maNV[8];
    char hoNV[15];
    char tenLot[15];
    char ten[15];
    char diaChi[20];
    int namSinh;
    double luong;
};


int File_Array(char* filename, NhanVien a[MAX], int& n) {
    ifstream in(filename);
    if (!in) {
        cout << "\nKhong mo duoc tap tin!";
        return 0;
    }

    string temp;
    getline(in, temp);
    getline(in, temp);

    n = 0;
    while (!in.eof() && n < MAX) {
        in >> a[n].maNV;
        in >> a[n].hoNV;
        in >> a[n].tenLot;
        in >> a[n].ten;
        in >> a[n].diaChi;
        in >> a[n].namSinh;
        in >> a[n].luong;
        if (in)
            n++;
    }

    in.close();
    return 1;
}

void Heading() {
    cout << left
        << setw(10) << "MaNV"
        << setw(12) << "Ho"
        << setw(12) << "TenLot"
        << setw(12) << "Ten"
        << setw(15) << "DiaChi"
        << setw(8) << "NamSinh"
        << setw(12) << "Luong"
        << endl;
    cout << string(80, '-') << endl;
}

void Output_Struct(NhanVien p) {
    cout << left
        << setw(10) << p.maNV
        << setw(12) << p.hoNV
        << setw(12) << p.tenLot
        << setw(12) << p.ten
        << setw(15) << p.diaChi
        << setw(8) << p.namSinh
        << setw(12) << fixed << setprecision(0) << p.luong
        << endl;
}

void Output_Arr(NhanVien a[MAX], int n) {
    Heading();
    for (int i = 0; i < n; i++)
        Output_Struct(a[i]);
}

void HoanVi(NhanVien& x, NhanVien& y) {
    NhanVien t = x;
    x = y;
    y = t;
}

void Copy(NhanVien b[MAX], NhanVien a[MAX], int n) {
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}

void Selection_MaNV(NhanVien a[MAX], int n) {
    int i, j, cs_min;
    for (i = 0; i < n - 1; i++) {
        cs_min = i;
        for (j = i + 1; j < n; j++)
            if (strcmp(a[j].maNV, a[cs_min].maNV) < 0)
                cs_min = j;
        HoanVi(a[i], a[cs_min]);
    }
}

void Insertion_DiaChi(NhanVien a[MAX], int n) {
    int i, j;
    NhanVien x;
    for (i = 1; i < n; i++) {
        x = a[i];
        j = i - 1;
        while (j >= 0 && strcmp(a[j].diaChi, x.diaChi) > 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}


int getMax(NhanVien a[MAX], int n) {
    int mx = a[0].namSinh;
    for (int i = 1; i < n; i++)
        if (a[i].namSinh > mx)
            mx = a[i].namSinh;
    return mx;
}

void CountSort_NamSinh(NhanVien a[MAX], int n, int exp) {
    NhanVien output[MAX];
    int count[10] = { 0 };

    for (int i = 0; i < n; i++)
        count[(a[i].namSinh / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(a[i].namSinh / exp) % 10] - 1] = a[i];
        count[(a[i].namSinh / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

void Radix_NamSinh(NhanVien a[MAX], int n) {
    int m = getMax(a, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        CountSort_NamSinh(a, n, exp);
}