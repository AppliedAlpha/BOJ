#include <iostream>
using namespace std;
typedef long long ll;
int n, m, k, a, b;
ll seg[2100000] = {0LL, }, temp, c;

//Segment Tree
//Blog 86 -> Explanation
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
    cin.tie(nullptr);
    cin >> n >> m >> k;
    int q = m + k;
    for (int i=1; i<=n; i++) {
        cin >> temp;
        update(i, temp);
    }
    while (q--) {
        cin >> a >> b >> c;
        if (a == 1) update(b, c);
        else cout << query(b, (int)c) << '\n';
    }
    return 0;
}