#include <iostream>
using namespace std;
int n, q, a, b, c, temp;
int seg[400004], arr[100001];

//Segment Tree

int seg_func(int x, int y) {
    if (x == -1) return y;
    if (y == -1) return x;
    return (arr[x] <= arr[y] ? x : y);
}
int update(int i, int x, int nidx, int node_st, int node_en) {
    if (i < node_st || i > node_en) return seg[nidx];
    if (node_st == node_en) return seg[nidx] = i;
    int mid = (node_st + node_en) / 2;
    return seg[nidx] = seg_func(update(i, x, 2*nidx, node_st, mid), update(i, x, 2*nidx+1, mid+1, node_en));
}

int query(int i, int j, int nidx, int node_st, int node_en) {
    if (j < node_st || i > node_en) return -1;
    if (i <= node_st && j >= node_en) return seg[nidx];
    int mid = (node_st + node_en) / 2;
    return seg_func(query(i, j, 2*nidx, node_st, mid), query(i, j, 2*nidx+1, mid+1, node_en));
}

int update(int i, int x) { return update(i, x, 1, 1, n); }

int query(int i, int j) { return query(i, j, 1, 1, n); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> temp;
        arr[i] = temp;
        update(i, temp);
    }
    cin >> q;
    while (q--) {
        cin >> a >> b >> c;
        if (a == 1) {
            arr[b] = c;
            update(b, c);
        }
        else cout << query(b, c) << '\n';
    }
    return 0;
}