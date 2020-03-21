#include <iostream>
using namespace std;
typedef long long ll;
struct Tree {
    ll value, lazy;
};

int n, m, a, b, c;
Tree seg[400004] = {0LL, };
ll temp;

// ~= 10999
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
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> temp;
        update_range(i, i, temp);
    }
    cin >> m;
    while (m--) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> temp;
            update_range(b, c, temp);
        }
        else {
            cin >> b;
            cout << query(b, b) << '\n';
        }
    }
    return 0;
}
