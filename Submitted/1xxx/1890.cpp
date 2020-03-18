#include <iostream>
using namespace std;
typedef long long ll;
int arr[101][101];
ll dp[101][101] = {0LL, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin >> arr[i][j];
    dp[0][0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == n-1 && j == n-1) continue;
            if (i + arr[i][j] < n) dp[i + arr[i][j]][j] += dp[i][j];
            if (j + arr[i][j] < n) dp[i][j + arr[i][j]] += dp[i][j];
        }
    }
    cout << dp[n-1][n-1];
    return 0;
}