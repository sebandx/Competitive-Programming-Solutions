#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
int main() {
    ll n; cin >> n;
    vector<ll> villages(n);
    for (ll i = 0; i < n; i++) {
        cin >> villages[i];
    }

    sort(villages.begin(), villages.end());

    lb smol = LONG_LONG_MAX;
    for (ll i = 1; i < n - 1; i++) {
        smol = min(smol, lb(villages[i] - villages[i - 1]) / 2.0 + lb(villages[i + 1] - villages[i]) / 2.0);
    }
    cout << fixed << setprecision(1) << smol << endl;

    return 0;
}
