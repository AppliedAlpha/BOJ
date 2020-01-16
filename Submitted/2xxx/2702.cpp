#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int c;
    while (a % b) {
        c = a % b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        if (b > a) swap(a, b);
        int g = gcd(a, b);
        cout << a*b/g << ' ' << g << '\n';
    }
    return 0;
}