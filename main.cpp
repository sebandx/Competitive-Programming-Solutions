#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int t; cin >> t;
    vector<vector<int>> trees(t, vector<int>(2));
    set<int> rows;
    set<int> columns;

    for (int i = 0; i < t; i++) {
        vector<int> pos(2);
        cin >> pos[0] >> pos[1];
        trees[i] = pos;

        rows.insert(pos[0]);
        columns.insert(pos[1]);
    }
    rows.insert(0);
    columns.insert(0);


    int maxSize = 0;
    for (auto row : rows) {
        for (auto column : columns) {
            bool f = true;
            while (f) {
                vector<int> s = {row + 1, column + 1};
                vector<int> e = {s[0] + maxSize + 1, s[1] + maxSize + 1};
                for (auto tree : trees) {
                    if (s[0] <= tree[0] && s[1] <= tree[1] && tree[0] <= e[0] && tree[1] <= e[1] || (e[0] > n || e[1] > n)) {
                        f = false;
                        break;
                    }
                }
                if (f) {
                    maxSize++;
                }
            }
        }
    }

    cout << maxSize + 1 << "\n";
    return 0;
}
