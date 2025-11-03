#include <fstream>


#define MAX 100

struct sinhvien
{
    char maSV[8];
    char hoSV[15];
    char tenLot[15];
    char ten[15];
    char lop[6];
    int namSinh;
    double dtb;
    int tichLuy;
};

int File_Array(char* filename, sinhvien a[MAX], int& n);
void Heading();
void Output_Struct(sinhvien p);
void Output_Arr(sinhvien a[MAX], int n);
void HoanVi(sinhvien& x, sinhvien& y);
void Copy(sinhvien b[MAX], sinhvien a[MAX], int n);


void QuickSort(sinhvien a[MAX], int n);
void Partition(sinhvien a[MAX], int l, int r);
void Shift(sinhvien a[MAX], int l, int r);
void Create_Heap(sinhvien a[MAX], int n);
void HeapSort(sinhvien a[MAX], int n);
void MergeSort(sinhvien F[MAX], int n);
void Distribution(sinhvien F[MAX], int n, sinhvien F1[MAX], int& h1, sinhvien F2[MAX], int& h2, int p);
void Merge(sinhvien F1[MAX], int h1, sinhvien F2[MAX], int h2, sinhvien F[MAX], int p);



int File_Array(char* filename, sinhvien a[MAX], int& n)
{
    ifstream in(filename);
    if (!in)
    {
        cout << "\nKhong mo duoc tap tin!";
        return 0;
    }

    string temp;
    getline(in, temp);
    getline(in, temp);

    n = 0;
    while (!in.eof() && n < MAX)
    {
        in >> a[n].maSV;
        in >> a[n].hoSV;
        in >> a[n].tenLot;
        in >> a[n].ten;
        in >> a[n].lop;
        in >> a[n].namSinh;
        in >> a[n].dtb;
        in >> a[n].tichLuy;
        if (in)
            n++;
    }

    in.close();
    return 1;
}

void Heading()
{
    cout << left << setw(10) << "MaSV"
        << setw(12) << "Ho"
        << setw(12) << "Ten lot"
        << setw(12) << "Ten"
        << setw(8) << "Lop"
        << setw(8) << "Nam"
        << setw(10) << "DTB"
        << setw(10) << "TichLuy"
        << endl;
    cout << string(82, '-') << endl;
}

void Output_Struct(sinhvien p)
{
    cout << left << setw(10) << p.maSV
        << setw(12) << p.hoSV
        << setw(12) << p.tenLot
        << setw(12) << p.ten
        << setw(8) << p.lop
        << setw(8) << p.namSinh
        << setw(10) << fixed << setprecision(1) << p.dtb
        << setw(10) << p.tichLuy
        << endl;
}

void Output_Arr(sinhvien a[MAX], int n)
{
    Heading();
    for (int i = 0; i < n; i++)
        Output_Struct(a[i]);
}

void HoanVi(sinhvien& x, sinhvien& y)
{
    sinhvien t = x;
    x = y;
    y = t;
}

void Copy(sinhvien b[MAX], sinhvien a[MAX], int n)
{
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}


void Partition(sinhvien a[MAX], int l, int r)
{
    int i = l, j = r;
    sinhvien x = a[(l + r) / 2];
    do
    {
        while (a[i].dtb < x.dtb)
            i++;
        while (a[j].dtb > x.dtb)
            j--;
        if (i <= j)
        {
            HoanVi(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j)
        Partition(a, l, j);
    if (i < r)
        Partition(a, i, r);
}

void QuickSort(sinhvien a[MAX], int n)
{
    Partition(a, 0, n - 1);
}

void Shift(sinhvien a[MAX], int l, int r)
{
    int i = l;
    int j = 2 * i + 1;
    sinhvien x = a[i];
    while (j <= r)
    {
        if (j < r && a[j].dtb < a[j + 1].dtb)
            j++;
        if (a[j].dtb <= x.dtb)
            return;
        else
        {
            a[i] = a[j];
            i = j;
            j = 2 * i + 1;
        }
        a[i] = x;
    }
}

void Create_Heap(sinhvien a[MAX], int n)
{
    int l = (n - 1) / 2;
    while (l >= 0)
    {
        Shift(a, l, n - 1);
        l--;
    }
}

void HeapSort(sinhvien a[MAX], int n)
{
    Create_Heap(a, n);
    int r = n - 1;
    while (r > 0)
    {
        HoanVi(a[0], a[r]);
        r--;
        Shift(a, 0, r);
    }
}

void Distribution(sinhvien F[MAX], int n, sinhvien F1[MAX], int& h1, sinhvien F2[MAX], int& h2, int p)
{
    int i, k = 1, l = 0;
    h1 = 0;
    h2 = 0;
    do
    {
        i = 1;
        while (i <= p && l < n)
        {
            if (k == 1)
                F1[h1++] = F[l];
            else
                F2[h2++] = F[l];
            i++;
            l++;
        }
        k = 3 - k;
    } while (l < n);
}

void Merge(sinhvien F1[MAX], int h1, sinhvien F2[MAX], int h2, sinhvien F[MAX], int p)
{
    int i1 = 0, i2 = 0, r1, r2, h = 0;
    while (i1 < h1 && i2 < h2)
    {
        r1 = r2 = 1;
        while (r1 <= p && r2 <= p && i1 < h1 && i2 < h2)
        {
            if (F1[i1].dtb <= F2[i2].dtb)
                F[h++] = F1[i1++], r1++;
            else
                F[h++] = F2[i2++], r2++;
        }
        while (i1 < h1 && r1 <= p)
            F[h++] = F1[i1++], r1++;
        while (i2 < h2 && r2 <= p)
            F[h++] = F2[i2++], r2++;
    }
    while (i1 < h1)
        F[h++] = F1[i1++];
    while (i2 < h2)
        F[h++] = F2[i2++];
}

void MergeSort(sinhvien F[MAX], int n)
{
    int p = 1, h1, h2;
    sinhvien F1[MAX], F2[MAX];
    while (p < n)
    {
        Distribution(F, n, F1, h1, F2, h2, p);
        Merge(F1, h1, F2, h2, F, p);
        p *= 2;
    }
}