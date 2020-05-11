#include <iostream>
using namespace std;
typedef long long ll;

ll solve(int n) {
    ll dp[36] = {1, 1};
    for (int i=2; i<=n; i++) {
        if (i % 2) {
            dp[i] += dp[(i-1)/2]*dp[(i-1)/2];
        }
        for (int j=0; j<i/2; j++) {
            dp[i] += 2*(dp[j]*dp[i-j-1]);
        }
    }
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