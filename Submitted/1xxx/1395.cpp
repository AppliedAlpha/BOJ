#include <iostream>
#include <algorithm>
using namespace std;
struct Tree {
    int value;
    bool lazy;
};

int n, m, a, b, c;
Tree seg[400000] = {0, 0, };

// ~= 10999
//Lazy Propagation
void lazy(int idx, int st, int en) {
    if (seg[idx].lazy) { //Lazy Check
        seg[idx].value = (en - st + 1) - seg[idx].value;
        if (st != en) {
            seg[2*idx].lazy ^= 1;
            seg[2*idx+1].lazy ^= 1;
        }
        seg[idx].lazy = false;
    }
}

int update_range(int i, int j, int idx, int st, int en) {
    lazy(idx, st, en);
    if (j < st || i > en) return seg[idx].value;
    if (i <= st && j >= en) {
        seg[idx].lazy ^= 1;
        lazy(idx, st, en);
        return seg[idx].value;
    }
    int mid = (st + en) / 2;
    return seg[idx].value = update_range(i, j, 2*idx, st, mid) + update_range(i, j, 2*idx+1, mid+1, en);
}

int query(int x, int y, int idx, int st, int en) {
    lazy(idx, st, en);
    if (y < st || x > en) return 0;
    if (x <= st && y >= en) return seg[idx].value;
    int mid = (st + en) / 2;
    return query(x, y, 2*idx, st, mid) + query(x, y, 2*idx + 1, mid+1, en);
}

int update_range(int x, int y) { return update_range(x, y, 1, 1, n); }
int query(int st, int en) { return query(st, en, 1, 1, n); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        if (a == 0) update_range(b, c);
        else {
            cout << query(min(b, c), max(b, c)) << '\n';
        }
    }
    return 0;
}
