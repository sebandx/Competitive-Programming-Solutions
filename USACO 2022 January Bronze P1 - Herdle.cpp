#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<char> grid(9);
    for (int i = 0; i < 9; i++) {
        cin >> grid[i];
    }
    vector<char> grid2(9);
    for (int i = 0; i < 9; i++) {
        cin >> grid2[i];
    }
    int green = 0;
    for (int i = 0; i < 9; i++) {
        if (grid[i] == grid2[i]) {
            green++;
        }
    }
    unordered_map<char, int> count;
    for (int i = 0; i < 9; i++) {
        count[grid[i]] += 1;
    }
    unordered_map<char, int> count2;
    for (int i = 0; i < 9; i++) {
        count2[grid2[i]] += 1;
    }
    int yellow = 0;
    for (const auto pair : count) {
        if (count2.find(pair.first) != count2.end()) {
            yellow += min(pair.second, count2[pair.first]);

        }
    }
    cout << green << "\n" << yellow - green << "\n";

    return 0;
}
