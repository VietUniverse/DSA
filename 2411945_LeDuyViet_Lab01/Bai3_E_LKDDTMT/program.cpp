#include <iostream>
using namespace std;
#include "thuvien.h"

void ChayChuongTrinh()
{
    cout << "Nhap n: "; cin >> n;
    cout << "Nhap ma tran:\n";
    NhapMaTran(a, n);
    int x, y;
    cout << "Nhap toa do xuat phat (1..n): "; cin >> x >> y;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) visited[i][j] = 0;
    visited[x - 1][y - 1] = 1;
    dem3 = 0;
    Try(x - 1, y - 1, 0, a[x - 1][y - 1]);
    cout << "\nTong so duong di: " << dem3 << endl;
    system("PAUSE");
}

int main()
{
    ChayChuongTrinh();
    return 0;
}
