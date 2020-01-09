#include <iostream>
#include <algorithm>
using namespace std;
int a[10001], dp[10001] = {0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    for (int i=3; i<=n; i++) {
        dp[i] = max(dp[i-1], max(dp[i-3]+a[i-1], dp[i-2])+a[i]);
    }
    cout << dp[n];
}