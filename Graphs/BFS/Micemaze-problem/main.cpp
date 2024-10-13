//Problem link: https://www.spoj.com/problems/MICEMAZE/

#include<bits/stdc++.h>
using namespace std;

int mainFunc(int n, int end, int t, vector<pair<int,int>> adj[]) {
    queue<pair<int, int>> q;
    vector<int> dist(n);
    vector<bool> vis(n, false);
    q.push({end, 0});
    dist[end] = 0;
    vis[end] = true;
    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        for(auto it : adj[front.first]) {
            if(!vis[it.first]) {
                q.push(it);
                vis[it.first] = true;
                dist[it.first] = dist[front.first] + it.second;
            }
        }
    }
    int cnt=0;
    for (int i=0;i<n;i++) {
        if(dist[i] <= t) cnt++;
    }
    return cnt;
}

int main() {
    int n, end, t, m;
    cin >> n >> end >> t >> m;
    vector<pair<int, int>> adj[n+1];
    for (int i=0;i<m;i++) {
        int src, dest, time;
        cin >> src >> dest >> time;
        adj[dest].push_back({src, time});
    }
    int res = mainFunc(n, end, t, adj);
    cout << res;
}