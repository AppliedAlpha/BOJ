#include <iostream>
#define mod 15746
using namespace std;

int solve(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2, c = 3;
    n -= 2;
    while (n--) {
        c = a + b;
        a = b % mod;
        b = c % mod;
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n);
}