#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
map<pii, bool> dp;

bool solve(int n, int m) {
    auto i = dp.find(pii(n, m));
    if (i != dp.end()) return i->second;
    bool res = false;
    if (!(n % m)) res = true;
    else if (n < m*2LL) res = !(solve(m, n-m));
    else res = true;
    return dp[pii(n, m)] = res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (true) {
        cin >> n >> m;
        if (!n && !m) break;
        if (n < m) swap(n, m);
        cout << (solve(n, m) ? "A wins\n" : "B wins\n");
    }
    return 0;
}