#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, vector<int>>& graph, int cur, vector<int>& distance) {
    for (auto adj : graph[cur]) {
        if (distance[adj] == -1) {
            distance[adj] = distance[cur] + 1;
            dfs(graph, adj, distance);
        }
    }
}
int main() {
    int n; cin >> n;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < n - 1; i++) {
        int x; int y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<int> distance(n + 1, -1);
    distance[1] = 0;
    dfs(graph, 1, distance);
    int maxD = INT_MIN;
    int maxDNode;
    for (int i = 1; i <= n; i++) {
        if (maxD < distance[i]) {
            maxD = distance[i];
            maxDNode = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        distance[i] = -1;
    }
    
    distance[maxDNode] = 0;
    dfs(graph, maxDNode, distance);
    maxD = INT_MIN;
    for (int i = 1; i <= n; i++) {
        if (maxD < distance[i]) {
            maxD = distance[i];
        }
    }

    cout << maxD << "\n";
}
