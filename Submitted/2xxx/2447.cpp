#include <iostream>
using namespace std;
char v[2300][2300];

void solve(int n, int x, int y) {
    if (n == 1) {
        v[x][y] = '*';
        return;
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (i == 1 && j == 1) continue;
            solve(n/3, x+n/3*i, y+n/3*j);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) v[i][j] = ' ';
    }
    solve(n, 0, 0);
    for (int i=0; i<n; i++) cout << v[i] << '\n';
    return 0;
}