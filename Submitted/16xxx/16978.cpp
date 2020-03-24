#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct up {
    int i, v;
};

struct qr {
    int k, i, j, pos;
};

ll seg[400004];
int n, q, a, b, c, d, temp;
vector<up> v1;
vector<qr> v2;
vector<ll> res;

// Offline Query
// How to make it better?

bool comp(const qr& x, const qr &y) { return x.k < y.k; }

ll update(int i, ll x, int idx, int st, int en) {
    if (i < st || i > en) return seg[idx];
    if (st == en) return seg[idx] = x;
    int mid = (st + en) / 2;
    return seg[idx] = update(i, x, 2*idx, st, mid) + update(i, x, 2*idx+1, mid+1, en);
}

ll query(int i, int j, int idx, int st, int en) {
    if (j < st || i > en) return 0LL;
    if (i <= st && j >= en) return seg[idx];
    int mid = (st + en) / 2;
    return query(i, j, 2*idx, st, mid) + query(i, j, 2*idx+1, mid+1, en);
}

ll update(int i, ll x) { return update(i, x, 1, 1, n); }
ll query(int i, int j) { return query(i, j, 1, 1, n); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> temp;
        update(i, temp);
        if (i == 1) v1.push_back({1, temp});
    }
    cin >> q;
    int pos = 0;
    while (q--) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            v1.push_back({b, c});
        }
        else {
            cin >> b >> c >> d;
            v2.push_back({b, c, d, pos++});
        }
    }
    res.resize(pos);
    sort(v2.begin(), v2.end(), comp);
    int it = 0, it2 = 0;
    while (it != v1.size()) {
        up now = v1[it];
        update(now.i, now.v);
        while (v2[it2].k == it) {
            ll ans = query(v2[it2].i, v2[it2].j);
            res[v2[it2].pos] = ans;
            it2++;
            if (it2 == v2.size()) break;
        }
        it++;
    }
    for (auto i : res) cout << i << '\n';
    return 0;
}