// Cho một tập gồm các số nguyên a1,a2...an . Thực hiện trên tập số nguyên đã cho một dãy thao tác  gồm 2 loại sau
// -insert x: thêm một phần tử giá trị x vào tập
// -delete-max: xóa khỏi tập và trả về giá trị của phần tử lớn nhất trong tập

// Input
// -Dòng 1: số nguyên dương 
// -Dòng 2: a1,a2...an
// -Các dòng tiếp theo, mỗi dòng chứa 1 thao tác và định dạng như đã đề cập ở trên. Đầu vào input kết thúc bởi 1 dòng duy nhất  1 kí tự *

#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;
priority_queue<int> pq;
int n;
void input(){
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        int tes;
        cin>>tes;
        pq.push(tes);
    }
    
}
vector<int> ans;
int main(){
    input();
    string type;
    do
    {
        cin>>type;
        if(type=="*") break;
        
        if(type=="insert"){
            int x;
            cin>>x;
            pq.push(x);
        }
        if(type=="delete-max"){
            int cur=pq.top();
            cout<<cur<<endl;
            pq.pop();
        }
    } while (true);
    
}