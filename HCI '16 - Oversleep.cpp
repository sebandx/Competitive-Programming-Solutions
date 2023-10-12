#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; int m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<int> startPos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            grid[i][j] = c;
            if (c == 's') {
                startPos = {i, j};
            }
        }
    }

    vector<vector<int>> directions = {{0, 1},{1,0},{-1,0},{0,-1}};
    queue<vector<int>> q;
    q.push(startPos);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[startPos[0]][startPos[1]] = true;
    vector<vector<int>> distance(n, vector<int>(m, 0));

    while (!q.empty()) {
        vector<int> cur = q.front(); q.pop();
        for (const auto& direction : directions) {
            vector<int> newPos = {cur[0] + direction[0], cur[1] + direction[1]};
            if (0 <= newPos[0] && newPos[0] < n && 0 <= newPos[1] && newPos[1] < m && grid[newPos[0]][newPos[1]] != 'X' && !visited[newPos[0]][newPos[1]]) {
                if (grid[newPos[0]][newPos[1]] == 'e') {
                    cout << distance[cur[0]][cur[1]] << "\n";
                    exit(0);
                }
                visited[newPos[0]][newPos[1]] = true;
                distance[newPos[0]][newPos[1]] = distance[cur[0]][cur[1]] + 1;
                q.push(newPos);
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}
