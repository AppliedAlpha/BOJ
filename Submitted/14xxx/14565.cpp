#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
struct tri {
    ll mod, x, y;
};

//Extended Euclidean Algorithm
tri extended_eu(ll a, ll b) {
    if (b == 0) return {a, 1LL, 0LL};
    tri ex = extended_eu(b, a % b);
    return {ex.mod, ex.y, ex.x - (a / b) * ex.y};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, a;
    cin >> n >> a;
    cout << n - a << ' ';
    tri ex = extended_eu(a, n);
    if (ex.mod != 1) cout << -1;
    else {
        if (ex.x < 0) ex.x = (ex.x + n) % n;
        cout << ex.x;
    }
    return 0;
}