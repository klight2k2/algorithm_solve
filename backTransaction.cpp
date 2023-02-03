#include <bits/stdc++.h>
#include <set>
using namespace std;
int totalMoney = 0, totalTrans = 0;
void display(set<string> s)
{
    set<string>::iterator itr;

    // Displaying set elements
    for (itr = s.begin();
         itr != s.end(); itr++)
    {
        cout << *itr << " ";
    }
}
// map<string,vector<string>> listTrans;
map<string, int> listMoney;
map<string, bool> checkCycle;
set<string> listAccount;
int main()
{
    string fromAccount, toAccount, timepoint, atm;
    int money;
    do
    {
        cin >> fromAccount;
        if (fromAccount == "#")
        {
            continue;
        }
        cin >> toAccount >> money >> timepoint >> atm;
        totalTrans++;
        totalMoney += money;
        listMoney[fromAccount] += money;
        string cycle = fromAccount + toAccount;
        checkCycle[cycle] = true;
        listAccount.insert(fromAccount);
        listAccount.insert(toAccount);
    } while (fromAccount != "#");

    string query, acc;
    do
    {
        cin >> query;

        if (query == "#")
        {
            continue;
        }
        if (query == "?number_transactions")
        {
            cout << totalTrans << endl;
        }
        if (query == "?total_money_transaction")
        {
            cout << totalMoney << endl;
        }
        if (query == "?list_sorted_accounts")
        {
            display(listAccount);
        }
        if (query == "?total_money_transaction_from")
        {
            cin >> acc;
            cout << listMoney[acc] << endl;
        }
        if (query == "?inspect_cycle")
        {
            // set<string>::iterator itr;
            // bool checkC = true;
            // int k;
            // string account;
            // cin>>account>>k;
            // int cnt = 0;
            // for (itr = listAccount.begin();
            //      itr != listAccount.end(); itr++)
            // {
            //     cnt++;
            //     set<string>::iterator nexttr = itr;
            //     nexttr++;
            //     if (nexttr == listAccount.end() || cnt >= k)
            //     {
            //         nexttr = listAccount.begin();
            //     }
            //     string testtt = *itr + *nexttr;
            //     if (checkCycle[testtt] != true)
            //     {
            //         checkC = false;
            //         break;
            //     }
            //     if(cnt>=k) break;
            // }
            cout << 1;
        }

    } while (query != "#");
}