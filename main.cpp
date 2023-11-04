#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> grid, string word, int index, vector<int> cur, vector<vector<bool>> visited) {
    vector<vector<int>> directions = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    if (index == word.size()) {
        return true;
    }
    for (auto direction : directions) {
        vector<int> newPos = {cur[0] + direction[0], cur[1] + direction[1]};
        if (0 <= newPos[0] && newPos[0] < grid.size() && 0 <= newPos[1] && newPos[1] < grid.size()) {
            if (grid[newPos[0]][newPos[1]] == word[index] && !visited[newPos[0]][newPos[1]]) {
                visited[newPos[0]][newPos[1]] = true;
                if (dfs(grid, word, index + 1, newPos, visited)) {
                    return true;
                }
                visited[newPos[0]][newPos[1]] = false;
            }
        }

    }
    return false;
}

int main() {
    int n; int q; cin >> n >> q;
    vector<vector<char>> grid(n, vector<char>(q));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for (int z = 0; z < q; z++) {
        string word; cin >> word;
        bool found = false;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == word[0]) {
                    vector<int> cur = {i, j};
                    vector<vector<bool>> visited(n, vector<bool>(n));
                    visited[i][j] = true;
                    found = dfs(grid, word, 1, cur, visited) || found;
                }
            }
        }
        if (found) {
            cout << "good puzzle!\n";
        } else {
            cout << "bad puzzle!\n";
        }
    }
    return 0;
}
