#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, vector<pair<int,int>>>& graph, int cur, vector<int>& distance) {
    for (auto adj : graph[cur]) {
        if (distance[adj.first] == -1) {
            distance[adj.first] = distance[cur] + adj.second;
            dfs(graph, adj.first, distance);
        }
    }
}
int main() {
    int n; cin >> n;
    unordered_map<int, vector<pair<int, int>>> graph;
    int sumEdges = 0;
    for (int i = 0; i < n; i++) {
        int a; int b; int c; cin >> a >> b >> c;
        sumEdges += c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int time = 2 * sumEdges;
    vector<int> distance(n + 1, -1);
    distance[0] = 0;
    dfs(graph, 0, distance);
    int maxVal = INT_MIN;
    for (auto val : distance) {
        maxVal = max(maxVal, val);
    }
    
    time = time - maxVal;
    cout << time << "\n";
}
