#include <bits/stdc++.h>
using namespace std;
int main() {
    int h; int m;
    char garbage;
    cin >> h >> garbage >> m;
    int distance = 0;
    int tHour = h;
    int tMin = m;
    while (distance < 120) {
        if (7 <= tHour && tHour < 10 || 15 <= tHour && tHour < 19) {
            tMin += 20;
        } else {
            tMin += 10;
        }
        if (60 <= tMin) {
            tMin = tMin % 60;
            tHour++;
        }
        distance += 10;
        tHour %= 24;
    }

    if (tHour < 10) {
        cout << "0" << tHour << ":";
    } else {
        cout << tHour << ":";
    }

    if (tMin < 10) {
        cout << "0" << tMin << "\n";
    } else {
        cout << tMin << "\n";
    }

    return 0;
}
