#include <iostream>
#define mod 1000000007
using namespace std;
typedef long long ll;

struct _lazy {
    ll mul = 1, sum = 0;

    void operator += (_lazy &x) { // Try (In Operator +=)
        if (x.mul == 0) {
            mul = 0;
            sum = x.sum;
            return;
        }
        mul = (mul * x.mul) % mod;
        sum = (sum * x.mul) % mod;
        sum = (sum + x.sum) % mod;
    }
};

ll seg[400004];
_lazy lazy[400004];
int n, m, a, b, c, v, temp;

// 10999 ?
// Lazy Propagation

void lazy_propagation(int idx, int st, int en) {
    if (lazy[idx].mul == 1 && lazy[idx].sum == 0) // X1, +0 (Empty)
        return;

    seg[idx] = (seg[idx] * lazy[idx].mul + (en-st+1) * lazy[idx].sum) % mod;
    if (st != en) {
        lazy[2*idx] += lazy[idx];
        lazy[2*idx+1] += lazy[idx];
    }
    lazy[idx] = {1, 0};
}

// i -> s, j -> e, st -> l, en -> r;
// sum, mul, set (configured with 'l')
void update(int i, int j, int idx, int st, int en, _lazy &l) {
    lazy_propagation(idx, st, en);
    if (i > en || j < st) return;
    if (i <= st && j >= en) {
        lazy[idx] += l;
        lazy_propagation(idx, st, en);
        return;
    }
    int mid = (st + en) / 2;
    update(i, j, 2*idx, st, mid, l);
    update(i, j, 2*idx+1, mid+1, en, l);
    seg[idx] = (seg[2*idx] + seg[2*idx+1]) % mod;
}

ll query(int i, int j, int idx, int st, int en) {
    lazy_propagation(idx, st, en);
    if (i > en || j < st) return 0LL;
    if (i <= st && j >= en) return seg[idx];
    int mid = (st + en) / 2;
    return (query(i, j, 2*idx, st, mid) + query(i, j, 2*idx+1, mid+1, en)) % mod;
}

void update(int i, int j, _lazy &l) { return update(i, j, 1, 1, n, l); }
ll query(int i, int j) { return query(i, j, 1, 1, n); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> temp;
        _lazy init = {0, temp};
        update(i, i, init);
    }
    cin >> m;
    while (m--) {
        cin >> a;
        if (a <= 3) {
            cin >> b >> c >> v;
            _lazy upd;
            if (a == 1) upd = {1, v};
            else if (a == 2) upd = {v, 0};
            else upd = {0, v};
            update(b, c, upd);
        }
        else {
            cin >> b >> c;
            cout << query(b, c) << '\n';
        }
    }
    return 0;
}