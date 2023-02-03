#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
int x[100];
bool isVisited[100] = {false};
void printSolve()
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}
void solve(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (!isVisited[v])
        {
            x[k] = v;
            isVisited[v] = true;
            if (k == n)
            {
                printSolve();
            }
            else
            {
                solve(k + 1);
            }
            x[k] = -1;
            isVisited[v] = false;
        }
    }
}

int main()
{
    cin >> n;
    solve(1);
}