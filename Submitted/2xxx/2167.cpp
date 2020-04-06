#include <iostream>
using namespace std;
int arr[301][301], dp[301][301];

// ~= 11660
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, x1, x2, y1, y2;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i][j] = arr[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    cin >> k;
    while (k--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] << '\n';
    }
    return 0;
}