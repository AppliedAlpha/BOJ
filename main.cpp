#include <iostream>
#include <algorithm>
using namespace std;
int n, q, a, b, c, tmp, seg[800008];

int update(int i, int x, int idx, int st, int en) {
    if (i < st || i > en) return seg[idx];
    if (st == en) return seg[idx] = x;
    int mid = (st + en) / 2;
    return seg[idx] = update(i, x, 2 * idx, st, mid) ^ update(i, x, 2 * idx + 1, mid + 1, en);
}

int query(int i, int j, int idx, int st, int en) {
    if (j < st || i > en) return 1;
    if (i <= st && j >= en) return seg[idx];
    int mid = (st + en) / 2;
    return query(i, j, 2 * idx, st, mid) ^ query(i, j, 2 * idx + 1, mid + 1, en);
}

int update(int i, int x) { return update(i, x, 1, 1, n); }

int query(int i, int j) { return query(i, j, 1, 1, n); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> tmp;
        update(i, tmp);
    }
    while (q--) {
        cin >> a >> b >> c;
        if (a == 1) update(b, c);
        else cout << query(min(b, c), max(b, c)) << '\n';
    }
    return 0;
}