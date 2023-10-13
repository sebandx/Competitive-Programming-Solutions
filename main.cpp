#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int x = 0; x < t; x++) {
        int r; cin >> r;
        int c; cin >> c;
        vector<vector<char>> grid(r, vector<char>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> grid[i][j];
            }
        }
        queue<vector<int>> q;
        vector<int> startPos = {0,0};
        q.push(startPos);
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        visited[startPos[0]][startPos[1]] = true;
        vector<vector<int>> distance(r, vector<int>(c, 0));

        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        bool possible = false;
        while(!q.empty()) {
            vector<int> curPos = q.front(); q.pop();
            if (curPos[0] == r - 1 && curPos[1] == c - 1) {
                cout << distance[curPos[0]][curPos[1]] + 1 << "\n";
                possible = true;
                break;
            }
            char val = grid[curPos[0]][curPos[1]];
            if (val == '+') {
                for (auto direction : directions) {
                    vector<int> newPos = {curPos[0] + direction[0], curPos[1] + direction[1]};
                    if (0 <= newPos[0] && newPos[0] < r && 0 <= newPos[1] && newPos[1] < c && !visited[newPos[0]][newPos[1]] && grid[newPos[0]][newPos[1]] != '*') {
                        q.push(newPos);
                        visited[newPos[0]][newPos[1]] = true;
                        distance[newPos[0]][newPos[1]] = distance[curPos[0]][curPos[1]] + 1;
                    }
                }
            } else if (val == '|') {
                for (int i = 0; i < 2; i++) {
                    vector<int> direction = directions[i];
                    vector<int> newPos = {curPos[0] + direction[0], curPos[1] + direction[1]};
                    if (0 <= newPos[0] && newPos[0] < r && 0 <= newPos[1] && newPos[1] < c && !visited[newPos[0]][newPos[1]] && grid[newPos[0]][newPos[1]] != '*') {
                        q.push(newPos);
                        visited[newPos[0]][newPos[1]] = true;
                        distance[newPos[0]][newPos[1]] = distance[curPos[0]][curPos[1]] + 1;
                    }
                }
            } else if (val == '-') {
                for (int i = 2; i < 4; i++) {
                    vector<int> direction = directions[i];
                    vector<int> newPos = {curPos[0] + direction[0], curPos[1] + direction[1]};
                    if (0 <= newPos[0] && newPos[0] < r && 0 <= newPos[1] && newPos[1] < c && !visited[newPos[0]][newPos[1]] && grid[newPos[0]][newPos[1]] != '*') {
                        q.push(newPos);
                        visited[newPos[0]][newPos[1]] = true;
                        distance[newPos[0]][newPos[1]] = distance[curPos[0]][curPos[1]] + 1;
                    }
                }
            }
        }
        if (!possible) {
            cout << "-1\n";
        }
    }
    return 0;
}
