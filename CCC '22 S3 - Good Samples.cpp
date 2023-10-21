#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; ll m; ll k; cin >> n >> m >> k;
    if (k < n) {
        cout << "-1\n";
        return 0;
    }
    k -= n;
    vector<ll> a(n);
    a[0] = 1;
    deque<ll> q;
    q.push_back(1);
    ll last = 1;
    for (ll i = 1; i < n; i++) {
        if (k >= q.size()) {
            last++;
            if (last <= m) {
                k -= last - 1;
                a[i] = last;
                q.push_back(last);
            } else {
                ll x = q.front(); q.pop_front();
                k -= m -1;
                a[i] = x;
                q.push_back(x);
            }
        } else {
            ll pos = q.size() - 1 - k;
            a[i] = q[pos];
            k = 0;
            q.push_back(a[i]);
        }
    }
    if (k > 0) {
        cout << "-1\n";
        return 0;
    }
    for (ll i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
