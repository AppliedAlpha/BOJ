#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define i32_max 2147483646
#define mod 1000000009
#define endl cout << '\n'
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

int n, m, dp[100003][4] = {0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;

    dp[1][1] = dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for (int i=4; i<100003; i++) {
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % mod;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % mod;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % mod;
    }

    while (n--) {
        cin >> m;
        cout << ((i64)dp[m][1] + dp[m][2] + dp[m][3]) % mod;
        endl;
    }

    return 0;
}