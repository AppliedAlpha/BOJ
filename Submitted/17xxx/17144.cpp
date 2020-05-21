#include <iostream>
using namespace std;

struct _pair {
    int y, x;
};

int r, c, t, a[51][51] = {0, }, up, down;
_pair dir[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void spread() {
    int b[51][51] = {0, };
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            if (a[i][j] >= 5) {
                for (const auto k : dir) {
                    int _y = i + k.y, _x = j + k.x;
                    if (_y < 1 || _y > r) continue;
                    if (_x < 1 || _x > c) continue;
                    if (a[_y][_x] == -1) continue;
                    b[_y][_x] += a[i][j] / 5;
                    b[i][j] -= a[i][j] / 5;
                }
            }
        }
    }
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            a[i][j] += b[i][j];
        }
    }
}

void fresh() {
    // Up
    a[up-1][1] = 0;
    for (int i=up-1; i>=1; i--) a[i+1][1] = a[i][1];  // ↓
    for (int i=1; i<c; i++) a[1][i] = a[1][i+1];    // ←
    for (int i=1; i<=up-1; i++) a[i][c] = a[i+1][c]; // ↑
    for (int i=c-1; i>=1; i--) a[up][i+1] = a[up][i]; // →
    a[up][1] = -1;

    // Down
    a[down+1][1] = 0;
    for (int i=down; i<=r-1; i++) a[i][1] = a[i+1][1];   // ↑
    for (int i=1; i<c; i++) a[r][i] = a[r][i+1];  // ←
    for (int i=r-1; i>=down; i--) a[i+1][c] = a[i][c];// ↓
    for (int i=c-1; i>=1; i--) a[down][i+1] = a[down][i];   // →
    a[down][1] = -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c >> t;
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1 && up == 0) {
                up = i;
                down = i+1;
            }
        }
    }
    while (t--) {
        spread();
        fresh();
    }
    int res = 0;
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            res += (a[i][j] > 0 ? a[i][j] : 0);
        }
    }
    cout << res;
    return 0;
}