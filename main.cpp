#include <bits/stdc++.h>
using namespace std;

int dfs(int cur, int prev, vector<int>& distances, vector<bool>& visited, unordered_map<int, vector<int>>& graph, int maxCycle) {
    visited[cur - 1] = true;
    distances[cur - 1] = (prev == -1) ? 0 : distances[prev - 1] + 1;
    int localMax = maxCycle;

    for (auto val : graph[cur]) {
        if (visited[val - 1]) {
            localMax = max(distances[cur - 1] - distances[val - 1] + 1, localMax);
        } else if (!visited[val - 1]) {
            localMax = max(dfs(val, cur, distances, visited, graph, localMax), localMax);
        }
    }

    return localMax;
}

int main() {
    for (int x = 0; x < 5; x++) {
        unordered_map<int, vector<int>> graph;
        set<int> nodes;

        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int n1; int n2; cin >> n1 >> n2;
            graph[n1].push_back(n2);
            nodes.insert(n1); nodes.insert(n2);
        }
        vector<int> distances(nodes.size(), 0);
        vector<bool> visited(nodes.size(), false);
        cout << dfs(1, -1, distances, visited, graph, 0) << "\n";
    }
    return 0;
}
