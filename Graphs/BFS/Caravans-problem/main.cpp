//Problem link: https://acm.timus.ru/problem.aspx?space=1&num=2034

#include<bits/stdc++.h>
using namespace std;

void bfs(int src, vector<int> adj[], vector<int> &dist) {
    queue<int> q;
    q.push(src);
    dist[src]=0;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(auto it:adj[front]) {
            if(dist[it]==-1) {
                dist[it]=dist[front]+1;
                q.push(it);
            }
        }
    }
}

void bfs_max_dist(int src, int dest, vector<int> adj[], vector<int> &dist_src, vector<int> &max_dist_from_rob, vector<int> &dist_rob) {
    queue<int> q;
    q.push(src);
    dist_src[src]=0;
    max_dist_from_rob[src] = dist_rob[src];
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(auto it:adj[front]) {
            int c=min(max_dist_from_rob[front],dist_rob[it]);
            if(dist_src[it]==-1 || (max_dist_from_rob[it]<c)) {
                dist_src[it]=dist_src[front]+1;
                max_dist_from_rob[it]=c;
                if(it != dest) {
                    q.push(it);
                }
            }
        }
    }
}

void mainFunc(int n, int src, int dest, int rob, vector<int> adj[]) {
    vector<int> dist_src(n+1,-1);
    vector<int> max_dist_from_rob(n+1,0);
    vector<int> dist_rob(n+1,-1);
    bfs(rob, adj, dist_rob);
    bfs_max_dist(src, dest, adj, dist_src, max_dist_from_rob, dist_rob);
    cout << max_dist_from_rob[dest] <<endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int src, dest, rob;
    cin >> src >> dest >> rob;
    mainFunc(n, src, dest, rob, adj);
}