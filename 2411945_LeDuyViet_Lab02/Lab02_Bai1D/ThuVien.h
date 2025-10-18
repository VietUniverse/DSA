#define MAX 100


int TapTin_mang1c(char* filename, int a[MAX], int& n);
void Xuat_Mang(int a[MAX], int n);

int TKTT_DauTien(int a[MAX], int n, int x);
int TKTT_DauTien_LC(int a[MAX], int n, int x);
int TKTT_CuoiCung(int a[MAX], int n, int x);
void TKTT_CacChiSo(int a[MAX], int n, int x);


int TapTin_mang1c(char* filename, int a[MAX], int& n)
{
    ifstream in(filename);
    if (!in)
        return 0;
    in >> n;
    for (int i = 0; i < n; i++)
        in >> a[i];
    in.close();
    return 1;
}

void Xuat_Mang(int a[MAX], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << '\t';
    cout << endl;
}


int TKTT_DauTien(int a[MAX], int n, int x)
{
    int i = 0;
    while (i < n && a[i] != x)
        i++;
    if (i == n)
        return -1;
    return i;
}

int TKTT_DauTien_LC(int a[MAX], int n, int x)
{
    int i = 0;
    a[n] = x;
    while (a[i] != x)
        i++;
    if (i == n)
        return -1;
    return i;
}

int TKTT_CuoiCung(int a[MAX], int n, int x)
{
    int i = n - 1;
    while (i >= 0 && a[i] != x)
        i--;
    return i;
}

void TKTT_CacChiSo(int a[MAX], int n, int x)
{
    int found = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            found = 1;

    if (!found)
        cout << endl << x << " khong co trong mang.";
    else
    {
        cout << endl << x << " xuat hien tai cac vi tri: ";
        for (int i = 0; i < n; i++)
            if (a[i] == x)
                cout << i << '\t';
    }
}
#pragma once
