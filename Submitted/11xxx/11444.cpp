#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix _mul(const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<ll>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    if (n <= 1) {
        cout << n;
        return 0;
    }
    matrix res = {{1, 0}, {0, 1}};
    matrix base = {{1, 1}, {1, 0}};
    while (n > 0) {
        if (n & 1) res = _mul(res, base);
        base = _mul(base, base);
        n /= 2;
    }
    cout << res[0][1];
    return 0;
}

//TRY, Source By BJ