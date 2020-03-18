#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
vector<int> v, d;

// ~= 1684
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, tmp, res, t;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n > 1) {
            v.resize(n);
            d.resize(n - 1);
            for (int i = 0; i < n; i++) {
                cin >> tmp;
                v[i] = tmp;
                if (i != 0) d[i - 1] = v[i] - v[i - 1];
            }
            if (d.size() == 1) {
                if (d[0] != 0) cout << d[0] << '\n';
                else cout << "INFINITY\n";
            }
            else {
                res = d[0];
                for (int i = 1; i < d.size(); i++) {
                    res = gcd(res, d[i]);
                }
                if (res != 0) cout << res << '\n';
                else cout << "INFINITY\n";
            }
        } else {
            cin >> tmp;
            if (tmp != 0) cout << tmp << '\n';
            else cout << "INFINITY\n";
        }
    }
    return 0;
}