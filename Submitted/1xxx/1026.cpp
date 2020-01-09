#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, res = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto & i : a) cin >> i;
    for (auto & i : b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    for (int i=0; i<n; i++) res += a[i] * b[i];
    cout << res;
    return 0;
}