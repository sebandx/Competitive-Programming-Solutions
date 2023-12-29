#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    long long n; long long m; cin >> n >> m;
    unordered_map<long long, long long> rows;
    for (long long i = 0; i < n; i++) {
        long long val; cin >> val;
        if (val != -1) {
            rows[val - i]++;
        }
    }
    unordered_map<long long, long long> columns;
    for (long long i = 0; i < m; i++) {
        long long val; cin >> val;
        if (val != -1) {
            columns[val - i]++;
        }
    }

    long long c = 0;
    for (auto val : rows) {
        if (columns.find(val.first) != columns.end()) {
            c += min(val.second, columns[val.first]);
        }
    }
    cout << c << "\n";
    return 0;
}
