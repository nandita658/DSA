// Problem Statement: https://cses.fi/problemset/task/1069

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int len = str.length();
    int ans = 1, size = 1;
    for(int i=0;i<len-1;i++) {
        if(str[i] == str[i+1]) {
            size++;
        } else {
            size = 1;
        }
        ans = max(ans, size);
    }
    cout << ans;
}