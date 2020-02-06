#include <iostream>
#include <cstdlib>
#define mod 1000000000
using namespace std;
typedef long long ll;

int detection(int n) {
    if (n == 0) return 0;
    else if (n < 0 && !(abs(n) % 2)) return -1;
    else return 1;
}

ll solve(int n) {
    if (n <= 1) return n;
    ll a = 0, b = 1, c;
    for (int i=2; i<=n; i++) {
        c = (a + b) % mod;
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
    cout << detection(n) << '\n' << solve(abs(n));
    return 0;
}