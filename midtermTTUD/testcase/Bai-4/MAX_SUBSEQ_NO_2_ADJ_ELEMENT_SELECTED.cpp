// cho một dãy gồm các số nguyên dương a1,a2...an Tìm tập con của dãy đã cho sao cho tổng các phần tử trong
// tập con là lớn nhất và trong tập con không chứa 2 phần tử liên tiếp nào của dãy đã cho
// input
// -dòng 1 chứa 1 số nguyên dương n
// -dòng 2 chứa  a1,a2...an 
// output
// ghi ra tổng các phần tử trong tập con tìm được
#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;
int n, arr[MAX],dp[MAX];

void input(){
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    
}
int max(int a,int b){
    return a>b?a:b;
}
void solve(){
    dp[1]=arr[1];
    for (int i = 2; i <= n; i++)
    {
        if(i<=2){
            dp[i]=max(dp[i-1],arr[i]);
        }else{
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }
    }
    cout<<dp[n];
    
}

int main(){
    input();
    solve();
}