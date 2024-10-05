//Problem link: https://www.spoj.com/problems/NAKANJ/

#include <bits/stdc++.h>
using namespace std;

pair <int, int> string_to_pair(string str) {
    int x = str[0] - 'a';
    int y = str[1] - '1';
    return {x, y};
}

bool isValidMove(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

int minKnightMoves(pair<int, int> start, pair<int, int> end) {
    if(start == end) return 0;
    vector<pair<int, int>> moves = {
        {2,1}, {2,-1}, {-2,1}, {-2,-1},
        {1,2}, {1,-2}, {-1,2}, {-1,-2}
    };
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> vis(8, vector<bool>(8, false));
    q.push({start, 0});
    vis[start.first][start.second] = true;
    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        for(auto move : moves) {
            int new_x = front.first.first + move.first;
            int new_y = front.first.second + move.second;
            if (make_pair(new_x, new_y) == end) {
                return front.second + 1;
            }
            if (isValidMove(new_x, new_y) && !vis[new_x][new_y]) {
                vis[new_x][new_y] = true;
                q.push({{new_x, new_y}, front.second+1});
            }
        }
    }
}

void sol() {
    string startPos, endPos;
    cin >> startPos >> endPos;
    pair <int, int> start = string_to_pair(startPos);
    pair <int, int> end = string_to_pair(endPos);
    int res = minKnightMoves(start, end);
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}