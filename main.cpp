#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n; cin >> n;
    vector<vector<ll>> grid(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int z = 0; z < 4; z++) {
        vector<vector<ll>> rotated(n, vector<ll>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][n - i - 1] = grid[i][j];
            }
        }
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (grid[i][0] < grid[i - 1][0]) {
                flag = false;
                break;
            }
        }
        for (int i = 1; i < n; i++) {
            if (grid[0][i] < grid[0][i - 1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << grid[i][j] << " ";
                }
                cout << "\n";
            }
            return 0;
        }
        grid = rotated;
    }
}
