#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v, dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, _max = 1;
    cin >> n;
    v.resize(n);
    dp.resize(n);
    for (auto & i : v) cin >> i;
    for (int i=0; i<n; i++) {
        if (dp[i] == 0) dp[i] = 1;
        for (int j=0; j<i; j++) {
            if (v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j]+1);
                _max = max(_max, dp[i]);
            }
        }
    }
    cout << _max;
    return 0;
}