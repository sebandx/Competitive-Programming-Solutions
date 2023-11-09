#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string word; cin >> word;

    char prev = word[0];
    bool flag = true;
    for (auto c : word) {
        if (prev != c) {
            flag = false;
            break;
        }
        prev = c;
    }
    if (flag) {
        cout << 1 << "\n";
        exit(0);
    }
    if (word[0] == word[word.size() - 1]) {
        n--;
        for (int i = 0; i < word.size() - 1; i++) {
            if (word[i] == word[i + 1]) {
                n--;
            }
        }

        cout << n << "\n";
    } else {
        cout << n << "\n";
    }


    return 0;
}
