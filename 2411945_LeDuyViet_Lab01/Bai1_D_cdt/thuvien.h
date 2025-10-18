#define MAX 100
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

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

void MinMax(int a[MAX], int l, int r, int& min, int& max)
{
    int min1, min2, max1, max2;
    if (l == r)
    {
        min = a[l];
        max = a[l];
    }
    else
    {
        MinMax(a, l, (l + r) / 2, min1, max1);
        MinMax(a, (l + r) / 2 + 1, r, min2, max2);
        min = (min1 < min2) ? min1 : min2;
        max = (max1 > max2) ? max1 : max2;
    }
}
