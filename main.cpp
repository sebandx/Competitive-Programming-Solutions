#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool monkeyWord(string s);

// ho lee fuk the problem is actually insanely kewl

// manages 'simple' words
// ie. not stringed together by N

bool aWord(string s) {
    if (s == "A") {
        return true;
    } else if (s.size() >= 3 && s[0] == 'B' && s.back() == 'S' && monkeyWord(s.substr(1, s.size() - 2))) {
        // if start & end is B & S
        // for it to be a monkey word the middle must be a monkey word
        // this is done by calling monkeyWord function

        // remember s.size() must be >= 3 otherwise that allows 'BS' to be a monkeyWord
        // the reason why s.substring(1, s.size() - 2) is s.size() - 2 not s.size() - 1
        // is because the substr function in cpp
        // takes in parameters starting position && number characters
        // not end position
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
        // You start at i = 1 bcs 'N' can never be at the first letter
        for (int i = 1; i < s.size() && !found; i++) {
            // found must be || bcs it is false intially
            // this checks if the word before N is a simple word
            // & if s[i] is N
            // and if the word after N is a monkey word
            // recursively by breaking down (as it may also be multiple monkey words merged together)
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
