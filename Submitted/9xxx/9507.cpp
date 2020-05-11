#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n;
    ll dp[68] = {1, 1, 2, 4, };
    for (int i=4; i<=67; i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
    while (n--) {
        cin >> m;
        cout << dp[m] << '\n';
    }
}