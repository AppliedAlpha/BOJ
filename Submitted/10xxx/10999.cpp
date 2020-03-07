#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Tree {
    ll value, lazy;
};

int n, m, k, q, a, b, c;
Tree seg[2100000] = {0LL, };
ll temp;

//Lazy Propagation
void update_range(int i, int j, ll x, int idx, int st, int en) {
    if (seg[idx].lazy) { //Lazy Check
        seg[idx].value += seg[idx].lazy * (en - st + 1);
        if (st != en) {
            seg[2*idx].lazy += seg[idx].lazy;
            seg[2*idx+1].lazy += seg[idx].lazy;
        }
        seg[idx].lazy = 0;
    }
    if (j < st || i > en) return;
    if (i <= st && j >= en) {
        seg[idx].value += x * (en - st + 1);
        if (st != en) {
            seg[2*idx].lazy += x;
            seg[2*idx+1].lazy += x;
        }
        return;
    }
    int mid = (st + en) / 2;
    update_range(i, j, x, 2*idx, st, mid);
    update_range(i, j, x, 2*idx+1, mid+1, en);
    seg[idx].value = seg[2*idx].value + seg[2*idx + 1].value;
}

ll query(int x, int y, int idx, int st, int en) {
    if (seg[idx].lazy) { //Lazy Check
        seg[idx].value += seg[idx].lazy * (en - st + 1);
        if (st != en) {
            seg[2*idx].lazy += seg[idx].lazy;
            seg[2*idx+1].lazy += seg[idx].lazy;
        }
        seg[idx].lazy = 0;
    }
    if (y < st || x > en) return 0LL;
    if (x <= st && y >= en) return seg[idx].value;
    int mid = (st + en) / 2;
    return query(x, y, 2*idx, st, mid) + query(x, y, 2*idx + 1, mid+1, en);
}

void update_range(int x, int y, ll val) { return update_range(x, y, val, 1, 1, n); }
ll query(int st, int en) { return query(st, en, 1, 1, n); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> k;
    q = m + k;
    for (int i=1; i<=n; i++) {
        cin >> temp;
        update_range(i, i, temp);
    }
    while (q--) {
        cin >> a >> b >> c;
        if (a == 1) {
            cin >> temp;
            update_range(b, c, temp);
        }
        else {
            cout << query(min(b, c), max(b, c)) << '\n';
        }
    }
    return 0;
}
