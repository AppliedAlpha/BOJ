#include <iostream>
#define mod (int)1e9
using namespace std;
int v[10][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, res = 0;
    cin >> n;
    v[0][1] = 0;
    for (int i=1; i<10; i++) v[i][1] = 1;
    for (int i=2; i<=n; i++) {
        v[0][i] = v[1][i-1] % mod;
        v[9][i] = v[8][i-1] % mod;
        for (int j=1; j<9; j++) {
            v[j][i] = (v[j-1][i-1] + v[j+1][i-1]) % mod;
        }
    }
    for (int i=0; i<10; i++) {
        res += v[i][n];
        res %= mod;
    }
    cout << res;
}