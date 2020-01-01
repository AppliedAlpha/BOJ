#include <iostream>
#include <vector>
using namespace std;
int dp[10001] = {0, };
vector<int> nums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, tmp;
    cin >> n >> k;
    while (n--) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    dp[0] = 1;
    for (auto a : nums) {
        for (int i=1; i<=k; i++) {
            if (i-a >= 0) dp[i] += dp[i-a];
        }
    }
    cout << dp[k];
}