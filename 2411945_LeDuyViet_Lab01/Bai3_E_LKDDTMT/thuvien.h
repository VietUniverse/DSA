#include <iostream>
using namespace std;
#define MAX 20

int a[MAX][MAX];
int visited[MAX][MAX];
int n;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int pathR[MAX * MAX], pathC[MAX * MAX];
int dem3 = 0;

void NhapMaTran(int a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
}

void XuatDuongDi(int len, int sum)
{
    cout << "\nDuong di thu " << ++dem3 << ": ";
    for (int k = 0; k < len; k++)
        cout << "(" << pathR[k] + 1 << "," << pathC[k] + 1 << ") ";
    cout << " | Do dai = " << len << " | Tong = " << sum;
}

void Try(int x, int y, int len, int sum)
{
    pathR[len] = x; pathC[len] = y;
    XuatDuongDi(len + 1, sum);
    for (int k = 0; k < 4; k++)
    {
        int u = x + dx[k], v = y + dy[k];
        if (u >= 0 && u < n && v >= 0 && v < n && visited[u][v] == 0)
        {
            visited[u][v] = 1;
            Try(u, v, len + 1, sum + a[u][v]);
            visited[u][v] = 0;
        }
    }
}