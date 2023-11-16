#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; int m; cin >> n >> m;
    unordered_map<int, set<int>> graph;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int s; int t; cin >> s >> t;
        graph[s].insert(t);
        vector<int> edge = {s, t};
        edges.push_back(edge);
    }

    for (auto edge : edges) {
        graph[edge[0]].erase(edge[1]);
        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto adj : graph[cur]) {
                if (!visited[adj - 1]) {
                    visited[adj - 1] = true;
                    q.push(adj);
                }
            }
        }
        if (visited[n - 1]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        graph[edge[0]].insert(edge[1]);
    }
    return 0;
}
