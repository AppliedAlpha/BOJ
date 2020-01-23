#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    int n, res = 0;
    cin >> n;
    v.resize(n);
    for (auto & i : v) cin >> i;
    sort(v.rbegin(), v.rend());
    int i;
    for (i=0; i<n-2; i+=3) {
        res += v[i] + v[i+1];
    }
    for (; i<n; i++) {
        res += v[i];
    }
    cout << res;
}