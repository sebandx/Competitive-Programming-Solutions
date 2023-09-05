#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<vector<int>> ways;

void add(vector<int> &seq, int n, int sum, int last) {
    if (sum == n) {
        ways.insert(seq);
        return;
    }
    for (int i = last; i <= n - 1; i++) {
        if (i + sum > n) {
            break;
        }
        seq.push_back(i);
        add(seq, n, sum + i, i);
        seq.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> emp; int s = 0;

    add(emp, n, s, 1);

    for (auto seq : ways) {
        cout << n << "=";
        for (int i = 0; i < seq.size(); i++) {

            if (i + 1 >= seq.size()) {
                cout << seq[i];
            } else {
                cout << seq[i] << "+";
            }
        }
        cout << "\n";
    }

    cout << "total=" << ways.size() << "\n";
    return 0;
}
