#include <bits/stdc++.h>
#include <algorithm>
#define MAX 1000
using namespace std;

struct Job
{
    int d;
    int p;
};

Job job[MAX];
int n;
int x[MAX];
bool isVisited[MAX] = {false};
int prof = 0;
int maxProf = 0;
void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> job[i].d;
        cin >> job[i].p;
    }
}

void printSolve()
{
    maxProf = maxProf > prof ? maxProf : prof;
}

void sovle(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (!isVisited[v])
        {
            isVisited[v] = true;
            if (job[v].d >= k)
                prof += job[v].p;
            if (k == n)
            {
                printSolve();
            }
            else
            {
                sovle(k + 1);
            }

            if (job[v].d >= k)
                prof -= job[v].p;
            isVisited[v] = false;
        }
    }
}

bool compareJob(Job a, Job b)
{
    if (a.d == b.d)
    {
        return a.p > b.p;
    }
    return a.d < b.d;
}

int main()
{
    input();
    sovle(1);
    cout << maxProf;
}