#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int a; int b; int n; cin >> a >> b >> n;
        int numA = 0;
        bool flag = false;
        while(n - numA * a >= 0) {
            if ((n - numA * a) % b == 0) {
                flag = true;
                break;
            } else {
                numA++;
            }
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
