#include <bits/stdc++.h>
using namespace std;

int main() {
    int a; int b; int c; int d; cin >> a >> b >> c >> d;
    if (a < b && c < d) {
        cout << "Go to the department store\n";
    } else if (a < b) {
        cout << "Go to the grocery store\n";
    } else if (c < d) {
        cout << "Go to the pharmacy\n";
    } else {
        cout << "Stay home\n";
    }
    return 0;
}
