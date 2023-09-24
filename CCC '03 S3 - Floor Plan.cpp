#include <bits/stdc++.h>
using namespace std;

int main() {
    int flooring; cin >> flooring;
    int rows; cin >> rows;
    int columns; cin >> columns;
    vector<vector<char>> grid(rows, vector<char>(columns));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    vector<int> rooms;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (grid[i][j] == 'I') {
                continue;
            }
            int roomSize = 0;
            queue<vector<int>> q;
            q.push({i, j});
            while (!q.empty()) {
                vector<int> cur = q.front(); q.pop();
                for (auto vec : directions) {
                    vector<int> newPos = {cur[0] + vec[0], cur[1] + vec[1]};
                    if (0 <= newPos[0] && newPos[0] < rows && 0 <= newPos[1] && newPos[1] < columns && grid[newPos[0]][newPos[1]] == '.') {

                        q.push(newPos);
                        grid[newPos[0]][newPos[1]] = 'I';
                        roomSize++;
                    }
                }
            }
            rooms.push_back(roomSize);
        }
    }
    sort(rooms.begin(), rooms.end());
    int numRooms = 0;
    for (int i = rooms.size() - 1; i >= 0; i--) {
        if (flooring - rooms[i] < 0) {
            break;
        }
        flooring -= rooms[i];
        numRooms++;
    }
    if (numRooms == 1) {
        cout << numRooms << " room, " << flooring << " square metre(s) left over" << "\n";
    } else {
        cout << numRooms << " rooms, " << flooring << " square metre(s) left over" << "\n";
    }
    return 0;
}
