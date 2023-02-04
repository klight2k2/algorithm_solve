// -Subsset of a sequence sum is from a to b
// Cho một dãy gồm n số phân biệt a1,a2,...an. Cho hai số nguyên dương A và B. Tính Q là số tập
// con của dãy n số nguyên đã cho sao cho tổng các phần tử của mỗi tập con lớn hơn hoặc bằng A và nhỏ hơn hoặc bằng B
// input
// -Dòng 1 chứa n, A,B
// -Dòng 2: chứa a1,a2,...an
// output
// -Ghi ra giá trị Q
#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;
int n, arr[MAX], A, B, result = 0;
vector<int> leftArr, rightArr;
vector<int>::iterator low, high;

void input()
{

    cin >> n >> A >> B;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void genSubsets(int startId, int setSize,
                vector<int> &vec)
{
    int total;
    long long numSubsets = pow(2, setSize);
    for (int i = 0; i < numSubsets; i++)
    {
        total = 0;
        for (int j = 0; j < setSize; j++)
        {
            if (i & (1 << j))
                total += arr[j + startId];
        }
        vec.push_back(total);
    }
}
void calc()
{
    for (int i = 0; i < leftArr.size(); i++)
    {
        high = upper_bound(rightArr.begin(), rightArr.end(), B - leftArr[i]);
        low = lower_bound(rightArr.begin(), rightArr.end(), A - leftArr[i]);
        result += (high - low);
    }
}
void solve()
{
    genSubsets(0, n / 2, leftArr);
    if (n % 2 != 0)
        genSubsets(n / 2, n / 2 + 1, rightArr);
    else
        genSubsets(n / 2, n / 2, rightArr);
    sort(rightArr.begin(), rightArr.end());
    calc();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();
    cout << result << endl;
}