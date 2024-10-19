// Problem statement: https://cses.fi/problemset/task/1083

#include <bits/stdc++.h>
using namespace std;

int main() {
    long n;
    cin >> n;
    long sum = 0;
    for(int i=0;i<n-1;i++) {
        long a;
        cin >> a;
        sum+=a;
    }
    long total = (n*(n+1))/2;
    cout << total-sum;
    return 0;
}