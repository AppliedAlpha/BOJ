#include <iostream>
typedef long long ll;
using namespace std;
ll n, k, mod;
int c[2003][2003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> mod;
    for (int i=0; i<=mod; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j=1; j<i; j++) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    }
    int res = 1;
    while (n > 0 || k > 0) {
        res = (res * c[n%mod][k%mod]) % mod;
        n /= mod;
        k /= mod;
    }
    cout << res;
    return 0;
}