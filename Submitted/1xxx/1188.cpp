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
    int n, m;
    cin >> n >> m;
    cout << m - gcd(n, m);
    return 0;
}