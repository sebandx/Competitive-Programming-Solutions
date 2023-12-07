#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    if (4 > n) {
        cout << "-1\n";
    } else {
        vector<vector<int>> grid(n, vector<int>(n, 0));
        int last = 0;
        for (int i = 2; i < n; i += 5) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = 1;
            }
            last = i;
        }

        if (n - 1 - last > 2) {
            for (int j = 0; j < n; j++) {
                grid[n - 1][j] = 1;

            }
            if (n % 5 == 1) {
                for (int j = 2; j + 2 < n; j += 5) {
                    grid[n - 2][j] = 1;
                    grid[n - 1][j + 2] = 0;
                    grid[n - 1][j - 2] = 0;
                    if (j + 1 + 2 < n) {
                        grid[n - 2][j + 1] = 1;
                        grid[n - 1][j + 3] = 0;
                        grid[n - 1][j - 1] = 0;
                        j++;
                    }

                }

            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
