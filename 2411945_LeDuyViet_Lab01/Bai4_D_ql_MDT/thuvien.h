#ifndef THUVIEN_H
#define THUVIEN_H

#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 20

const int a[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int b[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void Try(int i, int x, int y, int h[MAX][MAX], int n, int& slg);
void Xuat_HanhTrinh(int h[MAX][MAX], int n);
void Init(int h[MAX][MAX], int n);

void Try(int i, int x, int y, int h[MAX][MAX], int n, int& slg)
{
    int k, u, v;
    for (k = 0; k <= 7; k++)
    {
        u = x + a[k];
        v = y + b[k];
        if (1 <= u && u <= n && 1 <= v && v <= n && h[u][v] == 0)
        {
            h[u][v] = i;
            if (i < n * n)
                Try(i + 1, u, v, h, n, slg);
            else
            {
                slg++;
                cout << "\nLoi giai thu " << slg << " :";
                Xuat_HanhTrinh(h, n);
            }
            h[u][v] = 0;
        }
    }
}

void Xuat_HanhTrinh(int h[MAX][MAX], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << endl << endl;
        for (int j = 1; j <= n; j++)
            cout << setw(5) << h[i][j];
    }
    cout << endl << endl;
}

void Init(int h[MAX][MAX], int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            h[i][j] = 0;
}

#endif
