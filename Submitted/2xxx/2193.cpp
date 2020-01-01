#include <iostream>
using namespace std;

long long solve(int n) {
    if (n <= 2) return 1;
    long long a = 1, b = 1, c;
    for (int i=3; i<=n; i++) {
        c = a + b;
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
    cout << solve(n);
}