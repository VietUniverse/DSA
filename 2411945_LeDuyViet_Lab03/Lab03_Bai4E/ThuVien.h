#define MAX 100

struct NhanVien {
    string ho;
    string ten;
    int namSinh;
    double luong;
};

void HoanVi(NhanVien& a, NhanVien& b) {
    NhanVien t = a;
    a = b;
    b = t;
}

int SoSanh(const NhanVien& a, const NhanVien& b) {
    if (a.luong < b.luong) return -1;
    if (a.luong > b.luong) return 1;

    if (a.ten < b.ten) return -1;
    if (a.ten > b.ten) return 1;

    if (a.ho < b.ho) return -1;
    if (a.ho > b.ho) return 1;

    if (a.namSinh < b.namSinh) return -1;
    if (a.namSinh > b.namSinh) return 1;

    return 0;
}


int Partition(NhanVien a[MAX], int l, int r) {
    NhanVien pivot = a[(l + r) / 2];
    int i = l, j = r;

    while (i <= j) {
        while (SoSanh(a[i], pivot) < 0) i++;
        while (SoSanh(a[j], pivot) > 0) j--;
        if (i <= j) {
            HoanVi(a[i], a[j]);
            i++; j--;
        }
    }
    return i;
}

void QuickSort(NhanVien a[MAX], int l, int r) {
    if (l < r) {
        int pi = Partition(a, l, r);
        if (l < pi - 1)
            QuickSort(a, l, pi - 1);
        if (pi < r)
            QuickSort(a, pi, r);
    }
}

void NhapDanhSach(NhanVien ds[MAX], int& n) {
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "\nNhan vien thu " << i + 1 << ":\n";
        cout << "Ho: "; getline(cin, ds[i].ho);
        cout << "Ten: "; getline(cin, ds[i].ten);
        cout << "Nam sinh: "; cin >> ds[i].namSinh;
        cout << "Luong: "; cin >> ds[i].luong;
        cin.ignore();
    }
}

void File_Array(const char* filename, NhanVien a[MAX], int& n)
{
    ifstream fin(filename);
    if (!fin) {
        cout << "\nKhong mo duoc tap tin " << filename << endl;
    }

    n = 0;
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string ho, ten, temp;
        int namSinh;
        double luong;

        getline(ss, ho, ',');
        getline(ss, ten, ',');
        getline(ss, temp, ',');
        namSinh = stoi(temp);
        getline(ss, temp, ',');
        luong = stod(temp);

        a[n].ho = ho;
        a[n].ten = ten;
        a[n].namSinh = namSinh;
        a[n].luong = luong;
        n++;
    }

    fin.close();
}


void XuatDanhSach(NhanVien ds[MAX], int n) {
    cout << endl << "================= DANH SACH NHAN VIEN =================" << endl;
    cout << left
        << setw(5) << "STT"
        << setw(25) << "Ho"
        << setw(15) << "Ten"
        << setw(12) << "Nam sinh"
        << setw(15) << "Luong" << endl;

    cout << string(72, '-') << endl;

    cout << fixed << setprecision(0);

    for (int i = 0; i < n; i++) {
        cout << left
            << setw(5) << i + 1
            << setw(25) << ds[i].ho
            << setw(15) << ds[i].ten
            << setw(12) << ds[i].namSinh
            << right << setw(15) << ds[i].luong << endl;
    }

    cout << string(72, '=') << endl;
}



void Shift(NhanVien a[MAX], int l, int r) {
    int i = l;
    int j = 2 * i + 1;
    NhanVien x = a[i];
    while (j <= r) {
        if (j < r && SoSanh(a[j], a[j + 1]) < 0)
            j++;
        if (SoSanh(x, a[j]) >= 0)
            break;
        else {
            a[i] = a[j];
            i = j;
            j = 2 * i + 1;
        }
    }
    a[i] = x;
}

void CreateHeap(NhanVien a[MAX], int n) {
    int l = (n - 1) / 2;
    while (l >= 0) {
        Shift(a, l, n - 1);
        l--;
    }
}

void HeapSort(NhanVien a[MAX], int n) {
    CreateHeap(a, n);
    int r = n - 1;
    while (r > 0) {
        HoanVi(a[0], a[r]);
        r--;
        Shift(a, 0, r);
    }
}


void Merge(NhanVien a[MAX], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    NhanVien* L = new NhanVien[n1];
    NhanVien* R = new NhanVien[n2];

    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (SoSanh(L[i], R[j]) <= 0)
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void MergeSort(NhanVien a[MAX], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);
        Merge(a, l, m, r);
    }
}


void ShakerSort(NhanVien a[MAX], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            if (SoSanh(a[i], a[i + 1]) > 0) {
                HoanVi(a[i], a[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (SoSanh(a[i], a[i + 1]) > 0) {
                HoanVi(a[i], a[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

