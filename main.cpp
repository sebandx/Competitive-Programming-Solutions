#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    unordered_map<char, set<char>> graph;
    vector<string> edges;
    unordered_map<char, bool> visited;
    while (input != "**") {
        cin >> input;
        if (input == "**") {
            break;
        }
        edges.push_back(input);
        graph[input[0]].insert(input[1]);
        graph[input[1]].insert(input[0]);
        visited[input[0]] = false;
        visited[input[1]] = false;
    }
    int count = 0;
    for (auto edge : edges) {
        graph[edge[0]].erase(edge[1]);
        graph[edge[1]].erase(edge[0]);

        queue<char> q;
        q.push('A');
        visited['A'] = true;
        while (!q.empty()) {
            char cur = q.front(); q.pop();
            for (auto val : graph[cur]) {
                if (!visited[val]) {
                    visited[val] = true;
                    q.push(val);
                }
            }
        }
        if (!visited['B']) {
            cout << edge << "\n";
            count++;
        }
        for (auto& pair : visited) {
            visited[pair.first] = false;
        }
        graph[edge[0]].insert(edge[1]);
        graph[edge[1]].insert(edge[0]);
    }
    cout << "There are " << count << " disconnecting roads.\n";
    return 0;
}
