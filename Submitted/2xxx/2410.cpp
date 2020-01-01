#include <iostream>
#include <vector>
#define mod 1000000000
using namespace std;
int dp[1000001] = {0, };
vector<int> nums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i=1; i<=n; i*=2) nums.push_back(i);
    dp[0] = 1;
    for (auto a : nums) {
        for (int i=1; i<=n; i++) {
            if (i-a >= 0) {
                dp[i] += dp[i-a];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[n];
}