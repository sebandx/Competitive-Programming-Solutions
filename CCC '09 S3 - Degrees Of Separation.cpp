#include <bits/stdc++.h>
using namespace std;

int main() {
    string cmd;
    vector<set<int>> temp = {{}, {6}, {6}, {4,5,6,15}, {3,5,6}, {3,4,6}, {1,2,3,4,5,7}, {6,8}, {7,9}, {8,10,12}, {9,11}, {10,12}, {9,11,13}, {12,14,15}, {13}, {3,13}, {17,18}, {16,18}, {16,17}};
    vector<set<int>> graph(51);

    for (int i = 0; i < temp.size(); i++) {
        graph[i] = temp[i];
    }

    while (cmd != "q") {
        cin >> cmd;
        if (cmd == "i") {
            int x; int y; cin >> x >> y;
            graph[x].insert(y);
            graph[y].insert(x);
        } else if (cmd == "d") {
            int x; int y; cin >> x >> y;
            graph[x].erase(y);
            graph[y].erase(x);
        } else if (cmd == "n") {
            int x; cin >> x;
            cout << graph[x].size() << "\n";
        } else if (cmd == "f") {
            int x; cin >> x;
            set<int> notInclude = graph[x];
            notInclude.insert(x);
            set<int> ff;
            for (auto val : graph[x]) {
                for (auto val1 : graph[val]) {
                    if (!notInclude.count(val1)) {
                        ff.insert(val1);
                    }
                }
            }
            cout << ff.size() << "\n";
        } else if (cmd == "s") {
            int x; int y; cin >> x >> y;
            queue<int> q;
            vector<bool> visited(51, false);
            vector<int> distance(51, 0);
            q.push(x);
            distance[x] = 0;
            while (!q.empty()) {
                int current = q.front(); q.pop();
                for (auto val : graph[current]) {
                    if (!visited[val]) {
                        q.push(val);
                        visited[val] = true;
                        distance[val] = distance[current] + 1;
                    }
                }
            }
            if (visited[y]) {
                cout << distance[y] << "\n";
            } else {
                cout << "Not connected" << "\n";
            }
        }
    }
    return 0;
}
