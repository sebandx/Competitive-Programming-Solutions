#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> graph;

bool dfs(int cur, unordered_map<int, int>& visited, unordered_map<int, int>& distance, int start, int target) {
    visited[cur] = 1;
    for (auto val : graph[cur]) {
        if (visited[val] == 1) {
            if (visited[target] == 1 && visited[start] == 1) {
                cout << "Yes " << distance[target] - distance[start] - 1 << "\n";
                return true;
            }
        } else if (visited[val] == 0) {
            distance[val] = distance[cur] + 1;
            if (dfs(val, visited, distance, start, target)) {
                return true;
            }
        }
    }
    visited[cur - 1] = 2;
    return false;
}

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int x; int y; cin >> x >> y;
        graph[x].push_back(y);
    }
    int num1, num2;

    cin >> num1 >> num2;
    while (num1 != 0 || num2 != 0) {
        unordered_map<int, int> visited;
        unordered_map<int, int> distance;
        for (const auto& pair : graph) {
            visited[pair.first] = 0;
            distance[pair.first] = 0;
        }
        if (!dfs(num1, visited, distance, num1, num2)) {
            cout << "No\n";
        }
        cin >> num1 >> num2;
    }
    return 0;
}
