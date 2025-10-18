#include <iostream>
#include <iomanip>
using namespace std;
#include "Thuvien.h"

void ChayChuongTrinh()
{
    int n, x, y, h[MAX][MAX], slg = 0;
    cout << "Nhap kich thuoc ban co: n = ";
    cin >> n;
    if (n <= 0 || n >= MAX)
    {
        cout << "n phai thuoc [1.." << (MAX - 1) << "]\n";
        system("PAUSE");
        return;
    }
    cout << "\nNhap toa do dau (x y) trong khoang 1.." << n << ":\n";
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;
    if (x < 1 || x > n || y < 1 || y > n)
    {
        cout << "Toa do bat dau khong hop le\n";
        system("PAUSE");
        return;
    }
    Init(h, n);
    h[x][y] = 1;
    if (n == 1)
    {
        slg = 1;
        cout << "\nLoi giai thu 1 :";
        Xuat_HanhTrinh(h, n);
    }
    else
    {
        Try(2, x, y, h, n, slg);
    }
    if (!slg) cout << "\nKhong co loi giai!";
    else cout << "\nSo loi giai : " << slg;
    system("PAUSE");
}

int main()
{
    ChayChuongTrinh();
    return 0;
}
