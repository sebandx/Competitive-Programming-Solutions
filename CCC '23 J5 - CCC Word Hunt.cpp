#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0},
                                  {1,1},{-1,-1},{1,-1},{-1,1}};
int occurs = 0;
void find(vector<vector<char>> grid, string word, int index, vector<int> direction, vector<int> prevPos, bool turn, vector<vector<int>> path) {
    if (index == word.size()) {
        occurs++;
        return;
    }
    if (turn) {
        vector<int> pos = {prevPos[0] + direction[0], prevPos[1] + direction[1]};
        if (pos[0] >= 0 && pos[0] < grid[0].size() && pos[1] >= 0 && pos[1] < grid.size() && grid[pos[1]][pos[0]] == word[index]) {

            path.push_back(pos);
            find(grid, word, index + 1, direction, pos, turn, path);
            path.pop_back();
        }
    } else if (direction[0] == 0 || direction[1] == 0) {
        for (int i = 0; i < 4; i++) {
            vector<int> pos = {prevPos[0] + directions[i][0], prevPos[1] + directions[i][1]};
            if (pos[0] >= 0 && pos[0] < grid[0].size() && pos[1] >= 0 && pos[1] < grid.size() && grid[pos[1]][pos[0]] == word[index]) {
                if (directions[i][0] == direction[0] && directions[i][1] == direction[1]) {
                    path.push_back(pos);
                    find(grid, word, index + 1, direction, pos, turn, path);
                    path.pop_back();
                } else {
                    vector<int> newDirection = {directions[i][0], directions[i][1]};
                    path.push_back(pos);
                    find(grid, word, index + 1, newDirection, pos, true, path);
                    path.pop_back();
                }
            }
        }
    } else {
        for (int i = 4; i < 8; i++) {
            vector<int> pos = {prevPos[0] + directions[i][0], prevPos[1] + directions[i][1]};
            if (pos[0] >= 0 && pos[0] < grid[0].size() && pos[1] >= 0 && pos[1] < grid.size() && grid[pos[1]][pos[0]] == word[index]) {
                if (directions[i][0] == direction[0] && directions[i][1] == direction[1]) {
                    path.push_back(pos);
                    find(grid, word, index + 1, direction, pos, turn, path);
                    path.pop_back();
                } else {
                    path.push_back(pos);
                    vector<int> newDirection = {directions[i][0], directions[i][1]};
                    find(grid, word, index + 1, newDirection, pos, true, path);
                    path.pop_back();
                }
            }
        }
    }
}
int main() {
    string w; cin >> w;
    int r, c; cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            if (grid[j][i] == w[0]) {
                for (auto vec : directions) {
                    vector<int> pos = {i + vec[0], j + vec[1]};
                    vector<vector<int>> path = {{i, j}};
                    if (0 <= pos[0] && pos[0] < c && 0 <= pos[1] && pos[1] < r && grid[pos[1]][pos[0]] == w[1]) {
                        path.push_back(pos);
                        find(grid, w, 2, vec, pos, false, path);
                    }
                }
            }
        }
    }
    cout << occurs << "\n";
    return 0;
}
