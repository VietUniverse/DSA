#include <iostream>
using namespace std;
#define MAX 200

void NhapDay(int a[MAX], int n)
{
    for (int i = 1; i <= n; i++) a[i] = i;
}

void XuatDay(int a[MAX], int n)
{
    for (int i = 1; i <= n; i++) cout << a[i] << '\t';
}

void HoanVi(int& x, int& y)
{
    int t = x; x = y; y = t;
}

void Exchange(int a[MAX], int i, int j, int m)
{
    for (int k = 0; k <= m - 1; k++)
        HoanVi(a[i + k], a[j + k]);
}

void Transpose(int a[MAX], int n, int m)
{
    int i = m, j = n - m;
    int base = m + 1;
    while (i != j)
    {
        if (i > j)
        {
            Exchange(a, base - i, base, j);
            i = i - j;
        }
        else
        {
            j = j - i;
            Exchange(a, base - i, base + j, i);
        }
    }
    Exchange(a, base - i, base, i);
}
