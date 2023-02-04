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
    int curr=1;
    switch (ind)
    {
    case 1:
    case 8:
        curr = 100;
        break;
    case 4:
        curr = -100;
        break;
    case 2:
    case 9:
        curr = 10;
        break;
    case 7:
        curr = 1000;
        break;

    default:
        break;
    }
    for (int v = 1; v <= 9; v++)
    {
        if (checkNum[v] == false)
        {
            result+=curr*v;
            checkNum[v]=true;
            if(ind==10){
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
    TRY(1);
    cout<<cnt;
}