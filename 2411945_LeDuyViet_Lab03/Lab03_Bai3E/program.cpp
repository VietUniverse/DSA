#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;

#include "ThuVien.h"
#include "menu.h"

int main()
{
    NhanVien a[MAX], b[MAX];
    int n = 0;

    ChayChuongTrinh(a, b, n);
    return 0;
}