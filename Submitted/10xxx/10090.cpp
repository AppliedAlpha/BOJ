#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll res = 0;
int seg[4000004], n;
vector<int> v;

ll update(int i, ll x, int idx, int st, int en) {
    if (i < st || i > en) return seg[idx];
    if (st == en) return seg[idx] = x;
    int mid = (st + en) / 2;
    return seg[idx] = update(i, x, 2 * idx, st, mid) + update(i, x, 2 * idx + 1, mid + 1, en);
}

ll query(int i, int j, int idx, int st, int en) {
    if (j < st || i > en) return 0LL;
    if (i <= st && j >= en) return seg[idx];
    int mid = (st + en) / 2;
    return query(i, j, 2 * idx, st, mid) + query(i, j, 2 * idx + 1, mid + 1, en);
}

ll update(int i, ll x) { return update(i, x, 1, 1, n); }

ll query(int i, int j) { return query(i, j, 1, 1, n); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    v.resize(n);
    for (auto & i : v) cin >> i;
    for (int i=0; i<n; i++) {
        res += query(v[i]+1, n);
        update(v[i], 1);
    }
    cout << res;
    return 0;
}