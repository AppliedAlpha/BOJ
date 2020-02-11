#include <iostream>
#include <vector>
#define mod 1000
using namespace std;
typedef long long ll;
typedef vector<vector<int>> matrix;

matrix _mul(const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<int>(n));
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
    int n;
    ll power;
    cin >> n >> power;
    matrix base(n, vector<int>(n)), res(n, vector<int>(n));
    for (auto & i : base) for (int & j : i) cin >> j;
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            if (i == j) res[i][j] = 1;
            else res[i][j] = 0;
        }
    }
    while (power > 0) {
        if (power & 1) res = _mul(res, base);
        base = _mul(base, base);
        power /= 2;
    }
    for (const auto & i : res) {
        for (int j : i) cout << j << ' ';
        cout << '\n';
    }
    return 0;
}