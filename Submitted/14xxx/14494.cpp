#include <iostream>
#define mod 1000000007
typedef long long ll;
using namespace std;
ll n, m, dp[1002][1002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i=1; i<=n; i++) dp[i][1] = 1;
    for (int i=1; i<=m; i++) dp[1][i] = 1;
    for (int i=2; i<=n; i++) {
        for (int j=2; j<=m; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }
    cout << dp[n][m];
    return 0;
}