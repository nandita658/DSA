// Problem statement: https://cses.fi/problemset/task/1070

#include <bits/stdc++.h>
using namespace std;

void sol(int n) {
    if (n==2 || n==3) {
        cout << "NO SOLUTION";
        return;
    }
    for (int i = 2;i<=n;i+=2) {
        cout << i << " ";
    }
    for (int i=1;i<=n;i+=2) {
        cout << i << " ";
    }
}

int main() {
    int n;
    cin >> n;
    sol(n);
    return 0;
}