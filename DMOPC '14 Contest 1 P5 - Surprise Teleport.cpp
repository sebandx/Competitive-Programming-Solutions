#include <bits/stdc++.h>
using namespace std;

int main() {
    int r; int c; cin >> r >> c;
    vector<int> start(2);
    cin >> start[0] >> start[1];
    vector<int> end(2);
    cin >> end[0] >> end[1];
    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    int t; cin >> t;
    set<vector<int>> portals;
    for (int i = 0; i < t; i++) {
        vector<int> pos(2);
        cin >> pos[0] >> pos[1];
        portals.insert(pos);
    }

    queue<vector<int>> q;
    q.push(start);

    vector<vector<bool>> visited(r, vector<bool>(c, false));
    vector<vector<int>> distance(r, vector<int>(c, 0));

    visited[start[0]][start[1]] = true;
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

    int portalTime = 0;
    bool portalFound = false;
    while (!q.empty()) {
        vector<int> cur = q.front(); q.pop();
        if (cur[0] == end[0] && cur[1] == end[1]) {
            break;
        }
        if (portals.find(cur) != portals.end() && !visited[end[0]][end[1]] && !portalFound) {
            portalFound = true;
            portalTime = distance[cur[0]][cur[1]];
        }
        for (auto direction : directions) {
            vector<int> newPos = {cur[0] + direction[0], cur[1] + direction[1]};
            if (0 <= newPos[0] && newPos[0] < r && 0 <= newPos[1] && newPos[1] < c && grid[newPos[0]][newPos[1]] == 'O' && !visited[newPos[0]][newPos[1]]) {
                q.push(newPos);
                visited[newPos[0]][newPos[1]] = true;
                distance[newPos[0]][newPos[1]] = distance[cur[0]][cur[1]] + 1;
            }
        }
    }
    if (portalFound) {
        cout << distance[end[0]][end[1]] - portalTime << "\n";
    } else {
        cout << 0 << "\n";
    }
    return 0;
}
