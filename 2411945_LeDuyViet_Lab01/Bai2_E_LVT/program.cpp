#include <iostream>
using namespace std;
#include "Thuvien.h"

void ChayChuongTrinh()
{
    int a[MAX], n, m;
    cout << "n = "; cin >> n;
    if (n <= 0 || n >= MAX) return;
    NhapDay(a, n);
    cout << "m = "; cin >> m;
    if (m < 0 || m >= n)
    {
        cout << "\nLoi: chi so m khong hop le! (yeu cau 0 <= m < " << n << ")";
        system("PAUSE");
        return;
    }
    if (m < 0 || m > n) return;
    cout << "Day ban dau:\n"; XuatDay(a, n); cout << endl;
    if (m > 0 && m < n) Transpose(a, n, m);
    cout << "Day ket qua:\n"; XuatDay(a, n); cout << endl;
    system("PAUSE");
}

int main()
{
    ChayChuongTrinh();
    return 0;
}
