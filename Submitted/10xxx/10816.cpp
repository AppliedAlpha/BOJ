#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, t;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    cin >> m;
    while (m--) {
        cin >> t;
        cout << upper_bound(v.begin(), v.end(), t) - lower_bound(v.begin(), v.end(), t) << ' ';
    }
}