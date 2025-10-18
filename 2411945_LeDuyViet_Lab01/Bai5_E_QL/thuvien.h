#include <iostream>
using namespace std;
#define MAX 20

int n5;
int colUsed[MAX], d1[MAX * 2], d2[MAX * 2];
int pos[MAX];
int dem5 = 0;

void XuatGiai5(int pos[])
{
    cout << "\nGiai phap " << ++dem5 << " : ";
    for (int i = 1; i <= n5; i++) cout << pos[i] << " ";
}

void Try5(int row)
{
    for (int c = 1; c <= n5; c++)
    {
        if (!colUsed[c] && !d1[row - c + n5] && !d2[row + c])
        {
            pos[row] = c;
            colUsed[c] = d1[row - c + n5] = d2[row + c] = 1;
            if (row == n5) XuatGiai5(pos);
            else Try5(row + 1);
            colUsed[c] = d1[row - c + n5] = d2[row + c] = 0;
        }
    }
}
