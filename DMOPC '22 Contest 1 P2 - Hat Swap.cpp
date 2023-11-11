#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; int m; cin >> n >> m;
    unordered_map<int, int> colour;
    for (int i = 0; i < n; i++) {
        int ci; cin >> ci;
        colour[i + 1] = ci;
    }

    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < m; i++) {
        int p1; int p2; cin >> p1 >> p2;
        graph[p1].push_back(p2);
        graph[p2].push_back(p1);
    }

    unordered_map<int, vector<int>> s;
    unordered_map<int, vector<int>> k;
    for (const auto& pair : colour) {
        s[pair.second] = {-1, -1, -1};
        k[pair.second] = {-1, -1, -1};
    }

    vector<bool> visitedS(n + 1, false);
    vector<int> distanceS(n + 1, 0);
    queue<int> q;
    q.push(1);
    visitedS[1] = true;
    s[colour[1]] = {0, -1, 1};
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto adj : graph[cur]) {
            if (!visitedS[adj]) {
                visitedS[adj] = true;
                distanceS[adj] = distanceS[cur] + 1;
                q.push(adj);
                if (s[colour[adj]][0] == -1) {
                    s[colour[adj]] = {distanceS[adj], -1, adj};
                } else if (s[colour[adj]][1] == -1) {
                    s[colour[adj]][1] = distanceS[adj];
                }
            }
        }
    }

    vector<bool> visitedK(n + 1, false);
    vector<int> distanceK(n + 1, 0);
    q.push(n);
    visitedK[n] = true;
    k[colour[n]] = {0, -1, n};
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto adj : graph[cur]) {
            if (!visitedK[adj]) {
                visitedK[adj] = true;
                distanceK[adj] = distanceK[cur] + 1;
                q.push(adj);
                if (k[colour[adj]][0] == -1) {
                    k[colour[adj]] = {distanceK[adj], -1, adj};
                } else if (k[colour[adj]][1] == -1) {
                    k[colour[adj]][1] = distanceK[adj];
                }
            }
        }
    }

    int smol = INT_MAX;
    for (const auto& pair : s) {
        if (pair.second[2] == k[pair.first][2] && pair.second[1] != -1) {
            smol = min(smol, min(pair.second[0] + k[pair.first][1], pair.second[1] + k[pair.first][0]));
        } else if (pair.second[2] != k[pair.first][2] && pair.second[0] != -1 && k[pair.first][0] != -1) {
            smol = min(smol, pair.second[0] + k[pair.first][0]);
        }
    }

    if (smol == INT_MAX) {
        cout << -1 << "\n";
    } else {
        cout << smol << "\n";
    }
}
