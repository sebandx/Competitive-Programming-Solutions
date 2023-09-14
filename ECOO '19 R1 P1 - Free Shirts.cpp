#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    for (int x = 0; x < 10; x++) {
        int n; int m; int d; cin >> n >> m >> d;
        vector<int> event(d);
        event[0] = n;
        for (int i = 0; i < m; i++) {
            int a; cin >> a;
            if (a < d) {
                event[a] += 1;
            }
        }

        int toWash = 0;
        int c = 0;
        for (int i = 1; i < d; i++) {
            event[i] += event[i - 1] - 1;
            toWash++;
            if (event[i] <= 0) {
                event[i] = toWash;
                toWash = 0;
                c++;
            }
        }
        cout << c << "\n";
    }

    return 0;
}
