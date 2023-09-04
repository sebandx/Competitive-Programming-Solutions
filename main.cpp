#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<bool> sieve(3163 + 1, true);
    sieve[0] = false; sieve[1] = false;

    for (int i = 2; i * i <= 3163; i++) {
        if (sieve[i]) {
            for (int j = 2 * i; j <= 3163; j += i) {
                sieve[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= 3163; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }


    for (auto val : nums) {
        for (auto p : primes) {
            if (p * p > val) {
                break;
            }
            while (val % p == 0) {
                cout << p << " ";
                val = val / p;
            }

        }
        if (val > 1) cout << val << " ";
        cout << "\n";

    }

}
