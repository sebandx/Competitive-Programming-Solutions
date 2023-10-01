#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; int m; cin >> n >> m;
    map<int, vector<int>> graph;
    for (int i = 0; i < m; i++) {
        int x; int y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    queue<int> qAnt;
    int w; cin >> w;
    for (int i = 0; i < w; i++) {
        int val; cin >> val;
        qAnt.push(val);
    }

    queue<int> q;
    q.push(1);
    vector<bool> visited(n);
    vector<int> distance(n);
    vector<bool> visitedAnts(n);

    int c = 1;
    // home is N
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == n) {
            cout << distance[cur - 1] << "\n";
            exit(0);
        }
        for (auto val : graph[cur]) {
            if (!visited[val - 1] && !visitedAnts[val - 1]) {
                q.push(val);
                visited[val - 1] = true;
                distance[val - 1] = distance[cur - 1] + 1;
            }
        }
        if (c == 4) {
            int curAnt = qAnt.front(); qAnt.pop();
            for (auto val : graph[curAnt]) {
                if (!visitedAnts[val - 1]) {
                    qAnt.push(val);
                    visitedAnts[val - 1] = true;
                }
            }
        }
        c++;
    }
    cout << "sacrifice bobhob314\n";
    return 0;
}
