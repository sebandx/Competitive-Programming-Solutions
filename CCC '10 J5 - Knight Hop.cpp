#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<int> startPos(2);
    vector<int> endPos(2);
    cin >> startPos[0] >> startPos[1] >> endPos[0] >> endPos[1];
    if (startPos[0] == endPos[0] && startPos[1] == endPos[1]) {
        cout << 0 << "\n";
    }
    queue<vector<int>> q;
    q.push(startPos);
    vector<bool> visited(8 * 8, false);
    vector<int> distance(8 * 8, 0);

    vector<vector<int>> directions = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    // blud ur way for indexing is retarded

    visited[(startPos[0] - 1) * 8 + startPos[1] - 1] = true;

    while (!q.empty()) {
        vector<int> cur = q.front(); q.pop();

        int curIdx = (cur[0] - 1) * 8 + cur[1] - 1;
        for (auto vec : directions) {
            vector<int> newPos = {cur[0] + vec[0], cur[1] + vec[1]};
            int newIdx = (newPos[0] - 1) * 8 + newPos[1] - 1;
            if (1 <= newPos[0] && newPos[0] <= 8 && 1 <= newPos[1] && newPos[1] <= 8 && !visited[newIdx]) {
                q.push(newPos);
                distance[newIdx] = distance[curIdx] + 1;
                visited[newIdx] = true;
                if (newPos[0] == endPos[0] && newPos[1] == endPos[1]) {
                    cout << distance[newIdx] << "\n";
                    exit(0);
                }
            }
        }

    }
    return 0;
}
