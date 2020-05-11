#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll dp[117] = {0, 1, 1, 1, 2, };
    for (int i=4; i<=116; i++) dp[i] = dp[i-1] + dp[i-3];
    cout << dp[n];
}