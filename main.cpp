#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; int m; int k; cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    queue<vector<int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            vector<int> pos = {i, j};
            if (grid[i][j] != 0) {
                visited[i][j] = true;
                q.push(pos);
            }
        }
    }
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<int>> distance(n, vector<int>(m, 0));
    while (!q.empty()) {
        vector<int> cur = q.front(); q.pop();
        for (auto direction : directions) {
            vector<int> newPos = {cur[0] + direction[0], cur[1] + direction[1]};
            if (0 <= newPos[0] && newPos[0] < n && 0 <= newPos[1] && newPos[1] < m && distance[cur[0]][cur[1]] + 1 <= k && !visited[newPos[0]][newPos[1]]) {
                distance[newPos[0]][newPos[1]] = distance[cur[0]][cur[1]] + 1;
                visited[newPos[0]][newPos[1]] = true;
                grid[newPos[0]][newPos[1]] = grid[cur[0]][cur[1]];
                q.push(newPos);
            } else if (0 <= newPos[0] && newPos[0] < n && 0 <= newPos[1] && newPos[1] < m && distance[cur[0]][cur[1]] + 1 == distance[newPos[0]][newPos[1]] && visited[newPos[0]][newPos[1]]) {
                grid[newPos[0]][newPos[1]] = min(grid[newPos[0]][newPos[1]], grid[cur[0]][cur[1]]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
