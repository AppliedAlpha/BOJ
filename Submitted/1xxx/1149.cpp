#include <iostream>
#include <algorithm>
using namespace std;
int v[1001][3], v_max[1001][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, res = 1e9;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            cin >> v[i][j];
            v_max[i][j] = 1e9;
        }
    }
    for (int i=0; i<3; i++) v_max[0][i] = v[0][i];
    for (int i=1; i<n; i++) {
        v_max[i][0] = v[i][0] + min(v_max[i-1][1], v_max[i-1][2]);
        v_max[i][1] = v[i][1] + min(v_max[i-1][0], v_max[i-1][2]);
        v_max[i][2] = v[i][2] + min(v_max[i-1][0], v_max[i-1][1]);
    }
    for (int i=0; i<3; i++) {
        res = min(res, v_max[n-1][i]);
    }
    cout << res;
}