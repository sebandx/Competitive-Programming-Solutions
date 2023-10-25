#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int r; int c; cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> visited(r, vector<bool>(c));
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    int totalMonkeys = 0;
    for (int i = 1; i < r - 1; i++) {
        for (int j = 1; j < c - 1; j++) {
            bool monkey = false;
            if (!visited[i][j] && grid[i][j] != '#') {
                queue<vector<int>> q;
                vector<int> pos = {i, j};
                q.push(pos);
                visited[i][j] = true;

                while (!q.empty()) {
                    vector<int> cur = q.front(); q.pop();
                    if (grid[cur[0]][cur[1]] == 'M') {
                        monkey = true;
                    }
                    for (auto direction : directions) {
                        vector<int> newPos = {cur[0] + direction[0], cur[1] + direction[1]};
                        if (!visited[newPos[0]][newPos[1]] && grid[newPos[0]][newPos[1]] != '#') {
                            q.push(newPos);
                            visited[newPos[0]][newPos[1]] = true;
                        }
                    }
                }
                if (monkey) {
                    totalMonkeys++;
                }
            }
        }
    }
    cout << totalMonkeys << "\n";
}