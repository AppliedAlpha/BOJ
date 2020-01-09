#include <iostream>
using namespace std;
int v[15][15];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        for (int i=0; i<=x; i++) {
            v[i][0] = 0;
            for (int j=1; j<=y; j++) {
                if (!i) v[i][j] = j;
                else v[i][j] = v[i-1][j] + v[i][j-1];
            }
        }
        cout << v[x][y] << '\n';
    }
    return 0;
}