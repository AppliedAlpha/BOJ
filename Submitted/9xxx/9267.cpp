#include <iostream>
using namespace std;
typedef long long ll;

ll _gcd(ll a, ll b) {
    ll c;
    while (a % b) {
        c = a % b;
        a = b;
        b = c;
    }
    return b;
}

bool solve(ll a, ll b, ll s) {
    if (!a && !b) return !s;
    if (!a) return !(s % b);
    if (!b) return !(s % a);
    if (a == s || b == s) return true;
    //tri ex = extended_eu(a, b);
    ll mod = _gcd(a, b);
    if (s % mod) return false;
    ll x = 1;
    while ((s-a*x)%b) x++;
    ll y = (s-a*x)/b;
    while (y > 0) {
        if (_gcd(x, y) == 1) return true;
        x += b / mod;
        y -= a / mod;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b, s;
    cin >> a >> b >> s;
    cout << (solve(a, b, s) ? "YES" : "NO");
    return 0;
}
