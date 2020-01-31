#include <iostream>
using namespace std;
typedef long long ll;

ll f(int a, int num) {
    ll res = 0, i = num;
    while (i <= a) {
        res += a/i;
        i *= num;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r;
    ll c2, c5;
    cin >> n >> r;
    c2 = f(n, 2) - f(r, 2) - f(n-r, 2);
    c5 = f(n, 5) - f(r, 5) - f(n-r, 5);
    cout << (c2 > c5 ? c5 : c2);
    return 0;
}