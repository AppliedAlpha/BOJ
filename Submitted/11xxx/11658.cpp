#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a, b, c, d, e;

// 11 12
// 21 22
vector<vector<int>> seg(2100, vector<int>(2100));
int arr[1025][1025] = {0, };

void update(int x, int y, int v) {
    int i = y+n-1, j = x+n-1;
    seg[i][j] = v;
    while (j > 1) {
        j /= 2;
        seg[i][j] = seg[i][j*2] + seg[i][j*2+1];
    }
    while (i > 1) {
        j = x+n-1;
        i /= 2;
        seg[i][j] = seg[i*2][j] + seg[i*2+1][j];
        while (j > 1) {
            j /= 2;
            seg[i][j] = seg[i][j*2] + seg[i][j*2+1];
        }
    }
}

int query_x(int y, int i, int j, int idx, int st, int en) {
    if (j < st || i > en) return 0;
    if (i <= st & j >= en) return seg[y][idx];
    int mid = (st + en) / 2;
    return query_x(y, i, j, 2*idx, st, mid) + query_x(y, i, j, 2*idx+1, mid+1, en);
}

int query_y(int x1, int x2, int i, int j, int idx, int st, int en) {
    if (j < st || i > en) return 0;
    if (i <= st && j >= en) return query_x(idx, x1, x2, 1, 1, n);
    int mid = (st + en) / 2;
    return query_y(x1, x2, i, j, 2*idx, st, mid) + query_y(x1, x2, i, j, 2*idx+1, mid+1, en);
}

int query_y(int x1, int x2, int y1, int y2) { return query_y(x1, x2, y1, y2, 1, 1, n); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> arr[i][j];
            update(i, j, arr[i][j]);
        }
    }
    while (m--) {
        cin >> a >> b >> c >> d;
        if (!a) update(b, c, d);
        else {
            cin >> e;
            cout << query_y(min(b, d), max(b, d), min(c, e), max(c, e)) << '\n';
        }
    }
    return 0;
}