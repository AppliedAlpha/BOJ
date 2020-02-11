#include <iostream>
using namespace std;
typedef long long ll;

ll fibo(ll p, ll q) {
    if (p <= 2) return (1 % q);
    ll a = 1, b = 1, c = 2;
    for (int i=3; i<=p; i++) {
        c = (a + b) % q;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        ll p, q;
        cin >> p >> q;
        cout << "Case #" << i << ": " << fibo(p, q) << '\n';
    }
    return 0;
}