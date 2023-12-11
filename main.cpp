#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<char>> grid(10, vector<char>(10));
    queue<vector<int>> q;
    vector<vector<bool>> visited(10, vector<bool>(10, false));
    vector<vector<int>> distance(10, vector<int>(10, -1));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'B') {
                q.push({i, j});
                visited[i][j] = true;
                distance[i][j] = 0;
            }
        }
    }


    while (!q.empty()) {
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<int> cur = q.front(); q.pop();

        for (auto direction : directions) {
            vector<int> newPos = {cur[0] + direction[0], cur[1] + direction[1]};
            if (0 <= newPos[0] && newPos[0] < 10 && 0 <= newPos[1] && newPos[1] < 10 && !visited[newPos[0]][newPos[1]]) {
                if (grid[newPos[0]][newPos[1]] == 'L') {
                    cout << distance[cur[0]][cur[1]] << "\n";
                    return 0;
                }
                else if (grid[newPos[0]][newPos[1]] == '.') {
                    visited[newPos[0]][newPos[1]] = true;
                    distance[newPos[0]][newPos[1]] = distance[cur[0]][cur[1]] + 1;
                    q.push(newPos);
                }

            }
        }
    }
    return 0;
}
