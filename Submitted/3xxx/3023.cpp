#include <iostream>
using namespace std;
bool c[101][101];

int main() {
    int d, r, x, y;
    char t;
    cin >> d >> r;
    for (int i=1; i<=d; i++) {
        for (int j=1; j<=r; j++) {
            cin >> t;
            c[i][j] = (t == '#');
            c[2*d+1-i][j] = c[i][j];
            c[i][2*r+1-j] = c[i][j];
            c[2*d+1-i][2*r+1-j] = c[i][j];
        }
    }
    cin >> x >> y;
    c[x][y] = !c[x][y];
    for (int i=1; i<=2*d; i++) {
        for (int j=1; j<=2*r; j++) {
            cout << (c[i][j] ? '#' : '.');
        }
        cout << "\n";
    }
}