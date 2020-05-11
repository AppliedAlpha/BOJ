#include <iostream>
using namespace std;
typedef long long ll;

ll solve(int n) {
    if (n == 1) return 4;
    if (n == 2) return 6;
    ll a = 4, b = 6, c;
    for (int i=3; i<=n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n);
}