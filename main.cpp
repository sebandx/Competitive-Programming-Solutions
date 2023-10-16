#include <bits/stdc++.h>
using namespace std;

int main() {
    // number of not large books in large section
    // + number of not medium book in medium section
    // - number of medium books in large section
    // to remove duplicate swaps for medium w. large
    string shelf;
    cin >> shelf;
    int numL = 0;
    int numM = 0;
    for (int i = 0; i < shelf.size(); ++i) {
        if (shelf[i] == 'L') {
            numL++;
        } else if (shelf[i] == 'M') {
            numM++;
        }
    }

    int mInL = 0;
    int misplacedL = 0;
    for (int i = 0; i < numL; ++i) {
        if (shelf[i] == 'M') {
            mInL++;
            misplacedL++;
        } else if (shelf[i] == 'S') {
            misplacedL++;
        }
    }

    int misplacedM = 0;
    int lInM = 0;
    for (int i = numL; i < numL + numM; ++i) {
        if (shelf[i] == 'L') {
            lInM++;
            misplacedM++;
        } else if (shelf[i] == 'S') {
            misplacedM++;
        }
    }
    cout << misplacedL + misplacedM - min(mInL, lInM) << std::endl;
    return 0;
}
