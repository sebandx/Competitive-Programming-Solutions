#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; int m; cin >> n >> m;
    for (int i = 2; i < min(2 + m, n + 1); i++) {
        cout << 1 << " " << i << "\n";
    }
    if (n + 1 < 2 + m) {
        int e = (2 + m) - (n + 1);
        int c = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (j == i) {
                    continue;
                }
                cout << i << " " << j << "\n";
                c++;
                if (e <= c) {
                    exit(0);
                }
            }
        }
    }
    return 0;
}
