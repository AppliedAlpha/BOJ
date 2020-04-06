#include <iostream>
using namespace std;
typedef long long ll;

struct p { ll a, b, c; };

// Division of Negative Number?
p extended_euc(ll a, ll b) {
    if (b == 0LL) return {a, 1, 0};
    p res = extended_euc(b, a % b);
    return {res.a, res.c, res.b - (a / b) * res.c};
}

bool solve(ll a, ll b, ll s) {
    if (!a && !b) return !s;
    if (!a) return !(s % b);
    if (!b) return !(s % a);
    p temp = extended_euc(a, b);
    ll g = temp.a, x = temp.b, y = temp.c;
    if (s % g) return false;
    ll diff = abs(b/g);
    x = (x % diff) * (s/g % diff) % diff;
    if (x < 0) x += diff;
    y = (s - a*x) / b;
    while (y > 0) {
        if (extended_euc(x, y).a == 1) return true;
        x += b/g;
        y -= a/g;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll a, b, s;
    cin >> a >> b >> s;
    cout << (solve(a, b, s) ? "YES" : "NO");
    return 0;
}