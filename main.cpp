#include <bits/stdc++.h>
using namespace std;

bool possible(string word, vector<string> blocks, int idx) {
    if (idx == word.size()) {
        return true;
    }
    for (int i = 0; i < blocks.size(); i++) {
        if (blocks[i].find(word[idx]) != string::npos) {
            vector<string> newBlocks(blocks);
            newBlocks.erase(newBlocks.begin() + i);
            if (possible(word, newBlocks, idx + 1)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int n; cin >> n;
    vector<string> blocks(4);
    for (int i = 0; i < 4; i++) {
        cin >> blocks[i];
    }
    for (int i = 0; i < n; i++) {
        string word; cin >> word;
        if (possible(word, blocks, 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }

    return 0;
}
