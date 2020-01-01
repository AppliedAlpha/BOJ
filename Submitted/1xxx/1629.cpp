#include <iostream>
typedef long long ll;
using namespace std;
ll a, b, c;

ll solve(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y % 2) {
            res *= x;
            res %= c;
        }
        x *= x;
        x %= c;
        y /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> c;
    cout << solve(a%c, b);
}