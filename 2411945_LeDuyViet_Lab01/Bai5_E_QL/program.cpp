#include <iostream>
using namespace std;
#include "Thuvien.h"

void ChayChuongTrinh()
{
    cout << "Nhap n (so hau): "; cin >> n5;
    for (int i = 0; i < MAX; i++) colUsed[i] = 0;
    for (int i = 0; i < MAX * 2; i++) d1[i] = d2[i] = 0;
    dem5 = 0;
    Try5(1);
    cout << "\nTong so cach dat: " << dem5 << endl;
    system("PAUSE");
}

int main()
{
    ChayChuongTrinh();
    return 0;
}
