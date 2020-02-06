#include <iostream>
#include <algorithm>
using namespace std;
int dp[11][100001], value[11][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, res = 0;
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) cin >> value[i][j];
    }
    for (int i=1; i<=m; i++) dp[i][1] = value[i][1];
    for (int k=1; k<n; k++) {
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=m; j++) {
                if (i == j)
                    dp[j][k+1] = max(dp[j][k+1], dp[i][k] + value[j][k+1] / 2);
                else
                    dp[j][k+1] = max(dp[j][k+1], dp[i][k] + value[j][k+1]);
            }
        }
    }
    for (int i=1; i<=m; i++) res = max(res, dp[i][n]);
    cout << res;
    return 0;
}