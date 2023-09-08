// C++ recursive function to
// solve tower of hanoi puzzle
#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
    if (n == 0) {
        return;
    }
    // move n - 1 disk from from_rod to aux_rod
    // this is so that the n-th disk is clear to move to to_rod
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    // after you've moved all n - 1 disks to aux_rod
    // you can move from_rod to to_rod
    // so this means aux_rod becomes your from_rod
    // to_rod remains the same because your moving to your final destination
    // which is to_rod
    // & from_rod is just the extra one you can use

    cout << from_rod << to_rod << "\n";


    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Driver code
int main()
{
    int N; cin >> N;

    hanoi(N, 'A', 'C', 'B');
    return 0;
}
