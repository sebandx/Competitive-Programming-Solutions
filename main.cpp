#include <bits/stdc++.h>
using namespace std;
int main() {
    int rows; int columns; int r; int c; cin >> rows >> columns >> r >> c;
    vector<vector<char>> grid(rows, vector<char>(columns, 'a'));
    if (rows != r && columns != c) {
        for (int i = r; i < rows; i++) {
            for (int j = c; j < columns; j++) {
                grid[i][j] = 'b';
                if (i == 0 || j == 0) {
                    grid[i][j] = 'c';
                }
                if (j == 0 && i == 0) {
                    grid[i][j] = 'd';
                }
            }
        }
    } else if (rows == r && columns % 2 == 0 && c % 2 != 0) {
        cout << "IMPOSSIBLE\n";
        exit(0);

    } else if (columns == c && rows % 2 == 0 && r % 2 != 0) {
        cout << "IMPOSSIBLE\n";
        exit(0);
    } else if (rows == r){
        int left = 0;
        int right = columns - 1;
        int cPal = columns - c;
        while (cPal - 2 >= 0) {
            grid[0][left] = 'e';
            grid[0][right] ='e';
            left++;
            right--;
            cPal -= 2;
        }
        if (cPal == 1) {
            grid[0][columns / 2] = 'e';
        }
    } else {
        int top = 0;
        int bottom = rows - 1;
        int rPal = rows - r;
        while (rPal - 2 >= 0) {
            grid[top][0] = 'e';
            grid[bottom][0] = 'e';
            top++;
            bottom--;
            rPal-=2;
        }
        if (rPal == 1) {
            grid[rows / 2][0] = 'e';
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    return 0;
}
