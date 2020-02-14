#include <iostream>
#define mod 1000000007
typedef long long ll;
using namespace std;
ll arr[4000002];

// ~= 11401
void fact_init() {
    arr[0] = 1;
    for (ll i=1; i<=4000000; i++) {
        arr[i] = i * arr[i-1];
        arr[i] %= mod;
    }
}

ll power(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y % 2) {
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        y /= 2;
    }
    return res;
}

ll solve(int n, int k) {
    ll a = power((arr[k] * arr[n - k]) % mod, mod - 2);
    a %= mod;
    ll res = arr[n] * a;
    res %= mod;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, k;
    cin >> m;
    fact_init();
    while (m--) {
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
    return 0;
}