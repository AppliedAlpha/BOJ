#include <iostream>
#include <vector>
#include <algorithm>
#define INF (int)2e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >> x;
    vector<int> dp(x+1, INF);
    dp[0] = 0;
    for (int i=1; i*i<=x; i++) dp[i*i] = 1;
    for (int i=2; i<=x; i++) {
        for (int j=1; j*j<=i; j++) {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }
    cout << dp[x];
    return 0;
}