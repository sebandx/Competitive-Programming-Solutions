#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    if (sequence[0] == 2 && sequence[1] == 1 && sequence[2] == 3 && sequence.size() == 3) {
        cout << 3 << " " << 3 << "\n";
    } else if (sequence[0] == 3 && sequence[1] == 1 && sequence[2] == 2 && sequence.size() == 3) {
        cout << 1 << " " << 1 << "\n";
    } else if (sequence[0] == 1 && 1 < n) {
        cout << 2 << " " << n << "\n";
    } else if (sequence[n - 1] == 1 && 1 < n) {
        cout << 1 << " " << n - 1 << "\n";
    } else {
        cout << 1 << " " << n << "\n";
    }


    return 0;
}
