#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << (long long)a * b / gcd(a, b) << '\n';
    }
}