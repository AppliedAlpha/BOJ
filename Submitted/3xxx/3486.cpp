#include <iostream>
using namespace std;

int reverse(int x) {
    int i, t = 0;
    if (x < 10) return x;
    while (x) {
        i = x % 10;
        t = t * 10 + i;
        x /= 10;
    }
    return t;
}

int solve(int a, int b) {
    a = reverse(a);
    b = reverse(b);
    return reverse(a + b);
}

int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << solve(a, b) << '\n';
    }
}