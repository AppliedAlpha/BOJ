#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
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
    int n;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        vector<ll> v(t);
        ll sum = 0;
        for (int i=0; i<t; i++) cin >> v[i];
        for (int i=0; i<t; i++) {
            for (int j=i+1; j<t; j++) {
                sum += gcd(v[i], v[j]);
            }
        }
        cout << sum << '\n';
    }
}