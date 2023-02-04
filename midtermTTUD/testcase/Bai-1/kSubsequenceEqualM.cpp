// cho một dãy gồm các số nguyên a1,a2,...an . Một dãy con k- phần tử của dãy đã cho là một dãy
// gồm k phần tử liên tiếp ai,ai+1,...ai+k-1 . Trọng số của dãy con k phần tử là tổng của các phần tử trong dãy con này.
// Cho hai số nguyên dương k và m. Tính Q là số lượng dãy con k phần tử sao cho trọng số của mỗi dãy con đều bằng m

// input 
// -Dòng 1 chữa 3 số nguyên dương n,k,m
// -Dòng 2: a1,a2....an
// Output
// ghi ra giá trị của Q
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int arr[MAX];
int n, k, m;

void input()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(NULL);
    // cout.tie(NULL);
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int cnt = 0;
int db[MAX] = {0};
void solve()
{
    for (int i = 1; i < k+1; i++)
    {
        db[1]+=arr[i];
        
    }
    if(db[1]==m) cnt++;
    for (int i = 2; i <= n - k; i++)
    {
        db[i]=db[i-1]-arr[i-1]+arr[i+k-1];
        // cout<<db[i]<<endl;
        if (db[i] == m)
            cnt++;
    }
    printf("%d", cnt);
}

int main()
{
    input();
    solve();
}