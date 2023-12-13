#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < n - 1; i++) {
        int a; int b; cin >> a >> b;
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        queue<int> q;
        vector<bool> visited(n, false);
        visited[i - 1] = true;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto adj : graph[cur]) {
                if (!visited[adj - 1]) {
                    visited[adj - 1] = true;
                    q.push(adj);
                }
            }
        }
        bool flag = true;
        for (auto val : visited) {
            flag = val && flag;
        }
        if (flag) {
            cout << i << "\n";
            return 0;
        }


    }
    cout << "-1\n";
    return 0;
}
