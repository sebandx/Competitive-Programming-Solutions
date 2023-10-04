#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int x = 0; x < t; x++) {
        int l; int w; cin >> l >> w;
        vector<vector<char>> grid(w, vector<char>(l));
        vector<int> startPos;
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < l; j++) {
                char c; cin >> c;
                if (c == 'C') {
                    startPos = {i, j};
                }
                grid[i][j] = c;
            }
        }

        vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
        queue<vector<int>> q;
        vector<vector<bool>> visited(w, vector<bool>(l, false));
        vector<vector<int>> distance(w, vector<int>(l, 0));

        q.push(startPos);
        visited[startPos[0]][startPos[1]] = true;

        bool pathFound = false;
        while (!q.empty()) {
            vector<int> cur = q.front(); q.pop();
            if (grid[cur[0]][cur[1]] == 'W') {
                if (distance[cur[0]][cur[1]] < 60) {
                    cout << distance[cur[0]][cur[1]] << "\n";
                } else {
                    cout << "#notworth\n";
                }
                pathFound = true;
                break;
            }
            for (auto val : directions) {
                vector<int> newPos = {cur[0] + val[0], cur[1] + val[1]};
                if (0 <= newPos[0] && newPos[0] < w && 0 <= newPos[1] && newPos[1] < l && grid[newPos[0]][newPos[1]] != 'X' && !visited[newPos[0]][newPos[1]]) {
                    q.push(newPos);
                    visited[newPos[0]][newPos[1]] = true;
                    distance[newPos[0]][newPos[1]] = distance[cur[0]][cur[1]] + 1;
                }
            }
        }
        if (!pathFound) {
            cout << "#notworth\n";
        }
    }
    return 0;
}
