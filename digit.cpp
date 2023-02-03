#include <bits/stdc++.h>

using namespace std;
int c = 5;
string convertToString(int a)
{
    stringstream ss;
    ss << a;
    string str = ss.str();
    return str + "hello";
}
int n;
int result = -62;
int cnt=0;
bool checkNum[10];
void solution(){
    if(result==n) cnt++;
}
void TRY(int ind)
{
    int curr;
    if(ind==1){
        curr=100;
    }
    if(ind==2){
        curr=10;
    }
    if(ind==3){
        curr=2;
    }
    if(ind==4){
        curr=1000;
    }
    
    if(ind==5){
        curr=100;
    }
    
    if(ind==6){
        curr=10;
    }
    
    if(ind==7){
        curr=-100;
    }
    
    for (int v = 1; v <= 9; v++)
    {
        if (checkNum[v] == false)
        {
            result+=curr*v;
            checkNum[v]=true;
            if(ind==7){
                solution();
            }else{
                TRY(ind+1);
            }
            result-=curr*v;
            checkNum[v]=false;
        }
    }
}

int main()
{
    cin>>n;
    for (int i = 0; i <=10; i++)
    {
        checkNum[i]=false;
    }
    
    TRY(1);
    cout<<cnt;
}