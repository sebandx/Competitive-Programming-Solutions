#include <bits/stdc++.h>
using namespace std;

int main() {
    int maxN = 0;
    int k; cin >> k;
    while ((maxN + 1) * (maxN) / 2 <= k) {
        maxN++;
    }
    vector<int> cycles;
    while (k >= 0 && maxN >= 2) {
        if (k - maxN * (maxN - 1) / 2 < 0) {
            maxN--;
            continue;
        }
        k -= maxN * (maxN - 1 ) / 2;
        cycles.push_back(maxN);
    }
    int v = 0; int e = 0;
    for (int cycle : cycles) {
        v += cycle;
        e += cycle;
    }
    e += cycles.size() - 1;
    cout << v << " " << e << "\n";
    int node = 1;
    for (int i = 0; i < cycles.size(); i++) {
        int begin;
        for (int j = 0; j < cycles[i]; j++) {
            if (j == 0) {
                begin = node;
            } else if (j == cycles[i] - 1) {
                cout << node << " " << begin << "\n";
            }
            if (j != cycles[i] - 1 || i != cycles.size() - 1) {
                cout << node << " " << node + 1 << "\n";
            }
            node++;
        }
    }
    return 0;
}
