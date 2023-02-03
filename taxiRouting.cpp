#include <bits/stdc++.h>
using namespace std;
int c[24][24], cMin = 0;
int n;
int x[12], y[12];
bool visited[12] = {false};
int fMin = 100000, f = 0, cnt = 0;
void input()
{
    cin >> n;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> c[i][j];
            cMin = cMin > c[i][j] ? c[i][j] : cMin;
        }
    }
}

bool check(int v)
{
    return visited[v];
}

void printSolve()
{
    if (fMin > f + c[y[n]][0])
        fMin = f + c[y[n]][0];
}

void solve(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (!check(v))
        {
            visited[v] = true;
            x[k] = v;
            y[k] = v + n;
            f += c[y[k - 1]][v] + c[v][v + n];
            if (k == n)
            {
                printSolve();
            }
            else
            {
                if (f + (n - v) * cMin * 2 + cMin < fMin)
                {
                    solve(k + 1);
                }
            }
            f -= (c[y[k - 1]][v] + c[v][v + n]);
            visited[v] = false;
            x[k] = -1;
            y[k] = -1;
        }
    }
}
int main()
{
    y[0] = 0;
    input();
    solve(1);
    cout << fMin;
}