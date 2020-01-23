#include <iostream>
#define mod 1000000007
using namespace std;
typedef long long ll;
ll a[51];

int solve(int n) {
    if (n < 2) return 1;
    a[0] = a[1] = 1;
    for (int i=2; i<=n; i++) {
        a[i] = (a[i - 2] + a[i - 1] + 1) % mod;
    }
    return a[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << solve(n);
}