#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "Thuvien.h"

void ChayChuongTrinh()
{
    int a[MAX], n, l, r, min = 0, max = 0;
    cout << "\nn = "; cin >> n;
    NhapDay(a, n);
    cout << "\nl = "; cin >> l;
    cout << "\nr = "; cin >> r;
    if (l < 0 || r < 0 || l >= n || r >= n || l > r)
    {
        cout << "\nLoi: chi so khong hop le! (yeu cau 0 <= l <= r < " << n << ")";
        system("PAUSE");
        return;
    }
    MinMax(a, l, r, min, max);
    cout << "\nDay da cho:\n";
    XuatDay(a, n);
    cout << "\nMina[" << l << ",..," << r << "] = " << min;
    cout << "\nMaxa[" << l << ",..," << r << "] = " << max;
    system("PAUSE");
}

int main()
{
    ChayChuongTrinh();
    return 1;
}
