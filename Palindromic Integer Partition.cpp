#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<ll, ll> memo;

ll palidrome(ll n) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    ll ans = 1;
    for (int i = 1; i * 2 <= n; i++) {
        ans += palidrome(n - 2 * i);
    }

    memo[n] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;

    cout << palidrome(n) << "\n";

    return 0;
}
