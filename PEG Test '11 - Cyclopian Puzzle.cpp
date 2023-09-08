#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << from_rod << to_rod << "\n";
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int N; cin >> N;
    hanoi(N, 'A', 'C', 'B');
    return 0;
}
