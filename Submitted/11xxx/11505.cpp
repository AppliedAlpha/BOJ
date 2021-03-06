#include <iostream>
#define mod 1000000007
using namespace std;
typedef long long ll;
int n, m, k, a, b;
ll seg[2100000] = {0LL, }, temp, c;

// ~= 2042
//Segment Tree
ll update(int i, ll x, int nidx, int node_st, int node_en) {
    if (i < node_st || i > node_en) return seg[nidx];
    if (node_st == node_en) return seg[nidx] = x;
    int mid = (node_st + node_en) / 2;
    return seg[nidx] = (update(i, x, 2*nidx, node_st, mid) * update(i, x, 2*nidx+1, mid+1, node_en)) % mod;
}

ll query(int i, int j, int nidx, int node_st, int node_en) {
    if (j < node_st || i > node_en) return 1LL;
    if (i <= node_st && j >= node_en) return seg[nidx];
    int mid = (node_st + node_en) / 2;
    return (query(i, j, 2*nidx, node_st, mid) * query(i, j, 2*nidx+1, mid+1, node_en)) % mod;
}

ll update(int i, ll x) { return update(i, x, 1, 1, n); }

ll query(int i, int j) { return query(i, j, 1, 1, n); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    int q = m + k;
    for (int i=1; i<=n; i++) {
        cin >> temp;
        update(i, temp);
    }
    while (q--) {
        cin >> a >> b >> c;
        if (a == 1) update(b, c);
        else cout << query(b, (int)c) << '\n';
    }
    return 0;
}