#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, x, y;
int k, q;

//TRY
//Blog 93 -> Mathematical Prove
ll solve() {
    if (k == 1) return abs(x-y);
    ll cnt = 0;
    while (x != y) {
        ll _max = max(x, y);
        y = min(x, y);
        x = (_max - 2)/k + 1;
        cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> q;
    while (q--) {
        cin >> x >> y;
        cout << solve() << '\n';
    }
    return 0;
}