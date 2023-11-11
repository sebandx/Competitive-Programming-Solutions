#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, vector<int>> graph;
    int n; int m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x; int y; cin >> x >> y;
        graph[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    vector<bool> visited(n, false);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto adj : graph[cur]) {
            if (!visited[adj - 1]) {
                visited[adj - 1] = true;
                q.push(adj);
            }
        }
    }

    if (graph[1].empty()) {
        visited[0] = true;
    }
    for (auto val : visited) {
        cout << val;
    }
    cout << "\n";
    return 0;
}
