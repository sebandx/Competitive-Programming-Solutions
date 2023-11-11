#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> cities(4, 0);
    for (int i = 1; i < 5; i++) {
        cin >> cities[i];
    }

    for (int i = 1; i < 5; i++) {
        cities[i] = cities[i] + cities[i - 1];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << abs(cities[j] - cities[i]) << " ";
        }
        cout << "\n";
    }
    return 0;
}
