#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int db[MAX], arr[MAX], n, l1, l2;

void inputs()
{
    cin >> n >> l1 >> l2;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    db[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i <= l1)
        {
            db[i] = max(db[i - 1], arr[i]);
        }
        else
        {
            db[i] = max(db[i - 1], db[i - l1] + arr[i]);
        }
    }
    cout << db[n];
}

int main()
{
    inputs();
    solve();
}