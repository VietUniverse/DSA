#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 15

int mvx[8] = { 2,1,-1,-2,-2,-1,1,2 };
int mvy[8] = { 1,2,2,1,-1,-2,-2,-1 };

void Init(int h[MAX][MAX], int n)
{
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) h[i][j] = 0;
}

void Xuat_HanhTrinh(int h[MAX][MAX], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << endl;
        for (int j = 1; j <= n; j++) cout << setw(4) << h[i][j];
    }
    cout << endl;
}

void CopyPath(int src[MAX][MAX], int dst[MAX][MAX], int n)
{
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dst[i][j] = src[i][j];
}

void TryAll(int iStep, int x, int y, int h[MAX][MAX], int n, int& cnt,
    int valMat[MAX][MAX], int curSum, int& bestSum, int bestH[MAX][MAX],
    int xEnd, int yEnd)
{
    int u, v;
    for (int k = 0; k < 8; k++)
    {
        u = x + mvx[k];
        v = y + mvy[k];
        if (u >= 1 && u <= n && v >= 1 && v <= n && h[u][v] == 0)
        {
            h[u][v] = iStep;
            int newSum = curSum + valMat[u][v];
            if (iStep < n * n)
                TryAll(iStep + 1, u, v, h, n, cnt, valMat, newSum, bestSum, bestH, xEnd, yEnd);
            else
            {
                if (u == xEnd && v == yEnd)
                {
                    cnt++;
                    if (newSum > bestSum)
                    {
                        bestSum = newSum;
                        CopyPath(h, bestH, n);
                    }
                }
            }
            h[u][v] = 0;
        }
    }
}
