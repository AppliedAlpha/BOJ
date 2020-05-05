#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _xor = 0, _sum = 0;
    int n, m, k;
    cin >> n;
    while (n--) {
        cin >> m;
        if (m <= 2) {
            cin >> k;
            _xor ^= k;
            _sum += (m == 1 ? k : -k);
        }
        else cout << (m == 3 ? _sum : _xor) << '\n';
    }
    return 0;
}