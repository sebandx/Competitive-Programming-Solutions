#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool dfs(int cur, int target, vector<int>& path, vector<bool>& visited, unordered_map<int, vector<int>>& graph) {
    visited[cur - 1] = true;
    path.push_back(cur);
    if (cur == target) {
        return true;
    }
    for (auto val : graph[cur]) {
        if (!visited[val - 1]) {
            if (dfs(val, target, path, visited, graph)) {
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; int r; cin >> n >> r;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < n - 1; i++) {
        int a; int b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    set<int> holes;
    for (int i = 0; i < r; i++) {
        int ri; cin >> ri;
        holes.insert(ri);
    }

    int x; int y; cin >> x >> y;
    vector<bool> visited(n, false);
    vector<int> path;
    dfs(x, y, path, visited, graph);

    vector<int> distanceToHole(n, INT_MAX);
    queue<int> q;
    for(int hole : holes) {
        distanceToHole[hole - 1] = 0;
        q.push(hole);
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto adj : graph[cur]) {
            if(distanceToHole[adj - 1] == INT_MAX) {
                distanceToHole[adj - 1] = distanceToHole[cur - 1] + 1;
                q.push(adj);
            }
        }
    }

    int minDistance = INT_MAX;
    for(int node : path) {
        minDistance = min(minDistance, distanceToHole[node - 1]);
    }
    cout << minDistance << "\n";
    return 0;
}
