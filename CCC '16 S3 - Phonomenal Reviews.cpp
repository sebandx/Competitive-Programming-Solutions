#include <bits/stdc++.h>
using namespace std;

void dfs1(int cur, unordered_map<int, vector<int>>& graph, vector<bool>& visited, vector<bool>& hasPho) {
    for (auto adj : graph[cur]) {
        if (!visited[adj]) {
            visited[adj] = true;
            dfs1(adj, graph, visited, hasPho);
            hasPho[cur] = hasPho[cur] | hasPho[adj];
        }
    }
}

void dfs2(int cur, unordered_map<int, vector<int>>& graph, vector<bool>& visited, vector<int>& distance, vector<bool>& hasPho) {
    for (auto adj : graph[cur]) {
        if (!visited[adj] && hasPho[adj]) {
            visited[adj] = true;
            distance[adj] = distance[cur] + 1;
            dfs2(adj, graph, visited, distance, hasPho);
        }
    }
}

int main() {
    int n; int m; cin >> n >> m;
    vector<bool> pho(n, false);
    int start = 0;
    for (int i = 0; i < m; i++) {
        int p; cin >> p;
        start = p;
        pho[p] = true;
    }

    unordered_map<int, vector<int>>graph;
    for (int i = 0; i < n - 1; i++) {
        int a; int b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n, false);
    visited[start] = true;
    dfs1(start, graph, visited, pho);
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    vector<int> distance(n, 0);
    dfs2(start, graph, visited, distance, pho);

    int count = 0;
    for (auto val : pho) {
        if (val) {
            count++;
        }
    }

    int rad = INT_MIN;
    int node = 0;
    for (int i = 0; i < n; i++) {
        if (rad < distance[i]) {
            rad = distance[i];
            node = i;
        }
    }

    for (int i = 0; i < n; i++) {
        distance[i] = 0;
        visited[i] = false;
    }
    visited[node] = true;
    dfs2(node, graph, visited, distance, pho);
    int diameter = 0;
    for (auto val : distance) {
        diameter = max(diameter, val);
    }

    cout << (count - 1) * 2 - diameter << "\n";
    return 0;
}
