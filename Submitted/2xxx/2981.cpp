#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int _gcd(int a, int b) {
    int c;
    while (a % b) {
        c = a % b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, j, gcd;
    vector<int> v, b, res;
    cin >> n;
    v.resize(n);
    b.resize(n-1);
    for (auto & i : v) cin >> i;
    sort(v.begin(), v.end());
    for (int i=0; i<n-1; i++) b[i] = v[i+1] - v[i];
    gcd = b[0];
    for (auto i : b) gcd = _gcd(gcd, i);
    for (j=1; j * j < gcd; j++) {
        if (!(gcd % j)) {
            res.push_back(j);
            res.push_back(gcd / j);
        }
    }
    if (j * j == gcd) res.push_back(j);
    sort(res.begin(), res.end());
    res.erase(res.begin());
    for (auto i : res) cout << i << ' ';
    return 0;
}