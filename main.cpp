#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& matrix, int cur, vector<int>& visited) {
    visited[cur] = 1;
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[cur][i] == 1) {
            if (visited[i] == 1) {
                cout << "NO\n";
                exit(0);
            } else if (visited[i] == 0){
                dfs(matrix, i, visited);
            }
        }
    }
    visited[cur] = 2;
}
int main() {
    int n; cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(matrix, i, visited);
        }
    }
    cout << "YES\n";
    return 0;
}
