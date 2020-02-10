#include <iostream>
using namespace std;
typedef long long ll;

// euler-pi problem
// n = p1^k1 x p2^k2 ... pm^km
// pi(n) = n x (1-1/p1) x (1-1/p2) ... x (1-1/pm)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    ll pi = n, prime = 2;
    while (prime * prime <= n) {
        if (!(n % prime)) pi = pi * (prime - 1) / prime;
        while (!(n % prime)) n /= prime;
        prime++;
    }
    if (n > 1) pi = pi * (n-1) / n;
    cout << pi;
    return 0;
}