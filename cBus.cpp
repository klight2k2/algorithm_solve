#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int x[MAX], c[MAX][MAX], q = 0, Q, f = 0, fMin = 1000000, cMin = 10000;
bool isVisited[2 * MAX] = {false};
int n;

void inputs()
{

    scanf("%d %d", &n, &Q);
    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            scanf("%d", &c[i][j]);
            cMin = cMin < c[i][j] ? cMin : c[i][j];
        }
    }
}
bool check(int v, int q)
{
    if (isVisited[v])
        return false;
    if (v <= n)
    {
        if (q < Q)
        {
            return true;
        }
    }
    else
    {
        if (isVisited[v - n])
        {
            return true;
        }
    }
    return false;
}

void printSolve()
{
    if (f + c[x[2 * n]][0] < fMin)
    {
        fMin = f + c[x[2 * n]][0];
    }
};

void solve(int k)
{
    for (int v = 1; v <= 2 * n; v++)
    {
        if (check(v, q))
        {
            isVisited[v] = true;
            x[k] = v;
            f += c[x[k - 1]][x[k]];
            if (v > n)
                q--;
            else
                q++;
            if (k == 2 * n)
            {
                printSolve();
            }
            else
            {
                if (f + (2 * n - k) * cMin < fMin)
                    solve(k + 1);
            }
            if (v > n)
                q++;
            else
                q--;
            f -= c[x[k - 1]][x[k]];
            isVisited[v] = false;
            x[k] = -1;
        }
    }
}
int main()
{
    x[0] = 0;
    inputs();
    solve(1);
    printf("%d", fMin);
}
