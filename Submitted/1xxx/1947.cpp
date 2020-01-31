#include <iostream>
#define mod 1000000000
using namespace std;
typedef long long ll;

ll solve(int n) {
    if (n <= 2) return n-1;
    ll a = 0, b = 1, c = 2;
    for (ll i=3; i<=n; i++) {
        c = (i-1) * (a+b); //점화식
        c %= mod;
        a = b;
        b = c;
    }
    return c;
}

//교란 순열 문제
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}