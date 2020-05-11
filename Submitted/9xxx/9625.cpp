#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    long long dp[50] = {0, 1, 1, };
    for (int i=3; i<50; i++) dp[i] = dp[i-1] + dp[i-2];
    cout << dp[n-1] << ' ' << dp[n];
}