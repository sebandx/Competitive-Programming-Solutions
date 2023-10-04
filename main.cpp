#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    unordered_map<ll, vector<ll>> graph;
    unordered_map<ll, bool> visited;

    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        graph[y].push_back(x);
        visited[x] = false;
        visited[y] = false;
    }

    ll p, q;
    cin >> p >> q;
    queue<ll> toVisit;
    toVisit.push(p);
    visited[p] = true;

    while (!toVisit.empty()) {
        ll cur = toVisit.front();
        toVisit.pop();
        if (cur == q) {
            cout << "no\n";
            exit(0);
        }
        for (auto val : graph[cur]) {
            if (!visited[val]) {
                visited[val] = true;
                toVisit.push(val);
            }
        }
    }

    for (const auto& pair : visited) {
        visited[pair.first] = false;
    }

    toVisit.push(q);
    visited[q] = true;
    
    while (!toVisit.empty()) {
        ll cur = toVisit.front();
        toVisit.pop();
        if (cur == p) {
            cout << "yes\n";
            exit(0);
        }
        for (auto val : graph[cur]) {
            if (!visited[val]) {
                visited[val] = true;
                toVisit.push(val);
            }
        }
    }
    cout << "unknown\n";
    return 0;
}
