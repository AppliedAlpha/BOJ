#include <iostream>
#define mod 10007
using namespace std;
int dp[1001][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i<10; i++) dp[1][i] = 1;
    for (int i=2; i<=n; i++) {
        for (int j=0; j<10; j++) {
            for (int k=0; k<=j; k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
            }
        }
    }
    int res = 0;
    for (int i=0; i<10; i++) res = (res + dp[n][i]) % mod;
    cout << res;
    return 0;
}