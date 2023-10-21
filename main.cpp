#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // tldr the logic of the program is as follows
    // choose largest good sample sequence size
    // repeat that sequence
    // unil k >= q.size()
    // then you determine the value that you need to set the next value to through the remaining value of k
    // note that you can fufill the amount of addition good samples required automatically
    // this is because q.size() > k
    // and repeat that value for the rest of the sequence, to avoid creating any unexpected good samples 
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
            // the first time something enters the else statement
            // it checks how many remaining good samples need to be created
            // and thus sets the value accordingly to be repeated for the rest of the sequence
            // their will never not be enough good samples
            // because k >= q.size() condition in the above if statement
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
