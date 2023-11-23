#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                c++;
            }
        }
    }
    c /= 2;

    int numForests = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            numForests++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (int j = 0; j < n; j++) {
                    if (grid[cur][j] && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }
    cout << c - (n - numForests) << "\n";

    return 0;
}
