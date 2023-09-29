#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, h, p;
    cin >> n >> h >> p;

    vector<ll> bosses(n);
    for (ll i = 0; i < n; i++) {
        cin >> bosses[i];
    }

    ll x = 0;
    while (x * p < h) {
        x++;
    }

    sort(bosses.begin(), bosses.end());

    ll idx = n - x;

    ll health = idx < 0 ? 0 : bosses[idx];
    ll time = idx < 0 ? 0 : bosses[idx] * h;
    for (auto val : bosses) {
        if (health < val) {
            time += (val - health) * p;
        }
    }
    cout << time << "\n";
    return 0;
}
