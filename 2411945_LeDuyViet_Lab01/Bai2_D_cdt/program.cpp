#include <iostream>
using namespace std;
#include "Thuvien.h"

void ChayChuongTrinh()
{
    int a[MAX], n, m;
    cout << "\nn = "; cin >> n;
    NhapDay(a, n);
    cout << "\nm = "; cin >> m;
    if (m < 0 || m >= n)
    {
        cout << "\nLoi: chi so m khong hop le! (yeu cau 0 <= m < " << n << ")";
        system("PAUSE");
        return;
    }
    cout << "\nDay ban dau:\n";
    XuatDay(a, n);
    Transpose(a, n, m);
    cout << "\nDay ket qua:\n";
    XuatDay(a, n);
    cout << endl;
    system("PAUSE");
}

int main()
{
    ChayChuongTrinh();
    return 1;
}
