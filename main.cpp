#include <bits/stdc++.h>
using namespace std;

int getV(char c) {
    if (c >= '0' && c <= '9') { return c - '0'; }
    return 10 + c - 'A';
}
int main() {
    int n; cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<bool>> row(n, vector<bool>(n));
    vector<vector<bool>> col(n, vector<bool>(n));
    bool flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            int v = getV(grid[i][j]);
            if (row[i][v] || col[i][v]) {
                flag = false;
            }
            row[i][v] = col[i][v] = true;
        }
    }

    if (!flag) {
        cout << "No\n";
        return 0;
    }
    vector<int> a(n);
    flag = true;
    for (int i = 0; i < n; i++) {
        a[i] = getV(grid[0][i]);
        if (i != 0 && a[i] < a[i - 1]) {
            flag = false;
        }
    }

    for (int i = 0; i < n; i++) {
        a[i] = getV(grid[i][0]);
        if (i != 0 && a[i] < a[i - 1]) {
            flag = false;
        }
    }

    if (flag) {
        cout << "Reduced\n";
    } else {
        cout << "Latin\n";
    }



    return 0;
}
