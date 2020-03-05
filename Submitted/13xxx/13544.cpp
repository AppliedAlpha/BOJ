#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, q, a, b, c, temp, res = 0;
vector<int> seg[400004];

// ~= 13537
//TRY
void update(int i, int x, int nidx, int node_st, int node_en) {
    if (i < node_st || i > node_en) return;
    seg[nidx].push_back(x);
    if (node_st != node_en) {
        int mid = (node_st + node_en) / 2;
        update(i, x, 2 * nidx, node_st, mid);
        update(i, x, 2 * nidx + 1, mid + 1, node_en);
    }
}

int query(int i, int j, int k, int nidx, int node_st, int node_en) {
    if (j < node_st || i > node_en) return 0;
    if (i <= node_st && j >= node_en)
        return seg[nidx].end() - upper_bound(seg[nidx].begin(), seg[nidx].end(), k);
    int mid = (node_st + node_en) / 2;
    return query(i, j, k, 2 * nidx, node_st, mid) + query(i, j, k, 2 * nidx + 1, mid + 1, node_en);
}

void update(int i, int x) { return update(i, x, 1, 1, n); }

int query(int i, int j, int k) { return query(i, j, k, 1, 1, n); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> temp;
        update(i, temp);
    }
    for (int i=1; i<400004; i++) sort(seg[i].begin(), seg[i].end());
    cin >> q;
    while (q--) {
        cin >> a >> b >> c;
        a ^= res;
        b ^= res;
        c ^= res;
        res = query(a, b, c);
        cout << res << '\n';
    }
    return 0;
}