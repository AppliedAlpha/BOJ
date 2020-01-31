#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int dp[1002][1002];
int man[1002], woman[1002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> man[i];
    for (int i=1; i<=m; i++) cin >> woman[i];
    sort(man+1, man+n+1);
    sort(woman+1, woman+m+1);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i][j] = dp[i-1][j-1] + abs(man[i] - woman[j]);
            if (i > j) dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if (i < j) dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m];
    return 0;
}