#include <iostream>
using namespace std;
bool printed = false;
int v[9][9];

bool check(int x, int y, int n) {
    for (int i=0; i<9; i++) {
        if (v[x][i] == n || v[i][y] == n) return false;
    }
    auto bx = x/3*3;
    auto by = y/3*3;
    for (int i=bx; i<bx+3; i++) {
        for (int j=by; j<by+3; j++) {
            if (v[i][j] == n) return false;
        }
    }
    return true;
}

void solve() {
    int x = -1, y = -1;
    if (!printed) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!v[i][j]) {
                    x = i;
                    y = j;
                    break;
                }
            }
            if (x != -1) break;
        }
        if (x == -1) {
            for (auto &i : v) {
                for (int j : i) cout << j << ' ';
                cout << '\n';
            }
            printed = true;
            return;
        }
        for (int i = 1; i <= 9; i++) {
            if (check(x, y, i)) {
                v[x][y] = i;
                solve();
                v[x][y] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (auto & i : v) for (int & j : i) cin >> j;
    solve();
    return 0;
}