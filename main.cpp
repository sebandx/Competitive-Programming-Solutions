#include <iostream>
#include <vector>

using namespace std;



int main () {
    vector<int> wait_time(101, -1);
    vector<int> is_waiting(101, -1);
    int m; int n; int increment;
    char action;



    cin >> m;

    for (int i = 0; i < m; ++i) {
        cin >> action >> n;
        if (action == 'W') {
            increment = n;
        } else if (increment > 1) {
            increment = 0;
        } else {
            increment = 1;
        }
        for (int j = 1; j <= 100; ++j) {
            if (is_waiting[j] > -1) {
                is_waiting[j] += increment;
            }
        }
        if (action == 'S') {
            wait_time[n] += (wait_time[n] == -1) + is_waiting[n];
            is_waiting[n] = -1;
        }else if (action == 'R') {
            is_waiting[n] = 0;
            if (wait_time[n] == -1) {
                wait_time[n] = 0;
            }
        }
    }

    for (int i = 1; i <= 100; ++i) {
        if (wait_time[i] > -1) {
            cout << i << ' ';
            if (is_waiting[i] > -1) {
                cout << -1 << '\n';
            } else {
                cout << wait_time[i] << '\n';
            }
        }
    }

    return 0;
}