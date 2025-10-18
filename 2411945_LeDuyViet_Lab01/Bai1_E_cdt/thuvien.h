#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define MAX 200

void NhapDay(int a[MAX], int n)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
        a[i] = -8 + rand() % 17;
}

void XuatDay(int a[MAX], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << '\t';
}

void MinMax(int a[MAX], int l, int r, int& mn, int& mx)
{
    if (l == r)
    {
        mn = a[l];
        mx = a[l];
        return;
    }
    int mid = (l + r) / 2;
    int mn1, mx1, mn2, mx2;
    MinMax(a, l, mid, mn1, mx1);
    MinMax(a, mid + 1, r, mn2, mx2);
    mn = (mn1 < mn2) ? mn1 : mn2;
    mx = (mx1 > mx2) ? mx1 : mx2;
}
