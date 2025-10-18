#include <iostream>
using namespace std;
#include "Thuvien.h"

void ChayChuongTrinh()
{
    int n;
    int val[MAX][MAX];
    int h[MAX][MAX];
    int bestH[MAX][MAX];
    cout << "Nhap kich thuoc ban co n: "; cin >> n;
    cout << "Nhap gia tri moi o:\n";
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> val[i][j];
    int xs, ys, xe, ye;
    cout << "Nhap toa do bat dau (x y): "; cin >> xs >> ys;
    cout << "Nhap toa do ket thuc (x y): "; cin >> xe >> ye;
    Init(h, n);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) bestH[i][j] = 0;
    h[xs][ys] = 1;
    int cnt = 0, bestSum = -999999, curSum = val[xs][ys];
    TryAll(2, xs, ys, h, n, cnt, val, curSum, bestSum, bestH, xe, ye);
    if (cnt == 0) cout << "Khong co loi giai!\n";
    else
    {
        cout << "So loi giai: " << cnt << endl;
        cout << "Gia tri lon nhat = " << bestSum << endl;
        cout << "Hanh trinh co gia tri lon nhat:\n";
        Xuat_HanhTrinh(bestH, n);
    }
    system("PAUSE");
}

int main()
{
    ChayChuongTrinh();
    return 0;
}
