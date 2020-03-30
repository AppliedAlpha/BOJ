#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, q, a, b, c;
struct Tree {
    ll x, y;
};
Tree seg[400004] = {0LL, };
ll temp;

Tree best_two(Tree &_a, Tree &_b) {
    vector<ll> v = {_a.x, _a.y, _b.x, _b.y};
    sort(v.begin(), v.end());
    return {v[3], v[2]};
}

Tree update(int i, ll x, int idx, int st, int en) {
    if (i < st || i > en) return seg[idx];
    if (st == en) {
        seg[idx].x = x;
        return seg[idx];
    }
    int mid = (st + en) / 2;
    auto left = update(i, x, 2 * idx, st, mid);
    auto right = update(i, x, 2 * idx + 1, mid + 1, en);
    return seg[idx] = best_two(left, right);
}

Tree query(int i, int j, int idx, int st, int en) {
    if (j < st || i > en) return {0, 0};
    if (i <= st && j >= en) return seg[idx];
    int mid = (st + en) / 2;
    auto left = query(i, j, 2 * idx, st, mid);
    auto right = query(i, j, 2 * idx + 1, mid + 1, en);
    return best_two(left, right);
}

Tree update(int i, ll x) { return update(i, x, 1, 1, n); }

ll query(int i, int j) {
    Tree res = query(i, j, 1, 1, n);
    return res.x + res.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> temp;
        update(i, temp);
    }
    cin >> q;
    while (q--) {
        cin >> a >> b >> c;
        if (a == 1) update(b, c);
        else cout << query(b, c) << '\n';
    }
    return 0;
}