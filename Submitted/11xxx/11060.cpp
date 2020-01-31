#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2147483600
using namespace std;
vector<int> v, dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    v.resize(n);
    dp.resize(n);
    for (auto & i : v) cin >> i;
    for (auto & i : dp) i = MAX;
    dp[0] = 0;
    for (int i=0; i<n-1; i++) {
        for (int j=1; j<=v[i]; j++) {
            if (i+j >= n) break;
            else dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }
    //for (auto i : dp) cout << i << ' ';
    cout << (dp[n-1] != MAX ? dp[n-1] : -1);
    return 0;
}