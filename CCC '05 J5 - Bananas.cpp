#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool monkeyWord(string s);

bool aWord(string s) {
    if (s == "A") {
        return true;
    } else if (s.size() >= 3 && s[0] == 'B' && s.back() == 'S' && monkeyWord(s.substr(1, s.size() - 2))) {
        return true;
    } else {
        return false;
    }

}

bool monkeyWord(string s) {
    if (aWord(s)) {
        return true;
    } else {
        bool found = false;
        for (int i = 1; i < s.size() && !found; i++) {
            found = found || s[i] == 'N' && aWord(s.substr(0, i)) && monkeyWord(s.substr(i + 1));
        }
        return found;
    }

}
int main() {
    while (true) {
        string s; cin >> s;
        if (s == "X") {
            break;
        }

        if (monkeyWord(s)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}
