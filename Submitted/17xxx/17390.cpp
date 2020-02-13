#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b;
    cin >> n >> m;
    v.resize(n);
    sum.resize(n+1);
    for (auto & i : v) cin >> i;
    sort(v.begin(), v.end());
    v.insert(v.begin(), 0);
    sum[0] = 0;
    for (int i=1; i<=n; i++) sum[i] = sum[i-1] + v[i];
    while (m--) {
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << '\n';
    }
    return 0;
}