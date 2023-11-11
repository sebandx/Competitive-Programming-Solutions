#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, vector<int>>& graph, vector<int>& distance, int cur) {
    for (auto adj : graph[cur]) {
        if (distance[adj] == -1) {
            distance[adj] = distance[cur] + 1;
            dfs(graph, distance, adj);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < n - 1; i++) {
        int u; int v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // this calculating distance from node 1 u monkey
    vector<int> d(n + 1, -1);
    d[1] = 0;
    dfs(graph, d, 1);
    int maxVal = INT_MIN;
    int maxX;
    for (int i = 1; i <= n; i++) {
        if (maxVal < d[i]) {
            maxVal = d[i];
            maxX = i;
        }
    }

    vector<int> dx(n + 1, -1);
    dx[maxX] = 0;
    dfs(graph, dx, maxX);

    maxVal = INT_MIN;
    int maxY;
    for (int i = 1; i <= n; i++) {
        if (maxVal < dx[i]) {
            maxVal = dx[i];
            maxY = i;
        }
    }

    vector<int> dy(n + 1, -1);
    dy[maxY] = 0;
    dfs(graph, dy, maxY);
    for (int i = 1; i <= n; i++) {
        int radius = max(dx[i], dy[i]);
        cout << radius + 1 << "\n";
    }






    return 0;
}
