#include <iostream>
#include <queue>
using namespace std;

struct Point {
    char x, y;
};

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<char>> grid(r, vector<char>(c));
    queue<Point> flood, painter;
    vector<vector<char>> floodDistance(r, vector<char>(c, -1));
    vector<vector<char>> painterDistance(r, vector<char>(c, -1));

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                painter.push({(char)i, (char)j});
                painterDistance[i][j] = 0;
            }
            if (grid[i][j] == '*') {
                flood.push({(char)i, (char)j});
                floodDistance[i][j] = 0;
            }
        }
    }

    const pair<int, int> directions[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!flood.empty()) {
        Point cur = flood.front(); flood.pop();
        for (auto direction : directions) {
            Point newPos = {static_cast<char>(cur.x + direction.first), static_cast<char>(cur.y + direction.second)};
            if (0 <= newPos.x && newPos.x < r && 0 <= newPos.y && newPos.y < c && floodDistance[newPos.x][newPos.y] == -1 && (grid[newPos.x][newPos.y] == '.' || grid[newPos.x][newPos.y] == 'S')) {
                flood.push(newPos);
                floodDistance[newPos.x][newPos.y] = floodDistance[cur.x][cur.y] + 1;
            }
        }
    }

    while (!painter.empty()) {
        Point cur = painter.front(); painter.pop();
        if (grid[cur.x][cur.y] == 'D') {
            cout << (int)painterDistance[cur.x][cur.y] << "\n";
            return 0;
        }
        for (auto direction : directions) {
            Point newPos = {static_cast<char>(cur.x + direction.first), static_cast<char>(cur.y + direction.second)};
            if (0 <= newPos.x && newPos.x < r && 0 <= newPos.y && newPos.y < c && (painterDistance[cur.x][cur.y] + 1 < floodDistance[newPos.x][newPos.y] || floodDistance[newPos.x][newPos.y] == -1) && (grid[newPos.x][newPos.y] == '.' || grid[newPos.x][newPos.y] == 'D')) {
                if (painterDistance[newPos.x][newPos.y] == -1) {
                    painter.push(newPos);
                    painterDistance[newPos.x][newPos.y] = painterDistance[cur.x][cur.y] + 1;
                }
            }
        }
    }

    cout << "KAKTUS\n";
    return 0;
}
