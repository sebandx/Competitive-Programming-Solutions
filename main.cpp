#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    vector<vector<ll>> friends(n, vector<ll>(3));
    for (int i = 0; i < n; i++) {
        cin >> friends[i][0] >> friends[i][1] >> friends[i][2];
    }
    sort(friends.begin(), friends.end(), [](const vector<ll>& a, const vector<ll>& b) {
        return a[0] < b[0];
    });
    ll l = 0;
    ll h = friends[friends.size() - 1][0];
    ll m;

    while (l <= h) {
        m = (l + h) / 2;
        ll t = 0;
        for (auto val : friends) {
            int distance = abs(val[0] - m);
            if (distance > val[2]) {
                t += (distance - val[2]) * val[1];
            }
        }
        ll mRight = m + 1;
        ll tRight = 0;
        for (auto val : friends) {
            int distance = abs(val[0] - mRight);
            if (distance > val[2]) {
                tRight += (distance - val[2]) * val[1];
            }
        }
        ll mLeft = m - 1;
        ll tLeft = 0;
        for (auto val : friends) {
            int distance = abs(val[0] - mLeft);
            if (distance > val[2]) {
                tLeft += (distance - val[2]) * val[1];
            }
        }
        if (t < tRight && t < tLeft) {
            break;
        } else if (t == tRight || t == tLeft) {
            break;
        } else if (t < tRight) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }

    ll t = 0;
    for (auto val : friends) {
        ll distance = abs(val[0] - m);
        if (distance > val[2]) {
            t += (distance - val[2]) * val[1];
        }
    }
    cout << t << "\n";
    return 0;
}
