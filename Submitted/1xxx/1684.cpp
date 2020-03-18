#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
vector<int> v, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, tmp, res;
    cin >> n;
    if (n > 1) {
        v.resize(n);
        d.resize(n-1);
        for (int i=0; i<n; i++) {
            cin >> tmp;
            v[i] = tmp;
            if (i != 0) d[i-1] = v[i] - v[i-1];
        }
        if (d.size() == 1) cout << d[0];
        else {
            res = d[0];
            for (int i=1; i<d.size(); i++) {
                res = gcd(res, d[i]);
            }
            cout << res;
        }
    }
    else {
        cin >> tmp;
        cout << tmp;
    }
    return 0;
}