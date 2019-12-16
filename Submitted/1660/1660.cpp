#include <iostream>
#include <vector>
#define INF 2147483646
using namespace std;
vector<int> coins, value;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int solve(int k) {
    int n, t = 1;
    value.resize(k+1);
    value[0] = 0;
    value[1] = 1;
    while (1) {
        n = (t*(t+1)*(t+2))/6;
        if (n > k) break;
        coins.push_back(n);
        t++;
    }
    for (int i=2; i<=k; i++) {
        value[i] = INF;
        for (auto c : coins) {
            if (i-c >= 0)
                value[i] = min(value[i], value[i-c]+1);
        }
    }
    return value[k];
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << solve(n);
}