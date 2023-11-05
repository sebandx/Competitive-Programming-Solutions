#include <bits/stdc++.h>
using namespace std;

int lcmCycle = 1;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

void dfs(int cur, vector<int>& visited, vector<int>& distance, unordered_map<int, int>& graph) {
    visited[cur - 1] = 1;
    int val = graph[cur];
    if (visited[val - 1] == 1) {
        int len = distance[cur - 1] - distance[val - 1] + 1;
        lcmCycle = lcm(lcmCycle, len);
    } else if (visited[val - 1] == 0) {
        distance[val - 1] = distance[cur - 1] + 1;
        dfs(val, visited, distance, graph);
    }
    visited[cur - 1] = 2;
}

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        lcmCycle = 1;
        unordered_map<int, int> graph;
        for (int i = 0; i < n; i++) {
            int i1, i2; cin >> i1 >> i2;
            graph[i1] = i2;
        }

        vector<int> visited(n, 0);
        vector<int> distance(n, 0);
        for (const auto& pair : graph) {
            if (visited[pair.first - 1] == 0) {
                dfs(pair.first, visited, distance, graph);
            }
        }
        cout << lcmCycle << "\n";

        cin >> n;
    }
    return 0;
}
