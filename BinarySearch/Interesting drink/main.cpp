// Problem statement: https://codeforces.com/problemset/problem/706/B/

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> shops;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        shops.push_back(a);
    }
    sort(shops.begin(), shops.end());
    int q;
    cin >> q;
    vector<int> coins;
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        coins.push_back(a);
    }
    vector<int> res;
    for (int i = 0; i < q; i++)
    {
        auto it = upper_bound(shops.begin(), shops.end(), coins[i]);
        res.push_back(it - shops.begin());
    }
    for (int i = 0; i < q; i++)
    {
        cout << res[i] << endl;
    }
}