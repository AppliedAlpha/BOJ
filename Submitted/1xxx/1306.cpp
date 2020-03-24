#include <iostream>
#include <algorithm>
using namespace std;
int n, m, tmp, seg[4000004];

// LOL Piece Of Cake
int update(int i, int x, int idx, int st, int en) {
    if (i < st || i > en) return seg[idx];
    if (st == en) return seg[idx] = x;
    int mid = (st + en) / 2;
    return seg[idx] = max(update(i, x, 2 * idx, st, mid), update(i, x, 2 * idx + 1, mid + 1, en));
}

int query(int i, int j, int idx, int st, int en) {
    if (j < st || i > en) return 0LL;
    if (i <= st && j >= en) return seg[idx];
    int mid = (st + en) / 2;
    return max(query(i, j, 2 * idx, st, mid), query(i, j, 2 * idx + 1, mid + 1, en));
}

int update(int i, int x) { return update(i, x, 1, 1, n); }

int query(int i, int j) { return query(i, j, 1, 1, n); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> tmp;
        update(i, tmp);
    }
    for (int i=m; i<=n-m+1; i++) cout << query(i-m+1, i+m-1) << ' ';
    return 0;
}