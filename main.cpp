#include <bits/stdc++.h>
using namespace std;

int palidrome(int n) {
    int ans = 1;
    for (int i = 1; i * 2 <= n; i++) {
        ans = ans + palidrome(n - 2*i);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    cout << palidrome(n) << "\n";

    return 0;
}

