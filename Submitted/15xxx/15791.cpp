#include <iostream>
#define mod 1000000007
typedef long long ll;
using namespace std;

// ~= 11401
ll fact(ll x, ll res) {
    for (ll i=1; i<=x; i++) {
        res *= i;
        res %= mod;
    }
    return res;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    ll res;
    cin >> n >> k;
    if (n == k || k == 0) cout << 1;
    else {
        ll a = power(fact(k, fact(n - k, 1)), mod - 2);
        a %= mod;
        res = fact(n, 1) * a;
        res %= mod;
        cout << res;
    }
    return 0;
}