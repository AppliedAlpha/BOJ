#include <iostream>
#include <algorithm>
using namespace std;
int maze[1001][1001];
int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> maze[i][j];
        }
    }
    dp[0][0] = maze[0][0];
    for (int i=1; i<n; i++) dp[i][0] = dp[i-1][0] + maze[i][0];
    for (int i=1; i<m; i++) dp[0][i] = dp[0][i-1] + maze[0][i];
    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            dp[i][j] = max(max(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + maze[i][j];
        }
    }
    cout << dp[n-1][m-1];
    return 0;
}