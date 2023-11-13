#include <bits/stdc++.h>
using namespace std;

int main() {
    double k; double p; double x; cin >> k >> p >> x;
    double smol = INT_MAX;
    for (int i = 1; i < 10000; i++) {
        smol = min(smol, i * x + k * p / i);
    }
    cout << fixed << setprecision(3) << smol << "\n";
    return 0;
}
