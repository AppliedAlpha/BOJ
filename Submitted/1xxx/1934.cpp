#include <iostream>
using namespace std;

int solve(int a, int b) {
    int c = a % b;
    while (c) {
        a = b;
        b = c;
        c = a % b;
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
        cout << a*b/solve(a, b) << '\n';
    }
}