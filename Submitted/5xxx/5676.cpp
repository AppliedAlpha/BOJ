#include <iostream>
using namespace std;
int n, k, a, b, tmp, seg[400004];
char c;

int update(int i, int x, int idx, int st, int en) {
    if (i < st || i > en) return seg[idx];
    if (st == en) return seg[idx] = x;
    int mid = (st + en) / 2;
    return seg[idx] = update(i, x, 2 * idx, st, mid) * update(i, x, 2 * idx + 1, mid + 1, en);
}

int query(int i, int j, int idx, int st, int en) {
    if (j < st || i > en) return 1;
    if (i <= st && j >= en) return seg[idx];
    int mid = (st + en) / 2;
    return query(i, j, 2 * idx, st, mid) * query(i, j, 2 * idx + 1, mid + 1, en);
}

int update(int i, int x) { return update(i, x, 1, 1, n); }

int query(int i, int j) { return query(i, j, 1, 1, n); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (!((cin >> n >> k).eof())) {
        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            if (tmp != 0) tmp = (tmp > 0 ? 1 : -1);
            update(i, tmp);
        }
        while (k--) {
            cin >> c >> a >> b;
            if (c == 'C') {
                if (b != 0) b = (b > 0 ? 1 : -1);
                update(a, b);
            }
            else {
                int res = query(a, b);
                if (res > 0) cout << '+';
                else if (res < 0) cout << '-';
                else cout << 0;
            }
        }
        cout << '\n';
    }
    return 0;
}