// Problem Set - https://codeforces.com/contest/670/problem/D2

#include <bits/stdc++.h>
using namespace std;

bool possible(vector<long long> &a, vector<long long> &b, long long mid, long long n, long long k) {
    long long requiredIngredients = 0;
    for(long long i=0;i<n;i++) {
        if(mid*a[i]>b[i]) {
            requiredIngredients+=(mid*a[i]-b[i]);
        }
        if(requiredIngredients>k) {
            return false;
        }
    }
    return true;
}

int main() {
    long long l=1, r=2*1e9;
    long long n, k;
    cin >> n >> k;
    vector<long long> a, b;
    for(long long i=0;i<n;i++) {
        long long temp;
        cin >> temp;
        a.push_back(temp);
    }
    for(long long i=0;i<n;i++) {
        long long temp;
        cin >> temp;
        b.push_back(temp);
    }
    long long ans=0;
    while(l<=r) {
        long long mid = (l+r)/2;
        if(possible(a, b, mid, n, k)) {
            ans=mid;
            l=mid+1;
        } else {
            r=mid-1;
        }
    }
    cout << ans;
    return 0;
}