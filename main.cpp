#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; int m; int a; int b; cin >> n >> m >> a >> b;

    map<int, set<int>> graph;
    for (int i = 1; i <= n; i++) {
        graph[i] = {};
    }
    for (int i = 0; i < m; i++) {
        int x; int y; cin >> x >> y;

        graph[x].insert(y);
        graph[y].insert(x);
    }

    queue<int> q;
    vector<bool> visited(n + 1, false);
    q.push(a);
    visited[a] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto val : graph[cur]) {
            if (visited[val]) {
                continue;
            }
            q.push(val);
            visited[val] = true;
        }
    }

    if (visited[b]) {
        cout << "GO SHAHIR!\n";
    } else {
        cout << "NO SHAHIR!\n";
    }
    return 0;
}
