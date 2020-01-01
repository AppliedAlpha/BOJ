#include <iostream>
typedef long long ll;
using namespace std;

ll solve(ll a, ll b) {
    ll c = a % b;
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
    ll a, b;
    cin >> a >> b;
    if (b > a) swap(a, b);
    ll c = solve(a, b);
    for (int i=0; i<c; i++) cout << '1';
}