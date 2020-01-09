#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll cal(const vector<ll> &v, ll k) {
    ll sum = 0;
    for (auto i : v) sum += i/k;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll a, _max = 0;
    cin >> n >> a;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > _max) _max = v[i];
    }
    ll x = 1, y = _max;
    while (x <= y) {
        ll k = (x + y) / 2;
        if (cal(v, k) >= a && cal(v, k + 1) < a) {
            cout << k;
            break;
        }
        if (cal(v, k) >= a) x = k+1;
        else y = k-1;
    }
}