#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, b, tmp;
    cin >> n >> b;
    ll d = 1;
    while (d * b <= n) d *= b;
    while (d) {
        tmp = n / d;
        n %= d;
        d /= b;
        if (tmp <= 9) cout << tmp;
        else cout << char('A'+(tmp-10));
    }
}