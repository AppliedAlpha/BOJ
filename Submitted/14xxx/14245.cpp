#include <iostream>
using namespace std;
struct Tree {
    int value, lazy;
};

int n, m, a, b, c, d, temp;
Tree seg[2000000] = {0, 0, };

//Lazy Propagation
void lazy(int idx, int st, int en) {
    if (seg[idx].lazy) { //Lazy Check
        seg[idx].value ^= seg[idx].lazy;
        if (st != en) {
            seg[2*idx].lazy ^= seg[idx].lazy;
            seg[2*idx+1].lazy ^= seg[idx].lazy;
        }
        seg[idx].lazy = 0;
    }
}

int update_range(int i, int j, int val, int idx, int st, int en) {
    lazy(idx, st, en);
    if (j < st || i > en) return seg[idx].value;
    if (i <= st && j >= en) {
        seg[idx].lazy ^= val;
        lazy(idx, st, en);
        return seg[idx].value;
    }
    int mid = (st + en) / 2;
    return seg[idx].value = update_range(i, j, val, 2*idx, st, mid) ^ update_range(i, j, val, 2*idx+1, mid+1, en);
}

int query(int x, int y, int idx, int st, int en) {
    lazy(idx, st, en);
    if (y < st || x > en) return 0;
    if (x <= st && y >= en) return seg[idx].value;
    int mid = (st + en) / 2;
    return query(x, y, 2*idx, st, mid) ^ query(x, y, 2*idx + 1, mid+1, en);
}

int update_range(int x, int y, int val) { return update_range(x, y, val, 1, 1, n); }
int query(int st, int en) { return query(st, en, 1, 1, n); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> temp;
        update_range(i, i, temp);
    }
    cin >> m;
    while (m--) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update_range(b+1, c+1, d);
        }
        else {
            cin >> b;
            cout << query(b+1, b+1) << '\n';
        }
    }
    return 0;
}
