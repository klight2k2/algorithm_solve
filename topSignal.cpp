#include <bits/stdc++.h>

using namespace std;

int n, arr[1000000];

int main(){
    cin>>n;
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int Q=0;
    for (int i = 1; i < n-1; i++)
    {
        if(arr[i-1]<arr[i]&& arr[i]>arr[i+1] ) Q++;
    }
    cout<<Q;
    
}