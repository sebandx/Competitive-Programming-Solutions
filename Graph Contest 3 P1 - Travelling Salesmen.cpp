#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; int m; cin >> n >> m;
    map<int, vector<int>> graph;
    for (int i = 0; i < m; i++) {
        int a; int b; cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    int k; cin >> k;
    queue<int> q;
    vector<int> visited(n);
    vector<int> distances(n, 0);
    for (int i = 0; i < k; i++) {
        int val; cin >> val;
        q.push(val);
        visited[val - 1] = true;
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto val : graph[cur]) {
            if (!visited[val - 1]) {
                q.push(val);
                visited[val - 1] = true;
                distances[val - 1] = distances[cur - 1] + 1;
            }
        }
    }

    int maxTime = 0;
    for (auto val : distances) {
        if (maxTime < val) {
            maxTime = val;
        }
    }
    cout << maxTime << "\n";

    return 0;
}
