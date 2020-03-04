#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m, a, b;
ll seg[2100000] = {0LL, }, arr[1000001] = {0LL, }, c;

// ~= 2042
//Segment Tree
//Blog 86 -> Explanation
void update(int i, ll x, int nidx, int node_st, int node_en) {
    if (i < node_st || i > node_en) return;
    seg[nidx] += x;
    if (node_st != node_en) {
        int mid = (node_st + node_en) / 2;
        update(i, x, 2 * nidx, node_st, mid);
        update(i, x, 2 * nidx + 1, mid + 1, node_en);
    }
}

ll query(int i, int j, int nidx, int node_st, int node_en) {
    if (j < node_st || i > node_en) return 0LL;
    else if (i <= node_st && j >= node_en) return seg[nidx];
    int mid = (node_st + node_en) / 2;
    return query(i, j, 2*nidx, node_st, mid) + query(i, j, 2*nidx+1, mid+1, node_en);
}

void update(int i, ll x) { update(i, x, 1, 1, n); }

ll query(int i, int j) { return query(i, j, 1, 1, n); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b, c - arr[b]);
            arr[b] = c;
        }
        else {
            int t = (int)c;
            if (b > t) swap(b, t);
            cout << query(b, t) << '\n';
        }
    }
    return 0;
}