#include <iostream>
using namespace std;
int n, dp[5001] = {1, 0, 3, 0};
const int mod = 1000000007;

int main() {
    // possible when 'n is even'
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    if (n & 1) cout << '0';
    else {
        for (int i=4; i<=n; i += 2) {
            dp[i] = dp[i-2] * 3;
            dp[i] %= mod;
            for (int j=4; j<=i; j += 2) dp[i] = (dp[i] + dp[i-j] * 2) % mod;
        }
        cout << dp[n];
    }
    return 0;
}