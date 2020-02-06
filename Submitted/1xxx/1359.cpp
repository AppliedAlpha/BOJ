#include <iostream>
#include <iomanip>
using namespace std;
int dp[9][9];

int c(int n, int r) {
    int &ret = dp[n][r];
    if (ret > 0) return ret;
    if (r == 0 || r == n) return ret = 1;
    return ret = c(n-1, r-1) + c(n-1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, ret = 0;
    cin >> n >> m >> k;
    for (int i=k; i<=m; i++) {
        if (i <= m && m-i <= n-m)
            ret += c(m, i) * c(n-m, m-i);
    }
    cout << fixed << setprecision(15) << (double)1.0*ret/c(n, m);
    return 0;
}