#include <bits/stdc++.h>
using namespace std;

int main() {
    int j; cin >> j;
    int a; cin >> a;
    unordered_map<int, int> available;
    for (int i = 1; i <= j; i++) {
        char size; cin >> size;
        if (size == 'S') {
            available[i] = 1;
        } else if (size == 'M') {
            available[i] = 2;
        } else {
            available[i] = 3;
        }
    }
    int satisifed = 0;
    for (int i = 0; i < a; i++) {
        char size; cin >> size; int num; cin >> num;
        int reqSize = 0;
        if (size == 'S') {
            reqSize = 1;
        } else if (size == 'M') {
            reqSize = 2;
        } else {
            reqSize = 3;
        }
        if (available.find(num) != available.end() && reqSize <= available[num]) {
            available.erase(num);
            satisifed++;
        }
    }
    cout << satisifed << "\n";
    return 0;


}
