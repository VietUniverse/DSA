#include <iostream>
using namespace std;
#include "Thuvien.h"

void ChayChuongTrinh()
{
    int a[MAX], n, l, r, mn = 0, mx = 0;
    cout << "n = "; cin >> n;
    if (n <= 0 || n > MAX) return;
    NhapDay(a, n);
    cout << "l = "; cin >> l;
    cout << "r = "; cin >> r;
    if (l < 0 || r < 0 || l >= n || r >= n || l > r)
    {
        cout << "\nLoi: chi so khong hop le! (yeu cau 0 <= l <= r < " << n << ")";
        system("PAUSE");
        return;
    }
    if (l < 0) l = 0;
    if (r >= n) r = n - 1;
    MinMax(a, l, r, mn, mx);
    cout << "Day:\n"; XuatDay(a, n); cout << endl;
    cout << "Min = " << mn << ", Max = " << mx << endl;
    system("PAUSE");
}

int main()
{
    ChayChuongTrinh();
    return 0;
}
