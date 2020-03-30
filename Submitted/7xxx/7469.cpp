#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, q, temp, _i, _j, _k;
vector<int> seg[400004];

void update(int i, int x, int idx, int st, int en) {
    if (i < st || i > en) return;
    seg[idx].push_back(x);
    if (st != en) {
        int mid = (st + en) / 2;
        update(i, x, 2 * idx, st, mid);
        update(i, x, 2 * idx + 1, mid + 1, en);
    }
}

int query(int i, int j, int idx, int st, int en, int x) {
    if (j < st || i > en) return 0;
    if (i <= st && j >= en) return upper_bound(seg[idx].begin(), seg[idx].end(), x) - seg[idx].begin();
    int mid = (st + en) / 2;
    return query(i, j, 2 * idx, st, mid, x) + query(i, j, 2 * idx + 1, mid + 1, en, x);
}

void update(int i, int x) { return update(i, x, 1, 1, n); }

int query(int i, int j, int x) { return query(i, j, 1, 1, n, x); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> temp;
        update(i, temp);
    }
    for (int i=0; i<400004; i++) sort(seg[i].begin(), seg[i].end());
    //for (auto i : seg) sort(i.begin(), i.end()); <- WRONG!
    while (q--) {
        cin >> _i >> _j >> _k;
        // Binary Search
        int l = -1000000000, r = 1000000000;
        while (l <= r) {
            int m = (l + r) / 2;
            if (query(_i, _j, m) < _k) l = m+1;
            else r = m-1;
        }
        cout << l << '\n';
    }
    return 0;
}