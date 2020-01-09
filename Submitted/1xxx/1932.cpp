#include <iostream>
#include <algorithm>
using namespace std;
int v[501][501], v_max[501][501] = {0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, res = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) cin >> v[i][j];
    }
    v_max[0][0] = v[0][0];
    for (int i=1; i<n; i++) {
        v_max[i][0] = v[i][0] + v_max[i-1][0];
        v_max[i][i] = v[i][i] + v_max[i-1][i-1];
        for (int j=1; j<=i-1; j++) {
            v_max[i][j] = max(v_max[i-1][j-1], v_max[i-1][j]) + v[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        res = max(res, v_max[n-1][i]);
    }
    cout << res;
}