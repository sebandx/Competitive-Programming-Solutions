#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    map<int, vector<int>> graph;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        graph[i + 1] = {};
        for (int j = 0; j < m; j++) {
            int page; cin >> page;
            graph[i + 1].push_back(page);
        }
    }
    int minLen = INT_MAX;
    vector<bool> visited(n, false);
    vector<int> distance(n, 1);
    queue<int> q;
    q.push(1);
    visited[0] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto pg : graph[cur]) {
            if (!visited[pg - 1]) {
                q.push(pg);
                distance[pg - 1] = distance[cur - 1] + 1;
                visited[pg - 1] = true;
                if (graph[pg].empty()) {
                    minLen = min(minLen, distance[pg - 1]);
                }
            }
        }
    }
    if (all_of(visited.begin(), visited.end(), [](bool v) {return v;})) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }
    cout << minLen << "\n";
    return 0;
}
