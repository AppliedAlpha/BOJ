#include <iostream>
#define m 1000000007
using namespace std;

int solve(int n) {
    int a = 0, b = 1, c = 1;
    if (n <= 2) return (bool)n;
    else {
        for (int i=3; i<=n; i++) {
            a = b % m;
            b = c % m;
            c = (a + b) % m;
        }
        return c;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}
