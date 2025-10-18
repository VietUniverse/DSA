#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 20

int n, k;
int a[MAX], b[MAX];
int dem;

void Xuat_KQ(int a[MAX], int n)
{
    cout << "kq" << setw(3) << dem << " : ";
    for (int i = 1; i <= n; i++) cout << setw(2) << a[i];
    cout << endl;
}

void LietKe_DayNP(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i < n) LietKe_DayNP(i + 1);
        else { dem++; Xuat_KQ(a, n); }
    }
}

void LietKe_TH(int i)
{
    for (int j = a[i - 1] + 1; j <= n - k + i; j++)
    {
        a[i] = j;
        if (i == k) { dem++; Xuat_KQ(a, k); }
        else LietKe_TH(i + 1);
    }
}

void KhoiTao_danhdau()
{
    for (int i = 1; i <= n; i++) b[i] = 1;
}

void LietKe_HV(int i)
{
    for (int j = 1; j <= n; j++)
        if (b[j])
        {
            a[i] = j;
            b[j] = 0;
            if (i == n) { dem++; Xuat_KQ(a, n); }
            else LietKe_HV(i + 1);
            b[j] = 1;
        }
}
