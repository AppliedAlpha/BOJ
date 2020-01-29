#include <iostream>
using namespace std;
int dp[1003];

int solve(int n) {
    dp[1] = 1;
    dp[2] = 3;
    for (int i=3; i<=n; i++) dp[i] = (dp[i-1] + 2*dp[i-2]) % 10007;
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}