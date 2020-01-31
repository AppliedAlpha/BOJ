#include <iostream>
#include <algorithm>
using namespace std;
int res[2][100003];
int v[2][100003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> m;
    while (m--) {
        cin >> n;
        for (int i=0; i<n; i++) res[0][i] = res[1][i] = 0;
        for (auto & i : v) for (int j=0; j<n; j++) cin >> i[j];
        res[0][0] = v[0][0];
        res[1][0] = v[1][0];
        for (int i=1; i<n; i++) {
            res[0][i] = max(res[1][i-1] + v[0][i], res[0][i-1]);
            res[1][i] = max(res[0][i-1] + v[1][i], res[1][i-1]);
        }
        cout << max(res[0][n-1], res[1][n-1]) << '\n';
    }
    return 0;
}