#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
matrix self;

/*
 점화식

 [ 1       ] = [ 1 0 ] [ 1         ]
 [ S(0, n) ] = [ 1 1 ] [ S(0, n-1) ]
                 ...

 */

matrix _mul(const matrix &a, const matrix &b) {
    int n = a.size();
    int m = a[0].size();
    int o = b[0].size();
    matrix res(n, vector<ll>(m, 0LL));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<o; k++) {
                res[i][k] += a[i][j] * b[j][k];
                res[i][k] %= mod;
            }
        }
    }
    return res;
}

matrix _pow(const matrix &a, ll n) {
    matrix res = self, base = a;
    while (n > 0) {
        if (n & 1) res = _mul(res, base);
        base = _mul(base, base);
        n /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll k, n;
    cin >> k >> n;

    matrix a(k+2, vector<ll>(k+2));
    matrix b(k+2, vector<ll>(1, 1));
    matrix c(k+2, vector<ll>(k+2));
    for (int i=0; i<k+2; i++) {
        c[i][i] = 1;
        self = c; // 항등원 만들기
        for (int j=0; j<=i; j++) a[i][j] = 1;
    }

    matrix res = _mul(_pow(a, n-1), b);
    cout << res[k+1][0];
    return 0;
}