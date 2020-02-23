#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
map<pll, bool> dp;

// ~= 4342
bool solve(ll n, ll m) {
    auto i = dp.find(pll(n, m));
    if (i != dp.end()) return i->second;
    bool res = false;
    if (!(n % m)) res = true;
    else if (n < m*2LL) res = !(solve(m, n-m));
    else res = true;
    return dp[pll(n, m)] = res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    if (n < m) swap(n, m);
    cout << (solve(n, m) ? "win" : "lose");
    return 0;
}