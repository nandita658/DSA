#include <bits/stdc++.h>
using namespace std;

bool mainFun(int n, int r, int m, vector<int> adj[], vector<pair<int, int>> &soldier) {
    queue<pair<int, int>> q;
    vector<bool> vis(n+1, false);
    for (int i = 0; i < m; i++) {
        int city = soldier[i].first;
        int strength = soldier[i].second;
        q.push({city,0});
        vis[city] = true;
        while(!q.empty()) {
            int curr_city = q.front().first;
            int curr_strength = q.front().second;
            q.pop();
            if(curr_strength < strength) {
                for(auto it : adj[curr_city]) {
                    if(!vis[it]) {
                        q.push({it, curr_strength + 1});
                        vis[it]=true;
                    } else {
                        return false;
                    }
                }
            }
        }
    }
    for(int i = 1; i < n+1; i++) {
        if (!vis[i]) {
            return false;
        }
    }
    return true;
}

void sol() {
    int n, r, m;
    cin >> n >> r >> m;
    int r_copy = r, m_copy = m;
    vector<int> adj[n+1];
    vector<pair<int, int>> soldier;
    while (r_copy--) {
        int src, dest;
        cin >> src >> dest;
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    while (m_copy--) {
        int city, strength;
        cin >> city >> strength;
        soldier.push_back({city, strength});
    }
    bool res = mainFun(n, r, m, adj, soldier);
    res == true ? cout << "Yes" << endl : cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}