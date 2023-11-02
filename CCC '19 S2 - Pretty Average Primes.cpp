#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<bool> prime(2000001, true);
    prime[1] = false; prime[0] = false;
    for (int i = 2; i * i <= 2000000; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 2000000; j += i) {
                prime[j] = false;
            }
        }
    }
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        for (int j = 2; j < 2*n; j++) {
            int n1 = j;
            int n2 = 2*n - j;
            if (prime[n1] && prime[n2]) {
                cout << n1 << " " << n2 << "\n";
                break;
            }
        }
    }
    return 0;
}
