#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, pos, len = 1;
vector<int> v, lis, lis_len, res;

// Simple TRY
// LIS in O(n log n)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    v.resize(n);
    lis.resize(n);
    lis_len.resize(n);
    for (auto & i : v) cin >> i;
    lis[0] = v[0];
    lis_len[0] = 1;
    for (int i=0; i<n; i++) {
        if (v[i] > lis[len - 1]) {
            lis[len++] = v[i];
            lis_len[i] = len;
            continue;
        }
        pos = lower_bound(lis.begin(), lis.begin() + len, v[i]) - lis.begin();
        lis[pos] = v[i];
        lis_len[i] = pos + 1;
    }
    cout << len << '\n';
    for (int i=n-1; i>=0; i--) {
        if (lis_len[i] == len) {
            res.push_back(v[i]);
            len--;
        }
    }
    for (int i=res.size()-1; i>=0; i--) cout << res[i] << ' ';
    return 0;
}