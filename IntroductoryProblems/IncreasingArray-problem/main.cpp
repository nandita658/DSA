// Problem statement: https://cses.fi/problemset/task/1094

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long> arr;
    long ans=0;
    for(int i=0;i<n;i++) {
        long a;
        cin >> a;
        arr.push_back(a);
    }
    for(int i=1;i<n;i++) {
        if(arr[i-1]>arr[i]) {
            ans += (arr[i-1]-arr[i]);
            arr[i]=arr[i-1];
        }
    }
    cout << ans;
    return 0;
}