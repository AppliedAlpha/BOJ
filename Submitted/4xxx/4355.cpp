#include <iostream>
using namespace std;
typedef long long ll;

// euler-pi problem
// n = p1^k1 x p2^k2 ... pm^km
// pi(n) = n x (1-1/p1) x (1-1/p2) ... x (1-1/pm)

// ~= 11689
void solve(ll n) {
    ll res = 1, prime = 2;
    while (prime * prime <= n) {
        ll cnt = 0;
        while (!(n % prime)) {
            n /= prime;
            res *= prime;
            cnt++;
        }
        if (!cnt) {
            prime++;
            continue;
        }
        res = res * (prime - 1) / prime;
        prime++;
    }
    if (n != 1) res *= n-1;
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    while (n) {
        solve(n);
        cin >> n;
    }
    return 0;
}