//Problem link: https://www.spoj.com/problems/WATER/

#include<bits/stdc++.h>
using namespace std;

int mainFunc(int n, int m, vector<vector<int>> &field) {
    vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if (i==0 || i==n-1 || j==0 || j==m-1) {
                pq.push({field[i][j], i, j});
                vis[i][j]=true;
            }
        }
    }
    int ans = 0;
    while (!pq.empty()) {
        auto[height, x, y] = pq.top();
        pq.pop();
        for(auto dir : dirs) {
            int new_x = x + dir.first;
            int new_y = y + dir.second;
            if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && !vis[new_x][new_y]) {
                pq.push({max(height, field[new_x][new_y]), new_x, new_y});
                if(field[new_x][new_y] < height) ans += (height - field[new_x][new_y]);
                vis[new_x][new_y] = true;
            }
        }
    }  
    return ans;
}

void sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> field(n);
    for (int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int a;
            cin >> a;
            field[i].push_back(a);
        }
    }
    int res = mainFunc(n, m, field);
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        sol();
    } 
}