#include <iostream>
using namespace std;
typedef long long ll;
bool notPrime[10000001];

void prime_init() {
    notPrime[1] = true;
    notPrime[2] = false;
    for (int j=4; j<=10000000; j+=2) notPrime[j] = true;
    for (int i=3; i<=10000000; i+=2) {
        if (notPrime[i]) continue;
        for (int j=2*i; j<=10000000; j+=i) notPrime[j] = true;
    }
}

ll count(ll i, ll a, ll b) {
    ll base = i*i, ret = 0;
    while (base <= b) {
        if (base >= a) ret++;
        if ((base * i) % base != 0) break;
        base *= i;
    }
    return ret;
}

ll solve(ll a, ll b) {
    ll res = 0;
    res += count(2, a, b);
    for (ll i=3; i*i<=b; i+=2) {
        if (!notPrime[i]) res += count(i, a, b);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    cin >> a >> b;
    prime_init();
    cout << solve(a, b);
    return 0;
}