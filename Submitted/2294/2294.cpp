#include <iostream>
#include <vector>
#define INF 2147483646
using namespace std;
vector<int> coins, value;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int solve(int k) {
    value.resize(k+1);
    value[0] = 0;
    for (int i=1; i<=k; i++) {
        value[i] = INF;
        for (auto c : coins) {
            if (i-c >= 0)
                value[i] = min(value[i], value[i-c]+1);
        }
    }
    return (value[k] != INF) ? value[k] : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k, t;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> t;
        coins.push_back(t);
    }
    cout << solve(k) << '\n';
}